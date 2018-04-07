import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0



Item {
    id : mainPage
    objectName: "mainPage"



 Header{
     id : headerMainPage
     anchors.top : parent.top
     text: swipeView.currentIndex==0 ? "Most viewed" : "Categories"
     myState: "menu"
 }






 SwipeView {
     id: swipeView

     //anchors.fill: parent
     //anchors.topMargin: headerMainPage.height
     anchors.top : headerMainPage.bottom
     anchors.left: parent.left
     anchors.right: parent.right
     anchors.bottom: tabBar.top
     //anchors.bottomMargin: tabBar.height

     currentIndex: tabBar.currentIndex


     TopPage{

     }


     CatalogPage{

     }
 }

 TabBar {
     id: tabBar
     width: parent.width/2
     height: 30
     anchors.bottom: parent.bottom
     anchors.horizontalCenter: parent.horizontalCenter
     currentIndex: swipeView.currentIndex

     TabButton {
         width: mytext1.width
         Text{
             id : mytext1
            text: qsTr("Most viewed")
            font.family: fixedFont.name
            font.pixelSize: fontSize
         }
     }

     TabButton {
         width: mytext2.width
         Text{
             id : mytext2
             text: qsTr("Categories")
             font.family: fixedFont.name
             font.pixelSize: fontSize
         }
     }
}

}
