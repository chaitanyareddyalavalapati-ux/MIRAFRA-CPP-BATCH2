#include<iostream>
#include<optional>
using namespace std;
class myqueue
{
    struct Node
    {
        int val;
        Node* next;
        Node(int v):val(v),next(nullptr)
        {
           // cout<<"constructor in Node\n";
        }
    };
    Node* head;
    public:
    myqueue()
    {
        head=nullptr;
    }
    void push(int v)
    {
        Node* newnode=new Node(v);
        if(head==nullptr)
        {
            head=newnode;
        }
        else
        {
            Node* temp=head;
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void pop()
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    void print()
    {
        Node* temp=head;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    optional<int> front()
    {
        if(head!=nullptr)
        {
            return head->val;
        }
        else
        {
            return nullopt;
        }
    }
    optional<int> back()
    {
        if(head!=nullptr)
        {
            Node* temp=head;
            while(temp->next)
            {
                temp=temp->next;
            }
            return temp->val;
        }
        else
        {
            return nullopt;
        }
    }
    bool empty()
    {
        if(head!=nullptr)
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
        Node* temp=head;
        int c=0;
        while(temp)
        {
            c++;
            temp=temp->next;
        }
        return c;
    }
};
int main()
{
    myqueue q;
    q.push(3);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.pop();
    q.print();
    auto it=q.front();
    cout<<"front()="<<*it<<endl;
    auto it2=q.back();
    cout<<"back()="<<*it2<<endl;
    cout<<"empty()="<<boolalpha<<q.empty()<<noboolalpha<<endl;
    cout<<"size()="<<q.size()<<endl;
}








