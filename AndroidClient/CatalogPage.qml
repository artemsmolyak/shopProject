import QtQuick 2.0

Item {

    property int parentWidth : width
    property int parentHeight : height


    property var fontSize: 16
    FontLoader { id: fixedFont; name: "Drum"; source: "fonts/11613.ttf" }



    Component.onCompleted: {
        client.fillCatalogList();
       // console.log("width = " + width + "  " + height)
    }

    ListView{
        id : catalogList
        anchors.fill: parent
        model: catalogsModel

        delegate: Rectangle{
            width: parentWidth
            height: 160
             //anchors.horizontalCenter: parent.horizontalCenter

            Row {
                id : myColumn
                anchors.horizontalCenter: parent.horizontalCenter

                Image{
                    id : myImage
                    //anchors.fill: parent
                    width: parentWidth/3
                    height: 90
                    source: "image://myprovider/catalog/"+modelData.id
                }

                Text {
                    width: parentWidth/2
                    //anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    text: modelData.name
                    wrapMode: Text.Wrap

                    font.family: fixedFont.name
                    font.pixelSize: fontSize
                }
            }
            }
        }


}
