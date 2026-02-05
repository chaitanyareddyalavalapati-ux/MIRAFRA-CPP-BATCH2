#include<iostream>
#include<memory>
using namespace std;
class c2;
class c1{
    public:
    static int alive;
    shared_ptr<c2> b;
  
    c1(){
       ++alive;
       cout<<"c1 created"<<endl;
    }
    ~c1(){
        --alive;
        cout<<"c1 deleted"<<endl;
    }
};
class c2{
        public:
    static int alive;
   // shared_ptr<c1> b;
   weak_ptr<c1>b;
    c2(){
       ++alive;
       cout<<"c2 created"<<endl;
    }
    ~c2(){
        --alive;
        cout<<"c2 deleted"<<endl;
    }
};
int c1::alive=0;
int c2::alive=0;
int main(){
    {
        shared_ptr<c1> p1=make_shared<c1>();
        shared_ptr<c2> p2=make_shared<c2>();
        p1->b=p2;
        p2->b=p1;
        cout<<"indise block"<<endl;
        cout<<"c1 alive:"<<c1::alive<<endl;
        cout<<"c1 alive:"<<c2::alive<<endl;
    }
    cout<<"outside"<<endl;
    cout<<"c1 alive:"<<c1::alive<<endl;
    cout<<"c1 alive:"<<c2::alive<<endl;
}
