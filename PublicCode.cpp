// PublicCode.cpp: 公共代码。
//

#include "stdafx.h"

using namespace std;
using namespace cv;


//--------------------------------

void enhance_0(Mat &img) {
    
    return;
}

void enhance_1(Mat &img) {

    return;
}


/*
读取原图并增强
@param dirPath 图片所在文件夹路径
@param fileName 图片名称
@param enhanceType 增强方式
@param img 接收图像的Mat变量
*/
int ReadAndEnhance(String dirPath, String fileName, int enhanceType, Mat &img)
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

/*
对单个图片进行处理
@param dirPath 图片所在文件夹路径
@param fileName 图片名称
@param enhanceType 增强方式
*/
int start(String dirPath, String fileName, int enhanceType)
{
    Mat RawImg;
    int flag = -1;  // 函数运行情况参数
    
    flag = ReadAndEnhance(dirPath, fileName, enhanceType, RawImg);
    CHECK(flag);  // 出错返回错误参数

    // flag = split(RawImg ... );
    // CHECK(flag);

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

int main()
{
    String dirPath = "C:\\Users\\z\\Desktop\\fish\\Q0518\\3-7-15";
    String fileName = "_fish_Series_01.tif";

    cout << start(dirPath, fileName, 0) << endl;;

	system("pause");
	waitKey(0);
    return 0;
}