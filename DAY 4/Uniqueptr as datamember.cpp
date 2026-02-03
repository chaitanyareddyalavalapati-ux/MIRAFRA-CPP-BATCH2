#include<iostream>
#include<memory>
using namespace std;
class fun{
    unique_ptr<int>ptr;
    public:
    fun(int p):ptr(new int(p)){
        cout<<"constructor called"<<endl;
    }
    void show()const{
        cout<<*ptr<<endl;
    }
};
int main(){
    fun f(2);
    f.show();
}
