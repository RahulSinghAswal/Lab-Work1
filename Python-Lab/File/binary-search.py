# recursive binary search.
# Returns index of x in arr if present, else -1
def binary_search(arr, low, high, x):

	# Check base case
	if high >= low:

		mid = (high + low) // 2

		# If element is present at the middle itself
		if arr[mid] == x:
			return mid

		# If element is smaller than mid, then it can only
		# be present in left subarray
		elif arr[mid] > x:
			return binary_search(arr, low, mid - 1, x)

		# Else the element can only be present in right subarray
		else:
			return binary_search(arr, mid + 1, high, x)

	else:
		# Element is not present in the array
		return -1

#Driver code
n = int(input("Enter the no. of elements of list : "))
list1 = []
for i in range(n):
	a = int(input("Enter the element to be inserted in  list : "))
	list1.append(a)
print("Provided list is : \n",list1) 
key = int(input("Enter the element to be found : "))
# Function call
result = binary_search(list1, 0, len(list1)-1, key)

if result != -1:
	print("Element is present at index", str(result))
else:
	print("Element is not present in array")
