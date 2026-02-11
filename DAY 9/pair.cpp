#include<iostream>
#include<vector>

using namespace std;
class sparse{
    vector<pair<int,int>>p;
    public:
    void set(int value,int index){
        if(value!=0){
            p.push_back({index,value});
        }
    }
    int get(int index)const{
        for(const auto&[i,v]:p){
            if(i==index)
                return v;
        }
        return 0;
    }
    void print(){
        for(auto& [i,v]:p){
            cout<<i<<"->"<<v<<" ";
        }
        cout<<endl;
    }
};
int main(){
    sparse s;
    s.set(1,2);
    s.set(2,3);
    cout<<s.get(2)<<endl;
    s.print();
}
