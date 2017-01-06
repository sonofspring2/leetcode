#include <iostream> 
#include <string>
#include <map> 
#include <vector> 

using namespace std; 

vector<vector<int> > fullSubset(vector<int> &nums){
	static int step =0 ;
	static vector<vector<int> > results ; 

	//if (step == 0){//first step 
		results.push_back(vector<int>()); 


	while (step <nums.size()){
		int curRows = results.size();
		for(int i=0; i< curRows; i++){
			results.push_back( results[i]);  // copy i; 
			results[results.size()-1].push_back(nums[step]); // put in nums[i]
		}
		step ++; 
	}

	return results; 
}
ostream & operator<<(ostream &out, const vector<int> &nums){
	for(int i=0; i<nums.size();i++){
		out << nums.at(i) << " "; 
	}
	out << endl; 
}

ostream & operator<<(ostream &out, const vector < vector<int> > &results){
	for(int i=0; i<results.size();i++){
		out << results.at(i); 
	}
	//out << endl; 

	return out; 
}


int main() {

	int arr[] = { 1 , 2 , 3, 4, 5, 6}; 
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0])); 

	cout << " initial array is: " << nums ; 
	vector<vector<int> > results; 
	results = fullSubset(nums); 

	cout << "result is " << endl; 
	cout << results; 

	cout << "final subset number is " << results.size() << endl; 
	return 0; 
}