
#include <iostream>
#include <string> 
#include "cmath"

using namespace std;

double getPI()
{
	return 3.141592653589793238;
}

void MessageOnScreen(string msg)
{
	cout << msg << endl;
}

#pragma region Problem => 1 ( Procedure ) 
//void PrintYourName(string name)
//{
//	cout << name << endl;
//}
#pragma endregion


#pragma region Problem 2 => (Function) 
//string ReadYourName()
//{
//	string name;
//	cout << "Please Enter Your Name? Problem (2)" << endl;
//	getline(cin , name);
//	return name;
//}
#pragma endregion


#pragma region Problem 3 => (Enum , Procedure , 2 Function)  
//enum enNumberType { ODD = 1 , EVEN = 2 };
//
//int ReadNumber()
//{
//	int number;
//	cout << "The Problem 3 : Enter Number ?" << endl;
//	cin >> number;
//	return number;
//}
//
//enNumberType checkNumberType(int num)
//{
//	return ((num % enNumberType::EVEN) == 0) ? enNumberType::EVEN : enNumberType::ODD;
//}
//
//void PrintNumberType(enNumberType numberType)
//{
//	((numberType == enNumberType::EVEN) ? cout <<  "Number IS Even" : cout << "Number IS Odd");
//}
#pragma endregion


#pragma region Problem 4 && Update Problem 5 (Has Recommendation) => (Struct , 2 Function , Procedure) 

//struct stInfo
//{
//	int age;
//	bool driverLicense;
//	bool HasRecommendation;
//
//};
//
//stInfo ReadInfo()
//{
//	stInfo emp;
//	MessageOnScreen("Please Enter Is Age ?");
//	cin >> emp.age;
//
//	MessageOnScreen("Do You Have Driver License ? (1 OR 0)");
//	cin >> emp.driverLicense;
//
//	MessageOnScreen("Do You Have Recommendation ? (1 OR 0)");
//	cin >> emp.HasRecommendation;
//	return emp;
//}
//
//bool IsAccepted(stInfo emp)
//{
//	return(emp.HasRecommendation) ? true : (emp.age > 21 && emp.driverLicense);
//}
//
//void Print_Hired_OR_Regected(stInfo emp)
//{
//	(IsAccepted(emp)) ? MessageOnScreen("Hired") : MessageOnScreen("Rejected");
//}

#pragma endregion


#pragma region Problem 6 => (Struct , 2 Function , Procedure)
//struct stFullName
//{
//	string firstName, lastName;
//};
//
//stFullName ReadFullName()
//{
//	stFullName fullName;
//
//	MessageOnScreen("Please Enter First Name ?");
//	cin >> fullName.firstName;
//
//	MessageOnScreen("Please Enter Last Name ?");
//	cin >> fullName.lastName;
//
//	return fullName;
//}
//
//string GetFullName(stFullName fullname)
//{
//	return fullname.firstName + " " + fullname.lastName;
//}
//
//void PrintFullName(string fullname)
//{
//	MessageOnScreen(fullname);
//}

#pragma endregion


#pragma region Problem 7 => (2 Function , Procedure)

//int ReadNumber()
//{
//	int number;
//
//	MessageOnScreen("Please Enter Number ?");
//	cin >> number;
//	return number;
//}
//
//float CalculateHalfIsNumber(float number)
//{
//	return  number / 2;
//}
//
//void PrintHalfIsNumber(float number)
//{
//	MessageOnScreen(to_string(CalculateHalfIsNumber(number)));
//}
#pragma endregion


#pragma region Problem 8 => (2 Function , Procedure)

//float ReadMark()
//{
//	float mark;
//
//	MessageOnScreen("Please Enter Mark ?");
//	cin >> mark;
//	return mark;
//}
//
//bool CheckTheMark(float mark)
//{
//	return mark >= 50;
//}
//
//void PrintPassOrFailTheMark(float mark)
//{
//	(CheckTheMark(mark)) ? MessageOnScreen("Pass") : MessageOnScreen("Fail");
//}
#pragma endregion


#pragma region Problem 9 => (Struct , 2 Function , Procedure)
//struct stNumbers
//{
//	int arrayNumbers[3], sum = 0, Length = 0;
//
//};
//
//stNumbers ReadNumbers()
//{
//	stNumbers Numbers;
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "Please Number ( " <<  i + 1 << " ):";
//		cin >> Numbers.arrayNumbers[i]; 
//		Numbers.Length++;
//	}
//	return Numbers;
//}
//
//int CalculateNumbersSum(stNumbers numbers)
//{
//	for (int i = 0; i < numbers.Length; i++)
//	{
//		numbers.sum += numbers.arrayNumbers[i];
//	}
//	return numbers.sum;
//}
//
//void PrintNumberSum(stNumbers nums)
//{
//	MessageOnScreen("Sum OF Numbers = " + to_string(CalculateNumbersSum(nums)));
//}
#pragma endregion


#pragma region (Problem 10 && Problem 11) => (Struct , 4 Function , 2 Procedure)
//struct stMarks
//{
//	int arrayMarks[3], sum = 0, Length = 0;
//	
//}; 
//
//stMarks ReadMarks()
//{
//	stMarks marks;
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "Please Enter Mark ( " << i + 1 << " ): ";
//		cin >> marks.arrayMarks[i];
//		marks.Length++;
//	}
//	return marks;
//}
//
//float GetSumMarks(stMarks marks)
//{
//	for (int i = 0; i < marks.Length; i++)
//	{
//		marks.sum += marks.arrayMarks[i];
//	}
//	return (float)marks.sum;
//}
//
//float GetAverageMarks(stMarks marks)
//{
//	return GetSumMarks(marks) / marks.Length;
//}
//
//bool CheckAverageMarksGraterThan50(stMarks marks)
//{
//	return GetAverageMarks(marks) >= 50;
//}
//
//void PrintAverageMarks(stMarks marks)
//{
//	MessageOnScreen("Average Marks = " + to_string(GetAverageMarks(marks)));
//}
//
//void PrintPassOrFailForMarks(stMarks marks)
//{
//	(CheckAverageMarksGraterThan50(marks)) ? MessageOnScreen("Pass") : MessageOnScreen("Fail");
//}

#pragma endregion 


#pragma region Problem 12 => (Function ,  2 Procedure)

//void ReadTwoNumber(int & num1 , int & num2)
//{
//	MessageOnScreen("Please Enter Number :(1)");
//	cin >> num1;
//
//	MessageOnScreen("Please Enter Number :(2)");
//	cin >> num2;
//}
//
//int GetMax2Number(int num1, int num2)
//{
//	return (num1 > num2) ? num1 : num2;
//}
//
//void PrintMaxNumber(int maxNumber)
//{
//	MessageOnScreen("The Max Number = " + to_string(maxNumber));
//}
#pragma endregion


#pragma region Problem 13 => (Function ,  2 Procedure)

//void ReadThreeNumber(int& num1, int& num2 , int& num3)
//{
//	MessageOnScreen("Please Enter Number :(1)");
//	cin >> num1;
//
//	MessageOnScreen("Please Enter Number :(2)");
//	cin >> num2;
//
//	MessageOnScreen("Please Enter Number :(3)");
//	cin >> num3;
//}
//
//int GetMax3Number(int num1, int num2, int num3)
//{
//	return (num1 > num2) ? (num1 > num3) ? num1 : num3 : (num2 > num3) ? num2 : num3;
//	
//}
//
//void PrintMaxNumber(int maxNumber)
//{
//	MessageOnScreen("The Max Number = " + to_string(maxNumber));
//}
#pragma endregion


