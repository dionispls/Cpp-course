#include <iostream>
#include <string>

bool leap = false;

enum Months
{
	January, February, March, April, May, June, July, August, September, October, November, December
};

int day_amount(Months month)
{
	switch (month)
	{
	case Months::February:
		switch (flag_leap)
		{
		case true: return 29;
		case false: return 28;
		}
	case Months::April:
	case Months::June:
	case Months::September:
	case Months::November:
		return 30;
	case Months::January:
	case Months::March:
	case Months::May:
	case Months::July:
	case Months::August:
	case Months::October:
	case Months::December:
		return 31;
	}
}

int main()
{
	Months month = October;
	std::cout << day_amount(month);
	return 0;
}

