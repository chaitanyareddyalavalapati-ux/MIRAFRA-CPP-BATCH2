#include<iostream>
#include<utility>
using namespace std;
class A{
    int fuel;
    int* carnumber;
    public:
    A(int f=0,int cn=0):fuel(f),carnumber(new int(cn)){
        
    }
    A(const A& other){
        cout<<"Copy constructor"<<endl;
        delete carnumber;
        fuel=other.fuel;
        carnumber=new int(*other.carnumber);
    }
    A& operator=(const A& other){
        if(this!=&other){
            delete carnumber;
            fuel=other.fuel;
             carnumber=new int(*other.carnumber);
        }
        return *this;
    }
    A(A&& obj)noexcept:fuel(obj.fuel),carnumber(obj.carnumber) {
        cout<<"move constructor"<<endl;
        //fuel=obj.fuel;
        //carnumber=obj.carnumber;
        obj.carnumber=nullptr;
    }
    A& operator=( A&& obj){
        if(this!=&obj){
            fuel=obj.fuel;
            delete carnumber;
            carnumber=obj.carnumber;
            obj.carnumber=nullptr;
        }
        return *this;
    }
    void display( A& obj){
        cout<<obj.fuel<<" "<<*obj.carnumber<<endl;
    }
    void operator()(int f,int c){
        fuel=f;
        carnumber=new int(c);
    }
    ~A(){
        delete carnumber;
    }
};
int main(){
    A a(10,3456);
    a.display(a);
    A b=move(a);
    b.display(b);
    //a.display(a);
    a(30,5060);
    b=move(a);
    b.display(b);
}