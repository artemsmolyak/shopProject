import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0



Item {

 Header{
     id : headerMainPage
     text: swipeView.currentIndex==0 ? "Most viewed" : "Categories"
 }


 SwipeView {
     id: swipeView
     //anchors.fill: parent

     anchors.top : headerMainPage.bottom
     anchors.bottom: parent.bottom
     anchors.left: parent.left
     anchors.right: parent.right



     TopPage{

     }


     CatalogPage{

     }
 }




}
