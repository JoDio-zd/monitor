'''
主要用来做一个局部网内的摄像头
将摄像头获取的图像爬取下来
将图片连接视频输出
'''
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import *
import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
import requests

class Window(QWidget):
    def __init__(self):
        '基本页面搭建'
        super().__init__()
        self.setGeometry(400, 100, 650, 370)
        layout = QVBoxLayout()
        self.label = QLabel()
        self.label.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.label)
        self.setLayout(layout)
        timer = QTimer(self)
        timer.timeout.connect(self.showphoto)
        # 设置刷新时间，单位为ms
        timer.start(10000)
    def showphoto(self): 
        re = requests.get('http://127.0.0.1/index.jpg')
        url = 'http://192.168.8.1:8083/?action=snapshot'
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
