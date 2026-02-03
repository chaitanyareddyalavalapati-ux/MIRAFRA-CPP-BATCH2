#include<iostream>
using namespace std;
int& func(int& x){
    x*=x;
    return x;
}
void print(int& x){
    cout<<"constant &"<<&x<<endl;
}
void print(const int& x){
    cout<<"constant &"<<&x<<endl;
}
void print(int&& x){
    cout<<"constant &&"<<&x<<endl;
}
int main(){
    int x=2;
    //lvalue reference
    int& v=x;
    print(v);
    // const reference lvalue
    const int& y=100;
    print(y);
    //rvalue
    int&&r =80;
    print(r);
    int& u=func(x);
    print(u);
    
}