#---------------^_^-------------^_^-------
#利用python仿真双缝实验
#程序再版与2019/1/5，初版写于2017年12月
#作者：cclplus
#仅供学习交流使用
#如有疑问或者需求，可以联系作者707101557@qq.com

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import math
from ctypes import *
#dll = cdll.LoadLibrary('laser.dll');
dll=WinDLL('laser.dll')
class StructPointer(Structure):  
    _fields_ = [("arr", c_double * 2500)] 
    def __init__( self ):
        for i in range(2500):
            self.arr[i]=0.0
dll.laser_mode.restype = POINTER(StructPointer) 
n=c_long(50)    #方镜上点的个数
n_b=int(50)
k=c_long(30)
#ccl=np.ones((n,n),float)
ccl=StructPointer()
#dll.hello()
ccl=dll.laser_mode(n,k)
I=np.zeros((n_b,n_b),float)
for i in range(n_b):
    for j in range(n_b):
        I[i][j]=ccl.contents.arr[i*n_b+j]
X=range(n_b)
Y=range(n_b)
fig = plt.figure()
ax = Axes3D(fig)
ax.plot_surface(X,Y,I, rstride=1, cstride=1, cmap='rainbow')
plt.show()
