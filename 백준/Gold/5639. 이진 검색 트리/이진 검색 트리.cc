#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node * parent;
    Node(int val){
        this->val =val;
        left = right = parent =NULL;
    }
    void setLeft(Node *node){
        this->left = node;
        return;
    }
    Node* getLeft(){
        return this->left;
    }
    void setRight(Node * node){
        this->right=node;
        return;
    }
    Node* getRight(){
        return this->right;
    }
    void setParent(Node *node){
        this->parent=node;
        return;
    }
    Node* getParent(){
        return this->parent;
    }
};
class BST{
public:
    Node *root;
    BST(){
        root=NULL;
    }
    void insertNode(Node *node){
        if(root==NULL){
            root = node;
            return;
        }
        Node* cur_node = root;
        Node* par_node;
        while(cur_node!=NULL){
            if(cur_node->val<node->val){
                par_node = cur_node;
                cur_node = cur_node->getRight();
            }
            else{
                par_node = cur_node;
                cur_node = cur_node->getLeft();
            }
        }
        if(par_node->val<node->val)
            par_node->setRight(node);
        else par_node->setLeft(node);
    }
    void print_Post(Node * node){
        if(node==NULL)
            return;
        print_Post(node->getLeft());
        print_Post(node->getRight());
        cout<<node->val<<"\n";

    }
};
int main(){
    int num;
    BST bst;
    
    while(cin>>num){
        bst.insertNode(new Node(num));
    }
    bst.print_Post(bst.root);
}