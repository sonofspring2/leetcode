#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:

    static vector<int> twoSum(vector<int>& nums, int target) {
	
	int pos1, pos2 =0;
	int i =0; 
	vector<int>::iterator it = nums.begin();
	for(; it != nums.end(); it++){
		pos1 = i; 
		if(Solution::find(nums,target-*it,pos2)&& pos2!=pos1){
		break;
		}	
		i++;
    }     
	
	vector<int> ret_vect;
	ret_vect.push_back(pos1);
	ret_vect.push_back(pos2);

	return ret_vect;	
    }
	
	static bool find(vector<int>& nums, int find_elem, int &pos){
		bool found =false;
		int i=0;
		vector<int>::iterator it = nums.begin();
		for(; it != nums.end(); it++){
			if(*it == find_elem){
				found = true;
				pos = i;	 
				break;
			}
			i++;

		}	
		
		return found;
	}
};


int main(){
	int arr[] = {3,2,4};
	vector<int> vect(arr,arr+sizeof(arr)/sizeof(arr[0]));
	int target = 6; 
	vector<int> ret_vect = Solution::twoSum(vect,target);
	
	cout << "position is: " << ret_vect[0] <<" " << ret_vect[1]<< endl;
	return 0;
}
