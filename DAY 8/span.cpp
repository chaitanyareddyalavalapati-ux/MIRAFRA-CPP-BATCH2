#include<iostream>
#include<span>
#include<vector>
using namespace std;
/*void fun(span<int> v){
    for(auto p:v){
        cout<<p<<" ";
    }
    cout<<endl;
}*/
  int size=4;
void fun(span<int> s){
    for(auto& d:s){
        d*=2;
    }
   for(auto p:s){
        cout<<p<<" ";
    }
    cout<<endl;
}
void print(span<int>s,const string& ss){
    cout<<ss<<":";
    for(auto p:s){
        cout<<p<<" ";
    }
    cout<<endl;
}
int main(){
    //vector<int>v{1,2,3,4};
    //span<int> s(v);
   /* fun(v);
    int arr[3]{1,3,4};
    fun(arr);*/
    int* ptr=new int[::size]{1,2,3};
    span<int> s(ptr,::size);
    fun(s);
    cout<<"after span"<<endl;
    for(int i=0;i<::size;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    // take first elements
    auto p=s.first(2);
    auto q=s.last(2);
    print(p,"first");
    print(q,"last");
    auto w=s.subspan(1,2);
    print(w,"substring");
    delete[] ptr;
    
}