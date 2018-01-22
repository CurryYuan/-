#include <iostream>
#include <string>
#include <random>
#include <ctime> 
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;

class Random {
private:
	double U_Random()   /* ����һ��0~1֮�������� */
	{
		double f;
		f = (float)(rand() % 100);
		/* printf("%fn",f); */
		return f / 100;
	}
public:
	int random(double mean,int num) {
		cout << "Do you want to control the number of planes this time? [1 for yes / 0 for no]" << endl;
		string s;
		cin >> s;
		int number;
		if (s == "1") {
			if (num == 1) {
				cout << "Please enter the number of arrival planes: ";
				cin >> number;
				return number;
			}
			else {
				cout << "Please enter the number of departure planes: ";
				cin >> number;
				return number;
			}
		}
		else {
			if (num == 1)
				cout << "the number of arrival planes will be set randomly" << endl;
			else
				cout << "the number of departure planes will be set randomly" << endl;
			int temp=poisson(mean);
			cout << "The random number is: " << temp << endl;
			return temp;
		}
	}
	int poisson(double mean)  /* ����һ�����ɷֲ����������LamdaΪ����ƽ����*/
	{

		double Lambda = mean, k = 0;
		long double p = 1.0;
		long double l = exp(-Lambda);  /* Ϊ�˾��ȣ��Ŷ���Ϊlong double�ģ�exp(-Lambda)�ǽӽ�0��С��*/
		while (p >= l)
		{
			double u = U_Random();
			p *= u;
			k++;
		}
		return k - 1;
	}
};


