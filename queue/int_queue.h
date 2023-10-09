typedef struct Queue
{
    struct IntNode *first;
    struct IntNode *last;
    int size;
} IntQueue;

IntQueue *newQueue();
void push_item(IntQueue *q, int value); // add new elements to queue struct
void delete_item(IntQueue *q);          // delete the first  element from queue struct
void print_queue(IntQueue *q);          // print the queue struct
void free_queue(IntQueue *q);