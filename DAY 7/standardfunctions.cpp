#include<iostream>
#include<functional>
using namespace std;
// Normal function
void add(int a,int b){
    cout<<"Function addition: "<<a+b<<endl;
}
//functor
struct fun{
    void operator()(int a,int b){
        cout<<"Function subtraction through functor:"<<a-b<<endl;
    }
};
class A{
    public:
    static void display(int x,int y){
        cout<<"Through member function: "<<(x/y)<<endl;
        cout<<"Finally Completed"<<endl;
    }
};
int main(){
    function<void(int,int)>f;
    //Normal 
    f=add;
    f(10,3);
    
    //functor
    f=fun();
    f(20,9);
    
    // lambda
    f=[](int a,int b){
        cout<<"Multiplication through lambd: "<<a*b<<endl;
    };
    f(2,3);
    
    // class member function
    f=&A::display;
    f(10,2);
    
}





















/*class A{
    int a;
    public:
   static void print(int x){
        cout<<"hello finished:"<<x<<endl;
    }
};*/
/*using funcptr= int(*)(int,int);
int add(int a,int b){
    return a+b;
}*/
/*int main(){
   //funcptr f=add;
   //cout<<"Result: "<<f(2,3)<<endl;
   int localVar = 10;
    auto lambda = [localVar](int x)mutable
    {
        localVar++;
        cout<<(x+localVar)<<endl;
    };
    lambda(1);
}*/