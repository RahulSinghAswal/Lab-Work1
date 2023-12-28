import numpy as np

#1D array
a = np.array([10,20,30])
print(a)

#2D array
a = np.array([[10,20],[30,40]])
print(a)

#3D array
a = np.array([[[10,20],[30,40]],[[50,60],[70,80]]])
print(a)

#using asarray function
my_list = [10,20,30,40]
a = np.asarray(my_list)
print(a)