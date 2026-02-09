#include<iostream>
#include<span>
#include<vector>
#include<algorithm>
#include<ranges>
using namespace std;
int main(){
    vector<int>v{1,2,3,4};
    ranges::sort(v);
    
    for(auto p:v){
        cout<<p<<" ";
    }
    cout<<endl;
    
    // find the element
    auto q=ranges::find(v,3);
    if(q!=v.end()){
        cout<<"found 3 at index:"<<distance(v.begin(),q)<<endl;
    }
    
    // copy
    vector<int>destination(v.size());
    ranges::copy(v,destination.begin());
    cout<<"copied"<<endl;
    for(auto p:v){
        cout<<p<<" ";
    }
    cout<<endl;
    ranges::for_each(destination,[](int n){
      // return n;
       cout<<n<<" ";
    });
    cout<<endl;
    // boolalpha
    auto c=ranges::all_of(v,[](int n){
        return n>0;
    });
    cout<<"Boolalpha: "<<noboolalpha<<c<<endl;
    // count
    int count_of_16=ranges::count(v,1);
    cout<<"countes"<<count_of_16<<endl;
    
}