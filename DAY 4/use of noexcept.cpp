#include<iostream>
#include<vector>
using namespace std;
class GPIO{
    int pin;
    public:
    GPIO(int p=0):pin(p){}
    GPIO(const GPIO& obj){
        pin=obj.pin;
        cout<<"Copy called"<<endl;
    }
    GPIO(GPIO&& obj){
        cout<<"Move Called"<<endl;
    }
    ~GPIO(){
        cout<<"Destructer"<<endl;
    }
};
int main(){
    int x=10;
    vector<GPIO> v;
    //v.push_back(GPIO(5));
    v.push_back(GPIO(x));
}

// note without noexcept compiler will call copy only
// for copy we are using constA& beacuse  when no move and copyinf rvalue it is allowed