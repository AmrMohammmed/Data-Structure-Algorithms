#include<iostream>
#include<stack>
#include <string>
using namespace std;

int main()
{

	//swap method
	string s = "Hello World";
	string s_copy = s;
	int i = 0;
	int j = s.length() - 1;
	char tmp;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		//swap(s[i], s[j]);
		i++; j--;
	}

	cout << s << endl;

	//stack method
	stack <char>stk;
	

	for (int i = 0; i < s_copy.length(); i++)
		stk.push(s_copy[i]);
	for (int i = 0; i < s_copy.length(); i++)
	{
		s_copy[i] = stk.top();
		stk.pop();
	}
	


	cout << s_copy << endl;

	return 0;
}