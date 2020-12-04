#include"SatDataCloud_Lite.h"

int main()
{   
    SatDataCloud typhoon;
    typhoon.Run(Date(2013,6,26), "E:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\", ".\\", "typhoon20130626_50", 512, 512);
    return 0;
}