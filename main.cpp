#include "region.h"
using namespace std;

int main() {
    string fname = "C:\\Users\\Kostas\\Desktop\\DATABASES_PART_2\\bd-dec22-births-deaths-by-region.csv";
    node *root=nullptr;
    

    //BIRTHS BST
    root=read_csv_births(root, fname);
    cout << "Inorder traversal:\n";
    traverseInOrder(root);
    node* item=search_by_births(root,12);
    displayMenu(root);
   

    //REGION BST
    //root=read_csv_regions(root,fname);



    return 0;
}

