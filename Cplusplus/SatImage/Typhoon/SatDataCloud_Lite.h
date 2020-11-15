#pragma once
#include "global.h"
#include "../Utility/Vector.h"
#include "../Utility/Color.h"
#include <vector>
#include <algorithm> 
#include "../Utility/perlin.h"
enum SatDataType { IR1, IR2, IR3, IR4, VIS, CLC, CTT };
enum DrawType { LongLat, SunZA, Seg, TopSurface, BottomSurface, Thick, EffRadius, Extinction };
struct Date
{
	int year;
	int month;
	int day;
	Date()
	{
		year = 2013;
		month = 7;
		day = 10;
	}
	Date(int year, int month, int day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
};

//9210图像产品格式：
//9210图像产品主要有FY2C中国陆地区域云图、FY2C中国海区图。这两种产品格式及说明如下。
//文件格式：二进制格式1字节存放；大小为512列*518行（共512*518字节），其中前6行为头记录(包含定标表)，其余512行为数据部分。头记录的格式如下表所示：
//一级文件头记录结构：
//序号字节序号字节数类型描述字11－1212Char×12SAT96文件名213－142Int16整型数的字节顺序315－162Int16第一级文件头长度417－182Int16第二级文件头长度519－202Int16填充段数据长度621－222Int16记录长度723－242Int16文件头占用记录数825－262Int16产品数据占用记录数927－282Int16产品类别1029－302Int16压缩方式1131－388Char×8格式说明字串1239－402Int16产品数据质量标记
//二级文件头记录结构：
//序号字节序号字节数类型描述字141－488A×8卫星名249－502I×2时间（年）351－522I×2时间（月）453－542I×2时间（日）555－562I×2时间（时）657－582I×2时间（分）759－602I×2通道号861－622I×2投影方式963－642I×2图象宽度1065－662I×2图象高度1167－682I×2图象左上角扫描线号1269－702I×2图象左上角象元号1371－722I×2抽样率1473－742I×2地理范围（北纬）1575－762I×2地理范围（南纬）1677－782I×2地理范围（西经）1779－802I×2地理范围（东经）1881－822I×2投影中心纬度1983－842I×2投影中心经度2085－862I×2投影标准纬度1（或标准经度）2187－882I×2标准投影纬度22289－902I×2投影水平分辨率2391－922I×2投影垂直分辨率2493－942I×2地理网格叠加标志2595－962I×2地理网格叠加值2697－982I×2调色表数据块长度2799－1002I×2定标数据块长度28101－1022I×2定位数据块长度29103－1042I×2保留
///*第一级头记录*/
typedef struct AwxFileFirstHeader
{
	char strFileName[12]; //文件名 〖1〗
	short int iByteOrder; //形数的字节顺序 〖2〗
	short int iFirstHeaderLength; //第一级文件头长度 〖3〗
	short int iSecondHeaderLength; //第二级文件头长度 〖4〗
	short int iFillSectionLength; //填充段数据长度
	short int iRecoderLength; //记录长度 〖5〗
	short int iRecordsOfHeader; //文件头占用记录数 〖5A〗
	short int iRecordsOfData; //产品数据占用记录数
	short int iTypeOfProduct; //产品类别 〖6〗
	short int iTypeOfCompress; //压缩方式 〖7〗
	char strVersion[8]; //格式说明字串 〖8〗
	short int iFlagOfQuality; //产品数据质量标记 〖9〗
}AwxFileFirstHeader;

/*静止气象卫星图像产品的第二级文件头记录格式*/
typedef struct AwxFileGeoSatelliteSecondHeader
{
	char strSatelliteName[8]; //卫星名
	short int iYear; //时间（年）
	short int iMonth; //时间（月）
	short int iDay; //时间（日）
	short int iHour; //时间（时）
	short int iMinute; //时间（分）
	short int iChannel; //通道号
	short int iFlagOfProjection; //投影方式
	short int iWidthOfImage; //图像宽度
	short int iHeightOfImage; //图像高度
	short int iScanLineNumberOfImageTopLeft; //图像左上角扫描线号
	short int iPixelNumberOfImageTopLeft; //图像左上角象元号
	short int iSampleRatio; //抽样率
	short int iLatitudeOfNorth; //地理范围（北纬）
	short int iLatitudeOfSouth; //地理范围（南纬）
	short int iLongitudeOfWest; //地理范围（西经）
	short int iLongitudeOfEast; //地理范围（东经）
	short int iCenterLatitudeOfProjection;//投影中心纬度 度×100
	short int iCenterLongitudeOfProjection;//投影中心经度 度×100
	short int iStandardLatitude1;//标准投影纬度1（或标准经度）
	short int iStandardLatitude2; //标准投影纬度2
	short int iHorizontalResolution;//投影水平分辨率 公里×100
	short int iVerticalResolution; //投影垂直分辨率 公里×100
	short int iOverlapFlagGeoGrid; //地理网格叠加标志
	short int iOverlapValueGeoGrid;//地理网格叠加值
	short int iDataLengthOfColorTable; //调色表数据块长度
	short int iDataLengthOfCalibration; //定标数据块长度
	short int iDataLengthOfGeolocation; //定位数据块长度
	short int iReserved; //保留
}AwxFileGeoSatelliteSecondHeader;


class SatDataCloud
{
public:
	float* ir1Data;
	float* ir2Data;
	float* ir3Data;
	float* ir4Data;
	float* visData;
	float* clcData;
	float* cttData;

