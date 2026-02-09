#include<iostream>
#include<functional>
using namespace std;

void registerCallback(function<void(int)>cb){
    cb(75);
}

void sensorlog(int sensorID,int value){
    cout<<"sensorID: "<<sensorID<<" value: "<<value<<endl;
}

int main(){
    auto boundvalue=bind(sensorlog,101,placeholders::_1);
    registerCallback(boundvalue);
}