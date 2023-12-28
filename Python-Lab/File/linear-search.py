#function for linear search
def linear_Search(list1, key):  
    n = len(list1)
    # Searching list1 sequentially  
    for i in range(0, n):  
        if (list1[i] == key):  
            return i  
    return -1  
  

#Driver code
n = int(input("Enter the no. of elements of list : "))
list1 = []
for i in range(n):
	a = int(input("Enter the element to be inserted in  list : "))
	list1.append(a)
print("Provided list is : \n",list1) 
key = int(input("Enter the element to be found : "))

# linear search function called
res = linear_Search(list1, key)  
if(res == -1):  
    print("Element not found")  
else:  
    print("Element found at index: ", res)  