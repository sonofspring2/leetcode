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
        while(temp /10){lenNum*=10; temp = temp/10;}
        if(x/lenNum == x%10) 
            return (isPalindrome ( (x %lenNum)/10 ) );
        else
            return false;
    }
};
