#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "recordClients.txt";

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
	getline(cin >> ws, str);
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

float ReadNumberFloat(string msg)
{
	float number;
	PrintMessageOnScreen(msg);
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

#pragma region Problem 30 && 31 (Function)
short HowManyRecurringcharacters(string str , char findLetter , bool matchCase = true)
{
	short counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (matchCase)
		{
			if (str[i] == findLetter)
				counter++;
		}
		else
		{
			if (toupper(findLetter) == str[i] || tolower(findLetter) == str[i])
				counter++;
		}
	}
	return counter;
}
#pragma endregion

#pragma region Problem 32 (enum , Function)
enum enVowels { a = 97 , e = 101 , i = 105 , o = 111 ,u = 117 };

bool IsVowel(char letter)
{
	letter = tolower(letter);
	return (letter == static_cast<char>(enVowels::a) ||
		letter == static_cast<char>(enVowels::e) ||
		letter == static_cast<char>(enVowels::i) ||
		letter == static_cast<char>(enVowels::o) ||
		letter == static_cast<char>(enVowels::u));
}
#pragma endregion

#pragma region Problem 33 (Function)

short CountVowels(string str)
{
	short counter = 0;
	for (char &letter : str)
	{
		if (IsVowel(letter))
		{
			counter++;
		}
	}
	return counter;
}
#pragma endregion

#pragma region Problem 34 (Procedure)

void PrintAllVowels(string str)
{
	short counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (IsVowel(str[i]))
		{
			cout << str[i] << setw(4);
		}
	}
}
#pragma endregion

#pragma region Problem 35 (Procedure)
void PrintEachWordInString(string str , string delimter)
{
	size_t position = 0;
	string word;

	while ((position = str.find(delimter)) != string::npos)
	{
		word = str.substr(0 , position);

		if (!word.empty())
		{
			cout << word << endl;
		}
		str.erase(0, position + delimter.length());
	}

	if (!str.empty())
	{
		cout << str << endl;
	}
}
#pragma endregion

#pragma region Problem 36 (Function)
short CountEachWordInString(string str, string delimter)
{
	size_t position = 0;
	short counter = 0;
	string word;

	while ((position = str.find(delimter)) != string::npos)
	{
		word = str.substr(0, position);

		if (!word.empty())
		{
			counter++;
		}
		str.erase(0, position + delimter.length());
	}

	if (!str.empty())
	{
		counter++;
	}

	return counter;
}
#pragma endregion

#pragma region Problem 37 (Function)
vector<string> SplitEachWordInVector(string str , string delimter)
{
	size_t position = 0;
	string word;
	vector<string> vWords;

	while ((position = str.find(delimter)) != string::npos)
	{
		word = str.substr(0 , position);

		if (!word.empty())
		{
			vWords.push_back(word);
		}

		str.erase(0, position + delimter.length());
	}

	if (!str.empty())
	{
		vWords.push_back(str);
	}
	return vWords;
}

void PrintWordFromTheVector(vector<string> &vWords)
{
	cout << "\nTokens = " << vWords.size() << endl;
	for (string& word : vWords)
	{
		cout << word << endl;
	}
}
#pragma endregion

#pragma region Problem 38 (3 Function)
string TrimRightString(string str) 
{
	for (size_t i = str.length() - 1; i > 0 ; i--)
	{
		if (str[i] != ' ')
		{
			return str.substr(0 , i + 1);
		}
	}
	return str;
}

string TrimLeftString(string str)
{
	for (size_t i = 0 ; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			return str.substr(i, str.length() - 1);
		}
	}
	return "";
}

string TrimString(string str)
{
	return TrimRightString(TrimLeftString(str));
}
#pragma endregion

#pragma region Problem 39 (Function)
string JoinString(vector<string> vWord ,string delimter)
{
	string str = "";
	for (short i = 0; i < vWord.size(); i++)
	{
		str += vWord[i];
		str += (i != vWord.size() - 1) ? delimter : "";
	}
	return str;
}
#pragma endregion

#pragma region Problem 40 (Function)
string JoinString(string arr[], short arrLength ,string delimter)
{
	string str = "";
	for (short i = 0; i < arrLength; i++)
	{
		str += arr[i];
		str += (i != arrLength - 1) ? delimter : "";
	}
	return str;
}
#pragma endregion

#pragma region Problem 41 (Function)
//string ReverseWords(string str)
//{
//	vector <string> vWords = SplitEachWordInVector(str, " ");
//	string result = "";
//
//	for (int i = vWords.size() - 1; i >= 0; i--)
//	{
//		result += vWords[i];
//		result += (i != 0) ? " " :"";
//	}
//	return result;
//}
string ReverseWords(string str)
{
	vector <string> vWords = SplitEachWordInVector(str, " ");
	string result = "";
	vector <string>::iterator iter = vWords.end();
	while (iter != vWords.begin())
	{
		--iter;
		result += *iter;

		if (iter != vWords.begin()) 
			result += " ";
	}
	return result;
}
#pragma endregion

#pragma region Problem 42 && 43 (2 Function)
string ReplaceStringBuiltInFunction(string str, string stringToReplace, string replaseTo)
{
	size_t pos = str.find(stringToReplace);

	while (pos != string::npos)
	{
		str = str.replace(pos, stringToReplace.length(), replaseTo);
		pos = str.find(stringToReplace);
	}

	return str;
}

string ReplaceString(string str, string stringToReplace, string replaseTo, bool matchCase = true)
{
	vector <string> vWords = SplitEachWordInVector(str, " ");

	for (string& word : vWords)
	{
		if (matchCase)
		{
			if (stringToReplace == word)
			{
				word = replaseTo;
			}
		}
		else {
			if (LowerAllLetters(stringToReplace) == LowerAllLetters(word))
			{
				word = replaseTo;
			}
		}
	}
	return JoinString(vWords, " ");
}
#pragma endregion

