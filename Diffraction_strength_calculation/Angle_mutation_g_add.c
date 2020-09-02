#include "myhead.h"

TYPE_DATA Angle_mutation_g_add(TYPE_DATA v, TYPE_DATA x)//反射边界的角度突变描述函数g_add
{
	//v表示楔形角度（指的是外角）(范围为(PI,2*PI),注意是开区间)
	//x就是该函数的自变量
	int N_add;

	TYPE_DATA g_add;

	if ((v - PI) >= x)
	{
		N_add = 0;
	}
	else
	{
		N_add = 1;
	}

	g_add = pow(cos(((2 * v * N_add) - x) / 2), 2);

	return g_add;

}

/*void main()
{
	TYPE_DATA v = 5.3004;
	TYPE_DATA x = 1.5708;
	printf("g_add = %lf\n",Angle_mutation_g_less(v,x));
	printf("g_less = %lf\n",Angle_mutation_g_add(v,x));
}*/