#pragma region Problem 14 => (3 Procedure)
//void Read2Number(int &num1 , int &num2) 
//{
//	MessageOnScreen("Please Enter Number (1)");
//	cin >> num1;
//
//	MessageOnScreen("Please Enter Number (2)");
//	cin >> num2;
//}
//
//void Swap2Number(int &num1 , int &num2)
//{
//	int temp = num1;
//	num1 = num2;
//	num2 = temp;
//}
//
//void Print2Number(int num1, int num2)
//{
//	MessageOnScreen(to_string(num1)+ " , " + to_string(num2));
//}
#pragma endregion


#pragma region Problem 15 => (Struct , 2 Function , Procedure)
struct stRectangle
{
	double width, height, diagonal;
};

stRectangle ReadWidthAndHeight()
{
	stRectangle rectangle;
	MessageOnScreen("Please Enter Width Rectangle:");
	cin >> rectangle.width;

	MessageOnScreen("Please Enter Height Rectangle:");
	cin >> rectangle.height;

	return rectangle;
}

double calculateRectangleArea(stRectangle rectangle)
{
	return rectangle.height * rectangle.width;
}

void PrintRectangleArea(stRectangle rectangle)
{
	MessageOnScreen("Rectangle Area = " + to_string(calculateRectangleArea(rectangle)));
}
#pragma endregion


#pragma region Problem 16 => (Struct ,  Function , Procedure)
stRectangle ReadHeightAndDiagonal()
{
	stRectangle rectangle;
	MessageOnScreen("Please Enter Height Rectangle:");
	cin >> rectangle.height;

	MessageOnScreen("Please Enter Diagonal Rectangle:");
	cin >> rectangle.diagonal;

	return rectangle;
}

double calculateRectangleAreaThroughDiagonal(stRectangle rectangle)
{
	return rectangle.height * sqrt(pow(rectangle.diagonal, 2) - pow(rectangle.height, 2));
}

void PrintRectangleAreaThroughDiagonal(stRectangle rectangle)
{
	MessageOnScreen("Rectangle Area Through Diagonal = " + to_string(calculateRectangleAreaThroughDiagonal(rectangle)));
}
#pragma endregion


#pragma region Problem 17 => (Struct ,  2 Function , Procedure)
struct stTriangle
{
	float height, triangleRule, rib[3];
};

stTriangle ReadHeightAndTriangleRule()
{
	stTriangle triangle;
	MessageOnScreen("Please Enter triangle Rule:");
	cin >> triangle.triangleRule;

	MessageOnScreen("Please Enter Height Rectangle:");
	cin >> triangle.height;

	return triangle;

}

float calculateTriangleArea(stTriangle triangle)
{
	return (triangle.triangleRule / 2) * triangle.height;
}

void PrintTriangleArea(stTriangle triangle)
{
	MessageOnScreen("Triangle Area = " + to_string(calculateTriangleArea(triangle)));
}
#pragma endregion 


#pragma region Problem 18 => (Struct ,  2 Function , Procedure)
struct stCircle
{
	float radius, diameter, LengthPerimeter;
};

stCircle ReadCircleDistance()
{
	stCircle circle;
	MessageOnScreen("Please Enter Distance:");
	cin >> circle.radius;

	return circle;
}

double CalculateCircleAreaByRadius(stCircle circle)
{
	return (getPI() * pow(circle.radius, 2));
}

void PrintTriangleArea(stCircle circle)
{
	MessageOnScreen("Calculate Circle Area By Radius = " + to_string(CalculateCircleAreaByRadius(circle)));
}
#pragma endregion 


#pragma region  Problem 19 => (2 Function , Procedure)
stCircle ReadCircleDiameter()
{
	stCircle circle;
	MessageOnScreen("Please Enter Diameter:");
	cin >> circle.diameter;

	return circle;
}

double CalculateAreaCircleFullDiameter(stCircle circle)
{
	return getPI() * pow(circle.diameter, 2) / 4;
}

void PrintAreaCircleFullDiameter(stCircle circle)
{
	MessageOnScreen("Calculate Area Circle Full Diameter = " + to_string(CalculateAreaCircleFullDiameter(circle)));
}
#pragma endregion 


#pragma region  Problem 20 => (Struct , 2 Function , Procedure)
struct stSquare
{
	double SquareSide;
};

stSquare ReadSquareSide()
{
	stSquare Square;
	MessageOnScreen("Please Enter Square Side:");
	cin >> Square.SquareSide;

	return Square;
}

double CalculateCircleAreaInscribedInSquare(stSquare Square)
{
	return getPI() * pow(Square.SquareSide, 2) / pow(2, 2);
}

void PrintCircleAreaInscribedInSquare(stSquare Square)
{
	MessageOnScreen("Calculate Circle Area Inscribed In Square = " + to_string(CalculateCircleAreaInscribedInSquare(Square)));
}
#pragma endregion 


#pragma region  Problem 21 => (2 Function , Procedure)

stCircle ReadLengthPerimeter()
{
	stCircle circle;
	MessageOnScreen("Please Enter Length Perimeter :");
	cin >> circle.LengthPerimeter;

	return circle;
}

double CalculateCircleAreaAlongCircumference(stCircle circle)
{
	return pow(circle.LengthPerimeter, 2) / (getPI() * 4);
}

void PrintCircleAreaAlongCircumference(stCircle circle)
{
	MessageOnScreen("Calculate Circle Area Along Circumference = " + to_string(CalculateCircleAreaAlongCircumference(circle)));
}
#pragma endregion 


#pragma region Problem 22 => (2 Function , Procedure)
stTriangle ReadSideHeightTriangleAndTriangleRule()
{
	stTriangle triangle;
	MessageOnScreen("Please Enter Side height of triangle :");
	cin >> triangle.height;

	MessageOnScreen("Please Enter Triangle rule :");
	cin >> triangle.triangleRule;
	return triangle;
}

double CalculateCircleAreaInscribedInIsoscelesTriangle(stTriangle triangle)
{
	return getPI() * (pow(triangle.triangleRule, 2) / 4) *
		(((2 * triangle.height) - triangle.triangleRule) / ((2 * triangle.height) + triangle.triangleRule));
}

void PrintCalculateCircleAreaInscribedInIsoscelesTriangle(stTriangle triangle)
{
	MessageOnScreen("Calculate Circle Area In scribed In Isosceles Triangle = " +
		to_string(CalculateCircleAreaInscribedInIsoscelesTriangle(triangle)));
}
#pragma endregion 


#pragma region Problem 23 => (2 Function , Procedure)
stTriangle ReadThreeRibs()
{
	stTriangle triangle;
	for (int i = 0; i < 3; i++)
	{
		cout << "Please Enter Rib " << (i + 1) << ":\n";
		cin >> triangle.rib[i];

	}
	return triangle;
}

double CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(stTriangle triangle)
{
	double P = (triangle.rib[0] + triangle.rib[1] + triangle.rib[2]) / 2,
		result = (triangle.rib[0] * triangle.rib[1] * triangle.rib[2]) /
		(4 * sqrt(P * (P - triangle.rib[0]) * (P - triangle.rib[1]) * (P - triangle.rib[2])));
	result *= result;
	result *= getPI();
	return result;
}

void PrintCalculateCircleAreaCircleDescribedAroundArbitraryTriangle(stTriangle triangle)
{
	MessageOnScreen("Calculate circle area circle Described around an Arbitrary Triangle = " +
		to_string(CalculateCircleAreaCircleDescribedAroundArbitraryTriangle(triangle)));
}
#pragma endregion 


#pragma region Problem 24 => (2 Function , Procedure)
//int ReadAge() 
//{
//	int age;
//	MessageOnScreen("Please Enter Age ?");
//	cin >> age;
//	return age;
//}
//
//bool ValidationAge(int age)
//{
//	return (age >= 18 && age <= 45);
//}
//
//void PrintValidTheAgeORNotValid(int age)
//{
//	(ValidationAge(age) ? MessageOnScreen("Valid Age") : MessageOnScreen("InValid Age , Must Be Between From 18 To 45"));
//}

#pragma endregion


#pragma region Problem 25 => (3 Function , Procedure)
//int ReadAge()
//{
//	int age;
//	MessageOnScreen("Please Enter Age ?");
//	cin >> age;
//	return age;
//}
//
//bool ValidationAge(int age)
//{
//	return (age >= 18 && age <= 45);
//}
//
//int CheckEnterValidTheAge() 
//{
//	int age = 0;
//	do
//	{
//		age = ReadAge();
//
//	} while (!ValidationAge(age));
//	return age;
//}
//
//void PrintValidTheAgeORNotValid(int age)
//{
//	MessageOnScreen("Valid Age : " + to_string(age)) ;
//}
#pragma endregion


#pragma region Problem 26 => (Function , Procedure) 

//int ReadNumber() 
//{
//	int n = 1;
//	MessageOnScreen("Please Enter Number ?");
//	cin >> n;
//	return n;
//}
//
//void PrintNumbersFrom1ToN(int n)
//{
//	for (int i = 1; i <= n ; i++)
//	{
//		MessageOnScreen(to_string(i));
//	}
//}
#pragma endregion


#pragma region Problem 27 => (Function , Procedure) 

//int ReadNumber()
//{
//	int n = 1;
//	MessageOnScreen("Please Enter Number ?");
//	cin >> n;
//	return n;
//}
//
//void PrintNumbersFromNTo1(int n)
//{
//	for (int i = n; i >= 1; i--)
//	{
//		MessageOnScreen(to_string(i));
//	}
//}
#pragma endregion


#pragma region Problem 28 => (2 Function , Procedure) 
//int ReadNumber() 
//{
//	int n = 1;
//	MessageOnScreen("Please Enter Number ?");
//	cin >> n;
//	return n;
//}	
//int CalculateSumOddNumbers(int n)
//{
//	int sum = 0;
//	for (int i = 1; i <= n ; i +=2)
//	{
//			sum += i;
//	}
//	return sum;
//}
//
//void PrintSumOddNumbers(int sumNumbers)
//{
//	MessageOnScreen("Sum Numbers Odd = " + to_string(sumNumbers));
//}

#pragma endregion


#pragma region Problem 29 => (2 Function , Procedure) 
//int ReadNumber()
//{
//	int n = 1;
//	MessageOnScreen("Please Enter Number ?");
//	cin >> n;
//	return n;
//}
//int CalculateSumEvenNumbers(int n)
//{
//	int sum = 0;
//	for (int i = 2; i <= n; i += 2)
//	{
//		sum += i;
//	}
//	return sum;
//}
//
//void PrintSumEvenNumbers(int sumNumbers)
//{
//	MessageOnScreen("Sum Numbers Even = " + to_string(sumNumbers));
//}

#pragma endregion


#pragma region Problem => 30 (2 Function , Procedure) 
//int ReadPositiveNumber()
//{
//	int  n;
//	do
//	{
//		MessageOnScreen("Pleas Enter Positive Number ?");
//		cin >> n;
//	} while (n <= 0);
//
//	return n;
//}
//
//int CalculateFactorialNumber(int n)
//{
//	int f = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		f *= i;
//	}
//	return f;
//}
//
//void PrintFactorialNumber(int factorial)
//{
//	MessageOnScreen("Factorial Number = " + to_string(CalculateFactorialNumber(factorial)));
//}
#pragma endregion


#pragma region Problem => 31 (Function , Procedure)
//int ReadNumber() {
//	int num;
//	MessageOnScreen("Please Enter Number");
//	cin >> num;
//	return num;
//}
//
//void PowerOf_2_3_4(int num)
//{
//	int PowerNumOf2, PowerNumOf3, PowerNumOf4;
//	PowerNumOf2 = num * num;
//	PowerNumOf3 = PowerNumOf2 * num;
//	PowerNumOf4 = PowerNumOf3 * num;
//	MessageOnScreen("Power OF ^2 = " + to_string(PowerNumOf2) + 
//		"\nPower OF ^3 = " + to_string(PowerNumOf3)+ 
//		"\nPower OF ^4 = " + to_string(PowerNumOf4));
//}
#pragma endregion


#pragma region Problem => 32 (Function , 2 Procedure)
//void ReadNumberAndPowerNumber(int& number, int& powerNumber) 
//{
//	MessageOnScreen("Please Enter Number:");
//	cin >> number;
//
//	MessageOnScreen("Please Enter Power Of Number:");
//	cin >> powerNumber;
//}
//
//int CalculatePowerNumber(int num, int powerNumber)
//{
//	if (powerNumber == 0)
//		return 1;
//
//	int result = num;
//
//	for (int i = 1; i < powerNumber; i++)
//	{
//		result *= num;
//	}
//	return result;
//}
//
//void PrintPowerOFM(int powerNumber)
//{
//	MessageOnScreen("Number ^M = " +to_string(powerNumber));
//}
#pragma endregion


#pragma region Problem => 33 (2 Function )

//int ReadNumberInRange(int from, int to)
//{
//	int number;
//	do
//	{
//		MessageOnScreen("Enter Number In Range ( " + to_string(from) + " => " + to_string(to) + " )");
//		cin >> number;
//	} while (number < from || number > to);
//
//	return number;
//}
//
//char GetGradeLetter(int grade)
//{
//
//	if (grade >= 90 and grade <= 100)
//	{
//		return 'A';
//	}
//	else if (grade >= 80 and grade <= 89)
//	{
//		return 'B';
//	}
//	else if (grade >= 70 and grade <= 79)
//	{
//		return 'C';
//	}
//	else if (grade >= 60 and grade <= 69)
//	{
//		return 'D';
//	}
//	else if (grade >= 50 and grade <= 59)
//	{
//		return 'E';
//	}
//	else
//	{
//		return 'F';
//	}
//}
#pragma endregion


