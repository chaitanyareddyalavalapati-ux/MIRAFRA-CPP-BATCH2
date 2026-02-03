#include<iostream>
using namespace std;
int main(){
    int a=10;
    const int *p=&a;// data is constant
   // *p=30;// error
    cout<<*p<<endl;
    
    int b=20;
    int* const p1=&b;// pointer is constant
    //p1=&a;// error
    cout<<*p1<<endl;
    
    int c=40;
    const int *const p2=&c;// both are constant
    //*p=40// error
    //p=&a;// error
    cout<<*p2<<endl;
    
    const int d=50;
    const int&p=d;// const reference 
}