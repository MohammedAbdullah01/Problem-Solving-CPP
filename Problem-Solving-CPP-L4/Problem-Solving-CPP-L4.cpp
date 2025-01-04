#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <ctime>

using namespace std;

#pragma region structs
struct stDate
{
	short Year,
		Month,
		Day;
};
struct stPeriod
{
	stDate DateStart;
	stDate DateEnd;
};


#pragma endregion

#pragma region Enums
enum enNumberOfDaysPerMonth
{
	January = 1, February, March, April, May, June, July, August, September,
	October, November, December
};

enum enDateCompare
{
	Before = -1 , Equal, After
};
#pragma endregion

#pragma region Defined Function
short howManyDaysInMonth(short year, enNumberOfDaysPerMonth month);
bool validateDate(stDate date);
#pragma endregion

#pragma region Helper Function

void PrintMessageOnScreen(string msg)
{
	cout << msg << endl;
}

char ReadCharacter(string msg)
{
	char charcter;
	cout << msg;
	cin >> charcter;
	return charcter;
}

string ReadWords(string msg)
{
	string name;
	cout << msg;
	getline(cin >> ws, name);
	return name;
}

string ReadWord(string msg)
{
	string name;
	cout << msg;
	cin >> name;
	return name;
}

int ReadNumberInteger(string msg)
{
	int number;
	cout << msg;
	cin >> number;
	return number;
}

float ReadNumberFloat(string msg)
{
	float number;
	cout << msg;
	cin >> number;
	return number;
}

string ReadFullName()
{
	string fullName;

	fullName = ReadWord("Please Enter First Name ?");

	fullName += " " + ReadWord("Please Enter Last Name ?");

	return fullName;
}

int ReadPositiveNumber(string msg)
{
	int number;
	do
	{
		number = ReadNumberInteger(msg);
	} while (number <= 0);

	return number;
}

int ReadNumberInRange(int from, int to , string msg)
{
	int number;
	do
	{
		number = ReadNumberInteger(msg + " (" + to_string(from) + " => " + to_string(to) + ") ? ");
	} while (number < from || number > to);

	return number;
}

int ReadNumberWithValidate(string msg)
{
	int number;
	cout << msg << endl;
	cin >> number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter valid Number:";
		cin >> number;
	}
	return number;
}

float ReadPositiveFloatNumber(string msg)
{
	float number;
	do
	{
		number = ReadNumberFloat(msg);
	} while (number <= 0);

	return number;
}

vector<string> SplitEachWordInVector(string str, string delimter = " ")
{
	vector<string> VWords;
	size_t position = 0;
	string word = "";

	while ((position = str.find(delimter)) != string::npos)
	{
		word = str.substr(0, position);
		if (!word.empty())
		{
			VWords.push_back(word);
		}
		str.erase(0, position + delimter.length());
	}

	if (!str.empty())
	{
		VWords.push_back(str);
	}

	return VWords;
}

#pragma endregion

#pragma region Problem 1 => (Function)
string numberToText(int number)
{
	if (number == 0)
	{
		return "";
	}

	if (number >= 1 && number <= 19)
	{
		string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
		"Eight", "Nine","Ten", "Eleven", "Twelve", "Thirteen",
		"Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen",
		"Nineteen" };

		return arr[number] ;
	}

	if (number >= 20 && number <= 99)
	{
		string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty",
		"Sixty", "Seventy", "Eighty", "Ninety" };

		return arr[number / 10] + " " + numberToText(number % 10);
	}

	if (number >= 100 && number <= 199)
	{
		return "One Hundred " + numberToText(number % 100);
	}

	if (number >= 200 && number <= 999)
	{
		return numberToText(number / 100) +  " Hundreds " + numberToText(number % 100);
	}

	if (number >= 1000 && number <= 1999)
	{
		return "One Thousand " + numberToText(number % 1000);
	}

	if (number >= 2000 && number <= 999999)
	{
		return numberToText(number / 1000) + " Thousands " + numberToText(number % 1000);
	}

	if (number >= 1000000 && number <= 1999999)
	{
		return "One Million " + numberToText(number % 1000000);;
	}

	if (number >= 2000000 && number <= 999999999)
	{
		return numberToText(number / 1000000) + " Millions " + numberToText(number % 1000000);
	}

	if (number >= 1000000000 && number <= 1999999999)
	{
		return "One Billion " + numberToText(number % 1000000000);
	}

	else
	{
		return numberToText(number / 1000000000) + " Billions " + numberToText(number % 1000000000);
	} 

}
#pragma endregion

#pragma region Problem 2 => (Function)
bool isLeapYear(short year) 
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
#pragma endregion

#pragma region Problem 3 => (4 Functions , Procedure)
short howManyDaysInYear(short year)
{
	return isLeapYear(year) ? 366 : 365 ;
}

short howManyHoursInYear(short year)
{
	return howManyDaysInYear(year) * 24 ;
}

int howManyMinutesInYear(short year)
{
	return howManyHoursInYear(year) * 60;
}

int howManySecondsInYear(short year)
{
	return howManyMinutesInYear(year) * 60;
}

void printNumberOfDaysHoursMinutesSeconds(short year)
{
	cout << "\nNumber Of Days\t\tIn Year [" << year << "] Is "
		<< howManyDaysInYear(year) << endl;

	cout << "Number Of Hours\t\tIn Year [" << year << "] Is "
		<< howManyHoursInYear(year) << endl;

	cout << "Number Of Minutes\tIn Year [" << year << "] Is "
		<< howManyMinutesInYear(year) << endl;

	cout << "Number Of Seconds\tIn Year [" << year << "] Is "
		<< howManySecondsInYear(year) << endl;
}
#pragma endregion

#pragma region Problem 4 => (Enum , 4 Function , Procedure)
short howManyDaysInMonth(short year ,enNumberOfDaysPerMonth month)
{
	switch (month)
	{
	case January :
	case March:
	case May:
	case July:
	case August:
	case October:
	case December:
		return 31;

	case February:
		return isLeapYear(year) ? 29 : 28;

	case April:
	case June:
	case September:
	case November:
		return 30;

	default:
		return 0;
	}
}

short howManyHoursInMonth(short year , enNumberOfDaysPerMonth month )
{
	return howManyDaysInMonth(year , month) * 24;
}

int howManyMinutesInMonth(short year , enNumberOfDaysPerMonth month)
{
	return howManyHoursInMonth(year , month) * 60;
}

int howManySecondsInMonth(short year, enNumberOfDaysPerMonth month)
{
	return howManyMinutesInMonth(year, month) * 60;
}

void printNumberOfDaysHoursMinutesSeconds(enNumberOfDaysPerMonth month , short year)
{
	cout << "\nNumber Of Days\t\tIn Month [" << month << "] Is "
		<< howManyDaysInMonth(year , month) << endl;

	cout << "Number Of Hours\t\tIn Month [" << month << "] Is "
		<< howManyHoursInMonth(year, month) << endl;

	cout << "Number Of Minutes\tIn Month [" << month << "] Is "
		<< howManyMinutesInMonth(year, month) << endl;

	cout << "Number Of Seconds\tIn Month [" << month << "] Is "
		<< howManySecondsInMonth(year, month) << endl;
}
#pragma endregion

#pragma region Problem 5 => (Enum , 3 Functions)
enum enDaysNameInWeek
{
	Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

string FormatDate(short year, short month, short day , char separator = '/')
{
	return to_string(day) + separator + to_string(month) + separator + to_string(year);
}

string getDayName(enDaysNameInWeek dayNumber)
{
	switch (dayNumber)
	{
	case Sunday:	return "Sunday";
	case Monday:	return "Monday";
	case Tuesday:	return "Tuesday";
	case Wednesday:	return "Wednesday";
	case Thursday:	return "Thursday";
	case Friday:	return "Friday";
	case Saturday:	return "Saturday";
	default:		return "Not Found Day";
	}
}

short dayOfWeekOrder(short year , short month , short day)
{
	short
		a = (14 - month) / 12,
		y = year - a,
		m = month + (12 * a) - 2,
		d = day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12);

	return (d % 7) + 1 ;

}

short dayOfWeekOrder(stDate date)
{
	return dayOfWeekOrder(date.Year, date.Month , date.Day);
}

#pragma endregion

#pragma region Problem 6 => (Function , Procedure)

string getMonthName(enNumberOfDaysPerMonth monthNumber)
{
	switch (monthNumber)
	{
	case January:	return "Jan";
	case February:	return "Feb";
	case March:		return "Mar";
	case April:		return "Apr";
	case May:		return "May";
	case June:		return "Jun";
	case July:		return "Jul";
	case August:	return "Aug";
	case September:	return "Sep";
	case October:	return "Oct";
	case November:	return "Nov";
	case December:	return "Dec";
	default:		return "Not Found Month";
	}
}

