import QtLocation 5.6
import QtQuick 2.15

MapQuickItem {
    id: marker
    anchorPoint.x: circle.width/2  // Utilisez circle au lieu de image
    anchorPoint.y: circle.height   // Utilisez circle au lieu de image

    property alias color: circle.color

    sourceItem: Rectangle {
        id: circle
        width: 20
        height: 20
        radius: 10
        color: "red"
        border.width: 2
        border.color: "white"

        // Optionnel : Ajouter un texte pour l'ID
        Text {
            anchors.centerIn: parent
            text: "Tunisia Mall"
            color: "white"
            font.bold: true
        }
    }
}