#pragma region Problem 44 (2 Function)
bool IsPunctuation(char Punc)
{
	switch (Punc)
	{
	case '?':return true; 
	case '}':return true;
	case '{':return true;
	case ',':return true;
	case '.':return true;
	case '-':return true;
	case '_':return true;
	case ']':return true;
	case '[':return true;
	case '(':return true;
	case ')':return true;
	case '!':return true;
	case ';':return true;
	case ':':return true;
	case '`':return true;
	}
	return false;
}

string RemovePunctuationFromString(string str)
{
	string result = "";
	for (short i = 0; i < str.length(); i++)
	{
		if (!IsPunctuation(str[i]))
		{
			result += str[i];
		}
	}
	return result;
}
#pragma endregion

#pragma region Problem 45 (struct , 2 Functions)
struct stClientData 
{
	string accountNumber = "", name = "", pinCode="", phone = "";
	float accountBalance = 0.00;
	bool markForDelete = false;
};

stClientData ReadNewClient()
{
	stClientData client;
	client.accountNumber = ReadString("Enter Account Number ?");
	client.pinCode = ReadString("Enter Pin Code ?");
	client.name = ReadString("Enter Your Name ?");
	client.phone = ReadString("Enter Phone Number ?");
	client.accountBalance = ReadNumberFloat("Enter Account Balance ?");
	return client;
}

string convertRecordToLine(stClientData clientData , string seperator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += clientData.accountNumber + seperator;
	stClientRecord += clientData.pinCode + seperator;
	stClientRecord += clientData.name + seperator;
	stClientRecord += clientData.phone + seperator;
	stClientRecord += to_string( clientData.accountBalance);
	return  stClientRecord;
}
#pragma endregion

#pragma region Problem 46 (Function , Procedure)
/*  
	Another solution :
		If modifying the input string is acceptable and memory efficiency 
			is a priority, Function 1 is a better choice.

	string subStringWord(string &str , string seperator = "#//#")
	{
		size_t position;
		string word = "";
		if ((position = str.find(seperator)) != string::npos)
		{
			word = str.substr(0, position);
			str.erase(0 , position + seperator.length());
			return word;
		}
		return str;
	}

	stClientData convertLineDataToRecord(string str)
	{
		stClientData client;
		client.accountNumber = subStringWord(str);
		client.pinCode = subStringWord(str);
		client.name = subStringWord(str);
		client.phone = subStringWord(str);
		client.accountBalance = std::stof(subStringWord(str));

		return client;
	}
*/

stClientData convertLineDataToRecord(string str, string seperator = "#//#")
{
	stClientData client;
	vector <string> vClientData = SplitEachWordInVector(str , seperator);

	client.accountNumber = vClientData[0];
	client.pinCode = vClientData[1];
	client.name = vClientData[2];
	client.phone = vClientData[3];
	client.accountBalance = std::stof(vClientData[4]);

	return client;
}

void printClientRecord(stClientData client)
{
	cout << "\nThe following is the extracted client record :\n\n";
		
	cout << "Account Number	:	" << client.accountNumber << endl;
	cout << "PinCode		:	" << client.pinCode << endl;
	cout << "Name		:	" << client.name << endl;
	cout << "Phone		:	" << client.phone << endl;
	cout << "Account Balance	:	" << client.accountBalance << endl;

}
#pragma endregion

#pragma region Problem 47 (3 Procedure)
void SaveRecordLineToFile(string fileName, string record)
{
	fstream myFile;
	myFile.open(fileName, ios::out | ios::app);

	if (myFile.is_open())
	{
		myFile << record << endl;
		myFile.close();
	}

}

void AddNewClient()
{
	stClientData client;
	string line = "";
	client = ReadNewClient();
	line = convertRecordToLine(client);
	SaveRecordLineToFile(ClientsFileName, line);
}

void AddClients()
{
	char againNewClient;
	
	do
	{
		system("cls");
		cout << "\nAdding New Client:\n\n";

		AddNewClient();
		
		cout << "Client Added Successfully, Do You Want To Add More Clients ? Y/N ?";
		cin >> againNewClient;

	} while (againNewClient == 'y' || againNewClient == 'Y');
}


#pragma endregion

#pragma region Problem 48 (2 Procedure , Function)
vector<stClientData> LoadClientsDataFromFile(string fileName)
{
	vector<stClientData> vClients;
	fstream myFile;
	
	myFile.open(fileName , ios::in);

	if (myFile.is_open())
	{
		string line = "";
		stClientData client;
		
		while (getline(myFile , line))
		{
			client = convertLineDataToRecord(line);
			vClients.push_back(client);
		}
		myFile.close();
	}
	return vClients;
}

void PrintClientRecordDetails(stClientData client)
{
	cout << "The following is the extracted client Details :\n\n"
		<< "-Account Number :" << client.accountNumber << "\n"
		<< "- PinCode :" << client.pinCode << "\n"
		<< "- Name :" << client.name << "\n"
		<< "- Phone :" << client.phone << "\n"
		<< "- Account Balance :" << client.accountBalance << "\n\n";
}
void PrintClientRecord(stClientData client)
{
	cout << "| " << setw(15) << left << client.accountNumber;
	cout << "| " << setw(10) << left << client.pinCode;
	cout << "| " << setw(40) << left << client.name;
	cout << "| " << setw(12) << left << client.phone;
	cout << "| " << setw(12) << left << client.accountBalance;
}