void printMonthCalendar(short year , short month)
{
	cout << "\n ___________________________" 
		<< getMonthName((enNumberOfDaysPerMonth)month)
		<< "___________________________\n\n";

	cout << setw(8) << "Sun" << setw(8) << "Mon" << setw(8) << "Tue" 
		<< setw(8) << "Wed" << setw(8) << "Thu" << setw(8) << "Fri" 
		<< setw(8) << "Sat" << setw(8) << "\n\n";

	short daysInMonth = howManyDaysInMonth(year, (enNumberOfDaysPerMonth)month);
	short firstDay = dayOfWeekOrder(year, month, 1);

	for (short i = 1; i < firstDay; ++i) {
		cout << setw(8) << "";
	}


	for (short day = 1; day <= daysInMonth; ++day)
	{
		cout << setw(8) << day;

		if ((firstDay + day - 1) % 7 == 0 && (day != daysInMonth)) {
			cout << endl << endl;
		}
	}
	cout << "\n _________________________________________________________\n";
}
#pragma endregion

#pragma region Problem 7 => (Procedure)
void printYearCalendar(short year) 
{
	cout << "\n__________________________________________________________\n"
		<< "\n\t\t\tCalemdar - " << year << "\n"
		<< "__________________________________________________________\n";
	for (short i = 1; i <= 12; i++)
	{
		printMonthCalendar(year , i);
	}
}
#pragma endregion

#pragma region Problem 8 => (Function)
short getTotalDaysFromBeginOfYear(short year , short month , short day)
{
	short sumDay = day;
	for (short i = 1; i < month; i++)
	{
		sumDay += howManyDaysInMonth(year, (enNumberOfDaysPerMonth)i);
	}
	return sumDay;
}

short getTotalDaysFromBeginOfYear(stDate date)
{
	short sumDay = date.Day;
	for (short i = 1; i < date.Month; i++)
	{
		sumDay += howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)i);
	}
	return sumDay;
}
#pragma endregion

#pragma region Problem 9 => (Function)
stDate convertFromTotalDaysToDate(short totalDay , short year)
{
	short daysInMonth;
	stDate date;
	string result = "";
	date.Year = year;
	for (short i = 1; i <= 12; i++)
	{
		date.Month = i;
		daysInMonth = howManyDaysInMonth(year, (enNumberOfDaysPerMonth)date.Month);

		if (daysInMonth >= totalDay)
		{
			date.Day = totalDay;
			break;
		}
		totalDay -= daysInMonth;
	}
	return date;
}
#pragma endregion

#pragma region Problem 10 => (Function)
stDate DateAddDays(short days, stDate date)
{
	short remainingDays = days + getTotalDaysFromBeginOfYear(date.Year, date.Month, date.Day);
	short monthDays = 0;

	date.Month = 1;

	while (true)
	{
		monthDays = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);

		if (remainingDays > monthDays)
		{
			remainingDays -= monthDays;
			date.Month++;

			if (date.Month > 12)
			{
				date.Month = 1;
				date.Year++;
			}
		}
		else
		{
			date.Day = remainingDays;
			break;
		}
	}
	return date;
}
#pragma endregion

#pragma region Problem 11 => (2 Function)
stDate ReadFullDate()
{
	stDate date;
	date.Day = ReadNumberInRange(1, 31, "please enter a Day ? ");
	date.Month = ReadNumberInRange(1, 12, "please enter a Month ? ");
	date.Year = ReadNumberInRange(1000, 3400, "please enter a Year ? ");

	cout << endl;

	/*if (!validateDate(date))
	{
		throw invalid_argument("The Date Is invalid.");
	}*/

	return date;
}

bool IsDate1BeforeDate2(stDate date1 , stDate date2)
{
	if (date1.Year < date2.Year) 
		return true;
	else if (date1.Year > date2.Year) 
		return false;

	if (date1.Month < date2.Month) 
		return true;
	else if (date1.Month > date2.Month) 
		return false;

	return date1.Day < date2.Day;
}
#pragma endregion

#pragma region Problem 12 => (Function)
bool IsDate1EqualDate2(stDate date1, stDate date2)
{
	return date1.Year == date2.Year && date1.Month == date2.Month && date1.Day == date2.Day;
}
#pragma endregion

#pragma region Problem 13  => (2 Function)
bool IsLastDayInMonth(stDate date)
{
	return date.Day == howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);
}

bool IsLastMonthInYear(short month)
{
	return month == 12;
}
#pragma endregion

#pragma region Problem 14 (2 Function)
stDate increaseDateByOneDay(stDate date)
{
	if (IsLastDayInMonth(date))
	{
		if (IsLastMonthInYear(date.Month))
		{
			date.Year++;
			date.Day = 1;
			date.Month = 1;
		}
		else
		{
			date.Day = 1;
			date.Month++;
		}
	}
	else 
	{
		date.Day++;
	}
	return date;
}
#pragma endregion

#pragma region Problem 15 => (Function)
void swapDates(stDate& date, stDate& date2)
{
	stDate temp = date;
	date = date2;
	date2 = temp;
}

int calculateDifferenceInDays(stDate date1  , stDate date2, bool IncludingEndDay = false)
{
	int days = 0;
	short swapFlagValue = 1;

	if (IsDate1EqualDate2(date1, date2))
		return ++days;

	if (!IsDate1BeforeDate2(date1, date2))
	{
		swapDates(date1, date2);
		swapFlagValue = -1;
	}

	while (IsDate1BeforeDate2(date1 , date2))
	{
		days++;
		date1 = increaseDateByOneDay(date1);
	}

	return IncludingEndDay ? ++days * swapFlagValue : days * swapFlagValue;
}
#pragma endregion

#pragma region Problem 16 => (Function)
stDate GetSystemDate()
{
	stDate date;
	time_t t = time(0);
	tm now;

	localtime_s(&now, &t);

	date.Year = now.tm_year + 1900;
	date.Month = now.tm_mon + 1;
	date.Day = now.tm_mday;

	return date;
}
#pragma endregion

#pragma region Problem 18 => (Function)
stDate IncreaseDateByXDays(stDate date ,  short addingDays)
{
	while (addingDays > 0) {
		date = increaseDateByOneDay(date);
		addingDays--;
	}
	return date;
}
#pragma endregion

#pragma region Problem 19 => (Function)
stDate IncreaseDateByOneWeek(stDate date)
{
	return IncreaseDateByXDays(date , 7);
}
#pragma endregion

#pragma region Problem 20 => (Function)
stDate IncreaseDateByXWeek(stDate date , short addingWeeks)
{
	return IncreaseDateByXDays(date, addingWeeks * 7);
}
#pragma endregion

#pragma region Problem 21 => (Function)
stDate IncreaseDateByOneMonth(stDate date)
{
	if (date.Month == 12)
	{
		date.Month = 1;
		date.Year++;
	}
	else
	{
		date.Month++;
	}

	short numberOfDaysInMonthCurrent = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);

	if (date.Day > numberOfDaysInMonthCurrent)
	{
		date.Day = numberOfDaysInMonthCurrent;
	}
	return date;
}
#pragma endregion

#pragma region Problem 22 => (Function)
/* 
*	Function 1 produces a more realistic result (28/5/2023), which aligns 
	with standard calendar behavior.

*	Input : 31/12/2022 , Add 5 Months
*	Result : (28/5/2023)
*/
stDate IncreaseDateByXMonth(stDate date , short addingMonths)
{
	for (short i = 1; i <= addingMonths; i++)
	{
		date = IncreaseDateByOneMonth(date);
	}
	return date;
}

/*
*	Function 2 produces an arguably less intuitive result (31/5/2023) but may 
	be better for specific use cases.

*	Input : 31/12/2022 , Add 5 Months
*	Result : (31/5/2023)
*/
stDate IncreaseDateByXMonths2(stDate date, short addingMonths) {
	date.Month += addingMonths;
	while (date.Month > 12) {
		date.Month -= 12;
		date.Year++;
	}
	int daysInMonth = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);
	if (date.Day > daysInMonth) {
		date.Day = daysInMonth;
	}
	return date;
}
#pragma endregion

#pragma region Problem 23 => (Function)
stDate IncreaseDateByOneYear(stDate date)
{
	date.Year++;
	short numberOfDaysInMonthCurrent = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);

	if (date.Day > numberOfDaysInMonthCurrent)
		date.Day = numberOfDaysInMonthCurrent;

	return date;
}
#pragma endregion

