import QtQuick 2.15
import QtQuick.Controls 2.15


import QtQuick.Window 2.2
import QtQuick 2.3
 
 
 
Rectangle {
    
    visible:true
    anchors.fill:parent
    //height:400
    color:"yellow"


    Button
    {
        x:10
        y:10
        text:"Show Order"
        onClicked:mainView.onStart(0)
    }
 
 
 
}