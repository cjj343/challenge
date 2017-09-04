#include <iostream>
#include <fstream>

int main()
{
	int rows;
	int *pyramid = nullptr;
	int elements;

	int count = 0;

	std::ifstream inputFile;
	int value;

	inputFile.open("bigchallengenosol.txt");

	inputFile >> rows;
	inputFile.clear();

	elements = ((1 + static_cast<double>(rows)) / 2)*rows;

	pyramid = new int[elements];

	while (inputFile >> value)
	{
		pyramid[count] = value;
		count++;
		inputFile.clear();
	}

	for (int i = (rows - 1); i > 0; i--)
	{
		for (int x = ((i-1)*((i-1) + 1) / 2); x < (i*(i + 1) / 2); x++)
		{
			if ((pyramid[x] + pyramid[x+i]) < (pyramid[x] + pyramid[x + i + 1]))
			{
				pyramid[x] = (pyramid[x] + pyramid[x+i]);
			}
			else
			{
				pyramid[x] = (pyramid[x] + pyramid[x + i + 1]);
			}
		}
	}

	std::cout << pyramid[0] << std::endl;

	delete[] pyramid;
	pyramid = nullptr;

	inputFile.close();

	return 0;
}