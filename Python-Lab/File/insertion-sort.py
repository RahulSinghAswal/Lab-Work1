# Insertion sort in Python

def insertionSort(array):
    for step in range(1, len(array)):
        key = array[step]
        j = step - 1
        # Compare key with each element on the left of it until an element smaller than it is found
        # For descending order, change key<array[j] to key>array[j].
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        # Place key at after the element just smaller than it.
        array[j + 1] = key


#Driver code
n = int(input("Enter the no. of elements of list : "))
arr = []
for i in range(n):
	a = int(input("Enter the element to be inserted in  list : "))
	arr.append(a)
print("Provided list is : \n",arr) 


insertionSort(arr)
print('The array after sorting in Ascending Order by selection sort is:')
print(arr)
