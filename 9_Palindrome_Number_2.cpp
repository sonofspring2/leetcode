class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        if(x <10 && x >=0)
            return true;
        if(x >=10 && x<100)
        {
            return (x/10==x%10)? true: false;
        }
        int temp = x;
        int lenNum =1;
        int len=1;
        while(temp /10){lenNum*=10;len++; temp = temp/10;}
        
        int temp2 = x; 
        int high=len; 
        int low =0;
        while(high > low)
        {
            int highBit = temp2 /lenNum; 
            int lowBit = temp2 %10; 
            if(highBit !=lowBit)
            {
                return false;
            }
            temp2 = (temp2%lenNum) / 10; 
            lenNum /=100;
            
            high --;
            low++;
        }
        
        return true;
    }
};