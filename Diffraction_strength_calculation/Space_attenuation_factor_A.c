#include "myhead.h"

TYPE_DATA Space_attenuation_factor_A(TYPE_DATA s2)//平面波入射情况下的空间衰减因子A

//s1表示入射点到绕射点的距离
//%s2表示绕射点到场点的距离
//%beita2就是边缘固定坐标系涉及到的两个角度分量中的一个（这里是大小）
{
	TYPE_DATA A;

	A = 1 / sqrt(s2);

	return A;
}