import QtQuick 2.0

Item {

    Rectangle{
        anchors.fill: parent
        color: "red"


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


    Component.onCompleted: {
        for(var i = 0; i < myModel.count;i++){
            console.log(i + myModel.get(i))
        }

    }
}