#pragma region Problem => 34 (3 Functions)
//int ReadTotalSales()
//{
//	int totalSales;
//
//	do
//	{
//		MessageOnScreen("Enter Total Sales ?");
//		cin >> totalSales;
//	} while (totalSales < 0);
//
//	return totalSales;
//}
//
//double GetCommissionPercentage(int totalSales)
//{
//	if (totalSales > 1000000)
//		return 0.01;
//
//	else if (totalSales > 500000 and totalSales <= 1000000)
//		return 0.02;
//
//	else if (totalSales > 100000 and totalSales <= 500000)
//		return 0.03;
//
//	else if (totalSales > 50000 and totalSales <= 100000)
//		return 0.05;
//
//	else
//		return 0.00;
//}
//
//double calculateTotalCommission(int totalSales)
//{
//	return (double) GetCommissionPercentage(totalSales) * totalSales;
//}
#pragma endregion


#pragma region Problem 35 => (struct , enum ,  3 Functions)
//struct  stMoneyCategories
//{
//	float Pennies = 0, Nickels = 0, Dimes = 0, Quarter = 0, Dollars = 0;
//};
//
//enum enMoneyCategories
//{
//	Pennies = 1, Nickels = 5, Dimes = 10, Quarter = 25, Dollars = 100
//};
//
//stMoneyCategories ReadMoneyCategories()
//{
//	stMoneyCategories moneyCategories;
//
//	MessageOnScreen("Enter (Pennies) ?");
//	cin >> moneyCategories.Pennies;
//
//	MessageOnScreen("Enter (Nickels) ?");
//	cin >> moneyCategories.Nickels;
//
//	MessageOnScreen("Enter (Dimes) ?");
//	cin >> moneyCategories.Dimes;
//
//	MessageOnScreen("Enter (Quarter) ?");
//	cin >> moneyCategories.Quarter;
//
//	MessageOnScreen("Enter (Dollars) ?");
//	cin >> moneyCategories.Dollars;
//
//	return moneyCategories;
//}
//
//float CalaculateTotalPennies(stMoneyCategories moneyCategories)
//{
//	return
//		(moneyCategories.Pennies * enMoneyCategories::Pennies) +
//		(moneyCategories.Nickels * enMoneyCategories::Nickels) +
//		(moneyCategories.Dimes * enMoneyCategories::Dimes) +
//		(moneyCategories.Quarter * enMoneyCategories::Quarter) +
//		(moneyCategories.Dollars * enMoneyCategories::Dollars);
//}
//
//float CalaculateTotalDollars(float totalPennies)
//{
//	return totalPennies / enMoneyCategories::Dollars;
//}
#pragma endregion


#pragma region Problem 36 (struct , Functions , Procedure)
//struct stCalculater
//{
//	float FirstNumber, SecondNumber;
//	char TypeOperation;
//};
//
//stCalculater ReadNumbers()
//{
//	stCalculater calculater;
//	MessageOnScreen("Enter First Number ?");
//	cin >> calculater.FirstNumber;
//
//	MessageOnScreen("Enter Type Operation ?");
//	cin >> calculater.TypeOperation;
//
//	MessageOnScreen("Enter Second Number ?");
//	cin >> calculater.SecondNumber;
//
//	return calculater;
//}
//
//void Calculate(stCalculater calculater)
//{
//	float result;
//	switch (calculater.TypeOperation)
//	{
//	case '+':
//		result = calculater.FirstNumber + calculater.SecondNumber;
//		cout << "Result = " << result << endl;
//		break;
//
//	case '-':
//		result = calculater.FirstNumber - calculater.SecondNumber;
//		cout << "Result = " << result << endl;
//		break;
//
//	case '*':
//		result = calculater.FirstNumber * calculater.SecondNumber;
//		cout << "Result = " << result << endl;
//		break;
//
//	case '/':
//		if (calculater.SecondNumber != 0)
//		{
//			result = calculater.FirstNumber / calculater.SecondNumber;
//			cout << "Result = " << result << endl;
//		}
//		else
//		{
//			cout << "Error: Division by zero is undefined." << endl;
//		}
//		break;
//
//	default:
//		cout << "Wrong Type Operation";
//		break;
//	}
//}
#pragma endregion


#pragma region Problem 37 (2 Function)
//int ReadNumber()
//{
//	int number;
//
//	MessageOnScreen("Enter Number ?");
//	cin >> number;
//	return number;
//}
//
//int SumNumbersUntil_99(int number)
//{
//	int  sum = 0;
//
//	while (number != -99)
//	{
//		sum += number;
//		number = ReadNumber();
//	}
//	return sum;
//}
#pragma endregion


#pragma region Problem 38 (enum , 2 Function , Procedure)
//enum enPrimeOrNotPrime{Prime = 1 , NotPrime = 2};
//
//int ReadNumber()
//{
//	int number;
//
//	MessageOnScreen("Enter Number ?");
//	cin >> number;
//	return number;
//}
//
//enPrimeOrNotPrime checkNumberPrime(int num)
//{
//	int m = (int)round(num / 2);
//	for (int i = 2; i <= m; i++)
//	{
//		if (num % i == 0)
//			return enPrimeOrNotPrime::NotPrime;
//	}
//	return enPrimeOrNotPrime::Prime;
//}
//
//void PrintPrimeORNotPrime(int num)
//{
//	switch (checkNumberPrime(num))
//	{
//	case enPrimeOrNotPrime::Prime :
//		MessageOnScreen("Prime");
//		break;
//	case enPrimeOrNotPrime::NotPrime:
//		MessageOnScreen("Not Prime");
//		break;
//	}
//}
#pragma endregion


#pragma region Problem 39 => (struct , 2 Functions)
//struct stInvoice
//{
//	double totalBill, cachePaid;
//};
//
//stInvoice ReadTotalBillAndCachePaid()
//{
//	stInvoice invoice;
//
//	MessageOnScreen("Please Enter Total Bill?");
//	cin >> invoice.totalBill;
//
//	MessageOnScreen("Please Enter Cache Paid?");
//	cin >> invoice.cachePaid;
//
//	return invoice;
//}
//
//double CalculateRemainder(stInvoice invoice)
//{
//	double remainder = 0.00;
//	if (invoice.cachePaid > invoice.totalBill)
//	{
//		remainder = invoice.cachePaid - invoice.totalBill;
//	}
//	return remainder;
//}
#pragma endregion


#pragma region Problem 40 => (2 Function)
//double ReadBillValue()
//{
//	double billValue;
//	MessageOnScreen("Enter Bill Value ?");
//	cin >> billValue;
//	return billValue;
//}
//
//double CalculateTotalBillAfterChargesServicesAndSalesTax(double totalBill)
//{
//	totalBill = totalBill * 1.1;
//	totalBill = totalBill * 1.16;
//
//	return totalBill;
//}
#pragma endregion


#pragma region Problem 41 => (struct 2 Functions)
//struct stWeeksAndDaysAndHoursAndMinutesAndSeconds
//{
//	double numberOfWeeks, numberOfDays, numberOfHours, numberOfMinutes, numberOfSeconds;
//};
//
//stWeeksAndDaysAndHoursAndMinutesAndSeconds  ReadNumberOfHours()
//{
//	stWeeksAndDaysAndHoursAndMinutesAndSeconds wDHMS;
//	MessageOnScreen("Enter Number Of Hours ?");
//	cin >> wDHMS.numberOfHours;
//	return wDHMS;
//}
//
//stWeeksAndDaysAndHoursAndMinutesAndSeconds
//CalculateTheNumberOfWeeksAndDaysInThatNumberOFHours(stWeeksAndDaysAndHoursAndMinutesAndSeconds wDHMS)
//{
//	 wDHMS.numberOfWeeks = 24 * 7,
//		wDHMS.numberOfDays = wDHMS.numberOfHours / 24,
//		wDHMS.numberOfWeeks = wDHMS.numberOfHours / wDHMS.numberOfWeeks;
//	return wDHMS;
//}
#pragma endregion


