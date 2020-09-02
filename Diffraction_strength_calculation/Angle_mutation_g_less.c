#include "myhead.h"

TYPE_DATA Angle_mutation_g_less(TYPE_DATA v, TYPE_DATA x)//绕射边界的角度突变描述函数g_less

//v表示楔形角度（指的是外角）(范围为(PI,2*PI),注意是开区间)
//x就是该函数的自变量
{
	int N_less;

	TYPE_DATA g_less;

	if (x < (PI - v))
	{
		N_less = -1;
	}
	else if ((x >= PI - v) && x <= (PI + v))
	{
		N_less = 0;
	}
	else
	{
		N_less = 1;
	}

	g_less = pow(cos(((2 * v * N_less) - x) / 2), 2);

	return g_less;
}