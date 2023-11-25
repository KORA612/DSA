# [[1, 2, 3],[4, 5, 6]] transpose [[1, 4],[2, 5],[3, 6]]
# 2*3 -> 3*2
# a[i,j] == b[j,i]

def isTranspose(a, b):
  if len(a) != len(b[0]) or len(a[0]) != len(b):
    print ("Dimension")
    return False

  for i in range(len(a)):
    for j in range(len(b[0])):
      if a[i][j] != b[j][i]:
        return False

  return True

a = [[0, 1, 2, 3],[4, 5, 6, 7],[8, 9, 10, 11]]
b = [[0, 4, 8],[1, 5, 9],[2, 6, 10],[3, 7, 11]]

print(isTranspose(a, b))