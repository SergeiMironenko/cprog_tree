#include <stdio.h>
#include <stdlib.h>
#include "tree_functions.h"

Tree *load_test_data_1(Tree *root)
{
    root = add_tree(root, 5);

    root = add_tree(root, 11);
    root = add_tree(root, 1);

    root = add_tree(root, -5);
    root = add_tree(root, 3);
    root = add_tree(root, 8);
    root = add_tree(root, 14);

    root = add_tree(root, -7);
    root = add_tree(root, -4);
    root = add_tree(root, 2);
    root = add_tree(root, 4);
    root = add_tree(root, 7);
    root = add_tree(root, 10);
    root = add_tree(root, 13);
    root = add_tree(root, 20);
    root = add_tree(root, -99);
    root = add_tree(root, 80);
}

Tree *load_test_data_2(Tree *root)
{
    root = add_tree(root, 6);
    root = add_tree(root, 5);
    root = add_tree(root, 4);
    root = add_tree(root, 3);
    root = add_tree(root, 2);
    root = add_tree(root, 1);
}

void run()
{
    Tree *root = NULL;
    int stay = 1;
    int n = 0;
    char c = '\n';

    while (stay)
    {
        printf("----------------------------\n");
        printf("Операции с бинарным деревом:\n");
        printf("1 - добавить узел в дерево\n");
        printf("2 - вывести дерево\n");
        printf("3 - сбалансировать дерево\n");
        printf("4 - загрузить тестовый набор 1\n");
        printf("5 - загрузить тестовый набор 2\n");
        printf("q - выход\n> ");

        while (c != '\n') c = getchar();
        scanf("%c", &c);
        switch(c)
        {
            case '1':
                printf("Введите число\n> ");
                scanf("%d%c", &n, &c);
                root = add_tree(root, n);
                break;
            case '2':
                if (root) print_tree(root);
                else printf("(!) Дерево пустое\n");
                break;
            case '3':
                balance_tree(&root);
                break;
            case '4':
                root = load_test_data_1(root);
                break;
            case '5':
                root = load_test_data_2(root);
                break;
            default:
                stay = 0;
                break;
        }
    }
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
