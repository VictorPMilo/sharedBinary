#include <stdio.h>
#include <stdlib.h>

#include "../include/binary_search_tree_int.h"

// auxiliary functions
void print_level(bst_int tree, int level) {
    for (int i = 0; i < level - 1; i++) {
        printf("   ");
    }

    if (is_empty(tree)) {
        printf("%snil\n", level == 0 ? "" : " +-");
        return;
    }

    printf("%s(%d)\n", level == 0 ? "" : " +-", tree->value);
    print_level(tree->left, level + 1);
    print_level(tree->right, level + 1);
}


int max(int a, int b) {
    return (a > b) ? a : b;
}

// functions from the signature
void print_bst(bst_int tree) {
    print_level(tree, 0);
}


bst_int nil() {
    bst_int tree = NULL;
    return tree;
}


bool is_empty(bst_int tree) {
    return (tree == NULL);
}


int value(bst_int tree) {
    return (tree->value);
}


int size(bst_int tree) {
    if (tree == NULL) {
        return 0;
    } else { 
        return(size(tree->left) + 1 + size(tree->right)); 
    } 
}


int height(bst_int tree) {
    if (is_empty(tree)) {
        return -1;
    } else { 
        return(max(height(tree->left), height(tree->right))+1); 
    } 
}

// size(tree->left) + size(tree->right)


bst_int left_child(bst_int tree) {
    return (tree->left);
}


bst_int right_child(bst_int tree) {
    return (tree->right);
}


/**
 * @brief Retrieve a subtree in the tree given the value of
 *        its root.
 *
 * @param tree   a pointer to the tree
 * @param value  the value of the root of the subtree to search
 *
 * @return an empty tree if the value is not in
 *         the binary search tree, the subtree
 *         whose root contains the value otherwise
 */
bst_int retrieve(bst_int tree, int value) {

    if (is_empty(tree)) {
        return NULL;
    }

    if (value < tree->value) {
        return retrieve(tree->left, value);
    }
    
    if (value > tree->value) {
        return retrieve(tree->right, value);
    }

    return tree;
    
}




bst_int insert(bst_int tree, int value) {
    if (is_empty(tree)) {

        bst_node_int *new_leaf = malloc(sizeof(bst_node_int));

        new_leaf->value = value;
        new_leaf->left = NULL;
        new_leaf->right = NULL;

        return new_leaf;
    }

    
    if (value > tree->value) {
        tree->right = insert(tree->right, value);
    } 
    
    if (value < tree->value){
        tree->left = insert(tree->left, value);
    }

    return(tree);
}


bst_int delete(bst_int tree, int value) {

    if (is_empty(tree)) {
        return tree;
    }


    if (value > tree->value) {
        tree->right = delete(tree->right, value);
    } 
    
    
    if (value < tree->value){
        tree->left = delete(tree->left, value);
    } 
    
    
    if (tree->value == value) {

        if (is_empty(left_child(tree)) && is_empty(right_child((tree)))) {
            free(tree);
            return NULL;

        } 
        
        
        else if (is_empty(left_child((tree))) ^ is_empty(right_child((tree)))) {

            if (!is_empty(left_child((tree)))) {            // if the left is empty the function return true, so negating it it mean that the it will go
                                                            // through just when the left is not empty 
                bst_int temp = tree->left;
                free(tree);
                return(temp);
            }

            else if (!is_empty(right_child((tree)))) {
                bst_int temp = tree->right;
                free(tree);
                return(temp);
            }
        } 


        else {
            bst_int temp = tree->left;  // go left once

            while (!is_empty(temp->right)) {
                temp = temp->right; //go right until the end
            }

            tree->value = temp->value;  // substitute the value

            tree->left = delete(tree->left, temp->value);  //delete the leaf containing the value that has been moved 
        }

    }

    return tree;

}


//In an in-order traversal, you visit the nodes of the tree in the following order:
// Visit the left subtree.
// Visit the root node.
// Visit the right subtree.
// For a binary search tree, this traversal will print the node values in ascending order.
void in_order_dfs_infix(bst_int tree) {
    if (is_empty(tree)) {
        return;
    }

    // go left
    in_order_dfs_infix(tree->left);

    // print
    printf("%d ", tree->value);

    // go right
    in_order_dfs_infix(tree->right);
}


void deallocate_bst(bst_int tree) {
    if (is_empty(tree)) {
        return;
    }

    deallocate_bst(tree->left);
    deallocate_bst(tree->right);

    free(tree);
}



 
