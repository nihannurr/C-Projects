#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE      10
#define MAX_ARRAY_DATA  100

void* AllocateMemory(int size);
int* GenerateRandomIntArray(int arraySize);

void* AllocateMemory(int size)
{
    void* pvMem = NULL;

    pvMem = malloc(size);

    if (NULL == pvMem) {
        fprintf(stderr, "Cannot allocate memory!!!\n");
        exit(EXIT_FAILURE);
    }
    return pvMem;
}

int* GenerateRandomIntArray(int arraySize)
{
    int* pArray;
    int i;

    pArray = AllocateMemory(sizeof(int) * arraySize);
    for(i = 0; i < arraySize; ++i)
        pArray[i] = (rand() % MAX_ARRAY_DATA) + 1;

    return pArray;
}


void PrintIntArray(int* pArr, int size)
{
    int i;

    for (i = 0; i < size; ++i)
        printf("Array[%d] ..: %d\n", i, pArr[i]);
}

 int RemoveFromIntArray(int* pArr, int size, int last_index, int toDelete)
 {
    int i,j;

    for (i = 0; i < size; ++i)
        if (pArr[i] == toDelete)
            break;

    // Item NOT FOUND!!!
    if (i == size)
        return last_index;

    for(j = i + 1; j < last_index; ++j)
        pArr[j - 1] = pArr[j];
    --last_index;

    return last_index;
 }

void ReverseIntArray(int* pArr, int size)
{
    int i, temp;

    for (i = 0; i < size / 2; ++i) {
        temp = pArr[i];
        pArr[i] = pArr[size - 1 - i];
        pArr[size - 1 - i] = temp;
    }
}



int main()
{
    int* pArray;
    //int last_index;


    srand(time(NULL));// seed random number generator!

    pArray = GenerateRandomIntArray(ARRAY_SIZE);
    PrintIntArray(pArray, ARRAY_SIZE);

    /*
    last_index = RemoveFromIntArray(pArray, ARRAY_SIZE, ARRAY_SIZE, 13);
    printf("Integer array after deletion of 13\n");
    PrintIntArray(pArray, last_index);
    */
    printf("After reversing int array...\n");
    ReverseIntArray(pArray, ARRAY_SIZE);
    PrintIntArray(pArray, ARRAY_SIZE);


    return 0;
}
