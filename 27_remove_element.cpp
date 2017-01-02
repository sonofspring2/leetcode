
#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

ostream & operator<<(ostream &out,const vector<int> & vect){
	for(int i=0; i< vect.size(); i++){
		out << vect[i] << " "; 
	}
	out << endl; 
	return out; 
}
class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        int removeNum = 0;
        for(int i=0; i<nums.size(); ){
			cout << "nums is :" << nums; 
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
                removeNum ++; 
                continue;
            }
            i++;
        }
        
        return removeNum;
    }
};
int main(){
	int array[] = {1};
	vector<int> nums(array,array + sizeof(array)/sizeof(array[0]));
	int val = 1; 
	
	int removeNum;
	removeNum = Solution::removeElement(nums,val);
	cout << "removed number is " << removeNum << endl;
	cout << "after remove, nums is " << nums;
	return 0; 
}
