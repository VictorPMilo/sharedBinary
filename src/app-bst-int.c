#include "../include/binary_search_tree_int.h"
#include <stdio.h>


int main() {

    bst_int albero = nil();

    albero = insert(albero, 1);

    albero = insert(albero, 2);

    albero = insert(albero, 3);

    albero = insert(albero, 4);

    albero = insert(albero, 5);

    albero = insert(albero, 6);

    albero = insert(albero, 7);

    albero = insert(albero, 8);
    
    albero = insert(albero, 9);

    albero = insert(albero, 10);

    albero = insert(albero, 11);

    print_bst(albero);

    printf("The size of the tree is: %d\n", size(albero));

    printf("The height of the tree is: %d\n", height(albero));

    // bst_int sotto_albero = retrieve(albero, 10);

    // print_bst(sotto_albero);

    albero = delete(albero, 10);

    print_bst(albero);

    in_order_dfs_infix(albero);
    printf("\n");

    deallocate_bst(albero);


    return 0;
}
