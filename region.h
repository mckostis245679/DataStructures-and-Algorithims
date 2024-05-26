#ifndef REGION_H
#define REGION_H
#include "string"
#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "iostream"
#include "cstdlib"
#include "vector"
using namespace std;

struct Region{
    string period;
    bool event;     //1:Birth, 0:Death
    string region;
    int cnt;
};

struct node {
  Region data;
  struct node *left;
  struct node *right;
  struct node *equalnext;
  int height;
};

//File Handling
node* read_csv_births(node* root, const string& filename);
node* read_csv_regions(node* root,const string& filename);
node* read_csv_regions_avl(node* root,const string& filename);
//Binary-tree
node* newNode(Region data);
void traverseInOrder( node *temp); 
void print_node_equal_list(node* temp);
void print_node(node *temp);
//BIN_TREE_BIRTHS
node* insert_by_births(node* root,Region data);
node* search_by_births(node* root,int key);
node* find_min(node* root);
node* find_max(node* root);
void displayMenu(node* root);
//BIN_TREE_REGION
node* insert_by_region(node* root, Region data);
node* search_by_region(node* root,string region);
//AVL
int heightcalc(node* temp);
int b_factor(node *temp);
node* insert_by_region_avl(node* root, Region data);
void lilwayne(node* a);
void rotate_right(node *a);
void rotate_left(node *a);
//hashing
int hash(string str, int D);

#endif //REGION_H