import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    Text {
        id : text
        anchors.centerIn: parent
        text: qsTr("NO CONNECT")
    }

    Button{
        id : button
        anchors.top: text.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "connect"
        onClicked: {
            client.connectToServer()
        }
    }
}
