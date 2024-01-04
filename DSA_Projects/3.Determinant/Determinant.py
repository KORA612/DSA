# This program calculates determinant of a given matrix in a .txt format in 3 diffrent ways:
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

    res = matrix[0][0]
    for i in range(n-1):  # diagonal pointer
        for j in range(i+1, n):  # sub diagonal pointer
            ratio = matrix[j][i] / matrix[i][i]
            for k in range(i, n):  # insider pointer
                matrix[j][k] -= ratio * matrix[i][k]
        res *= matrix[i+1][i+1]

    return (round(res))


def Omid_Rezaifar(matrix):
    n = len(matrix)
    if n == 1:
        return matrix[0][0]
    if n == 2:
        return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0])
    else:
        subMatrix1 = []
        for row in matrix[1:n]:
            subMatrix1.append(row[1:])
        #print(subMatrix1)
        subMatrix2 = []
        for row in matrix[1:n]:
            subMatrix2.append(row[:-1])

        subMatrix3 = []
        for row in matrix[:-1]:
            subMatrix3.append(row[1:])

        subMatrix4 = []
        for row in matrix[:-1]:
            subMatrix4.append(row[:-1])

        denominator = []
        for row in matrix[1:-1]:
            denominator.append(row[1:-1])

        newMatrix = [
            [Omid_Rezaifar(subMatrix1), Omid_Rezaifar(subMatrix2)],
            [Omid_Rezaifar(subMatrix3), Omid_Rezaifar(subMatrix4)],
        ]

        det = Omid_Rezaifar(denominator)

        if det == 0:
            print("Div by zero")
            return
        else:
            return round((newMatrix[0][0] * newMatrix[1][1] - newMatrix[0][1] * newMatrix[1][0]) / det)


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
    print("Invalid input! / Undifined")
    exit()

# Output:
print("-------------------------------------------")
print("Determinant of the given array is : ")
print("    Laplace expansion :       ", end="")
print(Laplace_expansion(matrix))
print("    Gaussian elimination :  ", end="")
print(Gaussian_elimination(matrix))
print("    Omid Rezaifar :           ", end="")
print(Omid_Rezaifar(matrix))
print("-------------------------------------------")
