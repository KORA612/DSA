import tkinter as tk

def submit_input():
    user_input = input_entry.get()
    output_label.config(text="Submitted Input: " + user_input)

root = tk.Tk()
root.title("Input Window")
root.geometry("400x200")

input_label = tk.Label(root, text="Enter Infix string :")
input_label.pack()

input_entry = tk.Entry(root, width=20)
input_entry.pack()

submit_button = tk.Button(root, text="Submit", command=submit_input)
submit_button.pack()

output_label = tk.Label(root)
output_label.pack()

print(input_entry.get())
root.mainloop()
