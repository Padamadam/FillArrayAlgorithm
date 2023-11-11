#include <array>
#include <ostream>
#include <iomanip>
#include <exception>
#include "FillArray.h"

void fillMyArray(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns)
{
	if (rows == 0 || rows > maxRows || columns == 0 || columns > maxColumns)
		throw std::invalid_argument("Invalid array size.");
	int value = 1;
	int m = rows - 1;
	int n = columns - 1;
	int row_size = rows - 1;
	int column_size = columns - 1;


	for (int y = 0; y <= column_size; y++)
	{
		int k = row_size;
		int l = y;
		while (l >= 0 && k >= 0)
		{
			array[k][l] = value++;
			k--;
			l--;
		}
	}
		for (int x = row_size - 1 ; x >= 0; x--)
		{
			int k = x;
			int l = column_size;
			while (k >= 0)
			{
				array[k][l] = value++;
				k--;
				l--;
			}
		}
}


void displayArray(std::ostream& stream, std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns)
{
	for (int row = 0; row < rows; ++row)
	{
		for (int column = 0; column < columns; ++column)
			stream << std::setw(4) << array[row][column];
		stream << std::endl;
	}
}
