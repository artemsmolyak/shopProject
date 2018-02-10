import QtQuick 2.3
import QtQuick.Window 2.2

Item {
    id: screenItem
    anchors.fill: parent
    function show() {
        rect.x = 0
        menuVisible = true
    }
    function hide() {
        rect.x = -rect.width
        menuVisible = false
    }
    property int animationDuration: 200
    property bool menuVisible: false
    property int dragThreshold: 120
    property int menuWidth: 300
    Rectangle {
        id: rect
        width: menuWidth
        x: -rect.width
        height: Screen.height
        color: "lightsteelblue"
        Drag.active: menuDragArea.drag.active
        Behavior on x {
            NumberAnimation {
                duration: animationDuration
                easing.type: Easing.InOutQuad
            }
        }
        MouseArea {
            property int dragX: 0
            property int startX: 0
            property int diffX: 0
            id: menuDragArea
            hoverEnabled: true
            height: rect.height
            width: rect.width + 40
            anchors.left: rect.left
            drag.target: rect
            drag.axis: Drag.XAxis
            drag.minimumX: -rect.width
            drag.maximumX: 0
            onPressed: startX = rect.x + rect.width
            onReleased: {
                dragX = rect.x + rect.width
                diffX = Math.abs(startX - dragX)
                if ((diffX > dragThreshold) && (startX == 0)){
                    rect.x = 0
                    menuVisible = true
                } else if ((diffX < dragThreshold) && (startX == 0)){
                    rect.x = -rect.width
                    menuVisible = false
                }
                if ((diffX > dragThreshold) && (startX == rect.width)){
                    rect.x = -rect.width
                    menuVisible = false
                } else if ((diffX < dragThreshold) && (startX == rect.width)){
                    rect.x = 0
                    menuVisible = true
                }
            }
        }
    }
    Rectangle{
        id: shadowRect
        anchors.left: rect.right
        anchors.right: screenItem.right
        opacity: (rect.x + rect.width) / (rect.width * 2.2)
        color: "black"
        height: screenItem.height
        MouseArea{
            id: shadowArea
            anchors.fill: shadowRect
            visible: menuVisible ? true : false
            hoverEnabled: true
            onClicked: {
                if (menuVisible == true){
                    rect.x = -rect.width
                    menuVisible = false
                }
            }
        }
        Rectangle{
            id: shadowRect2
            color: "black"
            anchors.left: parent.left
            width: 5
            opacity: (rect.x + rect.width) / (rect.width * 2)
            height: screenItem.height
        }
        Rectangle{
            id: shadowRect3
            color: "black"
            anchors.left: parent.left
            width: 3
            opacity: (rect.x + rect.width) / (rect.width * 1.9)
            height: screenItem.height
        }
    }
    onMenuVisibleChanged: menuVisible ? rect.x = 0 : rect.x = -rect.width
}
