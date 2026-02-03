#include<iostream>
#include<thread>
#include<atomic>
using namespace std;
atomic<int>count{0};
//int count=0;
void funct(){
    for(int i=0;i<500;i++){
        count++;
    }
}
int main(){
    thread t1(funct);
    thread t2(funct);
    t1.join();
    t2.join();
    cout<<count<<endl;
}