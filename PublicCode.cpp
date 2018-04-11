#include "stdafx.h"
#include "Structs.h"

#define WIDTH 1360
#define HEIGHT 1024
#define FISH_READ_ERROR -10
#define FISH_ENHANCE_PARA_ERROR -12

// 错误全用负数，FISH开头 ERROR结尾
// 两位的是读取和增强可能出现的
// split出错可以用三位的

using namespace std;
using namespace cv;


void show(String name, Mat img)
{
	namedWindow(name, CV_WINDOW_AUTOSIZE);
	imshow(name, img);
    waitKey(0);
	return;
}

//--------------------------------

void enhance_0(Mat &img) {
    
    return;
}

void enhance_1(Mat &img) {

    return;
}

// 读取原图并增强
int ReadAndEnhance(String dirPath, String fileName, Mat &img, int enhanceType)
{
    img = imread(dirPath + "\\" + fileName);
    if (img.empty()) return FISH_READ_ERROR;  // 读取错误 返回-10

    switch (enhanceType) {
        case 0: enhance_0(img); break;
        case 1: enhance_1(img); break;
        default: return FISH_ENHANCE_PARA_ERROR; // 增强参数错误 返回-12
    }

    return 0;
}

//--------------------------

int start(String dirPath, String fileName, int enhanceType)
{
    Mat RawImg;
    int flag = -1;  // 函数运行情况参数
    
    flag = ReadAndEnhance(dirPath, fileName, RawImg, 0);
    if (flag != 0) return flag; // 出错返回错误参数

    // split

    // 去燥？？？ TODO(@izhx)

    // findHead
    // 检测 等后续操作
    // 这个函数里最好都是调用
    // 可能会出错，记得返回非零，方便主界面提示

    /*
    如果用文件，就生成一个与图片文件同名的文件夹，
    里面是四个图片，加上一个json文件，
    这样java读json应该更方便，
    */

    return 0;  // 正常执行返回0，其他不为0
}