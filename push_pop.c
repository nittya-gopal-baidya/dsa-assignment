#include <stdio.h>

void pushData(int arr[], int n, int *size)
{
    printf("Enter Elements To Be Pushed : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Data has been pushed successfuly ");
    *size = *size + n;
}
void popData(int arr[], int pos, int *size)
{
    int poped_data=arr[pos];
    for (int i = pos; i < *size; i++)
    {
        arr[pos] = arr[pos + 1];
        *size = *size - 1;
    }
    printf("%d has been poped successfuly ",arr[poped_data]);
}
void display(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
}
int main()
{
    int max_size = 0, size = 0, n, choice,pos;
    printf("Enter the max size of array : ");
    scanf("%d", &max_size);
    int arr = (int *)malloc(max_size * sizeof(int));
    

    printf("\t\t----------------------------------------\n");
    printf("\t\t\t\tMENU : \n");

    printf("\t\t----------------------------------------\n");
    printf("\t\t\t [1]PUSH DATA \n");
    printf("\t\t\t [2]POP DATA \n");
    printf("\t\t\t [3]DISPLAY DATA\n");
    printf("\t\t\t [3]EXIT\n\n");

    printf("Enter your choice :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("How many data you want to push : ");
        scanf("%d", &n);
        size += n;
        if (size <= max_size)
        {
            pushData(arr, n, &size);
        }
        else
        {
            printf("Max size exceeds , Overflow Occur !");
        }
        break;
    case 2:
        printf("Enter the possition of data to be poped : ");
        scanf("%d",&pos);
        if(pos>size)
        {
            printf("Invalid possition , Please enter between 1 to %d ",size);
            return 0;
        }
        else
        {
            popData(arr,pos,&size);
            
        }
        break;
        case 3:
            display(arr,size);
            break;
        case 4:
            return 0;
        default:
        printf("Invalid Choice ! ");
    }
    return 0;
}
