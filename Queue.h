#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct data
{
    /* data */
    int value;
    struct data *next;
}data;
typedef struct Queue
{
    /* links */
    data *head ;
    data *tail ;

    int Size;
    
}Queue;



Queue *CreateQueue(){
    Queue *nq = malloc(sizeof(Queue));

    nq->head = NULL;
    nq->tail = NULL;
    nq->Size = 0 ;

    return nq; 
}

int Size(Queue * pointer){
    return pointer->Size;
}
bool IsEmpty(Queue *pointer){
    return (pointer->Size == 0);
}
void Enqueue(Queue *pointer , int value){

    data *NewNode = malloc(sizeof(data));
    NewNode->value = value ;
    NewNode->next = NULL;

    if(Size(pointer)==0){
        pointer->tail = NewNode;
        pointer->head = pointer->tail;
        pointer->Size++;
    }else{
        NewNode->next = pointer->head;
        pointer->head = NewNode;
        pointer->Size++;
    }
}
int Dequeue(Queue *pointer) {
    if (Size(pointer) == 0) {
        printf("Queue Is Empty\n");
        return -1;
    } else {
        int dequeuedValue = pointer->tail->value;

        
        if (Size(pointer) == 1) {
            free(pointer->tail);
            
            pointer->head = NULL;
            pointer->tail = NULL;
        } else {
            data *temp = pointer->head;
            while (temp->next != pointer->tail) {
                temp = temp->next;
            }
            temp->next = NULL;
            free(pointer->tail);
            pointer->tail = temp;
        }

        pointer->Size--;

        return dequeuedValue;
    }
}

void PrintQueue(Queue *pointer) {
    data *current = pointer->head;

    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->value);  
        current = current->next;
    }
    printf("\n"); 
}



#endif //QUEUE_H_INCLUDED