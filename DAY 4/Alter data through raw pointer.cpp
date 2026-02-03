#include<iostream>
#include<memory>
using namespace std;
void alter(int* pq){
    *pq=100;
    cout<<"Resource inside"<<*pq<<endl;
    cout<<&pq<<endl;
}
int main(){
    unique_ptr<int> uniptr=make_unique<int>(10);
    cout<<"Resource inside"<<*uniptr<<endl;
    cout<<&uniptr<<endl;
    int* p=uniptr.get();
    alter(p);
}