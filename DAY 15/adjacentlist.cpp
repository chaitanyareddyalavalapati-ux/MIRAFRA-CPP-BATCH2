#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class graph{
	unordered_map<int,list<int>>mp;
	public:
	void add(int u,int v){
		mp[u].push_back(v);//directed;
	}
	void print(){
		for(const auto& p:mp){
		    cout<<p.first<<"->";
			for(const auto& q:p.second){
				cout<<q<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
};
int main(){
	graph g;
	g.add(0,1);
	g.add(0,2);
	g.add(1,0);
	g.print();
}
