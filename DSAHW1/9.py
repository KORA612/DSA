#1!+2!+3!+...+n!
def Recursive_Sum_of_Fact(n,i=1):
    if i==n :
        return i
    return 1+((n+1)*Recursive_Sum_of_Fact(n+1,i+1))

print(Recursive_Sum_of_Fact(3))