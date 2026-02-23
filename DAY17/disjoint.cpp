#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void DFS(int start,vector<vector<int,int>> adj,vector<bool>visited,vector<bool>recstack){
	visited[start]=true;
	recstack[start]=true;
	
}
int main(){
	int v=4;
	vector<vector<int,int>> adj;
	vector<bool> visited(v,false);
	vector<bool> recstack(v,false);
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);
	DFS(0,adj,visited,recstack);
}
