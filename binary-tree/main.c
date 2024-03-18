#include "binary-tree.h"

int main(){
    TreeNode *root = NULL;

    root = insert_node(root, 10);
    root = insert_node(root, 6);
    root = insert_node(root, 15);
    root = insert_node(root, 9);
    root = insert_node(root, 3);
    root = insert_node(root, 5);
    root = insert_node(root, 2);

    preorder_print(root);

    root = delete_node(root, 6);
    preorder_print(root);
    
    return 0;
}