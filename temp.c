#include <stdio.h>
#include <stdlib.h>

void pushData(int arr[], int n, int *size)
{
    printf("Enter Elements To Be Pushed : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        *size=*size+1;
    }
    //*size = *size + n;
    printf("Data has been pushed successfuly\n ");
    
}
void popData(int arr[], int*size)
{
    //int poped_data = arr[pos-1];
    // for (int i = pos-1; i < *size; i++)
    // {
    //     arr[i] = arr[i + 1];
    if(*size<0)
    {
        printf("Stack is empty ! ");
    }
    else
    {
        printf("%d has been poped successfuly \n", arr[*size]);
        *size = *size - 1;
    }
    //}
    
}
void display(int arr[], int size)
{

    if (size <0)
    {
        printf("Stack is empty ! Nothing to display here \n");
    }
    else
    {
        for (int i = 0; i <= size; i++)
        {
            printf(" %d ", arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    int max_size = 0, size = -1, n, choice, pos;
    printf("Enter the max size of array : ");
    scanf("%d", &max_size);
    int *arr = (int *)malloc(max_size * sizeof(int));

    while (1)
    {
        printf("\t\t----------------------------------------\n");
        printf("\t\t\t\tMENU : \n");
        printf("\t\t----------------------------------------\n");
        printf("\t\t\t [1]PUSH DATA \n");
        printf("\t\t\t [2]POP DATA \n");
        printf("\t\t\t [3]DISPLAY DATA\n");
        printf("\t\t\t [4]EXIT\n\n");

        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("How many data you want to push : ");
            scanf("%d", &n);
            int temp_size=size + n;
            
            //printf("%d",size);
            if (temp_size <= max_size)
            {
                pushData(arr, n, &size);
            }
            else
            {
                printf("Max size exceeds , Overflow Occur !");
            }
            break;
        case 2:
            // printf("Enter the possition of data to be poped : ");
            // scanf("%d", &pos);
            // if (pos > size)
            // {
            //     printf("Invalid possition !");
            //     return 0;
            // }
            // else
            // {
                
                    popData(arr,&size);
                
            // }
            break;
        case 3:
            display(arr, size);
            break;
        case 4:
        printf("Thanks For Using This Program .\n");
            return 0;
        default:
            printf("Invalid Choice ! ");
        }
    }
    return 0;
}
