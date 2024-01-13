# In this project we have 2 main modes :

# First : Converting infix formats to postfix ones and calculate them.
#   Examples :
#       (A+B)*(C-D)/E+F -> A B + C D - * E / F +
'''NO SPACE'''

# Second : Just like the first one but draw a graph from -20 to 20 using matplotlib.
#   For that we can just save the result for "x = -20 to 20" in an array called ypoints and plot it!

import matplotlib.pyplot as plt
import tkinter as tk


def submit1():
    user_input = input_entry.get()
    postfix = infixToPostfix(user_input)
    val = calc(postfix)
    output_label.config(text="Postfix string is : " +
                        postfix + " = " + str(val))


def submit2():
    user_input = input_entry.get()
    postfix = infixToPostfix(user_input)
    output_label.config(text="Postfix string is : " + postfix)
    xpoints = []
    ypoints = []
    for i in range(0, 21):
        xpoints.append(i)
        ypoints.append(calc(postfix, i))
    plt.plot(xpoints,ypoints)
    plt.show()


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


def calc(str, x=1):
    stack = []
    tmp = ""

    for char in str:
        # Operands
        if char.isdigit() or char==".":
            tmp += char

        elif char.isalpha():  # Mode2 : It's X
            stack.append(x)

        # Operation
        else:
            if tmp != "":
                stack.append(float(tmp))  # Extracting Numbers
                tmp = ""
            # print(stack)

            if char != " ":
                secondOperand = stack.pop()
                firstOperand = stack.pop()

                if char == '+':
                    stack.append(firstOperand + secondOperand)
                elif char == '-':
                    stack.append(firstOperand - secondOperand)
                elif char == '*':
                    stack.append(firstOperand * secondOperand)
                elif char == '/':
                    stack.append(firstOperand // secondOperand)
                elif char == '^':
                    stack.append(firstOperand ** secondOperand)
    return stack.pop()


def infixToPostfix(inp):
    # inp = input(">>> Enter Infix string : ")
    stack = ["0"]
    postfixStr = ""
    key = 1

    for char in inp:
        if char.isalpha() or char.isdigit() or char==".":
            # Operand :
            postfixStr += char

        else:
            postfixStr += " "
            # Operation :
            while key:
                peek = stack.pop()
                stack.append(peek)
                if char == "(":
                    stack.append(char)
                    key = 0

                elif char == ")":
                    while peek != "(":
                        postfixStr += " " + peek
                        stack.pop()
                        peek = stack.pop()
                        stack.append(peek)
                    stack.pop()
                    key = 0
                elif pre(char, peek):
                    stack.append(char)
                    key = 0

                elif pre(char, peek) == 0:
                    postfixStr += " " + peek
                    stack.pop()

                # print(stack)
            key = 1
    # Output
    a = stack.pop()
    while a != "0":
        # print(stack)
        postfixStr += " " + a
        a = stack.pop()
    print(">>> Postfix string is :" + postfixStr)
    return postfixStr


root = tk.Tk()
root.title("Input Window")
root.geometry("300x150")

input_label = tk.Label(root, text="Enter Infix string :")
input_label.pack()

input_entry = tk.Entry(root, width=20)
input_entry.pack()

button1 = tk.Button(root, text="Mode 1", command=submit1)
button1.pack()

button2 = tk.Button(root, text="Mode 2", command=submit2)
button2.pack()

output_label = tk.Label(root)
output_label.pack()

root.mainloop()
