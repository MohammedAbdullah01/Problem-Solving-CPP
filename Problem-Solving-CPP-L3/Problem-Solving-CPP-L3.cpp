#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#pragma region Public Function
void PrintMessageOnScreen(string msg)
{
	cout << msg << endl;
}

int ReadPositiveNumber(string msg)
{
	int num;

	do
	{
		PrintMessageOnScreen(msg);
		cin >> num;
	} while (num < 0);

	return num;
}

void Swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

string ReadString(string msg)
{
	string str;
	PrintMessageOnScreen(msg);
	getline(cin, str);
	return str;
}

char ReadCharacter(string msg)
{
	char character;
	PrintMessageOnScreen(msg);
	cin >> character;
	return character;
}

int ReadNumber()
{
	int number;
	PrintMessageOnScreen("Please Enter Number ?");
	cin >> number;
	return number;
}

float ReadNumberFloat()
{
	float number;
	PrintMessageOnScreen("Please Enter Float Number ?");
	cin >> number;
	return number;
}

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
#pragma endregion


#pragma region Problem 1 (2 Procedure)

void FillMatrixWithRandomNumbers(int matrix[3][3], short strartFrom, short endTo)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = RandomNumber(strartFrom, endTo);
		}
	}
}

void PrintMatrix(int matrix[3][3], short rows, short columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("%0*d ", 3, matrix[i][j]);
		}
		cout << endl;
	}
}
#pragma endregion

#pragma region Problem 2 (Procedure)
void PrintEachRowSum(int matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += matrix[i][j];
		}
		cout << "Row " << i + 1 << " Sum = " << sum << endl;
	}
}
#pragma endregion

#pragma region Problem 3 (2 Procedure)
void PrintRowsSumInArray(int arr[3])
{
	for (int j = 0; j < 3; j++)
	{
		cout << "Row " << j + 1 << " Sum = " << arr[j] << endl;
	}
}

void SumMatrixRowsInArray(int matrix[3][3], int arr[3])
{
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += matrix[i][j];
		}
		arr[i] = sum;
	}
}
#pragma endregion

#pragma region Problem 4 (Function , Procedure)
int SumColumnsInMatrix(int matrix[3][3], int column)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += matrix[i][column];
	}
	return sum;
}

void PrintEachColumnsSum(int matrix[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		cout << "Columns " << i + 1 << " Sum = " << SumColumnsInMatrix(matrix, i) << endl;
	}
}
#pragma endregion

#pragma region Problem 5 (2 Procedure)
void SumMatrixColumnsInArray(int matrix[3][3], int arr[3])
{
	for (int j = 0; j < 3; j++)
	{
		arr[j] = SumColumnsInMatrix(matrix, j);
	}
}

void PrintColumnsSumInArray(int arr[3])
{
	for (int j = 0; j < 3; j++)
	{
		cout << "Columns " << j + 1 << " Sum = " << arr[j] << endl;
	}
}
#pragma endregion

#pragma region Problem 6 (Procedure)

void FillMatrixWithOrderedNumbers(int matrix[3][3])
{
	short order = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = order++;
		}
	}
}

#pragma endregion

#pragma region Problem 7 (Procedure)
void TransposeMatrix(int matrix[3][3], int temp[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			temp[j][i] = matrix[i][j];
		}
	}
}
#pragma endregion

#pragma region Problem 8 (Procedure)

void MultiplyTwoMatrix(int matrix[3][3], int matrix2[3][3], int resultMatrix[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			resultMatrix[i][j] = matrix[i][j] * matrix2[i][j];
		}
	}
}
#pragma endregion

#pragma region Problem 9 (2 Procedure)
void PrintMiddleRowOfMatrix(int matrix[3][3], short Rows, short Columns)
{
	short MiddleRow = Rows / 2;
	for (short i = 0; i < Columns; i++)
	{
		printf("%0*d ", 2, matrix[MiddleRow][i]);
	}
	cout << endl;
}

void PrintMiddleColumnsOfMatrix(int matrix[3][3], short Rows, short Columns)
{
	short MiddleColumns = Columns / 2;
	for (short i = 0; i < Columns; i++)
	{
		printf("%0*d ", 2, matrix[i][MiddleColumns]);
	}
	cout << endl;
}
#pragma endregion

#pragma region Problem 10 (Function)
int SumAllNumbersInMatrix(int matrix[3][3], short rows, short columns)
{
	int sum = 0;
	for (short i = 0; i < rows; i++)
	{
		sum += SumColumnsInMatrix(matrix, i);
	}
	return sum;
}
#pragma endregion

