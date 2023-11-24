def Recursive_Max(a,M=0,i=0):
    if len(a) == i :
        return M
    if (a[i]>M) :
        M = a[i]
    return Recursive_Max(a,M,i+1)

a=[7,2,45,98,0,50]
print(Recursive_Max(a))