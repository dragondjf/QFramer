import QtQuick 2.0

Rectangle {
    id: statusbar
    property int mainwindowwidth
    property int mainwindowheight
    property int enterX
    property int enterY
    property string text
    // signal sizegripChanged(int x, int y)
    opacity: 1
    anchors.margins: 0

    // Image{
    //     id: sizegrip
    //     width: 30
    //     height: 30
    //     anchors.margins: 0
    //     anchors.right: parent.right
    //     anchors.bottom: parent.bottom
    //     source: "../images/icons/dark/appbar.arrow.expand.png"

    //     MouseArea {
    //         id:sizegripmousearea
    //         anchors.fill: parent
    //         cursorShape: Qt.SizeFDiagCursor
    //         // hoverEnabled: true
    //         // onEntered: {
    //         //     statusbar.enterX = sizegripmousearea.mouseX;
    //         //     statusbar.enterY = sizegripmousearea.mouseY;
    //         // }
    //         // onPositionChanged:{
    //         //     // statusbar.sizegripChanged(mouse.x, mouse.y)
    //         //     var sizeIncrease = (x - statusbar.enterX > 0) && (y - statusbar.enterY > 0)
    //         //     var sizeDecrease = (x - statusbar.enterX < 0) && (y - statusbar.enterY < 0)
    //         //     console.log(sizeIncrease, sizeDecrease)
    //         //     if(sizeIncrease || sizeDecrease){
    //         //         mainwindowwidth =  mainwindowwidth + mouse.x - statusbar.enterX;
    //         //         mainwindowheight = mainwindowheight + mouse.y - statusbar.enterY;
    //         //     }
    //         // }
    //         onWheel:{
    //             console.log(wheel.pixelDelta)
    //             // if (wheel.angleDelta.y > 0)
    //             //     // console.log(wheel.angleDelta.y)
    //             // else
    //             //     // zoomOut();
    //         }
    //     }
    // }

    Text{
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 14
        font.weight: Font.Bold
        color: 'white'
        text: parent.text

        SequentialAnimation on opacity {
            loops: 15;
            NumberAnimation { from: 1; to: 0; duration: 1000 }
            PauseAnimation { duration: 400 }
        }
    }
}
