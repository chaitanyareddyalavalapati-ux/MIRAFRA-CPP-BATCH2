#include<iostream>
#include<memory>
using namespace std;
class BST{
	struct node{
		int data;
		unique_ptr<node> left;
		unique_ptr<node> right;
		node(int value){
			data=value;
		}
	};
	unique_ptr<node> root;
	public: 
	void insert(int value){
		insertimp(root,value);
	}
	void inorder(){
	    inorderimp(root.get());
	}
	void search(int value){
	     if(searchimp(root.get(),value)) cout<<"Found"<<endl;
	     else cout<<"Not found"<<endl;
	}
	void removeimp(int value){
	    removee(root,value);
	}
	private:
void insertimp(unique_ptr<node>&p,int value){
    	if(!p)
    	p=make_unique<node>(value);
	    if(value<p->data){
		    insertimp(p->left,value);
	    }
	    else if(value>p->data){
		    insertimp(p->right,value);
	    }
}
void inorderimp(const node* root){
	if(root==nullptr) return;
	inorderimp(root->left.get());
	// Print current node info
    std::cout << "Node Data: " << root->data
              << " | Address: " << root
	      << " | Left: " << root->left.get()
	      << " | Right: " << root->right.get()
	      << std::endl;

    inorderimp(root->right.get());
}
void removee(unique_ptr<node>& root,int value){
	if(!root) return ;
	if(value<root->data) removee(root->left,value);
	else if(value> root->data) removee(root->right,value);
	else{
		if(!root->left && !root->right){
		    root.reset();
		} 
		else if(!root->left){
		    root=move(root->right);

		} 
		else if(!root->right) {
		    root=move(root->left);
		}
		else{
			node* insucc=root->right.get();// i am doing inorder successor
			while(insucc->left!=nullptr){
				insucc=insucc->left.get();
			}
			root->data=insucc->data;
		    removee(root->right,insucc->data);
		}
	}
	//return root;
}
bool searchimp(const node*root,int value){
    if(!root) return false;
    if(root->data==value) return true;
    if(value<root->data) searchimp(root->left.get(),value);
    else if(value>root->data) searchimp(root->right.get(),value);
    return false;
}
};
int main(){
	BST b;
	b.insert(10);
	b.insert(20);
	b.insert(30);
	b.inorder();
	b.search(10);
	b.removeimp(20);
	b.inorder();
}
