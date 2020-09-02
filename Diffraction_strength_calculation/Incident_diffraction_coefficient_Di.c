#include "myhead.h"

new_complex Incident_diffraction_coefficient_Di(TYPE_DATA L, TYPE_DATA jiaoducha, TYPE_DATA n, TYPE_DATA beita, TYPE_DATA beita1)//��������ϵ��Di

//LΪ��ͬ������ľ������
//jiaoduchaΪ��Ե�̶�����ϵ�漰���������Ƕȷ����Ĳ�ֵ����С��������
//nΪШ�νǶ��е�n
//beitaΪ��Ų��ھ��Ƚ����еĲ���
//beita1Ϊ��Ե�̶�����ϵ�漰���������Ƕȷ����е�һ���������Ǵ�С��

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