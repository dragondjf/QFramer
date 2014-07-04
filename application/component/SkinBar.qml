import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

Rectangle{
    id: skinbar

    property int parentWidth
    property bool animationEnabled
    property string startcolor
    property string middlecolor
    property string stopcolor
    property string dialogcolor
    property int clickedX
    property int clickedY

    x: skinbar.parentWidth
    anchors.top: horizontalseparator.bottom
    anchors.margins: 0
    color: "transparent"


    RowLayout{
        anchors.fill: parent
        anchors.margins: 0
        spacing: 0
        Rectangle{
            id: start
            width: parent.height
            height: parent.height
            anchors.right: middle.left
            color: startcolor
        }
        Rectangle{
            id: middle
            width: parent.height
            height: parent.height
            anchors.right: stop.left
            color: middlecolor
        }
        Rectangle{
            id: stop
            width: parent.height
            height: parent.height
            color: stopcolor
        }
    }

    ColorDialog {
        id: colorDialog
        visible: false
        modality: Qt.NonModal
        title: "Choose a color"
        color: "green"
        showAlphaChannel: true
        onAccepted: {
            if(skinbar.clickedX >= start.x && skinbar.clickedX < middle.x){
                skinbar.startcolor = colorDialog.currentColor;
            }
            else if(skinbar.clickedX >= middle.x && skinbar.clickedX < stop.x){
                skinbar.middlecolor = colorDialog.currentColor;
            }
            else if(skinbar.clickedX >= stop.x && skinbar.clickedX < stop.x + stop.width){
                skinbar.stopcolor = colorDialog.currentColor;
            }
            skinbar.x = skinbar.parentWidth 
        }
        onRejected: { skinbar.x = skinbar.parentWidth }
    }

    Behavior on x {
        enabled: skinbar.animationEnabled
        NumberAnimation { duration: 1000 }
    }
    Behavior on opacity {
        enabled: skinbar.animationEnabled
        NumberAnimation { duration: 1000 }
    }

    MouseArea {
        id: mousearea
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        propagateComposedEvents: false
        onClicked: {
            skinbar.clickedX = mouse.x;
            skinbar.clickedY = mouse.y;
            if(skinbar.clickedX < start.x || skinbar.clickedX > stop.x + stop.width){
                skinbar.x = skinbar.parentWidth
            }else{
                colorDialog.open();                
            }
            mouse.accepted = true;
        }
    }
}
