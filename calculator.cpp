#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;//���������ռ�
//��������
long double Calculating(const vector<string>& ex); 
long double calcu(string ope,long double& num1,long double& num2);
inline void cal(stack<string>& symbol,stack<long double>& num);
//main����
int main()
{
	string expression;
	vector<string> ex;
	cout<<"��������ѧ���ʽ���Կո����ÿ���ַ�������=��Ϊ����������";//�����ʾ��Ϣ 
	cin>>expression;//�����һ��string
	//���û�����ı��ʽ����string�͵������� 
	while (expression!=string("="))
	{
		ex.push_back(expression);//�������� 
		cin>>expression;//������һ��string 
	} 
	ex.push_back(expression);//�����һ��string�������� 
	cout<<"��������"<<Calculating(ex)<<"\n";//������ex��Ϊ�����������Calculating�������м��㲢��������� 
	return 0;
} 
//Calculating����
long double Calculating(const vector<string>& ex)
{
	stack<string> symbol;//�������stack 
	stack<long double> num;//����stack 
	symbol.push("=");//ջ������=������ 
	//��˳���ȡex�����е����ݴ�Ϊt 
	for(auto t:ex)
	{
		//���ݲ�ͬ������в�ͬ���� 
		switch(t[0])
		{
			//��tΪ�����������������ʱ�������Ǹ��������ջ��Ԫ�ؽ�������ɾ�����ǵ���cal����
			//������̿���ͨ����stackʾ��ͼ�����õ���� 
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
			default://���������������˵��tΪ���� 
			{
				long double number=stold(t);//���ַ���ת��Ϊlong double�� 
				num.push(number);//�����ַ���numջ�� 
			}
		}
	}
	return num.top();//����numջ��Ԫ�أ���Ϊ���ռ����� 
} 
//��������cal
inline void cal(stack<string>& symbol,stack<long double>& num)
{
	auto number=num.top();//��ȡnumջ��Ԫ�ز�����number 
	num.pop();//�Ƴ�numջ��Ԫ�� 
	auto ope=symbol.top();//��ȡsymbolջ��Ԫ�ز�����ope 
	symbol.pop();//�Ƴ�symbolջ��Ԫ�� 
	calcu(ope,num.top(),number);//����calcu�������м��㣬������������Ϊnum��ջ��Ԫ�� 
} 
//calcu����
long double calcu(string ope,long double& num1,long double& num2)
{
	//������������в�ͬ�ļ��� 
	switch(ope[0])
	{
		case '+':num1+=num2;break;
		case '-':num1-=num2;break;
		case '*':num1*=num2;break;
		case '/':num1/=num2;break;
	}
	return num1;//���ؼ����� 
} 
