#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	static int binarySearchRot(vector<int> &nums, int target){
		int low = 0; 
		int high = nums.size()-1;
		while(low<=high){
			int mid = ( low + high ) /2; 
			cout << "high " << high << ";" << "low " << low << ";" << "mid " << mid << endl; 
	
			if ( nums[mid] == target){
				return mid;  // return the found index; 
			}
//			if ( target > nums[mid] ) {
//				if ( target > nums[low]) {
//					
//				}
//				low = mid +1; 
//			}
//			
//			if ( target < nums[mid]) {
//				if ( target >= nums[low]) { //normal case 
//					high = mid -1; 
//				}
//				else {
//					low = mid + 1; 
//				}
//			}
			if( nums[mid] >=nums[low] ) {
				if (target < nums[mid] ) {
					target >=low ? high = mid -1: low = mid +1;
				}
				else {
					low = mid +1; 
				}
			}
			else {
				if ( target < nums[mid] ) {
					high = mid -1; 
				}
				else {
					target >= low ? high = mid -1: low = mid +1; 
				}
			}
			
		}

		return -1; 
	}

};

int main(){
	

	 // int array[] = {3,4 ,5 , 1 ,2};
	// int array[] = {3,4 ,5 , 6 ,12};
	 // int array[] = {5,1,3};
	 int array[] = {1,3,5};
	int target = 1;  
	vector<int> vect(array, array + sizeof(array)/sizeof(array[0]));
	int result = Solution::binarySearchRot(vect, target); 
	cout << " result of " << target << " is "<< result << endl; 
	
	return 0; 
}
