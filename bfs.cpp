#programmer: Mohammad J. Nourbakhsh
#include<iostream>
#include<queue>
using namespace std;
int main(){
    
    int adj [5][5] = {{ 0, 1, 1, 0, 0},
        { 0, 0, 0, 0, 1},
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 1, 0}};
    
    int *d = new int[5];
    int s = 0;
    d[s ] = 0 ;
    for (int i=0; i<5; i++) {
        if (i == s) {
            continue;
        }
        d[i] = 10000;
    }
    
    queue<int> myQ;
    myQ.push(s);
    while (!myQ.empty()) {
        int u = myQ.front();
        myQ.pop();
        for (int i=0; i<5; i++) {
            
            if (adj [u][i] ==1 && d[i] == 10000 && u != i) {
                d[i] = d[u] +1;
                myQ.push(i);
            }
        }
    }
    
    for (int i=0; i<5; i++) {
        if (i != s) {
            std::cout<<"i= "<< i<<" d= "<< d[i]<<" ";
        }
    }
    return 0;
}