def KhayamPascal(n):
    if n == 0:
        return []
    result = [[1]]
    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(result[i - 1][j - 1] + result[i - 1][j])
        row.append(1)
        result.append(row)
    return result

n = 10
result = KhayamPascal(n)
for row in result:
    for num in row:
        print(num, end=" ")
    print()