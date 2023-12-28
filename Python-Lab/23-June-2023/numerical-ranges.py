import numpy as np

a = np.arange(10,20,2)
print(a)
print("-"*50)

a = np.arange(10,30,3, dtype=float)
print(a)
print("-"*50)

a = np.arange(10,22,2)
print(a)
print("-"*50)
arr = np.reshape(a,(2,3))
print(arr)
print("-"*50)

a = np.arange(10,100,10)
print(a)
print("-"*50)

a = a.reshape(3,3)
print(a)
print("-"*50)