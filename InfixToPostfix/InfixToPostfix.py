# In this project we have 2 main modes :

# First : Converting infix formats to postfix ones and calculate them.
#   Examples :
#       (A+B)*(C-D)/E+F -> AB+CD-*E/F+

# Second : Just like the first one but draw a graph from 0 to 20 using matplotlib.
#   For that we can just save the result for "x = 0 to 20" in an array called ypoints and plot it!

import matplotlib.pyplot as plt
import tkinter as tk


def submit1():
    user_input = input_entry.get()
    postfix = infixToPostfix(user_input)
    val = calc(user_input)
    output_label.config(text="Postfix string is : " +
                        postfix + " = " + str(val))


def submit2():
    user_input = input_entry.get()
    postfix = infixToPostfix(user_input)
    output_label.config(text="Postfix string is : " + postfix)
    '''ypoints = []
    for i in range(0, 21):
        ypoints[i] = i #calc(user_input)'''
    ypoints = [3, 8, 1, 10, 5, 7]
    plt.plot(ypoints)
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


def calc(str):
    print(str)
    return 0


def infixToPostfix(inp):
    # inp = input(">>> Enter Infix string : ")
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
                        postfixStr += peek
                        stack.pop()
                        peek = stack.pop()
                        stack.append(peek)
                    stack.pop()
                    key = 0
                elif pre(char, peek):
                    stack.append(char)
                    key = 0

                elif pre(char, peek) == 0:
                    postfixStr += peek
                    stack.pop()

                # print(stack)
            key = 1
    # Output
    a = stack.pop()
    while a != "0":
        # print(stack)
        postfixStr += a
        a = stack.pop()
    # print(">>> Postfix string is :" + postfixStr)
    return postfixStr


root = tk.Tk()
root.title("Input Window")
root.geometry("400x200")

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
