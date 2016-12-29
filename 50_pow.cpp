#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std; 

class Solution{
public:
	static	double myPow(double x, int n){
		cout << "n is " << n << endl;
		if(x ==1){
			return 1;
		}
		double half = 0;
		if(n==1)
			return x; 
		if(n==0)
			return 1.0; 
		if(n>0)
		{	
			half = myPow(x,n/2);		
			if(n%2==0){ return half * half; }
			else if(n%2 == 1) {return half * half * x; } 	
		}
//	deal with tricky one -2147483648;
		else if(n<0)
		{
			if(n == -2147483648){
				half = myPow(x,-(n/2)); 
				return 1/(half*half); 
			}
					
			return 1/myPow(x, -n); 
		}
		
//         if(n == 0)
//             return 1;
//         if(n<0){
//             n = -n;
//             x = 1/x;
//         }
// 		double half;
// 		half = myPow(x,n/2);		
// //        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
// 		return (n%2==0) ? half*half: x*half*half; 
		
		return 0; 
	}	
};

int main(){
	
	int temp = -2147483648;
	cout <<"temp is " << temp << endl; 
	cout <<"abs 1 temp is " << -temp << endl; 
	cout <<"abs 2 temp is " << abs(temp)/2 << endl; 
	cout <<"divide 2 temp is " << temp/2 << endl; 
	cout <<"abs 1 temp/2 is " << -(temp/2) << endl; 

	double result = Solution::myPow( 2.0,temp+1 );  
	cout <<"pow result is : " << result << endl; 
	return 0;
}
