#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXQUEUE 20

struct indices
{
    int front1;
    int rear1;
    int front2;
    int rear2;
    int produce;
    int consume;
};
typedef struct indices  INDEX;

struct prod_cons
{
    int data[MAXQUEUE];
    INDEX * index;
};
typedef struct prod_cons PD;


void enqueue_prod(PD * p)
{
    if(p->index->rear1 == p->index->rear2)
    {
        printf("queue is full\n");
        return;
    }
    int x;
    printf("Element entered in producer\n");
    x = rand()%10;
    p->index->rear1++;
    p->data[p->index->rear1]=x;
    p->index->produce = 1;
    p->index->consume = 0;
}

void enqueue_cons(PD * p)
{
    if(p->index->rear1 == p->index->rear2)
    {
        printf("queue is full\n");
        return;
    }
    int x;
    printf("Element entered in consumer\n");
    x = rand()%10;
    p->index->rear2++;
    p->data[p->index->rear2]=x;
    p->index->produce = 0;
    p->index->consume = 1;
}



void dequeue_cons(PD * p)
{
    if(p->index->front2 == MAXQUEUE-1)
    {
        printf("Queue is empty\n");
        return;
    }
    int x;
    x = p->data[p->index->rear2];
    p->index->front2--;
    printf("Dequeued element from consumer\n");
    p->index->produce = 2;
    p->index->consume = 3;
}

void dequeue_prod(PD * p)
{
    if(p->index->front2 == MAXQUEUE-1)
    {
        printf("Queue is empty\n");
        return;
    }
    int x;
    x = p->data[p->index->rear1];
    p->index->front1++;
    printf("Dequeued element from producer\n");
    p->index->produce = 3;
    p->index->consume = 2;
}

void display(PD *p)
{
    if(p->index->front2 == MAXQUEUE-1)
    {
        printf("Queue is empty\n");
        return;
    }
    int i, j;
    printf("Producer data:\n");
    for(i=p->index->front1; i<=p->index->rear1; i++)
    {
        printf("|%d|\n", p->data[i]);
    }
    printf("consumer data\n");
    for(j=p->index->front2; i>=p->index->rear2; j--)
    {
        printf("|%d|\n", p->data[j]);
    }
}

void active(PD * p)
{
    if(p->index->produce == 1)
        printf("last enqueue: producer queue\n");
    else if(p->index->consume == 1)
        printf("Last enqueue: consumer queue\n");
    if(p->index->produce == 3)
        printf("Last dequeue: producer queue\n");
    else if(p->index->consume == 3)
        printf("Last dequeue: consumer queue\n");
}

int main()
{

    PD * p;
    int ch;
    p->index->front1 = 0;
    p->index->front2 = MAXQUEUE-1;
    p->index->rear1 = p->index->front1;
    p->index->rear2 = p->index->front2;
    while(1)
    {
        printf("1- produce in producer\n2-consumer from consumer\n3- produce in consumer\n4- consume in producer\n5- print producr consumer\n6-get active producer consumer\n7- exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: enqueue_prod(p);
                    break;

            case 2: dequeue_cons(p);
                    break;

            case 3: enqueue_cons(p);
                    break;

            case 4: dequeue_prod(p);
                    break;

            case 5: display(p);
                    break;

            case 6: active(p);
                    break;

            case 7: printf("terminating\n");
                    exit(0);
        }
    }
}
