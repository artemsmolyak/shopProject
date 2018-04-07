import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


Item {
    id: header
    width: parent.width
    height: 38

    property alias text : headerText.text
    property string myState: "back"


    Component.onCompleted: {
        menuBackIcon.state = myState
    }


    //side menu
     Drawer {
             id: drawer
             width: 0.7 * window.width
             height: window.height

             SideMenu{
                 anchors.fill:parent
             }
         }


    Text{
        id: headerText
        anchors.centerIn: parent
        text: ""
        font.family: fixedFont.name
        font.pixelSize: fontSize
    }


    Rectangle{
        id : rect
        anchors.left: parent.left
        width: 50
        height: 38

        MenuBackIcon {
            id: menuBackIcon
            anchors.centerIn: parent

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    menuBackIcon.state = myState //  menuBackIcon.state === "menu" ? "back" : "menu"
                    if (myState == "menu")
                           drawer.visible = true
                    else if (myState == "back")
                           stackView.pop()
                }
            }
        }
    }


  }
