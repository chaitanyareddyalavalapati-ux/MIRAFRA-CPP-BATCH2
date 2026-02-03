#include<iostream>
#include<memory>
//#include<ofstream>
using namespace std;
//template<typename T>
class sensor{
   int c;
    public:
    sensor(int p){
        c=p;
        cout<<"hey"<<endl;
    }
    ~sensor(){
        cout<<"completed"<<endl;
    }
    void display(){
        cout<<c<<endl;
    }
    friend ostream& operator <<(ostream&fout,const sensor&obj);
};
ostream& operator <<(ostream&fout,const sensor&obj){
    fout<<obj.c;
    return fout;
}
int main(){
    int x=10;
    unique_ptr<sensor> p1=make_unique<sensor>(10);
    cout<<&p1<<endl;
    p1->display();
    sensor* d=p1.get();// before move it is pointing the object here ownership is not transfering but we are getting the data without move
    *d=*d+10;
    cout<<d<<endl;
    unique_ptr<sensor> p2=move(p1);
    if(!p1)cout<<"moved"<<endl;
     d=p1.get();// here it showing nullptr
    cout<<d<<endl;
    //delete[] d;
}