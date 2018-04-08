import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3


Item {
    objectName: "currentProduct"

    property string m_id : "none"
    property string m_name : "none"
    property string m_detail : "none"



Header{
    id : header
    //text: "Current"
     myState : "back"
     anchors.top : parent.top
}



Rectangle{
    id : mainRect

    anchors{
        top : header.bottom
        left: parent.left
        right: parent.right
        bottom: btn.top
        leftMargin: 15
        topMargin: 15
    }

    ScrollView{
        anchors.fill: parent
        horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
        verticalScrollBarPolicy: Qt.ScrollBarAlwaysOff

        clip: true

               Column{


                    Text{
                        text : ""
                    }


                    Text{
                        width: parent.width
                        text: m_name
                        font.bold : true
                        clip : true
                        wrapMode : Text.Wrap
                    }


                    Text{
                        text : ""
                    }




                    Image{
                        anchors.horizontalCenter: parent.horizontalCenter
                        id : myImage

                        width: 200
                        height: 200
                        source: "image://myprovider/product/"+m_id
                    }



                    Text{
                        anchors.left: parent.left
                        anchors.right: parent.right
                        //anchors.horizontalCenter: parent.horizontalCenter
                        text : " "
                    }

                    Text{
                        anchors.left: parent.left
                        anchors.right: parent.right
                        //anchors.horizontalCenter: parent.horizontalCenter
                        text: m_detail
                        //clip : true
                        wrapMode : Text.Wrap
                        textFormat : Text.StyledText
                    }

                }// colunm

    }//scrollView

}  //Rectangle


Button{
    id : btn
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottom: parent.bottom
    text: qsTr("Add to bag")
    anchors.bottomMargin: 10
}

}
