import QtQuick 2.0
import "../component"

TabWidget {
    gcolor: "green"

    Rectangle {
        id: page1
        objectName: "page1"
        property string title: "Red"
        property string icon: "../images/icons/dark/appbar.tree.leaf.png"
        
        signal clicked()

        anchors.fill: parent
        anchors.margins: 100
        color: "transparent"

        Rectangle {
            anchors.fill: parent; anchors.margins: 0
            color: "transparent"
            Grid {
                columns: 4
                rows: 4
                spacing: 5
                Button { text: color; color: "red"; rotationX: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "green"; rotationX: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "blue"; rotationY: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "cyan"; rotationY: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "magenta"; rotationX: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "red"; rotationY: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "green"; rotationY: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "blue"; rotationX: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "cyan"; rotationY: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "magenta"; rotationZ: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "red"; rotationX: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "green"; rotationY: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "blue"; rotationX: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "cyan"; rotationZ: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "magenta"; rotationX: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
                Button { text: color; color: "magenta"; rotationY: 1; width: page1.width / 4 -5; height: page1.height / 4 - 5 }
            }
        }
    }

    Rectangle {
        id: page2
        objectName: "page2"
        property string title: "Green"
        property string icon: "../images/icons/dark/appbar.tree.leaf.three.png"
        anchors.fill: parent
        color: "transparent"

        Rectangle {
            anchors.fill: parent; anchors.margins: 0
            color: "#7fff7f"
            Text {
                width: parent.width - 20
                anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                text: "Flower stems are green"
                font.pixelSize: 20
                wrapMode: Text.WordWrap
            }
        }
    }

    Rectangle {
        id: page3
        objectName: "page3"
        property string title: "Blue"
        property string icon: "../images/icons/dark/appbar.tree.pine.png"
        anchors.fill: parent
        color: "transparent"

        Rectangle {
            anchors.fill: parent; anchors.margins: 0
            color: "#7f7fff"
            Text {
                width: parent.width - 20
                anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                text: "Violets are blue"
                font.pixelSize: 20
                wrapMode: Text.WordWrap
            }
        }
    }
}
