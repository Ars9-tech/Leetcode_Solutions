//Pow(x,n)
//--------

class Solution {
public:
    double helper(double x, long long n){  // base x, power n
        if(n==0) 
            return 1;

        double temp = helper(x, n/2); //recursive calling x^n/2
        if (n%2 == 0) 
            return temp*temp;  // n is even
        else 
            return x*temp*temp; // n is odd
    }
    double myPow(double x, int n) {
        long long exp = abs((long long)n);  // this line handles negative exponent safely 
        double result = helper(x, exp);
        if(n<0)
            return 1.0/result;
        
        return result;
    }
        
    
};


//Space Complexity = O(log n)
//Time Complexity = O(log n)

  
