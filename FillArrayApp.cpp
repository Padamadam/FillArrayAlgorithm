#include <iostream>
#include "FillArray.h"

bool compareArray(std::array<std::array<int, maxColumns>, maxRows>& array,
	std::array<std::array<int, maxColumns>, maxRows>& testArray, size_t rows, size_t columns)
{
	for (size_t row = 0; row < rows; ++row)
		for (size_t column = 0; column < columns; ++column)
			if (array[row][column] != testArray[row][column])
				return false;
	return true;
}


bool testException(size_t rows, size_t columns)
{
	try
	{
		std::array<std::array<int, maxColumns>, maxRows> testArray;
		fillMyArray(testArray, rows, columns);
		std::cout << "Exception was not thrown for " << rows << " rows and "
			<< columns << " columns.\n";
		return false;
	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << e.what();
		std::cout << " For " << rows << " rows and " << columns << " columns.\n";
	}
	return true;
}

bool test_array3x4()
{
	std::array<std::array<int, maxColumns>, maxRows> testArray;
	testArray[0] = { 6, 9, 11, 12 };
	testArray[1] = { 3, 5, 8, 10 };
	testArray[2] = { 1, 2, 4, 7 };

	std::array<std::array<int, maxColumns>, maxRows> myArray;
	fillMyArray(myArray, 3, 4);
	if (compareArray(myArray, testArray, 3, 4))
	{
		std::cout << "Case 3x4 run successfully\n";
		return true;
	}
	else
	{
		std::cout << "Testing 3x4 failed. Expected:\n";
		displayArray(std::cout, testArray, 3, 4);
		std::cout << "\n Obtained array:\n";
		displayArray(std::cout, myArray, 3, 4);
		return false;
	}
}

bool test_array5x5()
{
	std::array<std::array<int, maxColumns>, maxRows> testArray;
	testArray[0] = { 15, 19, 22, 24, 25 };
	testArray[1] = { 10, 14, 18, 21, 23 };
	testArray[2] = { 6,  9, 13, 17, 20 };
	testArray[3] = { 3, 5, 8, 12, 16 };
	testArray[4] = { 1, 2, 4, 7, 11 };

	std::array<std::array<int, maxColumns>, maxRows> myArray;
	fillMyArray(myArray, 5, 5);
	if (compareArray(myArray, testArray, 5, 5))
	{
		std::cout << "Case 5x5 run successfully\n";
		return true;
	}
	else
	{
		std::cout << "Testing 5x5 failed. Expected:\n";
		displayArray(std::cout, testArray, 5, 5);
		std::cout << "\n Obtained array:\n";
		displayArray(std::cout, myArray, 5, 5);
		return false;
	}
}

bool test_array1x3()
{
	std::array<std::array<int, maxColumns>, maxRows> testArray;
	testArray[0] = { 3, 2, 1 };

	std::array<std::array<int, maxColumns>, maxRows> myArray;
	fillMyArray(myArray, 1, 3);
	if (compareArray(myArray, testArray, 1, 3))
	{
		std::cout << "Case 1x3 run successfully\n";
		return true;
	}
	else
	{
		std::cout << "Testing 1x3 failed. Expected:\n";
		displayArray(std::cout, testArray, 1, 3);
		std::cout << "\n Obtained array:\n";
		displayArray(std::cout, myArray, 1, 3);
		return false;
	}
}

bool test_array1x1()
{
	std::array<std::array<int, maxColumns>, maxRows> testArray;
	testArray[0] = { 1 };

	std::array<std::array<int, maxColumns>, maxRows> myArray;
	fillMyArray(myArray, 1, 1);
	if (compareArray(myArray, testArray, 1, 1))
	{
		std::cout << "Case 1x1 run successfully\n";
		return true;
	}
	else
	{
		std::cout << "Testing 1x1 failed. Expected:\n";
		displayArray(std::cout, testArray, 1, 1);
		std::cout << "\n Obtained array:\n";
		displayArray(std::cout, myArray, 1, 1);
		return false;
	}
}

bool test_array1x10()
{
	std::array<std::array<int, maxColumns>, maxRows> testArray;
	testArray[0] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::array<std::array<int, maxColumns>, maxRows> myArray;
	fillMyArray(myArray, 1, 10);
	if (compareArray(myArray, testArray, 1, 10))
	{
		std::cout << "Case 1x10 run successfully\n";
		return true;
	}
	else
	{
		std::cout << "Testing 1x10 failed. Expected:\n";
		displayArray(std::cout, testArray, 1, 10);
		std::cout << "\n Obtained array:\n";
		displayArray(std::cout, myArray, 1, 10);
		return false;
	}
}

int main()
{
	
	if (test_array3x4() && test_array1x10() 
	&& test_array1x1() && test_array1x1() 
	&& test_array5x5())
		std::cout << "Filling array tests run successfully\n\n";
	else
		std::cout << "\nUnit tests failed\n";
		
	testException(0, 10);
	testException(-10, 12);
	testException(7, 7);
	testException(13, 0);
	std::cout << "\nEnd of tests.\n";
	return 0;
}
