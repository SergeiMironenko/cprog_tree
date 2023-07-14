#include <stdlib.h>
#include <stdio.h>
#include "tree_functions.h"



// -------------------- Функции дерева --------------------

// Добавление узла в дерево
Tree *add_tree(Tree *root, int val)
{
    // Если дерево непустое
    if (root)
    {
        // Создание нового узла
        Tree *new_node = (Tree*)malloc(sizeof(Tree));
        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;

        // Поиск точки прикрепления нового узла
        Tree *node = root;
        while (1)
        {
            if (val < node->val)
            {
                if (node->left) node = node->left;
                else { node->left = new_node; break; }
            }
            else if (val > node->val)
            {
                if (node->right) node = node->right;
                else { node->right = new_node; break; }
            }
            else
            {
                printf("(!) Данное значение не добавлено, т к уже имеется в дереве.\n");
                break;
            }
        }
    }
    // Если дерево пустое
    else
    {
        root = (Tree*)malloc(sizeof(Tree));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
    }
    return root;
}

// Глубина узла
int max_level_node(Tree *tree, int level)
{
    if (tree)
    {
        int new_level_1 = max_level_node(tree->left, level + 1);
        int new_level_2 = max_level_node(tree->right, level + 1);
        if (new_level_1 > level) level = new_level_1;
        if (new_level_2 > level) level = new_level_2;
    }
    return level;
}

// Максимальная глубина дерева
int max_level(Tree *tree)
{
    return max_level_node(tree, -1);
}

// Вывод дерева
void print_tree(Tree *tree)
{
    // Инициализация очереди
    int queue_size = 0;
    Queue *queue = init_queue();

    // Переменные для вывода схемы
    int level = -1;  // Текущий уровень при обходе дерева
    int maxlevel = max_level(tree);  // Максимальный уровень дерева
    int spacing = 0;  // Для вывода элементов схемы
    int newline = 0;  // Индикатор новой строки
    int pow_2 = 1;  // Степень двойки, максимальное кол-во элементов на текущем уровне (для определения новой строки)

    // Элементы схемы
    char *empty = "   ";
    char *from_root = "─┴─";
    char *from_root_to_left = "─╯ ";
    char *from_root_to_right = " ╰─";
    char *pipe = "───";
    char *to_left = " ╭─";
    char *to_right = "─╮ ";

    // Добавление корня дерева в очередь
    push_queue(queue, tree);
    queue_size++;
    Tree *node;  // Следующий элемент очереди

    // Пока очередь не пуста
    while (queue->next)
    {
        // Выяснение, новая строка (newline = 1) или нет (newline = 0)
        newline = 0;
        for (int i = 0; i <= maxlevel && queue_size >= pow_2; i++)
        {
            if (queue_size == pow_2)
            {
                newline = 1;
                break;
            }
            pow_2 *= 2;
        }

        // Если новая строка, то сначала вывод схемы, затем элементов дерева
        if (newline)
        {
            level++;
            printf("\n");

            // Вывод схемы
            if (level != 0)
            {
                // Отступ
                spacing = pow_int(2, maxlevel - level) - 1;

                // Ветвления
                Tree *peek_node = NULL;
                for (int i = 0; i < pow_2; i++)
                {
                    if (peek_queue(*queue, i)) peek_node = peek_queue(*queue, i)->data;
                    else peek_node = NULL;

                    // Левый узел
                    if (i % 2 == 0)
                    {
                        // Отступ слева
                        for (int i = 0; i < spacing; i++) printf("%s", empty);

                        // Левый непустой элемент
                        if (peek_node)
                        {
                            printf("%s", to_left);

                            // Отступ от левого элемента до центра
                            for (int j = 0; j < spacing; j++) printf("%s", pipe);
                        }
                        // Левый пустой элемент
                        else
                        {
                            printf("%s", empty);

                            // Отступ от левого элемента до центра
                            for (int j = 0; j < spacing; j++) printf("%s", empty);
                        }

                    }
                    // Правый узел
                    else
                    {
                        // Правый непустой элемент
                        if (peek_node)
                        {
                            // Центр
                            if (peek_queue(*queue, i - 1) && peek_queue(*queue, i - 1)->data) printf("%s", from_root);
                            else printf("%s", from_root_to_right);

                            // Отступ от центра до правого
                            for (int j = 0; j < spacing; j++) printf("%s", pipe);

                            printf("%s", to_right);

                            // После правого
                            for (int j = 0; j < spacing; j++) printf("%s", empty);
                        }
                        // Правый пустой элемент
                        else
                        {
                            // Центр
                            Queue *q = peek_queue(*queue, i - 1);
                            Tree *t;
                            if (q) t = q->data;
                            if (peek_queue(*queue, i - 1) && peek_queue(*queue, i - 1)->data) printf("%s", from_root_to_left);
                            else printf("%s", empty);

                            // Отступ от центра до правого
                            for (int j = 0; j < spacing; j++) printf("%s", empty);

                            printf("%s", empty);

                            // После правого
                            for (int j = 0; j < spacing; j++) printf("%s", empty);
                        }

                        // Дополнительный отступ
                        printf("%s", empty);
                    }
                }

                printf("\n");
            }

            // Получение элемента из очереди
            node = pop_queue(queue);
            queue_size--;

            // Вывод элементов дерева
            // Отступ слева
            spacing = pow_int(2, maxlevel - level) - 1;
            for (int i = 0; i < spacing; i++) printf("%s", empty);

            // Вывод элемента дерева
            if (node) printf("%3d", node->val);
            else printf("%s", empty);
        }
        else
        {
            // Получение элемента из очереди
            node = pop_queue(queue);
            queue_size--;

            // Вывод элементов дерева
            // Отступ между элементами
            spacing = pow_int(2, maxlevel - level + 1) - 1;
            for (int i = 0; i < spacing; i++) printf("%s", empty);

            if (node) printf("%3d", node->val);
            else printf("%s", empty);
        }

        // Добавление элементов дерева в очередь
        if (level != maxlevel)
        {
            if (node)
            {
                push_queue(queue, node->left);
                push_queue(queue, node->right);
            }
            else
            {
                push_queue(queue, NULL);
                push_queue(queue, NULL);
            }
            queue_size += 2;
        }
    }
    free(queue);
    printf("\n");
}

// Освобождение дерева
void free_tree(Tree *tree)
{
    if (tree)
    {
        free_tree(tree->right);
        free_tree(tree->left);
        free(tree);
    }
}

// Балансировка дерева
void balance_tree(Tree **tree)
{
    if (*tree)
    {
        while (max_level((*tree)->left) - max_level((*tree)->right) >= 2)
        {
            Tree *tmp = (*tree)->left;
            (*tree)->left = tmp->right;
            tmp->right = *tree;
            *tree = tmp;
        }

        while (max_level((*tree)->right) - max_level((*tree)->left) >= 2)
        {
            Tree *tmp = (*tree)->right;
            (*tree)->right = tmp->left;
            tmp->left = *tree;
            *tree = tmp;
        }
        balance_tree(&((*tree)->left));
        balance_tree(&((*tree)->right));
    }
}
