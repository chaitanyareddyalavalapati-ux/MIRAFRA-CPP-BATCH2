#include<iostream>
using namespace std;
template<typename T>
class customvector{
    size_t size;
    size_t capacity;
    T* data;
    public:
    customvector():size(0),capacity(0),data(nullptr){}
    // copy cpnstructor
    customvector(const customvector& obj){
        size=obj.size;
        capacity=obj.capacity;
        data=new T[obj.size];
        for(size_t i=0;i<obj.size;i++){
            data[i]=obj.data[i];
        }
    }
    // copy assignment
    customvector& operator=(const customvector& obj){
        if(this==&obj) return *this;
        if(this!=&obj){
            delete[] data;
            size=obj.size;
            capacity=obj.capacity;
             data=new T[obj.size];
            for(size_t i=0;i<obj.size;i++){
                data[i]=obj.data[i];
            }
        }
        return *this;
    }
    // move constructor
    customvector(customvector&& obj){
        size=obj.size;
        capacity=obj.capacity;
        data=obj.data;
        obj.data=nullptr;
        obj.size=0;
        obj.capacity=0;
    }
    // move assignment
    customvector& operator=(customvector&& obj){
        if(this==&obj) return *this;
        if(this!=&obj){
            delete[] data;
            size=obj.data;
            capacity=obj.capacity;
            data=obj.data;
            obj.data=nullptr;
            obj.size=0;
            obj.capacity=0;
        }
        return *this;
    }
    // push_back
    void push_back(T value){
        if(size>=capacity){
            grow();
        }
        data[size++]=value;
    }
    // implace_back
    void implace_back(T value){
        if(size==capacity){
            grow();
        }
        data[size++]=value;
    }
    void grow(){
        size_t newcap=(capacity==0)?1:capacity*2;
        T* newdata=new T[newcap];
        // copy
        for(size_t i=0;i<size;i++){
            newdata[i]=data[i];
        }
        delete[] data;
        data=newdata;
        capacity=newcap;
        newdata=nullptr;
    }
     T& front(){
        return *(data);
    }
    T& back(){
        return *(data+(size-1));
    }
    // iterator
    T* begin(){
        return data;
    }
    // end
    T* end(){
        return data+size;
    }
    // size
    size_t siz(){
        return size;
    }
    // access
    T& operator[](int index){
        return data[index];
    }
    // at  
    T& at(int index){
        if(index<0||index>=size){
            throw out_of_range("Inex is not valid");
        }
        return data[index];
    }
    // pop_back
    T& pop_back(){
        data[size]=0;
        size=size-1;
    }
    // clear
    void clear(){
        for(size_t i=0;i<size;i++){
            data[i]=0;
        }
        size=0;
    }
    // insert
    void insert(size_t pos,T value){
        if(pos>size){
            throw out_of_range("invalid");
        }
        if(size==capacity){
            grow();
        }
        if(pos<size){
            for(size_t i=size-1;i>=pos;i--){
                data[i+1]=data[i];
            }
        }
        data[pos]=value;
        size++;
    }
    // erase
    void erase(size_t pos){
        if(pos<size){
            for(size_t i=pos;i<size-1;i++){
                data[i]=data[i+1];
            }
            size--;
        }
    }
    // empty
    bool empty(){
        if(size==0) return true;
        else return false;
    }
    // destruxtor
    ~customvector(){
        delete[] data;
    }
};
int main(){
    customvector<int> v;
    v.push_back(10);
    
}
