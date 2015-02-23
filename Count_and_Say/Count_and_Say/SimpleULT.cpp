#include "Count_and_Say.h"
#include <iostream>

void main(){
    Solution sol;

    for (int i = 1; i < 10; ++i){
        cout << sol.countAndSay(i) << endl;
    }
}