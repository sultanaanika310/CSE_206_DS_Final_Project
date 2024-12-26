#include <stdio.h>
#define maxSize 100   // Maximum size of the array

// Function to insert an element at a specific position in the array
void insert (int arr[], int *size, int element, int position)
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
void delete (int arr[], int *size, int position)
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
int search (int arr[], int size, int element)
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
void display (int arr[], int size)
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

int main()
{
    int arr[maxSize];   // Array declaration
    int size = 0;
    int choice, element, position;

    while (1)
    {
        printf("\nSelect Operation:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for an element\n");
        printf("4. Display the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Insert an element
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the positon (0 to %d) : ", size);
            scanf("%d", &position);
            insert(arr, &size, element, position);
            break;

        case 2:
            // Delete an element
            printf("Enter the position to delete (0 to %d) : ", size-1);
            scanf("%d", &position);
            delete(arr, &size, position);
            break;

        case 3:
            // Search for an element
            printf("Enter the element to search: ");
            scanf("%d", &element);
            position = search(arr, size, element);
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
            display (arr, size);
            break;

        case 5:
            // Exit the program
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
