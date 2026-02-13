#include<iostream>
#include<optional>
using namespace std;
class mystack
{
    int *arr;
    int top_size;
    int max_size;
    public:
    mystack(int i=0):arr(new int[i])
    {
        top_size=-1;
        max_size=i;
        cout<<"constructor\n";
    }
    void push(int val)
    {
        if(top_size>=max_size)
        {
            cout<<"stack overflow\n";
            return;
        }
        top_size++;
        arr[top_size]=val;
    }
    void pop()
    {
        if(top_size<0)
        {
            cout<<"stack underflow\n";
            return;
        }
        arr[top_size--]=0;
        cout<<"top element popped\n";
    }
    bool empty()
    {
        if(top_size<0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int size()
    {
        return (top_size+1);
    }
    optional<int> top()
    {
        if(top_size>=0)
        return arr[top_size];
        else
        return nullopt;
    }
    void display()
    {
        if(top_size<0)
        {
            cout<<"stack is empty\n";
            return;
        }
        for(int i=0;i<=top_size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    ~mystack()
    {
        delete[] arr;
        cout<<"destructor\n";
    }
};
int main()
{
    mystack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    auto r=st.top();
    cout<<"top()="<<*r<<endl;
    st.pop();
    st.display();
    return 0;
}







