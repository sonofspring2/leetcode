#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {

public:

    static vector<int> twoSum(vector<int>& nums, int target) {
	
	int pos1, pos2 =0;
	map<int,int> mymap; //map element value with its index; 
	vector<int> ret_vect;
	for(int i=0; i<nums.size(); i++){
	mymap[nums[i]] = i ;
	}	
	
	map<int,int>::iterator it = mymap.end();
	
	for(int i=0; i<nums.size(); i++){
		it = mymap.find(target - nums[i]); 
		if(it!=mymap.end()&& it->second !=i){
		ret_vect.push_back(i);
		ret_vect.push_back(it->second);
		break;
		}	
	}
		

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
