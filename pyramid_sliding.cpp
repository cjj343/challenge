#include <iostream>
#include <fstream>

bool checkBurned(bool * const ptr, const int);

int main()
{
	int rows;
	int *pyramid = nullptr;
	bool *burned = nullptr;
	int *distance = nullptr;
	int elements;
	int index = 0;
	int row = 1;
	int nodes;
	int count = 0;

	std::ifstream inputFile;
	int value;

	inputFile.open("bigchallengenosol.txt");

	inputFile >> rows;
	inputFile.clear();
	

	elements = ((1 + static_cast<double>(rows))/2)*rows;
	nodes = elements - rows;

	pyramid = new int[elements];
	burned = new bool[nodes];
	distance = new int[elements];

	while (inputFile >> value)
	{
		pyramid[count] = value;
		count++;
		inputFile.clear();
	}

	burned[0] = true;
	distance[0] = pyramid[0];

	for (int i = 1; i < elements; i++)
	{
		distance[i] = INT_MAX;
	}

	for (int i = 1; i < nodes; i++)
	{
		burned[i] = false;
	}


	while (checkBurned(burned, nodes))
	{
		distance[(index + row)] = distance[index] + pyramid[(index + row)];
		distance[((index + row) + 1)] = distance[index] + pyramid[((index + row) + 1)];

		int lowest = INT_MAX;

		for (int i = 0; i < nodes; i++)
		{
			if (distance[i] < lowest & burned[i] != true)
			{
				lowest = distance[i];
				index = i;
			}
		}

		burned[index] = true;


		for (int i = 2; i < rows; i++)
		{
			if (index < ((1 + static_cast<double>(i)) / 2)*i & (index >= ((1 + static_cast<double>((i - 1))) / 2)*(i - 1)))
			{
			row = i;
			}
		}
	}

	int lowest = INT_MAX;

	for (int i = ((1 + static_cast<double>((rows - 1))) / 2)*(rows - 1); i < elements; i++)
	{
		if(distance[i] < lowest)
		{
			lowest = distance[i];
		}
	}

	std::cout << lowest << std::endl;

	delete[] pyramid;
	pyramid = nullptr;

	delete[] burned;
	burned = nullptr;

	delete[] distance;
	distance = nullptr;

	inputFile.close();

	return 0;
}

bool checkBurned(bool * const ptr, const int y)
{
	bool test = false;



	for (int i = 0; i < y; i++)
	{
		if (ptr[i] == false)
		{
			test = true;
			return test;
		}
	}

	return test;



}