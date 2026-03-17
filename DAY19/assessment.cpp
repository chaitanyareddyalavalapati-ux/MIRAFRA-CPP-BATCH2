#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//enum controlstations{TrafficControl,PowerGrid,WaterSupply,HospitalNetwork,PoliceControl,DataCenter};
//string original[]={"TrafficControl","PowerGrid","WaterSupply","HospitalNetwork","PoliceControl","DataCenter"};
string original[]={"BLR","DEL","HYD","Bom","mee"};
struct dataa{
	int u;
	int v;
	int wt;
};
void initialise(vector<int>&parent,vector<int>&rank,int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
		rank[i]=0;
	}
	cout<<endl;
}
int findparent(vector<int>& parent,int u){// this is path compresssion to achieve O(1) and also flatted tree
	if(parent[u]==u) return parent[u];
	return parent[u]=findparent(parent,parent[u]);
}
void unionset(int u,int v,vector<int>& parent,vector<int>& rank){
    u=findparent(parent,u);
    v=findparent(parent,v);
    if(u==v) return;
	if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else if(rank[v]<rank[u]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;
	}
}
void printing(vector<int>parent){
	for(int i=0;i<parent.size();i++){
		cout<<parent[i]<<" ";
	}
	cout<<endl;
}
void print(vector<int>rank){
	for(int i=0;i<rank.size();i++){
		cout<<rank[i]<<" ";
	}
	cout<<endl;
}
int minimumspaningtree(vector<dataa>edges,int n){
	// sort the algorithm
	sort(edges.begin(),edges.end(),[](const dataa& a,const dataa& b){
			return a.wt<b.wt;
	});
	vector<int>parent(n);
	vector<int>rank(n);
	int edgeweight=0;
	int edgecount=0;
	// initialse 
	initialise(parent,rank,n);
	// process the nodes
	for(int i=0;i<edges.size();i++){
		int u=edges[i].u;
		int v=edges[i].v;
		int wt=edges[i].wt;
		if(findparent(parent,u)!=findparent(parent,v)){
			unionset(u,v,parent,rank);
			cout<<original[u]<<"  \u2708   "<<original[v]<<":"<<wt<<endl;
		//	cout<<u<<"->"<<v<<":"<<wt<<endl;
			edgeweight+=wt;
			edgecount++;
			if(edgecount==n-1) break;
		}
	}
	printing(parent);
	print(rank);
	return edgeweight;
}
int main(){
	int n=5;
	// adjacent list
	vector<dataa>edges={
        {0, 2, 5},
        {0, 4, 8},
        {2, 4, 6},
        {1, 3, 10},
        {3, 0, 12},
        {1, 0, 15}};
	int totalweight=minimumspaningtree(edges,n);
	cout<<"Total MST weight: "<<totalweight<<endl;
}
