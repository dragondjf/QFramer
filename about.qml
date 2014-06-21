import QtQuick 2.0

Rectangle {
    width: 100
    height: 62

    gradient: Gradient {
        GradientStop {id: start; position: 0.0; color: "green" }
        GradientStop {id: middle; position: 0.5; color: "yellow" }
        GradientStop {id: stop; position: 1.0; color: "white" }
    }
    Column {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("QFramer")
            font.pointSize: 30
            font.weight: Font.Light
            color: "green"
        }

        Image {
            id: icon
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "/skin/images/logo.png"
        }



        Text {
            clip: true
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("A faster and easier frame based on Qt5.3")
            font.pointSize: 16
            font.weight: Font.Light
            color: "green"
        }

        Text {
            clip: true
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("QFramer project are released under the terms of the GPLv3 license")
            font.pointSize: 12
            font.weight: Font.Light
            color: "green"
        }

        Text {
            clip: true
            baseUrl: "https://github.com/dragondjf/QCFramer"
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Github: <a>https://github.com/dragondjf/QCFramer</a>")
            font.pointSize: 12
            font.weight: Font.Light
            color: "green"
        }
        Text {
            clip: true
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Email: ding465398889@163.com")
            font.pointSize: 12
            font.weight: Font.Light
            color: "green"
        }
        Text {
            clip: true
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("QQ: 465398889")
            font.pointSize: 12
            font.weight: Font.Light
            color: "green"
        }

        Image {
            id: sialan_logo
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "/skin/images/QFramer.png"
        }
    }

    Text {
        clip: true
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 8
        font.pointSize: 12
        color: "green"
        text: "version 0.1.0.0"
    }
}
