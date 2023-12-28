import numpy as np

a = np.array([[10,20],[30,40],[50,60]])
print(a)
print("-"*50)

# sum
b = np.sum(a)
print("Sum of all elements\t", b)
print("-"*50)

b = np.sum(a, axis=0)
print("Sum of elements column wise\t", b)
print("-"*50)

b = np.sum(a, axis=1)
print("Sum of elements row wise\t", b)
print("-"*50)


# min function
b = np.min(a)
print("Minimum value in array \t", b)
print("-"*50)


b = np.min(a, axis=0)
print("Minimum value in array column wise \t", b)
print("-"*50)

b = np.min(a, axis=1)
print("Minimum value in array column wise \t", b)
print("-"*50)


# max function

b = np.max(a)
print("Maximum value in array \t", b)
print("-"*50)


b = np.max(a, axis=0)
print("Maximum value in array column wise \t", b)
print("-"*50)

b = np.max(a, axis=1)
print("Maximum value in array column wise \t", b)
print("-"*50)

# mean function

b = np.mean(a)
print("Mean of all values  ", b)
print("-"*50)

b = np.mean(a, axis=0)
print("Mean of values column wise  ", b)
print("-"*50)

b = np.mean(a, axis=1)
print("Mean of values row wise  ", b)
print("-"*50)


# var function

b = np.var(a)
print("Variance of the whole matrix is: ", b)
print("-"*50)

b = np.var(a, axis=0)
print("Variance column wise: ", b)
print("-"*50)

b = np.var(a, axis=1)
print("Variance row wise: ", b)
print("-"*50)

# std function

b = np.std(a)
print("Standard deviation (SD) of the whole matrix is: ", b)
print("-"*50)

b = np.std(a, axis=0)
print("Standard deviation (SD) column wise: ", b)
print("-"*50)

b = np.std(a, axis=1)
print("Standard deviation (SD) row wise: ", b)
print("-"*50)


# median function

b = np.median(a)
print("Median of the whole matrix is: ", b)
print("-"*50)

b = np.median(a, axis=0)
print("Median column wise: ", b)
print("-"*50)

b = np.median(a, axis=1)
print("Median row wise: ", b)
print("-"*50)










