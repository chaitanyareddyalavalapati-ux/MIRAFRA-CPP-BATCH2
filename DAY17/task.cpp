#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
struct airportinfo{
	string boarding;
	string dropping;
	int cost;
	airportinfo(string b,string d,int c){
		boarding=b;
		dropping=d;
		cost=c;
	}
};
struct comparator{
    bool operator()(pair<int,string>&a,pair<int,string>&b ){
        return a.first>b.first;
    }
};
class Ticketbooking{
	unordered_map<string,vector<pair<string,int>>> adj;
	unordered_map<string,int> dist;
	unordered_map<string,string>parent;
	// here i am storing weight,node
	priority_queue<pair<int,string>,vector<pair<int,string>>,comparator> q;
	public:
	void add(airportinfo a){
		adj[a.boarding].push_back({a.dropping,a.cost});
	}
	void shortest(string src){
		dist[src]=0;
		q.push({dist[src],src});
		while(!q.empty()){
			int distance=q.top().first;
			string node=q.top().second;
			q.pop();
			for(auto& neighbor:adj[node]){
				int weight=neighbor.second;
				string s=neighbor.first;
				if(!dist.count(s)) dist[s]=INT_MAX;
				if(!parent.count(s)) parent[s]=" ";
				if(dist[s]>distance+weight){
					dist[s]=distance+weight;
					parent[s]=node;
					q.push({dist[s],s});
				}
			}
		}
		cout<<"From "<<src<<" airport to connected airports "<<endl;
    }
   void print(string src){
    cout << "From " << src << ":\n";
    for(auto &p : dist){
        cout << "Airport: " << p.first 
             << "  Cost: " << p.second;

        if(parent.count(p.first))
            cout << "  via " << parent[p.first];

        cout << endl;
    }
}
    
};
int main(){
	Ticketbooking tb;
	tb.add(airportinfo("Hyderabad","Bangalore",5000));
	tb.add(airportinfo("Hyderabad","Delhi",3000));
	tb.add(airportinfo("Hyderabad","mumbai",1000));
	tb.add(airportinfo("mumbai","Delhi",1500));
	tb.shortest("Hyderabad");
	tb.print("Hyderabad");
}
