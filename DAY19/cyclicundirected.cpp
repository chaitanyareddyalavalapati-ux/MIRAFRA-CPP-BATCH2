#include<iostream>
#include<vector>
#include<list>
using namespace std;
bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>& visited){
	visited[node]=true;
	for(int neighbor:adj[node]){
		if(!visited[neighbor]){
			dfs(neighbor,node,adj,visited);
		}
		else if(neighbor!=parent){
			return true;
		}
	}
	return false;
}
int main(){
	int v=7;
	vector<vector<int>>adj(v);
	vector<bool>visited(v,false);
	adj[0].push_back(1);
	adj[1].push_back(0);

	adj[0].push_back(3);
	adj[3].push_back(0);
	
	adj[1].push_back(2);
	adj[2].push_back(1);
	
	adj[2].push_back(3);
	adj[2].push_back(3);


	adj[5].push_back(6);
	adj[6].push_back(5);
	
	bool detect=false;
	// here i am trasering to know that grapg may contain discoonected also
	for(int i=0;i<v;i++){
		if(!visited[i]){
			if(dfs(i,-1,adj,visited)){// passing current node,parent_node,adjcentlist,visioted array
				detect=true;
				break;
			}
		}
	}
	if(detect){
		cout<<"Cycle found"<<endl;
	}
	else{
		cout<<"Cycle not found"<<endl;
	}
}
