#include<iostream>
#include<vector>
#include<list>
#include<array>
using namespace std;
template<typename iterator>
void print_all(iterator first,iterator last){
    while(first!=last){
        cout<<*first<<" ";
        ++first;
    }
    cout<<endl;
}
int main(){
    vector<int>v={1,2,3,4};
    print_all(v.begin(),v.end());
    array<int,4>arr={5,6,7};
    print_all(arr.begin(),(arr.begin()+4));
   // int p[]={8,9,10};
   //int* p=new int[]{9,9,10};
    print_all(p,p+3);
}