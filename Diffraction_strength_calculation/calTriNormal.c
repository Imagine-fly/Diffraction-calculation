#include "myhead.h"

TYPE_DATA* calTriNormal(TYPE_DATA* ver1, TYPE_DATA* ver2, TYPE_DATA* ver3)//求三角面的法向量 
{
	TYPE_DATA temp1[3], temp2[3];

	static TYPE_DATA normal[3];

	TYPE_DATA length = 0.0;

	temp1[0] = ver2[0] - ver1[0];

	temp1[1] = ver2[1] - ver1[1];

	temp1[2] = ver2[2] - ver1[2];

	temp2[0] = ver3[0] - ver2[0];

	temp2[1] = ver3[1] - ver2[1];

	temp2[2] = ver3[2] - ver2[2];

	//计算法线
	normal[0] = -(temp1[1] * temp2[2] - temp1[2] * temp2[1]);

	normal[1] = -(temp1[2] * temp2[0] - temp1[0] * temp2[2]);

	normal[2] = -(temp1[0] * temp2[1] - temp1[1] * temp2[0]);


	//法线单位化
	length = sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);

	if (length == 0.0f) 
	{ 
		
		length = 1.0f; 

	}

	normal[0] /= length;

	normal[1] /= length;

	normal[2] /= length;

	return normal;

}
/*void main()
{
	TYPE_DATA a[3] = {0,0,0};
	TYPE_DATA b[3] = {0,3,0};
	TYPE_DATA c[3] = {2,3,-3};

	TYPE_DATA*d;
	TYPE_DATA normal[3];
	int i;
	d = calTriNormal(a,b,c);
	normal[0] = *d;
	normal[1] = *(d + 1);
	normal[2] = *(d + 2);

	for(i = 0; i <= 2; i++)
	{
		printf("normal[%d] = %lf\n",i,normal[i]);
	}

}*/