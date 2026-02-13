#include<iostream>
#include<queue>
#include<set>
using namespace std;
class process{
	public:
	int id;
	string process_name;
	int brusttime;
	//public:
	process(int i,string n,int brust ){
		id=i;
		process_name=n;
		brusttime=brust;
	}
	friend ostream& operator<<(ostream&out,const process& obj){
		out<<obj.id<<" "<<obj.process_name<<" "<<obj.brusttime<<endl;
		return out;
	}
};
struct comapare{
	bool operator()(const process&obj1,const process& obj2)const{
		if(obj1.brusttime==obj2.brusttime){
			return obj1.id<obj2.id;
		}
		return obj1.brusttime<obj2.brusttime;
	}

};
int main(){
	set<process,comapare>pq;
	pq.insert(process(1,"add",2));
	pq.insert(process(3,"div",6));
	pq.insert(process(34,"sub",5));
	pq.insert(process(2,"mul",4));
	pq.insert(process(3,"mul",4));
	for(auto p:pq){
		cout<<p<<" ";
	}
	cout<<endl;
}
