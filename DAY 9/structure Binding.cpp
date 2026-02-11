#include<iostream>
#include<utility>
using namespace std;
struct s{
    mutable int x:2;// to make const function to change the value
    volatile double y;// to tell compiler not to optimise its value maybe change
};
s f(){// function to initialise the structure variables
    return s{1,2.2};
}
int main(){
    const auto&[x,y]=f();
    cout<<x<<" "<<y<<endl;
    x=3;// no error as i am changing the mutable
    cout<<x<<" "<<y<<endl;
    //y=3.3;// error as it is const variable
    //cout<<x<<" "<<y<<endl;
    cout<<"second scenarioes"<<endl;
    
     //auto& [xx,yy]=f();
    xx=-2;
    yy=3.3;
    cout<<xx<<" "<<yy<<endl;
}
