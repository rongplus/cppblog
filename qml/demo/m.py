from PyQt5 import QtQuick, QtCore, QtQml
from PyQt5.QtGui import QGuiApplication

app = QGuiApplication([])


view = QtQuick.QQuickView()
url = QtCore.QUrl("MessageView.qml")
#url = QtCore.QUrl("c.qml")

view.setSource(url)
view.show()
app.exec()
