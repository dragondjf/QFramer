import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import "component"


ApplicationWindow {
    id: mainwindow

    property bool isfullscreen: false
    property int dragpoistionX
    property int dragpoistionY

    function showWindow(){
        if(mainwindow.isfullscreen == true)
            {
                mainwindow.showNormal();
                mainwindow.isfullscreen = false;
            }
        else{
            mainwindow.showFullScreen();
            mainwindow.isfullscreen = true;         
            }
    }

    width: 800
    height: 600
    color: 'green'
    flags: Qt.Window| Qt.FramelessWindowHint
    title: 'QFramer'
    Rectangle{
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "red" }
            GradientStop { position: 0.33; color: "yellow" }
            GradientStop { position: 1.0; color: "green" }
        }

        TitleBar{
            id: titlebar
            title: '564'
            height: 30
            isfullscreen: mainwindow.isfullscreen

            skinIcon: "../images/icons/dark/appbar.clothes.shirt.png"
            skinHoverIcon: "../images/icons/light/appbar.clothes.shirt.png"
            dropdownmenuIcon: "../images/icons/dark/appbar.control.down.png"
            dropdownmenuHoverIcon: "../images/icons/light/appbar.control.down.png"
            minIcon: "../images/icons/dark/appbar.minus.png"
            minHoverIcon: "../images/icons/light/appbar.minus.png"
            maxIcon: "../images/icons/dark/appbar.fullscreen.box.png"
            maxHoverIcon: "../images/icons/light/appbar.fullscreen.box.png"
            normalIcon: "../images/icons/dark/appbar.app.png"
            normalHoverIcon: "../images/icons/light/appbar.app.png"
            closeIcon: "../images/icons/dark/appbar.close.png"
            closeHoverIcon: "../images/icons/light/appbar.close.png"

            MouseArea{
                property variant clickPos
                property bool moveflag
                anchors.fill: parent
                anchors.rightMargin: 30 * 5
                // height: 
                hoverEnabled: true
                propagateComposedEvents: true
                onPressed:{
                    moveflag = true
                    clickPos  = Qt.point(mouse.x,mouse.y)
                    // mouse.accepted = false
                }
                onReleased:{
                    moveflag = false
                }
                onPositionChanged:{
                    if(clickPos && moveflag){
                        var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
                        mainwindow.x = mainwindow.x+delta.x;
                        mainwindow.y = mainwindow.y+delta.y;
                    }
                }
                onClicked:{
                    mouse.accepted = false;
                }
                onDoubleClicked:{
                    parent.doubleClicked();
                }
            }

            onMinClicked:{
                mainwindow.showMinimized()
            }

            onMaxClicked:{
                mainwindow.showWindow();
            }

            onCloseClicked:{
                Qt.quit();
            }

            onDoubleClicked:{
                console.log('222')
                mainwindow.showWindow();
            }
        }

        HorizontalSeparator{
            id: horizontalseparator
            height: 2
            color: "lightgreen"
            anchors.top: titlebar.bottom
        }




        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_F1){
                mainwindow.showWindow();
            }
        }
        Keys.onEscapePressed:{
            mainwindow.close();
        }

        
    }
}
