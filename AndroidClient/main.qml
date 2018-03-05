import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
     id: window
     objectName: "window"
    visible: true
    width: 320
    height: 480
    title: qsTr("Movies Things")


   //side menu
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


        //Main page
        HomePage{

        }


        //Catalog
        CatalogPage{
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
        height: 70
        color: "black"

//        Rectangle{
//            anchors.fill: parent
//            border.width: 1
//            color: "green"
//        }


        MouseArea {
            anchors.fill: parent
            onClicked: {
                 menuBackIcon.state = menuBackIcon.state === "menu" ? "back" : "menu"
                 drawer.visible = true
            }
        }

//        MenuBackIcon {
//          id: menuBackIcon
//          anchors.centerIn: parent
//        }
      }



}
