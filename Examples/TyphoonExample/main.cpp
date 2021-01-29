#include"SatDataCloud_Lite.h"

int main()
{   
    SatDataCloud typhoon;
    // 参数分别为 - 定位输入文件的日期 - 输入文件路径 - 输出文件路径 - 输出文件名 - 提取台风的长度 - 提取台风的宽度
    typhoon.Run(Date(2013,6,26), "E:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\", ".\\", "typhoon20130626_50", 512, 512);
    return 0;
}