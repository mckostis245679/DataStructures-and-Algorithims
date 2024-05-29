#include "region.h"
using namespace std;

int main() {
    string fname = "C:\\Users\\Kostas\\Desktop\\DATABASES_PART_2\\bd-dec22-births-deaths-by-region.csv";
    node *root=nullptr;
    int d=11;

    //BIRTHS BST
   /* root=read_csv_births(root, fname);
    cout << "Inorder traversal:\n";
    heighcalc(root);
    traverseInOrder(root);*/
    //node* item=search_by_births(root,12);
   // displayMenu(root);
   

    //REGION BST
  root=read_csv_regions_avl(root,fname);
    heightcalc(root);
    traverseInOrder(root);
    printBinaryTree(root,0,10);
   cout<<"AFTER DELETION\n";
   root=delete_node_avl(root,"Tasman region");
  // heightcalc(root);
   traverseInOrder(root);
    printBinaryTree(root,0,10);
    
    //HASHING
    /*vector<node*> htable(d);
    read_csv_regions_htable(htable,fname);
    print_htable(htable);
    node* temp=search_htable(htable,"New Zealand","2006");
    print_node(temp);*/

    return 0;
}

