#include<iostream>
#include<stack>
#include <string>
using namespace std;

bool isPair(char open,char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '[' && close == ']')
		return true;

	return false;
}

bool areBalanced(string exp)
{
	stack<char>s;

	for(int i=0;i<exp.length();i++)
	{	
		if(exp[i]=='('|| exp[i] == '{'|| exp[i] == '[')
		{
			s.push(exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (s.empty() == true || isPair(s.top(),exp[i]) == false)
				return false;
			s.pop();
		}
	}

	return s.empty();

}

int main()
{
	string expression;

	for (int i = 0; i < 1; i++) 
	{
		cin >> expression;

		if (areBalanced(expression))
			cout << "Balanced"<<endl;
		else
			cout << "Not Balanced"<<endl;

	}

	return 0;
}