#pragma region Problem 42 => (3 Function)
//double ReadPositiveNumber(string message)
//{
//	double number;
//	do
//	{
//		MessageOnScreen(message);
//		cin >> number;
//	} while (number <= 0);
//
//	return number;
//}
//
//stWeeksAndDaysAndHoursAndMinutesAndSeconds ReadNumberOfDaysAndHoursAndMinutesAndSeconds()
//{
//	stWeeksAndDaysAndHoursAndMinutesAndSeconds wDHMS;
//	 wDHMS.numberOfDays = ReadPositiveNumber("Enter Number Of Days ?");
//	 wDHMS.numberOfHours = ReadPositiveNumber("Enter Number Of Hours ?");
//	 wDHMS.numberOfMinutes =  ReadPositiveNumber("Enter Number Of Minutes ?");
//	 wDHMS.numberOfSeconds = ReadPositiveNumber("Enter Number Of Seconds ?");
//
//	return wDHMS;
//}
//
//double CalculateDurationInSeconds(stWeeksAndDaysAndHoursAndMinutesAndSeconds wDHMS)
//{
//	return (wDHMS.numberOfDays  * 24 * 60 * 60) + 
//		(wDHMS.numberOfHours  * 60 * 60) + 
//		(wDHMS.numberOfMinutes * 60) + wDHMS.numberOfSeconds;
//}
#pragma endregion


#pragma region Problem 43 => (enum , Function)
//enum CalculateSeconds
//{
//	secondsOfMinutes = 60 , 
//	secondsOfHours = 3600 ,
//	secondsOfDays = 86400  
//};
//
//stWeeksAndDaysAndHoursAndMinutesAndSeconds CalculateSecondsTo_Days_Hours_Minutes_Seconds(int totalSeconds)
//{
//	stWeeksAndDaysAndHoursAndMinutesAndSeconds wDHMS;
//	int Remainder;
//
//	wDHMS.numberOfDays = totalSeconds / CalculateSeconds::secondsOfDays;
//
//	Remainder = totalSeconds % CalculateSeconds::secondsOfDays;
//
//	wDHMS.numberOfHours = Remainder / CalculateSeconds::secondsOfHours;
//
//	Remainder = Remainder % CalculateSeconds::secondsOfHours;
//
//	wDHMS.numberOfMinutes = Remainder / CalculateSeconds::secondsOfMinutes;
//
//	Remainder = Remainder % CalculateSeconds::secondsOfMinutes;
//
//	wDHMS.numberOfSeconds = Remainder;
//
//	return wDHMS;
//}
#pragma endregion


#pragma region Problem 44 => (Enum , Function , Procedure)
//enum DaysOfWeekInNumbers
//{
//	 SunDay		= 1,
//	 MonDay		= 2,
//	 TuesDay	= 3,
//	 WednesDay	= 4,
//	 ThursDay	= 5,
//	 FriDay		= 6,
//	 SatrDay	= 7
//};
//
//int ReadNumberDay() {
//	int number = 0;
//
//	do
//	{
//		MessageOnScreen("Enter Number The Day ?");
//		cin >> number;
//		(number <= 0 || number > 7) ? MessageOnScreen("Wrong Day Number") : MessageOnScreen("");
//		
//	} while (number <= 0 || number > 7);
//
//	return number;
//
//}
//
//void PrintNameDayAgainstNumber(int numberDay)
//{
//	switch (numberDay)
//	{
//	case DaysOfWeekInNumbers::SunDay:
//		cout << "SunDay" << endl;
//		break;
//	case DaysOfWeekInNumbers::MonDay:
//		cout << "MonDay" << endl;
//		break;
//	case DaysOfWeekInNumbers::TuesDay:
//		cout << "TuesDay" << endl;
//		break;
//	case DaysOfWeekInNumbers::WednesDay:
//		cout << "WednesDay" << endl;
//		break;
//	case DaysOfWeekInNumbers::ThursDay:
//		cout << "ThursDay" << endl;
//		break;
//	case DaysOfWeekInNumbers::FriDay:
//		cout << "FriDay" << endl;
//		break;
//	case DaysOfWeekInNumbers::SatrDay:
//		cout << "SatrDay" << endl;
//		break;
//	}
//}
#pragma endregion


#pragma region Problem 45 => (Enum , Function , Procedure)
//enum Months
//{
//
//	January		= 1,
//	February	= 2,
//	March		= 3,
//	April		= 4,
//	May			= 5,
//	June		= 6,
//	July		= 7,
//	August		= 8,
//	September	= 9,
//	October		= 10,
//	November	= 11,
//	December	= 12
//};
//
//int ReadNumberMonth() {
//	int number = 0;
//
//	do
//	{
//		MessageOnScreen("Enter Number The Month ?");
//		cin >> number;
//		(number <= 0 || number > 12) ? MessageOnScreen("Wrong Month Number") : MessageOnScreen("");
//
//	} while (number <= 0 || number > 12);
//
//	return number;
//
//}
//
//void PrintNameMonthAgainstNumber(int numberMonth)
//{
//	switch (numberMonth)
//	{
//	case Months::January:
//		cout << "January" << endl;
//		break;
//	case Months::February:
//		cout << "February" << endl;
//		break;
//	case Months::March:
//		cout << "March" << endl;
//		break;
//	case Months::April:
//		cout << "April" << endl;
//		break;
//	case Months::May:
//		cout << "May" << endl;
//		break;
//	case Months::June:
//		cout << "June" << endl;
//		break;
//	case Months::July:
//		cout << "July" << endl;
//		break;
//	case Months::August:
//		cout << "August" << endl;
//		break;
//	case Months::September:
//		cout << "Septembe" << endl;
//		break;
//	case Months::October:
//		cout << "October" << endl;
//		break;
//	case Months::November:
//		cout << "November" << endl;
//		break;
//	case Months::December:
//		cout << "December" << endl;
//		break;
//	}
//}
#pragma endregion


#pragma region Problem => 46 (Procedure)
//void PrintFromAToZ()
//{
//	for (int i = 65; i <= 90; i++)
//	{
//		cout << (char)i << " , ";
//	}
//}
#pragma endregion


#pragma region Problem => 47 (2 Functions)

//float ReadPositiveNumber(string message)
//{
//	float number;
//	do
//	{
//		MessageOnScreen(message);
//		cin >> number;
//	} while (number <= 0);
//
//	return number;
//}
//
//float calculateNumberMonthRepayAmount(float loanAmount, float monthlyPayment)
//{
//	return loanAmount / monthlyPayment;
//}
#pragma endregion


#pragma region Problem => 48 (2 Functions)

//float ReadPositiveNumber(string message)
//{
//	float number;
//	do
//	{
//		MessageOnScreen(message);
//		cin >> number;
//	} while (number <= 0);
//
//	return number;
//}
//
//float CalculateMonthlyInstallmentEveryMonth(float loanAmount, float howManyMonths)
//{
//	return loanAmount / howManyMonths;
//}
#pragma endregion


