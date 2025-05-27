import React, { useRef, useEffect, useState } from 'react';
import mapboxgl from 'mapbox-gl';
import 'mapbox-gl/dist/mapbox-gl.css';

const CU_BOUNDS = [
  [ -99.20180065406191, 19.304029335693357],
  [ -99.164676862322, 19.3391027167136]  
];

 
const LOCATIONS =[
    {id:1, name:'Base Metro Universidad', coords:[-99.17484728071443, 19.32371074952203]},
    {id:2, name:'CENDI', coords:[-99.17493458652294, 19.32867177512749]},
]


export default function Map(){
  const mapContainer = useRef(null);
  const mapRef = useRef(null);

  const [origin,   setOrigin]   = useState(null);
  const [destination, setDestination] = useState(null);

  useEffect(() => {
    mapboxgl.accessToken = import.meta.env.VITE_MAPBOX_TOKEN;
    mapRef.current = new mapboxgl.Map({
      container: mapContainer.current,
      style: 'mapbox://styles/mapbox/streets-v11',
      center: [-99.1835, 19.333], 
      zoom: 9,
      maxBounds:CU_BOUNDS
    });
    // map.current.fitBounds(CU_BOUNDS, {padding: 9 });  
    // mapRef.addControl(new mapboxgl.NavigationControl(), 'top-right');


     LOCATIONS.forEach(loc => {
      const el = document.createElement('div');
      el.className = 'marker';
      el.title = loc.name;
      el.style.backgroundImage = "url('/Location.png')";
      el.style.backgroundSize ="contain";
      el.style.backgroundRepeat = 'no-repeat';
      el.style.backgroundPosition = "center";
      el.style.width  = '35px';
      el.style.height = '35px';
      el.style.cursor = 'pointer';
      el.addEventListener('click', () => {
        if (!origin) {
          setOrigin(loc);
        } else if (!destination) {
          setDestination(loc);
        } else {
          setOrigin(loc);
          setDestination(null);
        }
      });

      new mapboxgl.Marker(el)
        .setLngLat(loc.coords)
        // .setAnchor("center")
        .addTo(mapRef.current);
    });



    return () => {
        if (mapRef.current) {
            mapRef.current.remove();
        }
    };

    

    
  }, []);

  useEffect(() => {
    if (origin && destination) {
      const map = mapRef.current;

      // Si ya existía la capa, quítala
      if (map.getSource('route')) {
        map.removeLayer('route');
        map.removeSource('route');
      }

      // GeoJSON de línea
      const routeGeo = {
        type: 'Feature',
        geometry: {
          type: 'LineString',
          coordinates: [origin.coords, destination.coords]
        }
      };

      map.addSource('route', { type: 'geojson', data: routeGeo });
      map.addLayer({
        id: 'route',
        type: 'line',
        source: 'route',
        paint: {
          'line-color': '#007cbf',
          'line-width': 4
        }
      });
    }
  }, [origin, destination]);

  

   return (
    <>
      <div ref={mapContainer}
           style={{ position: 'absolute', top: 0, bottom: 0, width: '100%' }} />
      <div className="selection-panel" style={{
        position: 'absolute', top: 10, left: 10, zIndex: 1000,
        background: 'white', padding: '0.5rem', borderRadius: '4px', color:'black'
      }}>
        <div>Origen: {origin ? origin.name : '—'}</div>
        <div>Destino: {destination ? destination.name : '—'}</div>
      </div>
    </>
  );
};

