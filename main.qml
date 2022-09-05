import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick
import qml.testmodule

Window {
  width: 1000
  height: 1000
  visible: true
  title: qsTr("Hello World")

  Button {
    text: "Open"
    onClicked: {
     fileDialog.open()
    }
  }

  FileDialog {
    id: fileDialog
    fileMode: FileDialog.OpenFiles;
    onAccepted: {
      console.log("You choose: " + selectedFiles[0].toString().replace("file:///", ""));
      viewPort.open(selectedFiles[0].toString().replace("file:///", ""))
    }
  }

  Item {
    anchors.fill: parent

    clip: true

    ImageItem {
      id: viewPort
       anchors.fill: parent
     // width: 100
      //height: 100
    }
  }
}
