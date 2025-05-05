import QtLocation 5.6
import QtPositioning 5.6
import QtQuick 2.15
import QtQuick.Controls 2.15


Rectangle {
    width: 640
    height: 480

    // Map plugin (osm in this case)
    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(36.8401, 10.2654)
        zoomLevel: 12 // Add a default zoom level

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            property bool dragging: false
            property real lastX: 0
            property real lastY: 0

            onPressed: (mouse) => {
                dragging = true
                lastX = mouse.x
                lastY = mouse.y
            }

            onPositionChanged: (mouse) => {
                if (dragging) {
                    var dx = lastX - mouse.x
                    var dy = lastY - mouse.y
                    // Update the map center to simulate panning
                    var newCenter = mapView.center
                    newCenter.latitude += dy * 0.003// Adjust for panning speed
                    newCenter.longitude -= dx * 0.003 // Adjust for panning speed
                    mapView.center = newCenter
                    lastX = mouse.x
                    lastY = mouse.y
                }
            }

            onReleased: {
                dragging = false
            }

            onWheel: (wheel) => {
                if (wheel.angleDelta.y > 0) {
                    mapView.zoomLevel += 1
                } else {
                    mapView.zoomLevel -= 1
                }
            }
        }
    }

    // Function to set center of the map programmatically
    function setCenter(lat, lng) {
        mapView.center = QtPositioning.coordinate(lat, lng)
    }
}





