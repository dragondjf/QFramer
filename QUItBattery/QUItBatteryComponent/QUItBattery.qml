import QtQuick 2.0
import QtQuick.Particles 2.0

Item {
    id: root

    // Value between 0 (0%) and 1 (100%)
    property real value: 0.5
    // Battery is being charged
    property bool charging: false
    // Setting a max rotation, 0 means non-liquid
    property real maxLiquidRotation: 50

    /* Private */
    property real __smoothedValue: value
    // True when battery is running low
    property bool __batteryLow: root.value <= 0.2
    // Battery liquid rotation
    property real __bRotation: Math.max(-maxLiquidRotation, Math.min(root.rotation+90, maxLiquidRotation))

    width: batteryImage.width
    height: batteryImage.height

    Behavior on __smoothedValue {
        SmoothedAnimation {
            velocity: 0.1
            duration: 1200
        }
    }
    Behavior on __bRotation {
        SmoothedAnimation {
            velocity: 3.0
            duration: 500
        }
    }

    Image {
        id: batteryBar
        source: "images/battery_bar.png"
        visible: false
    }

    ParticleSystem {
        id: particlesItem
        anchors.fill: batteryBar

        ImageParticle {
            source: "images/particle.png"
            rotationVariation: 180
            color:"#ffffff"
            colorVariation: 0.2
        }

        Emitter {
            width: 8
            height: parent.height
            x: 20
            emitRate: root.charging ? 20 + 50*root.value : 2 + 5*root.value
            lifeSpan: 3500
            size: 32
            sizeVariation: 24
            velocity: PointDirection{ x: 5+100*root.value; xVariation: x*0.5; yVariation: 6 }
            endSize: 8

        }
        Turbulence {
            width: parent.width
            height: parent.height
            strength: 32
        }
    }

//    ShaderEffectSource {
//        id: particlesShaderSource
//        anchors.fill: particlesItem
//        sourceItem: particlesItem
//        hideSource: true
//        visible: false
//    }

//    ShaderEffect {
//        id: shaderEffectItem
//        anchors.fill: particlesShaderSource

//        property variant source: batteryBar
//        property variant source2: particlesShaderSource
//        property real value: 0.10 + root.__smoothedValue*0.78
//        property real rot: root.__bRotation

//        fragmentShader: "
//            uniform sampler2D source;
//            uniform sampler2D source2;
//            uniform lowp float qt_Opacity;
//            varying highp vec2 qt_TexCoord0;
//            uniform highp float value;
//            uniform highp float rot;
//            void main() {
//                lowp vec4 pix = texture2D(source, qt_TexCoord0);
//                lowp vec4 pix2 = texture2D(source2, qt_TexCoord0);
//                highp float r = qt_TexCoord0.y*(rot*0.008) - 0.0042*rot + abs(rot)*(value-0.5)*0.006;
//                highp float isVis = smoothstep(qt_TexCoord0.x-0.02-r, qt_TexCoord0.x+0.02-r, value);
//                highp vec4 color = vec4(1.0 - value, value, 0.0, 1.0);
//                highp vec4 light =  color * isVis * pix;
//                gl_FragColor = (isVis * pix.a * pix2 + light) * qt_Opacity;
//            }"
//    }

    Item {
        id: clipper
        anchors.fill: parent
        anchors.leftMargin: 40
        anchors.rightMargin: 40
        clip: true

        Image {
            id: levelImage
            source: "images/bar_level2.png"
//            x: shaderEffectItem.value * root.width + (Math.abs(-root.__bRotation)*(shaderEffectItem.value-0.5)*2.9) - 75
            visible: false
        }

//        ShaderEffect {
//            id: levelImageShaderEffect
//            anchors.fill: levelImage
//            opacity: 0.5
//            transform: [
//                Rotation {
//                    origin.x: 32
//                    origin.y: 135
//                    angle: -root.__bRotation
//                }, Scale {
//                    origin.x: 32
//                    origin.y: 134
//                    yScale: 1 + root.__bRotation*root.__bRotation*0.00021
//                }
//            ]

//            property variant source: levelImage
//            property real value: shaderEffectItem.value

//            fragmentShader: "
//            uniform sampler2D source;
//            uniform lowp float qt_Opacity;
//            varying highp vec2 qt_TexCoord0;
//            uniform highp float value;
//            void main() {
//                lowp vec4 pix = texture2D(source, qt_TexCoord0);
//                highp vec4 color = vec4(1.0 - value, value, 0.2, 1.0);
//                gl_FragColor = pix * color * qt_Opacity;
//            }"
//        }
    }

    ParticleSystem {
        anchors.fill: batteryBar
        running: root.charging || !empty
        ImageParticle {
            groups: ["first", "second"]
            source: "images/lightning.png"
            rotationVariation: 20
            color:"#ffffff"
            colorVariation: 0.1
            opacity: 0.5
        }
        Emitter {
            group: "first"
            width: 8
            height: 8
            anchors.verticalCenter: parent.verticalCenter
            emitRate: 100
            lifeSpan: 1400
            lifeSpanVariation: 500
            size: 32
            sizeVariation: 16
            velocity: PointDirection{ x: 200; xVariation: x*0.5; yVariation: 30 }
            endSize: 8
            enabled: root.charging
        }
        GroupGoal {
            groups: ["first"]
//            x: shaderEffectItem.value * parent.width
            height: parent.height
            width: 100
            goalState: "second"
            jump: true
        }
        Gravity {
            groups: ["second"]
            magnitude: 200
            angle: -180
        }
    }

    Text {
        anchors.verticalCenter: parent.verticalCenter
        x: 60
        font.pixelSize: 26
        color: "#404040"
        style: Text.Outline
        styleColor: "#ffffff"
        opacity: root.charging ? 0.6 : 0
        text: "Charging"
        Behavior on opacity {
            NumberAnimation { duration: 500; easing.type: Easing.InOutQuad }
        }
    }

    Image {
        id: batteryImage
        source: "images/battery2.png"
    }

    Text {
        anchors.centerIn: parent
        y: 22
        font.pixelSize: 48
        style: Text.Outline
        color: root.__batteryLow && !root.charging ? "#802020" : "#404040"
        styleColor: "#ffffff"
        font.bold: true
        rotation: -root.rotation
        text: (root.value*100).toFixed(0) + "%"
        SequentialAnimation on opacity {
            running: root.__batteryLow && !root.charging
            loops: Animation.Infinite
            alwaysRunToEnd: true
            NumberAnimation { to: 0.5; duration: 200; easing.type: Easing.InOutQuad }
            NumberAnimation { to: 1.0; duration: 200; easing.type: Easing.InOutQuad }
        }
    }
}
