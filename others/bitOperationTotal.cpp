#include <iostream>
#include <vector>
#include <string>
#include <map>
// #include <ioformat> 

using namespace std;

#define INFO

class BitOperations{
public:
	static void swap(int &a, int &b){
		#ifdef INFO
		cout << "before swap: " << a <<" " << b <<endl;  
		#endif
		a = a^b;
		b = a^b;
		a = a^b; 	
		#ifdef INFO
		cout << "after swap: " << a <<" " << b <<endl;  
		#endif
	}
	
	// using &1 to determine is odd or even 
	static bool isOdd(const int &a){
		#ifdef INFO
		cout << "Input " << a <<"	" <<  ( a&1? "This is an odd number" : "This is an even number" )<< endl; 
		#endif
		return a&1; 
	}


	// using >> to get the abs of a int; 
	static int getAbs(const int & a){
		#ifdef INFO
		cout << "abs of " << a << " is " << (( a^(a>> 31)) - (a>> 31) ) << endl; 
		#endif 
		return (( a >> 31) ^a )- (a >> 31); 
	}	
	
	// using XOR to determine only once element, other element appear twice; 
	static int OnceElement(int * nums, int len){
		int res =0; 
		for(int i=0; i<len; i++){
			res ^=nums[i]; 
		}
		#ifdef INFO
		cout << "Single element is " << res << endl; 
		#endif
		
		return res; 
	}
	
	static int Average1(const int &a, const int &b){
		return (a+b)/2; 
	}
	static int Average2(const int &a, const int &b){
		return (a&b) + ((a^b)>>1); 
	}


//	static int SelectLarger(const int &a, const int &b, const int &c) // a?b:c
//	{
//		int y = (b^c)&(-a);
//		return b^y; 
//	}
};

int main(){
	
	int a = 10001; 
	int b = 277882760;
	int nums[] = {2,3,5,10,5,2,3}; 

	// BitOperations::swap(a,b); 

//	BitOperations::isOdd(b); 
//	BitOperations::OnceElement(nums, sizeof(nums)/sizeof(nums[0])); 
	BitOperations::getAbs(a); 
	BitOperations::getAbs(-1000); 

	int aa = 2000000002;
	int bb = 2000000000;
	
	int mean1,mean2; 
	mean1 = BitOperations::Average1(aa,bb);
	mean2 = BitOperations::Average2(aa,bb);
	
	#ifdef INFO
	cout << "mean1 is " << mean1 << endl;
	cout << "mean2 is " << mean2 << endl;
	#endif

//	int larger = BitOperations::Select(0,a,b);	
	return 0; 
}
