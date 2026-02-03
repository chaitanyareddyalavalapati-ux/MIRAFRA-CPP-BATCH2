#include<iostream>
#include<memory>
using namespace std;
template<typename T>
class custom{
    T* data;
    public:
     explicit custom(T* p=nullptr):data(p){
        cout<<"custom "<<endl;
    }
    ~custom(){
        cout<<"deleted"<<endl;
        delete data;
    }
    custom(const custom& obj)=delete;
    custom& operator=(const custom& obj)=delete;
    T* operator*() const{
        return data;
    }
    T* operator->() const{
        return data;
    }
    // check if the pointer is valid
    bool valid() const{
        return data!=nullptr;
    }
    T* release(){
        T*temp=data;
        data=nullptr;
        return temp;
    }
    // reset
    void reset(T* newint=nullptr){
        delete data;
        data=newint;
    }
    
};
class Test{
    public:
    Test(){cout<<"Test constructor"<<endl;}
    ~Test(){
        cout<<"Destructor"<<endl;
    }
    void greet(){
        cout<<"Hello"<<endl;
    }
};
int main(){
    custom<Test> p1(new Test());
    p1->greet();
    cout<<&p1<<endl;
    p1.reset();
    cout<<*p1<<endl;
    p1.reset(new Test());
     cout<<&p1<<endl;
    custom<Test> p2(new Test());
    Test* raw=p2.release();
    if(!p2.valid()){
        cout<<"yes"<<endl;
    }
    delete raw;
}