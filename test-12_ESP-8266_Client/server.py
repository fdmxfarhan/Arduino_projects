#!/usr/bin/env python3

import socket,time
import tkinter as tk

root = tk.Tk()
root.geometry("600x300")


##class ClientThread(Thread): 
## 
##    def __init__(self,ip,port): 
##        Thread.__init__(self) 
##        self.ip = ip 
##        self.port = port 
####        print( "[+] New server socket thread started for " + ip + ":" + str(port) )
## 
##    def run(self): 
##        while True : 
##            data = conn.recv(2048) 
##            if data:
##                print("Server received data:", data)
##            time.sleep(1)
####            MESSAGE = raw_input("Multithreaded Python server : Enter Response from Server/Enter exit:")
####            if MESSAGE == 'exit':
####                break
####            conn.send(MESSAGE)  # echo 



########################################   Server initialize
HOST = '192.168.43.210'
PORT = 65432
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(12)
conn, addr = s.accept()
print('Connected by', addr)












########################################
def resetserv():
    s.close()
    s.bind((HOST, PORT))
    s.listen(12)
    conn, addr = s.accept()
    print('Connected by', addr)

def ledon():
    conn.sendall(b'N')
def ledoff():
    conn.sendall(b'F')

















############################################################## Reset server
##label1 = tk.Label(root, text="Reset the server")
##label1.place(x = 20, y = 200 , width = 200, height = 25)
##
##connectserver = tk.Button(root, text='Reset', width=25, command = resetserv)
##connectserver.place(x = 20, y = 240 , width = 100, height = 25)



############################################################## Pager 1
label1 = tk.Label(root, text="Pager 1")
label1.place(x = 20, y = 30 , width = 100, height = 25)
    
on1 = tk.Button(root, text='On', width=25, command=ledon)
on1.place(x = 20, y = 70 , width = 100, height = 25)

off1 = tk.Button(root, text='Off', width=25, command=ledoff)
off1.place(x = 20, y = 110 , width = 100, height = 25)
############################################################## Pager 2
label1 = tk.Label(root, text="Pager 2")
label1.place(x = 170, y = 30 , width = 100, height = 25)
    
on1 = tk.Button(root, text='On', width=25, command=ledon)
on1.place(x = 170, y = 70 , width = 100, height = 25)

off1 = tk.Button(root, text='Off', width=25, command=ledoff)
off1.place(x = 170, y = 110 , width = 100, height = 25)
############################################################## Pager 3
label1 = tk.Label(root, text="Pager 3")
label1.place(x = 320, y = 30 , width = 100, height = 25)
    
on1 = tk.Button(root, text='On', width=25, command=ledon)
on1.place(x = 320, y = 70 , width = 100, height = 25)

off1 = tk.Button(root, text='Off', width=25, command=ledoff)
off1.place(x = 320, y = 110 , width = 100, height = 25)
############################################################## Pager 4
label1 = tk.Label(root, text="Pager 4")
label1.place(x = 470, y = 30 , width = 100, height = 25)
    
on1 = tk.Button(root, text='On', width=25, command=ledon)
on1.place(x = 470, y = 70 , width = 100, height = 25)

off1 = tk.Button(root, text='Off', width=25, command=ledoff)
off1.place(x = 470, y = 110 , width = 100, height = 25)


tk.mainloop()




##while True:
##    conn.sendall(b'Hey, Whats up?!')
##    time.sleep(2)
