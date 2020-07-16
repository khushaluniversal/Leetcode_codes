/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int power_sign = 1;
        int base_sign = 1;
        long long int y = n;
        
        if(n < 0)
            power_sign = -1;
            
        
        y = power_sign * y;
        
        if((x < 0.0) && (n & 1))
            base_sign = -1.0;
        
        x = x * base_sign;
        
        int i = 1;
        
        while(y > 0)
        {
            if(y & 1)
                ans = ans * x;
            
            y = y >> 1;
            x = x * x;
        }
        if(power_sign < 0)
            ans = 1.0 / ans;
        
        return(ans * base_sign);
    }
};
