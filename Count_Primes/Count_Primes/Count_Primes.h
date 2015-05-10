// Count the number of prime numbers less than a non - negative number, n

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2){
            return 0;
        }
        else{
            int primeCount = 1;  // 1 not counted?
            const int bufferSize = (n - 1) >> 1; // only consider odd numbers, skip 1
            // array idx 0 <--> real number 3
            // array idx 1 <--> real number 5
            // array idx i <--> real number 2(i+1)+1
            // array idx imax = (n - 1 / 2) - 1 <--> real number n
            // N = 2i + 3,  i = (N - 3) / 2
            if (bufferSize > 0){
                vector<bool> visited(bufferSize, false);
                for (int i = 0; i < bufferSize; ++i){
                    if (!visited[i]){
                        int primeNumber = ((i << 1) + 3);
                        if (primeNumber < n){
                            primeCount++;
                        }
                        // every 2 * primeNumber --> -> index += primeNumber
                        // want to scan from p^2, so need (primeNumber >> 1) * 2 * primeNumber
                        // so the first idx to check is : currIdx + primeNumber * (primeNumber >> 1)
                        // to avoid overflow, need to check if it's okay to do the muplication
                        // so bufferSize - currIdx = the amount can be shift.
                        // so (bufferSize - currIdx) / (primeNumber) needs to be larger than (primeNumber >> 1)
                        if ((bufferSize - i) / primeNumber >= (primeNumber >> 1)){
                            int multipleOfThePrimeIdx = i + primeNumber * (primeNumber >> 1);
                            while (multipleOfThePrimeIdx < bufferSize){
                                visited[multipleOfThePrimeIdx] = true;
                                multipleOfThePrimeIdx += primeNumber;
                            }
                        }
                    }
                }
            }
            
            return primeCount;
        }
    }
};

