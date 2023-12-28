import numpy as np

# creating array using array() function
print("Creaing array using asarray() function\n")

import numpy as np

arr = np.array([[1, 2, 3], [4, 5, 6]])

# Create an iterator object using nditer
iter_obj = np.nditer(arr, flags=['multi_index'])

# Iterate over the elements using the iterator
for x in iter_obj:
    print(x, iter_obj.multi_index)

