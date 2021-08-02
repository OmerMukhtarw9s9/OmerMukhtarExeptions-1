//Omer Mukhtar
// CIS 1202
// 30 june 21
#include<iostream>
#include<string>


using namespace std;
//Exception classes
//A class to handle invalidCharacterExcpeption
class invalidCharacterExcpeption
{
};
//A class That  handle invalidRangeException
class invalidRangeException
{
};
//class to handle caseConversionException
class caseConversionException
{
};
//function used to find character,the  offset value
char character(char start, int offset)
{
	//THis finds the ascii value of start
	int startAsciiValue = int(start);
	//adds the offset to start's ascii value to find a specfic value
	int target = startAsciiValue + offset;
	try {
		//if its in lower Case alphabet or upper Case alphabet displays invalidCharacterExcpeption
		if (startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122)
		{
			throw invalidCharacterExcpeption();
		}
		// Using else if target is not lower case alphabet or upper case alphabet  display invalidRangeException
		else if (target < 65 || (target > 90 && target < 97) || target > 122)
		{
			throw invalidRangeException();
		}
		//else if target is lower case and start is upper case or target is upper case and start is lower case then throw caseConversionException
		else if ((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90))
		{
			throw caseConversionException();
		}
	}
	//capture all of the appropriate expressions and publish the message
	catch (invalidCharacterExcpeption exception1)
	{
		cout << "Invalid Character Exception " << endl;
		return ' ';
	}
	catch (invalidRangeException exception2)
	{
		cout << "Invalid Range Exception " << endl;
		return ' ';
	}
	catch (caseConversionException exception3)
	{
		cout << "Cannot make case changes from upper to lower or otherwise " << endl;
		return ' ';
	}
	//Return the character value of target if no exceptions were recorded.
	return char(target);
}
int main()
{
	cout << character('a', 1) << endl;
	cout << character('a', -1) << endl;
	cout << character('Z', -1) << endl;
	cout << character('?', 5) << endl;
	cout << character('A', 32) << endl;

}