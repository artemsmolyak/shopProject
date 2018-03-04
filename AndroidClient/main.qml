import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
     id: window
     objectName: "window"
    visible: true
    width: 320
    height: 480
    title: qsTr("Hello World")


//        StackView {
//            id: stackView
//            //initialItem: swipeView
//            anchors.fill: parent
//        }
//        Page {
//            Label {
//                text: qsTr("Second page")
//                anchors.centerIn: parent
//            }


//            Button{
//                width: 100
//                height: 20
//                onClicked: {
//                    console.log("press")
//                    client.fillMainList()
//                    stackView.push(Qt.resolvedUrl("Page3.qml"))
//                }
//            }
//        }










    Drawer {
            id: drawer
            width: 0.7 * window.width
            height: window.height

        }


    StackView {
        id: stackView
        //initialItem: swipeView
        anchors.fill: parent
    }


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {

            Label {
                //text: qsTr("Main page")
                anchors.centerIn: parent
            }


        }


        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }


            Button{
                width: 100
                height: 100
                onClicked: {
                    console.log("press")
                    client.fillMainList()
                    stackView.push(Qt.resolvedUrl("Page3.qml"))
                }
            }

            ListView{
                id : secondList
                anchors.fill: parent
                model: myModel
                delegate: Text{
                    width: 100
                    height: 100
                        text: modelData
                    }
                }

        }
    }

    ListModel {
        id : secondListModel
        ListElement {
                name: "Apple"
            }
            ListElement {
                name: "Orange"
            }
            ListElement {
                name: "Banana"
            }
    }



    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Home")
        }
        TabButton {
            text: qsTr("Categories")
        }
    }





    header:Rectangle {
        width: 48
        height: 48
        //color: "black"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                 menuBackIcon.state = menuBackIcon.state === "menu" ? "back" : "menu"
                 drawer.visible = true
            }
        }

        MenuBackIcon {
          id: menuBackIcon
          anchors.centerIn: parent
        }
      }

//    SidePane{
//        id : sidepanel
//        visible: false
//    }

}
