#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // For using bool, true, and false
#define maxSize 100   // Maximum size

// Function to insert an element at a specific position in the array
void insertArray (int arr[], int *size, int element, int position)
{
    if (*size >= maxSize)
    {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (position < 0 || position > *size)
    {
        printf("Invalid position! Please enter a position between 0 to %d", *size);
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[position] = element;
    (*size)++;
    printf("Element %d inserted at position %d.\n", element, position);
}

// Function to delete an element at a specific position in the array
void deleteArray (int arr[], int *size, int position)
{
    if (*size == 0)
    {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (position < 0 || position >= *size)
    {
        printf("Invalid position! Please enter a positon between 0 to %d", *size-1);
        return;
    }
    int deleteElement = arr[position];

    // Shift elements to the left to fill the gap created by the deletion
    for (int i = position; i < *size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    (*size)--;
    printf("Element %d deleted from position %d.\n", deleteElement, position);
}

// Function to search for an element in the array
int searchArray (int arr[], int size, int element)
{
    for (int i=0; i<size; i++)
    {
        if (arr[i] == element)
        {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to display the array
void displayArray (int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Define a structure for the linked list node
typedef struct Node
{
    int data;            // Data stored in the node
    struct Node* next;  // Pointer to the next node
} Node;

// Function to create a new node
Node* createNode (int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));    // Allocate memory for the node
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL; // Initialize the next pointer to NULL
    return newNode;
}

// Function to insert a node at the head of the linked list
void insertAtHead (Node** head, int val)
{
    Node* n = createNode(val); // Create a new node
    n->next = *head;    // Point the new node's next to the current head
    *head = n;      // Update the head to the new node
}

// Function to insert a node at the end of the linked list
void insertAtEnd (Node** head, int val)
{
    Node* n = createNode(val);  // Create a new node with the given value

    if (*head == NULL)      // If the list is empty, make the new node the head
    {
        *head = n;
        return;
    }
    Node* temp = *head;

    while (temp->next != NULL )     // Traverse to the last node
    {
        temp = temp->next;
    }
    temp->next = n;     // link the last node to the new node
}

// Function to display the linked list
void displayLinkedList (Node* head)
{
    Node* temp = head;
    if (temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

// Function to delete a node by value
void deleteByValue (Node** head, int val)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete %d.\n", val);
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;

    // If the head node contains the value to delete
    if (temp != NULL && temp->data == val)
    {
        *head = temp->next; // Change head to the next node
        free(temp);         // Free the old head
        printf("Deleted %d from the list.\n", val);
        return;
    }

    // Traverse the list to search for the node to delete
    while (temp != NULL && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found
    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", val);
        return;
    }

    // Unlink the node and free its memory
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", val);
}

// Function to search for a value in the linked list
bool searchLinkedList (Node* head, int key)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)  // If the value is found
        {
            return true;
        }
        temp = temp->next;
    }
    return false;   // Return false if the value is not found
}

// Stack structure
typedef struct
{
    int arr[maxSize];
    int top;
} stack;

// Initializing stack
void initStack (stack *st)
{
    st->top = -1;
}

// Push element onto stack
void push (stack *st, int x)
{
    if (st->top == maxSize-1)
    {
        printf("Stack overflow\n");
    }
    st->top++;
    st->arr[st -> top] = x;
    printf("%d pushed in stack\n", x);
}

// Pop element from stack
void pop (stack *st)
{
    if (st->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d poped from stack\n", st->arr[st->top]);
        st->top--;
    }
}

// Get the top element of stack
int Top (stack *st)
{
    if (st->top == -1)
    {
        printf("No element in Stack\n");
        return 0;
    }
    else
    {
        printf("Top element : %d\n", st->arr[st->top]);
    }
    return st->arr[st->top];
}

// Queue structure
typedef struct
{
    int arr[maxSize];
    int front;
    int back;
} queue;

// Initialize the  queue
void initQueue (queue *q)
{
    q->front = -1;
    q->back = -1;
}

// Insert element into the queue
void enqueue (queue *q, int x)
{
    if (q->back == maxSize-1)
    {
        printf("Queue overflow\n");
        return;
    }
    q->back++;
    q->arr[q->back] = x;
    printf("%d inserted to the queue.\n", x);

    if (q->front == -1)
    {
        q->front++;
    }
}

// Delete element from the queue
void dequeue (queue *q)
{
    if ((q->front == -1) || (q->front > q ->back))
    {
        printf("Queue underflow\n");
        return;
    }
    printf("%d deleted from the queue.\n", q->arr[q->front]);
    q -> front++;
}

// Get the front element of the queue
int peek (queue *q)
{
    if (q->front == -1 || q->front > q->back)
    {
        printf("No element in queue\n");
        return -1;
    }
    return q->arr[q->front];
}


int main()
{

    int choice, value, pos;

    printf("\nSelect data structure : \n");
    printf("1. Array \n");
    printf("2. Linked List \n");
    printf("3. Stack \n");
    printf("4. Queue \n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
        int arr[maxSize];   // Array declaration
        int size = 0;
        int choiceArray, element, position;

        while (1)
        {
            printf("\nSelect Operation for Array:\n");
            printf("1. Insert an element\n");
            printf("2. Delete an element\n");
            printf("3. Search for an element\n");
            printf("4. Display the array\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choiceArray);

            switch (choiceArray)
            {
            case 1:
                // Insert an element
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the positon (0 to %d) : ", size);
                scanf("%d", &position);
                insertArray(arr, &size, element, position);
                break;

            case 2:
                // Delete an element
                printf("Enter the position to delete (0 to %d) : ", size-1);
                scanf("%d", &position);
                deleteArray(arr, &size, position);
                break;

            case 3:
                // Search for an element
                printf("Enter the element to search: ");
                scanf("%d", &element);
                position = searchArray(arr, size, element);
                if (position != -1)
                {
                    printf("Element %d found at position %d.\n", element, position);
                }
                else
                {
                    printf("Element %d not found in the array.\n",element);
                }
                break;

            case 4:
                // Display the array
                displayArray(arr, size);
                break;

            case 5:
                // Exit the program
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
            }
        }

    case 2:
        Node* head = NULL;      // Initialize the linked list as empty
        int choiceLinkedList, valueLL;

        while (1)
        {
            printf("\nSelect Operation for Linked List: \n");
            printf("1. Insert at the head\n");
            printf("2. Insert at the end\n");
            printf("3. Display the list\n");
            printf("4. Delete a node by value\n");
            printf("5. Search for a value\n");
            printf("6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choiceLinkedList);

            switch (choiceLinkedList)
            {
            case 1:
                // Take input for inserting at the head
                printf("Enter value to insert at the head: ");
                scanf("%d", &valueLL);
                insertAtHead(&head, valueLL);
                printf("%d has inserted in the list.\n", valueLL);
                break;

            case 2:
                // Take input for inserting at the end
                printf("Enter value to insert at the end: ");
                scanf("%d", &valueLL);
                insertAtEnd(&head, valueLL);
                printf("%d has inserted in the list.\n", valueLL);
                break;

            case 3:
                // Display the linked list
                printf("Linked list: ");
                displayLinkedList(head);
                break;

            case 4:
                // Take input for deletion
                printf("Enter value to delete: ");
                scanf("%d", &valueLL);
                deleteByValue(&head, valueLL);
                break;

            case 5:
                // Search for a value
                printf("Enter value to search: ");
                scanf("%d", &valueLL);
                if (searchLinkedList(head, valueLL))
                {
                    printf("Value %d found in the list.\n", valueLL);
                }
                else
                {
                    printf("Value %d not found in the list.\n", valueLL);
                }
                break;

            case 6:
                // Exit the program
                printf("Existing program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
            }
        }

    case 3:
        stack st;
        initStack (&st);

        int choiceStack, valueSt;

        while (1)
        {
            printf("\nSelect Operation for Stack: \n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Top element\n");
            printf("Enter your choice : ");
            scanf("%d", &choiceStack);

            if (choiceStack==1 || choiceStack==2 || choiceStack==3)
            {
                if (choiceStack == 1)
                {
                    printf("Enter the value to push : ");
                    scanf("%d", &valueSt);
                    push(&st, valueSt);
                }
                else if (choiceStack == 2)
                {
                    pop(&st);
                }
                else
                {
                    valueSt = Top(&st);
                }
            }
            else
            {
                printf("Invalid number! Please try again.\n");
            }
        }

    case 4:
        queue q;
        initQueue (&q);

        int choiceQueue, valueQ;

        while (1)
        {
            printf("\nSelect Operation for Queue: \n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Peek element\n");
            printf("Enter your choice : ");
            scanf("%d", &choiceQueue);

            if (choiceQueue==1 || choiceQueue==2 || choiceQueue==3)
            {
                if (choiceQueue == 1)
                {
                    printf("Enter value to enqueue : ");
                    scanf("%d", &valueQ);
                    enqueue(&q, valueQ);
                }
                else if (choiceQueue == 2)
                {
                    dequeue(&q);
                }
                else
                {
                    valueQ = peek(&q);
                    if (valueQ != -1)
                    {
                        printf("Front element : %d\n", valueQ);
                    }
                }
            }
            else
            {
                printf("Invalid number! please try again.\n");
            }
        }

    default:
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}
