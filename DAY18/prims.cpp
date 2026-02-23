#include<iostream>
#include<vector>
#include<climits>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;
class prims{
	int v;
	vector<vector<pair<int,int>>> adj;//adjacent list
	//initalize the arrays
	vector<int>dist;// key
	vector<int>parent;//parent
	vector<bool>visited;// visted
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	public:
	prims(int vv){
		v=vv;
		adj.resize(v);
		dist.resize(v+1,INT_MAX);
		parent.resize(v+1,-1);
		visited.resize(v+1,false);
	}
	// adjacent list
	void add(int u,int v,int w){
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	// prims algorithm
	void shortestpath(int src){
		int u=src;
		dist[u]=0;
		pq.push({dist[u],src});
		while(!pq.empty()){
			int distance=pq.top().first;
			int node=pq.top().second;
			pq.pop();
			if(visited[node]) continue;
			visited[node]=true;
			for(auto neighbor:adj[node]){
				int weight=neighbor.second;
				int n=neighbor.first;
				if(!visited[n]&&weight<dist[n]){
					dist[n]=weight;
					parent[n]=node;
					pq.push({dist[n],n});
				}
			}
		}		
	}
	// printing
	void print(){
		int weight=0;
		for(int i=2;i<v;i++){
			weight+=dist[i];
			cout<<parent[i]<<"->"<<i<<" weight:"<<dist[i]<<endl;
		}
		cout<<endl;
		cout<<"total weight"<<weight<<endl;
	}
};
int main(){
	int v=5;
	prims p(v);
	//p.add(0,1,2);
	//p.add(0,3,6);
	p.add(1,4,5);
	p.add(1,3,8);
	p.add(1,2,3);
	p.add(2,1,3);
	p.add(2,4,7);
	p.shortestpath(1);
	p.print();
}
