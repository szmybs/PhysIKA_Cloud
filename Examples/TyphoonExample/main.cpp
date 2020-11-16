#include"SatDataCloud_Lite.h"

int main()
{   
    SatDataCloud typhoon;
    typhoon.Run(Date(2013,7,10), "D:\\Code\\PhysIKA_Cloud_Data\\Typhoon\\SULI\\SEC\\", ".", "typhoon20130710");
    return 0;
}