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