void PrintShowAllClient(vector<stClientData> vClients)
{
	cout << "\n\t\t\t\t\tClinet List (" << vClients.size() << ") Client(s)";
	cout << "\n-------------------------------------------------";
	cout << "-------------------------------------------------\n" << endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n-------------------------------------------------";
	cout << "-------------------------------------------------\n" << endl;

	for (stClientData &client : vClients)
	{
		PrintClientRecord(client);
		cout << endl;
	}
	cout << "\n-------------------------------------------------";
	cout << "-------------------------------------------------\n" << endl;
}

#pragma endregion

#pragma region Problem 49 (Function)
bool FindClientByAccountNumber(string accountNumber , vector<stClientData> vClients,stClientData& client)
{
	for (stClientData &c : vClients)
	{
		if (c.accountNumber == accountNumber)
		{
			client = c;
			return true;
		}
	}
	return false;
}
#pragma endregion

#pragma region Problem 50 (3 Functions)
bool markClientForDeleteByAccountNumber(string accountNumber , vector<stClientData>& vClients)
{
	for (stClientData &client : vClients)
	{
		if (accountNumber == client.accountNumber)
		{
			client.markForDelete = true;	
			return true;
		}
	}
	return false;
}

vector<stClientData> saveClientsDataToFile(string FileName , vector<stClientData> vClients)
{
	fstream myFile;
	string dataLine;

	myFile.open(ClientsFileName, ios::out);

	if (myFile.is_open())
	{
		for (stClientData& c : vClients)
		{
			if (c.markForDelete == false)
			{
				dataLine = convertRecordToLine(c);

				myFile << dataLine << endl;

			}
		}
		myFile.close();
	}
	return vClients;
}

bool DeleteClientByAccountNumber(string accountNumber , vector<stClientData> &vClients )
{
	stClientData client;
	char answer = 'n';
	if (FindClientByAccountNumber(accountNumber, vClients, client))
	{
		PrintClientRecordDetails(client);

		cout << "\n\nAre You Sure You Want Delete This Client ? y/n ?";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			markClientForDeleteByAccountNumber(accountNumber , vClients);
			saveClientsDataToFile(ClientsFileName , vClients);

			vClients = LoadClientsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	cout << "\nClient With Account Number (" << accountNumber << ") Is Not Found\n";
	return false;
	
}
#pragma endregion

#pragma region Problem 51 (2 Functions)
stClientData changeClientRecord(string accountNumber)
{
	stClientData client;
	client.accountNumber = accountNumber;

	client.pinCode = ReadString("Enter Pin Code ?");
	client.name = ReadString("Enter Your Name ?");
	client.phone = ReadString("Enter Phone Number ?");
	client.accountBalance = ReadNumberFloat("Enter Account Balance ?");

	return client;
}

bool UpdateClientByAccountNumber(string accountNumber, vector<stClientData>& VClients)
{
	stClientData client;
	char answer = 'n';

	if (FindClientByAccountNumber(accountNumber , VClients , client))
	{
		PrintClientRecordDetails(client);
		cout << "\n\nAre You Sure You Want Update This Client ? y/n ?";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			for (stClientData &C : VClients)
			{
				if (accountNumber == C.accountNumber)
				{
					C = changeClientRecord(accountNumber);
					break;
				}
			}

			saveClientsDataToFile(ClientsFileName , VClients);
			cout << "\n\nClient Updated Successfully\n";
			return true;
		}
	}
	cout << "\nClient With Account Number (" << accountNumber << ") Not Found\n";
	return false;
}
#pragma endregion


