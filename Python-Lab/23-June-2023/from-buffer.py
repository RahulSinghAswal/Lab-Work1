import numpy as np

a = b"Welcome to numpy"
arr = np.frombuffer(a, dtype="S1")
print(arr)

