# eval with expression 
x = 5
a = eval("x+5")
print(a)
print("-"*50)

# eval with global variable
num = 10
x = 5
a = eval("num*x")
print(a)
print("-"*50)

# eval with local variable
a = eval("x+2", {"x":2})
print(a)
print("-"*50)

# eval with strings
text = "4*6-3"
print("The given text : ", text)
a = eval(text)
print(a)
print("-"*50)

# eval with math module
import math 
a = eval('math.pi*2')
print(a)
print("-"*50)
r = 2
Area = eval("math.pi*r*r")
print("Area of circle is:", Area)
print("-"*50)
s = eval("math.sqrt(Area)")
print(s)
print("-"*50)

# eval with Boolean Expression

a = 2
b = 3
c = eval("a!=b")  #1
d = eval("a>2 and b==3") #0
e = eval("a == b")  #0

print(c,d,e, sep=" ")