#pragma region Problem 24 => (Function)
stDate IncreaseDateByXYears(stDate date , short addingYears)
{
	for (short i = 1; i <= addingYears; i++)
	{
		date = IncreaseDateByOneYear(date);
	}
	return date;
}
#pragma endregion

#pragma region Problem 25 => (Function)
stDate IncreaseDateByXYearsFaster(stDate date , short addingYears)
{
	date.Year += addingYears;
	short numberOfDaysInMonthCurrent = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);

	if (date.Day > numberOfDaysInMonthCurrent)
		date.Day = numberOfDaysInMonthCurrent;

	return date;
}
#pragma endregion

#pragma region Problem 26 => (Function)
stDate IncreaseDateByOneDecade(stDate date)
{
	return IncreaseDateByXYearsFaster(date , 10);
}
#pragma endregion

#pragma region Problem 27 => (Function)
stDate IncreaseDateByXDecades(stDate date , short addingDecades)
{
	for (short i = 1; i <= addingDecades; i++)
	{
		date = IncreaseDateByXYearsFaster(date, 10);
	}
	return date;
}
#pragma endregion

#pragma region Problem 28 => (Function)
stDate IncreaseDateByXDecadesFaster(stDate date, short addingDecades)
{
	return IncreaseDateByXYearsFaster(date, 10 * addingDecades);
}
#pragma endregion

#pragma region Problem 29 => (Function)
stDate IncreaseDateByOneCentury(stDate date)
{
	return IncreaseDateByXYearsFaster(date, 100);
}
#pragma endregion
 
#pragma region Problem 30 => (Function)
stDate IncreaseDateByOneMillennium(stDate date)
{
	return IncreaseDateByXYearsFaster(date, 1000);
}
#pragma endregion

#pragma region Problem 31 => (Function)
stDate decreaseDateByOneDay(stDate date)
{
	if (date.Day == 1 && date.Month == 1)
	{
		date.Year--;
		date.Day = 31;
		date.Month = 12;
	}
	else if (date.Month <= 12 && date.Day == 1)
	{
		date.Month--;
		date.Day = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);
	}
	else
	{
		date.Day--;
	}

	return date;
}
#pragma endregion

#pragma region Problem 32 => (Function)
stDate decreaseDateByXDays(stDate date , short subtractDays)
{
	while (subtractDays > 0)
	{
		date = decreaseDateByOneDay(date);
		subtractDays--;
	}
	return date;
}
#pragma endregion

#pragma region Problem 33 => (Function)
stDate decreaseDateByOneWeek(stDate date)
{
	return decreaseDateByXDays(date, 7);
}
#pragma endregion

#pragma region Problem 34 => (Function)
stDate decreaseDateByXWeeks(stDate date , short subtractWeeks)
{
	return decreaseDateByXDays(date, subtractWeeks * 7);
}
#pragma endregion

#pragma region Problem 35 => (Function)
stDate decreaseDateByOneMonth(stDate date)
{
	if (date.Month == 1 )
	{
		date.Month = 12;
		date.Year--;
	}
	else
	{
		date.Month--;
	}

	short numberDaysInMonthCurrent = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);
	if (date.Day > numberDaysInMonthCurrent)
	{
		date.Day = numberDaysInMonthCurrent;
	}
	return date;
}
#pragma endregion

#pragma region Problem 36 => (Function)
stDate decreaseDateByXMonths(stDate date, short subtractMonths)
{
	while (subtractMonths > 0 )
	{
		date = decreaseDateByOneMonth(date);
		subtractMonths--;
	}
	return date;
}
#pragma endregion

#pragma region Problem 37 => (Function)
stDate decreaseDateByOneYear(stDate date)
{
	date.Year--;
	short daysInMonth = howManyDaysInMonth(date.Year , (enNumberOfDaysPerMonth) date.Month);

	if (date.Day > daysInMonth)
	{
		date.Day = daysInMonth;
	}
	return date;
}
#pragma endregion

#pragma region Problem 38 => (Function)
stDate decreaseDateByXYears(stDate date, short subtractYears)
{
	while (subtractYears > 0)
	{
		date = decreaseDateByOneYear(date);
		subtractYears--;
	}
	return date;
}
#pragma endregion

#pragma region Problem 39 => (Function)
stDate decreaseDateByXYearsFaster(stDate date , short subtractYears)
{
	date.Year -= subtractYears;
	short daysInMonth = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);

	if (date.Day > daysInMonth)
	{
		date.Day = daysInMonth;
	}
	return date;
}
#pragma endregion

#pragma region Problem 40 => (Function)
stDate decreaseDateByOneDecade(stDate date)
{
	return decreaseDateByXYearsFaster(date , 10);
}
#pragma endregion

#pragma region Problem 41 => (Function)
stDate decreaseDateByXDecades(stDate date, short subtractDecades)
{
	while (subtractDecades > 0)
	{
		date = decreaseDateByXYearsFaster(date , 10);
		subtractDecades--;
	}
	return date;
}
#pragma endregion

#pragma region Problem 42 => (Function)
stDate decreaseDateByXDecadesFaster(stDate date, short subtractDecades)
{
	return decreaseDateByXYearsFaster(date, subtractDecades * 10);
}
#pragma endregion

#pragma region Problem 43 => (Function)
stDate decreaseDateByOneCentury(stDate date)
{
	return decreaseDateByXYearsFaster(date, 100);
}
#pragma endregion

#pragma region Problem 44 => (Function)
stDate decreaseDateByOneMillennium(stDate date)
{
	return decreaseDateByXYearsFaster(date, 1000);
}
#pragma endregion

#pragma region Problem 45 => (Function)
bool IsEndOfWeek(stDate date) 
{
	return dayOfWeekOrder(date) == 7;
}
#pragma endregion

#pragma region Problem 46 => (Function)
bool IsWeekEnd(stDate date)
{
	return IsEndOfWeek(date) || dayOfWeekOrder(date) == 6;
}
#pragma endregion

#pragma region Problem 47 => (Function)
bool IsBusinessDay(stDate date)
{
	return !IsWeekEnd(date);
}
#pragma endregion

#pragma region Problem 48 => (Function)
short DaysUntilTheEndOfWeek(stDate date)
{
	return 7 - dayOfWeekOrder(date);
}
#pragma endregion

#pragma region Problem 49 => (Function)
short DaysUntilTheEndOfMonth(stDate date)
{
	return howManyDaysInMonth(date.Year , (enNumberOfDaysPerMonth) date.Month) - date.Day;
}
#pragma endregion

#pragma region Problem 50 => (Function)
short DaysUntilTheEndOfYear(stDate date)
{
	return IsLastMonthInYear(date.Month) ? DaysUntilTheEndOfMonth(date) :
		howManyDaysInYear(date.Year) -  getTotalDaysFromBeginOfYear(date);
}
#pragma endregion

#pragma region Problem 51 => (Function)
short howManyTheActualVacationDaysFromDate1ToDate2(stDate dateFrom , stDate dateTo)
{
	short ActualVacation = 0;
	while (IsDate1BeforeDate2(dateFrom, dateTo))
	{
		if (!IsWeekEnd(dateFrom))
		{
			ActualVacation++;
		}

		dateFrom = increaseDateByOneDay(dateFrom);
	}

	return ActualVacation;
}
#pragma endregion

#pragma region Problem 52 => (Function)
stDate vacationReturnDate(stDate dateFrom, short vacationDays)
{
	if (!validateDate(dateFrom))
		throw invalid_argument("Invalid start date provided.");

	stDate returnDate = dateFrom;
	while (vacationDays > 0 || IsWeekEnd(returnDate))
	{ 
		if (IsBusinessDay(returnDate))
			vacationDays--;

		returnDate = increaseDateByOneDay(returnDate);
	}

	if (!validateDate(returnDate))
		throw runtime_error("Resulting date is invalid.");

	return returnDate;
}
#pragma endregion 

#pragma region Problem 53 => (Function)
bool IsDate1AfterDate2(stDate date1 , stDate date2)
{
	return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2));
}
#pragma endregion

#pragma region Problem 54 => (Function)
enDateCompare CompareDates(stDate date1 , stDate date2)
{
	return IsDate1BeforeDate2(date1, date2) ? enDateCompare::Before
		: IsDate1AfterDate2(date1, date2) ? enDateCompare::After 
		: enDateCompare::Equal;
}
#pragma endregion

