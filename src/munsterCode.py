import numpy as np
import ctypes
import sys

munsterCode_lib = ctypes.CDLL('./munsterCode.so')

path=sys.argv

data=np.genfromtxt(path[1]+'/input.txt',skip_header=1)
x0=data[0,:]
y0=data[1,:]
a=data[2,:]
b=data[3,:]
lr=data[4,:]
mI=data[5,:]

arg1=float(x0[3])
arg2=float(y0[3])
arg3=float(a[3])
arg4=float(b[3])
arg5=float(lr[3])
arg6=int(mI[3])

# specify the argument types and return type of the C function
munsterCode_lib.gradient_descent.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_int]

# call the C function
result = munsterCode_lib.gradient_descent(arg1, arg2, arg3, arg4, arg5, arg6)
