#include<iostream>
using namespace std;
template<typename T>
void process(T value){
    if constexpr(sizeof(T)==4){
        cout<<"32 bit\n"<<endl;
    }
    else{
        cout<<"Not 32 bit\n"<<endl;
    }
}
int main(){
    process(10);
    process(20.5);
}