#pragma region Problem => 49 (2 Functions)
//string ReadPinCode()
//{
//	string pinCode;
//	MessageOnScreen("Enter Please Pin Code ?");
//	cin >> pinCode;
//	return pinCode;
//}
//
//bool Login()
//{
//	string pinCode;
//
//	do
//	{
//		pinCode = ReadPinCode();
//		if (pinCode == "1234")
//			return true;
//		else
//		{
//			MessageOnScreen("Wrong PIN");
//			system("color 4F");
//		}
//	} while (pinCode != "1234");
//
//	return false;
//}
#pragma endregion


#pragma region Problem => 50 (2 Functions)
//string ReadPinCode()
//{
//	string pinCode;
//	MessageOnScreen("Enter Please Pin Code ?");
//	cin >> pinCode;
//	return pinCode;
//}
//
//bool Login()
//{
//	string pinCode;
//	int counter = 3;
//
//	do
//	{
//		counter--;
//		pinCode = ReadPinCode();
//
//		if (pinCode == "1234")
//			return true;
//		else
//		{
//			cout << "Wrong PIN, You Have " << counter << " More Tries" << endl;
//			system("color 4F");
//		}
//	} while (pinCode != "1234" && counter >= 1);
//
//	return false;
//}
#pragma endregion




int main()
{
#pragma region Problem 1 
	/* Write a Program To Print Your Name On Screen */

	/*cout << "The Problem 1 : Print Your Name" << endl;
	PrintYourName();*/
#pragma endregion


#pragma region Problem 2
	/* Write a Program To ask The User To Enter his/her Name And Print It On Screen */

	 //PrintYourName(ReadYourName()); 
#pragma endregion


#pragma region Problem 3
	/* Write a program To Ask The User To Enter a Number ,
	Then Print "ODD" If Its odd Or "EVEN" If its even */

	//PrintNumberType(checkNumberType(ReadNumber()));
#pragma endregion


#pragma region Problem 4
	/* Write a program To Ask The User To Enter a (Age , Driver License) ,
	Then Print "Hired" If Grater Then The Age 21 And Driver License = True ,
	Otherwise Print "Regected" */


	/*MessageOnScreen("The Problem 4 : Enter => (Age , Driver License) ?");

	Print_Hired_OR_Regected(ReadInfo());*/
#pragma endregion


#pragma region Problem 5
	/* Write a program To Ask The User To Enter a (Age , Driver License , HasRecommendation) ,
	Then Print "Hired" If Grater Then The (Age 21 And Driver License = True) OR (HasRecommendation = True),
	Otherwise Print "Regected" */

	/*MessageOnScreen("The Problem 5 : Enter => (Age , Driver License , HasRecommendation) ?");

	Print_Hired_OR_Regected(ReadInfo());*/
#pragma endregion


#pragma region Problem 6
	/* Write a program To Ask The User To Enter a First Name , Last Name
	Then Print FullName On Screen */

	/*MessageOnScreen("The Problem 6 : Enter (First Name , Last Name) ?");
	PrintFullName(GetFullName(ReadFullName()));*/
#pragma endregion


#pragma region Problem 7
	/* Write a program To Ask The User To Enter a Number
	Then Print Half Of The Number */
	/*MessageOnScreen("The Problem 7");
	PrintHalfIsNumber(ReadNumber());*/
#pragma endregion


#pragma region Problem 8
	/* Write a program To Ask The User To Enter a Mark
	Then Print "Pass" If Mark >= 50 , Otherwise Print "Fail" */

	/*MessageOnScreen("The Problem 8");
	PrintPassOrFailTheMark(ReadMark());*/
#pragma endregion


#pragma region Problem 9
	/* Write a program To Ask The User To Enter a (Num1 , Num2 , Num3)
	Then Print Sum Numbers (Num1 , Num2 , Num3) */

	/*MessageOnScreen("The Problem 9");
	PrintNumberSum(ReadNumbers());*/
#pragma endregion


#pragma region Problem 10
	/* Write a program To Ask The User To Enter a (Mark1 , Mark2 , Mark3)
	Then Print Average Marks */

	/*MessageOnScreen("The Problem 10:");

	PrintAverageMarks(ReadMarks());*/
#pragma endregion


#pragma region Problem 11
	/* Write a program To Ask The User To Enter a (Mark1 , Mark2 , Mark3)
	Then Print The Average Marks Of Entered Marks , and Print "Pass" IF Average >= 50 ,
	Otherwise Print "Fail" */

	/*MessageOnScreen("The Problem 11:");

	stMarks marks = ReadMarks();

	PrintAverageMarks(marks);

	PrintPassOrFailForMarks(marks);*/
#pragma endregion


#pragma region Problem 12
	/* Write a program To Ask The User To Enter a (Num1 , Num2)
	Then Print The Max Number */

	/*MessageOnScreen("The Problem 12:");
	int num1, num2;
	ReadTwoNumber(num1, num2);

	PrintMaxNumber(GetMax2Number(num1, num2));*/
#pragma endregion


#pragma region Problem 13
	/* Write a program To Ask The User To Enter a (Num1 , Num2 , Num3)
	Then Print The Max Number */

	/*MessageOnScreen("The Problem 13:");
	int inputNum1, inputNum2, inputNum3;

	ReadThreeNumber(inputNum1 , inputNum2 , inputNum3);
;
	PrintMaxNumber(GetMax3Number(inputNum1, inputNum2, inputNum3));*/
#pragma endregion


#pragma region Problem 14
	/* Write a program To Ask The User To Enter a (Num1 , Num2)
	Then Print The Two Number , Then Swap The Two Number And Print Them */

	/*MessageOnScreen("The Problem 14 :");
	int inputNum1,inputNum2;

	Read2Number(inputNum1 , inputNum2);

	Print2Number(inputNum1, inputNum2);

	Swap2Number(inputNum1, inputNum2);

	Print2Number(inputNum1, inputNum2);*/
#pragma endregion


#pragma region Problem 15
	/* Write a program To Ask The User To Enter a (height  , width)
	Calculate Rectangle Area And Print It On The Screen */

	/*MessageOnScreen("the problem 15 :");

	PrintRectangleArea(ReadWidthAndHeight());*/
#pragma endregion


#pragma region Problem 16
	/* Write a program To Ask The User To Enter a (height  , diagonal)
	Calculate Rectangle Area Through diagonal And Side Area Of Rectangle And
	Print It On The Screen And Print It On The Screen .
	Law => (height x sqrt( (diagonal x diagonal) - (height x height) ) ) */

	/*MessageOnScreen("the problem 16 :");

	PrintRectangleAreaThroughDiagonal(ReadHeightAndDiagonal());*/
#pragma endregion


#pragma region Problem 17
	/* Write a program To Ask The User To Enter a (height  , Triangle Rule)
	Calculate Triangle Area Then Print It On The Screen.
	Law => (1/2 TriangleRule *  height) */

	/*MessageOnScreen("The Problem 17 :");

	PrintTriangleArea(ReadHeightAndTriangleRule());*/
#pragma endregion


#pragma region Problem 18  
	/* Write a program To Ask The User To Enter a (Distance)
	Calculate Circle Area By Radius Then Print It On The Screen.
	Law => (π * (Distance * Distance) ) */

	/*MessageOnScreen("The Problem 18 :");

	PrintTriangleArea(ReadCircleDistance());*/
#pragma endregion


#pragma region Problem 19 
	/* Write a program To Ask The User To Enter a (Diameter)
	Calculate the area of a circle in full diameter  Then Print It On The Screen.
	Law => (π * (Diameter * Diameter) / 4 ) */

	/*MessageOnScreen("The Problem 19 :");

	PrintAreaCircleFullDiameter(ReadCircleDiameter());*/
#pragma endregion


#pragma region Problem 20 
	/* Write a program To Ask The User To Enter a (Square Side )
	Calculate circle area inscribed in square Then Print It On The Screen.
	Law => (π * ( (Square Side * Square Side) /  (2 * 2) ) ) */

	/*MessageOnScreen("The Problem 20 :");

	PrintCircleAreaInscribedInSquare(ReadSquareSide());*/
#pragma endregion


#pragma region Problem 21 
	/* Write a program To Ask The User To Enter a ( Length Perimeter )
	Calculate circle area along the circumference, Then Print It On The Screen.
	Law =>  (Length Perimeter * Length Perimeter) /  (π * 4)  */

	/*MessageOnScreen("The Problem 21 :");

	PrintCircleAreaAlongCircumference(ReadLengthPerimeter());*/
#pragma endregion


#pragma region Problem 22
	/* Write a program To Ask The User To Enter a ( Side height of triangle , Triangle rule )
	Calculate circle area Inscribed In an Isosceles Triangle, Then Print It On The Screen.
	Law =>  ( π * ((Triangle rule * Triangle rule) / 4) * (( (2 * Side height of triangle) - Triangle rule ) /
	( (2 * Side height of triangle) + Triangle rule ))  */

	/*MessageOnScreen("The Problem 22 :");

	PrintCalculateCircleAreaInscribedInIsoscelesTriangle(ReadSideHeightTriangleAndTriangleRule());*/
#pragma endregion


#pragma region Problem 23
	/* Write a program To Ask The User To Enter a ( rib1 , rib2 , rib3 )
	Calculate circle area circle Described around an Arbitrary Triangle, Then Print It On The Screen.
	Law =>
	Step1 => P = ((rib1 + rib2 + rib3) / 2)
	Step2 =>  (rib1 * rib2 * rib3) / (4 * sqrt(P * (P - rib1) * (P - rib2) * (P - rib3)) )
	ٍStep3 => multiplied by the result by itself
	Step4 => (result Step3 * π)  */

	/*MessageOnScreen("The Problem 23 :");

	PrintCalculateCircleAreaCircleDescribedAroundArbitraryTriangle(ReadThreeRibs());*/
#pragma endregion


#pragma region Problem 24
	/* write a program to ask the user to enter a (age)
	if age is between 18 and 45 print "valid age" , otherwise print "invalid age" */

	/*MessageOnScreen("The Problem 24 :");
	PrintValidTheAgeORNotValid(ReadAge());*/
#pragma endregion


#pragma region Problem 25
	/* write a program to ask the user to enter a (age)
	if age is between 18 and 45 print "valid age" , otherwise print "invalid age"
	and return ask User To Enter a Valid Age
	Notes: You Should Keep Asking User To Enter a Valid Age Until Enters IT*/

	/*MessageOnScreen("The Problem 25 :");
	PrintValidTheAgeORNotValid(CheckEnterValidTheAge());*/
#pragma endregion


#pragma region Problem 26
	/* write a program to ask the user to enter a (N)
	Print Numbers From 1 To N */

	/*MessageOnScreen("The problem 26");

	PrintNumbersFrom1ToN(ReadNumber());*/
#pragma endregion


#pragma region Problem 27
	/* write a program to ask the user to enter a (N)
	Print Numbers From N To 1 */

	/*MessageOnScreen("The problem 27");

	PrintNumbersFromNTo1(ReadNumber());*/
#pragma endregion


#pragma region Problem 28
	/* write a program Sum "ODD" to ask the user to enter a (N)
	Print Numbers From 1 To N */

	/*MessageOnScreen("The problem 28");
	PrintSumOddNumbers(CalculateSumOddNumbers(ReadNumber()));*/
#pragma endregion


#pragma region Problem 29
	/* write a program Sum "EVEN" to ask the user to enter a (N)
	Print Numbers From 1 To N */

	/*MessageOnScreen("The problem 29");
	PrintSumEvenNumbers(CalculateSumEvenNumbers(ReadNumber()));*/
#pragma endregion


#pragma region Problem 30
	/* write a program To Calculate "Factorial" OF N! */

	/*MessageOnScreen("The problem 30:");
	PrintFactorialNumber(ReadPositiveNumber());*/
#pragma endregion


#pragma region Problem 31
	/* write a program To Ask The User To Enter Number ,
	Then Print The (Number ^2 , Number ^3 , Number ^4) */

	/*MessageOnScreen("The Problem 31 :");

	PowerOf_2_3_4(ReadNumber());*/
#pragma endregion


#pragma region Problem 32
	/* write a program To Ask The User To Enter ("Number" , "M") Power Number ^ M  */

	//int inputNumber, inputM;
	//ReadNumberAndPowerNumber(inputNumber, inputM);
	//PrintPowerOFN(CalculatePowerNumber(inputNumber, inputM));
#pragma endregion


#pragma region Problem 33
	/* write a program To Ask The User To Enter ("Grade")
	Then Print The Grade as Follows :
	* 90 - 100 Print A
	* 80 - 89 Print B
	* 70 - 79 Print C
	* 60 - 69 Print D
	* 50 - 59 Print E
	* Otherwise Print F
	*/

	/*MessageOnScreen("The problem 33");
	cout << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;*/
#pragma endregion


#pragma region Problem 34
	/* write a program To Ask The User To Enter ("Total Sales")
	The Commission is calculate as one precentage * The total sales ,
	all you need is to decide which precentage to use of the following

	> 1000,000		=> Precentage 1%
	> 500 To 1M		=> Precentage 2%
	> 100K To 500K	=> Precentage 3%
	> 50K To 100K	=> Precentage 5%
	> Othewise		=> Precentage 0%
	*/

	/*int totalSales = ReadTotalSales();
	float precentage = GetCommissionPercentage(totalSales);
	MessageOnScreen(to_string(calculateTotalCommission(totalSales)));*/
#pragma endregion


#pragma region Problem 35
	/* write a program To Ask The User To Enter ('Pennies , Nickels , Dimes , Quarter , Dollars')
	Then Calculate the Total Pennies / Toal Dollars and Print Them on Screen */

	/*MessageOnScreen("The Problem 35");

	float totalPennies = CalaculateTotalPennies(ReadMoneyCategories());

	MessageOnScreen("Total Pennies = " + to_string(totalPennies));
	MessageOnScreen("Total Dolars = " + to_string(CalaculateTotalDollars(totalPennies)));*/
#pragma endregion


#pragma region Problem 36
	/* write a program To Ask The User To Enter ('Number1 , Number2 , 'Type Operation')
	Then Per From The Calculate according to the operation type follows ('+' , '-' , '*' , '/' ) */

	/*MessageOnScreen("The Problem 36:");
	Calculate(ReadNumbers());*/
#pragma endregion


#pragma region Problem 37
	/* write a program ask The user To Enter (Number)
	To Read Numbers From User and sum Them ,
	Keep reading 'Until' the user Enter -99 Then Print The Summ On Screen */

	/*MessageOnScreen("The Problem 37");

	int result = SumNumbersUntil_99(ReadNumber());
	cout << "Result = " << result << endl;*/
#pragma endregion


#pragma region Problem 38
	/* write a program ask The user To Enter (Number)
	To Read a Number and Check it is a 'Prime Number' Or Not Prime
	Notes : Prime Number Can Only  Divide On One and On Itself Then Print Prime Or Not Prime */

	/*MessageOnScreen("The problem 38 :");

	PrintPrimeORNotPrime(ReadNumber());*/
#pragma endregion


#pragma region Problem 39
	/* write a program ask The user To Enter (cache Paid)
	To Read a 'Total Bill' and 'Cach Paid' And Calculate The Remainder To Be 'Paid Back'  */

	/*MessageOnScreen("The problem 39");
	MessageOnScreen("Remainder = " + to_string(CalculateRemainder(ReadTotalBillAndCachePaid())));*/

#pragma endregion


#pragma region Problem 40
	/* Arestaurant Charges (10%) Services Feed and (16%) Sales Tax */

	/* write a program ask The user To Enter (Bill Value)
	To Read a 'Bill Value' and add Service Fee and Sales Tax , And Print The Total Bill On The Screen */

	/*MessageOnScreen("Problem 40 :");
	MessageOnScreen("Charges Services => (10%)");
	MessageOnScreen("Sales Tax => (16%)");

	MessageOnScreen("Calculate Total Bill After Charges Services And Sales Tax = " +
		to_string(CalculateTotalBillAfterChargesServicesAndSalesTax(ReadBillValue())) );*/

#pragma endregion


#pragma region Problem 41
	/* write a program ask The user To Enter (Number Of Hours)
	To Read a Number OF Hours and Calculate The Number Of Weeks and Days In That Number */

	/*MessageOnScreen("The Problem 41:");

	stWeeksAndDaysAndHoursAndMinutesAndSeconds wDHMS =
	CalculateTheNumberOfWeeksAndDaysInThatNumberOFHours(ReadNumberOfHours());
	cout << "Number Of Weeks = " << wDHMS.numberOfWeeks << endl << "Number Of Days = " << wDHMS.numberOfDays << endl;*/


#pragma endregion


#pragma region Problem 42
	/* write a program ask The user To Enter (Number Of Days , Number Of Hours , Number Of Minutes , Number Of Seconds)
	To Calculate The Task Duration In Seconds And Print It On Screen Given
	The Time Duration Of a Task In The Number Of Days , Hours , Minutes , Seconds */

	/*MessageOnScreen("The Problem 42: ");
	cout << "Total Seconds = " << round(CalculateDurationInSeconds(ReadNumberOfDaysAndHoursAndMinutesAndSeconds())) << endl;*/
#pragma endregion


#pragma region Problem 43
	/* write a program That Inputs The Number Of "Seconds" and Changes It To Days (Hours , Minutes , Seconds) */

	/*stWeeksAndDaysAndHoursAndMinutesAndSeconds wDHMS =
	CalculateSecondsTo_Days_Hours_Minutes_Seconds(ReadPositiveNumber("Enter Total Seconds ?"));

	cout
	<< "Number Of Days	  : " << round(wDHMS.numberOfDays) << endl
	<< "Number Of Hours	  : " << round(wDHMS.numberOfHours) << endl
	<< "Number Of Minutes : " << round(wDHMS.numberOfMinutes) << endl
	<< "Number Of Seconds : " << round(wDHMS.numberOfSeconds) << endl;*/
#pragma endregion


#pragma region Problem 44
	/* write a program To ask  The User Enter (Number Day)
	Then Print The Day as Follows :
		1 Print 'SunDay'
		2 Print 'MonDay'
		3 Print 'TuesDay'
		4 Print 'WednesDay'
		5 Print 'ThursDay'
		6 Print 'FriDay'
		7 Print 'SatrDay'
		Otherwise Print 'Wrong Day' and Ask The User To Enter 'Day' Again
	*/

	/*MessageOnScreen("The Problem 44:");
	PrintNameDayAgainstNumber(ReadNumberDay());*/


#pragma endregion


#pragma region Problem 45
	/* write a program To ask  The User Enter (Number Month)
	Then Print The Day as Follows :
		1 Print		'January'
		2 Print		'February'
		3 Print		'March'
		4 Print		'April'
		5 Print		'May'
		6 Print		'June'
		7 Print		'July'
		8 Print		'August'
		9 Print		'September'
		10 Print	'October'
		11 Print	'November'
		12 Print	'December'
		Otherwise Print 'Wrong Month' and Ask The User To Enter 'Month' Again
	*/

	/*MessageOnScreen("The Problem 45 :");
	PrintNameMonthAgainstNumber(ReadNumberMonth());*/

#pragma endregion


#pragma region Problem 46
	/* write a program To Print All Letters From (A To Z) */

	/*MessageOnScreen("The Problem 46");
	PrintFromAToZ();*/

#pragma endregion


#pragma region Problem 47
	/* write a program To Read a 'Loan Amount' and 'Monthly Payment' and
	calculate How Many Monthly You Need To Settle The Loan */

	/*MessageOnScreen("The Problem 47");
	float leaonAmount = ReadPositiveNumber("Please Enter Loan Amount ?");
	float monthlyInstallment =  ReadPositiveNumber("Please Enter Monthly Installment ?");

	cout << "Total Months = " << calculateNumberMonthRepayAmount(leaonAmount , monthlyInstallment) << endl;*/

#pragma endregion


#pragma region Problem 48
	/* write a program To Read a 'Loan Amount' and 'Number Of Months To Pay' and
	calculate How Many Monthly You Need To Settle The Loan */

	/*MessageOnScreen("The Problem 48");
	float leaonAmount = ReadPositiveNumber("Please Enter Loan Amount ?");
	float howManyMonths = ReadPositiveNumber("Please Enter Number How Many Months ?");

	cout << "Monthly Installment Every Month = "
		<< CalculateMonthlyInstallmentEveryMonth(leaonAmount, howManyMonths)
		<< endl;*/

#pragma endregion


#pragma region Problem 49
	/* write a program To Read The (ATM Pin Code) Form The User, Then Check If 'PIN CODE = 1234',
	Then Show The Balance To User OtherWise Prin 'Wrong PIN CODE', and ask User To Enter The PIN Again */

	/*MessageOnScreen("The Problem 49:");
	if (Login())
	{
		system("color 2F");
		cout << "Your Account Balance Is = " << 7500 << endl;
	}*/

#pragma endregion


#pragma region Problem 50
	/* write a program To Read The (ATM Pin Code) Form The User, Then Check If 'PIN CODE = 1234',
	Then Show The Balance To User OtherWise Prin 'Wrong PIN CODE', and ask User To Enter The PIN Again and
	Only Allow User To Enter The 'PIN CODE 3 Times' If Fail , Print 'Card is Locked'*/

	/*MessageOnScreen("The Problem 50:");
	if (Login())
	{
		system("color 2F");
		cout << "Your Account Balance Is = " << 7500 << endl;
	}
	else
	{
		cout << "Your Card Blocked Call The Bank For Help" << endl;
	}*/

#pragma endregion

}