#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class ecommerce{
    int discount;
    public:
    ecommerce(int d):discount(d){}
    int operator()(int a){
        int d=(discount*a/100);
        a=a-d;
        return a;
    }
};
int main(){
    vector<int>v{100,200,300};
    vector<int>discountprices(v.size());
    int discount=10;
    ecommerce e(discount);
    transform(v.begin(),v.end(), discountprices.begin(),e);
    for(auto &x:discountprices) cout<<x<<" ";
    cout<<endl;
}