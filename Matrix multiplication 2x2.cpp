#include<iostream>

using namespace std;
const int B_rows = 2;
const int B_columns = 2;

const int C_rows = 2;
const int C_columns = 3;
int main()
{
	int B_matrix[B_rows][B_columns] = { {4,-1},{0,2} };
	int C_matrix[C_rows][C_columns] = { {1,4,2},{3,1,5} };
	int result_matrix[B_rows][C_columns] = { };

	for(int i=0;i< B_rows;i++)
	{
		for(int j=0;j< C_columns;j++)
		{
			int cell = 0;
			for(int k=0;k<B_columns;k++)
			{
				cell += B_matrix[i][k] * C_matrix[k][j];

			}
			result_matrix[i][j] = cell;

		}
	}

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout << result_matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}