#pragma region Problem 55 => (3 Function)
bool IsOverlapPeriods(stPeriod period1 , stPeriod period2)
{
	if (!(validateDate(period1.DateStart) && validateDate(period1.DateEnd) &&
		validateDate(period2.DateStart) && validateDate(period2.DateEnd)))
	{
		throw invalid_argument("One or more provided dates are invalid.");
	}

	return (
		CompareDates(period2.DateEnd, period1.DateStart) 
		== enDateCompare::Before ||

		CompareDates(period2.DateStart, period1.DateEnd) 
		== enDateCompare::After) 
		? false 
		: true;
}

stPeriod ReadPeriod()
{
	stPeriod period;
	cout << "Enter Start Date :\n";
	period.DateStart = ReadFullDate();

	cout << "Enter End Date :\n";
	period.DateEnd = ReadFullDate();

	if (CompareDates(period.DateStart, period.DateEnd) == enDateCompare::After) {
		throw invalid_argument("Start date must not be after end date.");
	}

	return period;
}

vector<stDate> getDatesOverlapBetween2Periods(stPeriod period1, stPeriod period2)
{
	if (!IsOverlapPeriods(period1, period2)) {
		return {};
	}

	stDate overlapStart = CompareDates(period1.DateStart, period2.DateStart) 
		== enDateCompare::After ? period1.DateStart : period2.DateStart;

	stDate overlapEnd = CompareDates(period1.DateEnd, period2.DateEnd) 
		== enDateCompare::Before ? period1.DateEnd : period2.DateEnd;

	vector<stDate> datesOverlap;

	while (CompareDates(overlapStart, overlapEnd) != enDateCompare::After)
	{
		datesOverlap.push_back(overlapStart);
		overlapStart = increaseDateByOneDay(overlapStart);
	}

	return datesOverlap;
}
#pragma endregion

#pragma region Problem 56 => (Function)
short calculatePeriodLengthInDays(stPeriod period , bool includeEndDate = false)
{
	return calculateDifferenceInDays(period.DateStart, period.DateEnd, includeEndDate);
		
}
#pragma endregion

#pragma region Problem 57 => (Function)
bool isDateInPeriod(stPeriod period , stDate date)
{
	return (CompareDates(date, period.DateStart) != enDateCompare::Before) &&
		(CompareDates(date, period.DateEnd) != enDateCompare::After);
}
#pragma endregion

#pragma region Problem 58 => (Function)
short howManyDaysOverlap(stPeriod period1, stPeriod period2 , bool includeEndDate = false)
{
	if (!IsOverlapPeriods(period1, period2)) {
		return 0;
	}

	stDate overlapStart = CompareDates(period1.DateStart, period2.DateStart)
		== enDateCompare::After ? period1.DateStart : period2.DateStart;

	stDate overlapEnd = CompareDates(period1.DateEnd, period2.DateEnd)
		== enDateCompare::Before ? period1.DateEnd : period2.DateEnd;

	return calculateDifferenceInDays(overlapStart, overlapEnd, includeEndDate);
}
#pragma endregion

#pragma region Problem 59 => (Function)
bool validateDate(stDate date) {
	if (date.Month < 1 || date.Month > 12 || date.Day < 1 || date.Day > 31) {
		return false;
	}
	short daysInMonth = howManyDaysInMonth(date.Year, (enNumberOfDaysPerMonth)date.Month);
	return date.Day <= daysInMonth;
}
#pragma endregion

#pragma region Problem 60 => (Function)
stDate convertDateFromDateStringToDateStructure(string dateString, string separator = "/")
{
	vector <string> vDate = SplitEachWordInVector(dateString, separator);

	stDate sDate;
	sDate.Day	= stoi(vDate.at(0));
	sDate.Month = stoi(vDate.at(1));
	sDate.Year	= stoi(vDate.at(2));

	if(!validateDate(sDate))
	{
		throw invalid_argument("is a Not Valid Date (dd/mm/yyy) : (" + dateString + ")");
	}

	return sDate;
}
#pragma endregion

#pragma region Problem 61 => (Function)
string convertDateFromDateStructureToDateString(stDate date, string separator = "/")
{
	return to_string(date.Day) + 
		separator + to_string(date.Month) + 
		separator + to_string(date.Year);
}
#pragma endregion

#pragma region Problem 62 => (2 Functions)
string replaceWordInString(string str, string toReplace, string replacement)
{
	if (toReplace.empty())
	{
		return str;
	}

	size_t i = 0;
	string result = "";
	while (i < str.length())
	{
		if (str.substr(i, toReplace.length()) == toReplace)
		{
			result += replacement;
			i += toReplace.length();
		}
		else
		{
			result += str[i];
			i++;
		}
	}
	return result;
}

string FormatDate(stDate date, string format = "dd/mm/yyy")
{
	string formaDate = "";
	formaDate = replaceWordInString(format, "dd", to_string(date.Day));
	formaDate = replaceWordInString(formaDate, "mm", to_string(date.Month));
	formaDate = replaceWordInString(formaDate, "yyyy", to_string(date.Year));
	return formaDate;

}
#pragma endregion


