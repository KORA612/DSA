def Recursive_Truth_Table(n,s=""):
    if n == len(s) :
        print (s)
    else :
        Recursive_Truth_Table(n,s+"0")
        Recursive_Truth_Table(n,s+"1")

print(Recursive_Truth_Table(3))