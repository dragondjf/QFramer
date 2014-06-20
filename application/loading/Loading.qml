import QtQuick 2.0

Rectangle {
    id: loading
    property int pwidth: 10
    property bool success: false

    x: 0
    width: 5
    height: 5
    radius: 5
    color: "green"

    Behavior on x {
        NumberAnimation {
            id: numAnimation
            loops: 10
            from: 0
            // to: parent.pwidth
            easing.type:Easing.OutInCirc
            duration: 3000 
            onRunningChanged: {
                if (!running) {
                    loading.destroy();
                }else{
                    if(parent.pwidth != undefined){
                        numAnimation.to = parent.pwidth
                    }
                }
            }
        }
    }
}
