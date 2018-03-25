import QtQuick 2.7

Item {
   id : mainPage
   objectName: "mainPage"


   property int parentWidth : width
   property int parentHeight : height



    Component.onCompleted: {
        client.fillMainList();
        console.log("fillMainList = " + myModel1)
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
            //id : wrapper

            //border.width: 1
            //color: "green"

            width: parentWidth/2
            height: 160

            //color: GridView.isCurrentItem ? "grey" : "white"
            //focus: true

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

                    //color: wrapper.GridView.isCurrentItem ? "red" : "black"
                }
            }

        } //delegate
    }


    function update(){
        console.log("client.fillMainList();"  )
    }
}
