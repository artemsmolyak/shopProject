import QtQuick 2.0
import QtQuick.Controls 1.4

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
   anchors.top :  header.bottom
   anchors.bottom: parent.bottom
   anchors.left: parent.left
   anchors.right: parent.right

   Column{
     anchors.fill: parent


     Text{
         text : " "
     }

       Text{
           anchors.horizontalCenter: parent.horizontalCenter
           width: parent.width
           text: m_name
           font.bold : true
           clip : true
           wrapMode : Text.Wrap
       }


       Text{
           text : " "
       }




     Image{
         anchors.horizontalCenter: parent.horizontalCenter
         id : myImage

         width: parent.width * 0.6
         height: parent.height * 0.6
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

   Button{
       anchors.horizontalCenter: parent.horizontalCenter
       anchors.bottom: parent.bottom
       text: qsTr("Add to bag")
   }

}

}
