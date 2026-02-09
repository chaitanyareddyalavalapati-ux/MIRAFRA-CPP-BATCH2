#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int main(){
    vector<pair<int,int>>v;
    v.push_back({1,2});
    v.push_back({2,3});
    for(const auto&[index,value]:v){
        cout<<index<<value<<endl;
    }
}