#include <iostream>
#include <string> 
#include "cmath"

using namespace std;
// p2 : CheckPrime()
//p3  : isAcceptsDivision()

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
	cin >> str;
	return str;
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
#pragma endregion



#pragma region Problem 1 => (2 Procedure , Function)
void PrintTableHeader()
{
	PrintMessageOnScreen("\n\n\t\t\tMultiplication Table From 1 To 10\n\n");
	cout << "\t";

	for (int i = 1; i <= 10; i++)
	{
		cout << i <<  "\t";
	}
	PrintMessageOnScreen("\n--------------------------------------------------------------------------------------");
}

string coulmSeprator(int i)
{
	return (i == 10) ? "  |" : "   |";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << coulmSeprator(i) << "\t";

		for (int a= 1; a <= 10; a++)
		{
			cout << i * a << "\t";
		}
		cout << endl;
	}
	
}
#pragma endregion

#pragma region Problem 2 => (enum, Procedure, Function)
enum enPrimeNotPrime
{
	Prime = 1 , NotPrime = 2
};

enPrimeNotPrime CheckPrime(int num)
{
	int m = num / 2;
	for (int i = 2; i <= m; i++)
	{
		if (num % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumbersFrom1ToN(int num)
{
	cout << "\nPrime Numbers From ( 1 ) To ( " << num << " ) are : " << endl;
	for (int i = 1 ; i <= num; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
		{
			cout << i << endl;
		}
	}
}
#pragma endregion

#pragma region Problem 3 => (Procedure, 2 Function)
bool isAcceptsDivision(int num1 , int num2)
{
	return num1 % num2 == 0;
}

int SumAllDivisors(int num)
{
	int sum = 0;
	for (int i = 1; i < num; i++)
	{
		if (isAcceptsDivision(num , i))
		{
			sum += i;
		}
	}
	return sum;
}

void PrintNumberPerfectOrPerfect(int num)
{
	if (num == SumAllDivisors(num))
		cout << num << " IS Perfect";
	else
		cout << num << " IS Not Perfect";
}
#pragma endregion

#pragma region Problem 4 => (Procedure)
void PrintPerfectNumbersFrom1ToN(int num)
{
	cout << "\nPerfect Numbers From ( 1 ) To ( " << num << " ) are : " << endl;
	for (int i = 1; i <= num; i++)
	{
		if (i == SumAllDivisors(i))
		{
			cout << i << endl;
		}
	}
}
#pragma endregion

#pragma region Problem 5 (Procedure)
void PrintReverseOfNumber(int number)
{
	int remainder = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number /= 10;
		cout << remainder << endl;
	} 
}
#pragma endregion

#pragma region Problem 6 (Function)
int SumOfDigits(int number)
{
	int remainder = 0, sum = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number /= 10;
		sum += remainder;
	}
	return sum;
}

#pragma endregion

#pragma region Problem 7 (Function)
int reverseNumber(int number)
{
	int remainder = 0 ,result = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number /= 10;
		result = result * 10 + remainder;
	}
	return result;
}

#pragma endregion

#pragma region Problem 8 (Function)
short countDigitFrequency(int number , short digit)
{
	short remainder = 0 , counter = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number /= 10;
		if (digit == remainder)
			counter++;
	}
	return counter;
}
#pragma endregion

#pragma region Problem 9 (Procedure)
void PrintAllDigitFrequency(int number)
{
	for (short i = 0 ; i < 10; i++)
	{
		short countDigit = 0;
		countDigit = countDigitFrequency(number , i);

		if (countDigit > 0)
		{
			cout << "Digit ( " << i << " ) Frequency is ( " << countDigit << " ) Time" << endl;
		}
	}
}
#pragma endregion

#pragma region Problem 10 (Procedure)
void PrintNumberOrderFromLeftToRight(int number)
{
	number = reverseNumber(number);

	PrintReverseOfNumber(number);
}
#pragma endregion

#pragma region Problem 11 (Function)
bool IsPalindromeNumber(int currentNum)
{
	return currentNum == reverseNumber(currentNum);
}
#pragma endregion

#pragma region Problem 12 (Procedure)
void PrintInvertedNumberPatternDesc(int num)
{
	for (int i = num ; i >= 1; i--)
	{
		for (int a = i; a >= 1 ; a--)
		{
			cout << i;
		}
		cout << endl;
	}
}
#pragma endregion

#pragma region Problem 13 (Procedure)
void PrintInvertedNumberPatternAsc(int num)
{
	for (int i = 1; i <= num; i++)
	{
		for (int a = 1; a <= i; a++)
		{
			cout << i;
		}
		cout << endl;
	}
}
#pragma endregion

#pragma region Problem 14 (Procedure)
void PrintInvertedLetterPatternDesc(int num)
{
	for (int i = (65 + num) - 1; i >= 65; i--)
	{
		for (int a = 65; a <= i; a++)
		{
			cout << (char)i;
		}
		cout << endl;
	}
}
#pragma endregion

#pragma region Problem 15 (Procedure)
void PrintInvertedLetterPatternAsc(int num)
{
	for (int i = 65 ; i < (65 + num); i++)
	{
		for (int a = 65; a <= i; a++)
		{
			cout << (char)i;
		}
		cout << endl;
	}
}
#pragma endregion

#pragma region Problem 16 (Procedure)
void PrintAllWordsFromAAAToZZZ() 
{
	string result = "";

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int a = 65; a <= 90; a++)
			{
				result += (char)i;
				result += (char)j;
				result += (char)a;
				cout << result << endl;
				result = "";
			}
		}
	}
}
#pragma endregion

#pragma region Problem 17 (Functions)

