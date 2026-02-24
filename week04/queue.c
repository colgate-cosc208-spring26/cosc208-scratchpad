#include <stdio.h>
#include <stdlib.h>

struct item {
    int value;
    struct item *next;
};

struct queue {
    struct item *head;
    struct item *tail;
};

// the new_queue function creates a new, empty queue.
struct queue *new_queue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(int value, struct queue *q) {
    struct item *newitem = malloc(sizeof(struct item));
    newitem->value = value;
    newitem->next = NULL;

    if (q->head == NULL && q->tail == NULL) {
        q->head = q->tail = newitem;
    } else {
        q->tail->next = newitem;
        q->tail = newitem;
    }
}

void print_queue(struct queue *q) {
    struct item *tmp = q->head;
    int position = 0;
    while (tmp != NULL) {
        printf("%d, %d\n", position, tmp->value);
        position += 1;
        tmp = tmp->next;
    }
}

int main() {
    struct queue *q = new_queue();
    enqueue(13, q);
    enqueue(64, q);
    enqueue(60, q);
    enqueue(27, q);
    print_queue(q);
} 
