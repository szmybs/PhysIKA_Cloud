#include"SatDataCloud_Lite.h"
#include"string"

int main()
{   
    SatDataCloud typhoon;
    // 参数分别为 - 定位输入文件的日期 - 输入文件路径 - 输出文件路径 - 输出文件名 - 提取台风的长度 - 提取台风的宽度
	//typhoon.Run(Date(2013,6,26), "D:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\", ".\\", "typhoon20130626_50", 512, 512);

    vector<std::string> files;
	files.emplace_back("D:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\FY2E_SEC_VIS_MLS_20130625_0500.AWX");
    files.emplace_back("D:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\FY2E_SEC_IR1_MLS_20130625_0500.AWX");
    files.emplace_back("D:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\FY2E_SEC_IR2_MLS_20130625_0500.AWX");
    files.emplace_back("D:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\FY2E_SEC_IR3_MLS_20130625_0500.AWX");
    files.emplace_back("D:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\FY2E_SEC_IR4_MLS_20130625_0500.AWX");

	// 参数分别为 - 文件列表 - 输出文件路径 -输出文件名 - 提取台风的长度 - 提取台风的宽度
    typhoon.Run(files, ".\\", "typhoon201306250500", 512, 512);

    return 0;
}