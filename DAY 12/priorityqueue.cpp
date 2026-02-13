#include<iostream>
#include<queue>
using namespace std;
int main(){
	priority_queue<int>q;
	q.push(20);
	q.push(40);
	q.push(10);
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
	cout<<endl;
	priority_queue<int,vector<int> ,greater<int>>qq;
	qq.push(20);
	qq.push(40);
	qq.push(10);
	while(!qq.empty()){
		cout<<qq.top()<<" ";
		qq.pop();
	}
	cout<<endl;
}
