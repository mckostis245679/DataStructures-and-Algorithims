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
    node->height=-1;
  return node;
}

void printBinaryTree(node* root, int space = 0, int height = 10) {
    if (root == nullptr) return;
    space += height;
    printBinaryTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data.region << "\n";
    printBinaryTree(root->left, space);
}

// Traverse Inorder
void traverseInOrder( node *temp) {
  if (temp != nullptr) {
    traverseInOrder(temp->left);
    print_node(temp);
    traverseInOrder(temp->right);
  }
}

void print_node_equal_tree(node* temp){
    
      print_node(temp);
      temp=temp->equalnext;
      traverseInOrder(temp);
}

void print_node(node *temp){
    if (temp==nullptr){
        cout<<"Key not found\n";
        return;
    }
    cout << "Period: " << temp->data.period << ", ";
    cout << "Event: " << (temp->data.event ? "Births" : "Deaths") << ", ";
    cout << "Region: " << temp->data.region << ", ";
    cout << "Count: " << temp->data.cnt <<",";
    cout << "Height: " << temp->height << ",";
    cout << "Bfactor: " << b_factor(temp) ;
    cout<<endl;
}

void deletetree(node *temp){
  if (temp!=nullptr){
    deletetree(temp->left);
    deletetree(temp->equalnext);//delete secondary tree
    deletetree(temp->right);    
    delete temp;  
  }
}


node* delete_node(node* temp, string key){
  if (temp==nullptr){
    cout<<"no such key to be deleted\n";
    return temp;
  } 
  if (key < temp->data.region) {
    temp->left = delete_node(temp->left, key);

    return temp;
  }
  else if (key > temp->data.region) {
    temp->right = delete_node(temp->right, key);
    return temp;
  } 
  if(temp->left==nullptr && temp->right==nullptr) {//if the node is a leaf just delete
    cout<<"leaf\n";
    deletetree(temp->equalnext);  
    delete temp;
    return nullptr;
  }
  else if (temp->right==nullptr){//no right child
      cout<<"no right child\n";
      node* left=temp->left;
      deletetree(temp->equalnext);
      delete temp;
      return left;
  }
  else if (temp->left==nullptr){//no lieft child
      cout<<"no left child\n";
      node* right=temp->right;
      deletetree(temp->equalnext);
      delete temp;
      return right;
  }
  else{// two children ,swap node with the next minimum value 
    cout<<"two children\n";
    node* minvalue=find_min(temp->right);
    deletetree(temp->equalnext);
    //swap node with min value of the right subtree of the temp node
    temp->data=minvalue->data;
    temp->equalnext=minvalue->equalnext;
    temp->right=delete_node(temp->right,minvalue->data.region);
    lilwayne(temp->right); 
   return temp;
  }
}