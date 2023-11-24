# C(n, r) = n! / (r!(n-r)!)

def combinations(n, r):
    if r > n:
        return 0
    if r == 0:
        return 1
    result = 1
    for i in range(1, r + 1):
        result *= (n - r + i)
        result //= i
    return result
print(combinations(5, 3))

#non-recursive better