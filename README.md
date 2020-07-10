# 操作说明
示例编译运行环境：Windows 10 64位，安装Microsoft Visual Studio Community 2019  
代码文件：calculator.cpp  
编译运行方法一：将代码文件添加为Visual Studio项目源文件进行编译运行  
编译运行方法二：利用Windows原生cmd进行编译运行——在正确文件夹路径下输入命令 cl calculator.cpp 进行编译，编译成功后输入命令 calculator.exe 运行程序  
（若无法通过cl命令编译代码文件，解决办法建议参考https://blog.csdn.net/adam_fei/article/details/77842742 ）  
（为了避免系统环境因素导致的始终无法编译代码文件，编译成功后的文件 calculator.exe 也放入了库中，可以通过先运行 calculator.exe 检测代码功能）  
当程序正确运行后，便可以输入需要计算的数学表达式，回车后便可得到计算结果。  
在输入需要计算的数学表达式时，请注意以下几点，否则程序无法正常运行：  
1. 需在英文输入状态下输入算式  
2. 输入算式时需用空格隔开每个字符（每个数字看作一个字符），正确示例如下：  
    1 + ( 4.5 / 2 ) - 0.3 =  
    ( 3 * 2 ) + 1.7 =  
