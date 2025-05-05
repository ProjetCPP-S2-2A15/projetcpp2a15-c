// Initialiser la carte centrée sur Tunis
var map = L.map('map').setView([36.81, 10.17], 13);

// Ajouter la couche OpenStreetMap
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19
}).addTo(map);

// Fonction accessible depuis Qt pour ajouter un marqueur
function addMarker(lat, lng) {
    L.marker([lat, lng]).addTo(map).bindPopup("Voici le Mall !").openPopup();
}