bool GuessPassword(string originalPassword)
{
int counter = 0;
string guessPass = "";
for (int i = 65; i <= 90; i++)
{
	for (int j = 65; j <=90 ; j++)
	{
		for (int h = 65; h <= 90 ; h++)
		{
			guessPass += (char)i;
			guessPass += (char)j;
			guessPass += (char)h;
			counter++;

			cout << "Trial[" << counter << "] : " << guessPass << endl;

			if (guessPass == originalPassword)
			{
				PrintMessageOnScreen("--------------------------------------");
				PrintMessageOnScreen("Password Is " + originalPassword);
				cout << "Found after " << counter << " Trail" << endl;
				PrintMessageOnScreen("--------------------------------------");
				return true;
			}
			guessPass = "";
		}
	}
}
return false;
}

#pragma endregion

#pragma region Problem 18 (2 Function)
string EncryptionText(string text)
{
	string EncryptText = "";
	for (int i = 0; i < text.length(); i++)
	{
		int asciiCode = (int)text[i];
		asciiCode += 2;
		EncryptText += (char)asciiCode;
	}
	return EncryptText;
}

string DecryptionText(string encrypttext)
{
	string DecryptText = "";
	for (int i = 0; i < encrypttext.length(); i++)
	{
		int asciiCode = (int)encrypttext[i];
		asciiCode -= 2;
		DecryptText += (char)asciiCode;
	}
	return DecryptText;
}
#pragma endregion

#pragma region Problem 19 (Function)
int RandomNumber(int from , int to)
{
	return rand() % (to - from + 1) + from;
}
#pragma endregion

#pragma region Problem 20 (Enum , Function)
enum enCharacterType { SmallLetter , CapitalLetter , SpecialCharacter , DigitInOrder };

char GetCharacterRandom(enCharacterType charType)
{
	switch (charType)
	{
	case enCharacterType::SmallLetter:
		return (char)RandomNumber(97, 122);

	case enCharacterType::CapitalLetter:
		return (char)RandomNumber(65, 90);

	case enCharacterType::SpecialCharacter:
		return (char)RandomNumber(33, 47);

	case enCharacterType::DigitInOrder:
		return (char)RandomNumber(48, 57);

	default:
		// Handle unexpected input gracefully
		return '\0';  // Return a null character as a fallback
	}
}
#pragma endregion

#pragma region Problem 21 (2 Functions , Procedure)

string GenerateWord(enCharacterType charType, short Length)
{
	string word = "";
	for (int i = 0;  i < Length; i++)
	{
		word += GetCharacterRandom(charType);
	}
	return word;
}

string GenerateKey()
{
	string key = "";

	for (int i = 0; i < 4; i++)
	{
		key += GenerateWord(enCharacterType::CapitalLetter , 4);
		if (i < 3)
		{
			key += "-";
		} 
	}

	return key;
}

void PrintGenerateKeysFrom1ToN(short num) 
{
	for (int i = 1; i <= num; i++)
	{
		cout << "Key[" << i << "] : "<< GenerateKey() << endl;
	}
}
#pragma endregion

#pragma region Problem 22 (Functions , 2 Procedure)
void ReadArray(int arr[100] , int &arrLength)
{
	arrLength =  ReadPositiveNumber("Enter Number Of Elements: \n");

	PrintMessageOnScreen("\nEnter Array Elements: ");

	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}

int HowManyNumberCertainElementRepeated(int searchNum , int arr[100], int arrLength)
{
	short counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (searchNum == arr[i])
			counter++;
	}
	return counter;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
#pragma endregion

#pragma region Problem 23 (Procedure)
void FillArrayWithRandomNumbers(int arr[100] , int &arrLength , int startFromNum = 1 , int endToNum = 100)
{
	if (arrLength <= 0)
		arrLength = ReadPositiveNumber("Enter Number Of Elements: \n");

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(startFromNum, endToNum);
	}
}
#pragma endregion

#pragma region Problem 24 (Function)
int GetMaxNumberInArray(int arr[100]  , int arrLength)
{
	int max = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
#pragma endregion

#pragma region Problem 25 (Function)
int GetMinNumberInArray(int arr[100], int arrLength)
{
	int min = 2147483647;
	for (int i = 0; i < arrLength; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}
#pragma endregion

#pragma region Problem 26 (Function)
int SumArray(int arr[100], int arrLength)
{
	int sum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		sum += arr[i];
	}
	return sum;
}
#pragma endregion

#pragma region Problem 27 (Function)
float AverageArray(int arr[100], int arrLength)
{
	return (float)SumArray(arr, arrLength) / arrLength;
}
#pragma endregion

#pragma region Problem 28 (Procedure)
void CopyArray(int arrSource[100] , int arrDestination[100] , int arrLength )
{
		for (int i = 0; i < arrLength; i++)
		{
			arrDestination[i] = arrSource[i];
		}
}
#pragma endregion

#pragma region Problem 29 (Procedure)
void copyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength , int &arr2Length)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		
		if(CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
		{
			arrDestination[counter++] = arrSource[i];
		}
	}

	arr2Length = counter;
}
#pragma endregion

#pragma region Problem 30 (Procedure)
void SumOfTwoArrayElements(int firstArr[100], int SecondArr[100], int sumArr[100], int arrLength)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		sumArr[i] = firstArr[i] + SecondArr[i];
	}
}
#pragma endregion

#pragma region Problem 31 (2 Procedure)
void FillArrayWith1ToN(int arr[100] , int &arrLength)
{
	arrLength = ReadPositiveNumber("Enter Number Of Elements: \n");

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = i + 1;
	}
}

void ShuffleArray(int arr[100] , int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		int randNum1 = RandomNumber(1, arrLength-1),
		 randNum2 = RandomNumber(1, arrLength-1);

		Swap(arr[randNum1], arr[randNum2]);
	}
}

