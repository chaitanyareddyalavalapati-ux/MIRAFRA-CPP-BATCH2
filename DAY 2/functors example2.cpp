#include<iostream>
//#include<unistd>
using namespace std;
class LED{
    bool state;
    int switchh;
     public:
    LED(){
        state=false;
        switchh=0;
    }
    void LED_on(){
       cout<<"LED ON"<<endl;
    }
    void LED_off(){
        cout<<"LED OFF"<<endl;
    }
    void operator()(bool y,int s){
        if(state!=y && s==1)
        state=y;
    }
    void display(){
        if(state) LED_on();
         else LED_off();
    }
};
int main(){
    LED l;
    int s;
    cin>>s;
    l(true,s);
    l.display();
    cin>>s;
     l(false,s);
    l.display();
}