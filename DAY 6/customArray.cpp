#include<iostream>
#include<stdexcept>
using namespace std;
template<typename T,size_t N>
class customarray{
    T data[N];
    public:
    customarray(){}
    // access
    T& front(){
        return *(data);
    }
    T& back(){
        return *(data+(N-1));
    }
    // iterator
    T* begin(){
        return data;
    }
    // end
    T* end(){
        return data+N;
    }
    // size
    size_t size(){
        return N;
    }
    // access
    T& operator[](int index){
        return data[index];
    }
    // at  
    T& at(int index){
        if(index<0||index>=N){
            throw out_of_range("Inex is not valid");
        }
        return data[index];
    }
    // fill
    void fill(T value){
        for(size_t i=0;i<N;i++){
            data[i]=value;
        }
    }
    // data
    T* _data(){
        return data;
    }
};
int main(){
    customarray<int,5>p;
    for(int i=0;i<5;i++){
        cin>>p[i];
    }
    cout<<p.front()<<endl;
    cout<<p.back()<<endl;
    p.fill(0);
    for(auto x:p){
        cout<<x<<" ";
    }
    
}