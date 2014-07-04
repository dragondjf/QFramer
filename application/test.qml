import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.0

GridLayout {
    columns: 4
    property int index: -1
    rowSpacing: 5
    columnSpacing: 5
    Label {
        Layout.rowSpan: 2
        text: "Stack Index: " + index
    }
    Button {
        text: "Push New Component"
        onClicked: stackView.push(componentPage)
    }
    Button {
        text: "Push New URL"
        onClicked: stackView.push(Qt.resolvedUrl("View.qml"))
    }
    Button {
        text: "Back"
        enabled: index !== 0
        onClicked: stackView.pop()
    }

    RowLayout {
        Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
        Layout.columnSpan: 3
        spacing: 5
        Label { text: "Jump to index:" }
        ComboBox {
            model: stackView.depth
            currentIndex: stackView.currentItem.Stack.index
            enabled: stackView.depth > 1
            onCurrentIndexChanged: {
                if (stackView.currentItem !== null &&
                        currentIndex !== stackView.currentItem.Stack.index)
                    stackView.pop(stackView.get(currentIndex, true))
            }
        }
    }
}