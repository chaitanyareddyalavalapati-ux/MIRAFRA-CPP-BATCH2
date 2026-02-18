#include<iostream>
#include<string>
using namespace std;
class car{
	struct node{	
		string name;
		string manufacturer;
		int rating;
		node* left;
		node* right;
		node(string s,string m,int r):name(s),manufacturer(m),rating(r),left(nullptr),right(nullptr){}
	};
	node* head;
	public:
	car():head(nullptr){}
	void insert(string name,string manufacturer,int rate){
		insertimp(head,name,manufacturer,rate);
	}
	void inorder(){
		inorderimp(head);
	}
	private:
	void inorderimp(node* head){
	    if(head==nullptr) return;
		inorderimp(head->right);
		cout<<"car name: "<<head->name<<"| manufacturer:"<<head->manufacturer<<"| rating : "<<head->rating<<endl;
		inorderimp(head->left);
	}
	void insertimp(node*& p,string name,string manufacturer,int rate){
		if(p==nullptr) {
		    p=new node(name,manufacturer,rate);
		    return;
		}
		if(rate<p->rating)
			insertimp(p->left,name,manufacturer,rate);
		else if(rate>p->rating)
			insertimp(p->right,name,manufacturer,rate);
	}
};
int main(){
	car c;
	c.insert("Thar","Mahindra",5);
	c.insert("Rolls Royce","Rolls Royce manufactures",4);
	c.insert("Tata","Tata motors",4);
	c.insert("Merceds","Mercedes Benz",3);
	c.inorder();
}
