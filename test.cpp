#include "testlib.h"
#include <iostream>
 
using namespace std;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    
    const int MAX_N = 1000;
    const int MAX_M = 1000;
    const int MAX_VAL = 100;
    const int MIN_VAL = -100;
 
   
    int n = rnd.next(1, MAX_N);
    int m = rnd.next(1, MAX_M);
 
 
    cout << n << " " << m << endl;
 
   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) {
                cout << " ";
            }
            cout << rnd.next(MIN_VAL, MAX_VAL);
        }
        cout << endl;
    }
 
    return 0;
}

