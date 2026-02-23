#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
enum ECU{
	EngineControl=1,BatteryManagement,Dashboard,ADASCamera,RearParkingSensor,Infotainment
};
string s[]={" ","EngineControl","BatteryManagement","Dashboard","ADASCamera","RearParkingSensor","Infotainment"};
class cabellayout{
	int v;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<vector<pair<int,int>>> adj;
	// length,visited,parent
	vector<int>length;
	vector<bool>visited;
	vector<int>parent;
	public:
	cabellayout(int vv){
		v=vv;
		adj.resize(v);
		length.resize(v,INT_MAX);
		visited.resize(v,false);
		parent.resize(v,-1);
	}
	void add(int u,int v,int w){// prims logic only work for undirected,weighted graph
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	// prims algorithm
	void shortest(int src){
		length[src]=0;
		pq.push({length[src],src});// in priority queue i am passing {weight,node}
		while(!pq.empty()){
			int distance=pq.top().first;
			int node=pq.top().second;
			pq.pop();
			if(visited[node]) continue;
			visited[node]=true;
			for(auto neighbor:adj[node]){
				int weight=neighbor.second;// neighbour node weight
				int neighbornode=neighbor.first;
				if(!visited[neighbornode]&&length[neighbornode]>weight){
					length[neighbornode]=weight;
					parent[neighbornode]=node;
					pq.push({length[neighbornode],neighbornode});
				}
			}
		}
	}
	// print
	void print(){
		for(int i=2;i<v;i++){
			cout<<s[parent[i]]<<"  to  "<<s[i]<<" cost:"<<length[i]<<endl;
		}
		cout<<endl;
	}
	void print1(){
		for(int i=2;i<v;i++){
			cout<<parent[i]<<"  ->  "<<i<<" weight:"<<length[i]<<endl;
		}
	}
	
};
int main(){
	cabellayout cl(7);
	cl.add(1,2,3);
	cl.add(1,3,4);
	cl.add(2,3,2);
	cl.add(2,4,6);
	cl.add(3,4,5);
	cl.add(3,5,7);
	cl.add(4,6,4);
	cl.add(5,6,3);
	cl.shortest(1);
	cl.print();
	cl.print1();
}

