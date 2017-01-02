
#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;


class Solution{
public:

	static int binarySearchRot(vector<int> &nums, int target){
		int low = 0; 
		int high = nums.size()-1;
		while(low <= high){
			int mid = ( low + high ) /2; 
			cout << "high " << high << ";" << "low " << low << ";" << "mid " << mid << endl; 
	
			if ( nums[mid] == target){
				return mid;  // return the found index; 
			}
			if( nums[mid] >=nums[low] ) {
				if (target < nums[mid] ) {
					target >=nums[low] ? high = mid -1: low = mid +1;
					cout <<" after update " << endl; 
					cout << "high " << high << ";" << "low " << low << ";" << "mid " << mid << endl; 
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
					target >= nums[low] ? high = mid -1: low = mid +1; 
				}
			}
			
		}

		return -1; 
	}

	static void binarySearchRegion(vector<int> &nums, int &start, int &end){
	}


	static void binarySearchStart(vector<int> &nums, int &start, int &target){
		int low = 0; 
		int high = nums.size()-1;
		
		while(low <= high){
			int mid = ( low + high ) /2; 
			if ( nums[mid] == target ){   // find one record it; 
				start = mid; 
			} 

		}	
	}
	static void binarySearchEnd(vector<int> &nums, int &start, int &end){
		int low = 0; 
		int high = nums.size()-1;
	}
};
int main(){

	return 0; 
}
