# Python program to find largest number in a list
def maxElement(list1):
	max = list1[0]
	for x in list1:
		if x > max:
			max = x
	return max


# Driver code
n = int(input("Enter the no. of elements of list : "))
list1 = []
for i in range(n):
	a = int(input("Enter the element to be inserted in  list : "))
	list1.append(a)
print("Provided list is : \n",list1)
print("Largest element is:", maxElement(list1))
