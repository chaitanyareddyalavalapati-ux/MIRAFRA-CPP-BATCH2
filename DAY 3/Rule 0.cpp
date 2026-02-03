#include<iostream>
#include<vector>
using namespace std;
class car{
    vector<int>number;
    public:
    car(int count=0):number(count,0){}
    void get(int index,int numb){
        if(index<number.size()){
            number[index]=numb;
        }
    }
    void display()const {
        cout<<"Total vehicles:"<<number.size()<<endl;
        for(int i=0;i<number.size();i++){
            cout<<"car number "<<i<<number[i]<<endl;
        }
    }
};
int main(){
    car c(2);
    c.get(0,3456);
    c.get(1,6789);
   // c.get(2,9009);
    c.display();       
    car c1(3);
    c1.get(0,3456);
    c1.get(1,6789);
    c1.get(2,890);
    c=c1;
    c.display();
}