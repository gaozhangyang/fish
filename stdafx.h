// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream> 
#include <exception> 
#include <vector>
#include <string.h>
#include <direct.h>


// TODO: 在此处引用程序需要的其他头文件
#include <opencv2\opencv.hpp>
#include <opencv2/core/core.hpp>
#include "tiffio.h"
#include "highgui.h"
#include "cvaux.h"
#include "cxcore.h"
#include "opencv2/imgproc.hpp"

#include "FishHead.h"

#define BYTE unsigned char
#define TIFF_SSIZE_T signed int