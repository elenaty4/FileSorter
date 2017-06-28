#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h> //for checking if file exists
#include <string.h>

void insertSort (int data[], int size)
{
    /* Insertion sort goes iterates through the list and check if the current element has elements that are LARGER than it.
       If that's the case then the both swap.
    */
    int SIZE = size;
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

void selectSort(int data[], int size)
{
    /* Selection sort iterates through a list and finds the smallest value.
       Once found, it is placed at the first of the list
    */
    int SIZE = size;
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

void bubbleSort(int data[], int size)
{
    /* Bubble Sort constantly compares two adjacent items and swap them if the 2nd item of the 2 is smaller than the 1st item
    */
    int SIZE = size;
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

int main()
{
    bool validInput = false;
    char fileName[128];
    char *fnptr = fileName;
    FILE *fp;
    do
    {
        printf("This program sorts a list in a file and creates a NEW file that is sorted\n");
        printf("Please enter a file that contains a list of numbers: ");

        scanf("%s", fnptr);

        fp = fopen(fileName, "r"); //will read the file

        //check if file exists
        if(access(fileName, F_OK) != -1)
        {
            validInput = true;
        }
        else
        {
            printf("That file does not exist. Please try again\n");
        }
    }while(!validInput);

    FILE *fp2;
    char line[128];

    //Taking ".txt' out of the fileName to create fileName_sorted.txt
    int nameLen = strlen(fileName)-4;
    char nameWOtxt[nameLen];
    strncpy(nameWOtxt, fileName, nameLen);
    nameWOtxt[nameLen] = '\0';
    fp2 = fopen(strcat(nameWOtxt, "_sorted.txt"), "w");

    int ch = 0;
    int lines = 0;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }
    int numList[lines];

    rewind(fp); //going back to the beginning of the file

    //add the elements in the file into the numList
    int i = 0;
    while(fgets(line, sizeof line, fp) && i < lines) //iterating by line
    {
        int intLine = atoi(line);
        numList[i] = intLine;
        i++;
    }
    printf("Sorting the file\n");

    //UNCOMMENT ONE OF THESE FUNCTIONS TO ACTIVATE THEM
    //insertSort(numList, lines);
    //selectSort(numList, lines);
    //bubbleSort(numList, lines);
    //mergeSort(numList, 0, lines-1);

    int j = 0;
    for(j; j < lines; j++)
    {
        fprintf(fp2, "%d\n", numList[j]);
    }

    fclose(fp);
    fclose(fp2);
    return 0;
}
