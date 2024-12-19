#include<iostream>
#include<stack>
#include <string>

using namespace std;

bool isOperand(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int calcOperation(int operand1, int operand2, char sign)
{
	if (sign == '+')
		return operand1 + operand2;

	else if (sign == '-')
		return operand1 - operand2;

	else if (sign == '*')
		return operand1 * operand2;

	else if (sign == '/')
	{
		if (operand2 == 0)
		{
			cout << "Division by Zero" << endl;
			exit(-1);
		}

		return operand1 / operand2;
	}
}
int evalPostfix(string exp)
{
	stack<int>s;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == ' ')
			continue;

		if (isOperand(exp[i]))
		{
			string tmp = "";
			do 
			{
				tmp += exp[i];
				i++;
			} while (isOperand(exp[i]));

			s.push(stoi(tmp));//stoi convert string to int
		}
		else if (isOperator(exp[i]))
		{
			int operand2 = s.top();
			s.pop();
			int operand1 = s.top();
			s.pop();
			s.push(calcOperation(operand1, operand2, exp[i]));
		}
	}
	return s.top();
}

int main()
{

	cout << evalPostfix("5 5 /2 + 1 9 * -") << endl;
	cout << evalPostfix("10 2 1 + 5 + * 2 / 1 -") << endl;
	cout << evalPostfix("2 8 2 3 * + 2 / + 1 -") << endl;

	return 0;
}