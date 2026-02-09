#include<iostream>
#include<vector>
#include<ranges>
#include<map>
#include<string>
using namespace std;
int main(){
    vector<int>v{1,2,3,5,6,7};
    auto even=v|views::filter([](int n){
        return n%2==0;
    });
    auto square=v|views::transform([](int n){
        return n*n;
    });
    for(auto q:even){
        cout<<q<<" ";
    }
    cout<<endl;
    for(auto q:square){
        cout<<q<<" ";
    }
    cout<<endl;
    for(auto q:v){
        cout<<q<<" ";
    }
    cout<<endl;
    // reverse
    auto reversed=v|views::reverse;
    cout<<"reversed"<<endl;
    for(auto q:reversed){
        cout<<q<<" ";
    }
    cout<<endl;
    // standard std::map<Key, T> ;
    map<int,string>mp{{1,"one"},{2,"two"},{3,"Three"},{4,"four"},{5,"five"}};
    cout<<"Keys"<<endl;
    for(auto pq:mp|views::keys){
        cout<<pq<<" ";
    }
    cout<<endl;
    cout<<"values"<<endl;
     for(auto pq:mp|views::values){
        cout<<pq<<" ";
    }
    cout<<endl;
    // views will not modify the original data but it will just make the data modified as per our requires
}