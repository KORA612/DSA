# We have to calculate determinant of a given matrix in a .txt format in 3 diffrent ways:
#   First  -> Laplace expansion
#   Second -> Gaussian elimination
#   Third  -> Omid Rezaifar

def Laplace_expansion(matrix, row=0):
    n = len(matrix)

    if n == 1:
        return matrix[0][0]

    det = 0
    for col in range(n):
        sign = (-1) ** (row + col)
        submatrix = [row[:col] + row[col+1:]
                     for row in (matrix[:row] + matrix[row+1:])]
        det += sign * matrix[row][col] * Laplace_expansion(submatrix)

    return det


def Gaussian_elimination(matrix):
    n = len(matrix)
    if n == 1:
        return matrix[0][0]

    for i in range(n):  # diagonal pointer
        for j in range(i+1, n):  # sub diagonal pointer
            ratio = matrix[j][i] / matrix[i][i]
            for k in range(i, n):  # insider pointer
                matrix[j][k] -= ratio * matrix[i][k]
    res = 1
    for i in range(n):
        res *= matrix[i][i]
    return res


def Omid_Rezaifar(matrix):
    n = len(matrix)
    if n == 1:
        return matrix[0][0]
    if n == 2:
        return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0])


# Main Driver:
'''
import os
cwd = os.getcwd()
files = os.listdir(cwd)
print("Files in %r: %s" % (cwd, files))
'''

# Input:
with open("input.txt", "r") as file:
    matrix = []
    for line in file:
        row = [int(x) for x in line.split()]
        matrix.append(row)
file.close()

# print("row : ",len(matrix))
# print("col : ",len(matrix[0]))
# print(matrix)

if len(matrix) != len(matrix[0]):
    print("Invalid input!")
    exit()

# Output:
print("Determinant of the given array is : ")
print("    Laplace expansion :       ", end="")
print(Laplace_expansion(matrix))
print("    Gaussian elimination :  ", end="")
print(Gaussian_elimination(matrix))
print("    Omid Rezaifar :           ", end="")
print(Omid_Rezaifar(matrix))
