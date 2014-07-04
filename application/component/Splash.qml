import QtQuick 2.0
import QtQuick.Window 2.1


Image {
    id: splashImage

    property int timeoutInterval: 2000
    signal timeout
    source: "../images/png/logo.png"

    Timer {
        interval: timeoutInterval; running: true; repeat: false
        onTriggered: {
            visible = false
            splashImage.timeout()
        }
    }
}