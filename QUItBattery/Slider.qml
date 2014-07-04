import QtQuick 2.0

Item {
    id: root
    width: 200
    height: 112

    property real value: 0
    property real maximum: 1
    property real minimum: 0
    property int xMax: width - handle.width - 4
    property alias text: sliderText.text

    onValueChanged: updatePos();
    onXMaxChanged: updatePos();
    onMinimumChanged: updatePos();

    function updatePos() {
        if (maximum > minimum) {
            var pos = 2 + (value - minimum) * root.xMax / (maximum - minimum);
            pos = Math.min(pos, width - handle.width - 2);
            pos = Math.max(pos, 2);
            handle.x = pos;
        } else {
            handle.x = 2;
        }
    }

    Rectangle {
        id: backgroundBar
        anchors.fill: parent
        anchors.topMargin: 40
        anchors.bottomMargin: 40
        border.width: 1
        border.color: "white"
        opacity: 0.2
        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightgray" }
            GradientStop { position: 1.0; color: "gray" }
        }
    }

    Rectangle {
        id: filler
        anchors.left: parent.left
        anchors.right: handle.horizontalCenter
        anchors.top: backgroundBar.top
        anchors.bottom: backgroundBar.bottom
        border.width: 1
        border.color: "#202020"
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#f0f0f0" }
            GradientStop { position: 1.0; color: "#404040" }
        }
    }

    Item {
        id: handle
        width: 80
        height: parent.height
        Image {
            anchors.centerIn: parent
            source: "images/handle.png"
        }
        Image {
            id: handleHighlight
            anchors.centerIn: parent
            source: "images/toggle.png"
            opacity: mouseArea.pressed ? 0.6 : 0
            Behavior on opacity {
                NumberAnimation { duration: 200 }
            }
        }
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            anchors.margins: -20
            drag.target: parent
            drag.axis: Drag.XAxis
            drag.minimumX: 2
            drag.maximumX: root.xMax+2
            onPositionChanged: {
                value = (maximum - minimum) * (handle.x-2) / root.xMax + minimum;
            }
        }
    }

    Text {
        id: sliderText
        anchors.centerIn: parent
        font.pixelSize: 28
        style: Text.Outline
        styleColor: "white"
        color: "black"
        opacity: 0.4
    }
}
