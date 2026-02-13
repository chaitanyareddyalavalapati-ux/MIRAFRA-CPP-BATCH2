#include<iostream>
#include<queue>
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
	/*bool operator>(const process& obj)const{
		return brusttime>obj.brusttime;
	}
	bool operator<(const process& obj)const{
		return brusttime<obj.brusttime;
	}*/
	friend ostream& operator<<(ostream&out,const process& obj){
		out<<obj.id<<" "<<obj.process_name<<" "<<obj.brusttime<<endl;
		return out;
	}
};
struct comapare{
	bool operator()(const process&obj1,const process& obj2){
		return obj1.brusttime<obj2.brusttime;
	}

};
int main(){
	priority_queue<process,vector<process>,comapare>pq;
	//priority_queue<process>pq;
	pq.push(process(1,"add",2));
	pq.push(process(3,"div",6));
	pq.push(process(34,"sub",5));
	pq.push(process(2,"mul",4));
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}

}
