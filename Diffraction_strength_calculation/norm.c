#include "myhead.h"

TYPE_DATA norm(TYPE_DATA* vector)//��һ�ռ�������ģ 
{
	
	TYPE_DATA temp;

	TYPE_DATA norm_result;

	temp = pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2);

	norm_result = sqrt(temp);

	return norm_result;

}
/*void main()
{
	TYPE_DATA a[3] = {2,3,-3};

	printf("norm(a) = %lf\n",norm(a));
}*/