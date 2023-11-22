#include<stdio.h>

int main()
{
int arr[10],n;
printf("Enter 10 Elements : \n");
for(int i=0;i<10;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter position of element to be display : ");
scanf("%d",&n);
if(n<10)
    printf("%d th element in list is %d",n,arr[n-1]);
else
    printf("Please enter position between 1 and 10");




    return 0;
}