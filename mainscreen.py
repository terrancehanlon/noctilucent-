import subprocess, sys
from Tkinter import * 
import requests

def printtext():
    global e
    global ee
    string = e.get(2) 
    print string 
def login():
    name = e.get()
    password = ee.get()
    r = requests.post('http://localhost:5000/login', json={"name": e.get()})
    # r = requests.request(method='post', url=' http://127.0.0.1:5000/login', data={'name': name})
    print(r.json())




inp = raw_input("Enter name: ")

if(inp == 's'):
    root = Tk()
    root.geometry("500x500")
    w = Label(root, text="Hello, world!")
    e = Entry(root)
    e.insert(0, 'username')
    ee = Entry(root)
    ee.insert(0, 'password')
    ee.config(show="*")
    e.pack()
    e.focus_set()
    ee.pack()
    ee.focus_set()
    
    w.pack()
    b = Button(root,text='okay',command=login)
    b.pack(side='bottom')


    root.mainloop()

if(inp == 't'):
    subprocess.call("./mainp")