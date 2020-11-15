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

//9210ͼ���Ʒ��ʽ��
//9210ͼ���Ʒ��Ҫ��FY2C�й�½��������ͼ��FY2C�й�����ͼ�������ֲ�Ʒ��ʽ��˵�����¡�
//�ļ���ʽ�������Ƹ�ʽ1�ֽڴ�ţ���СΪ512��*518�У���512*518�ֽڣ�������ǰ6��Ϊͷ��¼(���������)������512��Ϊ���ݲ��֡�ͷ��¼�ĸ�ʽ���±���ʾ��
//һ���ļ�ͷ��¼�ṹ��
//����ֽ�����ֽ�������������11��1212Char��12SAT96�ļ���213��142Int16���������ֽ�˳��315��162Int16��һ���ļ�ͷ����417��182Int16�ڶ����ļ�ͷ����519��202Int16�������ݳ���621��222Int16��¼����723��242Int16�ļ�ͷռ�ü�¼��825��262Int16��Ʒ����ռ�ü�¼��927��282Int16��Ʒ���1029��302Int16ѹ����ʽ1131��388Char��8��ʽ˵���ִ�1239��402Int16��Ʒ�����������
//�����ļ�ͷ��¼�ṹ��
//����ֽ�����ֽ�������������141��488A��8������249��502I��2ʱ�䣨�꣩351��522I��2ʱ�䣨�£�453��542I��2ʱ�䣨�գ�555��562I��2ʱ�䣨ʱ��657��582I��2ʱ�䣨�֣�759��602I��2ͨ����861��622I��2ͶӰ��ʽ963��642I��2ͼ����1065��662I��2ͼ��߶�1167��682I��2ͼ�����Ͻ�ɨ���ߺ�1269��702I��2ͼ�����Ͻ���Ԫ��1371��722I��2������1473��742I��2����Χ����γ��1575��762I��2����Χ����γ��1677��782I��2����Χ��������1779��802I��2����Χ��������1881��822I��2ͶӰ����γ��1983��842I��2ͶӰ���ľ���2085��862I��2ͶӰ��׼γ��1�����׼���ȣ�2187��882I��2��׼ͶӰγ��22289��902I��2ͶӰˮƽ�ֱ���2391��922I��2ͶӰ��ֱ�ֱ���2493��942I��2����������ӱ�־2595��962I��2�����������ֵ2697��982I��2��ɫ�����ݿ鳤��2799��1002I��2�������ݿ鳤��28101��1022I��2��λ���ݿ鳤��29103��1042I��2����
///*��һ��ͷ��¼*/
typedef struct AwxFileFirstHeader
{
	char strFileName[12]; //�ļ��� ��1��
	short int iByteOrder; //�������ֽ�˳�� ��2��
	short int iFirstHeaderLength; //��һ���ļ�ͷ���� ��3��
	short int iSecondHeaderLength; //�ڶ����ļ�ͷ���� ��4��
	short int iFillSectionLength; //�������ݳ���
	short int iRecoderLength; //��¼���� ��5��
	short int iRecordsOfHeader; //�ļ�ͷռ�ü�¼�� ��5A��
	short int iRecordsOfData; //��Ʒ����ռ�ü�¼��
	short int iTypeOfProduct; //��Ʒ��� ��6��
	short int iTypeOfCompress; //ѹ����ʽ ��7��
	char strVersion[8]; //��ʽ˵���ִ� ��8��
	short int iFlagOfQuality; //��Ʒ����������� ��9��
}AwxFileFirstHeader;

/*��ֹ��������ͼ���Ʒ�ĵڶ����ļ�ͷ��¼��ʽ*/
typedef struct AwxFileGeoSatelliteSecondHeader
{
	char strSatelliteName[8]; //������
	short int iYear; //ʱ�䣨�꣩
	short int iMonth; //ʱ�䣨�£�
	short int iDay; //ʱ�䣨�գ�
	short int iHour; //ʱ�䣨ʱ��
	short int iMinute; //ʱ�䣨�֣�
	short int iChannel; //ͨ����
	short int iFlagOfProjection; //ͶӰ��ʽ
	short int iWidthOfImage; //ͼ����
	short int iHeightOfImage; //ͼ��߶�
	short int iScanLineNumberOfImageTopLeft; //ͼ�����Ͻ�ɨ���ߺ�
	short int iPixelNumberOfImageTopLeft; //ͼ�����Ͻ���Ԫ��
	short int iSampleRatio; //������
	short int iLatitudeOfNorth; //����Χ����γ��
	short int iLatitudeOfSouth; //����Χ����γ��
	short int iLongitudeOfWest; //����Χ��������
	short int iLongitudeOfEast; //����Χ��������
	short int iCenterLatitudeOfProjection;//ͶӰ����γ�� �ȡ�100
	short int iCenterLongitudeOfProjection;//ͶӰ���ľ��� �ȡ�100
	short int iStandardLatitude1;//��׼ͶӰγ��1�����׼���ȣ�
	short int iStandardLatitude2; //��׼ͶӰγ��2
	short int iHorizontalResolution;//ͶӰˮƽ�ֱ��� �����100
	short int iVerticalResolution; //ͶӰ��ֱ�ֱ��� �����100
	short int iOverlapFlagGeoGrid; //����������ӱ�־
	short int iOverlapValueGeoGrid;//�����������ֵ
	short int iDataLengthOfColorTable; //��ɫ�����ݿ鳤��
	short int iDataLengthOfCalibration; //�������ݿ鳤��
	short int iDataLengthOfGeolocation; //��λ���ݿ鳤��
	short int iReserved; //����
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
