#include<iostream>
#include <stdlib.h> 
#include <time.h> 
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int maxNum = atoi(argv[2]);
    int* set = new int[n];
    for(int i = 0; i < n; i++){
        set[i] = rand() % (maxNum+1);
    }
    clock_t start = clock();
    string which = "";
    long long set_one = 0, set_two = 0;
    for(int i = 0; i < n; i++){
        if(set_one<=set_two){
            set_one+=set[i];
            which += '0';
        } else{
            set_two+=set[i];
            which += '1';
        }
    }
    clock_t end = clock();
    float t = (float) (end - start) / CLOCKS_PER_SEC;


    cout<<set_one<<" "<<set_two<<endl;
    cout<<"Czas wykonania: "<<t<<endl;
    //cout<<which<<endl;
}