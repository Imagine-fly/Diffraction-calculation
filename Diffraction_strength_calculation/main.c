#include "myhead.h"

int main()
{
	int i;//ѭ��������

	//���ߵ�������������ĸ����㣺O(0,0,0),A(0,3,0),B(3,4,0),C(2,3,-3)
	TYPE_DATA O[3] = { 0,0,0 };

	TYPE_DATA A[3] = { 0,3,0 };

	TYPE_DATA B[3] = { 3,4,0 };

	TYPE_DATA C[3] = { 2,3,-3 };

	//�����D(0,0,3)�������E(0,2,0)
	TYPE_DATA D[3] = { 0,0,3 };

	TYPE_DATA E[3] = { 0,2,0 };

	//�������䳡����P(3,4,0)
	TYPE_DATA P[3] = { 3,4,0 };

	//������ƽ��ķ����� 
	TYPE_DATA Normal_vector1[3];//������OAB�ķ����� 

	TYPE_DATA Normal_vector2[3];//������OAC�ķ�����

	//������ƽ��ļн�(�û��ȱ�ʾ)
	TYPE_DATA Plane_angle;

	//���������潻�ߵķ�������
	TYPE_DATA e[3] = { 0,1,0 };

	//���䷽��ķ�������DE
	TYPE_DATA s1[3] = { 0,2,-3 };

	//���䷽��ķ�������
	TYPE_DATA s2[3] = { 3,2,0 };

	//�������䷽��ʸ�������䷽��ʸ��������ߵĴ�ֱ���ϵķ���
	TYPE_DATA s1t[3];//���䷽���ϵ� 

	TYPE_DATA s2t[3];//���䷽���ϵ� 

	//����ƽ��1��������
	TYPE_DATA t1[3];

	//��Ե�̶�����ϵ�漰���������Ƕȷ���(���ֱ�����ʽ��������ʸ��)
	TYPE_DATA shiliang_jiaodu1[3];//ʸ�� 

	TYPE_DATA shiliang_jiaodu2[3];

	TYPE_DATA biaoliang_jiaodu1;//���� 

	TYPE_DATA biaoliang_jiaodu2;


	//�����Ե�̶�����ϵ�漰�������������������Ǳ���
	TYPE_DATA beita1[3];

	TYPE_DATA beita2[3];

	//�����������ϵ����ȡ��Ե����ϵ���Ĵ�ֱ����Ϊ1��ƽ�з���Ϊ-1
	new_complex Ds;

	new_complex Di;

	new_complex Dr;

	new_complex Dh;
	
	//����糡ǿ��
	TYPE_DATA dianchangqiangdu[3] = { 1,0,0 };

	//�õ����䳡ǿ����ı���
	TYPE_DATA Ei1;

	TYPE_DATA Ei2;

	new_complex Eo1;

	new_complex Eo2;

	TYPE_DATA c, d;//��ʱ���� 

	TYPE_DATA* temp1;//�м����

	TYPE_DATA temp2;

	TYPE_DATA temp3;

	TYPE_DATA temp4[3];

	TYPE_DATA temp5[3];

	//��������OAB��������OAC�ķ�����
	temp1 = calTriNormal(O, A, B);

	for (i = 0; i < 3; i++)
	{
		
		Normal_vector1[i] = *(temp1 + i);

	}

	temp1 = calTriNormal(O, A, C);

	for (i = 0; i < 3; i++)
	{
		
		Normal_vector2[i] = *(temp1 + i);

	}

	//����ƽ��ļн�(�û��ȱ�ʾ)
	Plane_angle = acos(dot(Normal_vector1, Normal_vector2) / (norm(Normal_vector1) * norm(Normal_vector2)));

	//�����䷽��ʸ�������䷽��ʸ��������ߵĴ�ֱ���ϵķ���
	temp2 = dot(s1, e);

	temp3 = dot(s2, e);

	for (i = 0; i <= 2; i++)
	{

		temp4[i] = s1[i] - temp2 * e[i];

		temp5[i] = s2[i] - temp3 * e[i];

	}
	for (i = 0; i <= 2; i++)
	{

		s1t[i] = temp4[i] / norm(temp4);

		s2t[i] = temp5[i] / norm(temp5);

	}
	//��ƽ��1�������� 
	
	temp1 = cross(Normal_vector1, e);//ע������Ĳ�˷����matlab�еĲ�̫һ�£�Ҫ�˶�һ�� 

	for (i = 0; i < 3; i++)
	{
		t1[i] = *(temp1 + i);
	}

	//���Ե�̶�����ϵ�漰���������Ƕȷ���(���ֱ�����ʽ��������ʸ��)
	temp1 = cross(e, s1);

	for (i = 0; i < 3; i++)
	{
		
		temp4[i] = *(temp1 + i);

	}

	temp1 = cross(e, s2);

	for (i = 0; i < 3; i++)
	{
		
		temp5[i] = *(temp1 + i);

	}

	for (i = 0; i <= 2; i++)
	{

		shiliang_jiaodu1[i] = -(temp4[i]) / norm(temp4);

		shiliang_jiaodu2[i] = (temp5[i]) / norm(temp5);

	}

	biaoliang_jiaodu1 = PI - (PI - acos(-dot(s1t, t1))) * sign(-dot(s1t, Normal_vector1));

	biaoliang_jiaodu2 = PI - (PI - acos(dot(s2t, t1))) * sign(dot(s2t, Normal_vector1));

	//��Ե�̶�����ϵ�漰�������������������Ǳ���
	temp1 = cross(shiliang_jiaodu1, s1);

	for (i = 0; i < 3; i++)
	{
		
		beita1[i] = *(temp1 + i);

	}

	temp1 = cross(shiliang_jiaodu2, s2);

	for (i = 0; i < 3; i++)
	{
		
		beita2[i] = *(temp1 + i);

	}

	//���������ϵ����ȡ��Ե����ϵ���Ĵ�ֱ����Ϊ1��ƽ�з���Ϊ-1

	Di = Incident_diffraction_coefficient_Di(Distance_parameter_L(norm(s2), norm(beita1)), biaoliang_jiaodu2 - biaoliang_jiaodu1, 2 - (Plane_angle / PI), 2 * PI, norm(beita1));

	Dr = Incident_diffraction_coefficient_Dr(Distance_parameter_L(norm(s2), norm(beita1)), biaoliang_jiaodu2 + biaoliang_jiaodu1, 2 - (Plane_angle / PI), 2 * PI, norm(beita1));

	Ds.real = Di.real + Dr.real;

	Ds.imag = Di.imag + Dr.imag;

	Di = Incident_diffraction_coefficient_Di(Distance_parameter_L(norm(s2), norm(beita1)), biaoliang_jiaodu2 - biaoliang_jiaodu1, 2 - (Plane_angle / PI), 2 * PI, norm(beita1));

	Dr = Incident_diffraction_coefficient_Dr(Distance_parameter_L(norm(s2), norm(beita1)), biaoliang_jiaodu2 + biaoliang_jiaodu1, 2 - (Plane_angle / PI), 2 * PI, norm(beita1));

	Dh.real = Di.real - Dr.real;

	Dh.imag = Di.imag - Dr.imag;

	//�����䳡��������䳡ǿ 
	Ei1 = dot(dianchangqiangdu, beita1);

	Ei2 = dot(dianchangqiangdu, shiliang_jiaodu1);

	c = -(Ei1 * Space_attenuation_factor_A(norm(s2)));

	Eo1.real = c * (Ds.real * cos(2 * PI * norm(s2)) + Ds.imag * sin(2 * PI * norm(s2)));

	Eo1.imag = c * (Ds.imag * cos(2 * PI * norm(s2)) - Ds.real * sin(2 * PI * norm(s2)));

	d = -(Ei2 * Space_attenuation_factor_A(norm(s2)));

	Eo2.real = d * (Dh.real * cos(2 * PI * norm(s2)) + Dh.imag * sin(2 * PI * norm(s2)));

	Eo2.imag = d * (Dh.imag * cos(2 * PI * norm(s2)) - Dh.real * sin(2 * PI * norm(s2)));

	//������
	printf("ƽ��1��OAB���ķ�����:(%lf,%lf,%lf)\n", Normal_vector1[0], Normal_vector1[1], Normal_vector1[2]);

	printf("ƽ��2��OAC���ķ�����:(%lf,%lf,%lf)\n", Normal_vector2[0], Normal_vector2[1], Normal_vector2[2]);

	printf("Plane_angle = %lf\n", Plane_angle);

	for (i = 0; i <= 2; i++)
	{

		printf("s1t[%d] = %lf\n", i, s1t[i]);

	}
	for (i = 0; i <= 2; i++)
	{

		printf("s2t[%d] = %lf\n", i, s2t[i]);

	}

	for (i = 0; i <= 2; i++)
	{

		printf("t1[%d] = %lf\n", i, t1[i]);

	}

	for (i = 0; i <= 2; i++)
	{

		printf("shiliang_jiaodu1[%d] = %lf\n", i, shiliang_jiaodu1[i]);

	}
	for (i = 0; i <= 2; i++)
	{

		printf("shiliang_jiaodu2[%d] = %lf\n", i, shiliang_jiaodu2[i]);

	}

	printf("biaoliang_jiaodu1 = %lf\n", biaoliang_jiaodu1);

	printf("biaoliang_jiaodu2 = %lf\n", biaoliang_jiaodu2);

	for (i = 0; i <= 2; i++)
	{

		printf("beita1[%d] = %lf\n", i, beita1[i]);

	}
	for (i = 0; i <= 2; i++)
	{

		printf("beita2[%d] = %lf\n", i, beita2[i]);

	}

	printf("Ds = %lf + (%lf)i\n", Ds.real, Ds.imag);

	printf("Dh = %lf + (%lf)i\n", Dh.real, Dh.imag);

	printf("Eo1 = %lf + (%lf)i\n", Eo1.real, Eo1.imag);

	printf("Eo2 = %lf + (%lf)i\n", Eo2.real, Eo2.imag);

	return 0;

}