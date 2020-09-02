#include "myhead.h"

TYPE_DATA Definite_integral_cos(TYPE_DATA a, TYPE_DATA b) {

	TYPE_DATA s = 0, x = a;

	int i;

	for (i = 1; i < N + 1; i++) //i��0��ʼ��1��ʼ��û���κ�Ӱ���
	{

		//�������������Ⱥ�˳��������⣬��ȡ���ε���߸߻����ұߵĸ߶�
		x = (x + (b - a) / N);

		s = s + cos(pow(x, 2)) * ((b - a) / N);//�����ֵĺ���cos(x^2)д������

	}

	return s;

}

TYPE_DATA Definite_integral_sin(TYPE_DATA a, TYPE_DATA b) {

	TYPE_DATA s = 0, x = a;

	int i;

	for (i = 1; i < N + 1; i++)//i��0��ʼ��1��ʼ��û���κ�Ӱ���
	{

		//�������������Ⱥ�˳��������⣬��ȡ���ε���߸߻����ұߵĸ߶�
		x = (x + (b - a) / N);

		s = s + sin(pow(x, 2)) * ((b - a) / N);//�����ֵĺ���sin(x^2)д������

	}

	return s;

}

new_complex Definite_integral(TYPE_DATA lower, TYPE_DATA upper)
{
	
	new_complex Result;

	Result.real = Definite_integral_cos(lower, upper);

	Result.imag = -(Definite_integral_sin(lower, upper));

	return Result;

}