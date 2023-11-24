def Recursive_Greatest_Common_Divisor(a,b):
    if a%b == 0 :
        return b
    return Recursive_Greatest_Common_Divisor(b,a%b)

a,b = 36,30
print(Recursive_Greatest_Common_Divisor(a,b))