import QtQuick 2.7

Item {
   id : mainPage
   objectName: "mainPage"




    Component.onCompleted: {
        client.fillMainList();
    }
    property int parentWidth : width
    property int parentHeight : height

    Component {
            id: contactDelegate

            Rectangle {
                anchors.fill: parent
                border.width: 1
                color: "green"
                width: 100
                height: 100

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
        cellHeight: 150



        //anchors.horizontalCenter: parent.horizontalCenter
        model: myModel1
        delegate:  Rectangle {

            //border.width: 1
           // color: "green"
            width: parentWidth/2
            height: 150

            Column {
                id : myColumn
                anchors.fill: parent

                Text {
                    anchors.horizontalCenter:  parent.horizontalCenter
                    horizontalAlignment: Text.AlignHCenter
                    width: parent.width
                    text: modelData.name
                    wrapMode: Text.WrapAnywhere
                }

                Image{
                    id : myImage
                    anchors.horizontalCenter:  parent.horizontalCenter
                    width: 100
                    height: 100
                    source: "image://myprovider/"+modelData.id
                }
            }

        }
    }


    function update(){
        console.log("client.fillMainList();"  )
    }
}
