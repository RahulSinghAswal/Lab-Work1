# Selection sort in Python
def selectionSort(array, size):
	
	for ind in range(size):
		min_index = ind

		for j in range(ind + 1, size):
			# select the minimum element in every iteration
			if array[j] < array[min_index]:
				min_index = j
		# swapping the elements to sort the array
		(array[ind], array[min_index]) = (array[min_index], array[ind])


#Driver code
n = int(input("Enter the no. of elements of list : "))
arr = []
for i in range(n):
	a = int(input("Enter the element to be inserted in  list : "))
	arr.append(a)
print("Provided list is : \n",arr) 

size = len(arr)
selectionSort(arr, size)
print('The array after sorting in Ascending Order by selection sort is:')
print(arr)
