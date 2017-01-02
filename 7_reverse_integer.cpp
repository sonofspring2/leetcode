class Solution {
public:
    int reverse(int x) {
        int imax = numeric_limits<int>::max();
        int imin = numeric_limits<int>::min();
        //long k = x; 
        bool isNegative = false;
        if(x < 0){
            x = -x;
            isNegative = true;
        }
        if(x == 0 || x == imin ){
            return 0; 
        }

        long res =0;
        int rem;
        while(x){
            rem  = x % 10; 
            res  = res *10 + rem;
            x = x /10;
        }
        if (res > imax) return 0; 
        
        return isNegative? -res: res;
    }
};