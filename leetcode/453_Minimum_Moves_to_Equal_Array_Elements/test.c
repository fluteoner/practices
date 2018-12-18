#include <stdio.h>

int main() 
{

    int arr[10] = {108,108,2,13,4,5,9,8,11,6};
    int first = arr[0];
    int second = arr[0];
    int i;

    for(i=0;i<10;i++)
    {
        if(first < arr[i])
        {
            second = first;
            first = arr[i];
        }
        else if(second < arr[i])
        {
            second = arr[i];
        }

    }

    printf("First = %d\n", first);
    printf("Second = %d\n", second);


    return 0;
}
