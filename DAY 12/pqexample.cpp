#include<iostream>
#include<queue>
using namespace std;
class process{
	int id;
	string process_name;
	int brusttime;
	public:
	process(int i,string n,int brust ){
		id=i;
		process_name=n;
		brusttime=brust;
	}
	bool operator>(const process& obj)const{
		return brusttime>obj.brusttime;
	}
	bool operator<(const process& obj)const{
		return brusttime<obj.brusttime;
	}
	friend ostream& operator<<(ostream&out,const process& obj){
		out<<obj.id<<" "<<obj.process_name<<" "<<obj.brusttime<<endl;
		return out;
	}
};
int main(){
	//priority_queue<process,vector<process>,greater<process>>pq;
	priority_queue<process>pq;
	pq.push({1,"add",2});
	pq.push({3,"div",6});
	pq.push({34,"sub",5});
	pq.push({2,"mul",4});
	while(!pq.empty()){
		//process t=pq.top();
		//pq.pop();
		cout<<pq.top();
		pq.pop();
	}

}
