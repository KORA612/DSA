def Recursive_Decimal_to_Binary(n):
    if n==1 :
        print(1)
        return
    Recursive_Decimal_to_Binary(int(n/2))
    print(n%2)

a=36
print(Recursive_Decimal_to_Binary(a))