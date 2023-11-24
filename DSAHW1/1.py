def Recursive_Division(a,b,i=0):
    if b*i >= a :
        return i-1
    return Recursive_Division(a,b,i+1)
print(Recursive_Division(50,4))