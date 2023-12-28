#function for exponentiation of a number
def exponent(base, power) :
   result = base
   if (exponent != 0):
      return (base ** power)
    
   else :
      return 1


#Driver code

base = int(input("Enter a number : "))
power = int(input("Enter the power for the number : "))

print("Exponential value is : ", exponent(base,power))