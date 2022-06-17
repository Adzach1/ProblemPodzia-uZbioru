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
    #pragma omp parallel shared(set_one, which, set_two) num_threads(4)
    {    
        long long set_one1 = 0, set_two1 = 0;
        string which1 = "";
        #pragma omp for schedule(static)
            for(int i = 0; i < n; i++){
                if(set_one1<=set_two1){
                    set_one1+=set[i];
                    which1 += '0';
                } else{
                    set_two1+=set[i];
                    which1 += '1';
                }
            }
        #pragma omp critical
        {
            set_one += set_one1;
            set_two += set_two1;
            which += which1;
        }
    }
    clock_t end = clock();
    float t = (float) (end - start) / CLOCKS_PER_SEC;


    cout<<set_one<<" "<<set_two<<endl;
    cout<<"Czas wykonania: "<<t<<endl;
    //cout<<which<<endl;
}