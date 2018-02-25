#programmer: Mohammad J. Nourbakhsh
#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

void merge1(int *a, int start, int middle, int end){
    int csize = end - start +1; // because end is included
    int * c = new int[csize];
    int i=start, j= middle +1 , k =0;
    while (k<csize) {
        if ((a[i] < a[j] && i<= middle) || j>end ) {
            c[k] = a[i] ;
            i++; k++;
        }
        else if ( (a[i] >= a[j] && j <= end ) || i> middle){
            c[k] = a[j];
            j++; k++;
        }
    }
    for ( k=0; k< csize; k++) {
        a[k+start] = c[k];
    }

}
void mergesort1(int *a, int start, int end){

    if (start< end) {
        int middle =(start + end) /2;
        mergesort1(a, start, middle); // including middle
        mergesort1(a, middle+1, end);// including end
        merge1(a, start, middle, end);
    }

}
void swap(int &a, int &b){
    int temp = a;
    a= b;
    b= temp;
}
int partition(int *a, int start, int end){
    int i = start, j =start;
    while( j <end){
        if( a[j] < a[start]){
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }
    
    swap(a[i], a[start]);
    return i;
    

}

void qs(int *a, int start, int end){
    if (start<end) {
        srand(time(NULL));
        int pivot = rand() % (end-start) + start;
        swap(a[start], a[pivot]);
        int pos = partition (a, start, end);
        qs(a, start, pos); // not including pos because pos has been found
        qs(a, pos+1, end);
    }
}
int main(){

    int a[10]= {10,1,2,3,4,9,8,7,6,5};
    int size = 10; // index from 0 ... 9
    //mergesort1(a, 0, size-1);
    qs(a,0, size);
    for (int i=0; i<size; i++) {
        std::cout<<a[i] << " ";
    }
    
    return 0;

}