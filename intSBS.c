#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch( int a[], int N, int X ) {
    int idxOfX = -1, mid, low, high;

    low = 0;
    high = N - 1;
    while ( (low <= high) && (idxOfX == -1) ) {
        mid = (low + high) / 2;

        if ( a[mid] == X ){
            idxOfX = mid;
        } else if ( a[mid] < X ) {
            low = mid + 1;
        } else {
            high = mid - 1;    
        }
    }

    return idxOfX;
}

void sort(int a[], int N)
{
    int i, j, next;

    for ( i = 1; i < N; ++i) {
        next = a[i];

        for ( j = i-1; j >= 0 && a[j] > next; --j){
            a[j+1] = a[j];	
        }
        a[j+1] = next;   
    } 
}

int main()
{
    //You can write some simple example to test out sort() and
    // binarySearch()

    return 0;
}
