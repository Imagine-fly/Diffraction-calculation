#include "myhead.h"

int main()
{
	int i;//循环计数用

	//共边的两个三角面的四个顶点：O(0,0,0),A(0,3,0),B(3,4,0),C(2,3,-3)
	TYPE_DATA O[3] = { 0,0,0 };

	TYPE_DATA A[3] = { 0,3,0 };

	TYPE_DATA B[3] = { 3,4,0 };

	TYPE_DATA C[3] = { 2,3,-3 };

	//入射点D(0,0,3)和绕射点E(0,2,0)
	TYPE_DATA D[3] = { 0,0,3 };

	TYPE_DATA E[3] = { 0,2,0 };

	//待求绕射场场点P(3,4,0)
	TYPE_DATA P[3] = { 3,4,0 };

	//定义两平面的法向量 
	TYPE_DATA Normal_vector1[3];//三角面OAB的法向量 

	TYPE_DATA Normal_vector2[3];//三角面OAC的法向量

	//定义两平面的夹角(用弧度表示)
	TYPE_DATA Plane_angle;

	//两个三角面交线的方向向量
	TYPE_DATA e[3] = { 0,1,0 };

	//入射方向的方向向量DE
	TYPE_DATA s1[3] = { 0,2,-3 };

	//绕射方向的方向向量
	TYPE_DATA s2[3] = { 3,2,0 };

	//定义入射方向矢量和绕射方向矢量在绕射边的垂直面上的分量
	TYPE_DATA s1t[3];//入射方向上的 

	TYPE_DATA s2t[3];//绕射方向上的 

	//定义平面1的切向量
	TYPE_DATA t1[3];

	//边缘固定坐标系涉及到的两个角度分量(两种表现形式：标量和矢量)
	TYPE_DATA shiliang_jiaodu1[3];//矢量 

	TYPE_DATA shiliang_jiaodu2[3];

	TYPE_DATA biaoliang_jiaodu1;//标量 

	TYPE_DATA biaoliang_jiaodu2;


	//定义边缘固定坐标系涉及到的另外两个分量，是贝塔
	TYPE_DATA beita1[3];

	TYPE_DATA beita2[3];

	//定义标量衍射系数，取边缘反射系数的垂直分量为1，平行分量为-1
	new_complex Ds;

	new_complex Di;

	new_complex Dr;

	new_complex Dh;
	
	//定义电场强度
	TYPE_DATA dianchangqiangdu[3] = { 1,0,0 };

	//得到绕射场强所需的变量
	TYPE_DATA Ei1;

	TYPE_DATA Ei2;

	new_complex Eo1;

	new_complex Eo2;

	TYPE_DATA c, d;//临时变量 

	TYPE_DATA* temp1;//中间变量

	TYPE_DATA temp2;

	TYPE_DATA temp3;

	TYPE_DATA temp4[3];

	TYPE_DATA temp5[3];

	//求三角面OAB和三角面OAC的法向量
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

	//求两平面的夹角(用弧度表示)
	Plane_angle = acos(dot(Normal_vector1, Normal_vector2) / (norm(Normal_vector1) * norm(Normal_vector2)));

	//求入射方向矢量和绕射方向矢量在绕射边的垂直面上的分量
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
	//求平面1的切向量 
	
	temp1 = cross(Normal_vector1, e);//注意这里的叉乘方向和matlab中的不太一致，要核对一下 

	for (i = 0; i < 3; i++)
	{
		t1[i] = *(temp1 + i);
	}

	//求边缘固定坐标系涉及到的两个角度分量(两种表现形式：标量和矢量)
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

	//边缘固定坐标系涉及到的另外两个分量，是贝塔
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

	//求标量衍射系数，取边缘反射系数的垂直分量为1，平行分量为-1

	Di = Incident_diffraction_coefficient_Di(Distance_parameter_L(norm(s2), norm(beita1)), biaoliang_jiaodu2 - biaoliang_jiaodu1, 2 - (Plane_angle / PI), 2 * PI, norm(beita1));

	Dr = Incident_diffraction_coefficient_Dr(Distance_parameter_L(norm(s2), norm(beita1)), biaoliang_jiaodu2 + biaoliang_jiaodu1, 2 - (Plane_angle / PI), 2 * PI, norm(beita1));

	Ds.real = Di.real + Dr.real;

	Ds.imag = Di.imag + Dr.imag;

	Di = Incident_diffraction_coefficient_Di(Distance_parameter_L(norm(s2), norm(beita1)), biaoliang_jiaodu2 - biaoliang_jiaodu1, 2 - (Plane_angle / PI), 2 * PI, norm(beita1));

	Dr = Incident_diffraction_coefficient_Dr(Distance_parameter_L(norm(s2), norm(beita1)), biaoliang_jiaodu2 + biaoliang_jiaodu1, 2 - (Plane_angle / PI), 2 * PI, norm(beita1));

	Dh.real = Di.real - Dr.real;

	Dh.imag = Di.imag - Dr.imag;

	//求绕射场场点的绕射场强 
	Ei1 = dot(dianchangqiangdu, beita1);

	Ei2 = dot(dianchangqiangdu, shiliang_jiaodu1);

	c = -(Ei1 * Space_attenuation_factor_A(norm(s2)));

	Eo1.real = c * (Ds.real * cos(2 * PI * norm(s2)) + Ds.imag * sin(2 * PI * norm(s2)));

	Eo1.imag = c * (Ds.imag * cos(2 * PI * norm(s2)) - Ds.real * sin(2 * PI * norm(s2)));

	d = -(Ei2 * Space_attenuation_factor_A(norm(s2)));

	Eo2.real = d * (Dh.real * cos(2 * PI * norm(s2)) + Dh.imag * sin(2 * PI * norm(s2)));

	Eo2.imag = d * (Dh.imag * cos(2 * PI * norm(s2)) - Dh.real * sin(2 * PI * norm(s2)));

	//检测代码
	printf("平面1（OAB）的法向量:(%lf,%lf,%lf)\n", Normal_vector1[0], Normal_vector1[1], Normal_vector1[2]);

	printf("平面2（OAC）的法向量:(%lf,%lf,%lf)\n", Normal_vector2[0], Normal_vector2[1], Normal_vector2[2]);

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