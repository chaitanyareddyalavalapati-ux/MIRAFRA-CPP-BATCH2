#include<iostream>
using namespace std;
consteval int square(int x){
	return x*x;
}
int main(){
	constexpr int a=square(2);
	cout<<"a:"<<a<<endl;
}
