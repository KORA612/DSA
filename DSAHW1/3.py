def Recursive_Reversed(a,i=0):
    if i>=len(a)/2 :
        return a
    t = a[i]
    a[i] = a[len(a)-i-1]
    a[len(a)-i-1] = t
    return Recursive_Reversed(a,i+1)

a=[1,2,3,4,5,6]
print(Recursive_Reversed(a))