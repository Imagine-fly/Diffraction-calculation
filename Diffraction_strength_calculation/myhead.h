/*
 *  myhead.h
 *
 *  Created on: 2020-8-8
 *  Version: 1
 *  Author: zhangpeng
 */
#ifndef MYHEAD_H_
#define MYHEAD_H_

#include <stdio.h>
#include <math.h>

#define PI 3.1416//定义圆周率的大小 

#define N 100000//求积分所用：迭代次数，取一个比较大的值，近似于无穷

typedef double TYPE_DATA;//方便以后修改精度

typedef struct new_complex {

    TYPE_DATA real;//实部

    TYPE_DATA imag;//虚部

}new_complex;

new_complex add(new_complex x, new_complex y);//复数相加

new_complex sub(new_complex x, new_complex y);//复数相减

new_complex mul(new_complex x, new_complex y);//复数相乘

new_complex div(new_complex x, new_complex y);//复数相除

TYPE_DATA Definite_integral_cos(TYPE_DATA a, TYPE_DATA b);//求cos(x^2)的定积分

TYPE_DATA Definite_integral_sin(TYPE_DATA a, TYPE_DATA b);//求sin(x^2)的定积分 

new_complex Definite_integral(TYPE_DATA lower, TYPE_DATA upper);//求指定的被积函数为复指数的定积分

new_complex Fresnel(double X);//菲涅尔过渡函数

TYPE_DATA* calTriNormal(TYPE_DATA* ver1, TYPE_DATA* ver2, TYPE_DATA* ver3);//求三角面的法向量

TYPE_DATA dot(TYPE_DATA* vector1, TYPE_DATA* vector2);//两空间向量点乘

TYPE_DATA* cross(TYPE_DATA* vector1, TYPE_DATA* vector2);//两空间向量做叉乘

TYPE_DATA norm(TYPE_DATA* vector);//求一空间向量的模 

TYPE_DATA Angle_mutation_g_less(TYPE_DATA v, TYPE_DATA x);//绕射边界的角度突变描述函数g_less

TYPE_DATA Angle_mutation_g_add(TYPE_DATA v, TYPE_DATA x);//反射边界的角度突变描述函数g_add

TYPE_DATA Distance_parameter_L(TYPE_DATA s2, TYPE_DATA beita1);//平面波入射情况下的距离参数L

TYPE_DATA Space_attenuation_factor_A(TYPE_DATA s2);//平面波入射情况下的空间衰减因子A

new_complex Incident_diffraction_coefficient_Dr(TYPE_DATA L, TYPE_DATA jiaoduhe, TYPE_DATA n, TYPE_DATA beita, TYPE_DATA beita1);//反射衍射系数Dr

new_complex Incident_diffraction_coefficient_Di(TYPE_DATA L, TYPE_DATA jiaoducha, TYPE_DATA n, TYPE_DATA beita, TYPE_DATA beita1);//入射衍射系数Di

int sign(TYPE_DATA x);//符号函数 

#endif

