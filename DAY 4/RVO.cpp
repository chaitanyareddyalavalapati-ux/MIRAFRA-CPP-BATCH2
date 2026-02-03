#include<iostream>
using namespace std;
class car{
    int fuel;
    int number;
    public:
    car(int f=0,int n=0):fuel(f),number(n){
        
    }
    void display(const car& obj){
        cout<<obj.fuel<<" "<<obj.number<<endl;
    }
    
};
 car create(){
    car v1(80,1);
    return v1;// in olden here copy temp //destructor
}
int main(){
    int x=create();// here again copy 
    x.display(x);
}