int main()
{
	srand((unsigned)time(NULL));

#pragma region Problem 1
/* 
	Write a program to fill a 3X3 matrix with random numbers.
		example :
			The following is a 3X3 random matrix:
			16	45	30
			25	51	3	
			24	19	100
*/

/*
	int matrix[3][3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);
	PrintMatrix(matrix ,3, 3);
*/
#pragma endregion

#pragma region Problem 2
/* 
	Write a program to fill a 3X3 matrix with random 
	numbers then print each row sum:
	example:
		the following a 3X3 random matrix:
		53	43	6
		65	83	48
		64	30	30
		the following are the sum of each row in the matrix:
		row 1 sum = 102
		row 2 sum = 196
		row 3 sum = 130
*/

/*
	int matrix[3][3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);

	cout << "The Following is a 3X3 random matrix\n";
	PrintMatrix(matrix ,3, 3);

	cout << "\nThe Following are the sum of each row in the matrix:\n";
	PrintEachRowSum(matrix);
*/

#pragma endregion

#pragma region Problem 3
/* 
	Write a program to fill a 3X3 matrix with random numbers 
	then sum each row in separate array and print the result
	example :
		53 43	6
		65	83	48
		64	30	36
		the following are the sum of each row in the matrix:
		row 1 sum = 102
		row 2 sum = 196
		row 3 sum = 130
*/

/*
	int matrix[3][3];
	int arr[3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);

	cout << "The Following is a 3X3 random matrix\n";
	PrintMatrix(matrix ,3, 3);

	SumMatrixRowsInArray(matrix , arr);
	cout << "\nThe Following are the sum of each row in the One Dimension Array:\n";
	PrintRowsSumInArray(arr);
*/

#pragma endregion

#pragma region Problem 4
/* 
	Write a program to fill a 3X3 matrix with random numbers 
	then print each col sum.
	example:
	the following is a 3X3 random matrix:
		5	1	87
		46	12	2
		87	2	68
	the following are the sum of each col in the matrix:
		col 1 sum = 138
		col 2 sum = 15
		col 3 sum = 157
*/

/*
	int matrix[3][3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);

	cout << "The Following is a 3X3 random matrix\n";
	PrintMatrix(matrix ,3, 3);

	cout << "\nThe Following are the sum of each columns in the Matrix:\n";
	PrintEachColumnsSum(matrix);
*/

#pragma endregion

#pragma region Problem 5
/* 
	Write a program to fill a 3X3 matrix with random numbers 
	then sum each col in another array and print them:
	example:
	the following ia a 3X3 matrix:
		5	1	87
		46	12	2
		87	2	68
	the following are the sum of each col in the matrix:
		col 1 sum = 138
		col 2 sum = 15
		col 3 sum = 157
*/

/*
	int matrix[3][3];
	int arr[3];
	FillMatrixWithRandomNumbers(matrix , 1 , 100);

	cout << "The Following is a 3X3 random matrix\n";
	PrintMatrix(matrix ,3, 3);

	SumMatrixColumnsInArray(matrix , arr);

	cout << "\nThe Following are the sum of each columns in the Array:\n";
	PrintColumnsSumInArray(arr);
*/

#pragma endregion

#pragma region Problem 6
/* 
	Write a program to fill a 3X3 matrix with ordered numbers .
	example :
	the following ia a 3X3 ordered matrix:
		1	2	3
		4	5	6
		7	8	9
*/

/*
	int matrix[3][3];
	FillMatrixWithOrderedNumbers(matrix);

	cout << "The Following is a 3X3 Matrix With Ordered Numbers:\n";
	PrintMatrix(matrix ,3, 3);
*/

#pragma endregion

#pragma region Problem 7
/* 
	Write a program to fill a 3X3 matrix with ordered numbers and print
	it , then transpose matrix and print it.
	example :
		the followwing is a 3X3 ordered matrix:
		1	2	3
		4	5	6
		7	8	9
		the following is the transposed matrix:
		1	4	7
		2	5	8
		3	6	9
*/

/*
	int matrix[3][3] , matrixTransposed[3][3];
	FillMatrixWithOrderedNumbers(matrix);

	cout << "The Following is a 3X3 Matrix With Ordered Numbers:\n";
	PrintMatrix(matrix ,3, 3);

	TransposeMatrix(matrix , matrixTransposed);

	cout << "\nThe Following is the transpose matrix:\n";
	PrintMatrix(matrixTransposed ,3, 3);
*/

#pragma endregion

#pragma region Problem 8
/* 
Write a program to fill a 3X3 matrix with random numbers and them
	then multiply them into a 3rd matrix and print it.
	example :
		matrix1:
			08	07	07
			01	06	10
			10	01	09
		matrix2:
			04	05	06
			04	05	08
			06	08	01
		results:
			32	35	42
			04	30	80
			60	08	09
*/

/*
	int matrix[3][3] , matrix2[3][3] , resultMatrix[3][3];

	FillMatrixWithRandomNumbers(matrix , 1 , 10);

	FillMatrixWithRandomNumbers(matrix2 , 1 , 10);

	MultiplyTwoMatrix(matrix , matrix2 , resultMatrix);

	cout << "Matrix (1):\n";
	PrintMatrix(matrix ,3, 3);

	cout << "\nMatrix (2):\n";
	PrintMatrix(matrix2 ,3, 3);

	cout << "\nResult: Multiply Two Matrix ( Matrix (1) * Matrix (2) ):\n";
	PrintMatrix(resultMatrix ,3, 3);
*/

#pragma endregion

#pragma region Problem 9
/* 
	Write a program to fill a 3X3 matrix with random numbers and them
	then print the middle row and middle col.
	example :
		matrix1:
			01	10	07
			10	03	02
			06	03	09

		Middle row of matrix1 is :
			10	03	02

		Middle cil of matrix1 is :
			10	03	02
*/

/*
	int matrix[3][3];

	FillMatrixWithRandomNumbers(matrix , 1 , 10);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	cout << "\nMiddle Row Of Matrix (1) is:\n";
	PrintMiddleRowOfMatrix(matrix , 3 , 3);

	cout << "\nMiddle Columns Of Matrix (1) is:\n";
	PrintMiddleColumnsOfMatrix(matrix, 3, 3);
*/
#pragma endregion

#pragma region Problem 10
/* 
	Write a program to fill a 3X3 matrix with random numbers and them
	then write a function to sum all numbers in this matrix and print.
	example :
		matrix1:
			04	08	06
			13	10	07
			08	08	10

		sum of matrix1 is : 64
*/

/*
	int matrix[3][3];

	FillMatrixWithRandomNumbers(matrix , 1 , 10);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	cout << "\nSum Of Matrix (1) is : ";
	cout << SumAllNumbersInMatrix(matrix , 3 , 3);
*/
#pragma endregion

#pragma region Problem 11 
/* 
	Write a program to compare two matrices and check 
		if they are equal or not.
		example :
			matrix1:
				06	03	06
				04	05	09
				03	04	04
			matrix2:
				08	09	06
				06	08	06
				09	03	15

			No: matrices are not equal
*/

/*
	int matrix[3][3], matrix2[3][3];
	//int matrix[3][3] = { {10,20,30} , {40,50,60} , {70,80,90} }, matrix2[3][3] = { {10,20,30} , {40,50,60}, {70,80,90} };

	FillMatrixWithRandomNumbers(matrix, 1, 10);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	FillMatrixWithRandomNumbers(matrix2, 1, 10);
	cout << "\nMatrix (2):\n";
	PrintMatrix(matrix2, 3, 3);

	if (CheckSumTwoMatrixEqualOrNotEqual(matrix, matrix2, 3, 3))
		cout << "Yes: Matrices are equal \n";
	else
		cout << "No: Matrices are not equal \n";
*/
#pragma endregion

#pragma region Problem 12
/* 
	Write a program to compare two matrices and check
	if they are typical or not.
	example :
		matrix1:
			06	03	06
			04	05	09
			03	04	04
		matrix2:
			08	09	06
			06	08	06
			09	03	15

		No: matrices are not equal
*/

/*
	int matrix[3][3], matrix2[3][3];
	//int matrix[3][3] = { {10,20,30} , {40,50,60} , {70,80,90} }, matrix2[3][3] = { {10,20,30} , {40,50,60}, {70,80,90} };

	FillMatrixWithRandomNumbers(matrix, 1, 10);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	FillMatrixWithRandomNumbers(matrix2, 1, 10);
	cout << "\nMatrix (2):\n";
	PrintMatrix(matrix2, 3, 3);

	if (CheckTwoMatrixEqualOrNotEqual(matrix, matrix2, 3, 3))
		cout << "Yes: Matrices are equal \n";
	else
		cout << "No: Matrices are not equal \n";
*/
#pragma endregion

#pragma region Problem 13
/* 
	Write a program to check if they matrix is identity or not.
	example :
		matrix1:
			01	00	00
			00	01	00
			00	00	01
		Yes: matrix is identity.
*/

/*
	int matrix[3][3] = { {1,0,0} , {0,1,0} , {0,0,1} };

	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	if (IsIdentityMatrix(matrix,3, 3))
		cout << "\nYes: Matrices Is Identity \n";
	else
		cout << "\nNo: Matrices Is Not Identity \n";
*/

#pragma endregion

#pragma region Problem 14
/* 
	Write a program to check if they matrix is scalar or not.
	example :
		matrix1:
			09	00	00
			00	09	00
			00	00	09
	Yes: matrix is scalar.
*/

/*
	int matrix[3][3] = { {10,0,0} , {0,9,0} , {0,0,9} };

	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	if (IsScalarMatrix(matrix,3, 3))
		cout << "\nYes: Matrices Is Scalar \n";
	else
		cout << "\nNo: Matrices Is Not Scalar \n";
*/

#pragma endregion

#pragma region Problem 15
/* 
	Write a program to check if they matrix is scalar or not.
	example :
		matrix1:
			9	1	12
			0	9	1
			0	9	9
	Enter the number to count in matrix ? 
	9
	Number 9 count in matrix is 4
*/

/*
	int matrix[3][3];

	FillMatrixWithRandomNumbers(matrix, 1, 10);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	int inputNumber = ReadPositiveNumber("\nEnter Number To Count In Matrix ?");
		cout << "Number " << inputNumber << " Count in Matrix "
		<< HowManyRepetedNumberInMatrix(matrix , inputNumber , 3 ,3);
*/

#pragma endregion

#pragma region Problem 16
/* 
	Write a program to check if the matrix is sparce or not.
	example :
		matrix1:
			10	0	12
			20	15	1
			0	0	9
		No: It`s Not Sparce

		matrix1:
			0	0	12
			0	0	1
			0	0	9

		Yes: It is Sparce
*/

/*
	int matrix[3][3] = { {10,11,0} , {12,9,0} , {0,0,6} };

	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	if(IsMatrixSparce(matrix , 3, 3))
	{
		cout << "\nYes: It Is Sparse\n";
	}
	else
	{
		cout << "\nNo: It`s Not Sparse\n";
	}
*/

#pragma endregion

#pragma region Problem 17
/* 
	Write a program to check if a given numbers exists matrix or not.
	example :
		matrix1:
			77	5	12
			22	20	1
			1	0	9
	Enter the number to look for in matrix ? 
	77
	Yes it is there
*/

/*
	int matrix[3][3];

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
	}
*/
#pragma endregion

#pragma region Problem 18
/* 
	Write a program to print the intersected numbers in two given matrices.
	example :
		matrix1:
			77	5	12
			22	20	1
			1	0	9
		matrix2:
			5	80	90
			22	77	1
			10	8	33
	Intersected numbers are:
	77	5	22	1	1
*/

/*
	int matrix[3][3] , matrix2[3][3];

	FillMatrixWithRandomNumbers(matrix, 1, 10);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	FillMatrixWithRandomNumbers(matrix2, 1, 10);
	cout << "\nMatrix (2):\n";
	PrintMatrix(matrix2, 3, 3);

	cout << "\nIntersected Numbers are:\n";
	PrintIntersectedNumbers(matrix ,matrix2 , 3 ,3);
*/

#pragma endregion

#pragma region Problem 19
/* 
	Write a program to print the Minimum and Maximum Numbers in matrix.
	example :
		matrix1:
			77	5	12
			22	20	6
			14	3	9

		Minimum Number Is:	3

		Maximum Number Is:	77
*/

/*
	int matrix[3][3];

	FillMatrixWithRandomNumbers(matrix, 10, 100);
	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	cout << "\nMinimum Number Is:\n";
	cout << MinNumberInMatrix(matrix, 3, 3);

	cout << "\nMaximum Number Is:\n";
	cout << MaxNumberInMatrix(matrix, 3, 3);
*/
#pragma endregion

#pragma region Problem 20
/* 
	Write a program to check it the matrix is palindrome or not.
	example :
		matrix1:
			1	2	1
			5	5	5
			7	3	7
		Yes : Matrix is palindrome

		matrix1:
			1	2	1
			5	5	5
			7	3	8
		No : Matrix is not palindrome
*/

/*
	int matrix[3][3] = { {1,2,1} , {5,5,5} , {7,3,7} };

	cout << "Matrix (1):\n";
	PrintMatrix(matrix, 3, 3);

	if (IsPalindromMatrix(matrix,3, 3))
		cout << "\nYes: Matrix Is Palindrom \n";
	else
		cout << "\nNo: Matrix Is Not Palindrom \n";
*/
#pragma endregion

#pragma region Problem 21
/* 
	Write a program to print fibonacci series of 10 
		example:
		result 	1	1	2	3	5	8	13	21	34	55
*/

/*
	PrintFibonacciSeries(10);
*/
#pragma endregion

#pragma region Problem 22
/* 
	Write a program to print fibonacci series of 10
		example : Use Recursion
		result 	1	1	2	3	5	8	13	21	34	55
*/

/*
	PrintFibonacciSeriesRecursion(10, 0, 1);
*/
#pragma endregion

#pragma region Problem 23
/* 
	Write a program to read a string then print the first letter of each
		word in that string.
	example:
		please enter your string ?
			Mohamed Rayyan Abdullah Ahmed

		First letters of this string:
		M
		R
		A
		A
*/

/*
	PrintFirstLetterInString(ReadString("Please Enter Your String ?\n"));.
*/
#pragma endregion

#pragma region Problem 24 
/* 
	Write a program to read a string then uppercase the first 
		letter of each word in that string 
	example:
		please enter your string ?
			mohamed rayyan abdullah ahmed

		string after conversion:
			Mohamed Rayyan Abdullah Ahmed
*/

/*
	string str = ReadString("Please Enter Your String ?\n");
	str = UppercaseFirstLetterOfEachWord(str);
	cout << "\nString After Conversion:\n";
	cout << str << endl;
*/
#pragma endregion

#pragma region Problem 25
/* 
	Write a program to read a string then lowercase the first 
	letter of each word in that string  
	example:
		please enter your string ?
			Mohamed Rayyan Abdullah Ahmed

		string after conversion:
			mohamed rayyan abdullah ahmed
*/

/*
	string str = ReadString("Please Enter Your String ?\n");
	str = LowercaseFirstLetterOfEachWord(str);
	cout << "\nString After Conversion:\n";
	cout << str << endl;
*/
#pragma endregion

#pragma region Problem 26
/* 
	Write a program to read a string Then upper all letters, 
	then lower all letters , and print them 
	example:
		string after upper:
			MOHAMED RAYYAN ABDULLAH AHMED

		string after lower:
			mohamed rayyan abdullah ahmed
*/	

/*
	string str = ReadString("Please Enter Your String ?\n");

	cout << "\nString After Upper:\n" << UpperAllLetters(str) << endl;

	cout << "\nString After Lower:\n" << LowerAllLetters(str) << endl;
*/
#pragma endregion

#pragma region Problem 27
/* 
	Write a program to read a character then invert it`s case
	and print it
	example:
		please enter a character ? 
			a
		
		char after inverting case:
			A
*/

/*
	char character = InvertLetterCase(ReadCharacter("Please Enter a Character ?\n"));
	cout << "\nChar After Inverting Case:\n" << character;
*/
#pragma endregion

#pragma region Problem 28
/* 
	Write a program to read a string then invert all it`s letters case
	and print it  
	example:
		please enter your string:
			mohamed RAYYAN ABDULLAH ahmed

		string after inverting all letters case:
			MOHAMED rayyan abdullah AHMED
*/

/*
	string str = InvertAllStringLettersCase(ReadString("Please Enter a Your String ?\n"));
	cout << "\nString after inverting All Letters Case:\n" << str;
*/
#pragma endregion

#pragma region Problem 29
/* 
	Write a program to read a string then count small / capital 
	letters in that string .
	example:
		please enter your string ? 
			Mohamed Rayyan

		string Length = 14
		capital letters count = 2
		small letters count = 11
*/

/*
	string str = ReadString("Please Enter a Your String ?\n");
	cout << "\nString Length : " << str.length() << endl;
	cout << "\nCount Small Letters: " << CountLetters(str , enWhatToCount::SmallLetters) << endl;
	cout << "\nCount Capital Letters: " << CountLetters(str , enWhatToCount::CapitalLetters) << endl;
*/
#pragma endregion

#pragma region Problem 30
/*
	Write a program to read a string and read character then count the
	character in that string .
	example:
		please enter your string ?
			Mohamed Rayyan

		please enter a character  ?
			m

		letter 'm' count = 1
*/

/*
	string str = ReadString("Please Enter a Your String ?\n");
	
	 char character = ReadCharacter("\nPlease Enter a Character ?\n");
	
	 short count = HowManyRecurringcharacters(str , character);
	
	cout << "\nLetter '"<< character << "' Count = " << count << endl;
*/
#pragma endregion

#pragma region Problem 31
/*
	Write a program to read a string and read character then count the
	character in that string (Match Case or Not) .
	example:
		please enter your string ?
			Mohamed Rayyan

		please enter a character  ?
			m

		letter 'm' count = 1

		letter 'm' Or 'M' count = 2
*/

/*
	string str = ReadString("Please Enter a Your String ?\n");
	
	char character = ReadCharacter("\nPlease Enter a Character ?\n");
	
	short count = HowManyRecurringcharacters(str, character);
	
	char Lower = tolower(character);
	char Upper = toupper(character);
	
	cout << "\nLetter '"<< character << "' Count = " << count << endl;
	
	count = HowManyRecurringcharacters(str , character, false);
	
	cout << "\nLetter '"<< Lower << "' OR '"<< Upper <<  "' Count = " << count << endl;
*/
#pragma endregion

#pragma region Problem 32
/*
	Write a program to read a character then check if it is a vowel
	or not (vowels are : a, e, i, o, u) .
	example:
		please enter a character  ?
			a

		Yes letter 'a' is Vowel
*/

/*
	char letter = ReadCharacter("Please Enter a Character?");
	
	if (IsVowels(letter))
	cout << "Yes: Letter '" << letter << "' Is Vowel\n";
	else
	cout << "No: Letter '" << letter << "' Is Not Vowel\n";
*/
#pragma endregion

#pragma region Problem 33
/*
	Write a program to read a string then count all vowels in that string
	(vowels are : a, e, i, o, u) .
	example:
		please enter a string  ?
			Mohamed Abdullah

		Number of Vowels is = 6
*/


/*
	string str = ReadString("Please Enter a String?");
	
	cout << "Number Of Vowels Is : " << CountVowels(str) << endl;
*/

#pragma endregion

#pragma region Problem 34
/* 
	Write a program to read string then print all vowels in that string
		(vowels are : a, e, i, o, u)
	example:
		Please enter your string ?
			Mohamed Abdullah

		vowels in string are : o	a	e	A	u	a
*/

/*
	string str = ReadString("Please Enter a String?");
	
	cout << "\nVowels In String : ";
	PrintAllVowels(str);
*/
#pragma endregion

#pragma region Problem 35
/*
	Write a program to read a string then print each word in that string
	example:
		
		please Enter Your string ?
			Mohamed Rayyan Abdullah Ahmed

		Your string words are:
			Mohamed 
			Rayyan 
			Abdullah 
			Ahmed
*/

/*
	string str = ReadString("Please Enter a String?");

	cout << "\nYour String Words are :\n";
	PrintEachWordInString(str , " ");
*/
#pragma endregion

#pragma region Problem 36
/*
	Write a program to read a string then count each word in that string
	example :
		please enter your string ?
			Mohamed Rayyan Abdullah Ahmed

		the number of words in your string is: 4
*/

/*
	string str = ReadString("Please Enter a String?");
	cout << "\nThe Number Of Words In Your String Is : " 
	<< CountEachWordInString(str , " ") << endl;
*/
#pragma endregion

#pragma region Problem 37
/*
	Write a program to read a string then make a function to split 
	each word in vector .
	example :
		please enter your string ?
			Mohamed Rayyan Abdullah Ahmed

		tokens = 4
			Mohamed
			Rayyan
			Abdullah
			Ahmed
*/

/*
	string str = ReadString("Please Enter a String?");
	vector<string> vWords = SplitEachWordInVector(str, " ");
	PrintWordFromTheVector(vWords);
*/
#pragma endregion

#pragma region Problem 38
/* Write a program to read a string then trim left , right , all
	example:
		please Enter your a string ?
			"  Mohamed Ahmed Rayyan  "

		Trim Left	= "Mohamed Ahmed Rayyan  "
		Trim Right	= "  Mohamed Ahmed Rayyan"
		Trim		= "Mohamed Ahmed Rayyan"
*/

/*
	string str = ReadString("Please Enter a String?");
	cout << "Original String =" << str << endl;
	cout << "Length Original a String = " << str.length() << endl;
	
	string strTL = TrimLeftString(str);
	cout << "\n\nTrim Left a String =" << strTL << endl;
	cout << "Length Trim Left = " << strTL.length() << endl;
	
	string strTR = TrimRightString(str);
	cout << "\n\nTrim Right a String =" << strTR << endl;
	cout << "Length Trim Right = " << strTR.length() << endl;
	
	string strT = TrimString(str);
	cout << "\n\nTrim a String =" << strT << endl;
	cout << "Length Trim = " << strT.length() << endl;
*/
#pragma endregion

#pragma region Problem 39
/* 
	Write a program to join vector of string into a one string 
	with separators 
	vector<string> vWords = { "Hello" , "World" , "C++" , "Programming" };
		example:
			vectore after join
				"Hello World C++ Programming"
*/

/*
	vector<string> words = { "Hello", "World", "C++", "Programming" };
	string delimiter = " ";
	string result = JoinString(words, delimiter);
	cout << "Joined String: " << result << endl;
*/
#pragma endregion

#pragma region Problem 40
/*
	Write a program to join array of string into a one string
	with separators
	vector<string> vWords = { "Hello" , "World" , "C++" , "Programming" };
		example:
			vectore after join
				"Hello World C++ Programming"

			array after join
				"Hello World C++ Programming"
*/

/*
	string words[] = { "Hello", "World", "C++", "Programming" };
	string delimiter = " ";
	short arrLength = ReadPositiveNumber("Enter Length The Array ?");
	string result = JoinString(words, arrLength , delimiter);
	cout << "Joined String: " << result << endl;
*/
#pragma endregion

#pragma region Problem 41
/* 
	Write a program to read string and reverse its words
	example:
		Please enter your string ?
			Mohamed Rayyan Ahmed Abdullah

		string after reversing words:
			Abdullah Ahmed Rayyan Mohamed
*/

/*
	string str = ReadString("Please Enter a String?");
	cout << "Original String =" << str << endl;
	cout << "String After Reversing Words =" << ReverseWords(str) << endl;
*/
#pragma endregion

#pragma region Problem 42
/* 
	Write a program to replace words in string
	example:

	original string
		Welcome To phalstein , phalstein is a nice country

	string after replace
		Welcome To egypt , egypt is a nice country
*/

/*
	string str = ReadString("Please Enter a String?");
	cout << "Original String =" << str << endl;
	cout << "String After Replace Built In Function =" 
	<< ReplaceStringBuiltInFunction(str , "Rayyan" , "Mohamed") << endl;
*/
#pragma endregion

#pragma region Problem 43
/* 
	Write a program to replace words in string using custom function:
	example:
	original string:
		Welcome To phalstein , phalstein is a nice country

	replace with match case:
		Welcome To phalstein , phalstein is a nice country

	replace with dont match case:
		Welcome To egypt , egypt is a nice country
*/

/*
	string str = ReadString("Please Enter a String?");
	cout << "Original String : " << str << endl;
	cout << "\nReplace With Match Case : " << ReplaceString(str, "rayyan", "Mohamed") << endl;
	cout << "\nReplace With Dont Match Case : " << ReplaceString(str , "rayyan" , "Mohamed" , false) << endl;
*/
#pragma endregion

#pragma region Problem 44
/* 
	Write a program to remove all punctuation from a string :
	example:
	original string:
		Welcome To phalstein , phalstein is: a nice; country

	punctuation removed:
		Welcome To phalstein phalstein is a nice country
*/


/*
	string str = "Welcome To phalstein ,phalstein is: a nice; country.";

	cout << "original string :\n" << str << endl;

	cout << "punctuation removed :\n" << RemovePunctuationFromString(str) << endl;
*/

#pragma endregion

#pragma region Problem 45
/* Write aprogram to read bank client data record and convert it to one line.
	example
	Please Enter Client Data:
		- Enter Account Number ? 
			A150
		- Enter PinCode ?
			1234
		- Enter Name ? 
			Mohamed Abdullah
		- Enter Phone ? 
			0123456789
		- Enter AccountBalance ? 
			5000

	Client Record For Saving is:
		A150#//#1234#//#Mohamed Abdullah#//#0123456789#//#5000.000
*/


/*
	cout << "Please Enter Client Data:\n\n";

	stClientData client = ReadNewClient();

	cout << "Client Record For Saving is :\n" 
	<< convertRecordToLine(client);
*/

#pragma endregion

#pragma region Problem 46
/* Write aprogram to convert line data to record and print it.
	example

	Line Record Is:
		A150#//#1234#//#Mohamed Abdullah#//#0123456789#//#5000.000

	The following is the extracted client record:
		- Account Number : A150
		- PinCode		 : 1234
		- Name			 : Mohamed Abdullah
		- Phone 		 : 0123456789
		- Account Balance: 5000
*/

/*
	string recordLine = "A150#//#1234#//#Mohamed Abdullah#//#0123456789#//#5000.000";

	cout <<"Line Record Is:" << recordLine << endl;

	stClientData clientData = convertLineDataToRecord(recordLine);

	printClientRecord(clientData);
*/
#pragma endregion

#pragma region Problem 47
/*
	Write a program to ask you to enter clients and save them to file.

		example:

		Adding New Client
			- Enter Account Number ? 
				A150
			- Enter PinCode ?
				1234
			- Enter Name ? 
				Mohamed Abdullah
			- Enter Phone ? 
				0123456789
			- Enter AccountBalance ? 
				5000

		Client Added Successfully, Do You Want To Add More Clients ? Y/N
*/

/*
	AddClients();
*/
#pragma endregion

#pragma region Problem 48
/*
	Write a program to read clients file and show them on 
		the screen as follows:
	example:
						Client List (Count Client) Client
	-----------------------------------------------------------------------
	| Account Number	| Pin Code	| Client Name	| Phone		| Balance |
	-----------------------------------------------------------------------
	|	A150			|	1234	| Mohamed Ahmed	| 011122222	| 9000
	|	A120			|	12355	| Ahmed Rayyan	| 011133333	| 7000
	-----------------------------------------------------------------------
*/

/*
	vector <stClientData> vClients =  LoadClientsDataFromFile(ClientsFileName);
	PrintShowAllClient(vClients);
*/
#pragma endregion

#pragma region Problem 49
/*
	Write a program to find client accountNumber and 
		print it to the screen.

	example:
		
		Please enter accountNumber ? A120

			The following is the extracted client record:
			- Account Number : A150
			- PinCode		 : 1234
			- Name			 : Mohamed Abdullah
			- Phone 		 : 0123456789
			- Account Balance: 5000

		otherwise: A1111
			Client With Account Number (A1111) Not Found"
*/

/*
	vector<stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
	string inputAccountNumber = ReadString("Please Enter Account Number ?");
	stClientData client;

	if (FindClientByAccountNumber(inputAccountNumber,vClients ,client))
		printClientRecord(client);

	else
		cout << "\nClient With Account Number (" << inputAccountNumber << ") Not Found";
*/
#pragma endregion

#pragma region Problem 50
/*
	Write a program to delete client by accountNumber and
		print it to the screen.

	example:

		Please enter accountNumber ? A120

			The following is the extracted client record:
			- Account Number : A150
			- PinCode		 : 1234
			- Name			 : Mohamed Abdullah
			- Phone 		 : 0123456789
			- Account Balance: 5000

			Are You Sure You Want Delete This Client ? y/n ?y

			---------------------------------
				Client Deleted Successfully
			---------------------------------

		otherwise: A1111
			-----------------------------------------------------
				Client With Account Number (A1111) Not Found"
			-----------------------------------------------------
*/

/*
	vector <stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
	string inputAccountNumber = ReadString("Please Enter Account Number ?");

	DeleteClientByAccountNumber(inputAccountNumber, vClients);
*/
#pragma endregion

#pragma region Problem 51
/*
	Write a program to update client by accountNumber and
		print it to the screen.

	example:

		Please enter accountNumber ? A120

			The following is the extracted client record:
			- Account Number : A150
			- PinCode		 : 1234
			- Name			 : Mohamed Abdullah
			- Phone 		 : 0123456789
			- Account Balance: 5000

			Are You Sure You Want update This Client ? y/n ?y

			Enter PinCode?
				4567

			Enter Name?
				Abdullah Mohamed

			Enter Phone?
				0987654321

			Enter Account Balance?
				8000

			---------------------------------
				Client Updated Successfully
			---------------------------------

		otherwise: A1111
		-----------------------------------------------------
			Client With Account Number (A1111) Not Found"
		-----------------------------------------------------
*/


/*
	vector <stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
	string inputAccountNumber = ReadString("Please Enter Account Number ?");

	UpdateClientByAccountNumber(inputAccountNumber, vClients);
*/

#pragma endregion



}