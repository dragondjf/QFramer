/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0

Item {
    id: tabWidget

    // Setting the default property to stack.children means any child items
    // of the TabWidget are actually added to the 'stack' item's children.
    // See the "Property Binding"
    // documentation for details on default properties.
    default property alias content: stack.children

    property int current: 0
    property color gcolor

    onCurrentChanged: setOpacities()
    Component.onCompleted: setOpacities()

    function setOpacities() {
        for (var i = 0; i < stack.children.length; ++i) {
            stack.children[i].opacity = (i == current ? 1 : 0)
        }
    }

    Row {
        id: headerTabs
        objectName: "headerTabs"
        anchors.horizontalCenter: parent.horizontalCenter
        // anchors.left: parent.left
        // anchors.leftMargin: 10
        Repeater {
            model: stack.children.length
            delegate: Rectangle {
                id: tab
                width: icon.sourceSize.width; height: icon.sourceSize.height

                border.color: 'white'
                border.width: 0
                gradient: Gradient {
                            GradientStop { position: 0.0; color: tabWidget.gcolor }
                            GradientStop { position: 0.5; color: 'yellow' }
                            GradientStop { position: 1.0; color: tabWidget.gcolor }
                        }
                // Rectangle {
                //     height: parent.height
                //     width: 1
                //     anchors { right: parent.right; rightMargin: 1 ; leftMargin: 1}
                //     color: "black"
                // }
                BorderImage {
                    id: icon
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    source: stack.children[index].icon
                    // visible: tabWidget.current == index
                }
                Text {
                    id: text
                    horizontalAlignment: Qt.AlignHCenter; verticalAlignment: Qt.AlignVCenter
                    // anchors.top: icon.bottom
                    anchors.bottom: tab.bottom
                    anchors.bottomMargin: 5
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: stack.children[index].title
                    elide: Text.ElideRight
                    font.bold: tabWidget.current == index
                    color: "white"
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    hoverEnabled: true
                    onEntered: {
                        parent.border.width = 1
                    }
                    onExited: {
                        parent.border.width = 0
                    }
                    onWheel: {}
                    onPressed:{
                        parent.border.color = "black"
                    }
                    onReleased:{
                        parent.border.color = "white"
                    }
                    onClicked: {
                        onClicked: tabWidget.current = index
                    }
                }
            }
        }
    }

    Item {
        id: stack
        objectName: 'stackView'
        width: tabWidget.width
        anchors.top: headerTabs.bottom; anchors.bottom: tabWidget.bottom
    }
}
