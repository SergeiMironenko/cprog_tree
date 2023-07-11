#ifndef TREE_FUNCTIONS_H_
#define TREE_FUNCTIONS_H_

// -------------------- Дерево --------------------

// Узел дерева
typedef struct Tree
{
    int val;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *add_tree(Tree *root, int val);  // Добавление узла в дерево
int max_level_node(Tree *tree, int level);  // Глубина узла
int max_level(Tree *tree);  // Максимальная глубина дерева
void print_tree(Tree *tree);  // Вывод дерева
void free_tree(Tree *tree);  // Освобождение дерева



// -------------------- Очередь --------------------

// Очередь для обхода дерева в ширину
typedef struct Queue
{
    Tree *data;
    struct Queue *next;
} Queue;

Queue *init_queue();  // Инициализация очереди
int push_queue(Queue *queue, Tree *tree);  // Добавление в очередь
Tree *pop_queue(Queue *queue);  // Удаление из очереди
Queue *peek_queue(Queue queue, int i);  // Вывести элемент из очереди



// -------------------- Дополнительные функции --------------------
int pow_int(int base, int deg);  // Возведение в степень

#endif  // TREE_FUNCTIONS_H_
