#include<iostream>
#include<vector>
using namespace std;
void initialise(vector<int>&parent,vector<int>&rank,int v){
    parent.resize(v);
    rank.resize(v);
	for(int i=1;i<=v;i++){
		parent[i]=i;
		rank[i]=0;
	}
}
int findparent(vector<int>&parent,int u){
	if(parent[u]==u) return parent[u];
	// path compression
	return parent[u]=findparent(parent,parent[u]);
}
void unionset(int u,int v,vector<int>& parent,vector<int>& rank){
	u=findparent(parent,u);
	v=findparent(parent,v);
	// now compare ranks 
	if(u==v){
		cout<<u<<"and"<<v<<"belongs to same set"<<endl;
		return ;
	}
	if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else if(rank[u]>rank[v]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;

	}
	cout<<"for "<<u<<" and "<<v<<" parent is "<<parent[u]<<" "<<parent[v]<<endl;
}
void print(vector<int>&parent,vector<int>&rank,int v){
	// parent
	cout<<"parent array"<<endl;
	for(int i=1;i<=v;i++){
		cout<<parent[i]<<" ";
	}
	cout<<endl;
	cout<<"Rank array"<<endl;
	for(int i=1;i<=v;i++){
		cout<<rank[i]<<" ";
	}
	cout<<"--------------------"<<endl;
}
int main(){
	int v=7;
	vector<int>parent;
	vector<int>rank;
	// initialise 
	initialise(parent,rank,v);
	print(parent,rank,v);
	unionset(1,2,parent,rank);
	print(parent,rank,v);
	unionset(2,3,parent,rank);
	print(parent,rank,v);
	unionset(3,4,parent,rank);
	print(parent,rank,v);
	unionset(2,4,parent,rank);
	print(parent,rank,v);
	unionset(5,6,parent,rank);
	print(parent,rank,v);
	unionset(2,6,parent,rank);
	print(parent,rank,v);
	if(findparent(parent,1)==findparent(parent,2)){
		cout<<"They are cyclic"<<endl;
	}
	else{
		cout<<"THey are not cyclic"<<endl;
	}
}