	float* irReflectanceData;//ir4->reflectance

	int* pixelTypeList; //0-ground, 1-cloud, 2-thin cloud(thin cirrus)
	float* cthList; //cloud top height of a day

	float* thinCloudTList;
	float* vis_thick_data;
	float* ir4_thick_data;
	float* efficientRadius_data;
	float* geo_thick_data;
	float* extinctionPlane;

	Vector2 dataRange[7];

public:
	SatDataCloud(void);
	void Init();
	void Run(Date date, string satStr, string savePath, string saveName);

	//position information
	float center_theta;
	float center_phi;

	//longitude latitude, altitude
	float* longitudeLatitudeTable;
	float* altitudeTable;
	void CreateLongLatTable(const char* longLatFile);
	void CreateLongLatTable();
	void DrawLongLatTable();
	void CreateAltitudeTable();

	//the azimuth angle and the zenith angle of the satellite
	float* satZenith_mat_E;
	float* satAzimuth_mat_E;

	float* satZenith_mat_F;
	float* satAzimuth_mat_F;

	void CreateSatZenithAzimuthIfo();

	//the azimuth angle and the zenith angle of the sun
	float* sunZenithAzimuth_mat;
	int CreateSunZenithAzimuthIfo(Date date);
	void CreateSunZenithAzimuthIfoFromFile(const char* filename);
	void DrawSunZenithAzimuth(int curFrame);

	//read satellite image data
	void IntepImgData(float* img_data, int img_width, int img_height, float* pData, int width, int height);
	void IntepImgData(int nframe, SatDataType channel, float* img_data, int img_width, int img_height, float* pData, int width, int height);

	bool ReadSingleSatData(char* filename, float* pData, SatDataType channel, int nframe);
	void ReadSatData(CString satStr, Date date, SatDataType channel);
	void DrawSatData(SatDataType channel, int nframe);

	//ground temperature
	float* ground_temperature_mat; //ir1
	float* ground_temperature_mat_ir2; //ir2
	void CreateGroundTemperatureTable(CString satStr, Date startDate, SatDataType channel);
	bool ReadFixedTimeAwxData(CString satStr, float* pData, Date date, int hour, int minute, SatDataType channel, int nframe);
	void DrawGroundTemperature(int nframe);

	//pixel type
	void CloudGroundSegment(); //cloud-ground labeling
	void Classification(); //cirrus-water-ice labeling
	void LabelCirrus(int nframe); //cirrus detection
	void SegmentSatDataKMeans(int nframe); //ice-water labeling
	void SegmentSatDataIRWV(int nframe);
	void DrawPixelType(int nframe);

	//cloud top height
	void CreateCloudTopHeight();
	bool FindaAndb(int nframe, int i, int j, float& a, float& b);
	void DrawCloudTopSurface(int nframe);
	void ComputeTriangleNormal(double normal[3], double PA[3], double PB[3], double PC[3]);

	//ir4 to reflectance
	float PlanckFunction(int channel, float T);
	void IR4Temperature2Reflectance();
	void ModifyReflectance();

	//cloud properties of the ice cloud and the water cloud.
	void ComputeCloudProperties_MEA();
	void DrawEfficientRadius(int nframe);

	//geometric thickness
	void ComputeGeoThick();
	void DrawGeoThick(int nframe);
	void DrawCloudBottomSurface(int nframe);
	void DrawExt(int nframe);

	//output to file
	void GenerateExtinctionFieldFile(int startFrame, int endFrame, int Z_Res);
	void GenerateCloudParticlesFile(string savePath, string saveName, int startFrame, int endFrame);

	float Dis2Boundary(float samplingpoint[3], float* tempCTH, float* temCBH, int X_RES, int Y_RES);

	void GenerateCloudFieldIfoFile(int startFrame, int endFrame);

	void GenerateIfoForDobashi();

	//output file for earth rendering
	void GenerateCloudFiledFileEarth(int startFrame, int endFrame, int X_Res, int Y_Res, int Z_Res);
	Vector3 MatMult(float Mat[9], Vector3 vec);

	bool FindPosInLgLatTable(float lg, float lat, int& y, int& x);

public:
	void TimeChannel2FileName(CString satStr, char filename[256], Date date, int hour, int minute, SatDataType channel);

	float PhaseFunction(Vector3 v1, Vector3 v2);

	float MetaballFunction(float r, float R);

	float InterPolateCTHField(float samplePoint[2], float* cthList, int nframe);
	float InterPolateGeoThickField(float samplePoint[2], float* geo_thick_data, int nframe);
	float InterPolateExtinctionPlane(float samplePoint[2], float* extinctionPlane, int nframe);

	bool isProbabilityGreater(double threahold);
	//draw each type
	void Draw(DrawType type);
	void DrawEarth();
	void DrawSimulationCube();

	//cloud particles data file
	int puffNumber;
	vector<Vector3> puffPosVec;
	vector<float> puffSizeVec;
	vector<Color4> puffColorVec;
	vector <float> puffExtVec;

	//output cloud model: cloudxx.dat
	void ExportCloudModel(char* cloudfile);

	void ExportCloudFieldIfo(int nframe, char* cloudfile);
	bool FindSlope(int nframe, int i, int j, float& slope, float* pdata_ir, float* pData_wv);
	void RenderFrame(SatDataType channel, int n_frame);
	void RenderFrame(DrawType dtype);

	void PrintRunIfo(string info);

	Perlin* perlin;
public:
	~SatDataCloud(void);
};
