typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    struct Node *first;
    struct Node *last;
    int size;
} Queue;

Queue *newQueue();
void push(Queue *q, int value);
void delete_item(Queue *q);
void print_queue(Queue *q);