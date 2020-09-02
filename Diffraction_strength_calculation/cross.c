#include "myhead.h" 

TYPE_DATA* cross(TYPE_DATA* vector1, TYPE_DATA* vector2)//两空间向量做叉乘
{
	
	static TYPE_DATA temp[3];

	temp[0] = vector1[1] * vector2[2] - vector2[1] * vector1[2];
	
	temp[1] = vector2[0] * vector1[2] - vector1[0] * vector2[2];
	
	temp[2] = vector1[0] * vector2[1] - vector2[0] * vector1[1];

	return temp;
}

/*void main()
{
	TYPE_DATA a[3] = {0,0,1};
	TYPE_DATA b[3] = {0,1,0};

	TYPE_DATA *d;
	TYPE_DATA normal[3];
	int i;
	d = cross(a,b);
	normal[0] = *d;
	normal[1] = *(d + 1);
	normal[2] = *(d + 2);

	for(i = 0; i <= 2; i++)
	{
		printf("normal[%d] = %lf\n",i,normal[i]);
	}
}*/