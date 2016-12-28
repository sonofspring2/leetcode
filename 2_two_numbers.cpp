#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};
 

ostream& operator<<(ostream &out, ListNode &li){
	ListNode *list_ptr = &li;
	//int i =0;
	while(list_ptr->next!=NULL)
	{
		out << list_ptr->val << " -> "  ; 
		list_ptr = list_ptr->next;
// 		out <<"iteration time is " << i <<"\n";
// 		i++;
		
	}
	//print out the last node value;
	out << list_ptr->val; 

	return out;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * res = new ListNode(0);
   		int len1 = Solution::lenList(l1);	     
   		int len2 = Solution::lenList(l2);	    

		//make the longer list List1;  
		ListNode * tempList = NULL; 
		if(Solution::lenList(l1) < Solution::lenList(l2)) //swap
		{
			tempList = l1; 
			l1 = l2; 
			l2 = tempList; 
		}
// 		cout << "after swap:" << '\n'; 
// 		cout << *l1 << endl; 
// 		cout << *l2 << endl<< endl; 
		if(Solution::lenList(l1) > Solution::lenList(l2))
		{
			int delta = Solution::lenList(l1) - Solution::lenList(l2); 
			ListNode * lastNode = NULL;
			lastNode = l2;
			while(lastNode ->next!=NULL) lastNode = lastNode -> next; 
			for(int i=0; i<delta; i++)
			{
				lastNode ->next = new ListNode(0);
				lastNode = lastNode->next; 
			}
		}
		
// 		cout <<"after padding 0: \n" ; 	
// 		cout << "list1 length is: " << Solution::lenList(l1) << "\n"; 	
// 		cout << "list2 length is: " << Solution::lenList(l2) << "\n"; 	
		for(int i=0; i< Solution::lenList(l1); i++)
		{
			int sum =0;
			int more =0;  
			bool first = true; 
			ListNode *tempList1 = l1; 
			ListNode *tempList2 = l2; 
			
			ListNode * endNode = NULL;
			while(tempList1 && tempList2){
				sum = tempList1->val + tempList2->val; 
				if(first){
				res->val = sum % 10; 
				endNode = res; 
				first = false; 
				}	
				else {
				endNode -> next = new ListNode((sum %10 + more)%10); 	
				endNode = endNode ->next;
				}
				more = (sum +more) / 10; 	
				tempList1 = tempList1 ->next;
				tempList2 = tempList2 ->next; 	
			}
			if(more){
				endNode -> next = new ListNode(more); 	
				endNode = endNode ->next;
			}
		}
		return res;	
    }

	static int lenList(ListNode* l1){
		int i =0; 
		while(l1->next!=NULL){
		l1 = l1 ->next; 
		i++;
		}
		i++;
		return i; 
	}
	
	
};

int main(){
	ListNode *mylist1= new ListNode(2);
	ListNode * nextnode = new ListNode(4); 
	mylist1->next = nextnode; 
	ListNode * nextnode2 = new ListNode(3); 
	mylist1->next->next = nextnode2; 
	
	ListNode *mylist2= new ListNode(5);
	ListNode * nextnode_2 = new ListNode(6); 
	mylist2->next = nextnode_2; 
 	ListNode * nextnode2_2 = new ListNode(4); 
 	mylist2->next->next = nextnode2_2; 
 	ListNode * nextnode3_2 = new ListNode(8); 
 	mylist2->next->next->next = nextnode3_2; 

	cout << *mylist1 << "\n"; 
	cout << *mylist2 << "\n"; 

	cout << "list1 length is: " << Solution::lenList(mylist1) << "\n"; 	
	cout << "list2 length is: " << Solution::lenList(mylist2) << "\n"; 	
	ListNode * res = NULL; 
	Solution mysol;
	res = mysol.addTwoNumbers(mylist1,mylist2);
	
 	cout << *res << "\n" ; 
}
