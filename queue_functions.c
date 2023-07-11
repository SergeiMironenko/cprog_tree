#include <stdlib.h>
#include "tree_functions.h"



// -------------------- Функции очереди --------------------

// Инициализация очереди
Queue *init_queue()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->data = NULL;
    queue->next = NULL;
    return queue;
}

// Добавление в очередь
int push_queue(Queue *queue, Tree *tree)
{
    while (queue->next) queue = queue->next;
    queue->next = (Queue*)malloc(sizeof(Queue));
    queue->next->data = tree;
    queue->next->next = NULL;
}

// Удаление из очереди
Tree *pop_queue(Queue *queue)
{
    Tree *tree = NULL;
    Queue *tmp = queue->next;
    if (tmp)
    {
        queue->next = queue->next->next;
        tree = tmp->data;
        free(tmp);
    }
    return tree;
}

// Вывести элемент из очереди
Queue *peek_queue(Queue queue, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (queue.next) queue.next = queue.next->next;
    }
    return queue.next;
}
