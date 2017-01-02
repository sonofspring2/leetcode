
#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

int main(){
	int a = 1000000003;
	cout << "a is : " << a << endl; 
	cout << "after bit moving is " << (a >> 29) << endl;
	return 0; 
}
