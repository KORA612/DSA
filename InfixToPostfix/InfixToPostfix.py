# In this project we have 2 main modes :

# First : Converting infix formats to postfix ones.
#   Examples :
#       (A + B) * (C - D) / E + F  ->  AB+CD-*E/F+

# Second : Just like the first one but draw a graph from 0 to 20 using matplotlib.
#   For that we can just save the result for "x = 0 to 20" in an array called ypoints and plot it!

import matplotlib.pyplot as plt


def value(str):
    if str == "0" or str == "(":
        return (0)
    if str == "+" or str == "-":
        return (1)
    if str == "*" or str == "/":
        return (2)
    if str == "^":
        return (3)


def pre(char, top):
    if value(char) > value(top):
        return 1
    else:
        return 0


# ypoints = []
# plt.plot(ypoints)
# plt.show()

inp = input(">>> Enter Infix string : ")
stack = ["0"]
postfixStr = ""
key = 1

for char in inp:
    if ord(char) >= 48 and ord(char) <= 90:
        # Operand :
        postfixStr += char

    else:
        # Operation :
        while key:
            peek = stack.pop()
            stack.append(peek)
            if char == "(":
                stack.append(char)
                key = 0
                
            elif char == ")":
                while peek != "(":
                    postfixStr +=  peek
                    stack.pop()
                    peek = stack.pop()
                    stack.append(peek)
                stack.pop()
                key = 0
            elif pre(char, peek):
                stack.append(char)
                key = 0
                
            elif pre(char, peek) == 0:
                postfixStr +=  peek
                stack.pop()
                
            print(stack)
        key = 1


# Output
a = stack.pop()
while a != "0":
    print(stack)
    postfixStr +=  a
    a = stack.pop()
print(">>> Postfix string is :" + postfixStr)