#pragma region Problem 11 (Function)
bool CheckSumTwoMatrixEqualOrNotEqual(int matrix[3][3], int matrix2[3][3], short rows, short columns)
{
	return SumAllNumbersInMatrix(matrix, rows, columns) == SumAllNumbersInMatrix(matrix2, rows, columns);
}
#pragma endregion

#pragma region Problem 12 (Function)
bool CheckTwoMatrixEqualOrNotEqual(int matrix[3][3], int matrix2[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (matrix[i][j] != matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
#pragma endregion

#pragma region Problem 13 (Function)
bool IsIdentityMatrix(int matrix[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
			{
				return false;
			}
		}
	}
	return true;
}
#pragma endregion

#pragma region Problem 14 (Function)
bool IsScalarMatrix(int matrix[3][3], short rows, short columns)
{
	short firstDiagElement = matrix[0][0];
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if ((i == j && matrix[i][j] != firstDiagElement) ||
				(i != j && matrix[i][j] > 0))
			{
				return false;
			}
		}
	}
	return true;
}
#pragma endregion

#pragma region Problem 15 (Function)
short HowManyRepetedNumberInMatrix(int matrix[3][3], short findNumber, short rows, short columns)
{
	short counter = 0;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (matrix[i][j] == findNumber)
			{
				counter++;
			}
		}
	}
	return counter;
}
#pragma endregion

#pragma region Problem 16 (Function)
bool IsMatrixSparce(int matrix[3][3], short rows, short columns)
{
	return HowManyRepetedNumberInMatrix(matrix, 0, rows, columns) >= rows * columns / 2;
}
#pragma endregion

#pragma region Problem 17 (Function)
bool IsExistsNumberInMatrix(int matrix[3][3], int Findnumber, short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (matrix[i][j] == Findnumber)
			{
				return true;
			}
		}
	}
	return false;
}
#pragma endregion

#pragma region Problem 18 (Procedure)
void PrintIntersectedNumbers(int matrix[3][3], int matrix2[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (IsExistsNumberInMatrix(matrix2, matrix[i][j], rows, columns))
			{
				cout << matrix[i][j] << setw(4);
			}
		}
	}
}
#pragma endregion

#pragma region Problem 19 (2 Function)
int MinNumberInMatrix(int matrix[3][3], short rows, short columns)
{
	int min = INT_MAX;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
		}
	}
	return min;
}

int MaxNumberInMatrix(int matrix[3][3], short rows, short columns)
{
	int max = INT_MIN;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
			}
		}
	}
	return max;
}
#pragma endregion

#pragma region Problem 20 (Function)
bool IsPalindromMatrix(int matrix[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns / 2; j++)
		{
			if (matrix[i][j] != matrix[i][columns - 1 - j])
			{
				return false;
			}
		}
	}
	return true;
}
#pragma endregion

#pragma region Problem 21 (Procedure)
void PrintFibonacciSeries(short number)
{
	int prev1 = 1, prev2 = 1, temp;
	cout << prev1 << "   " << prev2;
	for (short i = 2; i < number; i++)
	{
		temp = prev1 + prev2;
		cout << "   " << temp;
		prev2 = prev1;
		prev1 = temp;
	}
}
#pragma endregion

#pragma region Problem 22 (Procedure)
void PrintFibonacciSeriesRecursion(short number, short prev1, short prev2)
{
	int temp = 0;
	if (number > 0)
	{
		temp = prev1 + prev2;
		prev2 = prev1;
		prev1 = temp;
		cout << temp << "   ";

		PrintFibonacciSeriesRecursion(number - 1, prev1, prev2);
	}
}
#pragma endregion

#pragma region Problem 23 (Prosedure)
void PrintFirstLetterInString(string str)
{
	bool isFirstLetter = true;
	cout << "\nFirst Letters Of This String:\n";
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && isFirstLetter)
		{
			cout << str[i] << endl;
			isFirstLetter = false;
		}
		else if (str[i] == ' ')
		{
			isFirstLetter = true;
		}
	}
}
#pragma endregion

#pragma region Problem 24 (Function)
string UppercaseFirstLetterOfEachWord(string str)
{
	bool flag = true;

	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && flag)
		{
			str[i] = toupper(str[i]);
			flag = false;
		}
		else if (str[i] == ' ')
		{
			flag = true;
		}
	}
	return str;
}
#pragma endregion

