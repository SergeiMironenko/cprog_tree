#include <stdio.h>
#include <stdlib.h>
#include "tree_functions.h"

void run()
{
    Tree *root = NULL;

    root = add_tree(root, 5);

    root = add_tree(root, 11);
    root = add_tree(root, 1);

    root = add_tree(root, -5);
    // root = add_tree(root, 3);
    root = add_tree(root, 8);
    root = add_tree(root, 14);

    root = add_tree(root, -7);
    // root = add_tree(root, -4);
    // root = add_tree(root, 2);
    // root = add_tree(root, 4);
    // root = add_tree(root, 7);
    // root = add_tree(root, 10);
    // root = add_tree(root, 13);
    // root = add_tree(root, 20);
    root = add_tree(root, -99);
    // root = add_tree(root, 80);

    print_tree(root);

    printf("\n\nmax_level = %d level left = %d\n", max_level(root), max_level(root->left));

    free_tree(root);
}

int main(int argc, char *argv[])
{
    run();
    return 0;
}



// -------------------- Дополнительные функции --------------------

// Возведение в степень
int pow_int(int base, int deg)
{
    int res = 1;
    for (int i = 0; i < deg; i++) res *= base;
    return res;
}
