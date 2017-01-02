
#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

// here Record records the longest substring when s[i] is included. 
struct Record{
	int length; 
	int start; 
	int end;
};

class Solution {
public:
	static string longestPalindrome(string s){
		int len = s.size();
		Record * records = new Record[len]; 
		
		records[0].length =1;
		records[0].start =1;		
		records[0].end =1;		
		
		for(int i=1; i<len; i++){
			int candidate1 = 1; // just s[i]; 
			Record record_temp; 
			record_temp.length =1; 
			record_temp.start = i; 	
			record_temp.end = i; 	
			
			records[i] = record_temp; 
		
			int candidate2=0;
			
			int back = i;
			while(back >=0 && s[back] == s[i] ) {
				candidate2 ++ ;
				back --; 
			}
			
			if(candidate2 > candidate1 ) {
				record_temp.length = candidate2; 
				record_temp.start = back+1; 
				record_temp.end = i; 
				records[i] = record_temp; 
			}
			
			int candidate3 =0; 
			int symmetric_index = i-1 - records[i-1].length ; 
			cout << "s[" <<i<<"] = " <<s[i] << endl;
			cout <<  "s[" <<"symmetric"<<"] = " <<"s[" <<symmetric_index<<"] = " <<s[symmetric_index] << endl;
			if(symmetric_index >=0 && s[symmetric_index] == s[i]){
				candidate3 = records[i-1].length + 2; 
			}
			if(candidate3 > candidate1 && candidate3 > candidate2) {
				record_temp.length = candidate3; 
				record_temp.start = symmetric_index; 
				record_temp.end = i; 
				
			} 
			records[i] = record_temp; 
		}

		Record maxRecord = records[0]; 
		for(int i=0; i<len; i++){
			if(records[i].length > maxRecord.length){
				maxRecord = records[i]; 
			}	
		}
		return s.substr(maxRecord.start,maxRecord.end - maxRecord.start+1); 
	}

};

int main(){

	string longestSub; 
	// string s("forgeeksskeegfor");
	// string s("2333355");
	string s("bananas");
	longestSub = Solution::longestPalindrome(s);
	cout << "longest substring is :" << longestSub << endl; 

	return 0; 
}
