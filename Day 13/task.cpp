#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
	node(int value){
		data=value;
		left=nullptr;
		right=nullptr;
	}
};
class car{
	node* node
	string name;
	string manufacturer;
	int rating;
	public:
	car(string name,string man,int rate):name(name),manufacturer(manu),node(rate){}
	void display(){
		cout<<"presenting:"<<endl;
		cout<<name<<manufacturer<<rating<<endl;	
	}
};
void inorder(car *c,node* root){
	if(root==nullptr){
		return;
	}
	inorder(c,root->left);
	cout<<c.display();
	inorder(c,root->right);
}
int main(){
	car c[3];
	//for(int i=0;i<3;i++){
		c[0]("thar","mahindra",5);
		c[1]("rolls","huu",4);
		c[2]("benz","me",3);
	//}
	c.inorder(c,root);

}
