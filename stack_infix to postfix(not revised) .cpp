#include <iostream>
#include <string>
#include <stdlib.h>     
#define arr_size 100
using namespace std;

struct Stack
{
	private :
		int arr[arr_size];
		int top = -1;
	public :
		void push(int value)
		{
			if (top == arr_size - 1)
			{
				cout << "StackOverFlow!" << endl;
				return;
			}
			arr[++top] = value;

		}

		int pop()
		{
			if (top == -1)
			{
				cout << "Stack is Empty!" << endl;
				return -1;
			}
			int value = arr[top];
			top--;
			return value;
		}
		bool isEmpty()
		{
			return (top == -1);
		
		}
		void displayStack()
		{
			for (int i = top; i > -1; i--)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		int topValue()
		{
			if (top == -1) {
				cout << "Stack is Empty!" << endl;
				return -1; 
			}
			return arr[top];

		}
		

};

bool isPair(char exp_paranth,char stk_paranth)
{
	if (exp_paranth == ']' && stk_paranth != '[')
		return false;
	else if (exp_paranth == ')' && stk_paranth != '(')
		return false;
	else if (exp_paranth == '}' && stk_paranth != '{')
		return false;

	return true;
}


bool checkParanthes(string exp)
{
	Stack stk;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			stk.push(exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if(stk.isEmpty()||isPair(exp[i],stk.topValue())==false)
			{
				return false;
			}
			stk.pop();
		}
	}
	return stk.isEmpty();
}

bool isOperator(char exp_char)
{
	if (exp_char == '+' || exp_char == '-' || exp_char == '*' || exp_char == '/')
		return true;
	return false;
}
bool isOperand(char exp_char)
{
	if (exp_char >='0' && exp_char <='9')
		return true;
	return false;
}

int performOperation(char operat,int op1,int op2)
{
	int result;
	
	switch(operat)
	{
	case '+':
		result= op1 + op2;
		break;
	case '-':
		result= op1 - op2;
		break;
	case '*':
		result= op1 * op2;
		break;
	case '/':
		if(op2 !=0)
			result= op1 / op2;
			break;
	}
	return result ;
}

int evaluatePostfix(string exp)
{
	Stack stk;
	for(int i=0;i<exp.length();i++)
	{
		if (exp[i] == ' ')
			continue;

		if (isOperand(exp[i])) 
		{
			stk.push(exp[i]-'0');
		}
		else if(isOperator(exp[i]))
		{
			int op2 = stk.pop();
			int op1 = stk.pop();
			int result = performOperation(exp[i], op1, op2);
			stk.push(result);
		}
	
	}
	return stk.topValue();
}
bool hasHighPreced(char stkTop,char exp_char)
{
	if(stkTop == '*'||stkTop=='/')
	{
		return true;
	}
	else if (stkTop == '+' || stkTop == '-')
	{
		if(exp_char =='+' || exp_char=='-')
		{
			return true;
		}
		else if(exp_char == '*' || exp_char == '/')
		{
			return false;
		}
	}
}

string infixToPostfix(string exp)
{
	Stack stk;
	string result="";

	for(int i=0;i<exp.length();i++)
	{
		if(isOperand(exp[i]))
		{
			result += exp[i];
			result+=" ";
		}
		else if(isOperator(exp[i]))
		{
			//top has high precedence pop out it 
			while(stk.isEmpty()==false && hasHighPreced (stk.topValue(),exp[i]))
			{
				result += stk.pop();
				result += " ";
			
			}
			stk.push(exp[i]);
		}
	}
	while (stk.isEmpty()==false)
	{
		result += stk.pop();
		result += " ";
	}
	return result;
}

int main()
{
	//(2 * 3) + (5 * 4)] - 9
	//cout<<evaluatePostfix("2 3 * 5 4 * + 9 -")<<endl;
	//cout << infixToPostfix("2*3+5*4-9") << endl;

	
	//2 3 4 * + 5 6 * -
	//2+3*4-5*6=-16
	cout << evaluatePostfix(infixToPostfix("2+3*4-5*6"))<< endl;
}