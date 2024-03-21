#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Queue.h"

int main(){
    Queue *NewQueue ;
    int deqval;
    NewQueue = CreateQueue();

    Enqueue(NewQueue , 5);
    Enqueue(NewQueue , 4);
    Enqueue(NewQueue , 3);
    Enqueue(NewQueue , 2);

    PrintQueue(NewQueue);
printf("/////////////\n");
    deqval =  Dequeue(NewQueue);
    deqval =  Dequeue(NewQueue);
    deqval =  Dequeue(NewQueue);
    PrintQueue(NewQueue);
    deqval =  Dequeue(NewQueue);
    deqval =  Dequeue(NewQueue);
    PrintQueue(NewQueue);

    return 0;
}