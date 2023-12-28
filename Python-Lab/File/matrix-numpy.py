import numpy as np

def printMatrix(matrix) :
    for i in matrix:
        print(i)

# input two matrices
mat1 = ([1, 6, 5],[3 ,4, 8],[2, 12, 3])
mat2 = ([3, 4, 6],[5, 6, 7],[6,56, 7])

mat1 = np.array(mat1)
print("Matrix 1 : \n",mat1)

mat2 = np.array(mat2)
print("Matrix 2 : \n",mat2)

# This will return dot product
res = np.dot(mat1,mat2)

# print resulted matrix
print("Resultant Matrix : \n", res)
