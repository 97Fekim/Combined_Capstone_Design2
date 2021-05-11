#include <opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

string get_input_name(string str, int i);

int main()
{
	Mat src;
	/* 200장의 사진이 8종류임에 따라 8인덱스의 배열로 지정 */
	string ball[8] = { "big", "big_noise", "small", "small_noise", "mid", "mid_noise", "third", "third_noise" };
	string temp;

	/* 8 x 25 번 총 200번의 변환을 시행 */
	for (int j = 0; j < 8; ++j)
	{
		temp = ball[j];
		for (int i = 1; i <= 25; ++i)
		{
			src = imread(get_input_name(temp,i), IMREAD_GRAYSCALE);
			normalize(src, src, 0.0, 255.0, NORM_MINMAX);	// 이곳에서 전처리를 수행합니다.
			imwrite(get_input_name(temp, i), src);
		}
	}
	return 0;

}

/* 이미지 이름 포맷에 맞게 이름을 가져오는 함수 */
string get_input_name(string str, int i)
{
	string input_string = str;

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


	input_string.append(".jpg");

	return input_string;
}