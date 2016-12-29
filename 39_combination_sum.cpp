#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>


using namespace std;

ostream & operator<<(ostream &out,const vector<int> & vect){
	for(int i=0; i< vect.size(); i++){
		out << vect[i] << " "; 
	}
	out << endl; 
	return out; 
}

vector< vector<int> > results;

class Solution{
public:
//	static vector< vector<int> > results; 
	static vector< vector<int> > combinationSum(vector<int>& candidates, int target){
		sort(candidates.begin(),candidates.end());
		vector< vector<int> > results; 
		vector<int> com; 
		com.push_back(0);
		oneCombination(candidates,target,com, results);	
			
		return results;
	}
// make com[0] as the current sum of the array; 	
 	static void  oneCombination(vector<int>& candidates, int target, vector<int>& com, vector< vector<int> > & results){
// 	static void  oneCombination(vector<int>& candidates, int target){
// 		cout <<"current one combination is: " << com; 

		if(com[0] == target){
			//cout <<"found one !" << com; 
			results.push_back(vector<int>(com.begin()+1,com.end()));
			return; 
		}
		
		if(com[0] >  target){
// 			com[0] -=com[com.size()-1]; 
// 			com.pop_back();
			return; 
		}
		for(int i=0; i< candidates.size(); i++){
 			if(candidates[i] >= com.back())
			{
				com.push_back(candidates[i]); 
				com[0] +=candidates[i]; 
 				oneCombination(candidates, target, com, results); 	
//  				oneCombination(candidates, target); 	
	 			com[0] -=com[com.size()-1]; 
 				com.pop_back();
				
			}
		}	
		
	}
};
int main(){
	
	int array[] = {2, 1, 6, 7};
	vector<int> candidates(array,array + sizeof(array)/sizeof(array[0]));

	int target = 7; 
	
	cout << "candidates is : " << candidates; 
	cout << "copy of candidates is : " << vector<int> (candidates); 
	vector<int> oneResult; 
	oneResult.push_back(0);
	
// 	Solution::oneCombination(candidates,target,oneResult); 
//	cout << "one result is: " << oneResult; 

	vector< vector<int> > results_local; 	
 	results_local = Solution::combinationSum(candidates,target); 
	for(int i=0; i<results_local.size(); i++){
		cout << results_local[i]; 
	}
	return 0; 
}
