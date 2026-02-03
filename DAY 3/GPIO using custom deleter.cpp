#include<iostream>
#include<memory>
#include<utility>
using namespace std;
class GPIO{
    int pin;
    public:
    GPIO(int p):pin(p){
        cout<<"GPIO"<<pin<<"Initialized\n";
    }
    void write(bool value){
        cout<<"GPIO pin"<<pin<<"Writr:"<<(value?"HIGH":"LOW")<<endl;
    }
    int getpin() const{
        return pin;
    }
    /*~GPIO(){
        cout<<"Releasing GPIO PIN"<<pin<<endl;
    }*/
};
// custom deleter with state
class customDeleter{
    bool cloc;
    public:
    explicit customDeleter(){
         cloc=false;
         cout<<"Defualt"<<endl;
    }
    explicit customDeleter(bool c):cloc(c){}
    void operator()(GPIO* gpio)const{
        if(cloc){
            cout<<"GPIO CLOCK ACTIVE"<<gpio->getpin()<<endl;
        }
        else{
            cout<<"GPIO CLOCK INACTIVE"<<gpio->getpin()<<endl;
        }
        cout<<"Releasing GPIO PIN"<<gpio->getpin()<<endl;
         delete gpio;
    }
    
};
int main(){
    customDeleter d{}; // I can take deleter also
    unique_ptr<GPIO,customDeleter>p(new GPIO(5),d);
    //unique_ptr<GPIO,customDeleter>p(new GPIO(5),customDeleter{true});
   // auto p=make_unique<GPIO>(5);
    //p->write(true);
}