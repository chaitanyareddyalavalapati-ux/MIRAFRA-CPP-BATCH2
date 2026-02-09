#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main(){
    vector<int>v{10,20,30};
    //v.push_back(40);
    //v.pop_back();
    //v.shrink_to_fit();
    cout<<v.size()<<" "<<v.capacity()<<endl;
    vector<int>::iterator it;
    //v.erase(v.begin()+2);
    cout<<v.size()<<" "<<v.capacity()<<endl;
    for(it=v.begin();it!=v.end();++it){
        cout<<*it<<" ";
    }
      cout<<endl;
    /*v.emplace_back(40);
    for(it=v.begin();it!=v.end();++it){
        cout<<*it<<" ";
    }*/
    cout<<endl;
}