#include "myhead.h"

TYPE_DATA Distance_parameter_L(TYPE_DATA s2, TYPE_DATA beita1)//平面波入射情况下的距离参数L

//s1表示入射点到绕射点的距离
//s2表示绕射点到场点的距离
//beita1、beita2就是边缘固定坐标系涉及到的两个角度分量（这里是大小）

{
	
	TYPE_DATA L;

	L = s2 * pow((sin(beita1)), 2);

	return L;

}