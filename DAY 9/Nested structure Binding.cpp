#include<iostream>
#include<map>
#include<tuple>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    map<int,pair<string ,int>>employee={{100,{"chaitu",100000}},{101,{"chai",500000}},{102,{"vmshi",40000}}};
    for(auto&[a,info]:employee){
        auto&[b,c]=info;
        if(c<100000){
            c=c+((c*6)/100);
        }
    }
    for(auto[a,info]:employee){
         auto[b,c]=info;
        cout<<"ID:"<<a<<"name"<<b<<"salary"<<c<<endl;
    }
}