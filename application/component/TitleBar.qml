import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle{
    id: titlebar

    property string title
    property bool isfullscreen
    property bool skinIsVisible
    property variant skinIcon
    property variant skinHoverIcon
    property variant dropdownmenuIcon
    property variant dropdownmenuHoverIcon
    property variant minIcon
    property variant minHoverIcon
    property variant maxIcon
    property variant maxHoverIcon
    property variant normalIcon
    property variant normalHoverIcon
    property variant closeIcon
    property variant closeHoverIcon

    signal skinHovered()
    signal dropdownmenuClicked()
    signal minClicked()
    signal maxClicked()
    signal closeClicked()
    signal doubleClicked()

    width: parent.width
    color: 'transparent'

    MouseArea {
        anchors.fill: parent
        hoverEnabled: false
        onEntered: {}
        onExited: {}
        onWheel: {}
        onClicked: {}
        onDoubleClicked:{
            titlebar.doubleClicked();
        }
    }

    RowLayout{
        anchors.fill: parent
        anchors.margins: 0
        Text{
            id: text
            anchors.left: parent.left
            anchors.right: min.left
            anchors.leftMargin: 10
            color: "white"
            font.bold: true
            font.pointSize: 12
            height: parent.height
            text: titlebar.title
        }

        Rectangle{
            id: skin
            anchors.right: dropdownmenu.left
            width: parent.height
            height: parent.height
            color: "transparent"

            Image{
                id: skinimage
                anchors.fill: parent
                source: titlebar.skinIcon
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                propagateComposedEvents: true
                onEntered: {
                    parent.color="lightgreen";
                    skinimage.source = titlebar.skinHoverIcon;
                    titlebar.skinHovered();
                }
                onExited: {
                    parent.color="transparent";
                    skinimage.source = titlebar.skinIcon
                }
                onWheel: {}
                onClicked: {
                    // titlebar.minClicked();
                    mouse.accepted = false;
                }
            }
        }

        Rectangle{
            id: dropdownmenu
            anchors.right: min.left
            width: parent.height
            height: parent.height
            color: "transparent"

            Image{
                id: dropdownmenuimage
                anchors.fill: parent
                source: titlebar.dropdownmenuIcon
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                propagateComposedEvents: true
                onEntered: {
                    parent.color="lightgreen";
                    dropdownmenuimage.source = titlebar.dropdownmenuHoverIcon
                    
                }
                onExited: {
                    parent.color="transparent";
                    dropdownmenuimage.source = titlebar.dropdownmenuIcon
                }
                onWheel: {}
                onClicked: {
                    titlebar.dropdownmenuClicked();
                    mouse.accepted = false;
                }
            }
        }


        Rectangle{
            id: min
            anchors.right: max.left
            width: parent.height
            height: parent.height
            color: "transparent"

            Image{
                id: minimage
                anchors.fill: parent
                source: titlebar.minIcon
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                propagateComposedEvents: true
                onEntered: {
                    parent.color="lightgreen";
                    minimage.source = titlebar.minHoverIcon
                }
                onExited: {
                    parent.color="transparent";
                    minimage.source = titlebar.minIcon
                }
                onWheel: {}
                onClicked: {
                    titlebar.minClicked();
                    mouse.accepted = false;
                }
            }
        }

        Rectangle{
            id: max
            anchors.right: close.left
            width: parent.height
            height: parent.height
            color: "transparent"
            Image{
                id: maximage
                anchors.fill: parent
                source: titlebar.isfullscreen? titlebar.maxIcon : titlebar.normalIcon
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    parent.color = "lightgreen";
                    maximage.source =  titlebar.isfullscreen ? titlebar.maxHoverIcon : titlebar.normalHoverIcon

                }
                onExited: {
                    parent.color = "transparent";
                    maximage.source =  titlebar.isfullscreen ? titlebar.maxIcon : titlebar.normalIcon

                }
                onWheel: {}
                onClicked: {
                    titlebar.maxClicked();
                }
            }
        }

        Rectangle{
            id: close
            anchors.right: parent.right
            width: parent.height
            height: parent.height
            color: "transparent"

            Image{
                id: closeimage
                anchors.fill: parent
                source: titlebar.closeIcon
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    parent.color="lightgreen";
                    closeimage.source = titlebar.closeHoverIcon
                }
                onExited: {
                    parent.color="transparent";
                    closeimage.source = titlebar.closeIcon
                }
                onWheel: {}

                onClicked: {
                    titlebar.closeClicked();
                }
            }
        }
    }
}
