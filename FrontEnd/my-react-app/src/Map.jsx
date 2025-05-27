import React, { useRef, useEffect } from 'react';
import mapboxgl from 'mapbox-gl';
import 'mapbox-gl/dist/mapbox-gl.css';

const CU_BOUNDS = [
  [ -99.20180065406191, 19.304029335693357], // southwest  [lng, lat]
  [ -99.164676862322, 19.3391027167136]  
];


const Map = () => {
  const mapContainer = useRef(null);
  const mapRef = useRef(null);
  useEffect(() => {
    mapboxgl.accessToken = "pk.eyJ1IjoiZW1pci1xbyIsImEiOiJjbWI1aW10cmgwcDRrMmxxNnd5NnNpcnV2In0.9pyOmah5IOK3DqPhSpouHA";
    const map = new mapboxgl.Map({
      container: mapContainer.current,
      style: 'mapbox://styles/mapbox/streets-v11',
      center: [-99.1835, 19.333], 
      zoom: 9,
      maxBounds:CU_BOUNDS
    });
    // map.current.fitBounds(CU_BOUNDS, {padding: 9 });  
    map.addControl(new mapboxgl.NavigationControl(), 'top-right');
    return () => map.remove();
  }, []);

  return <div ref={mapContainer} style={{ width: '100vw', height: '100vh' }} />;
};

export default Map;