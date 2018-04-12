// PublicCode.cpp: 公共代码。
//

#include "stdafx.h"

using namespace std;
using namespace cv;


void show(String name, Mat img) {
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


/*
读取原图并增强，只有两种方式
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
    Mat rawImg;
    int flag = -1;  // 函数运行情况参数
    
    flag = ReadAndEnhance(dirPath, fileName, enhanceType, rawImg);
    CHECK(flag);  // 出错返回错误参数

    show("1", rawImg);
    // flag = split(RawImg ... );
    // CHECK(flag);

    // findHead
    // 检测 等后续操作
    // 这个函数里最好都是调用
    // 可能会出错，记得返回非零，方便主界面提示

    /*
    这里将这张图片放到一个文件中，名字固定叫_fish_Series_01.tif，
    然后将这个文件夹传给你，在这个文件夹里建立split和test文件，将结果放进去
    然后这里将这个人的信息处理好保存好之后，会清空这个文件夹，
    将下一个图片复制进去，名字还是_fish_Series_01.tif，重复上述操作
    */

    return 0;  // 正常执行返回0，其他不为0
}

int main()
{
    String dirPath = "C:\\Users\\z\\Desktop\\fish\\Q0518\\3-7-15";
    String fileName = "_fish_Series_01.tif";

    cout << start(dirPath, fileName, 0) << endl;;

	system("pause");
    return 0;
}