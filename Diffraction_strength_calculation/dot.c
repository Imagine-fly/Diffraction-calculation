#include "myhead.h"

TYPE_DATA dot(TYPE_DATA* vector1, TYPE_DATA* vector2)//两空间向量点乘 
{
	TYPE_DATA temp[3];

	TYPE_DATA dot_result;

	dot_result = vector1[0] * vector2[0] + vector1[1] * vector2[1] + vector1[2] * vector2[2];

	return dot_result;

}
/*void main()
{
	TYPE_DATA a[3] = {1,3,0};
	TYPE_DATA b[3] = {2,3,-3};
	
	printf("a**b = %lf\n",dot(a,b));
}*/