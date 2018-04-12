#pragma once
#include "stdafx.h"

#define CHECK(x) if(x)return x

#define WIDTH 1360
#define HEIGHT 1024

#define FISH_READ_ERROR -10
#define FISH_ENHANCE_PARA_ERROR -12

// 错误全用负数，FISH开头 ERROR结尾
// 两位的是读取和增强可能出现的
// split出错可以用三位的

using namespace cv;
using namespace std;

typedef struct Tiff2Mat_imgae {
    Mat head_image;
    Mat chromosome_image1;
    Mat chromosome_image2;
    Mat chromosome_image3;
} ChrImgs;

// 左上(top left)、右下(lower right) 坐标
typedef struct pos {
    int tl_x, tl_y, br_x, br_y;
};

// 一个精子的检测结果
typedef struct chrInfo {
    int id, status;  // id为此精子在图上编号，status 正常 0, 异常 1;
    int white_num, green_num, red_num;  // 三种染色体个数
    pos head_p;  // 精子头坐标信息
    vector<pos> white_p;  // 染色体坐标信息（不一定只有一个）
    vector<pos> green_p; 
    vector<pos> red_p;
    float average_gray;  // 平均灰度
};

// 一张图片的结果( _fish_Series_0x.tif )
typedef struct singleImg {
    int single_head_num, mutiple_head_num;
    int bad_total_num, bad_white_num, bad_green_num, bad_red_num;
    // 四张图，带框
    vector<chrInfo> chs; // 每个精子的结果
    vector<vector<int>> mutiChId;  // 粘连的精子头编号组，多个粘连，
    float average_gray;  // 平均灰度
};



void show(String name, Mat img) {
    namedWindow(name, CV_WINDOW_AUTOSIZE);
    imshow(name, img);
    waitKey(0);
    return;
}