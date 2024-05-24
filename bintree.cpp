#include "region.h"
using namespace std;

// New node creation
 node* newNode(Region key) {
    node* node =  new struct node; 
    if (node == nullptr) {
        cerr << "Memory allocation failed\n";
        exit(1);
    }

    node->data=key;
    node->left = nullptr;
    node->right = nullptr;
    node->equalnext=nullptr;

  return node;
}

node* insert(node* root,Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);
    //search left subtree for empty node
    if (data.cnt<root->data.cnt) {
        root->left=insert(root->left,data);
        return root;
    }
    //search right subtree for empty node
    else if(data.cnt>root->data.cnt) {
        root->right=insert(root->right,data);
        return root;
    }
    else {
        root->equalnext=insert(root->equalnext,data);
        return root;
    }
}

node* search(node* root,int key){
    if (root==nullptr) return nullptr ;
    //check if the node contains key
    if(root->data.cnt==key)return root;
    //search left subtree
    else if(key<root->data.cnt) return search(root->left,key);
    //search right subtree
    else return search(root->right,key);
}

node* find_min(node* root){
   if (root->left==nullptr) return root ;
    //check if the node contains key
    return find_min(root->left);
}

node* find_max(node* root){
   if (root->right==nullptr) return root ;
    //check if the node contains key
    return find_max(root->right);
}



// Traverse Inorder
void traverseInOrder( node *temp) {
  if (temp != nullptr) {
    traverseInOrder(temp->left);
    print_node_equal_list(temp);
    traverseInOrder(temp->right);
  }
}

void print_node_equal_list(node* temp){
    while(temp!=nullptr){
        print_node(temp);
        temp=temp->equalnext;
    }
}

void print_node(node *temp){
    if (temp==nullptr){
        cout<<"Key not found\n";
        return;
    }
    cout << "Period: " << temp->data.period << ", ";
    cout << "Event: " << (temp->data.event ? "Births" : "Deaths") << ", ";
    cout << "Region: " << temp->data.region << ", ";
    cout << "Count: " << temp->data.cnt << endl;
}