int main()
{
#pragma region Problem 1
/*
	Write a program to read a number and print the text of that number .
	
	ex:
		Enter a Number ? 5843
		Five Thousands Eight Hundreds Forty Three
*/

/*
	PrintMessageOnScreen(numberToText(ReadPositiveNumber()));
*/
#pragma endregion

#pragma region Problem 2
/*
	Write a program to check if year is a leap year or not.
	note:
		all years which are perfectly divisible by 4 are leap years except 
		for century years (years ending with 00) which are leap years only 
		if they are perfectly divisible by 400.

		ex:
		Leap Year	| Not Leap Year
		1968		|	1971
		2004		|	2006
		2012		|	2010
		1200		|	1700
		1600		|	1800
		2000		|	1900
*/

/*
	short year = ReadPositiveNumber("Please Enter a Year ? ");

	if (isLeapYear(year))
		cout << "\nis a leap year. : " << year;
	
	else 
		cout << "\nis not a leap year. : " << year;
*/
#pragma endregion

#pragma region Problem 3
/* 
	write a program to print number of :
		Days 
		Hours
		Minutes
		Seconds
	in a ceraion year.
	ex:
	please enter a year to check ? 2000
		Number Of Days		In Year [2000] Is 366
		Number Of Hours		In Year [2000] Is 8784
		Number Of Minutes	In Year [2000] Is 527040
		Number Of Seconds	In Year [2000] Is 31622400

	please enter a year to check ? 1971
		Number Of Days		In Year [1971] Is 365
		Number Of Hours		In Year [1971] Is 8760
		Number Of Minutes	In Year [1971] Is 525600
		Number Of Seconds	In Year [1971] Is 31536000
*/

/*	printNumberOfDaysHoursMinutesSeconds(
		ReadPositiveNumber("please enter a year to check ? "));
*/
#pragma endregion

#pragma region Problem 4
/*
	write a program to print number of :
		Days
		Hours
		Minutes
		Seconds
	in a ceraion year.
	ex:
	please enter a year to check ? 2000
	please enter a Month to check ? 2
		Number Of Days		In Month [2] Is 29
		Number Of Hours		In Month [2] Is 696
		Number Of Minutes	In Month [2] Is 41760
		Number Of Seconds	In Month [2] Is 2505600

	please enter a year to check ? 1971
	please enter a Month to check ? 2
		Number Of Days		In Month [2] Is 28
		Number Of Hours		In Month [2] Is 672
		Number Of Minutes	In Month [2] Is 40320
		Number Of Seconds	In Month [2] Is 2419200
*/

/*
	printNumberOfDaysHoursMinutesSeconds(
		(enNumberOfDaysPerMonth) ReadPositiveNumber("Please Enter a Month To Check ? "),
		ReadPositiveNumber("Please Enter a Year To Check ? "));
*/
#pragma endregion

#pragma region Problem 5
/* 
	Write a program to read a date, and print the day name of week.
	ex:
		Please Enter a year ? 2022
		Please Enter a Month ? 9
		Please Enter a Day ? 20

		Date		: 20/9/2022
		Day Order	: 3
		Day Name	: Tuesday
*/

/*
	short 
		year		 = ReadNumberInRange(2000, 2024 , "Please Enter a Year"),
		month		 = ReadNumberInRange(1, 12, "Please Enter a Month"),
		day			 = ReadNumberInRange(1 , 31 , "Please Enter a Day"),
		dayWeekOrder = dayOfWeekOrder(year, month, day);

	cout << "\nDate\t\t: " << FormatDate(year, month, day) << "\n";

	cout << "Date Order\t: " << dayWeekOrder << "\n";

	cout << "Day Name\t: " << getDayName((enDaysNameInWeek) dayWeekOrder)<< "\n";
*/
#pragma endregion

#pragma region Problem 6 
/* 
	Write a program to print month calendar.
	ex:
	please enter a year ? 2022
	please enter a Month ? 9

	-------------------Sep------------------------
		Sun	| Mon | Tue | Wed | Thu | Fri | Sat
								1	  2	    3
		4	 5	   6	 7      8	  9		10
		11	 12	   13	 14     15	  16	17
		18	 19	   20	 21     22	  23	24
		25	 26	   27	 28     29	  30		
	----------------------------------------------
	
*/

/*
	short year = ReadNumberInRange(1000, 2030, "please enter a Year ?"),
	month = ReadNumberInRange(1, 12, "\nplease enter a Month ?");
	printMonthCalendar(year, month);
*/	
#pragma endregion

#pragma region Problem 7
/*
	Write a program to print year calendar.
	ex:
	please enter a year ? 2022
	
	---------------------------------------------------
						Calemdar - 2022
	---------------------------------------------------

	-------------------January------------------------
		Sun	| Mon | Tue | Wed | Thu | Fri | Sat
									  	    1
		2	 3	   4	 5      6	  7		8
		9	 10	   11	 12     13	  14	15
		16	 17	   18	 19     20	  21	22
		23	 24	   25	 26     27	  28	29
		30	 31
	---------------------------------------------------

	-------------------February------------------------
		Sun	| Mon | Tue | Wed | Thu | Fri | Sat
				   1	 2	    3	  4	    5
		6	 7	   8	 9      10	  11	12	
		13	 14	   15	 16     17	  18	19
		20	 21	   22	 23     24	  25	26
		27	 28	   
	---------------------------------------------------
	etc.....

*/

/*
	short year = ReadNumberInRange(1000, 2030, "please enter a Year ?");
	printYearCalendar(year);
*/
#pragma endregion

#pragma region Problem 8
/*
	Write a program to print total days from the beginning of year.
	ex:
		please enter a Day ? 20
		please enter a Month ? 9
		please enter a Year ? 2022
		
		Number Of Days From The Begining Of The Year Is : 263
*/

/*
	short day = ReadNumberInRange(1, 31, "please enter a Day ? "),
		month = ReadNumberInRange(1, 12, "please enter a Month ? "),
		year  = ReadNumberInRange(1000, 2030, "please enter a Year ? "),

		DaysOrderInYear = getTotalDaysFromBeginOfYear(year, month, day);

	cout << "\nNumber Of Days From The Begining Of The Year Is: " << DaysOrderInYear;
*/
#pragma endregion

#pragma region Problem 9
/*
	Write a program to print total days from the beginning of year.
	ex:
		please enter a Day ? 20
		please enter a Month ? 9
		please enter a Year ? 2022

		Number Of Days From The Begining Of The Year Is : 263

		Date For [263] Is 20/9/2022
*/

/*
	short day = ReadNumberInRange(1, 31, "please enter a Day ? "),
		month = ReadNumberInRange(1, 12, "please enter a Month ? "),
		year  = ReadNumberInRange(1000, 2030, "please enter a Year ? "),

		DaysOrderInYear = getTotalDaysFromBeginOfYear(year, month, day);

	cout << "\nNumber Of Days From The Begining Of The Year Is : " << DaysOrderInYear << "\n";

	stDate date = convertFromTotalDaysToDate(DaysOrderInYear, year);
	cout << "\nDate For ["  << DaysOrderInYear << "] Is : "
	<< FormatDate(date.Year, date.Month, date.Day);
*/

#pragma endregion

#pragma region Problem 10
/*
Write a program to read date and read how many days to add to it,
print the results on screen.
ex:
	please enter a Day ? 10
	please enter a Month ? 10
	please enter a Year ? 2022
	How Many Days To Add ? 2500

	Date After Adding [" << 2500 << "] Days Is:  Is 14/8/2029
*/

/*
	stDate date;
	date.Day = ReadNumberInRange(1, 31, "please enter a Day ? ");
	date.Month = ReadNumberInRange(1, 12, "please enter a Month ? ");
	date.Year = ReadNumberInRange(1000, 2030, "please enter a Year ? ");

	short addDays = ReadNumberInRange(1, 5000, "How Many Days To Add ? ");

	stDate Newdate = DateAddDays(addDays, date);
	cout << "\nDate After Adding [" << addDays << "] Days Is: ";

	cout << FormatDate(Newdate.Year, Newdate.Month, Newdate.Day) << "\n";
*/
#pragma endregion

#pragma region Problem 11
/*
	Write a program to read date1 , date2 and check id date1 is less than date2
	ex:
	please enter a Day ? 12
	please enter a Month ? 2
	please enter a Year ? 2022

	please enter a Day ? 12
	please enter a Month ? 3
	please enter a Year ? 2022

	Yes, Date1 is Less Than Date2.
*/

/*
	stDate date1 = ReadFullDate();
	stDate date2 = ReadFullDate();

	if (IsDate1BeforeDate2(date1 , date2))
		cout << "\nYes, Date1 is Less Than Date2.\n";
	else
		cout << "\nNo, Date1 is Not Less Than Date2.\n";
*/
#pragma endregion

#pragma region Problem 12
/*
	Write a program to read date1 , date2 and check id date1 is Equal than date2
	ex:
	please enter a Day ? 12
	please enter a Month ? 2
	please enter a Year ? 2022

	please enter a Day ? 12
	please enter a Month ? 2
	please enter a Year ? 2022

	Yes, Date1 is Equal Than Date2.
*/

/*
	stDate date1 = ReadFullDate();
	stDate date2 = ReadFullDate();

	if (IsDate1EqualDate2(date1 , date2))
		cout << "\nYes, Date1 is Less Than Date2.\n";
	else
		cout << "\nNo, Date1 is Not Less Than Date2.\n";
*/
#pragma endregion

#pragma region Problem 13
/*
	Write a program to read a date and check:
		- if it is last day in month
		- if it is last month in year

	ex:
	please enter a Day ? 31
	please enter a Month ? 12
	please enter a Year ? 2022

	Yes, Day Is Last Day In Month.
	Yes, Month Is Last Month In Year.
*/

/*
	stDate date1 = ReadFullDate();

	if (IsLastDayInMonth(date1))
		cout << "\nYes, Day Is Last Day In Month.\n";
	else
		cout << "\nNo, Day Is Not Last Day In Month.\n";

	if (IsLastMonthInYear(date1.Month))
		cout << "\nYes, Month Is Last Month In Year.\n";
	else
		cout << "\nNo, Month Is Not Last Month In Year.\n";
*/
#pragma endregion

#pragma region Problem 14
/*
	Write a program to read a date and make a function to increase date by one day.

	ex:
	please enter a Day ? 31
	please enter a Month ? 12
	please enter a Year ? 2022

	Date after adding one day is : 1/1/2023
*/

/*
	stDate date = ReadFullDate();
	stDate newDate = increaseDateByOneDay(date);
	
	cout << "\nDate After Adding One Day Is : "
	<< FormatDate(newDate.Year, newDate.Month, newDate.Day) << endl;
*/
#pragma endregion

#pragma region Problem 15
/*
	Write a program to read a date1 , date2 and make a function to calculate 
	the difference in days.

	Note: Date1 should be less than date2

	ex:
	please enter a Day ? 1
	please enter a Month ? 1
	please enter a Year ? 2022

	please enter a Day ? 25
	please enter a Month ? 3
	please enter a Year ? 2022

	Diffrence Is : 83 Day(s).
	Diffrence (Including End Day) Is : 84 Day(s).
*/

/*
	stDate date = ReadFullDate();
	stDate date2 = ReadFullDate();

	cout <<  "\nDiffrence Is : "
	<< calculateDifferenceInDays(date , date2) << " Day(s).\n";

	cout << "\nDiffrence (Including End Day) Is : "
	<< calculateDifferenceInDays(date, date2, true) << " Day(s).\n";
*/
#pragma endregion

#pragma region Problem 16
/*
	Write a program calculate you age in days.
	ex:
	Please Enter Your Date of Birth:

	please enter a Day ? 16
	please enter a Month ? 8
	please enter a Year ? 1997

	Your Age Is : Day(s)
*/

/*
	cout << "Please Enter Your Date of Birth:\n";
	stDate DateBirth = ReadFullDate();
	stDate DateNow = GetSystemDate();

	cout << "\nYour Age Is : " 
	<< calculateDifferenceInDays(DateBirth , DateNow ,true) 
	<< endl;
*/
#pragma endregion

#pragma region Problem 17 (Customize Function => calculateDifferenceInDays() : Problem 15 )
/*
	Write a program to read a date1, date2 and make a function to calculate 
	the difference in day.

	Note: if date2 is less than date1 print the results in minutes
	ex:
	Please Enter Your Date of Birth:

	please enter a Day ? 1
	please enter a Month ? 1
	please enter a Year ? 2022

	please enter a Day ? 1
	please enter a Month ? 1
	please enter a Year ? 2000

	Diffrence Is : -8036 Day(s).
	Diffrence (Including End Day) Is : -8037 Day(s).
*/

/*
	stDate date = ReadFullDate();
	stDate date2 = ReadFullDate();

	cout <<  "\nDiffrence Is : "
	<< calculateDifferenceInDays(date , date2) << " Day(s).\n";

	cout << "\nDiffrence (Including End Day) Is : "
	<< calculateDifferenceInDays(date, date2, true) << " Day(s).\n";
*/
#pragma endregion

#pragma region Problem 18 
/*
	Write a program Increase Date By (10) Days.
	ex:

	please enter a Day ? 1
	please enter a Month ? 1
	please enter a Year ? 2023

	Adding 10 Days Is : 11/1/2023
*/

/*
	stDate date = IncreaseDateByXDays( ReadFullDate() , 
			ReadPositiveNumber("Enter Count Added Days ? "));

	cout << "\nAdding 10 Days Is : " 
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 19
/*
	Write a program Increase Date By One Week.
	ex:

	please enter a Day ? 11
	please enter a Month ? 1
	please enter a Year ? 2023

	Adding One Week : 18/1/2023
*/

/*
	stDate date = IncreaseDateByOneWeek(ReadFullDate());

	cout << "\nAdding One Week Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 20 
/*
	Write a program Increase Date By (10) Weeks.
	ex:

	please enter a Day ? 18
	please enter a Month ? 1
	please enter a Year ? 2023

	Adding 10 Weeks Is : 29/3/2023
*/

/*
	stDate date = IncreaseDateByXWeek( ReadFullDate() ,
			ReadPositiveNumber("Enter Count Added Weeks ? "));

	cout << "\nAdding 10 Weeks Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 21
/*
	Write a program Increase Date By One Month.
	ex:

	please enter a Day ? 29
	please enter a Month ? 3
	please enter a Year ? 2023

	Adding One Month Is : 29/4/2023
*/

/*
	stDate date = IncreaseDateByOneMonth( ReadFullDate());

	cout << "\nAdding One Month Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 22
/*
	Write a program Increase Date By (5) Months.
	ex:

	please enter a Day ? 29
	please enter a Month ? 4
	please enter a Year ? 2023

	Adding (5) Months Is : 29/9/2023

*/


/*
	short AddedMonths = ReadPositiveNumber("Enter Count Added Months ? ");
	stDate date = IncreaseDateByXMonth( ReadFullDate() , AddedMonths);

	cout << "\nAdding (" << AddedMonths << ") Months Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 23
/*
	Write a program Increase Date By One Year.
	ex:

	please enter a Day ? 29
	please enter a Month ? 9
	please enter a Year ? 2023

	Adding One Year Is : 29/9/2024
*/

/*
	stDate date = IncreaseDateByOneYear(ReadFullDate());

	cout << "\nAdding One Year Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 24
/*
	Write a program Increase Date By 10 Years.
	ex:

	please enter a Day ? 29
	please enter a Month ? 9
	please enter a Year ? 2024

	Adding 10 Years Is : 29/9/2034
*/

/*
	short AddedYears = ReadPositiveNumber("Enter Count Added Years ? ");
	stDate date = IncreaseDateByXYears( ReadFullDate() , AddedYears);

	cout << "\nAdding (" << AddedYears << ") Years Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 25
/*
	Write a program Faster Function Increase Date By 10 Years. 
	ex:

	please enter a Day ? 29
	please enter a Month ? 9
	please enter a Year ? 2034

	Adding 10 Years Is (Faster) : 29/9/2044
*/

/*
	short AddedYears = ReadPositiveNumber("Enter Count Added Years ? ");
	stDate date = IncreaseDateByXYearsFaster( ReadFullDate() , AddedYears);

	cout << "\nAdding (" << AddedYears << ") Years Is (Faster) : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 26
/*
	Write a program Increase Date By One Decade.
	ex:

	please enter a Day ? 29
	please enter a Month ? 9
	please enter a Year ? 2044

	Adding One Decade Is : 29/9/2054
*/

/*
	stDate date = IncreaseDateByOneDecade(ReadFullDate());

	cout << "\nAdding One Decade Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 27
/*
	Write a program Increase Date By 10 Decades.
	ex:

	please enter a Day ? 29
	please enter a Month ? 9
	please enter a Year ? 2054

	Adding 10 Desades Is : 29/9/2154
*/

/*
	short AddedDecades = ReadPositiveNumber("Enter Count Added Decades ? ");
	stDate date = IncreaseDateByXDecades( ReadFullDate() , AddedDecades);

	cout << "\nAdding (" << AddedDecades << ") Decades Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 28
/*
	Write a program Faster Function Increase Date By 10 Decades.
	ex:

	please enter a Day ? 29
	please enter a Month ? 9
	please enter a Year ? 2154

	Adding 10 Decades (Faster) Is : 29/9/2254
*/

/*
	short AddedDecades = ReadPositiveNumber("Enter Count Added Decades ? ");
	stDate date = IncreaseDateByXDecadesFaster( ReadFullDate() , AddedDecades);

	cout << "\nAdding (" << AddedDecades << ") Decades Is (Faster) : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 29
/*
	Write a program Increase Date By One Century.
	ex:

	please enter a Day ? 29
	please enter a Month ? 9
	please enter a Year ? 2254

	Adding One Century Is : 29/9/2354
*/

/*
	stDate date = IncreaseDateByOneCentury( ReadFullDate());

	cout << "\nAdding One Century Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 30
/*
	Write a program Increase Date By One Millennium.
	ex:

	please enter a Day ? 29
	please enter a Month ? 9
	please enter a Year ? 2354

	Adding One Millennium Is : 29/9/3354
*/

/*
	stDate date = IncreaseDateByOneMillennium(ReadFullDate());

	cout << "\nAdding One Millennium : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 31
/*
	Write a program Decrease Date By One Day.
	ex
	please enter a Day ? 31
	please enter a Month ? 12
	please enter a Year ? 2022

	Subtracting One Days Is : 30/12/2022
*/


/*
	stDate date = decreaseDateByOneDay(ReadFullDate());

	cout << "\nSubtracting One Day Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 32 
/*
	Write a program Decrease Date By (10) Days.
	ex:

	please enter a Day ? 30
	please enter a Month ? 12
	please enter a Year ? 2022

	Subtracting 10 Days Is : 20/12/2022
*/

/*
	stDate date = decreaseDateByXDays( ReadFullDate() ,
		ReadPositiveNumber("Enter Count Subtracted Days ? "));

	cout << "\nSubtracting 10 Days Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/

#pragma endregion

#pragma region Problem 33
/*
	Write a program Decrease Date By One Week.
	ex:

	please enter a Day ? 20
	please enter a Month ? 12
	please enter a Year ? 2022

	Subtracting One Week : 13/12/2022
*/

/*
	stDate date = decreaseDateByOneWeek(ReadFullDate());

	cout << "\nSubtracting One Week Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 34 
/*
	Write a program decrease Date By (10) Weeks.
	ex:

	please enter a Day ? 13
	please enter a Month ? 12
	please enter a Year ? 2022

	Subtracting 10 Weeks Is : 4/10/2022
*/

/*
	stDate date = decreaseDateByXWeeks( ReadFullDate() ,
		ReadPositiveNumber("Enter Count Subtracted Weeks ? "));

	cout << "\nSubtracting 10 Weeks Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/

#pragma endregion

#pragma region Problem 35
/*
	Write a program decrease Date By One Month.
	ex:

	please enter a Day ? 4
	please enter a Month ? 10
	please enter a Year ? 2022

	Subtracting One Month Is : 4/9/2022
*/

/*
	stDate date = decreaseDateByOneMonth( ReadFullDate());

	cout << "\nSubtracting One Month Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 36
/*
	Write a program decrease Date By (5) Months.
	ex:

	please enter a Day ? 4
	please enter a Month ? 9
	please enter a Year ? 2022

	Subtracting (5) Months Is : 4/4/2021
*/

/*
	short SubtractedMonths = ReadPositiveNumber("Enter Count Subtracted Months ? ");
	stDate date = decreaseDateByXMonths( ReadFullDate() , SubtractedMonths);

	cout << "\nSubtracting (" << SubtractedMonths << ") Months Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 37
/*
	Write a program decrease Date By One Year.
	ex:

	please enter a Day ? 4
	please enter a Month ? 4
	please enter a Year ? 2022

	Subtracting One Year Is : 4/4/2021
*/

/*
	stDate date = decreaseDateByOneYear(ReadFullDate());

	cout << "\nSubtracting One Year Is : "
	<< FormatDate(date.Year , date.Month , date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 38
/*
	Write a program decrease Date By 10 Years.
	ex:

	please enter a Day ? 4
	please enter a Month ? 4
	please enter a Year ? 2021

	Subtracting 10 Years Is : 4/4/2011
*/

/*
	short SubtractedYears = ReadPositiveNumber("Enter Count Subtracted Years ? ");
	stDate date = decreaseDateByXYears( ReadFullDate() , SubtractedYears);

	cout << "\nSubtracting (" << SubtractedYears << ") Years Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 39 
/*
	Write a program Faster Function decrease Date By 10 Years.
	ex:

	please enter a Day ? 4
	please enter a Month ? 4
	please enter a Year ? 2011

	Subtracting 10 Years Is (Faster) : 4/4/2001
*/

/*
	short SubtractedYears = ReadPositiveNumber("Enter Count Subtracted Years ? ");
	stDate date = decreaseDateByXYearsFaster( ReadFullDate() , SubtractedYears);

	cout << "\nSubtracting (" << SubtractedYears << ") Years Is (Faster) : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 40
/*
	Write a program decrease Date By One Decade.
	ex:

	please enter a Day ? 4
	please enter a Month ? 4
	please enter a Year ? 2001

	Subtracting One Decade Is : 4/4/1991
*/

/*
	stDate date = decreaseDateByOneDecade(ReadFullDate());

	cout << "\nSubtracting One Decade Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 41
/*
	Write a program decrease Date By 10 Decades.
	ex:

	please enter a Day ? 4
	please enter a Month ? 4
	please enter a Year ? 1991

	Subtracting 10 Desades Is : 4/4/1891
*/

/*
	short SubtractedDecades = ReadPositiveNumber("Enter Count Subtracted Decades ? ");
	stDate date = decreaseDateByXDecades( ReadFullDate() , SubtractedDecades);

	cout << "\nSubtracting (" << SubtractedDecades << ") Decades Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 42
/*
	Write a program Faster Function decrease Date By 10 Decades.
	ex:

	please enter a Day ? 4
	please enter a Month ? 4
	please enter a Year ? 1891

	Subtracting 10 Decades (Faster) Is : 4/4/1791
*/

/*
	short SubtractedDecades = ReadPositiveNumber("Enter Count Subtracted Decades ? ");
	stDate date = decreaseDateByXDecadesFaster( ReadFullDate() , SubtractedDecades);

	cout << "\nSubtracting (" << SubtractedDecades << ") Decades Is (Faster) : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 43
/*
	Write a program decrease Date By One Century.
	ex:

	please enter a Day ? 4
	please enter a Month ? 4
	please enter a Year ? 1791

	Subtracting One Century Is : 4/4/1691
*/

/*
	stDate date = decreaseDateByOneCentury( ReadFullDate());

	cout << "\nSubtracting One Century Is : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 44
/*
	Write a program decrease Date By One Millennium.
	ex:

	please enter a Day ? 4
	please enter a Month ? 4
	please enter a Year ? 1691

	Subtracting One Millennium Is : 4/4/691
*/

/*
	stDate date = decreaseDateByOneMillennium(ReadFullDate());

	cout << "\nSubtracting One Millennium : "
		<< FormatDate(date.Year, date.Month, date.Day) << endl;
*/
#pragma endregion

#pragma region Problem 45
/*
	Write a program to read a date and make function 
	IsEndOfWeek()
	ex:
	Today is Fri , 23/9/2022

	Is It End Of Week ?
		No Not End Of Week
*/

/*
	stDate date = ReadFullDate();

	if (IsEndOfWeek(date))
		cout << "\nYes End Of Week\n";
	else
		cout << "\nNo Not End Of Week\n";
*/
#pragma endregion

#pragma region Problem 46
/*
	Write a program to read a date and make function
	IsWeekEnd() , Fri Or Sat => True
	ex:
	Today is Fri , 23/9/2022

	Is It Weekend?
		Yes It Is a Weekend.
*/

/*
	stDate date = ReadFullDate();

	if (IsWeekEnd(date))
		cout << "\nYes It Is a Weekend\n";
	else
		cout << "\nNo It Is Not a Weekend\n";
*/
#pragma endregion

#pragma region Problem 47
/*
	Write a program to read a date and make function
	IsBusinessDay() , Fri Or Sat => True
	ex:
		Today is Fri , 23/9/2022

		Is It Business Day ?
			No It Is Not a Business Day.
*/

/*
	stDate date = ReadFullDate();

	if (IsBusinessDay(date))
		cout << "\nYes It Is a Business Day.\n";
	else
		cout << "\nNo It Is Not a Business Day\n";
*/
#pragma endregion

#pragma region Problem 48
/*
	Write a program to read a date and make function
	Days Until The End Of Week 
	ex:
		Today is Fri , 23/9/2022

		Days Until End Of Week : 1 Day(s)
*/

/*
	stDate date = ReadFullDate();

	cout << "\nDays Until End Of Week : " << DaysUntilTheEndOfWeek(date) " Day(s)\n";
*/
#pragma endregion

#pragma region Problem 49
/*
	Write a program to read a date and make function
	Days Until End Of Month
	ex:
		Today is Fri , 23/9/2022

		Days Until End Of Month : 8 Day(s)
*/

/*
	stDate date = ReadFullDate();

	cout << "\nDays Until End Of Month : " << DaysUntilEndOfMonth(date) " Day(s)\n";
*/
#pragma endregion

#pragma region Problem 50
/*
	Write a program to read a date and make function
	Days Until End Of Year
	ex:
		Today is Fri , 23/9/2022

		Days Until End Of Year : 100 Day(s)
*/

/*
	stDate date = ReadFullDate();

	cout << "\nDays Until End Of Year : " << DaysUntilEndOfYear(date) " Day(s)\n";
*/
#pragma endregion

#pragma region Problem 51
/*
	Write a program to read vacation period dateFrom and dateTo and make a function to 
	calculate the actual vacation days.

	Note:Weekends are excluded.

	ex:
	Vacation Starts:
		Please enter a Day ? 1 
		Please enter a month ? 1
		please enter a year ? 2022

	Vacation Ends:
		Please enter a Day ? 1
		Please enter a month ? 5
		please enter a year ? 2022

	Vacation From : Thu , 1/9/2022
	Vacation To : Mon , 5/9/2022

	Actual Vacation Days Is : 2

*/

/*
	cout << "Vacation Starts:\n";
	stDate date1 = ReadFullDate();

	cout << "Vacation End:\n";
	stDate date2 = ReadFullDate();

	cout << "Vaction From : " 
	<< getDayName((enDaysNameInWeek)dayOfWeekOrder(date1))
	<< " , " << FormatDate(date1.Year, date1.Month, date1.Day) << endl;

	cout << "Vaction To : " 
	<< getDayName((enDaysNameInWeek)dayOfWeekOrder(date2))
	<< " , " << FormatDate(date2.Year, date2.Month, date2.Day) << endl;

	cout << "\n\nActual Vacation Days Is : "
	<< howManyTheActualVacationDaysFromDate1ToDate2(date1, date2);
*/
#pragma endregion

#pragma region Problem 52
/*
	Write a program to read vacation start dateFrom and vacationDays,
	then make a function to calculate the vacation return date.

	Note:Weekends are excluded.

	ex:
	Vacation Starts:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2022

	Please enter vacation days ? 23
		Return Date : Wed , 2/2/2022
*/

/*
	cout << "Vacation Starts:\n";
	stDate date = ReadFullDate();

	short vacationDays = ReadPositiveNumber("Please Enter Vacation Days ? ");

	stDate returnDate = vacationReturnDate(date , vacationDays) ;

	cout << "\nReturn Date : "
	<< getDayName((enDaysNameInWeek)dayOfWeekOrder(returnDate)) 
	<< " , " << FormatDate(returnDate.Year , returnDate.Month , returnDate.Day);
*/
#pragma endregion

#pragma region Problem 53
/*
	Write a program a read Date1 and Date2 and check if Date1 is after date2 or not.

	ex:
	Enter Date1:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2022

	Enter Date2:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2000

	Yes, Date1 Is After Date2.
*/

/*
	cout << "Enter Date1:\n";
	stDate date1 = ReadFullDate();

	cout << "Enter Date2:\n";
	stDate date2 = ReadFullDate();

	if (IsDate1AfterDate2(date1 , date2))
	cout << "\nYes, Date1 Is After Date2.\n";
	else
	cout << "\nNo, Date1 Is Not After Date2.\n";
*/
#pragma endregion

#pragma region Problem 54
/*
	Write a program to read Date1 and Date2 and write a function to compare dates,
	it should return:

	-1 Before
	0 Equal
	1 After

	ex:
	Enter Date1:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2000

	Enter Date2:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2022

		Compare Result = -1
	------------------------------------
	Enter Date1:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2000

	Enter Date2:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2000

		Compare Result = 0
	------------------------------------
	Enter Date1:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2022

	Enter Date2:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2000

		Compare Result = 1

*/

/*
	cout << "Enter Date1:\n";
	stDate date1 = ReadFullDate();

	cout << "Enter Date2:\n";
	stDate date2 = ReadFullDate();

	cout << "\nCompare Result = " << CompareDates(date1, date2);
*/
#pragma endregion

#pragma region Problem 55
/*
	Weite a program to read two periods and check if they overlap or not .

	ex:
	-----------------
	Enter Period 1 : 
	-----------------
		Enter Start Date:
			Please enter a Day ? 1
			Please enter a month ? 2
			please enter a year ? 2022

		Enter End Date:
			Please enter a Day ? 10
			Please enter a month ? 2
			please enter a year ? 2022

	-----------------
	Enter Period 2 :
	-----------------
		Enter Start Date:
			Please enter a Day ? 5
			Please enter a month ? 2
			please enter a year ? 2022

		Enter End Date:
			Please enter a Day ? 15
			Please enter a month ? 2
			please enter a year ? 2022

	Yes, Periods Overlap.

*/

/*
	try 
	{
		cout << "Enter Period 1:\n";
		stPeriod period1 = ReadPeriod();

		cout << "Enter Period 2:\n";
		stPeriod period2 = ReadPeriod();

		if (IsOverlapPeriods(period1, period2))
		{
			cout << "\nYes, Periods Overlap\n\n";

			cout << "count Days Overlap = " << howManyDaysOverlap(period1, period2 ,true)
				<< "\n\n";

			cout << "Dates Overlap Between 2 Periods:\n\n";

			for (stDate &date : getDatesOverlapBetween2Periods(period1, period2))
			{
				cout << "- " << FormatDate(date.Year, date.Month, date.Day) << endl;
			}
		}
		else
		{
			cout << "\nNo, Periods Is Not Overlap\n\n";
		}

	}
	catch (const exception& ex) 
	{
			cout << "Error: " << ex.what() << endl;
	}
*/
#pragma endregion

#pragma region Problem 56
/*
	Write a program to read period and calculate period length in days ?

	ex:
	-----------------
	Enter Period 1 :
	-----------------
	Enter Start Date:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2022

	Enter End Date:
		Please enter a Day ? 5
		Please enter a month ? 1
		please enter a year ? 2022

		Period Length Is: 4
		Period Length (Including End Date) Is: 5
*/

/*
	cout << "Enter Period 1:\n";
	stPeriod period1 = ReadPeriod();

	cout << "Period Length Is: " << calculatePeriodLengthInDays(period1) << endl;

	cout << "\nPeriod Length (Including End Date) Is: " 
	<< calculatePeriodLengthInDays(period1, true) << endl;
*/
#pragma endregion

#pragma region Problem 57 
/*
	Write a program to read period and date, then check if date is within this
	period or not .

	ex:
	-----------------
	Enter Period :
	-----------------
	Enter Start Date:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2022

	Enter End Date:
		Please enter a Day ? 10
		Please enter a month ? 1
		please enter a year ? 2022

	Enter Date To Check:
		Please enter a Day ? 5
		Please enter a month ? 1
		please enter a year ? 2022

		Yes, Date Is Within Period
*/

/*
	cout << "Enter Period :\n\n";
	stPeriod period = ReadPeriod();

	cout << "Enter Date To Check :\n\n";
	stDate date = ReadFullDate();

	if (isDateInPeriod(period , date))
		cout << "\nYes, Date Is Within Period\n";

	else
		cout << "\nNo, Date Is Not Within Period\n";
*/
#pragma endregion

#pragma region Problem 58
/*
	Write a program to read a tow periods then count overlap days .

	ex:
	-----------------
	Enter Period 1 : 
	-----------------
	Enter Start Date:
		Please enter a Day ? 1
		Please enter a month ? 1
		please enter a year ? 2022

	Enter End Date:
		Please enter a Day ? 10
		Please enter a month ? 1
		please enter a year ? 2022

	-----------------
	Enter Period 2 :
	-----------------
	Enter Start Date:
		Please enter a Day ? 5
		Please enter a month ? 1
		please enter a year ? 2022

	Enter End Date:
		Please enter a Day ? 30
		Please enter a month ? 12
		please enter a year ? 2022

	Overlap Days Count Is : 5

*/

/*
	cout << "Enter Period 1:\n\n";
	stPeriod period1 = ReadPeriod();

	cout << "Enter Period 2:\n\n";
	stPeriod period2 = ReadPeriod();

	cout << "\n\nOverlap Days Count Is : " << howManyDaysOverlap(period1, period2) << endl;
*/
#pragma endregion

#pragma region Problem 59
/*
	Write a programe to read date and write a function to validate this date .
	
	Please enter a Day ? 35
	Please enter a month ? 1
	please enter a year ? 2022

		No, date is a not valide date
	-----------------------------------
	Please enter a Day ? 29
	Please enter a month ? 2
	please enter a year ? 2000

		Yes, date is a valide date
	-----------------------------------

	Please enter a Day ? 29
	Please enter a month ? 2
	please enter a year ? 2022

		No, date is a not valide date
	-----------------------------------

	Please enter a Day ? 31
	Please enter a month ? 4
	please enter a year ? 2022

		No, date is a not valide date
	-----------------------------------
	Please enter a Day ? 25
	Please enter a month ? 15
	please enter a year ? 2022

		No, date is a not valide date
*/

/*
	stDate date = ReadFullDate();

	if (validateDate(date))
		cout << "\nYes, date is a valide date\n";

	else
		cout << "\nNo, date is a not valide date\n";
*/
#pragma endregion

#pragma region Problem 60
/*
	Write a program to read date string and convert it to date structure.

	ex:
	Please Enter Date dd/mm/yyy ? 31/3/2022

		Day		: 31
		Month	: 3
		Year	: 2022
*/

/*
	try
	{
		string dateString = ReadWord("Please Enter Date dd/mm/yyy ? ");
		stDate dateStructure = convertDateFromDateStringToDateStructure(dateString);

		cout << "\n\nDate Convert From String To Structure : \n\n";

		cout << "Day: " << dateStructure.Day << endl;
		cout << "Month: " << dateStructure.Month << endl;
		cout << "Year: " << dateStructure.Year << endl << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "\nError: " << ex.what() << endl;
	}
*/

#pragma endregion

#pragma region Problem 61
/*
	Write a program to read date and convert From Date structure To date string .

	ex:
	Date structure
		Please enter a Day ? 31
		Please enter a month ? 3
		please enter a year ? 2022

	Date After Converted To String 31/3/2022
*/

/*
	stDate date = ReadFullDate();

	string converDateToString = convertDateFromDateStructureToDateString(date);

	cout << "\n\nDate Convert From Structure To String: \n\n";
	cout << "\nYou Entered: " << converDateToString << endl;
*/
#pragma endregion

#pragma region Problem 62
/*
	Write a program to read date and write a function to format that date .

	ex:

	Please enter date dd/mm/yyyy ? 31/3/2022

		31/3/2022

		2022/31/3

		3/31/2022

		3-31-2022

		31-3-2022

		Day: 31, Month: 3, Year: 2022
*/

/*
	string dateString = ReadWord("Please enter date dd/mm/yyyy ? ");
	stDate date = convertDateFromDateStringToDateStructure(dateString);

	cout << "\n" << FormatDate(date) << endl;
	cout << "\n" << FormatDate(date, "yyyy/dd/mm") << endl;
	cout << "\n" << FormatDate(date, "mm/dd/yyyy") << endl;
	cout << "\n" << FormatDate(date, "mm-dd-yyyy") << endl;
	cout << "\n" << FormatDate(date, "dd-mm-yyyy") << endl;
	cout << "\n" << FormatDate(date, "Day: dd, Month: mm, Year: yyyy") << endl;
*/
#pragma endregion
	
}

