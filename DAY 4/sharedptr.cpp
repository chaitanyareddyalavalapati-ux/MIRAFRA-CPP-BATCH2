#include<iostream>
#include<memory>
using namespace std;
class sensor{
    int data;
    public:
    sensor(int d):data(d){}
    void logger();
    void display();
    void control();
    int read()const{
        return data;
    }
    
};
void logger(shared_ptr<sensor>p){
    cout<<"logger accessed"<<p->read()<<endl;
}
void display(shared_ptr<sensor>p){
    cout<<"Display accessed"<<p->read()<<endl;
    
}
void control(shared_ptr<sensor>p){
    cout<<"Control accessed"<<p->read()<<endl;
}
int main(){
    shared_ptr<sensor> p=make_shared<sensor>(25);
    logger(p);
    control(p);
    display(p);
}