#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main(){
    list<int>l1{1,2,3};
    list<int>l2{4,5,6};
    //auto it=l1.begin();
    //it++;
   /* l1.splice(it,l2);// move all elements of list2 to list1 befor position it
    for(auto p:l1){
        cout<<p<<" ";
    }
    cout<<endl;
    for(auto q:l2){
        cout<<q<<" ";
    }
    cout<<endl;*/
    // splice single element
    /*auto itt=l1.begin();
    itt++;
    auto it=l2.begin();
   // it++;
    l1.splice(itt,l2,it);
    for(auto p:l1){
        cout<<p<<" ";
    }
    cout<<endl;
    for(auto q:l2){
        cout<<q<<" ";
    }*/
    // splice range of  element
    auto itt=l1.begin();
    itt++;
    auto it=l2.begin();
   // it++;
   auto end=l2.begin();
   advance(end,2);
    l1.splice(itt,l2,it,end);
    for(auto p:l1){
        cout<<p<<" ";
    }
    cout<<endl;
    for(auto q:l2){
        cout<<q<<" ";
    }
}