#include "region.h"
using namespace std;

int main() {
    string fname = "C:\\Users\\Kostas\\Desktop\\DATABASES_PART_2\\bd-dec22-births-deaths-by-region.csv";
    node *root=nullptr;
    root=read_csv(root, fname);
    cout << "Inorder traversal:\n";
    traverseInOrder(root,0);

    return 0;
}

