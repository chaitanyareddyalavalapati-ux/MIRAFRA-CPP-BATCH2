#include<iostream> 
#include<functional>
using namespace std;
/*void registercallback(void(*cb)(int)){
    cb(20);
}*/
void registercallback(function<void(int)>q){
    q(200);
}
int main(){
   // function<void(int)>q;
   int threshold=50;
   registercallback([threshold](int v)mutable{
       threshold=100;
       if(v>threshold){
            cout<<"Sensor burn out"<<endl;
        }
        else{
            cout<<"Sensor working"<<endl;
        }
    });
}
