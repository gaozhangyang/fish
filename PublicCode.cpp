// PublicCode.cpp: 公共代码。
//

#include "stdafx.h"

using namespace std;
using namespace cv;


void show(String name, Mat img) {
    namedWindow(name, CV_WINDOW_AUTOSIZE);
    imshow(name, img);
    return;
}

//--------------------------------

/*
图像USM锐化
@param src 原始图像
@param dst 输出图像
@param nAmount USM参数
*/
void sharpen_USM(Mat src, Mat &dst, int nAmount) {
    double sigma = 3;  // 3最好，小于3精子变小，大于3精子粘连变多
    int threshold = 1; 
    float amount = nAmount / 100.0f;  // 500

    Mat imgBlurred;
    GaussianBlur(src, imgBlurred, Size(), sigma, sigma);

    Mat lowContrastMask = abs(src - imgBlurred)<threshold;
    dst = src * (1 + amount) + imgBlurred * (-amount);
    src.copyTo(dst, lowContrastMask);
    return;
}

void enhance_0(Sperm &spe) {
    int USMpara = 600;
    Mat m0 = Mat::zeros(spe.raw.size(), spe.raw.type());
    Mat m1 = Mat::zeros(spe.head_image.size(), spe.head_image.type());
    Mat m2 = Mat::zeros(spe.chromosome_image1.size(), spe.chromosome_image1.type());
    Mat m3 = Mat::zeros(spe.chromosome_image2.size(), spe.chromosome_image2.type());
    Mat m4 = Mat::zeros(spe.chromosome_image3.size(), spe.chromosome_image3.type());
    sharpen_USM(spe.raw, m0, USMpara);
    sharpen_USM(spe.head_image, m1, USMpara);
    sharpen_USM(spe.chromosome_image1, m2, USMpara);
    sharpen_USM(spe.chromosome_image2, m3, USMpara);
    sharpen_USM(spe.chromosome_image3, m4, USMpara);
    spe.raw = m0.clone();
    spe.head_image = m1.clone();
    spe.chromosome_image1 = m2.clone();
    spe.chromosome_image2 = m3.clone();
    spe.chromosome_image3 = m4.clone();

    return;
}

void enhance_1(Mat &img) {
    //Mat m1 = Mat::zeros(img.size(), img.type());
    Mat m2 = Mat::zeros(img.size(), img.type());
    //img.convertTo(m1, -1, 1, -30);  // 亮度 -30，
    //sharpen_USM(m1, m1, 500);
    sharpen_USM(img, m2, 600);
    /*show("raw", img);
    show("m1", m1);
    show("m2", m2);
    Mat mm = imread("C:\\Users\\z\\Desktop\\fish\\Q0518\\14-19-11\\01.tif");
    show("mm", mm);
    waitKey();*/
    img = m2.clone();
    return;
    return;
}


/*
读取原图并分割
@param dirPath 图片所在文件夹路径
@param fileName 图片名称
@param spe 精子结构体
*/
int ReadAndSplit(String dirPath, String fileName, Sperm &spe) {
    Mat img = imread(dirPath + "\\" + fileName);
    if (img.empty()) return FISH_READ_ERROR;  // 读取错误 返回-10

    Sperm spe;
    // split read to 结构体

    return 0;
}

//--------------------------

/*
对单个图片进行处理
@param dirPath 图片所在文件夹路径
@param fileName 图片名称
@param enhanceType 增强方式
*/
int start(String dirPath, String fileName, int enhanceType) {
    Sperm spe;
    int flag = -1;  // 函数运行情况参数

    // opencv不能处理八页，所以改成先split再分别增强4次
    flag = ReadAndSplit(dirPath, fileName, spe);
    CHECK(flag);  // 出错返回错误参数

    if (enhanceType == 0) enhance_0(spe);  // 参数等于0是对结构体整体
    else if (enhanceType == 1) enhance_1(spe.raw);  // 参数等于1是我测试单张用的
    else return FISH_ENHANCE_PARA_ERROR;
    // 现在只实现了USM锐化，函数是对结构体做。

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