#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
void DFS(int start,vector<vector<int>> adj){
	int v=adj.size();
	vector<bool> visited(v,false);
	int node=adj[start];
	cout<<node<<" ";
	for(int neighbour:adj[node]){
		if(!visited[neighbour]){
			visited[neighbour]=true;
			start=start+1;
			DFS(start,adj);
		}
	}

}
int main(){
	vector<vector<int>> v;
	v[0]={1,2};
	v[1]={3};
	v[2]={3};
	v[3]={4};
	DFS(0,v);
}
