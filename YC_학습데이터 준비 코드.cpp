#include "tools.h"

string get_input_name(int );
string get_output_name(int, int);

int main()
{
	for (int i = 1; i <= 72; ++i)
	{
		string image_string = get_input_name(i);
		Mat src = imread(image_string,IMREAD_GRAYSCALE);

		for (int j = 1; j <= 178; ++j)
		{
			Mat ROI = src(rect[j-1]).clone();
			string output = get_output_name(i, j);
			imwrite(output, ROI);
		}
	}

}

string get_input_name(int i)
{
	string input_string = "¿øº»";

	char c = i + '0';

	if (i < 10)
	{
		char c = i + '0';
		input_string.push_back(c);
	}
	else if (i >= 10)
	{
		int i1 = i / 10;
		int i2 = i % 10;
		char c1 = i1 + '0';
		char c2 = i2 + '0';

		input_string.push_back(c1);
		input_string.push_back(c2);
	}


	input_string.append(".bmp");

	return input_string;
}

string get_output_name(int i, int j)
{
	string output_string;

	if (i < 10)
	{
		char c = i + '0';
		output_string.push_back(c);
	}
	else if (i >= 10)
	{
		int i1 = i / 10;
		int i2 = i % 10;
		char c1 = i1 + '0';
		char c2 = i2 + '0';

		output_string.push_back(c1);
		output_string.push_back(c2);
	}

	output_string.push_back('_');

	if (j < 10)
	{
		char c = j + '0';
		output_string.push_back(c);
	}
	else if (j >= 10 && j < 100)
	{
		int i1 = j / 10;
		int i2 = j % 10;
		char c1 = i1 + '0';
		char c2 = i2 + '0';

		output_string.push_back(c1);
		output_string.push_back(c2);
	}
	else if (j >= 100)
	{
		int i1 = j / 100;
		int i2 = (j % 100) / 10;
		int i3 = (j % 100) % 10;

		char c1 = i1 + '0';
		char c2 = i2 + '0';
		char c3 = i3 + '0';

		output_string.push_back(c1);
		output_string.push_back(c2);
		output_string.push_back(c3);
	}



	output_string.append(".bmp");

	return output_string;
}
