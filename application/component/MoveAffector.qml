
import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    ParticleSystem {
        anchors.fill: parent
        ImageParticle {
            groups: ["B"]
            anchors.fill: parent
            source: "qrc:///particleresources/star.png"
            color:"#10FF10"
            greenVariation: 0.8
        }

        Emitter {
            group: "B"
            emitRate: 10
            lifeSpan: 5000
            size: 64
            sizeVariation: 8
            // velocity: PointDirection{ x: 0; y: 0 }
            // y: 0
            // width: 10
            // height: 10
        }

        //! [B]
        Affector {
            groups: ["B"]
            // x: 10
            // y: 0
            width: 200
            height: 200
            once: true
            velocity: AngleDirection { angleVariation:180; magnitude: 180 }
        }
    }
}
