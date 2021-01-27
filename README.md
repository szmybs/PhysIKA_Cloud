# physIKA_Cloud

1. 请一定使用64位编译器；
2. 请一定在Windows平台下使用；
3. 请在clone时使用 git clone https://github.com/szmybs/PhysIKA_Cloud.git --recursive
   或者clone后使用 git submodule init    +    git submodule update
   以下载pybind11子模块；

4. Configure选项：
	1. CLOUD_EULER    欧拉法
	2. CLOUD_EXAMPLES    C++样例
	3. CLOUD_PYTHON    python接口
	4. CLOUD_IMG_CUMULUS    RGB图像生成积云
	5. CLOUD_SAT_CUMULUS    卫星云图生成积云（不在项目计划内）
	6. CLOUD_SAT_TYPHOON    卫星云图生成台风（暂无Python接口）
	7. CLOUD_WRF    WRF数据生成台风（暂未完成） 

5. 目录结构：
	1. Cplusplus    C++源码部分
	2. Examples    示例代码部分
	3. Python    python接口代码部分

6. BUILD完成后一定INSTALL以自动拷贝动态链接库；

7. python接口使用方式详见各txt文件