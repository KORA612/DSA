# 1 1 2 3 5 8 13 21 34 55
# f(n) = 1/(5 ** (1/2)) * ( ((1+(5 ** (1/2)))/2)**n - ((1-(5 ** (1/2)))/2)**n )

def fibo(n) :
    a , b = 1 , 1
    for i in range(n-2) :
        result = a+b
        a = b
        b = result
    return (result)

def fiboFormula(n):
    return(int(1/(5 ** (1/2)) * ( ( (1+(5 ** (1/2))) /2)**n - ((1-(5 ** (1/2)))/2)**n )))

print(fibo(9))
print(fiboFormula(9))

#non-recursive better