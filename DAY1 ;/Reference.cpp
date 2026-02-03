#include<iostream>
#include<vector>
using namespace std;
void func(int& n){
    n=n*n;
}
int& fun(int &n){
   // int n=5;
    static int &r=n;
    return r;
}
// Display API
void displayy(const int& n){
   // n=n+n;
    cout<<n<<endl;
}
// calibration API
void display(int& n){
    n=n+n;
    cout<<n<<endl;
}
int main(){
    int a=20;
    int *p=&a;
     cout<<a<<endl;
    cout<<p<<endl;
    int &ref=a;
    cout<<&ref<<endl;
    ref=10;
    // for const 
    cout<<a<<endl;
    const int aa=10;
    const int&reff=aa;
    cout<<reff;
    // refernce to pointer
    func(a);
    cout<<a<<endl;
    int r=fun(a);
    cout<<r<<endl;
   displayy(a);
    display(a);
    
    // to avoid copy of whole  string
    vector<int> vect{1,2,3};
    for(const auto&p:vect){
        cout<<&p<<" "<<p<<" ";
    }
    
    
    cout<<endl;
    
}
