#include <stdio.h>
#include <stdlib.h>

void insertSort (int data[])
{
    /* Insertion sort goes iterates through the list and check if the current element has elements that are LARGER than it.
       If that's the case then the both swap.
    */
    const int SIZE = 5;
    int i = 0;
    int k;
    for(i; i < SIZE; i++)
    {
        k = data[i];
        int j = i - 1;
        while(j >= 0)
        {
            if(k < data[j])
            {
                //swap occurs
                data[j+1] = data[j];
                data[j] = k;
            }
            j--;
        }
    }
}

void selectSort(int data[])
{
    /* Selection sort iterates through a list and finds the smallest value.
       Once found, it is placed at the first of the list
    */
    const int SIZE = 5;
    int i = 0;
    int minValue;
    int minPos; //position of where the minimum value is at
    for(i; i < SIZE; i++)
    {
        minValue = data[i];
        int j = i;
        for(j; j < SIZE; j++)
        {
            if(data[j] < minValue)
            {
                minValue = data[j];
                minPos = j;
            }
        }
        //Not check if that's the most minimum value
        if(minValue < data[i]) //if it's less than the first unswapped element
        {
            //swap occurs
            data[minPos] = data[i];
            data[i] = minValue;
        }
    }
}

void bubbleSort(int data[])
{
    /* Bubble Sort constantly compares two adjacent items and swap them if the 2nd item of the 2 is smaller than the 1st item
    */
    const int SIZE = 5;
    int i = 0;
    int j = 0;
    int temp;
    for(i; i < SIZE-1; i++)
    {
        for(j; j < SIZE-1-i; j++)
        {
            if(data[j] > data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

}

void mergeSort(int data[], int low, int high) //lowIndex, highIndex
{
    /* Merge Sort divides the list in half and sorts those divided pieces by splitting them in half as well
       and then puts them back together in the end in order
    */
    if(low != high)
    {
        int mid = (low + high) / 2; //splitting the indexes up
        mergeSort(data, low, mid); //the first half of the split up
        mergeSort(data, mid+1, high); //the second half of the split up
        merge(data, low, mid, high); //Merge the whole list afterwards
    }
}

void merge(int data[], int low, int mid, int high) //lowIndex, middleIndex, highIndex
{
    int i = low;
    int j = low;
    int k = mid + 1;
    int temp[100]; //Array used for merging

    for(i,j,k; j <= mid && k <= high; i++)
    {
        if(data[j] <= data[k])
        {
            temp[i] = data[j++];
        }
        else
        {
            temp[i] = data[k++];
        }

    }

    while(j <= mid)
    {
        temp[i++] = data[j++];
    }

    while(k <= high)
    {
        temp[i++] = data[k++];
    }

    int m = low;
    for(m; m <= high; m++)
    {
        data[m] = temp[m];
    }
}

void quickSort(int data[])
{
    /* Quick Sort involves a pivot. Anything that is smaller than the pivot will move to the LEFT of the pivot and anything
       that is larger than the pivot will move to the RIGHT of the pivot.
       The last element in a list will ALWAYS start out as a pivot in this case.
    */
    const int SIZE = 8;
    int pivot = data[SIZE-1];


}

int main()
{
    printf("Sorting Algorithm practice time!\n");
    printf("Insertion Sort algorithm\n");
    printf("Insertion sort is not a fast sorting algorithm because it uses nested loops. It is useful for only small data sets.\n");
    int data[5] = {98, 29, 87, 83, 61};
    insertSort(data);

    //print the array
    printf("\n");
    int i = 0;
    for(i; i < 5; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("\n");

    printf("Selection Sort algorithm\n");
    printf("Selection sort is ALSO not a fast sorting algorithms because it uses nested loops. It is useful for only small data sets.\n");
    int data2[5] = {8, 39, 31, 90, 21};
    selectSort(data2);

    //print the array
    printf("\n");
    i = 0;
    for(i; i < 5; i++)
    {
        printf("%d ", data2[i]);
    }
    printf("\n");
    printf("\n");

    printf("Bubble Sort algorithm\n");
    printf("Bubble Sort is ALSO not a fast sorting algorithm because it ALSO uses nested loops. It is useful for only small data sets.\n");
    int data3[5] = {16, 80, 17, 25, 52};
    selectSort(data3);

    //print the array
    printf("\n");
    i = 0;
    for(i; i < 5; i++)
    {
        printf("%d ", data3[i]);
    }
    printf("\n");
    printf("\n");

    printf("Merge Sort algorithm\n");
    printf("Merge Sort, unlike the other sorts, is a recursive method of sorting. It's faster and it works for larger data sets\n");
    int data4[] = {62, 31, 5, 94, 93, 95, 15, 52};
    mergeSort(data4, 0, 7);

    //print the array
    printf("\n");
    i = 0;
    for(i; i < 8; i++)
    {
        printf("%d ", data4[i]);
    }
    printf("\n");
    printf("\n");

    /*
    printf("Quick Sort algorithm\n");
    printf("Quick Sort, like Merge sort, ALSO uses recursion and it is faster and works for larger data sets \n");
    int data5[] = {60, 62, 78, 26, 13, 61, 68, 41};
    quickSort(data5);
    */
    return 0;
}
