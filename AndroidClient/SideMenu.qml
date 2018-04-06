import QtQuick 2.0

Item {

    property var fontSize: 18
    FontLoader { id: fixedFont; name: "Drum"; source: "fonts/11587.ttf" }

    Image{
        id : headerImage
        anchors.horizontalCenter: parent.horizontalCenter
        source: "pics/logo2.png"
        sourceSize.width: parent.width
        sourceSize.height: parent.height/5
    }

    //just for spaces
    Rectangle{
        id : emptySpaces
        anchors.top: headerImage.bottom
        width: parent.width
        height: 20
    }

    Column{
        anchors.top : emptySpaces.bottom
        anchors.bottom: parent.bottom
        width: parent.width

        Row{
            width: parent.width
            height: parent.height * 0.2
            spacing: 10

            Rectangle{
                width: 10
                height: 10
            }

            Image{
                source: "icons/home.png"
                sourceSize.width: 20
                sourceSize.height: 20
            }

            Text {
                id: name
                text: qsTr("Home")
                font.family: fixedFont.name
                font.pixelSize: fontSize
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                          stackView.push("MainPage.qml")
                          drawer.visible = false
                    }
                }
            }
        }


        Row{
            width: parent.width
            height: parent.height * 0.2
            spacing: 10

            Rectangle{
                width: 10
                height: 10
            }

            Image{
                source: "icons/bag.png"
                sourceSize.width: 20
                sourceSize.height: 20
            }


            Text {
                text: qsTr("Bag")
                font.family: fixedFont.name
                font.pixelSize: fontSize
            }
        }


        Row{
            width: parent.width
            height: parent.height * 0.2
            spacing: 10

            Rectangle{
                width: 10
                height: 10
            }

            Image{
                source: "icons/account.png"
                sourceSize.width: 20
                sourceSize.height: 20
            }

            Text {
                text: qsTr("My account")
                font.family: fixedFont.name
                font.pixelSize: fontSize
            }
        }



        Row{
            width: parent.width
            height: parent.height * 0.2
            spacing: 10

            Rectangle{
                width: 10
                height: 10
            }

            Image{
                source: "icons/settings.png"
                sourceSize.width: 20
                sourceSize.height: 20
            }

            Text {
                text: qsTr("App settings")
                font.family: fixedFont.name
                font.pixelSize: fontSize
            }
        }


        Row{
            width: parent.width
            height: parent.height * 0.2

            spacing: 10

            Rectangle{
                width: 10
                height: 10
            }

            Image{
                source: "icons/help.png"
                sourceSize.width: 20
                sourceSize.height: 20
            }


            Text {
                text: qsTr("Help & FAQs")
                font.family: fixedFont.name
                font.pixelSize: fontSize
            }
        }




        Rectangle{
            color: "grey"
            width: parent.width
            height: 2
            border.width: 2
        }


        Rectangle{
            width: parent.width
            height: parent.height * 0.2

            Text {
                text: qsTr("  Version 1.0")
                font.family: fixedFont.name
                font.pixelSize: 20
            }
        }


    }


}
