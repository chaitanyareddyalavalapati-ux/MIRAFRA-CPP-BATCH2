#include<iostream>
#include<memory>
using namespace std;
//template<typename T>
void deletee(int *p){
    free(p);
    cout<<"deleted"<<endl;
}
struct customdeleter{
    void operator()(int *p)const{
        free(p);
        cout<<"deleted"<<endl;
    }
};
class deleterr{
    public:
    void operator()(int *p)const{
        free(p);
        cout<<"deleted"<<endl;
    }
}
int main(){
    //unique_ptr<int,customdeleter<int>>p{(int*)malloc(sizeof(int))};
    // custom deleter using function pointer
   // unique_ptr<int,void(*)(int *)>p{(int*)malloc(sizeof(int)),deletee};
   unique_ptr<int,>p{(int*)malloc(sizeof(int)),deletee};
    if(!p){
        cerr<<"memory allocation failed"<<endl;
        return 1;
    }
    *p=1000;
    cout<<*p<<endl;
    
}