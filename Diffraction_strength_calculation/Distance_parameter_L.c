#include "myhead.h"

TYPE_DATA Distance_parameter_L(TYPE_DATA s2, TYPE_DATA beita1)//ƽ�沨��������µľ������L

//s1��ʾ����㵽�����ľ���
//s2��ʾ����㵽����ľ���
//beita1��beita2���Ǳ�Ե�̶�����ϵ�漰���������Ƕȷ����������Ǵ�С��

{
	
	TYPE_DATA L;

	L = s2 * pow((sin(beita1)), 2);

	return L;

}