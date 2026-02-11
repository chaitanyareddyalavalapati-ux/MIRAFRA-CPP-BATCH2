#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    public:
    node():data(0),next(nullptr){}
    node(int d){
        data=d;
        next=nullptr;
    }
};
class forwardlist{
    node* head;
    public:
    forwardlist():head(nullptr){}
    // push_front()
    void push_front(int value){
        node* newnode=new node(value);
        if(head==nullptr){
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    // size
    int count(){
        int c=0;
        node* temp=head;
        while(temp){
            temp=temp->next;
            c++;
        }
        return c;
    }
    // display 
    void display(){
        node* temp=head;
        if(head==nullptr){
            cout<<"{}";
        }
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    // insert_after
    /*void insert_after(forwardlist *p,int value){
        forwardlist* newnode=new forwardlist(value);
        forwardlist* temp;
        if(head==p){
            if(head->next!=nullptr){
                temp=head->next;
                head->next=newnode;
                newnode->next=temp;
            }
        }
        else{
            temp=head->next;
            while(temp->next!=p){
                temp=temp->next;
            }
            temp=head->next;
            head->next=newnode;
            newnode->next=temp;
        }
    }*/
    void insert_after(node*p,int value){
        node* newnode=new node(value);
        node* temp;
        if(p->next!=nullptr){
            temp=p->next;
            p->next=newnode;
            newnode->next=temp;
        }
    }
    // pop_front()
    void pop_front(){
        node* del=head;
        if(head!=nullptr){
            head=head->next;
            delete del;
        }
    }
    // begin()
    node* begin(){
        if(head!=nullptr)
        return head;
        else
        return 0;
    }
    // advance()
    void advance(node*&p,int pos){
        for(int i=0;i<pos;i++){
            p=p->next;
        }
    }
    // resize
    void resize(int value){
        int co=count();
        node* temp=head;
        // shrinking
        if(value<co){
            for(int i=0;i<value;i++) temp=temp->next;
            node* del=temp->next;
            temp->next=nullptr;
            while(del!=nullptr){
                node* move=del->next;
                delete del;
                del=move;
            }
        }
        // grow
        else if(value>co){//(value>)
            int dif=value-co;
            node*temp=head;
            if(temp==nullptr){
                head=new node(0);
            }
            while(temp->next!=nullptr)temp=temp->next;// here in consition dont take temp
            while(dif){
                node* newnode=new node(0);
                temp->next=newnode;
                dif--;
            }
        }
    }
    // clear
    void clear(){
        node* t=head;
        while(t){
            node* del=t;;
            t=t->next;
            delete del;
        }
        head=nullptr;
    }
    //  erase_after
    void erase_after(node*p){
        node* temp;
        if(p->next!=nullptr){
            temp=p->next;
            p->next=temp->next;
            delete temp;
        }
    }
};
int main(){
    forwardlist f;
    f.push_front(30);
    f.push_front(40);
    f.push_front(50);
    f.push_front(60);
    f.push_front(70);
    f.display();
    cout<<f.count()<<endl;
    f.pop_front();
    f.display();
    node*p=f.begin();
    int pos=2;
    f.advance(p,pos);
    f.insert_after(p,200);
    f.display();
    f.pop_front();
    f.display();
    f.resize(5);
    f.display();
     pos=1;
    f.advance(p,pos);
    //f.clear();
    f.erase_after(p);
    f.display();
    
}