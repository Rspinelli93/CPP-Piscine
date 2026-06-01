#include "parse.hpp"
#include "DataBase.hpp"

static bool validDate( std::string date );
static bool	validFloat( std::string eRate );
static bool validDay( std::string day );
static bool validMonth( std::string month );

/// @brief Parsing function, it takes 2 strings, one representing the date and the second repesenting the exchange rate value.
/// @param date String to parse for date. Valid date format: "2001-08-16"
/// @param eRate String to parse for eRate. Valid format: float notation (one come, only numbers).
/// @return True if both strings are valid
bool	parse( std::string date, std::string eRate )
{
	if (date.length() != 10 || !eRate.compare(""))
		return (false);
	if (validDate(date) && validFloat(eRate))
		return (true);
	return (false);
}

/// @brief Helper function to validate that a string follows a float format
/// @param eRate String to validate
/// @return True if its valid, False if not.
static bool	validFloat( std::string eRate )
{
	//std::cout << "rate: " << eRate << std::endl;
	bool comma = false;

	if (!eRate.compare("."))
		return (false);

	for (int i = 0; i < (int)eRate.length(); i++)
	{
		if (isdigit(eRate.at(i)))
			continue ;
		if (eRate.at(i) != '.')
			return (false);
		else
		{
			if (comma == true)
				return (false);
			else
				comma = true;
		}
	}
	return(true);
}

/// @brief Helper function to validate a date string. Valid date format: "2001-08-16"
/// @param date String to validate
/// @return True if valid.
static bool validDate( std::string date )
{
	//std::cout << "date: " << date << std::endl;

	// Check dash positions ('-')
	if (date.at(4) != '-' || date.at(7) != '-')
		return (false);

	// Validate years
	for (int i = 0; i < 4; i++)
		if (!isdigit(date.at(i)))
			return (false);

	// Validate Days and months
	if (!validDay(date.substr(8,2)) || !validMonth(date.substr(5,2)))
		return (false);

	// 30th of February
	if (!date.substr(5,2).compare("02") && date.at(8) >= '3')
		return (false);

	return (true);
}

static bool validDay( std::string day )
{
	//std::cout << "day: " << day << std::endl;

	// All digits
	if (!isdigit(day.at(0)) && !isdigit(day.at(1)))
		return (false);

	// Day 00
	if (day.at(0) == '0' && day.at(1) == '0')
		return (false);

	// Day 40++
	if (day.at(0) > '3')
		return (false);

	// Day 32++
	if (day.at(0) == '3' && (day.at(1) != '1' && day.at(1) != '0'))
		return (false);

	return (true);
}

static bool validMonth( std::string month )
{
	//std::cout << "month: " << month << std::endl;

	// All digits
	if (!isdigit(month.at(0)) || !isdigit(month.at(1)))
		return (false);

	// Month 00
	if (month.at(0) == '0' && month.at(1) == '0')
		return (false);

	// Month 20++
	if (month.at(0) > '1')
		return (false);
	
	// Month 13++
	if (month.at(0) == '1' && (month.at(1) != '0' && month.at(1) != '1' && month.at(1) != '2'))
		return (false);

	return (true);
}

void	parseTest( void )
{
	DataBase myDatabase;

	std::cout << "\033[32m[EXPECT: OK] 2011-08-21 | 5\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-08-21 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[32m[EXPECT: OK] 2011-08-21 | 3.14\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-08-21 | 3.14"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] negative value\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-08-21 | -1"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] too large\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-08-21 | 1001"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[32m[EXPECT: OK] value = 0\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-08-21 | 0"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[32m[EXPECT: OK] value = 1000\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-08-21 | 1000"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] bad date format\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("21-08-2011 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] invalid month\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-13-01 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] invalid day\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-32 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] month 00\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-00-01 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] day 00\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-00 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] missing comma\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-015"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] empty string\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr(""); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] only date no value\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 | "); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] letters as value\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 | abc"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] letters as date\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("abcd-ef-gh | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] feb 30\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-02-30 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] whitespace in value\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 |  5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] whitespace in date\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01 -01 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[32m[EXPECT: OK] 999.99\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 | 999.99"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[32m[EXPECT: OK] 1000.0\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 | 1000.0"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] 1000.1\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 | 1000.1"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	// Extra garbage cases
	std::cout << "\033[35m[EXPECT: ERR] special chars in date\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("20!1-01-01 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] null-like string\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr(""); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] only comma\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr(","); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] double comma\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 |  | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] newline in string\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01\n | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] tab in date\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-0\t1 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] value with sign +\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 | +5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] multiple dots in value\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 | 3.1.4"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] date with slashes\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011/01/01 | 5"); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }

	std::cout << "\033[35m[EXPECT: ERR] value is just a dot\033[0m" << std::endl;
	{ try { myDatabase.addDataUsr("2011-01-01 | ."); std::cout << "Valid!\n" << std::endl; } catch(const std::exception& e) { std::cerr << "\033[31m" << e.what() << "\n" << "\033[0m\n"; } }
}
