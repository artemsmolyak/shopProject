import QtQuick 2.7

Item {
   id : mainPage
   objectName: "mainPage"

   property var fontSize: 14
   FontLoader { id: fixedFont; name: "Drum"; source: "fonts/11613.ttf" }


   property int parentWidth : width
   property int parentHeight : height



    Component.onCompleted: {
        client.fillMainList();
        console.log("fillMainList = ")
    }


    Component {
            id: contactDelegate

            Rectangle {
                anchors.fill: parent
                border.width: 1
                color: "green"
                width: 100
                height: 100

//                                Image{
//                                    id : myImage
//                                    anchors.horizontalCenter:  parent.horizontalCenter
//                                    width: 90
//                                    height: 90
//                                    source: "image://myprovider/"+modelData.id
//                                }


//                Column {
//                    id : myColumn
//                    anchors.fill: parent

//                    Text {
//                        text: '<b>Price:</b> ' + modelData.price + " .р"
//                    }

//                    Text {
//                        width: parent.width
//                         text: '<b>Name:</b> ' + modelData.name
//                         wrapMode: Text.WrapAnywhere
//                    }


//                    Image{
//                        width: 100
//                        height: 100
//                        source: "image://myprovider/"+modelData.id
//                    }
//                }
            }
        }


    GridView{       
        id : secondList2
        anchors.fill: parent

        cellWidth: parentWidth/2
        cellHeight: 160

        model: myModel1
        delegate:  Rectangle {

            width: parentWidth/2
            height: 160

            Column {
                id : myColumn
                anchors.fill: parent

                Image{
                    id : myImage
                    anchors.horizontalCenter:  parent.horizontalCenter
                    width: 90
                    height: 90
                    source: "image://myprovider/product/"+modelData.id
                }

                Text {
                    width: parent.width * 0.8
                    anchors.horizontalCenter:  parent.horizontalCenter
                    horizontalAlignment: Text.AlignHCenter
                    text: modelData.name
                    wrapMode: Text.Wrap

                    font.family: fixedFont.name
                    font.pixelSize: fontSize
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                     console.log("click")
                     stackView.push( Qt.resolvedUrl("CurrentProduct.qml"))
                }
            }

        } //delegate
    }


    function update(){
        console.log("client.fillMainList();"  )
    }
}
