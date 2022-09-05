import QtQuick

import qml.testmodule

Window {
  width: 1000
  height: 1000
  visible: true
  title: qsTr("Hello World")

  Item {
    anchors.fill: parent
    clip: true

    ImageItem {
      id: viewPort
      anchors.fill: parent

      Component.onCompleted: {
        open("file:/Users/alez/Downloads/passport.jpg", "")
      }
    }
  }

}
