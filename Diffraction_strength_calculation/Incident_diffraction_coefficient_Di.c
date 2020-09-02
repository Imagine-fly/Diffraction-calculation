#include "myhead.h"

new_complex Incident_diffraction_coefficient_Di(TYPE_DATA L, TYPE_DATA jiaoducha, TYPE_DATA n, TYPE_DATA beita, TYPE_DATA beita1)//入射衍射系数Di

//L为不同波入射的距离参数
//jiaoducha为边缘固定坐标系涉及到的两个角度分量的差值（大小做减法）
//n为楔形角度中的n
//beita为电磁波在均匀介质中的波数
//beita1为边缘固定坐标系涉及到的两个角度分量中的一个（这里是大小）

{
	
	TYPE_DATA num, num1, num2;

	new_complex Di;

	new_complex F;

	TYPE_DATA temp, temp1;

	new_complex temp2;

	num = sqrt(2) / 2;

	temp = 1 / (2 * n * (sqrt(2 * PI * beita)) * sin(beita1));

	temp1 = num * temp;

	F = Fresnel(beita * L * Angle_mutation_g_add(n * PI, jiaoducha));

	num1 = 1 / tan((PI + jiaoducha) / (2 * n));

	num2 = 1 / tan((PI - jiaoducha) / (2 * n));

	temp2.real = num1 * F.real + num2 * F.real;

	temp2.imag = num1 * F.imag + num2 * F.imag;

	Di.real = -(temp2.real * temp1 + temp2.imag * temp1);

	Di.imag = -(temp2.imag * temp1 - temp2.real * temp1);

	return Di;

}

/*void main()
{
	TYPE_DATA L = 0.7220;
	TYPE_DATA jiaoducha = 1.5708;
	TYPE_DATA n = 1.6872;
	TYPE_DATA beita = 6.2832;
	TYPE_DATA beita1 = 3.6056;

	new_complex Di = Incident_diffraction_coefficient_Di(L,jiaoducha,n,beita,beita1);

	printf ("Di=%lf+(%lf)i\n",Di.real,Di.imag);

}*/