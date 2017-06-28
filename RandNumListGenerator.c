#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //for booleans
#include <time.h>
#include <string.h>


int randNum(int maxVal)
{
    int r = rand() % maxVal;
    return r;
}

int main()
{
    srand(time(NULL)); //PUT IT AT THE BEGINNING!
    bool validInt = false;
    char numElements[15];
    char *numePtr = numElements;
    char max[15];
    char *maxPtr = max;
    int numEleInt;
    int maxInt;

    do
    {
        printf("How many elements do you want in the list?\n");
        scanf("%s", numePtr);

        //Check if string is a number
        numEleInt = atoi(numElements);

        if (numEleInt == 0 && numElements[0] != '0')
        {
            printf("Input is NOT an Integer! Try again\n");
        }
        else
        {
            validInt = true;

        }
    }while(!validInt);

    validInt = false;
    do
    {
        printf("Please enter the maximum integer value: ");
        scanf("%s", maxPtr);

        //Check if string is a number
        maxInt = atoi(max);

        if (maxInt == 0 && max[0] != '0')
        {
            printf("Input is NOT an Integer! Try again\n");
        }
        else
        {
            validInt = true;
        }
    }while(!validInt);

    //ask for what the file name would be
    FILE *fp;
    printf("Please enter the name of the generated file: ");
    char fileName[128];
    char *fnptr = fileName;
    scanf("%s", fnptr);
    //creates a new file
    fp = fopen(strcat(fileName, ".txt"), "w");

    //Generate random numbers
    int i = 0;
    for(i; i < numEleInt; i++)
    {
        //call randnum method
        int number = randNum(maxInt);
        //enter this number into the txt file
        fprintf(fp, "%i\n", number);
    }
    fclose(fp);

    return 0;
}
