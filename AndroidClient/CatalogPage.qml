import QtQuick 2.0

Item {


    ListView{
        id : secondList
        anchors.fill: parent
        model: myModel
        delegate: Text{
            width: 100
            height: 100
                text: modelData
            }
        }


}
