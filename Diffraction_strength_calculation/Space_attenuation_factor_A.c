#include "myhead.h"

TYPE_DATA Space_attenuation_factor_A(TYPE_DATA s2)//ƽ�沨��������µĿռ�˥������A

//s1��ʾ����㵽�����ľ���
//%s2��ʾ����㵽����ľ���
//%beita2���Ǳ�Ե�̶�����ϵ�漰���������Ƕȷ����е�һ���������Ǵ�С��
{
	TYPE_DATA A;

	A = 1 / sqrt(s2);

	return A;
}