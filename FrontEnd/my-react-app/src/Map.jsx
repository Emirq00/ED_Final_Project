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
  const [inputValue, setInputValue] = useState("");
  const [locations, setLocations] = useState([]);
  const [origin, setOrigin] = useState(null);
  const [destination, setDestination] = useState(null);
  const [disabledNames, setDisabledNames] = useState([]);
  const [selectionStep, setSelectionStep] = useState('none');
  const [tempSelection, setTempSelection] = useState(null);
  const [selectedFeature, setSelectedFeature] = useState(null);

  const markersRef = useRef([]);

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

    if (origin && destination) return;

    markersRef.current.forEach(m => m.remove());
    markersRef.current = [];

    const showMarkers = selectionStep !== 'none';

    locations.forEach(feature => {
      const [lng, lat] = feature.geometry.coordinates;
      const { name } = feature.properties;
      if (disabledNames.includes(name)) return;

      const el = document.createElement('div');
      el.className = 'marker';
      Object.assign(el.style, {
        backgroundImage: "url('/Location.png')",
        backgroundSize: 'contain',
        backgroundRepeat: 'no-repeat',
        width: '35px',
        height: '40px',
        cursor: 'pointer',
        border: tempSelection?.name === name ? '2px solid #0074D9' : 'none',
      });

      el.addEventListener('click', () => {
        setTempSelection({
          name: feature.properties.name,
          key: feature.properties.key,     // 👈 agrega esto
          coords: [lng, lat],
        });
        setSelectedFeature(feature);
      });

      const marker = new mapboxgl.Marker(el).setLngLat([lng, lat]);
      markersRef.current.push(marker);
      if (showMarkers) marker.addTo(mapRef.current);
    });
  }, [locations, selectionStep, tempSelection, disabledNames, origin, destination]);

  useEffect(() => {
    if (!mapRef.current || origin == null || destination == null) return;

    markersRef.current.forEach(m => m.remove());
    markersRef.current = [];

    [origin, destination].forEach(point => {
      const el = document.createElement('div');
      el.className = 'marker';
      Object.assign(el.style, {
        backgroundImage: "url('/Location.png')",
        backgroundSize: 'contain',
        backgroundRepeat: 'no-repeat',
        width: '35px',
        height: '40px',
      });
      const marker = new mapboxgl.Marker(el).setLngLat(point.coords).addTo(mapRef.current);
      markersRef.current.push(marker);
    });
  }, [origin, destination]);

  const startSelection = () => {
    setTempSelection(null);
    setSelectedFeature(null);
    setSelectionStep('origin');
  };

  const confirmSelection = () => {
    if (!tempSelection) return;
    setDisabledNames(prev => [...prev, tempSelection.name]);

    if (selectionStep === 'origin') {
      setOrigin(tempSelection);
      setSelectionStep('destination');
    } else {
      setDestination(tempSelection);
      setSelectionStep('none');
    }
    setTempSelection(null);
    setSelectedFeature(null);
  };

