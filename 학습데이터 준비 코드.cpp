#include "tools.h"

string get_input_name(int );
string get_output_name(int, int);

int main()
{
	/* 총 72장의 전체 영상에 대해 반복 */
	for (int i = 1; i <= 72; ++i)
	{
		string image_string = get_input_name(i);		// 전체 영상의 이름 가져오기
		Mat src = imread(image_string,IMREAD_GRAYSCALE);// 가져온 이름으로 전체 영상 가져오기

		/* 하나의 전체 영상을 178개의 개별 이미지로 자르기 */
		for (int j = 1; j <= 178; ++j)
		{
			Mat ROI = src(rect[j-1]).clone();
			string output = get_output_name(i, j);
			imwrite(output, ROI);
		}
	}

}

/* i를 넣으면 원본i.jpg를 리턴하는 함수 */
string get_input_name(int i)
{
	string input_string = "원본";

	/* 정수i를 문자형으로 변환 */
	char c = i + '0';

	/* i가 1자리 일때 */
	if (i < 10)
	{
		char c = i + '0';
		input_string.push_back(c);
	}
	else if (i >= 10)	// i가 2자리 일 때
	{
		int i1 = i / 10;
		int i2 = i % 10;
		char c1 = i1 + '0';
		char c2 = i2 + '0';

		input_string.push_back(c1);
		input_string.push_back(c2);
	}

	/* 원본. 에다가 bmp를 붙이기 */
	input_string.append(".bmp");

	return input_string;
}

/* 개별 이미지의 형식은 i_j.bmp 이어야 한다 */
string get_output_name(int i, int j)
{
	string output_string;

	/* i가 한 자리일 때 때 */
	if (i < 10)
	{
		char c = i + '0';
		output_string.push_back(c);
	}
	else if (i >= 10)	/* i가 두 자리일 때 */
	{
		int i1 = i / 10;
		int i2 = i % 10;
		char c1 = i1 + '0';
		char c2 = i2 + '0';

		output_string.push_back(c1);
		output_string.push_back(c2);
	}

	output_string.push_back('_');
	
	/* j가 한 자리일 때 */
	if (j < 10)
	{
		char c = j + '0';
		output_string.push_back(c);
	}
	else if (j >= 10 && j < 100)	// j가 두 자리일 때 
	{
		int i1 = j / 10;
		int i2 = j % 10;
		char c1 = i1 + '0';
		char c2 = i2 + '0';

		output_string.push_back(c1);
		output_string.push_back(c2);
	}
	else if (j >= 100)		// j가 세 자리일 때
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


	/* 원본. 에다가 bmp를 붙이기 */
	output_string.append(".bmp");

	return output_string;
}
