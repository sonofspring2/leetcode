#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
Given "pwwkew", the answer is "wke"
*/
using namespace std;


class Solution {
public:
	static int lengthOfLongestSubstring(string s) {
		int last[256]; 
		fill_n(last,256,-1); 
		int max_sub = 0; 
		int max_start = -1;
		int max_end = -1; 

		int cur_sub = 0; 
		int start =0;
		int end =0; 

		for(int i=0; i<s.length(); i++){
// 			cout <<"current char is " << s[i] << endl;
// 			cout <<"correspond last is " << last[s[i]] << endl << endl;
			if(last[s[i]] < start)  // exit before start pos; 
			{
				end = i; 
				cur_sub = end - start +1; 		
				last[s[i]] = i; 
			}	
			else 
			{
				start = last[s[i]] +1; 
				end = i; 
				cur_sub = end-start +1; 
				last[s[i]] = i;	
			}
			if(max_sub < cur_sub)
			{
				max_sub = cur_sub; 	
				max_start = start; 
				max_end = end; 
			}
		}
		
		// cout << "longest non-repeating substring is : " << '\n'; 
		// cout <<s.substr(max_start, max_end-max_start+1) << '\n';
		
		return max_sub; 
    }
};


int main(){
	string mystring("pwwkew");
	
	int max_sub_length = 0; 
	max_sub_length = Solution::lengthOfLongestSubstring(mystring); 
	
	cout << "longest non-repeating substring length is: " << max_sub_length << endl; 	
	return 0; 
}
