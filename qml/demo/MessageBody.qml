import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15

Rectangle {
    id:mainRect
    color: "white"                                    
    anchors.fill:parent
    width:parent.width
    height:parent.height
    
    function gget() {
            console.log("Get:", parent.width)
            return 300
        }
     

    Rectangle
    {
        id:head
        width: parent.width
        height:70
        anchors.leftMargin:20

        CircleLetter {
            id: circleName
            color: "blue"
            //color: colorCode
            text:"dd"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left:parent.left
        }

        Text {
            y:20
            text: "name"
            id:userName
            anchors.left: circleName.right
        }
        Text {
            text: "name"
            id:messageTitle
            anchors.left: circleName.right
            anchors.top:userName.bottom
        }

    }//head

    Rectangle//line
    {
        id: spaceLine
        width: parent.width
        height:1
        color: "black"
        anchors.top:head.bottom
    }//end 

    Rectangle
    {
        id:toolBar
        width:parent.width
        height:50
        anchors.top:spaceLine.bottom
        anchors.left:parent.left
        anchors.right:parent.right
        //color:"blue"

        RowLayout 
        {
            id:toolRow
           // width:parent.width
            height:50
                                
            MyIconButton {
                id: buttonImage1  
                height: 40
                width: 40
                img_src: "Active.png"
                
            }
            MyIconButton {
                id: buttonImage2  
                height: 40
                width: 40
                img_src: "Bin.png"
                
            }
            MyIconButton {
                id: buttonImage3  
                height: 40
                width: 40
                img_src: "Bin.png"
                
            }
            MyIconButton {
                id: buttonImage4  
                height: 40
                width: 40
                img_src: "Active.png"
                
            }
        }

    }//end toolBar

    Rectangle
    {
        id:messageBodys       
        anchors.top:toolBar.bottom
        anchors.left:parent.left
        anchors.right:parent.right
        anchors.bottom:parent.bottom
        color:"blue"

        

        ScrollView {
            id:scrollV
            width: parent.width
            height : parent.height
            contentWidth: parent.width    // The important part
            contentHeight: rectCol.height  // Same
            clip : true  
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            ColumnLayout {
                id: rectCol
                Layout.fillWidth: true
                //width: parent.width*0.9
                Repeater {
                    id: repeater
                    model: 8
                    Item {
                        Layout.fillWidth: true
                        Layout.minimumWidth: gget()
                        height: 300
                        width: parent.width*0.9
          
                        // Rectangle {
                        //     width: parent.width
                        //     height: parent.height
                            
                        
                            Rectangle {
                                width: parent.width
                                height: parent.height*0.9
                         
                                color: "gray"
                                border.color: "black"
                                radius: 15

                                Text {
                                    text: "Message\nhello"
                                
                                }
                        
                                x:10
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        //}
                    }
                }
            }//end row
        }

        
       
    }
    
    

}