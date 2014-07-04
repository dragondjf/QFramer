import QtQuick 2.0

Flipable {
    id: button

    property string text: '545454'
    property string color
    property int rotationX: 1
    property int rotationY: 0
    property int rotationZ: 0
    signal clicked(int x, int y)

    width: 60
    height: 40
    state: "font"

    front: Rectangle{
        anchors.fill: parent
        color: button.color
        gradient: Gradient {
            GradientStop { position: 0.0; color: 'white' }
            GradientStop { position: 0.5; color: button.color }
            GradientStop { position: 1.0; color: 'white' }
        }
        Text{
            text: button.text
            anchors.centerIn: parent
            font: { font.pointSize=10; font.weight=Font.Bold}
            color: 'white'
        }
    }
    back: Rectangle{
        anchors.fill: parent
        // color: mousearea.pressed? 'darkgreen': 'green'
        color: button.color
        gradient: Gradient {
            GradientStop { position: 0.0; color: 'white' }
            GradientStop { position: 0.5; color: button.color }
            GradientStop { position: 1.0; color: 'white' }
        }

        Text{
            text: button.text
            anchors.centerIn: parent
            color: "white"
            font: { font.pointSize=10; font.weight=Font.Bold}
        }
    }

    MouseArea {
        id: mousearea
        anchors.fill: parent
        hoverEnabled: true
        propagateComposedEvents: true
        onEntered: {
            parent.state = 'back'
            // parent.front.color = 'darkgreen'
            // parent.back.color = 'darkgreen'

        }
        onExited: {
            parent.state = 'font'
            // parent.front.color = 'green'
            // parent.back.color = 'green'
        }

        onPressed:{
            // parent.front.color = 'lightgreen'
            // parent.back.color = 'lightgreen'
        }

        onClicked:{
            button.clicked(mouse.mouseX, mouse.mouseY);
            mouse.accepted = true
        }
    }

    transform: Rotation {
        id: rotation
        origin.x: button.width/2
        origin.y: button.height/2
        axis.x: 1 - button.rotationY - button.rotationZ; 
        axis.y: 1 - button.rotationX - button.rotationZ; 
        axis.z: 1 - button.rotationX - button.rotationY;      // set axis.y to 1 to rotate around y-axis
        angle: 0    // the default angle
    }

    states: [
        State {
            name: "font"
            PropertyChanges { target: rotation; angle: 0 }
        },
        State {
            name: "back"
            PropertyChanges { target: rotation; angle: 180 }
        }
    ]

    transitions: Transition {
        SmoothedAnimation { target: rotation; property: "angle";  velocity: 800 }
    }
}
