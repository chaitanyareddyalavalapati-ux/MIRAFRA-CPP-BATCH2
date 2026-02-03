#include<iostream>
using namespace std;
struct s{
    int x;
    s(){}
    s(int v=0):x(v){}
    void display(const s& obj){
        cout<<obj.x<<endl;
    }
};
int main(){
    //s obj{};// becuase no default constructor
  // s obj;// garbae value
   // s obj{2};// value initialization
   // obj.display(obj);
   // s obj();
}