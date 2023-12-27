# We have to calculate determinant of a given matrix in a .txt format in 3 diffrent ways:
#   First  -> Laplace expansion
#   Second -> Immediate consequences
#   Third  -> Omid Rezaifar

def Laplace_expansion(arr):
    return 1


def Immediate_consequences(arr):
    return 1


def Omid_Rezaifar(arr):
    return 1


# Main Driver:

# Input:
with open("DSA_Projects\Determinant\input.txt", "r") as file:
    matrix = []
    for line in file:
        row = [int(x) for x in line.split()]
        matrix.append(row)
#print(matrix)
file.close()

# Output:
print("Determinant of the given array is : ")
print("    Laplace expansion :       ",end="")
print(Laplace_expansion(matrix))
print("    Immediate consequences :  ",end="")
print(Immediate_consequences(matrix))
print("    Omid Rezaifar :           ",end="")
print(Omid_Rezaifar(matrix))
