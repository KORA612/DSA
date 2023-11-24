def Recursive_Avg(a,i=0):
    if i==len(a)-1 :
        return a[0]/len(a)
    a[0]+=a[i+1]
    return Recursive_Avg(a,i+1)

a=[1,2,3,4,5,6]
print(Recursive_Avg(a))