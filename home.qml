import QtQuick 2.0

Rectangle {

    gradient: Gradient {
        GradientStop {id: start; position: 0.0; color: "green" }
        GradientStop {id: middle; position: 0.5; color: "yellow" }
        GradientStop {id: stop; position: 1.0; color: "white" }
    }

    MouseClick{
        anchors.fill: parent
        color: "transparent"
    }
}
