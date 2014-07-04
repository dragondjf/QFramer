import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0
//import QtWebKit 3.0
import "component"
import "affectors"
import "loading"
import "functionPages"

Rectangle{
    id: mainwindow

    property bool isfullscreen: false
    property var loadingcircles

    signal minClicked()
    signal fullscreen()
    signal maxClicked()
    signal closeClicked()

    width: Screen.desktopAvailableWidth * 0.8
    height:Screen.desktopAvailableHeight * 0.8
    gradient: Gradient {
        GradientStop {id: start; position: 0.0; color: skinbar.startcolor }
        GradientStop {id: middle; position: 0.5; color: skinbar.middlecolor }
        GradientStop {id: stop; position: 1.0; color: skinbar.stopcolor }
    }

    TitleBar{
        id: titlebar
        objectName: 'titlebar'
        title: 'QFramer'
        height: 25
        anchors.margins: 0
        isfullscreen: mainwindow.isfullscreen
        skinIsVisible: false

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

        MouseClick{
            anchors.fill: parent
            color: "transparent"
        }

        onMinClicked:{
            mainwindow.minClicked()
        }

        onMaxClicked:{
            mainwindow.isfullscreen = !mainwindow.isfullscreen;
            mainwindow.maxClicked();
            skinbar.animationEnabled = false
            skinbar.x = parent.width
        }

        onCloseClicked:{
            Qt.quit();
        }

        onDoubleClicked:{
            titlebar.maxClicked();
        }

        onSkinHovered:{
            skinbar.animationEnabled = true
            if(skinbar.x == parent.width){
                skinbar.opacity = 1
                skinbar.x = parent.width - skinbar.width
            }else{
                skinbar.x = parent.width
                skinbar.opacity = 0
            }
        }

        onDropdownmenuClicked:{
            editMenu.popup();
        }

        Rectangle{
            x: 100
            y: 100
            id: menubar
            Menu {
                id : editMenu
                MenuItem { text : "orange"  ; onTriggered: titlebar.color = text }
                MenuItem { text : "lightsteelblue" ; onTriggered: titlebar.color = text }
                MenuItem { text : "deepskyblue"  ; onTriggered: titlebar.color = text }
                MenuItem { text : "navajowhite"  ; onTriggered: titlebar.color = text }
                MenuItem { text : "lemonchiffon" ; onTriggered: titlebar.color = text }
            }
        }
        
    }

    HorizontalSeparator{
        id: horizontalseparator
        height: 0
        color: "transparent"
        anchors.top: titlebar.bottom
    }

    SkinBar{
        id: skinbar
        objectName: 'skinbar'
        parentWidth: parent.width
        width: titlebar.height * 12
        height: titlebar.height
        anchors.top: titlebar.bottom
        startcolor: "green"
        middlecolor: "yellow"
        stopcolor: "white"
        animationEnabled: false
        opacity:0
        z: 100
    }

    CenterWindow{
        id: centerwindow
        objectName: 'centerwindow'
        width: parent.width
        anchors.left: parent.left
        anchors.top: horizontalseparator.bottom
        anchors.right: parent.right
        anchors.bottom: statusbar.top
        gradient: Gradient {
            GradientStop { position: 0.0; color: skinbar.startcolor }
            GradientStop { position: 0.5; color: skinbar.middlecolor }
            GradientStop { position: 1.0; color: skinbar.stopcolor }
        }

        MouseArea {
            id: centerwindowmouseArea
            anchors.fill: parent
            hoverEnabled: true
            propagateComposedEvents: true
            onPositionChanged: {
                if(mouse.x < 200){
                    leftsidebar.opacity = 1;
                }else{
                    leftsidebar.opacity = 0;
                }
            }
        }

        // FlickView{
        //     anchors.fill: parent
        // }
        TabFunctionPages{
            id: tabs
            objectName: 'tabs'
            anchors.fill: parent
        }

        SideBar{
            id: leftsidebar
            objectName: "leftsidebar"
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left

            gradient: Gradient {
                GradientStop { position: 0.0; color: skinbar.stopcolor }
                GradientStop { position: 0.5; color: skinbar.middlecolor }
                GradientStop { position: 1.0; color: 'darkgreen' }
            }

            Text{
                text: 'leftsidebar'
                anchors.centerIn: parent
            }

            NumberAnimation on width { to: 200; duration: 1000}

            MouseClick{
                anchors.fill: parent
                color: "transparent"
            }

            Row {
                spacing: 5
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                anchors.margins: 10
                Button{
                    id: ok
                    text: 'Ok'
                    onClicked:{
                        console.log('Ok')
                    }
                }
                Button{
                    id: cancel
                    
                    text: 'Cancel'
                    onClicked:{
                        console.log('Cancel')
                        leftsidebar.toggleshow()
                    }
                }
            }

        }

        SideBar{
            id: rightsidebar
            objectName: "rightsidebar"
            function stateshow(state){
                rightsidebar.state = rightsidebar.state == "primaryAnchors"? state: "primaryAnchors"
            }

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: leftsidebar.right
            anchors.right: parent.right
            enabled: false
            gradient: Gradient {
                GradientStop { position: 0.0; color: skinbar.stopcolor }
                GradientStop { position: 0.5; color: skinbar.middlecolor }
                GradientStop { position: 1.0; color: 'darkgreen' }
            }
            state: "primary"

//            WebView {
//                id: webView
//                anchors.fill: parent
//                url:"http://www.baidu.com"
//                // canGoBack: true
//                // canGoForward: true
//                objectName: "myWebView"

//                onLoadingChanged: {
//                    console.log("onLoadingChanged: status=" + loadRequest.status);
//                    if (loadRequest.status == WebView.LoadStartedStatus)
//                        console.log("Loading started...");
//                    if (loadRequest.status == WebView.LoadFailedStatus) {
//                       console.log("Load failed! Error code: " + loadRequest.errorCode);
//                       if (loadRequest.errorCode === NetworkReply.OperationCanceledError)
//                           console.log("Load cancelled by user");
//                    }
//                    if (loadRequest.status == WebView.LoadSucceededStatus)
//                        console.log("Page loaded!");
//                }
//            }

            Row {
                spacing: 5
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                anchors.margins: 10
                Button{
                    id: rightsidebar_ok
                    text: 'Ok'
                    onClicked:{
                        console.log('Ok')
                        rightsidebar.stateshow('bottomright');
                    }
                }
                Button{
                    id: rightsidebar_cancel
                    
                    text: 'Cancel'
                    onClicked:{
                        console.log('Cancel')
                        rightsidebar.stateshow('bottomright');
                    }
                }
            }

            states: [
                State {
                    name: "primary"
                    AnchorChanges { 
                        target: rightsidebar
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: leftsidebar.right
                        anchors.right: parent.right
                    }
                },
                State {
                    name: "right"
                    AnchorChanges { target: rightsidebar; anchors.left: parent.right }
                    PropertyChanges { target: rightsidebar; opacity: 0 }
                },
                State {
                    name: "left"
                    AnchorChanges { target: rightsidebar; anchors.right: leftsidebar.right }
                    PropertyChanges { target: rightsidebar; opacity: 0 }
                },
                State {
                    name: "top"
                    AnchorChanges { target: rightsidebar; anchors.bottom: parent.top }
                    PropertyChanges { target: rightsidebar; opacity: 0 }
                },
                State {
                    name: "bottom"
                    AnchorChanges { target: rightsidebar; anchors.top: parent.bottom }
                    PropertyChanges { target: rightsidebar; opacity: 0 }
                },
                State {
                    name: "topleft"
                    AnchorChanges { target: rightsidebar; anchors.bottom: parent.top; anchors.right: leftsidebar.right }
                    PropertyChanges { target: rightsidebar; opacity: 0 }
                },
                State {
                    name: "topright"
                    AnchorChanges { target: rightsidebar; anchors.bottom: parent.top; anchors.left: parent.right }
                    PropertyChanges { target: rightsidebar; opacity: 0 }
                },
                State {
                    name: "bottomleft"
                    AnchorChanges { target: rightsidebar; anchors.top: parent.bottom; anchors.right: leftsidebar.right}
                    PropertyChanges { target: rightsidebar; opacity: 0 }
                },
                State {
                    name: "bottomright"
                    AnchorChanges { target: rightsidebar; anchors.top: parent.bottom; anchors.left: parent.right}
                    PropertyChanges { target: rightsidebar; opacity: 0 }
                }
            ]

            transitions: [
                Transition {
                    AnchorAnimation { duration: 1000 }
                },
                Transition {
                    from: "primary"; to: "*"
                    PropertyAnimation { property: "opacity"; to:0; easing.type: Easing.OutBounce; duration: 1000 }
                }
            ]
        }
    }

    StatusBar{
        id:statusbar
        objectName: "statusbar"
        height: 30
        mainwindowwidth: parent.width
        mainwindowheight: parent.height
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 0
        color: "green"
        text: "Running"
        MouseClick{
            anchors.fill: parent
            color: "transparent"
        }

        // ProgressBar {
        //     id:progressbar
        //     property int duration: 4000
        //     height: 5
        //     // anchors.fill: parent
        //     anchors.margins: 0
        //     width: parent.width
        //     anchors.left: parent.left
        //     anchors.right: parent.right
        //     anchors.bottom: parent.bottom
        //     color: 'black'

        //     NumberAnimation on value { duration: progressbar.duration; from: 0; to: 100; loops: 1 }
        // }
    }

    focus: true
    Keys.onPressed: {
        if (event.key == Qt.Key_F11){
           mainwindow.isfullscreen = !mainwindow.isfullscreen;
           mainwindow.fullscreen();
        }
        if (event.key == Qt.Key_F10){
           mainwindow.isfullscreen = !mainwindow.isfullscreen;
           mainwindow.maxClicked();
        }
        if (event.key == Qt.Key_F12){
            rightsidebar.toggleshow();
            // console.log(rightsidebar.opacity)
             rightsidebar.stateshow('primary');
        }
        else if (event.key == Qt.Key_Up && (event.modifiers&Qt.ShiftModifier)){
            rightsidebar.stateshow('top');
        }
        else if (event.key == Qt.Key_Down && (event.modifiers&Qt.ShiftModifier)){
            rightsidebar.stateshow('bottom');
        }
        else if (event.key == Qt.Key_Left && (event.modifiers&Qt.ShiftModifier)){
            rightsidebar.stateshow('left');
        }
        else if (event.key == Qt.Key_Right && (event.modifiers&Qt.ShiftModifier)){
            rightsidebar.stateshow('right');
        }
        else if (event.key == Qt.Key_Up && (event.modifiers&Qt.ControlModifier)){
            rightsidebar.stateshow('topleft');
        }
        else if (event.key == Qt.Key_Down && (event.modifiers&Qt.ControlModifier)){
            rightsidebar.stateshow('topright');
        }
        else if (event.key == Qt.Key_Left && (event.modifiers&Qt.ControlModifier)){
            rightsidebar.stateshow('bottomleft');
        }
        else if (event.key == Qt.Key_Right && (event.modifiers&Qt.ControlModifier)){
            rightsidebar.stateshow('bottomright');
        }
    }
    Keys.onDigit0Pressed:{
        console.log("2221");
        rightsidebar.toggleshow();
    }

    Keys.onEscapePressed:{
        Qt.quit();
    }
}
