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
			int num = 0;
			do 
			{
				num = (num * 10) + (exp[i] - '0');
				i++;
			} while (isOperand(exp[i]));
			s.push(num);
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
	return 0;
}