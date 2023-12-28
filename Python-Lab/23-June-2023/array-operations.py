# Accessing 
import numpy as np

a = np.array([[10,20,30],[40,50,60]])
print(a)
print("-"*50)

print(a[0])
# first row of the array
print("-"*50)
print(a[1][2])

# copy operation
b = np.copy(a)
print(b)
print("-"*50)

# view operation
c = b.view()
print(c)
print("-"*50)
b[0][2] = 300
print(b)
print("-"*50)

print(c)
print("-"*50)

a[0][2] = 200
print("Array A \n",a)
print("-"*50)
print("Array B \n",b)
print("-"*50)

