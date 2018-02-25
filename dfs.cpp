#programmer: Mohammad J. Nourbakhsh
#include<iostream>
#include<stack>
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
    
    //queue<int> myQ;
    //myQ.push(s);
    stack<int> myStack;
    myStack.push(s);
    while (!myStack.empty()) {
        int u = myStack.top();
        myStack.pop();
        for (int i=0; i<5; i++) {
            
            if (adj [u][i] ==1 && d[i] == 10000 && u != i) {
                std::cout<<"\nu "<<u<<" "<< "i "<<i;
                d[i] = d[u] +1;
                myStack.push(i);
            }
        }
    }
    
    for (int i=0; i<5; i++) {
        if (i != s) {
            std::cout<<"\ni= "<< i<<" d= "<< d[i]<<" ";
        }
    }
    return 0;
}