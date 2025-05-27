import React, { useRef, useEffect, useState } from 'react';
import mapboxgl from 'mapbox-gl';
import 'mapbox-gl/dist/mapbox-gl.css';
import { SearchBox } from "@mapbox/search-js-react";
const CU_BOUNDS = [
  [ -99.20180065406191, 19.304029335693357],
  [ -99.164676862322, 19.3391027167136],
];

const accessToken = import.meta.env.VITE_MAPBOX_TOKEN;

export default function Map() {
  const mapContainer = useRef(null);
  const mapRef = useRef(null);
  const [mapLoaded, setMapLoaded] = useState(false);
  const [inputValue, setInputValue] = useState("");

  const [locations, setLocations] = useState([]);
  const [origin, setOrigin] = useState(null);
  const [destination, setDestination] = useState(null);

  
  useEffect(() => {
    mapboxgl.accessToken = accessToken;
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
      
      <div style={{padding:'1em'}}>
        <SearchBox
            accessToken={import.meta.env.VITE_MAPBOX_TOKEN}
            map={mapRef.current}
            mapboxgl={mapboxgl}
            value={inputValue}
            onChange={(d) => {
            setInputValue(d);
            }}
            placeholder='¿A dónde vamos?'
            marker
            theme={{
            variables: {
            unit: '16px',              // tamaño base de espaciado
            padding: '1rem',        // padding interno del input
            borderRadius: '8px',
            boxShadow: '0 2px 6px rgba(0,0,0,0.1)',
            fontFamily: 'Anonymous Pro',
            top:'50px', 
            position:''
            },
            }}
        />
      </div>
      
    </>
  );
}
