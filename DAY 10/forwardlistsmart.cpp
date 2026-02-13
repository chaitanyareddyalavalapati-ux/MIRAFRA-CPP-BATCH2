#include <iostream>
#include <memory>
using namespace std;
struct node{
    int data;
    //node* next;
    unique_ptr<node> next;
    public:
    node():data(0),next(nullptr){}
    node(int d){
        data=d;
        next=nullptr;
    }
};
class forwardlist{
    unique_ptr<node> head;
    public:
    forwardlist():head(nullptr){}
    // push_front()
    void push_back(int value){
       unique_ptr<node>  newnode=make_unique<node>(value);
        if(head==nullptr){
            head=move(newnode);
        }
        else{
            newnode->next=move(head);
            head=move(newnode);
        }
    }
    void pop_front(){
        auto del=move(head);
        head=move(del->next);
    }
    // display
    // display 
    void display(){
        node* temp=head.get();
        if(temp==nullptr){
            cout<<"{}";
        }
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=(temp->next).get();
        }
        cout<<endl;
    }
};
int main(){
    forwardlist f;
    f.push_back(10);
    f.push_back(20);
    f.push_back(20);
    f.display();
    f.pop_front();
    f.display();
}
