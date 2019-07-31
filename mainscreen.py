import subprocess, sys
from Tkinter import * 
inp = raw_input("Enter name: ")

if(inp == 's'):
    root = Tk()
    root.geometry("500x500")
    e = Entry(root)
    w = Label(root, text="Hello, world!")
    w.pack()

    root.mainloop()

if(inp == 't'):
    subprocess.call("./mainp")