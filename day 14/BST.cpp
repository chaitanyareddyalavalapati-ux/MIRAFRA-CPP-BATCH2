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
void inorder(node* root){
	if(root==nullptr) return;
	inorder(root->left);
	// Print current node info
    std::cout << "Node Data: " << root->data
              << " | Address: " << root
              << " | Left: " << root->left
              << " | Right: " << root->right
              << std::endl;

	inorder(root->right);
}
// insert
node* insert(node* root,int value){
	// check if root empty
	if(root==nullptr){
		return new node(value);
	}
	// check less 
	if(value<root->data){
		root->left=insert(root->left,value);
	}
	else if(value>root->data){
		root->right=insert(root->right,value);
	}
	return root;

}
// delete using postorder as it maintain that root will be deleted last
void deletion(node* root){
	if(root==nullptr){
		return;
	}
	deletion(root->left);
	deletion(root->right);
	cout<<"Deleted node"<<root->data<<endl;
	delete root;
}
// preorder
void preorder(node* root){
	if(root==nullptr) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
// delete node
void removee(node*& root,int value){
	if(!root) return ;
	if(value<root->data) removee(root->left,value);
	else if(value> root->data) removee(root->right,value);
	else{
		if(!root->left && !root->right){
		    delete root;
		    root=nullptr;
		} 
		else if(!root->left){
		    node* temp=root->right;
		    delete root;
		   // return temp;
		} 
		else if(!root->right) {
		    node* temp=root->left;
		    delete root;
		   // return temp;
		}
		else{
			node* insucc=root->right;// i am doing inorder successor
			while(insucc->left!=nullptr){
				insucc=insucc->left;
			}
			root->data=insucc->data;
		    removee(root->right,insucc->data);
		}
	}
	//return root;
}
int main(){
	node* root=nullptr;
	root=insert(root,1);
	root=insert(root,4);
	root=insert(root,6);
	root=insert(root,10);
	root=insert(root,7);
	root=insert(root,15);
	inorder(root);
	cout<<endl;
	removee(root,10);
	inorder(root);
}
