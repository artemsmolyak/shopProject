import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
     id: window
     objectName: "window"
    visible: true
    width: 320
    height: 480
    title: qsTr("Movies Things")


    property var fontSize: 20
    FontLoader { id: fixedFont; name: "Drum"; source: "fonts/11587.ttf" }


   //side menu
//    Drawer {
//            id: drawer
//            width: 0.7 * window.width
//            height: window.height

//            SideMenu{
//                anchors.fill:parent
//            }
//        }





    StackView {
        id: stackView
        initialItem: busy
        anchors.fill: parent
    }


    BusyIndicator {
        id : busy
        running: image.status === Image.Loading

        Component.onCompleted: {
            running = false;
            if (client.connectToServer()){
                    stackView.push( Qt.resolvedUrl("MainPage.qml"))
            }
            else
                   stackView.push( Qt.resolvedUrl("noConnect.qml"))
        }
    }




//    MainPage{
//       id: mainPage
//    }


//    SwipeView {
//        id: swipeView
//        anchors.fill: parent
//        currentIndex: tabBar.currentIndex


//        //Main page
//        HomePage{

//        }

//        //Catalog
//        CatalogPage{

//        }

////        TabBar {
////            anchors.bottom: parent.bottom
////            id: tabBar
////            currentIndex: swipeView.currentIndex
////            TabButton {
////                text: qsTr("Home")
////                font.family: fixedFont.name
////                font.pixelSize: fontSize
////            }
////            TabButton {
////                Text{
////                text: qsTr("Cadtegories")
////                font.family: fixedFont.name
////                font.pixelSize: fontSize
////                }
////            }
////        }
//    }







    //header

//    header:Rectangle {
//        id: header
//        width: parent.width
//        height: 38

//        Text{
//            id: headerText
//            anchors.centerIn: parent
//            text: swipeView.currentIndex==0 ? "Most viewed" : "Categories"
//            font.family: fixedFont.name
//            font.pixelSize: fontSize
//        }


//        Rectangle{
//            anchors.left: parent.left
//            width: 50
//            height: 38

//            MenuBackIcon {
//                id: menuBackIcon
//                anchors.centerIn: parent
//                MouseArea {
//                    anchors.fill: parent
//                    onClicked: {
//                        //menuBackIcon.state = menuBackIcon.state === "menu" ? "back" : "menu"
//                        drawer.visible = true
//                    }
//                }
//            }
//        }

//      }



}
