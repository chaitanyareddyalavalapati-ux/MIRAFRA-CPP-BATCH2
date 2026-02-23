#include<iostream>
#include<list>
#include<utility>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class googlemap{
	unordered_map<string,list<pair<string,int>>> mp;
	public:
	void add(string src,string dest,int w){
		mp[src].push_back({dest,w});
		//mp[dest].push_back({src,w});
	}
	// gathering all  neighbours along with their weights
	void find(string v) {

    if(mp.find(v) == mp.end()) {
        cout << "Location not found\n";
        return;
    }

    int minDist = INT_MAX;
    string nearest;

    for(auto q : mp[v]) {
        if(q.second < minDist) {
            minDist = q.second;
            nearest = q.first;
        }
    }

    if(minDist == INT_MAX)
        cout << "For node " << v << " there is no petrol bunk near your location\n";
    else
        cout << "From your location " << v
             << ", the nearest petrol bunk is "
             << nearest << " with a distance "
             << minDist << " meters\n";
}
	void display(){
		cout<<"Displaying the graph with nodes and edges"<<endl;
		for(auto p:mp){
			cout<<p.first<<"->";
			for(auto q:p.second){
				cout<<"["<<q.first<<","<<q.second<<"]"<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
};
int main(){
	googlemap g;
	g.add("madhapur","HP pertrol",3);
	g.add("Hitech","Bharath petrol",2);
	g.add("madhapur","hari petrol",1);
	g.add("Hitech","Indian petrol",4);
	//g.add(0,2,1);
	g.display();
	g.find("Hitech");
	//g.find(4);
}
