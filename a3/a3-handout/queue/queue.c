/* Name: Natthakan Euaumpon
 * ID: 6081213
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void push(Queue **q, char *word) {
    Node* new = (Node*) malloc(sizeof(Node));
    char* copy = (char*) malloc(strlen(word)+1);
    strcpy(copy,word);
    new->data = copy;
    if (!*q)
    {
        *q = (Queue*) malloc(sizeof(Queue));
    }
    if(((*q)->head != NULL && (*q)->tail != NULL) || ((*q)->head != NULL && (*q)->tail == NULL)){
        (*q)->tail->next = new;
        (*q)->tail = new;
    }else{
        (*q)->head = new;
    }
    
}

char *pop(Queue *q) {
    Node* p;
    char* prev;
    if (!isEmpty(q))
    {
        p = q->head;
        prev = p->data;
        q->head = q->head->next;
        if (q->tail)
        {
            q->tail = q->tail->next;
        }
        free(p);
        return prev;
    }else
    {
        return NULL;
    }
}

void print(Queue *q) {
    if(!isEmpty(q)){
        Node *h = q->head;
        while (h != NULL)
        {
            char* p = q->head->data;
            printf("%s/n", p);
            h = h->next;
        }
        
    }
}

int isEmpty(Queue *q) {
    if (q!=NULL){
        if (q->head != NULL && q->tail != NULL)
        {
            return 1;
        }else
        {
            return 0;
        }
    }
}

void delete(Queue *q) {
    while (!isEmpty(q))
    {
        Node* r = q->head;
        q->head = q->head->next;
        if (q->tail != NULL)
        {
            q->tail = q->tail->next;
        }
        free(r->data);
        free(r);
    }
    
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Queue *q = NULL;

    // print the queue
    print(q);

    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    print(q);

    // pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        printf("%s\n", item);
        free(item);
    }

    char *item = pop(q);
    assert(item == NULL);

    // push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the queue
    delete(q);

    // print again
    print(q);

    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the queue
    free(q);
}
