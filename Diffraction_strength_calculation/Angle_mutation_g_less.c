#include "myhead.h"

TYPE_DATA Angle_mutation_g_less(TYPE_DATA v, TYPE_DATA x)//����߽�ĽǶ�ͻ����������g_less

//v��ʾШ�νǶȣ�ָ������ǣ�(��ΧΪ(PI,2*PI),ע���ǿ�����)
//x���Ǹú������Ա���
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