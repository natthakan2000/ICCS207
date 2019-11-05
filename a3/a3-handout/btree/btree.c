/* Name: Natthakan Euaumpon
 * ID: 6081213
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void insert(Node **tree, int val) {
    if (*tree != NULL)
    {
        Node* root = *tree;
        if (root->data > val)
        {
            insert(&(root->left),val);
        }else
        {
            insert(&(root->right),val);
        }
    }else
    {
        *tree = (Node*) malloc(sizeof(Node));
        (*tree)->data = val;
    }
}

void print(Node *tree) {
    if (tree != NULL)
    {
        helper(tree,0);
    }   
}

void helper(Node *tree,int frontier){
    Node *p = tree;
    if (p != NULL){
        for (int i = 0; i < frontier-1; i++)
        {
            printf("  ");
        }
        if (frontier > 0)
        {
            printf("|-");
        }
        printf("%d\n", p->data);
        if (p->left)
        {
            helper(p->left,frontier++);
        }
        if (p->right)
        {
            helper(p->right,frontier++);
        }
    }
}

void delete(Node *tree) {
    if (tree->left == NULL)
    {
        if (tree->right == NULL)
        {
            free(tree);
            return;
        }else{
            delete(tree->right);
        }
    }else
    {
        delete(tree->left);
        if (tree->right != NULL)
        {
            delete(tree->right);
        }
    }
    free(tree);
}

Node *lookup(Node ** tree, int val) {
    Node *f = NULL;
    if (*tree != NULL)
    {
        if ((*tree)->data == val)
        {
            f = (*tree);
        }
        if ((*tree)->left != NULL)
        {
            f = lookup(&((*tree)->left),val);
            if (f != NULL){
                return f;
            }
        }
        if ((*tree)->right != NULL)
        {
            f = lookup(&((*tree)->right),val);
            if (f != NULL)
            {
                return f;
            }
            
        }
    }
    return f;
}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}