#pragma endregion

#pragma region Problem 32 (Procedure)
void CopyArrayInReverseOrder(int arrSource[100] , int arrDestination[100] , int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrDestination[i] = arrSource[arrLength - 1 - i];
	}
}
#pragma endregion

#pragma region Problem 33  (2 Procedure)
void FillArrayWithKeys(string arrSource[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrSource[i] = GenerateKey();
	}
}

void PrintStringArray(string arrSource[100] , int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array[" << i << "] : " << arrSource[i] << endl;
	}
}
#pragma endregion

#pragma region Problem 34 (Function)
int FindPositionNumber(int findNumber, int arrSource[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if(arrSource[i] == findNumber)
			return i;
	}
	return -1;
}
#pragma endregion

#pragma region Problem 35 (Function)
bool FindNumberInArray(int findNumber, int arrSource[100], int arrLength)
{
	return FindPositionNumber(findNumber, arrSource, arrLength) != -1;
}
#pragma endregion

#pragma region Problem 36 (2 Procedure)
void AddArrayElement(int number, int arrSource[100], int& arrLength)
{
	arrLength++;
	arrSource[arrLength - 1] = number;
}

void  InputUserNumbersInArray(int arr[100] , int& arrLength)
{
	short flag = 1;
	do
	{
		AddArrayElement(ReadNumber() , arr, arrLength );
		PrintMessageOnScreen("Do You Want To Add More Numbers ? [0]No, [1]Yes ?");
		cin >> flag;
	} while (flag == 1);
}
#pragma endregion

#pragma region Problem 37 (Procedure)
void CopyArrayUsingAddArrayElement(int arrSource[100] , int arrDestination[100] , int arrLength, int& arr2Length)
{
	for (int i = 0; i < arrLength; i++)
	{
		AddArrayElement(arrSource[i], arrDestination, arr2Length);
	}
}
#pragma endregion

#pragma region Problem 38 (Procedure)
void CopyOddNumbersToNewArray(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
	for (int i = 0; i < arrLength; i++)
	{
		if ((arrSource[i] % 2) != 0)
		{
			AddArrayElement(arrSource[i], arrDestination, arr2Length);
		}
	}
}
#pragma endregion

#pragma region Problem 39 (Procedure)
void CopyPrimeNumbersToNewArray(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
		{
			AddArrayElement(arrSource[i], arrDestination, arr2Length);
		}
	}
}
#pragma endregion

#pragma region Problem 40 (Procedure)
void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (!FindNumberInArray(arrSource[i], arrDestination, arr2Length))
		{
			AddArrayElement(arrSource[i], arrDestination, arr2Length);
		}
	}
}
#pragma endregion

#pragma region Problem 41 (Function)
bool IsPalindromeArray(int arr[100], int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		if (arr[i] != arr[length - i - 1])
		{
			return false;
		}
	}
	return true;
}
#pragma endregion

#pragma region Problem 42 (Function)
int OddCount(int arr[100], int arrLength)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if ((arr[i] % 2) != 0) {
			counter++;
		}
	}
	return counter;
}
#pragma endregion

#pragma region Problem 43 (Function)
int EvenCount(int arr[100], int arrLength)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if ((arr[i] % 2) == 0) {
			counter++;
		}
	}
	return counter;
}

#pragma endregion

#pragma region Problem 44 (Function)
int PositiveCount(int arr[100], int arrLength)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] > 0) {
			counter++;
		}
	}
	return counter;
}
#pragma endregion

#pragma region Problem 45 (Function)
int NegativeCount(int arr[100], int arrLength)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] <= 0) {
			counter++;
		}
	}
	return counter;
}
#pragma endregion

#pragma region Problem 46 (Function)
float MyAbs(float numNegative)
{
	return (numNegative > 0)? numNegative : numNegative * -1;
}
#pragma endregion

#pragma region Problem 47 (2 Function)
float GetFraction(float number)
{
	return number - (int)number;
}
int MyRound(float number)
{
	int intNumber = (int)number;

	if (abs(GetFraction(number)) >= .5)
	{
		if (intNumber > 0)
			++intNumber;
		else
			--intNumber;
	}
	return intNumber;
}
#pragma endregion

#pragma region Problem 48 (Function)
int MyFloor(float number)
{
	int intNum = (int)number;
	if (intNum < 0)
	{
		--intNum;
	}
	return intNum;
}
#pragma endregion

#pragma region Problem 49 (Function)
int MyCeil(float number)
{
	if (abs(GetFraction(number)) > 0)
	{
		if (number > 0)
			return (int)number + 1 ;
		else
			return (int)number;
	}
	return number;
}
#pragma endregion

#pragma region Problem 50 (Function)
int MySqrt(float number) 
{
	return pow(number , 0.5);
}
#pragma endregion



