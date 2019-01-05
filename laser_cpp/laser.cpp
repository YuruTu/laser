// laser.cpp : 定义 DLL 应用程序的导出函数。


#include "stdafx.h"
using namespace std;
const double pi = 4.0*atan(1.0);//或者pi=3.141592689793238465....
double I[100][100];//声明一个足够大的数组
double In[100][100];//我们希望加速程序的运行，速度比内存更重要

LASER_API StructPointer __stdcall laser_mode(long x, long y)
{
	int n = int(x);
	int t = int(y);
	double rd = 0.005;
	double ld = 1.0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			I[i][j] = 1.0;
		}
	}

	double n_b = (double)n;
	double temp, temp1, temp2;
	while (t--) {//循环t次后结束
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				In[i][j] = 0.0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int i1 = 0; i1 < n; i1++) {
					for (int j1 = 0; j1 < n; j1++) {
						temp1 = (double(i1 - i))*rd / n_b;
						temp1 *= temp1;
						temp2 = (double(j1 - j))*rd / n_b;
						temp2 *= temp2;
						temp = 1.0 / (4.0*pi)*I[i1][j1] * (1.0 + ld / sqrt(temp1 + temp2 + ld * ld)) / n_b / n_b;
						In[i][j] += temp;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				I[i][j] = In[i][j];
			}
		}
	}
	double S_I = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			S_I += I[i][j];
		}
	}
	double mul = n_b * n_b / S_I;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			I[i][j] *= mul;
			I[i][j] *= I[i][j];
		}
	}
	StructPointer p = (StructPointer)malloc(sizeof(StructPointerTest));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p->arr[i*n+j] = I[i][j];
		}
	}
	return p;
}
LASER_API void __stdcall hello() {

	cout << "你好" << endl;
}

