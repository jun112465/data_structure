#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
}TreeNode;

TreeNode* insert_node(TreeNode *root, int data);
TreeNode* delete_node(TreeNode *root, int data);
void inorder_print(TreeNode *root);
void preorder_print(TreeNode *root);
void postorder_print(TreeNode *root);