#pragma region Problem 25 (Function)
string LowercaseFirstLetterOfEachWord(string str)
{
	bool flag = true;

	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && flag)
		{
			str[i] = tolower(str[i]);
			flag = false;
		}
		else if (str[i] == ' ')
		{
			flag = true;
		}
	}
	return str;
}
#pragma endregion

#pragma region Problem 26 (2 Function)
string UpperAllLetters(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

string LowerAllLetters(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}
#pragma endregion

#pragma region Problem 27 (Function)
char InvertLetterCase(char character)
{
	return (isupper(character)) ? tolower(character) : toupper(character);
}
#pragma endregion

#pragma region Problem 28 (Function)
string InvertAllStringLettersCase(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = InvertLetterCase(str[i]);
	}
	return str;
}
#pragma endregion

#pragma region Problem 29 (2 Function)
enum enWhatToCount
{
	CapitalLetters = 1 , SmallLetters = 2 
};
short CountLetters(string str , enWhatToCount whatToCount)
{
	short counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (whatToCount == enWhatToCount::CapitalLetters && isupper(str[i]))
			counter++;

		if (whatToCount == enWhatToCount::SmallLetters && islower(str[i]))
			counter++;
	}
	return counter;
}
//OR
short CountSmallLettersInString(string str)
{
	short counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (islower(str[i]))
		{
			counter++;
		}
	}
	return counter;
}

short CountCapitalLettersInString(string str)
{
	short counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
		{
			counter++;
		}
	}
	return counter;
}

#pragma endregion

#pragma region Problem 30 (Function)
short HowManyRecurringcharacters(string str , char findLetter )
{
	short counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] == findLetter)
			counter++;
	}
	return counter;
}
#pragma endregion








