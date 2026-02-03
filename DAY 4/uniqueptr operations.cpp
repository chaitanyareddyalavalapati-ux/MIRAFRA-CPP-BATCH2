#include<iostream>
#include<memory>
using namespace std;
void alter(unique_ptr<int>* pq){
    *pq=make_unique<int>(300);
    //**pq=100;
    cout<<"Resource inside"<<**pq<<endl;
     cout<<"*p"<<(*pq).get()<<endl;
    cout<<pq<<endl;
}
int main(){
    unique_ptr<int> uniptr=make_unique<int>(10);
    cout<<"Resource inside"<<*uniptr<<endl;
    cout<<&uniptr<<endl;//stack
    //int* p=uniptr.get();
    alter(move(&uniptr));
    if(!uniptr)cout<<"Moved"<<endl;
}