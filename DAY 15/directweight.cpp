#include<iostream>
#include<vector>
#include<limits>
#include<iomanip>
using namespace std;
template<typename T>
class directedweighted{
	int vertices;
	T inf;
	vector<vector<T>> matrix;
	public:
	directedweighted(int v){
		vertices=v;
		inf=numeric_limits<T>::max();
		matrix.resize(v,vector<T>(v,inf));// resize means change the size
	}
	void add(int scr,int dest,T w){
		if(scr>=0&& scr<vertices && dest>=0 &&dest<vertices){
			matrix[scr][dest]=w;
		}
	}
	// printing
	void print(){
	for(const auto& p:matrix){
		for(const auto& q:p){
			if(q==inf){
				cout<<setw(6)<<"INF";
			}
			else
			cout<<setw(6)<<q;
		}
		cout<<endl;
	}
	cout<<endl;
	}
};
int main(){
	directedweighted<int> g(3);
	g.print();
	g.add(0,1,3);
	g.add(2,1,4);
	g.print();
	
}
