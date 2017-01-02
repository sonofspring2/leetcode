
#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;


class Solution{
public:

	static int subSum(vector<int> & nums, int & res_start, int &res_end){
		int cur =0; 
		int res = 0; // not choose any element; 
		
		int cur_start = 0; 

//		int res_start = 0; 
//		int res_end = 0; 
		for(int i=0; i< nums.size(); i++){
			cur += nums[i];
			if(cur > res){
				res = cur; 	
				res_start = cur_start; 
				res_end = i; 
			}
			if (cur < 0 ) {
				cur = 0; 
				cur_start = i+1; 
			}
		}	
		return res; 
	}
	//sum array is sum of a0...ai
	static vector<int> convertSum(vector<int> &nums){
		vector<int> * sum_array = new vector<int>[nums.size()]; 
		sum_array[0] = nums[0]; 

		for(i = 1; i< nums.size(); i++){
			sum_array[i] = sum_array[i-1] + nums[i]; 
		}

		return &sum_array; 
	}
	//sub array is delta of is Ai+1 - Ai; sub[0] = a[0]; 
	
	static vector<int> convertSub(vector<int> &nums){
		vector<int> * sub_array = new vector<int>[nums.size()]; 
		sub_array[0] = nums[0]; 
		for(int i=1; i<nums.size(); i++){
			sub_array[i] = a[i]-a[i-1]; 
		}
		return &sub_array;
	}
	
	static int binarySearch(vector<int> &nums){
	
	}	
};
int main(){

	int array[] = {3, -2, 1,2,-4,6,3,2}; 
	vector<int> vect(array, array+sizeof(array)/sizeof(array[0]));
	
	int start, end; 
	int res; 
	res = Solution::subSum(vect,start,end); 

	cout <<"mamimum sub sum is: " << res << endl; 
		
	return 0; 

}
