#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXWORD 220000
#define MAXLENGTH 32


void sort(char dictionary[][MAXLENGTH], int size)
{
    //Adapt the integer sorting algorithm here

}

int binarySearch(char dictionary[][MAXLENGTH], int size, char word[])
{
    //Adapt the integer binary search here
    return -1;
}


int readDictionary(char fname[], char dictionary[][MAXLENGTH], int max)
{
    int count = 0;
    FILE* infile;

    if(!( infile = fopen( fname, "r"))){
        return 0;
    }

    //Try to read up to max, but will stop if the file runs out
    while (count < max && fscanf(infile,"%s", dictionary[count++]) == 1);

    return count;
}

int queryWordList(char fname[], int* nQuery, 
                char dictionary[][MAXLENGTH], int size)
{
    FILE* infile;
    int count = 0, found = 0;
    char word[MAXLENGTH];

    if(!( infile = fopen( fname, "r"))){
        return 0;
    }

    while (count < *nQuery && fscanf(infile,"%s", word) == 1) {
        count++;
        if (binarySearch(dictionary, size, word) != -1){
            found++;
        }
    }

    //Update the number query if we cannot perform all
    if (count != *nQuery){
        *nQuery = count;
    }

    return found;
}

int main()
{
    char dictionary[MAXWORD][MAXLENGTH];
    char word[MAXLENGTH];

    int dSize = 0, success, nQuery = 10000, N;

    clock_t start, end;
    double seconds;

    //Read the "data size" as N
    printf("Data Size = ");
    scanf("%d", &N);

    //Initialize the dictionary up to N words
    // dSize is the actual size after initialization
    dSize = readDictionary("words_random.txt", dictionary, N);
    printf("Read %d words\n", dSize);

    //Sort dictionary first
    sort(dictionary, dSize);

    //Perform nQuery[10,000] searches
    success = queryWordList("words_query.txt", &nQuery, dictionary, dSize);

    //Print the statistic
    printf("Found %d out of %d queries in dictionary of %d words\n", 
        success, nQuery, dSize);

    return 0;
}