const handleSend = () => {
   console.log("Estado al enviar - origin:", origin, ", destination:", destination);
  // Verifica que origen y destino estén definidos y tengan key
  if (!origin || !origin.key || !destination || !destination.key) {
    alert("Origen o destino inválido.");
    return;
  }

  const payload = {
    origen: origin.key,
    destino: destination.key,
  };

  console.log("Enviando solicitud al backend...");
  console.log("Payload:", payload);
  fetch("http://127.0.0.1:8080/ruta", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(payload),
  })
    .then(res => {
      if (!res.ok) {
        return res.text().then(text => {
          alert("Error del servidor: " + text);
          throw new Error(text);
        });
      }
      
      return res.json();
      
    })
    .then((data) => {
      console.log("Respuesta del backend:", data);
      alert("Ruta calculada:\n" + JSON.stringify(data, null, 2));
    })
    .catch((err) => {
      console.error("Error de conexión:", err);
      alert("No se pudo conectar al backend.");
    });
};

  let mainText = 'Iniciar viaje';
  let mainDisabled = false;
  let mainOpacity = 1;
  if (selectionStep === 'origin') {
    mainText = 'Selecciona tu punto de partida';
    mainDisabled = true;
    mainOpacity = 0.5;
  } else if (selectionStep === 'destination') {
    mainText = 'Selecciona tu punto de destino';
    mainDisabled = true;
    mainOpacity = 0.5;
  } else if (origin && destination) {
    mainText = 'Confirma tu ruta';
    mainDisabled = true;
    mainOpacity = 0.5;
  }
  const handleMainClick = () => {
    if (selectionStep === 'none' && !origin && !destination) startSelection();
    else if (origin && destination) handleSend();
  };

  return (
    <>
      <div ref={mapContainer} style={{ position: 'absolute', top: 0, bottom: 0, width: '100%' }} />
      <div style={{ position: 'relative', zIndex: 1000, display: 'flex', justifyContent: 'space-around', padding: '1em' }}>
        <div style={{ position:'relative', display:'flex' }}>
          <SearchBox
            accessToken={accessToken}
            map={mapRef.current}
            mapboxgl={mapboxgl}
            value={inputValue}
            onChange={setInputValue}
            placeholder='¿A dónde vamos?'
            marker
            theme={{ variables: { unit: '16px', padding: '1rem', borderRadius: '8px', boxShadow: '0 2px 6px rgba(0,0,0,0.1)', fontFamily: 'Anonymous Pro', top:'50px' } }}
          />
        </div>
        <div style={{ position:'relative', display:'flex', paddingLeft:'1.5rem' }}>
          <button
            onClick={handleMainClick}
            disabled={mainDisabled}
            style={{
              padding: '0.5rem 1rem',
              fontSize: '1.2rem',
              backgroundColor: 'white',
              color: '#000000',
              border: 'none',
              borderRadius: '4px',
              cursor: mainDisabled ? 'not-allowed' : 'pointer',
              opacity: mainOpacity,
              fontFamily: 'Anonymous Pro',
            }}
          >{mainText}</button>
        </div>
      </div>

      {(origin || destination ) && (
        <div style={{ position: 'fixed', top: 80, right: 20, background: 'rgba(255,255,255,0.9)', padding: '1rem', borderRadius: '8px', zIndex: 1000 }}>
          <p style={{color:'black'}}><strong style={{color:'black'}}>Origen:</strong> {origin?.name || '—'}</p>
          <p style={{color:'black'}}><strong style={{color:'black'}}>Destino:</strong> {destination?.name || '—'}</p>
        </div>
      )}
      <div style={{ position: 'fixed', bottom: '3%', display: 'flex', gap: '1rem', zIndex: 1000, padding:'1rem' }}>
        {(selectionStep === 'origin' || selectionStep === 'destination') && (
          <>
            <button
              disabled={!tempSelection}
              onClick={confirmSelection}
              style={{ padding: '0.5rem 1rem', fontSize: '1rem', backgroundColor: tempSelection ? '#002B7A' : '#ccc', color: tempSelection ? '#D59F0F':'white', border: 'none', borderRadius: '4px', cursor: tempSelection ? 'pointer' : 'not-allowed', fontWeight:'bold' }}
            >Seleccionar</button>
            <button
              onClick={() => { setOrigin(null); setDestination(null); setSelectionStep('none'); setTempSelection(null); setDisabledNames([]); setSelectedFeature(null); }}
              style={{ padding: '0.5rem 1rem', fontSize: '1rem', backgroundColor: '#FF4136', color: 'white', border: 'none', borderRadius: '10%', cursor: 'pointer', fontWeight:'bold' }}
            >Cancelar</button>
          </>
        )}

        {origin && destination && selectionStep === 'none' && (
          <>
            <button
              onClick={handleSend}
              style={{ padding: '0.75rem 1.5rem', fontSize: '1rem', backgroundColor: '#002B7A', color: '#D59F0F', border: 'none', borderRadius: '4px', cursor: 'pointer', fontWeight:'bold' }}
            >Confirmar ruta</button>
            <button
              onClick={() => { setOrigin(null); setDestination(null); setSelectionStep('none'); setTempSelection(null); setDisabledNames([]); setSelectedFeature(null); }}
              style={{ padding: '0.5rem 1rem', fontSize: '1rem', backgroundColor: '#FF4136', color: 'white', border: 'none', borderRadius: '4px', cursor: 'pointer', fontWeight:'bold' }}
            >Cancelar</button>
          </>
        )}
      </div>

    
      <div
        style={{
          position: 'fixed',
          bottom: '15%',
          left: 0,
          right: '40%',
          height: '75%',
          width:'clamp(13rem, 17rem, 20rem)',
          backgroundColor: 'white',
          borderTopLeftRadius: '12px',
          borderTopRightRadius: '12px',
          boxShadow: '0 -2px 6px rgba(0,0,0,0.2)',
          transform: selectedFeature ? 'translateX(5%)' : 'translateX(-100%)',
          transition: 'transform 0.5s ease-in-out',
          zIndex: 1001,
          padding: '1rem',
          overflowX: 'auto',
        }}
      >
        {selectedFeature && (
          <>
            <button
              onClick={() => { setSelectedFeature(null); setTempSelection(null); }}
              style={{ position: 'absolute', top: 8, right: 12, background: 'transparent', border: 'none', fontSize: '2rem', cursor: 'pointer', color:'black' }}
            >×</button>
            <h3 style={{ margin: 0, fontSize: '1.25rem', fontWeight: 'bold', color:'black', padding:'1em'}}>{selectedFeature.properties.name}</h3>
            <p style={{ margin: '0.5rem 0', color: '#555' }}>{selectedFeature.properties.description}</p>
            {selectedFeature.properties.photo && (
              <img
                src={selectedFeature.properties.photo}
                alt={selectedFeature.properties.name}
                style={{ width: '100%', height: '120px', objectFit: 'cover', borderRadius: '8px' }}
              />
            )}
            {selectedFeature.properties.routes && (
              <>
                <p style={{ margin: '0.75rem 0 0.25rem 0', fontWeight: 'bold', color:'black' }}>Rutas:</p>
                <ul style={{ margin: 0, paddingLeft: '1.25rem', color: '#555' }}>
                  {selectedFeature.properties.routes.map((r, i) => (
                    <li key={i}>{r}</li>
                  ))}
                </ul>
              </>
            )}
          </>
        )}
      </div>
    </>
  );
}
