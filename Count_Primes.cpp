/*
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/

class Solution {
public:
   
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        
        int count = 0;
        bool *primes = new bool[n];
        
        for(int i = 0; i < n; i++)
            primes[i] = false;
        
        //using sieve of erasthosnas 
        for(int p = 2; (p*p) < n; p++)
        {
            if(primes[p] == false)
            {
                for(int j = p * p; j < n; j+=p)
                {
                    primes[j] = true;
                }
            }
        }
        for(int i = 2; i < n; i++)
        {
            if(!primes[i])
                count++;
        }
        return count;
    }
};
