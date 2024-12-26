#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // For using bool, true, and false

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
void display (Node* head)
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
bool search (Node* head, int key)
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

// Main function
int main()
{
    Node* head = NULL;      // Initialize the linked list as empty
    int choice, value;

    while (1)
    {
        printf("\nSelect Operation: \n");
        printf("1. Insert at the head\n");
        printf("2. Insert at the end\n");
        printf("3. Display the list\n");
        printf("4. Delete a node by value\n");
        printf("5. Search for a value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Take input for inserting at the head
            printf("Enter value to insert at the head: ");
            scanf("%d", &value);
            insertAtHead(&head, value);
            printf("%d has inserted in the list.\n", value);
            break;

        case 2:
            // Take input for inserting at the end
            printf("Enter value to insert at the end: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;

        case 3:
            // Display the linked list
            printf("Linked list: ");
            display(head);
            break;

        case 4:
            // Take input for deletion
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(&head, value);
            break;

        case 5:
            // Search for a value
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(head, value))
            {
                printf("Value %d found in the list.\n", value);
            } else
            {
                printf("Value %d not found in the list.\n", value);
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

    return 0;
}
