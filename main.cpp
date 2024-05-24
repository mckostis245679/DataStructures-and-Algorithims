#include "region.h"
using namespace std;

int main() {
    string fname = "C:\\Users\\Kostas\\Desktop\\DATABASES_PART_2\\bd-dec22-births-deaths-by-region.csv";
    node *root=nullptr;
    root=read_csv(root, fname);
    cout << "Inorder traversal:\n";
    traverseInOrder(root);
    node* item=search(root,12);
    print_node_equal_list(item);
    item=find_min(root);
    print_node_equal_list(item);
    item=find_max(root);
    print_node_equal_list(item);



    return 0;
}

