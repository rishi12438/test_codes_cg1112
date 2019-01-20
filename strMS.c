#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXLENGTH 32
#define MAXWORD 220000

void M(char a[][MAXLENGTH], int low, int mid, int high) 
//Purposely modified to a obsure fashion for CG1112 :-)
// Dont write like this for actual assignment / work
{
    int n = high-low+1, k;

    char **b;
    int left=low, right=mid+1, bIdx=0, i;

    b = (char**) malloc(sizeof(char*) * n);

    for (i = 0; i < n; i++){
        b[i] = (char*) malloc(sizeof(char)* MAXLENGTH);
    }

    while (left <= mid && right <= high) {
        if (strcmp(a[left], a[right]) < 0) {
            strcpy(b[bIdx++], a[left++]);
        } else {
            strcpy(b[bIdx++], a[right++]);
        }
    } 

    while (left<=mid) strcpy(b[bIdx++], a[left++]);
    while (right<=high) strcpy(b[bIdx++], a[right++]);

    for (k = 0; k < n; ++k) 
        strcpy(a[low+k], b[k]);

    for (i = 0; i < n; i++){
        free(b[i]);
    }
    free(b);

}

void MSort (char a[][MAXLENGTH], int low, int high)
{
    if (low < high) {
        int mid = (low+high)/2;	

        MSort(a, low, mid);	
        MSort(a, mid+1, high);

        M(a, low, mid, high);	
    }
}

int readDictionary(char fname[], char dictionary[][MAXLENGTH], int max)
{
    int count = 0;
    FILE* infile;

    if(!( infile = fopen( fname, "r"))){
        return 0;
    }

    while (count < max && fscanf(infile,"%s", dictionary[count++]) == 1);

    return count;
}


int main(int argc, char**argv)
{
    char dictionary[MAXWORD][MAXLENGTH];
    int dSize, N;

    //Read the "data size" as N
    printf("Data Size = ");
    scanf("%d", &N);

    dSize = readDictionary("words_random.txt", dictionary, N);
    printf("Read %d words\n", dSize);

    //Use mysterious sorting function
    MSort(dictionary, 0, dSize-1);
    printf("Sorted\n");

    return 0;
}
