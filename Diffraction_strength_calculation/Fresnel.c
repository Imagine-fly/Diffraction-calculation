#include "myhead.h"

new_complex Fresnel(double X)
{
	new_complex F;//菲涅尔函数结果的返回值

	new_complex Result;//定积分结果的接收值 

	if ((X > 0) && (X < 0.3)) 
	{

		F.real = (sqrt(PI * X) - X * sqrt(2) - (sqrt(2) / 3) * pow(X, 2)) * cos((PI / 4) + X) - ((sqrt(2) / 3) * pow(X, 2) - X * sqrt(2)) * sin((PI / 4) + X);

		F.imag = (sqrt(PI * X) - X * sqrt(2) - (sqrt(2) / 3) * pow(X, 2)) * sin((PI / 4) + X) + ((sqrt(2) / 3) * pow(X, 2) - X * sqrt(2)) * cos((PI / 4) + X);

	}
	else if (X > 5.5) 
	{

		F.real = (1 - (3 / 4) * (1 / pow(X, 2)) + (75 / 16) * (1 / pow(X, 4)));

		F.imag = (1 / (2 * X)) - (15 / 8) * (1 / pow(X, 3));

	}
	else if ((X >= 0.3) && (X <= 5.5)) 
	{


		Result = Definite_integral(0, sqrt(X));

		F.real = -(2 * sqrt(X) * sin(X)) * ((sqrt(2 * PI)) / 4 - Result.real) + (2 * sqrt(X) * cos(X)) * (Result.imag + (sqrt(2 * PI)) / 4);

		F.imag = (2 * sqrt(X) * sin(X)) * (Result.imag + (sqrt(2 * PI)) / 4) + (2 * sqrt(X) * cos(X)) * ((sqrt(2 * PI)) / 4 - Result.real);

	}
	else {

		printf("抱歉，X非正数！\n");

	}

	return F;

}

/*void main()
{
	new_complex F;
	F = Fresnel(5);
	printf ("F=%lf+(%lf)i\n",F.real,F.imag);
}*/