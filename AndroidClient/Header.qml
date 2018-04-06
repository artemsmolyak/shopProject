import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


Item {
    id: header
    width: parent.width
    height: 38

    property alias text : headerText.text

    Text{
        id: headerText
        anchors.centerIn: parent
        text: ""
        font.family: fixedFont.name
        font.pixelSize: fontSize
    }


    Rectangle{
        anchors.left: parent.left
        width: 50
        height: 38

        MenuBackIcon {
            id: menuBackIcon
            anchors.centerIn: parent
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    //menuBackIcon.state = menuBackIcon.state === "menu" ? "back" : "menu"
                    drawer.visible = true
                }
            }
        }
    }


  }
