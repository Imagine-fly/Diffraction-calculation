#include "myhead.h"

TYPE_DATA Definite_integral_cos(TYPE_DATA a, TYPE_DATA b) {

	TYPE_DATA s = 0, x = a;

	int i;

	for (i = 1; i < N + 1; i++) //i从0开始从1开始是没有任何影响的
	{

		//以下两条语句的先后顺序可以任意，即取矩形的左边高或者右边的高度
		x = (x + (b - a) / N);

		s = s + cos(pow(x, 2)) * ((b - a) / N);//被积分的函数cos(x^2)写在这里

	}

	return s;

}

TYPE_DATA Definite_integral_sin(TYPE_DATA a, TYPE_DATA b) {

	TYPE_DATA s = 0, x = a;

	int i;

	for (i = 1; i < N + 1; i++)//i从0开始从1开始是没有任何影响的
	{

		//以下两条语句的先后顺序可以任意，即取矩形的左边高或者右边的高度
		x = (x + (b - a) / N);

		s = s + sin(pow(x, 2)) * ((b - a) / N);//被积分的函数sin(x^2)写在这里

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