#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// Credit to Yasmin Senior + Deante Taylor
#define SIZE 100

int array[SIZE];

void fillArrayWithRandomNumbers(int array[SIZE]) {
for(int i = 0; i<SIZE; i++) array[i] = rand()%100;
}

void printArray(int array[SIZE]) {
for(int i = 0; i<SIZE; i++) printf("%5d", array[i]);
printf("\n");
}

typedef struct StartEndIndexes {
int start;
int end;

} StartEndIndexes;
void merge(int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;

int L[n1], R[n2];


for (i = 0; i < n1; i++)
L[i] = array[l + i];
for (j = 0; j < n2; j++)
R[j] = array[m + 1+ j];

i = 0; 
j = 0; 
k = l; 

while (i < n1 && j < n2)
    {
    if (L[i] <= R[j]){
    array[k] = L[i];
    i++;
    }else{
    array[k] = R[j];
    j++;
    }
    k++;
    }

while (i < n1){
    array[k] = L[i];
    i++;
    k++;
}


while (j < n2)
{
    array[k] = R[j];
    j++;
    k++;
    }
}


void* mergeSort(void* args) {
    StartEndIndexes sei = *((StartEndIndexes*)args);
    int error1, error2, midpoint;
    if (sei.start < sei.end){
    midpoint = (sei.start + sei.end) / 2;
    StartEndIndexes sei1, sei2;
    sei1.start = sei.start;
    sei1.end = midpoint;
    sei2.start = midpoint + 1;
    sei2.end = sei.end;
    pthread_t left_tid, right_tid;


    error1 = pthread_create(&left_tid, NULL, mergeSort, &sei1);
    error2 = pthread_create(&right_tid, NULL, mergeSort, &sei2);
    if (error1 != 0)
    printf("Error sorting left tree.\n");
    if (error2 != 0)
    printf("Error sorting right tree.\n");
    error1 = pthread_join(left_tid, NULL);
    error2 = pthread_join(right_tid, NULL);
    if (error1 != 0)
    printf("Error sorting left tree.\n");
    if (error2 != 0)
    printf("Error sorting right tree.\n");
    merge(sei.start, midpoint, sei.end);
}
return NULL;
}

int main() {
    srand(time(0));
    StartEndIndexes sei;
    sei.start = 0;
    sei.end = SIZE - 1;
    int error;
    fillArrayWithRandomNumbers(array);
    printf("Unsorted array: ");
    printArray(array);
    pthread_t tid;
    error = pthread_create(&(tid), NULL, &mergeSort, &sei);
    if (error != 0)
    printf("Error creating thread.\n");
    error = pthread_join(tid, NULL);
    if (error != 0)
    printf("Error joining thread.\n");
    printf("Sorted array: ");
    printArray(array);
}