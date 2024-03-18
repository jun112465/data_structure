#include "binary-tree.h"

TreeNode* insert_node(TreeNode *root, int data){
    // 트리의 루트값 반한

    if(root == NULL){
        root = malloc(sizeof(TreeNode));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    else if(data < root->data) root->left = insert_node(root->left, data);
    else root->right = insert_node(root->right, data);

    return root;
}

// 업데이트된 루트를 반환
TreeNode* delete_node(TreeNode *root, int data){
    if(root == NULL) 
        return root;

    if(data < root->data) 
        root->left = delete_node(root->left, data);
    else if(data > root->data) 
        root->right = delete_node(root->right, data);
    else{
        // 서브트리가 없거나 하나만 있는 경우
        if(root->left == NULL) {
            TreeNode* tmp = root->right;
            free(root);
            return tmp;
        }else if(root->right == NULL){
            TreeNode* tmp = root->left;
            free(tmp);
            return tmp;
        }

        // 양쪽에 서브트리가 있는 경우.
        TreeNode *tmp = root->right;
        while (tmp->left != NULL)
            tmp = tmp->left;
        root->data = tmp->data;
        root->right = delete_node(root->right, tmp->data);
    }

    return root;
}


void preorder_print(TreeNode *root){
    if(root == NULL) return;

    printf("%d ", root->data);
    preorder_print(root->left);
    preorder_print(root->right);
}

void inorder_print(TreeNode *root){
    if(root == NULL) return;

    inorder_print(root->left);
    printf("%d ", root->data);
    inorder_print(root->right);
}

void postorder_print(TreeNode *root){
    if(root == NULL) return;

    postorder_print(root->left);
    postorder_print(root->right);
    printf("%d ", root->data);
}