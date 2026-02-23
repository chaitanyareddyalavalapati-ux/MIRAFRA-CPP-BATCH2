#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
class shortestpath{
	int v;
	vector<vector<pair<int,int>>> adj;
	public:
	shortestpath(int vv){
		v=vv;
		adj.resize(v);
	}
	void add(int u,int v,int weight){
		adj[u].push_back({v,weight});
		adj[v].push_back({u,weight});
	}
void djk(int src){
	int v=adj.size();
// here weight,node;	
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<int>dist(v,INT_MAX);
	dist[src]=0;
	pq.push({0,src});
	while(!pq.empty()){
		int d=pq.top().first;
		int node=pq.top().second;
		pq.pop();
		for(auto edge:adj[node]){
			int neighbor=edge.first;
			int weight=edge.second;
			if(dist[neighbor]>d+weight){
				dist[neighbor]=d+weight;
				pq.push({dist[neighbor],neighbor});
			}
		}
	}
	cout<<"shortest distances from surce"<<endl;
	for(auto p:dist){
		cout<<p<<" ";
	}
	cout<<endl;
}
};
int main(){
	int v=5;
	shortestpath p(v);
	/*adj[0].push_back({1,4});
adj[0].push_back({2,1});
adj[2].push_back({1,2});p.add(0,1,4);*/
	p.add(0,1,4);
	p.add(0,2,1);
	p.add(2,1,2);
	p.djk(0);
}
