import QtQuick 2.0

Item {


    Component.onCompleted: {
        client.fillCatalogList();
       // console.log("width = " + width + "  " + height)
    }

    ListView{
        id : catalogList
        anchors.fill: parent
        model: myModel
        delegate: Text{
            width: 100
            height: 100
                text: modelData.name
            }
        }


}
