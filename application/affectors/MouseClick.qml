import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    ParticleSystem {
        id: sys
        anchors.fill: parent
        onEmptyChanged: if (empty) sys.pause();

        ImageParticle {
            system: sys
            id: cp
            source: "qrc:///particleresources/glowdot.png"
            colorVariation: 0.4
            color: "#000000FF"
        }

        Emitter {
            //burst on click
            id: bursty
            system: sys
            enabled: ma.pressed
            x: ma.mouseX
            y: ma.mouseY
            emitRate: 16000
            maximumEmitted: 4000
            acceleration: AngleDirection {angleVariation: 360; magnitude: 360; }
            size: 8
            endSize: 16
            sizeVariation: 4
        }

        MouseArea {
            anchors.fill: parent
            propagateComposedEvents: true
            onPressed: {
                sys.resume()
                mouse.accepted = true
                console.log('Particles pressed')
            }
            onClicked:{
                mouse.accepted = false
            }
            id: ma
        }
    }
}