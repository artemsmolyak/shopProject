import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
     id: window
    visible: true
    width: 320
    height: 480
    title: qsTr("Hello World")

    Drawer {
            id: drawer
            width: 0.7 * window.width
            height: window.height

        }



    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
            Label {
                text: qsTr("Main page")
                anchors.centerIn: parent
            }

        }


        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
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
        color: "black"

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
