#include <stdio.h>

#define MAX_SIZE 20 // we declare globally , max_size = 20 of array used here

void displayMenu()
{
    printf("\n\t\t\t-----------------------------------");
    printf("\n\t\t\t\t\tMenu:\n");
    printf("\t\t\t-----------------------------------\n");
    printf("[Press - 1] Insert element at nth location\n");
    printf("[Press - 2] Delete element at nth location\n");
    printf("[Press - 3] Search for an element\n");
    printf("[Press - 4] Display the list\n");
    printf("[Press - 5] Exit\n");
    printf("Enter your choice: ");
}

void displayList(int arr[], int size)
{
    printf("List: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertElement(int arr[], int *size)
{
    if (*size < MAX_SIZE)
    {
        int n, element;

        printf("Enter the position (n) to insert: ");
        scanf("%d", &n);

        if (n >= 1 && n <= *size + 1)
        {
            printf("Enter the element to insert: ");
            scanf("%d", &element);

            // Shift elements to make space for the new element
            for (int i = *size; i >= n; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[n - 1] = element;
            *size = *size + 1;

            printf("Element inserted successfully.\n");
        }
        else
        {
            printf("Invalid position. Please enter a position between 1 and %d.\n", *size + 1);
        }
    }
    else
    {
        printf("List is full. Cannot insert more elements.\n");
    }
}
void deleteElement(int arr[], int *size)
{
    if (*size > 0)
    {
        int n;

        printf("Enter the position (n) to delete: ");
        scanf("%d", &n);

        if (n >= 1 && n <= *size)
        {
            // Shift elements to remove the element at position n
            for (int i = n - 1; i < *size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            *size = *size - 1; // if we use *size++ then error will occured bacuse size is pointer type in this case

            printf("Element deleted successfully.\n");
        }
        else
        {
            printf("Invalid position. Please enter a position between 1 and %d.\n", *size);
        }
    }
    else
    {
        printf("List is empty. Cannot delete elements.\n");
    }
}
void searchElement(int arr[], int size)
{
    if (size > 0)
    {
        int element;

        printf("Enter the element to search: ");
        scanf("%d", &element);

        int found = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == element)
            {
                printf("Element found at position %d.\n", i + 1);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("Element not found in the list.\n");
        }
    }
    else
    {
        printf("List is empty. Cannot search for elements.\n");
    }
}
int main()
{
    int arr[MAX_SIZE];
    int size = 0;

    while (1)
    {
        displayMenu();

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertElement(arr, &size);
            
            break;

        case 2:
            deleteElement(arr, &size);
            break;

        case 3:
            searchElement(arr, size);
            break;

        case 4:
            displayList(arr, size);
            break;

        case 5:
            printf("Program terminated . Thanks using this program :) \n");
            return 0;

        default:
            printf("Invalid choice. Please choose between 1 and 5.\n");
        }
    }

    return 0;
}