int main()
{
	srand((unsigned)time(NULL));

#pragma region Problem 1
	/*int matrix[3][3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);
	PrintMatrix(matrix ,3, 3);*/
#pragma endregion

#pragma region Problem 2
	/*int matrix[3][3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);

	cout << "The Following is a 3X3 random matrix\n";
	PrintMatrix(matrix ,3, 3);

	cout << "\nThe Following are the sum of each row in the matrix:\n";
	PrintEachRowSum(matrix);*/

#pragma endregion

#pragma region Problem 3
	/*int matrix[3][3];
	int arr[3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);

	cout << "The Following is a 3X3 random matrix\n";
	PrintMatrix(matrix ,3, 3);

	SumMatrixRowsInArray(matrix , arr);
	cout << "\nThe Following are the sum of each row in the One Dimension Array:\n";
	PrintRowsSumInArray(arr);*/

#pragma endregion

#pragma region Problem 4
	/*int matrix[3][3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);

	cout << "The Following is a 3X3 random matrix\n";
	PrintMatrix(matrix ,3, 3);

	cout << "\nThe Following are the sum of each columns in the Matrix:\n";
	PrintEachColumnsSum(matrix);*/

#pragma endregion

#pragma region Problem 5
	/*int matrix[3][3];
	int arr[3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);

	cout << "The Following is a 3X3 random matrix\n";
	PrintMatrix(matrix ,3, 3);

	SumMatrixColumnsInArray(matrix , arr);

	cout << "\nThe Following are the sum of each columns in the Array:\n";
	PrintColumnsSumInArray(arr);*/

#pragma endregion

#pragma region Problem 6
	/*int matrix[3][3];
	FillMatrixWithOrderedNumbers(matrix);

	cout << "The Following is a 3X3 Matrix With Ordered Numbers:\n";
	PrintMatrix(matrix ,3, 3);*/

#pragma endregion

#pragma region Problem 7
	/*int matrix[3][3] , matrixTransposed[3][3];
	FillMatrixWithOrderedNumbers(matrix);

	cout << "The Following is a 3X3 Matrix With Ordered Numbers:\n";
	PrintMatrix(matrix ,3, 3);

	TransposeMatrix(matrix , matrixTransposed);

	cout << "\nThe Following is the transpose matrix:\n";
	PrintMatrix(matrixTransposed ,3, 3);*/

#pragma endregion

#pragma region Problem 8
	/*int matrix[3][3] , matrix2[3][3] , resultMatrix[3][3];

	FillMatrixWithRandomNumbers(matrix , 1 , 10);

	FillMatrixWithRandomNumbers(matrix2 , 1 , 10);

	MultiplyTwoMatrix(matrix , matrix2 , resultMatrix);

	cout << "Matrix (1):\n";
	PrintMatrix(matrix ,3, 3);

	cout << "\nMatrix (2):\n";
	PrintMatrix(matrix2 ,3, 3);

	cout << "\nResult: Multiply Two Matrix ( Matrix (1) * Matrix (2) ):\n";
	PrintMatrix(resultMatrix ,3, 3);*/

#pragma endregion

#pragma region Problem 9
	/*int matrix[3][3];

	FillMatrixWithRandomNumbers(matrix , 1 , 10);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	cout << "\nMiddle Row Of Matrix (1) is:\n";
	PrintMiddleRowOfMatrix(matrix , 3 , 3);

	cout << "\nMiddle Columns Of Matrix (1) is:\n";
	PrintMiddleColumnsOfMatrix(matrix, 3, 3);*/
#pragma endregion

#pragma region Problem 10
	/*int matrix[3][3];

	FillMatrixWithRandomNumbers(matrix , 1 , 10);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	cout << "\nSum Of Matrix (1) is : ";
	cout << SumAllNumbersInMatrix(matrix , 3 , 3);*/
#pragma endregion

#pragma region Problem 11 
	//int matrix[3][3], matrix2[3][3];
	////int matrix[3][3] = { {10,20,30} , {40,50,60} , {70,80,90} }, matrix2[3][3] = { {10,20,30} , {40,50,60}, {70,80,90} };

	//FillMatrixWithRandomNumbers(matrix, 1, 10);
	//cout << "Matrix (1):\n";
	//PrintMatrix(matrix, 3, 3);

	//FillMatrixWithRandomNumbers(matrix2, 1, 10);
	//cout << "\nMatrix (2):\n";
	//PrintMatrix(matrix2, 3, 3);

	//if (CheckSumTwoMatrixEqualOrNotEqual(matrix, matrix2, 3, 3))
	//	cout << "Yes: Matrices are equal \n";
	//else
	//	cout << "No: Matrices are not equal \n";

#pragma endregion

#pragma region Problem 12
//int matrix[3][3], matrix2[3][3];
////int matrix[3][3] = { {10,20,30} , {40,50,60} , {70,80,90} }, matrix2[3][3] = { {10,20,30} , {40,50,60}, {70,80,90} };

//FillMatrixWithRandomNumbers(matrix, 1, 10);
//cout << "Matrix (1):\n";
//PrintMatrix(matrix, 3, 3);

//FillMatrixWithRandomNumbers(matrix2, 1, 10);
//cout << "\nMatrix (2):\n";
//PrintMatrix(matrix2, 3, 3);

//if (CheckTwoMatrixEqualOrNotEqual(matrix, matrix2, 3, 3))
//	cout << "Yes: Matrices are equal \n";
//else
//	cout << "No: Matrices are not equal \n";

#pragma endregion

#pragma region Problem 13
/*int matrix[3][3] = { {1,0,0} , {0,1,0} , {0,0,1} };

cout << "Matrix (1):\n";
PrintMatrix(matrix, 3, 3);

if (IsIdentityMatrix(matrix,3, 3))
	cout << "\nYes: Matrices Is Identity \n";
else
	cout << "\nNo: Matrices Is Not Identity \n";*/

#pragma endregion

#pragma region Problem 14
	/*int matrix[3][3] = { {10,0,0} , {0,9,0} , {0,0,9} };

	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	if (IsScalarMatrix(matrix,3, 3))
		cout << "\nYes: Matrices Is Scalar \n";
	else
		cout << "\nNo: Matrices Is Not Scalar \n";*/

#pragma endregion

#pragma region Problem 15
		/*int matrix[3][3];

		FillMatrixWithRandomNumbers(matrix, 1, 10);
		cout << "Matrix (1):\n";
		PrintMatrix(matrix, 3, 3);

		int inputNumber = ReadPositiveNumber("\nEnter Number To Count In Matrix ?");
			cout << "Number " << inputNumber << " Count in Matrix "
			<< HowManyRepetedNumberInMatrix(matrix , inputNumber , 3 ,3);*/

#pragma endregion

#pragma region Problem 16
			/*int matrix[3][3] = { {10,11,0} , {12,9,0} , {0,0,6} };

		   cout << "Matrix (1):\n";
		   PrintMatrix(matrix, 3, 3);

		   if(IsMatrixSparce(matrix , 3, 3))
		   {
			   cout << "\nYes: It Is Sparse\n";
		   }
		   else
		   {
			   cout << "\nNo: It`s Not Sparse\n";
		   }*/

#pragma endregion

#pragma region Problem 17
		   /*int matrix[3][3];

		   FillMatrixWithRandomNumbers(matrix, 1, 10);
		   cout << "Matrix (1):\n";
		   PrintMatrix(matrix, 3, 3);

		   int inputFindNumber = ReadPositiveNumber("\nEnter The Number To Look For In Matrix ?");

		   if (IsExistsNumberInMatrix(matrix, inputFindNumber , 3,3))
		   {
			   cout << "Yes: It Is There";
		   }
		   else
		   {
			   cout << "No: It`s Not There";
		   }*/
#pragma endregion

#pragma region Problem 18
		   /*int matrix[3][3] , matrix2[3][3];

		   FillMatrixWithRandomNumbers(matrix, 1, 10);
		   cout << "Matrix (1):\n";
		   PrintMatrix(matrix, 3, 3);

		   FillMatrixWithRandomNumbers(matrix2, 1, 10);
		   cout << "\nMatrix (2):\n";
		   PrintMatrix(matrix2, 3, 3);

		   cout << "\nIntersected Numbers are:\n";
		   PrintIntersectedNumbers(matrix ,matrix2 , 3 ,3);*/

#pragma endregion

#pragma region Problem 19
		   /*int matrix[3][3];

			   FillMatrixWithRandomNumbers(matrix, 10, 100);
			   cout << "Matrix (1):\n";
			   PrintMatrix(matrix, 3, 3);

			   cout << "\nMinimum Number Is:\n";
			   cout << MinNumberInMatrix(matrix, 3, 3);

			   cout << "\nMaximum Number Is:\n";
			   cout << MaxNumberInMatrix(matrix, 3, 3);*/
#pragma endregion

#pragma region Problem 20
			   /*int matrix[3][3] = { {1,2,1} , {5,5,5} , {7,3,7} };

			   cout << "Matrix (1):\n";
			   PrintMatrix(matrix, 3, 3);

			   if (IsPalindromMatrix(matrix,3, 3))
				   cout << "\nYes: Matrix Is Palindrom \n";
			   else
				   cout << "\nNo: Matrix Is Not Palindrom \n";*/
#pragma endregion

#pragma region Problem 21
				   //PrintFibonacciSeries(10);
#pragma endregion

#pragma region Problem 22
//PrintFibonacciSeriesRecursion(10, 0, 1);
#pragma endregion

#pragma region Problem 23
//PrintFirstLetterInString(ReadString("Please Enter Your String ?\n"));
#pragma endregion

#pragma region Problem 24 
/*string str = ReadString("Please Enter Your String ?\n");
str = UppercaseFirstLetterOfEachWord(str);
cout << "\nString After Conversion:\n";
cout << str << endl;*/
#pragma endregion

#pragma region Problem 25
/*string str = ReadString("Please Enter Your String ?\n");
str = LowercaseFirstLetterOfEachWord(str);
cout << "\nString After Conversion:\n";
cout << str << endl;*/
#pragma endregion

#pragma region Problem 26
/*string str = ReadString("Please Enter Your String ?\n");

cout << "\nString After Upper:\n" << UpperAllLetters(str) << endl;

cout << "\nString After Lower:\n" << LowerAllLetters(str) << endl;*/
#pragma endregion

#pragma region Problem 27
/*char character = InvertLetterCase(ReadCharacter("Please Enter a Character ?\n"));
cout << "\nChar After Inverting Case:\n" << character;*/
#pragma endregion

#pragma region Problem 28
/*string str = InvertAllStringLettersCase(ReadString("Please Enter a Your String ?\n"));
cout << "\nString after inverting All Letters Case:\n" << str;*/
#pragma endregion

#pragma region Problem 29
//string str = ReadString("Please Enter a Your String ?\n");
//cout << "\nString Length : " << str.length() << endl;
//cout << "\nCount Small Letters: " << CountLetters(str , enWhatToCount::SmallLetters) << endl;
//cout << "\nCount Capital Letters: " << CountLetters(str , enWhatToCount::CapitalLetters) << endl;
#pragma endregion

#pragma region Problem 30
//string str = ReadString("Please Enter a Your String ?\n");
//
// char character = ReadCharacter("\nPlease Enter a Character ?\n");
//
// short count = HowManyRecurringcharacters(str , character);
//
//cout << "\nLetter '"<< character << "' Count = " << count << endl;
#pragma endregion









}