int main()
{
	srand((unsigned)time(NULL));
	#pragma region Problem 1 
	/* Write a program print the multiplication table from 1 to 10 as follows 
	example output:
			1	2	3	4	5	etc	10
	------------------------------------
	1	|	1	2	3	4	5	etc	10
	2	|	2	4	6	8	10	etc	20
	etc...
	*/
	
	/*PrintMultiplicationTable();*/

	#pragma endregion

	#pragma region Problem 2 
	/* Write a program print All Prime Numbers From 1 To N
	example Input: 10 => OutPut : 1, 2, 3, 5, 7
	*/

		//PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Enter Positive Number ?"));
	#pragma endregion

	#pragma region Problem 3
	/* Write a Program To check if the number is Perfect Or Not?
		note : Perfect Number = Sum (All Divisors) */
		
	//PrintNumberPerfectOrPerfect(ReadPositiveNumber("Please Enter Positive Number ?"));

	#pragma endregion

	#pragma region Problem 4
	/* Write a Program To Print All Perfect Numbers from 1 To N */

	//PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please Enter Positive Number ?"));

	#pragma endregion

	#pragma region Problem 5
	/* Write a Program To read a number and print it in a reverces order
	* 
		example input : 1234 
		output:
		4
		3
		2
		1 */

	//PrintReverseOfNumber(ReadPositiveNumber("Please Enter Positive Number ?"));

	#pragma endregion

	#pragma region Problem 6
	/* Write a Program To read a number and print the sum of its digits */

	//cout << "Sum Digits = " << SumOfDigits(ReadPositiveNumber("Please Enter Positive Number ?")) << endl;

	#pragma endregion

	#pragma region Problem 7
	/* Write a program to read a number and print it reversed
	example : input => 1234 output => 4321 */
	/*cout << "Reverse Number : " 
		<< reverseNumber(ReadPositiveNumber("Please Enter Positive Number ?")) 
		<< endl;*/
	#pragma endregion

	#pragma region Problem 8
	/* Write a program read a digit and a number, then print digit frequency in that number
	example : input: 1223222 , 2 output:Digit 2 Frequency is (5) Times */

	/*int number = ReadPositiveNumber("Enter Positive Number ?");
		short digit = ReadPositiveNumber("Enter Positive Digit ?");
	cout << "Digit " << digit 
		<< " Frequency is ( " << countDigitFrequency(number, digit) << " ) Times" 
		<< endl;*/
	#pragma endregion

	#pragma region Problem 9
	/* Write a program read a number , then print all digit frequency in that number
	example : input : 1223222
	output :
	Digit 1 Frequency is 1 Time
	Digit 2 Frequency is 5 Time
	Digit 3 Frequency is 1 Time*/
	//PrintAllDigitFrequency(ReadPositiveNumber("Enter Positive Number ?"));

	#pragma endregion

	#pragma region Problem 10
	/* Write a Program To read a number and print it in order from left to right

		example input : 1234
		output:
		1
		2
		3
		4 */
		//PrintNumberOrderFromLeftToRight(ReadPositiveNumber("Enter Positive Number ?"));
	#pragma endregion

	#pragma region Problem 11
		/* Write a Program To read a number and check if it is palindrome ?
		* palindrome is a number that reads the same from right to left
		* example : 
		input 1234	=>  output "No, it is Not a Palindrome Number"
		input 12321 =>  output "Yes, it is a Palindrome Number" */

		/*(IsPalindromeNumber(ReadPositiveNumber("Enter Positive Number ?"))) ?

			PrintMessageOnScreen("Yes, it is a Palindrome Number") :

			PrintMessageOnScreen("No, it is Not a Palindrome Number");*/
	#pragma endregion

	#pragma region Problem 12
	/* Write a program to read a number and print inverted pattern as follows ?

	* example : 
	------------------------
	input : 3 , input : 5
	------------------------
	output		output
	------------------------
	333			55555
	22			4444
	1			333
				22
				1
	*/	

	//PrintInvertedNumberPatternDesc(ReadPositiveNumber("Enter Positive Number ?"));
	#pragma endregion

	#pragma region Problem 13
	/* Write a program to read a number and print inverted pattern as follows ?

	* example :
	------------------------
	input : 3 , input : 5
	------------------------
	output		output
	------------------------
	1			1
	22			22
	333			333
				4444
				55555
	*/

	/*PrintInvertedNumberPatternAsc(ReadPositiveNumber("Enter Positive Number ?"));*/
	#pragma endregion

	#pragma region Problem 14
	/* Write a program to read a number and print inverted Letter pattern as follows ?

	* example :
	------------------------
	input : 3 , input : 5
	------------------------
	output		output
	------------------------
	CCC			EEEEE
	BB			DDDD
	A			CCC
				BB
				A
	*/

	//PrintInvertedLetterPatternDesc(ReadPositiveNumber("Enter Positive Number ?"));
	#pragma endregion

	#pragma region Problem 15
	/* Write a program to read a number and print inverted Letter pattern as follows ?

	* example :
	------------------------
	input : 3 , input : 5
	------------------------
	output		output
	------------------------
	A			A
	BB			BB
	CCC			CCC
				DDDD
				EEEEE
	*/

	//PrintInvertedLetterPatternAsc(ReadPositiveNumber("Enter Positive Number ?"));
	#pragma endregion

	#pragma region Problem 16
	/* Write a program to Print all Words From AAA To ZZZ ?

	* example : output
	* AAA
	* AAB
	* AAC
	* .
	* .
	* .
	* ZZZ
	*/

	//PrintAllWordsFromAAAToZZZ();
	#pragma endregion

	#pragma region Problem 17
	/* Write a program to guess a 3-Letter Password (All Capital)
	example : 
	input : AAF 
	output : 
	Trial [1] : AAA
	Trial [2] : AAB
	Trial [3] : AAC
	Trial [4] : AAD
	Trial [5] : AAE
	Trial [6] : AAF
	*/
	
	//GuessPassword(ReadString("Enter Password 3 Letter Password (All Capital) ?"));

	#pragma endregion

	#pragma region Problem 18
	/* Write a program to read a text and encrypt it , decrypt it
	example :
	input : Mohammed
	output : 
		Text Before Encryption : Mohammed
		Text After Encryption : Oqjcoogf
		Text After Decryption : Mohammed
	*/

		/*string originalText = ReadString("Please Enter The Text You Want To Encrypt ?"),
				encryptText = EncryptionText(originalText),
				decryptText = DecryptionText(encryptText);

		PrintMessageOnScreen("Text Before Encryption: " + originalText);
		PrintMessageOnScreen("Text After Encryption: " + encryptText);
		PrintMessageOnScreen("Text After Decryption: " + decryptText);*/


	#pragma endregion

	#pragma region Problem 19
	/* Write a program to print 3 random numbers from 1 to 10
	example :
	output : (Random)
		9
		5
		3
	*/
		/*
		cout << RandomNumber(1, 5) << endl;
		cout << RandomNumber(1, 5) << endl;
		cout << RandomNumber(1, 5) << endl;
		*/
	#pragma endregion

	#pragma region Problem 20
		/* Write a program to print random 
		small letter, capital letter, special character , and digiy in order
		example :
		output : (Random)
			i
			G
			$
			7
		*/
		/*cout << GetCharacterRandom(enCharacterType::SmallLetter) << endl;
		cout << GetCharacterRandom(enCharacterType::CapitalLetter) << endl;
		cout << GetCharacterRandom(enCharacterType::SpecialCharacter) << endl;
		cout << GetCharacterRandom(enCharacterType::DigitInOrder) << endl;*/

	#pragma endregion

	#pragma region Problem 21
	/* Write a program to read how many keys to generate and print them on the screen
	example :
		input : 5
		output :
			Key[1] : ETAI-HJUV-PEIP-CFRX
			Key[2] : UMCO-YSPQ-PHYK-STIL
			Key[3] : QBSR-MZEC-BYNA-DSYK
			Key[4] : MISQ-ULYB-ZRAZ-LMAG
			Key[5] : NACR-PPFJ-KZLF-ZHMT
	*/

	//PrintGenerateKeysFrom1ToN(ReadPositiveNumber("Enter How Many Keys Generate ?"));

	#pragma endregion

	#pragma region Problem 22
	/* Write a program to read N elements and store them in array then print all array elements 
		and ask for a number to check, 
		then print how many numbers a certain element repeated in that array 
		example :
		input : 5

		Enter array elements
			Element [1] : 1
			Element [2] : 1
			Element [3] : 1
			Element [4] : 2
			Element [5] : 3

			Enter The number you want to check : 1 

		Output :
			- Original array : 1 1 1 2 3
			- 1 Is Repeated 3 times
		*/

		/*int arrLength;

		int elements[100];

		ReadArray(elements, arrLength);

		cout << "\nOriginal Array : ";
		PrintArray(elements, arrLength);

		int numberCheck = ReadPositiveNumber("\nEnter The Number You Want To Check: ");

		int repeatedElement = HowManyNumberCertainElementRepeated(numberCheck , elements , arrLength);

		cout << "\nNumber " << numberCheck << " Is Repeated " << repeatedElement << " Times" << endl;*/

	#pragma endregion

	#pragma region Problem 23
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100
	example :
	input : 10 
	output : Array Elements : 65 55 10 17 80 95 25 35 45 66 */

	/*int arr[100], arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "Array Elements : ";
	PrintArray(arr, arrLength);*/
	#pragma endregion

	#pragma region Problem 24
		/* Write a program to fill array with max size 100 with random numbers from 1 to 100 , 
		then Print Max
		example :
		input : 10
		output : 
		Array Elements : 65 55 10 17 80 95 25 35 45 66
		Max Number IS : 80
		*/

		/*int arr[100], arrLength;
		FillArrayWithRandomNumbers(arr, arrLength);
		cout << "Array Elements : ";
		PrintArray(arr, arrLength);
		cout << "Max Number Is : " << GetMaxNumberInArray(arr , arrLength) << endl;*/
	
	#pragma endregion

	#pragma region Problem 25
		/* Write a program to fill array with max size 100 with random numbers from 1 to 100 ,
		then Print Min Number
		example :
		input : 10
		output :
		Array Elements : 65 55 10 17 80 95 25 35 45 66
		Min Number IS : 10
		*/

		/*int arr[100], arrLength;
		FillArrayWithRandomNumbers(arr, arrLength);
		cout << "Array Elements : ";
		PrintArray(arr, arrLength);
		cout << "Min Number Is : " << GetMinNumberInArray(arr, arrLength) << endl;*/

	#pragma endregion

	#pragma region Problem 26
			/* Write a program to fill array with max size 100 with random numbers from 1 to 100 ,
			then Print Sum  OF All Number
			example :
			input : 10
			output :
			Array Elements : 65 55 10 17 80 95 25 35 45 66
			Sum Of Number IS : 493
			*/

			/*int arr[100], arrLength = 0;
			FillArrayWithRandomNumbers(arr, arrLength);
			cout << "Array Elements : ";
			PrintArray(arr, arrLength);
			cout << "Sum Of Number IS : " << SumArray(arr, arrLength) << endl;*/

	#pragma endregion

	#pragma region Problem 27
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100 ,
	then Print Average Of All Number
	example :
	input : 10
	output :
	Array Elements : 65 55 10 17 80 95 25 35 45 66
	Sum Of Number IS : 49.3
	*/

		/*int arr[100], arrLength;
		FillArrayWithRandomNumbers(arr, arrLength);
		cout << "Array Elements : ";
		PrintArray(arr, arrLength);
		cout << "Average Of All Number IS : " << AverageArray(arr, arrLength) << endl;*/

	#pragma endregion

	#pragma region Problem 28
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100, 
		copy it to another array and print it  
		example :
		input : 10
		output : copy array
		Array 1 Elements : 65 55 10 17 80 95 25 35 45 66
		Array 2 Elements : 65 55 10 17 80 95 25 35 45 66
		*/

	/*int currentArr[100], newArr[100],  currentLength;

	FillArrayWithRandomNumbers(currentArr , currentLength);
	CopyArray(currentArr,  newArr, currentLength);

	PrintMessageOnScreen("\nArray 1 Elements:");
	PrintArray(currentArr, currentLength);

	PrintMessageOnScreen("\nArray 2 Elements:");
	PrintArray(newArr, currentLength);*/
	#pragma endregion

	#pragma region Problem 29
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		copy only prime numbers to another array and print 
		example :
		input : 10
		output : copy array
		Array 1 Elements : 42 68 35 1 70 25 79 59 63 65
		Prime Numbers In Array 2 : 1 79
		*/

	/*int currentArr[100], newArr[100] , currentLength;

	FillArrayWithRandomNumbers(currentArr , currentLength);

	PrintMessageOnScreen("\nArray 1 Elements:");
	PrintArray(currentArr, currentLength);

	int arr2Length = 0;
	copyOnlyPrimeNumbers(currentArr,  newArr, currentLength , arr2Length);

	PrintMessageOnScreen("\nPrime Numbers In Array 2 : ");
	PrintArray(newArr, arr2Length);*/
	#pragma endregion

	#pragma region Problem 30
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		Sum their elements in a third array and print the results
		example :
		input : 10 , 10
		output : 
			Array 1 Elements : 42 68 35 1 70 25 79 59 63 65
			Array 2 Elements : 6 46 82 28 62 92 96 43 28 37
			Sum Of array1 and array2 elements : 48	114 117 29 132 117 175 102 91 102 
	*/

	/*
	int firstArr[100], secondArr[100] ,newArr[100] , 
		arrLength = ReadPositiveNumber("Enter How Many Elements ?\n");

	FillArrayWithRandomNumbers(firstArr , arrLength);

	FillArrayWithRandomNumbers(secondArr , arrLength);

	SumOfTwoArrayElements(firstArr, secondArr, newArr, arrLength);

	PrintMessageOnScreen("\nArray 1 Elements:");
	PrintArray(firstArr, arrLength);

	PrintMessageOnScreen("\nArray 2 Elements:");
	PrintArray(secondArr, arrLength);

	PrintMessageOnScreen("\nSum Of array1 and array2 elements : ");
	PrintArray(newArr, arrLength);
	*/

	#pragma endregion

	#pragma region Problem 31
	/* Write a program to fill array with ordered numbers from 1 to N
	then print it, after that shuffle this array and print it after shuffle 
	example : 

	input : 10 

	output : 

		Array Elements Before Shuffle:
		1 2 3 4 5 6 7 8 9 10

		Array Elements after shuffle:
		2 4 6 8 10 1 3 5 7 9 */

		/*int arr[100], arrLength = 0;

		FillArrayWith1ToN(arr, arrLength);

		PrintMessageOnScreen("\nArray Elements Before Shuffle : ");
		PrintArray(arr, arrLength);

		ShuffleArray(arr, arrLength);

		PrintMessageOnScreen("\nArray Elements After Shuffle : ");
		PrintArray(arr, arrLength);*/

	#pragma endregion

	#pragma region Problem 32
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		copy iy to another array in reverse order and print it
		example :
		input : 10
		output :
			Array 1 Elements : 
			42 68 35 1 70 25 79 59 63 65

			Array 2 Elements after Copying array 1 in reversed order : 
			65 63 59 79 25 70 1 35 68 42
	*/

		
	/*int arrsourse[100], arrDestination[100] ,
		arrLength = ReadPositiveNumber("Enter How Many Elements ?\n");

	FillArrayWithRandomNumbers(arrsourse, arrLength);

	CopyArrayInReverseOrder(arrsourse , arrDestination , arrLength);

	PrintMessageOnScreen("\nArray 1 Elements:");
	PrintArray(arrsourse, arrLength);

	PrintMessageOnScreen("\nArray 2 Elements after Copying array 1 in reversed order :");
		PrintArray(arrDestination, arrLength);*/
		

	#pragma endregion

	#pragma region Problem 33
	/* Write a Program to read how many keys to generate and 
	fill them in array then print them on the screen 
	example :
		input : 5
		output :
			Array[0] : ETAI-HJUV-PEIP-CFRX
			Array[1] : UMCO-YSPQ-PHYK-STIL
			Array[2] : QBSR-MZEC-BYNA-DSYK
			Array[3] : MISQ-ULYB-ZRAZ-LMAG
			Array[4] : NACR-PPFJ-KZLF-ZHMT
	*/

	/*string arrSource[100];
	int arrLength = 0;
	arrLength = ReadPositiveNumber("How Many Keys Do You WWant To Generate ?: \n");
	FillArrayWithKeys(arrSource,  arrLength);

	PrintMessageOnScreen("\nArray Elements: ");
	PrintStringArray(arrSource ,arrLength);*/

	#pragma endregion

	#pragma region Problem 34
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		read number and return its index array if found otherwise return -1 .
	example :
	input : 10
	output :
		Array 1 Elements :
		42 68 35 1 70 25 79 59 63 65

		Please Enter a Number To Search For ?
		65

		Number You Are Looking For Is	: 65
		The Number Found at Position	: 9
		The Number Found Its Order		: 10 

	Otherwise:
		Please Enter a Number To Search For ?
		111

		Number You Are Looking For Is	: 111
		The Number Is Not Found :-( 
	*/

	/*int arrSource[100],  arrlength = 0 , findNumber;

	FillArrayWithRandomNumbers(arrSource , arrlength);

	PrintMessageOnScreen("\nArray 1 Elements :");
	PrintArray(arrSource , arrlength);

	findNumber = ReadPositiveNumber("\nPlease Enter a Number To Search For ?");

	cout << "Number You Are Looking For Is: " << findNumber << endl;

	int positionNumber = FindPositionNumber(findNumber, arrSource ,arrlength);

	if (positionNumber != -1)
	{
		cout << "The Number Found at Position : " << positionNumber << endl;
		cout << "The Number Found Its Order : " << positionNumber + 1 << endl;
	}
	else
	{
		cout << "The Number Is Not Found :-( " << endl;
	}*/
	#pragma endregion

	#pragma region Problem 35
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		read number and print if its found or not (reuse code in preve problem) .
	example :
	input : 10
	output :
		Array 1 Elements :
		42 68 35 1 70 25 79 59 63 65

		Please Enter a Number To Search For ?
		65

		Number You Are Looking For Is	: 65
		Yes, The Number Is Found :-) 

	Otherwise:
		Please Enter a Number To Search For ?
		111

		Number You Are Looking For Is	: 111
		The Number Is Not Found :-(
	*/

	/*int arrSource[100],  arrlength = 0;

	FillArrayWithRandomNumbers(arrSource , arrlength);

	PrintMessageOnScreen("\nArray 1 Elements :");
	PrintArray(arrSource , arrlength);

	int findNumber = ReadPositiveNumber("\nPlease Enter a Number To Search For ?");

	bool isFound = FindNumberInArray(findNumber, arrSource ,arrlength);

	cout << "\nNumber You Are Looking For Is: " << findNumber << endl;

	if (isFound)
		PrintMessageOnScreen("Yes, The Number Is Found :-)");

	else
		PrintMessageOnScreen("No ,The Number Is Not Found :-(");*/
	#pragma endregion

	#pragma region Problem 36
	/* Write a program to dynamically read numbers and save in an array max size of array is 100 
	allocate simi-dynamic array length 
	example:
	output :
		Please enter a number ? 10 
		Do you want to add more numbers ? [0]No , [1]Yes ? 1

		Please enter a number ? 20
		Do you want to add more numbers ? [0]No , [1]Yes ? 1

		Please enter a number ? 30
		Do you want to add more numbers ? [0]No , [1]Yes ? 0

		Array Length : 3
		Array Elements : 10 20 30
	*/

	/*int arrSource[100], arrLength = 0;

	InputUserNumbersInArray(arrSource, arrLength);

	cout << "\nArray Length : " << arrLength << endl;

	cout << "\nArray Elements : ";

	PrintArray(arrSource , arrLength);*/
	#pragma endregion

	#pragma region Problem 37
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		copy it to another array using AddArrayElement() , and print it 
		example :
		input : 10
		output : using Function AddArrayElement()
		Array 1 Elements : 65 55 10 17 80 95 25 35 45 66
		Array 2 Elements : 65 55 10 17 80 95 25 35 45 66 */

	/*int arrSource[100], arrLength = 0;

	FillArrayWithRandomNumbers(arrSource, arrLength);

	PrintMessageOnScreen("\nArray 1 Elements");
	PrintArray(arrSource, arrLength);

	int arrDestination[100] , arr2Length = 0;

	CopyArrayUsingAddArrayElement(arrSource, arrDestination, arrLength , arr2Length);

	PrintMessageOnScreen("\nArray 2 Elements");
	PrintArray(arrDestination, arr2Length);*/
	#pragma endregion

	#pragma region Problem 38
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		copy only odd numbers to another array using AddArrayElement() , and print it
		example :
		input : 10
		output : using Function AddArrayElement()
		Array 1 Elements : 59 14 84 36 6 51 48 91 96 67
		Array 2 Odd Numbers : 59 51 91 67 */

	/*int arrSource[100], arrLength = 0;

	FillArrayWithRandomNumbers(arrSource, arrLength);

	PrintMessageOnScreen("\nArray 1 Elements");
	PrintArray(arrSource, arrLength);

	int arrDestination[100] , arr2Length = 0;

	CopyOddNumbersToNewArray(arrSource, arrDestination, arrLength , arr2Length);

	PrintMessageOnScreen("\nArray 2 Odd Numbers");
	PrintArray(arrDestination, arr2Length);*/
	#pragma endregion

	#pragma region Problem 39
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		copy only prime numbers to another array using AddArrayElement() , and print it
		example :
		input : 10
		output : using Function AddArrayElement()
		Array 1 Elements : 61 100 32 75 81 95 50 98 13 70
		Array 2 Prime Numbers : 61 13 */

	/*int arrSource[100] , arrLength = 0;

	FillArrayWithRandomNumbers(arrSource, arrLength);

	PrintMessageOnScreen("\nArray 1 Elements");
	PrintArray(arrSource, arrLength);

	int arrDestination[100] , arr2Length = 0;

	CopyPrimeNumbersToNewArray(arrSource, arrDestination, arrLength , arr2Length);

	PrintMessageOnScreen("\nArray 2 Prime Numbers: ");
	PrintArray(arrDestination, arr2Length);*/
	#pragma endregion

	#pragma region Problem 40
	/* Write a program to fill array with numbers, 
		then print distinct numbers to another array 
	example :
	Input : 10
	Output : using Function AddArrayElement()
		Array 1 Elements : 10, 10, 10, 50, 50, 70, 70, 70, 70, 90
		Array 2 Distinct Elements : 10 50 70 90 */

	/*int arrSource[100] = { 10, 10, 10, 50, 50, 70, 70, 70, 70, 90 } ,  arrLength = 10, 
		arrDistinct[100], arr2Length = 0;

	PrintMessageOnScreen("Array 1 Elements:");
	PrintArray(arrSource , arrLength);

	CopyDistinctNumbersToArray(arrSource  , arrDistinct , arrLength , arr2Length);

	PrintMessageOnScreen("Array 2 Distinct Elements:");
	PrintArray(arrDistinct, arr2Length); */
	#pragma endregion

	#pragma region Problem 41
	/* Write a program to fill array with numbers , then check if it is palindrome array or not , note:
	palindrome array can be read the same from right to left and from left to right 
	example:
	input: 
		10 20 30 30 20 10
	output:
		Array Elements: 
		10 20 30 30 20 10

		Yes array is palindrome
	*/

	/*int arr[100] = { 10,20,30,30,20,10 }, arrLength = 6;

	if (IsPalindromeArray(arr, arrLength))
	{

		PrintMessageOnScreen("Yes Array Is Palindrome");
	}
	else
	{
		PrintMessageOnScreen("No Array Is Not Palindrome");
	}*/

	#pragma endregion

	#pragma region Problem 42
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		then print the count of odd numbers
		example :
			input : 10
			output : 
			Array Elements : 60 78 15 49 56 6 4 3 21 23
			Odd Numbers Count Is : 5 
	*/

	/*int arr[100] , arrLength = 0;

	FillArrayWithRandomNumbers(arr, arrLength);

	PrintMessageOnScreen("\nArray Elements: ");
	PrintArray(arr  , arrLength);

	int countOddNumbers = OddCount(arr , arrLength);
	cout << "Odd Numbers Count Is : " << countOddNumbers << endl;*/
	#pragma endregion

	#pragma region Problem 43
	/* Write a program to fill array with max size 100 with random numbers from 1 to 100,
		then print the count of odd numbers
		example :
			input : 10
			output :
			Array Elements : 60 78 15 49 56 6 4 3 21 23
			Even Numbers Count Is :  5
	*/

	/*int arr[100], arrLength = 0;

	FillArrayWithRandomNumbers(arr, arrLength);

	PrintMessageOnScreen("\nArray Elements: ");
	PrintArray(arr  , arrLength);

	int countEvenNumbers = EvenCount(arr , arrLength);
	cout << "Even Numbers Count Is : " << countEvenNumbers << endl;*/
	#pragma endregion

	#pragma region Problem 44
	/* Write a program to fill array with max size 100 with random numbers from -100 to 100
	then print the count of positive numbers
	example :
		input :
		17 -9 -9 -90 -72 -100 -4 60 -84 -15
		Output :
		Positive Numbers Count Is : 2
	*/

	/*int arr[100], arrLength = 0;

	FillArrayWithRandomNumbers(arr, arrLength, -100, 100);

	PrintMessageOnScreen("\nArray Elements: ");
	PrintArray(arr  , arrLength);

	int countPositiveNumbers = PositiveCount(arr , arrLength);
	cout << "Positive Numbers Count Is : " << countPositiveNumbers << endl;*/
	#pragma endregion

	#pragma region Problem 45
	/* Write a program to fill array with max size 100 with random numbers from -100 to 100
	then print the count of positive numbers
	example :
		input :
		17 -9 -9 -90 -72 -100 -4 60 -84 -15
		Output :
		Negative Numbers Count Is : 8
	*/

	/*int arr[100], arrLength = 0;

	FillArrayWithRandomNumbers(arr, arrLength, -100, 100);

	PrintMessageOnScreen("\nArray Elements: ");
	PrintArray(arr  , arrLength);

	int countNegativeNumbers = NegativeCount(arr , arrLength);
	cout << "Negative Numbers Count Is : " << countNegativeNumbers << endl;*/
	#pragma endregion

	#pragma region Problem 46
	/* Write a program to print abs of numbers, dont use built in abs function 
	* example:
	* input : -10
	* output : 
		* My abs Result : 10
		* C++ abs Result : 10
	*/

	/*float inputNum = ReadNumberFloat();

	cout << "My abs Result :" << MyAbs(inputNum) << endl;

	cout <<"C++ abs Result : " << abs(inputNum)  << endl;*/

	#pragma endregion

	#pragma region Problem 47
	/* Write a program to print round of numbers, dont use built in round function
	* example:
	* input : 10.7				|	10.3				|	-10.7
	* output :
	* --------------------------------------------------------------------------
		* My round Result : 11	| My round Result : 10	| My round Result : -11
		* C++ round Result : 11	| C++ round Result : 10	| C++ round Result : -11
	*/

	/*float inputNum = ReadNumberFloat();

	cout << "My round Result :" << MyRound(inputNum) << endl;

	cout <<"C++ round Result : " << round(inputNum)  << endl;*/

	#pragma endregion

	#pragma region Problem 48
	/* Write a program to print floor of numbers, dont use built in floor function
	* example:
	* input : 10.7				|	10.3				|	-10.3
	* output :
	* ---------------------------------------------------------------------------
		* My Floor Result : 10	| My Floor Result : 10	| My Floor Result : -11
		* C++ Floor Result : 10	| C++ Floor Result : 10	| C++ Floor Result : -11
	*/

	/*float inputNum = ReadNumberFloat();

	cout << "My Floor Result :" << MyFloor(inputNum) << endl;

	cout <<"C++ Floor Result : " << floor(inputNum)  << endl;*/

	#pragma endregion

	#pragma region Problem 49
	/* Write a program to print ceil of numbers, dont use built in ceil function
	* example:
	* input : 10.7				|		-10.7
	* output :
	* ---------------------------------------------------
		* My ceil Result : 11	|  My ceil Result : -10
		* C++ ceil Result : 11	|  C++ ceil Result : -10
	*/

	/*float inputNum = ReadNumberFloat();

	cout << "My Ceil Result :" << MyCeil(inputNum) << endl;

	cout << "C++ Ceil Result : " << ceil(inputNum) << endl;*/

	#pragma endregion

	
	#pragma region Problem 50
	/* Write a program to print sqrt of numbers, dont use built in sqrt function
	* example:
	* input : 25			
	* output :
	* --------------------------
		* My sqrt Result : 5	
		* C++ sqrt Result : 5	
	*/

	/*float inputNum = ReadNumberFloat();
	cout << "My Sqrt Result :" << MySqrt(inputNum) << endl;

	cout << "C++ Sqrt Result : " << sqrt(inputNum) << endl;*/
	#pragma endregion



} 