#include<iostream>
using namespace std;
class sensor{
    int value;
    mutable int count;
    public:
    sensor(int v=0):value(v){    count=0;}
    void write(int n){
        value=n;
    }
    int get() const{
        count++;
        return value;
    }
    int getcount()const{
        return count;
    }
};
int main(){
    sensor s(10);
    cout<<"Read"<<s.get()<<endl;
    s.write(100);
    cout<<"Read"<<s.get()<<endl;
    cout<<s.getcount()<<endl;
}