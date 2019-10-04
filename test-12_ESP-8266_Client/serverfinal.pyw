import socket , time
import tkinter as tk
from tkinter import *
from tkinter import messagebox

pager_num = 4

root = tk.Tk()
root.title("Pager management")
root.geometry("600x300")
menu = Menu(root)      
root.config(menu=menu)
filemenu = Menu(menu)

socket.setdefaulttimeout(2)
TCP_IP = '192.168.43.210'
##TCP_IP = socket.gethostbyname(socket.gethostname())
TCP_PORT = 65432

iplabel = tk.Label(root, text='IP: ' + TCP_IP + ':' + str(TCP_PORT))
iplabel.place(x = 0, y = 0 , width = 200, height = 25)
    

tcpServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
tcpServer.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
tcpServer.bind((TCP_IP, TCP_PORT)) 
conn = []
ip = []
port = []
for i in range(pager_num):
    conn.append(0)
    ip.append(0)
    port.append(0)
    
##for i in range(pager_num):
##    tcpServer.listen(4)
####    print( "Multithreaded Python server : Waiting for connections from TCP clients...") 
##    conn[i], (ip[i],port[i]) = tcpServer.accept()
##    print(ip[i], ' ', port[i])


def pageron1():
    connect1()
    conn[0].sendall(b'N')
def pageroff1():
    conn[0].sendall(b'F')
    connect1()
########################################################    
def pageron2():
    conn[1].sendall(b'N')
    connect2()
def pageroff2():
    conn[1].sendall(b'F')
    connect2()
########################################################    
def pageron3():
    conn[2].sendall(b'N')
    connect3()
def pageroff3():
    conn[2].sendall(b'F')
    connect3()
########################################################    
def pageron4():
    conn[3].sendall(b'N')
    connect4()
def pageroff4():
    conn[3].sendall(b'F')
    connect4()
########################################################    
def connect1():
    ip[0] = 0
    while ip[0] != '192.168.43.143':
        tcpServer.listen(4)
        try:
            conn[0], (ip[0],port[0]) = tcpServer.accept()
        except:
            messagebox.showinfo('error','pager is not online')
            break
    print(ip[0], ' ', port[0], "is conected")
################################################################################
def connect2():
    ip[1] = 0
    while ip[1] != '192.168.43.125':
        tcpServer.listen(4)
        try:
            conn[1], (ip[1],port[1]) = tcpServer.accept()
        except:
            messagebox.showinfo('error','pager is not online')
            break
    print(ip[1], ' ', port[1], "is conected")
################################################################################
def connect3():
    ip[2] = 0
    while ip[2] != '192.168.43.0':
        tcpServer.listen(4)
        try:
            conn[2], (ip[2],port[2]) = tcpServer.accept()
        except:
            messagebox.showinfo('error','pager is not online')
            break
    print(ip[2], ' ', port[2], "is conected")
################################################################################
def connect4():
    ip[3] = 0
    while ip[3] != '192.168.43.0':
        tcpServer.listen(4)
        try:
            conn[3], (ip[3],port[3]) = tcpServer.accept()
        except:
            messagebox.showinfo('error','pager is not online')
            break
    print(ip[3], ' ', port[3], "is conected")
def NewFile():
    print("New File!")


def OpenFile():
    print(name)


def About():
    print("This is a simple example of a menu")

############################################################## Pager 1
label1 = tk.Label(root, text="پيجر 1",font=("B Nazanin bold", 13))
label1.place(x = 20, y = 30 , width = 100, height = 25)
    
on1 = tk.Button(root, text='روشن',font=("B Nazanin", 13) , width=25, command=pageron1)
on1.place(x = 20, y = 70 , width = 100, height = 25)

off1 = tk.Button(root, text='خاموش' ,font=("B Nazanin", 13) , width=25, command=pageroff1)
off1.place(x = 20, y = 110 , width = 100, height = 25)

w2 = Scale(root, from_=0, to=100, orient = HORIZONTAL)
w2.set(10)
w2.place(x = 20, y = 170 , width = 100)
############################################################## Pager 2
label1 = tk.Label(root, text="پيجر 2",font=("B Nazanin bold", 13))
label1.place(x = 170, y = 30 , width = 100, height = 25)
    
on1 = tk.Button(root, text='روشن',font=("B Nazanin", 13) , width=25, command=pageron2)
on1.place(x = 170, y = 70 , width = 100, height = 25)

off1 = tk.Button(root, text='خاموش' ,font=("B Nazanin", 13) , width=25, command=pageroff2)
off1.place(x = 170, y = 110 , width = 100, height = 25)

w2 = Scale(root, from_=0, to=100, orient = HORIZONTAL)
w2.set(10)
w2.place(x = 170, y = 170 , width = 100)
############################################################## Pager 3
label1 = tk.Label(root, text="پيجر 3",font=("B Nazanin bold", 13))
label1.place(x = 320, y = 30 , width = 100, height = 25)
    
on1 = tk.Button(root, text='روشن',font=("B Nazanin", 13) , width=25, command=pageron3)
on1.place(x = 320, y = 70 , width = 100, height = 25)

off1 = tk.Button(root, text='خاموش' ,font=("B Nazanin", 13) , width=25, command=pageroff3)
off1.place(x = 320, y = 110 , width = 100, height = 25)

w2 = Scale(root, from_=0, to=100, orient = HORIZONTAL)
w2.set(10)
w2.place(x = 320, y = 170 , width = 100)
############################################################## Pager 4
label1 = tk.Label(root, text="پيجر 4",font=("B Nazanin bold", 13))
label1.place(x = 470, y = 30 , width = 100, height = 25)
    
on1 = tk.Button(root, text='روشن',font=("B Nazanin", 13) , width=25, command=pageron4)
on1.place(x = 470, y = 70 , width = 100, height = 25)

off1 = tk.Button(root, text='خاموش' ,font=("B Nazanin", 13) , width=25, command=pageroff4)
off1.place(x = 470, y = 110 , width = 100, height = 25)

w2 = Scale(root, from_=0, to=100, orient = HORIZONTAL)
w2.set(10)
w2.place(x = 470, y = 170 , width = 100)

########################################## connect to pager 1
off1 = tk.Button(root, text='اتصال به پيجر 1' ,font=("B Nazanin", 13) , width=25, command=connect1)
off1.place(x = 20, y = 220 , width = 100, height = 40)
########################################## connect to pager 2
off1 = tk.Button(root, text='اتصال به پيجر 2' ,font=("B Nazanin", 13) , width=25, command=connect2)
off1.place(x = 170, y = 220 , width = 100, height = 40)
########################################## connect to pager 3
off1 = tk.Button(root, text='اتصال به پيجر 3' ,font=("B Nazanin", 13) , width=25, command=connect3)
off1.place(x = 320, y = 220 , width = 100, height = 40)
########################################## connect to pager 4
off1 = tk.Button(root, text='اتصال به پيجر 4' ,font=("B Nazanin", 13) , width=25, command=connect4)
off1.place(x = 470, y = 220 , width = 100, height = 40)


menu.add_cascade(label="File", menu=filemenu)
filemenu.add_command(label="New", command=NewFile)
filemenu.add_command(label="Open...", command=OpenFile)
filemenu.add_separator()
filemenu.add_command(label="Exit", command=root.quit)

helpmenu = Menu(menu)
menu.add_cascade(label="Help", menu=helpmenu)
helpmenu.add_command(label="About...", command=About)



tk.mainloop()
