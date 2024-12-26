#include <stdio.h>
#define n 20

// Queue structure
typedef struct {
    int arr[n];
    int front;
    int back;
} queue;

// Initialize the  queue
void init (queue *q){
    q->front = -1;
    q->back = -1;
}

// Insert element into the queue
void enqueue (queue *q, int x){
    if (q->back == n-1){
        printf("Queue overflow\n");
        return;
    }
    q->back++;
    q->arr[q->back] = x;
    printf("%d inserted to the queue.\n", x);

    if (q->front == -1){
        q->front++;
    }
}

// Delete element from the queue
void dequeue (queue *q){
    if ((q->front == -1) || (q->front > q ->back)){
        printf("Queue underflow\n");
        return;
    }
    printf("%d deleted from the queue.\n", q->arr[q->front]);
    q -> front++;
}

// Get the front element of the queue
int peek (queue *q){
    if (q->front == -1 || q->front > q->back){
        printf("No element in queue\n");
        return -1;
    }
    return q->arr[q->front];
}

int main(){
    queue q;
    init (&q);

    int choice, value;

    while (1) {
        printf("\nSelect Operation : \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek element\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice==1 || choice==2 || choice==3){
            if (choice == 1){
                printf("Enter value to enqueue : ");
                scanf("%d", &value);
                enqueue(&q, value);
            } else if (choice == 2) {
                dequeue(&q);
            } else {
                value = peek(&q);
                if (value != -1){
                    printf("Front element : %d\n", value);
                }
            }
        } else {
            printf("Invalid number! please try again.\n");
        }
    }

    return 0;
}
