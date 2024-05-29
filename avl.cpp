#include "region.h"
using namespace std;

int heightcalc(node* temp){
    if (temp==nullptr) return -1;//when you find empty node return -1
    temp->height=max(heightcalc(temp->left),heightcalc(temp->right))+1;
    return temp->height;
}

int b_factor(node *temp) {
    int left_height=-1;
    int right_height=-1;
    if(temp->left!=nullptr){
        left_height=temp->left->height;
         
        if(left_height==-1){
            left_height=heightcalc(temp->left);
            cout<<"heightcalc called\n";
        }
    } 
    if(temp->right!=nullptr) {
        right_height=temp->right->height;
        
        if(right_height==-1){
            cout<<"heightcalc called\n";
            right_height=heightcalc(temp->right);
        }   
    }
        temp->height=max(left_height,right_height)+1;
        return left_height-right_height;//left.height-right.height
}


// B FACTOR : -1,0,1 


void rotate_left(node *a){
    node *b=a->right;
    node* c=b->left;
    node* d=a->left;
    //make a copy of data of a
    Region data=a->data;
    node* equalnext=a->equalnext;
    //assign p as the parent of b
   a->data=b->data;
    a->right=b->right;
    a->left=b;
    a->equalnext=b->equalnext;
    //assign b as the parent of a 
    b->right=c;//assign a as the parent of c 
    b->left=d;
    b->data=data;  
    b->equalnext=equalnext;
}

void rotate_right(node *a){
     node *b=a->left;
    node* c=b->right;
    node* d=a->right;
    //make a copy of data of a
    Region data=a->data;
    node* equalnext=a->equalnext;
    //assign p as the parent of b
    a->data=b->data;
    a->right=b;
    a->left=b->left;
    a->equalnext=b->equalnext;
    //assign b as the parent of a 
    b->right=d;
    b->left=c;
    b->data=data;  
    b->equalnext=equalnext;
}


void lilwayne(node* a){
     int balancefactor=b_factor(a);
    if (balancefactor>1){
        if(b_factor(a->left)>=0){
            rotate_right(a);
            heightcalc(a);
            cout<<"right rotate\n";
        } 
        else {
            rotate_left(a->left);
            rotate_right(a);
            heightcalc(a);
            cout<<"left right rotate\n";
        }
        return;
    }
    else if(balancefactor<-1){
        if(b_factor(a->right)<=0) {
            rotate_left(a);
            heightcalc(a);
            cout<<"left rotate\n";
        }
        else{
            rotate_right(a->right);
            rotate_left(a);
            heightcalc(a);
            cout<<"right left rotate\n";
        }
    }
}

node* insert_by_region_avl(node* root, Region data){
    //when you find empty child create a new node
    if (root==nullptr) return newNode(data);

    //search left subtree for empty node
    if (data.region < root->data.region) {
        root->left = insert_by_region_avl(root->left, data);
    }

        //search right subtree for empty node
    else if(data.region > root->data.region) {
        root->right=insert_by_region_avl(root->right,data);
        
    }
    else if(data.region == root->data.region) {
        root->equalnext=insert_by_region_avl(root->equalnext,data);
        return root;
    }
   
  
   lilwayne(root);
   
   

    return root;
}

node* delete_node_avl(node* temp, string key){
  if (temp==nullptr){
    cout<<"no such key to be deleted\n";
    return temp;
  } 
  if (key < temp->data.region) {
    temp->left = delete_node_avl(temp->left, key);
  }
  else if (key > temp->data.region) {
    temp->right = delete_node_avl(temp->right, key);
  }
  else{
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
        temp->right=delete_node_avl(temp->right,minvalue->data.region);
    }
  } 
   lilwayne(temp);
    return temp;
}

