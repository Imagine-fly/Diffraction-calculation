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

#define PI 3.1416//����Բ���ʵĴ�С 

#define N 100000//��������ã�����������ȡһ���Ƚϴ��ֵ������������

typedef double TYPE_DATA;//�����Ժ��޸ľ���

typedef struct new_complex {

    TYPE_DATA real;//ʵ��

    TYPE_DATA imag;//�鲿

}new_complex;

new_complex add(new_complex x, new_complex y);//�������

new_complex sub(new_complex x, new_complex y);//�������

new_complex mul(new_complex x, new_complex y);//�������

new_complex div(new_complex x, new_complex y);//�������

TYPE_DATA Definite_integral_cos(TYPE_DATA a, TYPE_DATA b);//��cos(x^2)�Ķ�����

TYPE_DATA Definite_integral_sin(TYPE_DATA a, TYPE_DATA b);//��sin(x^2)�Ķ����� 

new_complex Definite_integral(TYPE_DATA lower, TYPE_DATA upper);//��ָ���ı�������Ϊ��ָ���Ķ�����

new_complex Fresnel(double X);//���������ɺ���

TYPE_DATA* calTriNormal(TYPE_DATA* ver1, TYPE_DATA* ver2, TYPE_DATA* ver3);//��������ķ�����

TYPE_DATA dot(TYPE_DATA* vector1, TYPE_DATA* vector2);//���ռ��������

TYPE_DATA* cross(TYPE_DATA* vector1, TYPE_DATA* vector2);//���ռ����������

TYPE_DATA norm(TYPE_DATA* vector);//��һ�ռ�������ģ 

TYPE_DATA Angle_mutation_g_less(TYPE_DATA v, TYPE_DATA x);//����߽�ĽǶ�ͻ����������g_less

TYPE_DATA Angle_mutation_g_add(TYPE_DATA v, TYPE_DATA x);//����߽�ĽǶ�ͻ����������g_add

TYPE_DATA Distance_parameter_L(TYPE_DATA s2, TYPE_DATA beita1);//ƽ�沨��������µľ������L

TYPE_DATA Space_attenuation_factor_A(TYPE_DATA s2);//ƽ�沨��������µĿռ�˥������A

new_complex Incident_diffraction_coefficient_Dr(TYPE_DATA L, TYPE_DATA jiaoduhe, TYPE_DATA n, TYPE_DATA beita, TYPE_DATA beita1);//��������ϵ��Dr

new_complex Incident_diffraction_coefficient_Di(TYPE_DATA L, TYPE_DATA jiaoducha, TYPE_DATA n, TYPE_DATA beita, TYPE_DATA beita1);//��������ϵ��Di

int sign(TYPE_DATA x);//���ź��� 

#endif

