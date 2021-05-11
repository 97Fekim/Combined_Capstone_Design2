/* i_j.jpg의 형식만 갖추고 있다면 폴더에 넣기만 하면되는 방식 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

string get_output_name(int i, int j);

int main()
{
	Mat src;
	
	/* i_j.jpg 의 형식만 갖췄다면 폴더안에 있는 모든 사진 변환 */ 
	for (int i = 1; i <= 72; ++i)
	{
		for (int j = 1; j <= 178; ++j)
		{
			src = imread(get_output_name(i,j),IMREAD_GRAYSCALE);
			if (src.empty())	// 폴더안에 i_j.jpg가 없다면 패스,, 있는 사진만 변환
				continue;
			normalize(src, src, 0.0, 255.0, NORM_MINMAX);	// 현재는 스트레칭을 할 것이므로 스트레칭 한 줄 추가

			imwrite(get_output_name(i,j),src);
		}

	}

}

/* 학습데이터준비코드1 참조 */
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

	output_string.append(".jpg");

	return output_string;
}
