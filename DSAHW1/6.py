def Recursive_Multiplier(a,b,r=0):
    r+=a
    if b==1 :
        return r
    return Recursive_Multiplier(a,b-1,r)

a,b = 8,2
print(Recursive_Multiplier(a,b))