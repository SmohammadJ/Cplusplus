#programmer: Mohammad J. Nourbakhsh
#include<iostream>

using namespace std;

int main(){
    int a[] = {8,1,2,6,9,5, 4,7, 3,0};
    // int a[] = {0,1,2,3,4,5,6,7,8,9};
    int n = 10;

    for(int i= 0 ; i< n; i++){
        int max=0;
        for (int j=0; j< n-i ;j++){
            if (a[j] >= a[max]) {
                max = j;
            }
        }
        int temp= a[max];
        a[max] = a[n-1-i] ;
        a[n-1-i] = temp;
    }
    
    for(int i=0 ; i< n; i++)
        cout<<a[i] << " ";
    return 0;
}