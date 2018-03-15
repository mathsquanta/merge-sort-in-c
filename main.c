#include<stdio.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right)
{
    //counter variables
    int i,j,k;
    //declare variable for the number of elements in each sub array
    int nl,nr; // num of variables in left and right sub array
    nl = (mid - left) +1;
    nr = (right - mid);

    //define the subarrays

    int leftArray[nl];
    int rightArray[nr];
    // fill the left sub array
    for (i = 0; i<=nl; i++)
        {
            leftArray[i] = a[left+i];// this is because this array starts from index 0 in the main array and ends at mid
        }
    //fill the right sub array
    for (i = 0; i<=nr; i++)
        {
            rightArray[i] = a[mid+1+i];// this starts from mid+1 to the right most index in the main array
        }
        // initialize counter variables

        j = 0;
        i = 0;
        k =left;

        while(i<nl &&  j<nr)
        {
            if(leftArray[i]< rightArray[j])
                {
                    a[k] = leftArray[i];
                    i++;
                    k++;
                }
            if (leftArray[i]>rightArray[j])
                {
                    a[k] = rightArray[j];
                    j++;
                    k++;
                }
        }
        //Check for remaining unused part of sub array
        while (i<nl)
            {
                a[k] = leftArray[i];
                i++;
                k++;
            }

        while (j<nr)
            {
                a[k] =rightArray[j];
                j++;
                k++;
            }
}

void sort(int a[], int left, int right)
{
    int mid = 0;
    if (left<right)
    {
        mid = (left+right)/2;
        sort(a,left,mid);
        sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

int main()
{
    int i;
    int a[8] = {55,12,4, 0,14,76,8,98};
    printf("The unsorted array\n");
    for (i = 0; i<=7;i++)
    {
        printf("%d " ,a[i]);
    }

    printf("\n");
    sort(a,0,7);
    printf("The sorted array\n");
    //iterate through the array and print sorted array
    for (i = 0; i<=7;i++)
    {
        printf("%d " ,a[i]);
    }
    return 0;
}
