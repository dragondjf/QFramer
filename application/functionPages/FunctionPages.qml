import QtQuick 2.0
import QtQml.Models 2.1

Rectangle {
    id: root
    color: "lightgray"
    width: 320
    height: 480
    property bool printDestruction: false

//! [0]
    ObjectModel {
        id: pageModel

        Rectangle {
            width: view.width; height: view.height
            color: "#FFFEF0"
            Text { text: "Page 1"; font.bold: true; anchors.centerIn: parent }

            Component.onDestruction: if (printDestruction) print("destroyed 1")
        }
        Rectangle {
            width: view.width; height: view.height
            color: "#F0FFF7"
            Text { text: "Page 2"; font.bold: true; anchors.centerIn: parent }

            Component.onDestruction: if (printDestruction) print("destroyed 2")
        }
        Rectangle {
            width: view.width; height: view.height
            color: "#F4F0FF"
            Text { text: "Page 3"; font.bold: true; anchors.centerIn: parent }

            Component.onDestruction: if (printDestruction) print("destroyed 3")
        }
    }


    // ObjectModel {
    //     id: navgationModel

    //     Rectangle {
    //         width: navgation.width / navgationModel.count; height: navgation.height
    //         // color: "#FFFEF0"
    //         Text { text: "Page 1"; font.bold: true; anchors.centerIn: parent }

    //         MouseArea {
    //             anchors.fill: parent
    //             cursorShape: Qt.PointingHandCursor
    //             hoverEnabled: false
    //             onEntered: {}
    //             onExited: {}
    //             onWheel: {}
    //             onClicked: {
    //                 view.currentIndex = 0
    //             }
    //         }

    //         Component.onDestruction: if (printDestruction) print("destroyed 1")
    //     }
    //     Rectangle {
    //         width: navgation.width / navgationModel.count; height: navgation.height
    //         // color: "#F0FFF7"
    //         Text { text: "Page 2"; font.bold: true; anchors.centerIn: parent }
    //         MouseArea {
    //             anchors.fill: parent
    //             cursorShape: Qt.PointingHandCursor
    //             hoverEnabled: false
    //             onEntered: {}
    //             onExited: {}
    //             onWheel: {}
    //             onClicked: {
    //                 view.currentIndex = 1
    //             }
    //         }

    //         Component.onDestruction: if (printDestruction) print("destroyed 2")
    //     }
    //     Rectangle {
    //         width: navgation.width / navgationModel.count; height: navgation.height
    //         // color: "#F4F0FF"
    //         Text { text: "Page 3"; font.bold: true; anchors.centerIn: parent }
    //         MouseArea {
    //             anchors.fill: parent
    //             cursorShape: Qt.PointingHandCursor
    //             hoverEnabled: false
    //             onEntered: {}
    //             onExited: {}
    //             onWheel: {}
    //             onClicked: {
    //                 view.currentIndex = 2
    //             }
    //         }
    //         Component.onDestruction: if (printDestruction) print("destroyed 3")
    //     }
    // }

 
    ListView {
        id: view
        anchors { fill: parent; topMargin: 100 }
        model: pageModel
        orientation: ListView.Horizontal
        snapMode: ListView.SnapToItem
        currentIndex: navgation.currentIndex
        // dragging: false
        onCurrentIndexChanged:{
            console.log('view' + view.currentIndex);
        }
    }

    Component {
        id: highlightBar
        Rectangle {
            width: 200; height: 100
            color: "green"
            // y: listView.currentItem.y;
            // Behavior on y { SpringAnimation { spring: 2; damping: 0.1 } }
        }
    }


    Component {
        id: navgationDelegate
        Item {
            id: wrapper
            width: 200; height: 100
            
            Text { 
                text: wrapper.ListView.view.model.get(index).pageID
                anchors.centerIn: parent
            }
            // indent the item if it is the current item
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    wrapper.ListView.view.currentIndex = index;
                    view.currentIndex = index;
                }
            }
        }
    }

    ListView {
        id: navgation
        width: navgation.count * 200
        anchors { top: root.top; left: root.left; bottom: view.top }

        model: NavgationModel{}
        delegate: navgationDelegate
        orientation: ListView.Horizontal
        snapMode: ListView.SnapOneItem

        highlight: highlightBar
        highlightFollowsCurrentItem: true
        keyNavigationWraps: true
        currentIndex: view.currentIndex

        // Component.onCompleted: {
        //     console.log(navgation.count)
        //     navgation.width = navgationDelegate.count * 200
        // }
    }
}
