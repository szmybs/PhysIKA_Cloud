# physIKA_Cloud

1. 请一定使用64位编译器；
2. 需要CUDA和PhysIKA；

3. Configure选项：
	1. CLOUD_PYTHON  -  python接口
	2. CLOUD_EVOLUTION_BASED_PHYSICS - 基于物理的形状演化
	3. CLOUD_IMG_CUMULUS  -  RGB图像生成积云
	4. CLOUD_SAT_TYPHOON  -  卫星云图生成台风
	5. CLOUD_WRF  -  WRF数据生成台风
	6. EXAMPLE_SATIMG_TYPHOON  -  卫星云图生成台风示例（仅能在勾选CLOUD_SAT_TYPHOON且未勾选CLOUD_PYTHON下勾选此项）
	7. EXAMPLE_WRF  -  WRF示例（仅能在勾选CLOUD_WRF且未勾选CLOUD_PYTHON下勾选此项）
	8. USE_PREBUILT_OSG  -  是否使用预建的OSG（仅在Windows、Debug、VS2017以后版本可用，如果不满足条件请勿勾选此项）

4. 目录结构：
	1. Cplusplus    C++源码部分
	2. Examples    示例代码部分, 示意各部分如何使用
	3. Python    python接口代码部分

5. BUILD完成后一定INSTALL以自动拷贝动态链接库，Python接口相关文件和所需动态链接库会拷贝到 PROJECT_BINARY_DIR/Python 中；

6. python接口使用方式详见各txt文件