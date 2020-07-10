#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;//声明命名空间
//方法声明
long double Calculating(const vector<string>& ex); 
long double calcu(string ope,long double& num1,long double& num2);
inline void cal(stack<string>& symbol,stack<long double>& num);
//main函数
int main()
{
	string expression;
	vector<string> ex;
	cout<<"请输入数学表达式（以空格隔开每个字符，并以=作为结束符）：";//输出提示信息 
	cin>>expression;//读入第一个string
	//将用户输入的表达式存入string型的数组中 
	while (expression!=string("="))
	{
		ex.push_back(expression);//放入数组 
		cin>>expression;//读入下一个string 
	} 
	ex.push_back(expression);//将最后一个string放入数组 
	cout<<"计算结果："<<Calculating(ex)<<"\n";//以数组ex作为输入参数调用Calculating方法进行计算并输出计算结果 
	return 0;
} 
//Calculating函数
long double Calculating(const vector<string>& ex)
{
	stack<string> symbol;//运算符号stack 
	stack<long double> num;//数字stack 
	symbol.push("=");//栈顶增加=结束符 
	//按顺序读取ex数组中的数据存为t 
	for(auto t:ex)
	{
		//根据不同情况进行不同处理 
		switch(t[0])
		{
			//当t为各种运算符或是括号时，处理是根据情况对栈顶元素进行增加删除或是调用cal函数
			//具体过程可以通过画stack示意图来更好地理解 
			case '=':
			{
				while(symbol.top()!="=")
				{
					cal(symbol,num);
				}
				break;
			}
			case '(': symbol.push(t);break;
			case ')':
			{
				do
				{
					cal(symbol,num);
				}while(symbol.top()!="(");
				symbol.pop();
				break;
			}
			case '+':
			case '-':
			{
				if(symbol.top()=="("||symbol.top()=="=")
					symbol.push(t);
				else
				{
					cal(symbol,num);
					symbol.push(t);
				}
				break;
			}
			case '*':
			case '/':
			{
				if(symbol.top()=="*"||symbol.top()=="/")
				{
					cal(symbol,num);
					symbol.push(t);
				}
				else
					symbol.push(t);
				break;
			}
			default://若不是以上情况，说明t为数字 
			{
				long double number=stold(t);//将字符串转换为long double型 
				num.push(number);//将数字放入num栈顶 
			}
		}
	}
	return num.top();//返回num栈顶元素，即为最终计算结果 
} 
//内联函数cal
inline void cal(stack<string>& symbol,stack<long double>& num)
{
	auto number=num.top();//读取num栈顶元素并存入number 
	num.pop();//移除num栈顶元素 
	auto ope=symbol.top();//读取symbol栈顶元素并存入ope 
	symbol.pop();//移除symbol栈顶元素 
	calcu(ope,num.top(),number);//调用calcu函数进行计算，计算结果将保存为num的栈顶元素 
} 
//calcu函数
long double calcu(string ope,long double& num1,long double& num2)
{
	//根据运算符进行不同的计算 
	switch(ope[0])
	{
		case '+':num1+=num2;break;
		case '-':num1-=num2;break;
		case '*':num1*=num2;break;
		case '/':num1/=num2;break;
	}
	return num1;//返回计算结果 
} 
