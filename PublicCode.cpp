#include "stdafx.h"
#include "Structs.h"

using namespace cv;
using namespace std;

void show(String name, Mat img)
{
	namedWindow(name, CV_WINDOW_AUTOSIZE);
	imshow(name, img);
	return;
}

// 读取原图并增强
int ReadAndEnhance(string Dirpath, string fileName, Mat &img)     {

    // read

    // enhance

    return 0;  // 出错要记得返回非零
}

int start(string Dirpath, string fileName) {

    Mat RawImg;
    if (ReadAndEnhance(Dirpath, fileName, RawImg) != 0) return 1; // 出错返回1退出

    // split 等后续操作

    /*
    如果用文件，就生成一个与图片文件同名的文件夹，
    里面是四个图片，加上一个json文件，
    这样java读json应该更方便，
    */

    return 0;  // 正常执行返回0，其他不为0
}