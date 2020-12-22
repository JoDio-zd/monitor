'''
主要用来做一个局部网内的摄像头
将摄像头获取的图像爬取下来
将图片连接视频输出
可以使用按钮来控制小车的运行
'''
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import *
import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
import requests
import socket

class Window(QWidget):
    def __init__(self):
        '基本页面搭建'
        super().__init__()
        self.setGeometry(400, 100, 900, 370)
        layout = QVBoxLayout()
        self.label = QLabel()
        self.label.setGeometry(10, 10, 640, 360)
        layout.addWidget(self.label)
        self.setLayout(layout)
        self.turn_left = QPushButton('向左', self)
        self.turn_left.setGeometry(710, 60, 50, 30)
        self.turn_right = QPushButton('向右', self)
        self.turn_right.setGeometry(810, 60, 50, 30)
        self.turn_up = QPushButton('向上', self)
        self.turn_up.setGeometry(760, 20, 50, 30)
        self.turn_down = QPushButton('向下', self)
        self.turn_down.setGeometry(760, 60, 50, 30)
        self.forward = QPushButton('前', self)
        self.forward.setGeometry(760, 160, 50, 30)
        self.back = QPushButton('后', self)
        self.back.setGeometry(760, 200, 50, 30)
        self.left = QPushButton('左', self)
        self.left.setGeometry(710, 200, 50, 30)
        self.right = QPushButton('右', self)
        self.right.setGeometry(810, 200, 50, 30)
        timer = QTimer(self)
        timer.timeout.connect(self.showphoto)
        # 设置刷新时间，单位为ms
        t = 10
        timer.start(t)
        self.turn_up.clicked.connect(self.is_one_)
        self.turn_down.clicked.connect(self.is_two_)
        self.turn_left.clicked.connect(self.is_three_)
        self.turn_right.clicked.connect(self.is_four_)
        self.forward.clicked.connect(self.is_five_)
        self.back.clicked.connect(self.is_six_)
        self.left.clicked.connect(self.is_seven_)
        self.right.clicked.connect(self.is_eight_)
        ip = '192.168.8.182'
        port = 8080
        self.phone = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        self.phone.connect((ip, port))

    def is_one_(self):
        is_one = 1
        self.send_message(is_one)

    def is_two_(self):
        is_two = 2
        self.send_message(is_two)

    def is_three_(self):
        is_three = 3
        self.send_message(is_three)

    def is_four_(self):
        is_four = 4
        self.send_message(is_four)
    
    def is_five_(self):
        is_five = 5
        self.send_message(is_five)
    
    def is_six_(self):
        is_six = 6
        self.send_message(is_six)

    def is_seven_(self):
        is_seven = 7
        self.send_message(is_seven)
    
    def is_eight_(self):
        is_eight = 8
        self.send_message(is_eight)

    def send_message(self, which_one):
        if which_one == 1:
            code = 'XG' * 5
        elif which_one == 2:
            code = 'XH' * 5
        elif which_one == 3:
            code = 'XJ' * 5
        elif which_one == 4:
            code = 'XK' * 5
        elif which_one == 5:
            code = 'XB' * 1
        elif which_one == 6:
            code = 'XA' * 1
        elif which_one == 7:
            code = 'XC' * 1
        elif which_one == 8:
            code = 'XE' * 1
        # ip = '192.168.8.182'
        # port = 8080
        # phone=socket.socket(socket.AF_INET,socket.SOCK_STREAM)  #AF_INET基于网络类型的套接字家族;SOCK_STREAM,TCP协议。“买手机”
        # phone.connect((ip, port))
        self.phone.send(code.encode('utf8'))


    def showphoto(self): 
        url = 'http://192.168.8.1:8083/?action=snapshot.png'
        # url = 'http://127.0.0.1/index.jpg'
        re = requests.get(url=url)
        # 局部网内图片爬取
        f = open('./photo/f.png', 'wb')
        f.write(re.content)
        f.close()
        png = QtGui.QPixmap('./photo/f.png')
        self.label.setPixmap(png)
        re.close()
App = QApplication(sys.argv)
window = Window()
window.show()
App.exit(App.exec_()) 
window.phone.close()
