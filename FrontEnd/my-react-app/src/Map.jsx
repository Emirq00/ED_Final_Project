import React, { useRef, useEffect, useState } from 'react';
import mapboxgl from 'mapbox-gl';
import 'mapbox-gl/dist/mapbox-gl.css';

const CU_BOUNDS = [
  [ -99.20180065406191, 19.304029335693357],
  [ -99.164676862322, 19.3391027167136],
];

export default function Map() {
  const mapContainer = useRef(null);
  const mapRef = useRef(null);

  const [locations, setLocations] = useState([]);
  const [origin, setOrigin] = useState(null);
  const [destination, setDestination] = useState(null);

  
  useEffect(() => {
    mapboxgl.accessToken = import.meta.env.VITE_MAPBOX_TOKEN;
    mapRef.current = new mapboxgl.Map({
      container: mapContainer.current,
      style: 'mapbox://styles/mapbox/streets-v11',
      center: [-99.1835, 19.333],
      zoom: 15,
      maxBounds: CU_BOUNDS,
    });

    return () => mapRef.current.remove();
  }, []);

  
  useEffect(() => {
    fetch('/data/locations.geojson')
      .then(res => res.json())
      .then(data => setLocations(data.features))
      .catch(console.error);
  }, []);

  
  useEffect(() => {
    if (!mapRef.current || locations.length === 0) return;

    locations.forEach(feature => {
      const [lng, lat] = feature.geometry.coordinates;
      const { name } = feature.properties;

      const el = document.createElement('div');
      el.className = 'marker';
      el.title = name;
      el.style.backgroundImage   = "url('/Location.png')";
      el.style.backgroundSize    = 'contain';
      el.style.backgroundRepeat  = 'no-repeat';
      el.style.width             = '35px';
      el.style.height            = '40px';  
      el.style.cursor            = 'pointer';
    //   el.style.transform         = 'translate(-50%, -100%)';
    // el.style.backgroundColor = 'rgba(255,0,0,0.3)';

      el.addEventListener('click', () => {
        const locObj = { name, coords: [lng, lat] };
        if (!origin) {
          setOrigin(locObj);
        } else if (!destination) {
          setDestination(locObj);
        } else {
          setOrigin(locObj);
          setDestination(null);
        }
      });

      new mapboxgl.Marker(el)
        .setLngLat([lng, lat])
        .addTo(mapRef.current);
    });
  }, [locations, origin, destination]);

  

  return (
    <>
      <div
        ref={mapContainer}
        style={{ position: 'absolute', top: 0, bottom: 0, width: '100%' }}
      />
      <div
        className="selection-panel"
        style={{
          position: 'absolute', top: 10, left: 10, zIndex: 1000,
          background: 'white', padding: '0.5rem', borderRadius: '4px', color: 'black'
        }}
      >
        <div>Origen: {origin?.name ?? '—'}</div>
        <div>Destino: {destination?.name ?? '—'}</div>
      </div>
    </>
  );
}
