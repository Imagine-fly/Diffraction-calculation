#include "myhead.h"

new_complex add(new_complex x, new_complex y)//复数相加
{
	new_complex z;
	z.real = x.real + y.real;
	z.imag = x.imag + y.imag;
	return z;
}
new_complex sub(new_complex x, new_complex y)//复数相减
{
	new_complex z;
	z.real = x.real - y.real;
	z.imag = x.imag - y.imag;
	return z;
}
new_complex mul(new_complex x, new_complex y)//复数相乘
{
	new_complex z;
	z.real = (x.real * y.real) - (x.imag * y.imag);
	z.imag = (x.real * y.imag) + (x.imag * y.real);
	return z;
}
new_complex div(new_complex x, new_complex y)//复数相除
{
	new_complex z;
	double z0 = y.real * y.real + y.imag * y.imag;
	z.real = ((x.real * y.real) + (x.imag * y.imag)) / z0;
	z.imag = ((x.real * y.imag) - (x.imag * y.real)) / z0;
	return z;
}
