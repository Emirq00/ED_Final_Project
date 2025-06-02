import React, { useRef, useEffect, useState } from 'react';
import mapboxgl from 'mapbox-gl';
import 'mapbox-gl/dist/mapbox-gl.css';
import { SearchBox } from "@mapbox/search-js-react";

const CU_BOUNDS = [
  [-99.20180065406191, 19.304029335693357],
  [-99.164676862322, 19.3391027167136],
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
  const stepMarkersRef = useRef([]);

  const [isImageOpen, setIsImageOpen] = useState(false);

  const [estacionesCoords, setEstacionesCoords] = useState({});
  const [estacionesNames, setEstacionesNames] = useState({});

  const [routeGeometry, setRouteGeometry] = useState(null);
  const [routeSteps, setRouteSteps] = useState(null);
  const [routeDistance, setRouteDistance] = useState(null);
  const [routeDuration, setRouteDuration] = useState(null);
  const [selectedStepIndex, setSelectedStepIndex] = useState(null);

  // Función para asignar color según número de ruta
  const getRouteColor = (routeNum) => {
    switch (routeNum) {
      case 1: return "#3dc55e";    // ruta 1
      case 2: return "#f1e01f";    // ruta 2
      case 3: return "#07680a";    // ruta 3
      case 4: return "#583404";    // ruta 4
      case 5: return "#23bae6";    // ruta 5
      case 6: return "#c80000";    // ruta 6
      case 7: return "#ffaf2c";    // ruta 7
      case 8: return "#020e86";    // ruta 8
      case 9: return "#8d3ca7";    // ruta 9
      case 10: return "#161617";   // ruta 10
      case 11: return "#57109d";   // ruta 11
      case 12: return "#c8a6cc";   // ruta 12
      case 13: return "#c5eaec";   // ruta 13
      default: return "#7f8c8d";   // gris por defecto
    }
  };

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
      .then((data) => {
        setLocations(data.features);

        const coordsDict = {};
        const namesDict = {};
        data.features.forEach((feature) => {
          const key          = feature.properties.key;
          const coords       = feature.geometry.coordinates;
          const nombreBonito = feature.properties.name;
          coordsDict[key] = coords;
          namesDict[key]  = nombreBonito;
        });
        setEstacionesCoords(coordsDict);
        setEstacionesNames(namesDict);
      })
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
      const { name }   = feature.properties;
      if (disabledNames.includes(name)) return;

      const el = document.createElement('div');
      el.className = 'marker';
      Object.assign(el.style, {
        backgroundImage: "url('/Location.png')",
        backgroundSize:   'contain',
        backgroundRepeat: 'no-repeat',
        width:  '35px',
        height: '40px',
        cursor: 'pointer',
        border: tempSelection?.name === name ? '2px solid #0074D9' : 'none',
      });

      el.addEventListener('click', () => {
        setTempSelection({
          name: feature.properties.name,
          key:  feature.properties.key,
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
        backgroundSize:   'contain',
        backgroundRepeat: 'no-repeat',
        width:  '35px',
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

  
  async function fetchRouteGeometry(waypoints) {
    if (!waypoints || waypoints.length < 2) {
      throw new Error("Se requieren al menos 2 puntos para calcular la ruta");
    }
    const coordsString = waypoints.map(c => c.join(",")).join(";");
    const url =
      `https://api.mapbox.com/directions/v5/mapbox/driving/${coordsString}` +
      `?geometries=geojson&overview=full&access_token=${accessToken}`;

    const res = await fetch(url);
    if (!res.ok) {
      throw new Error("Error al obtener geometría de Mapbox Directions");
    }
    const json = await res.json();
    if (!json.routes || json.routes.length === 0) {
      throw new Error("Mapbox Directions no devolvió rutas");
    }
    return json.routes[0]; // retorna objeto con geometry, distance (en metros) y duration (en segundos)
  }

  const finalizeRoute = () => {
    const map = mapRef.current;
    if (map.getLayer("routeLine"))  map.removeLayer("routeLine");
    if (map.getSource("routeLine")) map.removeSource("routeLine");
    stepMarkersRef.current.forEach(m => m.remove());
    stepMarkersRef.current = [];

    setRouteSteps(null);
    setRouteGeometry(null);
    setRouteDistance(null);
    setRouteDuration(null);
    setSelectedStepIndex(null);

    setOrigin(null);
    setDestination(null);
    setSelectionStep('none');
    setTempSelection(null);
    setDisabledNames([]);
    setSelectedFeature(null);
  };

  const handleSendOrFinalize = () => {
    const isRouteActive = Boolean(routeSteps);
    if (isRouteActive) {
      finalizeRoute();
    } else {
      if (!origin || !origin.key || !destination || !destination.key) {
        alert("Origen o destino inválido.");
        return;
      }
      const payload = { origen: origin.key, destino: destination.key };
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
      .then(async data => {
        setRouteSteps(data.ruta);
        const coordsWaypoints = data.ruta.map(step => estacionesCoords[step.estacion]);
        try {
          const routeObj = await fetchRouteGeometry(coordsWaypoints);
          setRouteGeometry(routeObj.geometry);
          setRouteDistance(routeObj.distance);   // en metros
          setRouteDuration(routeObj.duration);   // en segundos
        } catch (err) {
          console.error(err);
          alert(err.message);
        }
      })
      .catch(err => {
        console.error("Error de conexión:", err);
        alert("No se pudo conectar al backend.");
      });
    }
  };

  const isRouteActive = Boolean(routeSteps);
  let mainText = isRouteActive ? 'Finalizar' : 'Iniciar viaje';
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
  } else if (!isRouteActive && origin && destination) {
    mainText = 'Confirmar ruta';
    mainDisabled = false;
    mainOpacity = 1;
  } else if (isRouteActive) {
    mainText = 'Finalizar';
    mainDisabled = false;
    mainOpacity = 1;
  }
  const handleMainClick = () => {
    if (!isRouteActive && !origin && !destination) startSelection();
    else handleSendOrFinalize();
  };

  useEffect(() => {
    const map = mapRef.current;
    if (!map || !routeGeometry || !routeSteps) return;

    if (map.getLayer("routeLine"))  map.removeLayer("routeLine");
    if (map.getSource("routeLine")) map.removeSource("routeLine");

    map.addSource("routeLine", {
      type: "geojson",
      data: {
        type: "Feature",
        properties: {},
        geometry: routeGeometry,
      },
    });

    map.addLayer({
      id: "routeLine",
      type: "line",
      source: "routeLine",
      layout: {
        "line-join": "round",
        "line-cap": "round",
      },
      paint: {
        "line-color": "#0074D9",
        "line-width": 4,
      },
    });

    stepMarkersRef.current.forEach(m => m.remove());
    stepMarkersRef.current = [];

    routeSteps.forEach((step, index) => {
      const key = step.estacion;
      const coords = estacionesCoords[key];
      if (!coords) return;
      const el = document.createElement('div');
      el.className = 'marker';

      if (index === selectedStepIndex) {
        Object.assign(el.style, {
          backgroundColor: "#FFD700",
          borderRadius: "50%",
          width: "18px",
          height: "18px",
          border: "3px solid #0074D9",
          cursor: "pointer",
        });
      } else {
        Object.assign(el.style, {
          backgroundColor: "#FF4136",
          borderRadius: "50%",
          width: "12px",
          height: "12px",
          border: "2px solid white",
          cursor: "pointer",
        });
      }

      el.title = `${index + 1}. ${estacionesNames[key] || key}`;
      el.addEventListener('click', () => {
        setSelectedStepIndex(index);
        map.flyTo({ center: coords, zoom: 16 });
      });

      const marker = new mapboxgl.Marker(el)
        .setLngLat(coords)
        .addTo(map);
      stepMarkersRef.current.push(marker);
    });

    if (selectedStepIndex === null) {
      const coords = routeGeometry.coordinates;
      const lats   = coords.map(c => c[1]);
      const lngs   = coords.map(c => c[0]);
      const minLng = Math.min(...lngs), maxLng = Math.max(...lngs);
      const minLat = Math.min(...lats), maxLat = Math.max(...lats);

      map.fitBounds(
        [
          [minLng, minLat],
          [maxLng, maxLat],
        ],
        { padding: 40 }
      );
    }
  }, [routeGeometry, routeSteps, estacionesCoords, selectedStepIndex]);

  const formatDistance = (meters) => {
    if (meters == null) return '--';
    const km = meters / 1000;
    return `${km.toFixed(2)} km`;
  };

  const formatDuration = (seconds) => {
    if (seconds == null) return '--';
    const hrs = Math.floor(seconds / 3600);
    const mins = Math.ceil((seconds % 3600) / 60);
    if (hrs > 0) {
      return `${hrs}h ${mins} m`;
    }
    return `${mins}m`;
  };

  return (
    <>
      <div ref={mapContainer} style={{ position: 'absolute', top: 0, bottom: 0, width: '100%' }} />

      <div style={{ position: 'relative', zIndex: 1000, display: 'flex', justifyContent: 'space-around', padding: '1em' }}>
        <div style={{ position: 'relative', display: 'flex' }}>
          <SearchBox
            accessToken={accessToken}
            map={mapRef.current}
            mapboxgl={mapboxgl}
            value={inputValue}
            onChange={setInputValue}
            placeholder='¿A dónde vamos?'
            marker
            theme={{
              variables: {
                unit: '16px',
                padding: '1rem',
                borderRadius: '8px',
                boxShadow: '0 2px 6px rgba(0,0,0,0.1)',
                fontFamily: 'Anonymous Pro',
                top: '50px'
              }
            }}
          />
        </div>
        <div style={{ position: 'relative', display: 'flex', paddingLeft: '1.5rem' }}>
          <button
            onClick={handleMainClick}
            disabled={mainDisabled}
            style={{
              padding: '0.5rem 1rem',
              fontSize: '1rem',
              backgroundColor: '#002B7A',
              color: '#D59F0F',
              fontWeight:'bold',

              border: 'none',
              borderRadius: '4px',
              cursor: mainDisabled ? 'not-allowed' : 'pointer',
              opacity: mainOpacity,
            }}
          >{mainText}</button>
        </div>
      </div>

      {(origin || destination) && (
        <div style={{
          position: 'fixed',
          top: 80,
          right: 20,
          background: 'rgba(255,255,255,0.9)',
          padding: '1rem',
          borderRadius: '8px',
          zIndex: 1000
        }}>
          <p style={{ color: '#002B7A', fontWeight:'500' }}>
            <strong style={{ color: '#D59F0F' }}>Origen:</strong> {origin?.name || '—'}
          </p>
          <p style={{ color: '#002B7A', fontWeight:'500'}}>
            <strong style={{ color: '#D59F0F' }}>Destino:</strong> {destination?.name || '—'}
          </p>
        </div>
      )}

      <div style={{
        position: 'fixed',
        bottom: '3%',
        display: 'flex',
        gap: '1rem',
        zIndex: 1000,
        padding: '1rem'
      }}>
        {(selectionStep === 'origin' || selectionStep === 'destination') && (
          <>
            <button
              disabled={!tempSelection}
              onClick={confirmSelection}
              style={{
                padding: '0.5rem 1rem',
                fontSize: '1rem',
                backgroundColor: tempSelection ? '#002B7A' : '#ccc',
                color: tempSelection ? '#D59F0F' : 'white',
                border: 'none',
                borderRadius: '4px',
                cursor: tempSelection ? 'pointer' : 'not-allowed',
                fontWeight: 'bold'
              }}
            >Seleccionar</button>
            <button
              onClick={() => {
                setOrigin(null);
                setDestination(null);
                setSelectionStep('none');
                setTempSelection(null);
                setDisabledNames([]);
                setSelectedFeature(null);
              }}
              style={{
                padding: '0.5rem 1rem',
                fontSize: '1rem',
                backgroundColor: '#FF4136',
                color: 'white',
                border: 'none',
                borderRadius: '4px',
                cursor: 'pointer',
                fontWeight: 'bold'
              }}
            >Cancelar</button>
          </>
        )}

        {origin && destination && selectionStep === 'none' && (
          <>
            <button
              onClick={handleMainClick}
              style={{
                padding: '0.75rem 1.5rem',
                fontSize: '1rem',
                backgroundColor: '#002B7A',
                color: '#D59F0F',
                border: 'none',
                borderRadius: '4px',
                cursor: 'pointer',
                fontWeight: 'bold'
              }}
            >{isRouteActive ? 'Finalizar' : 'Confirmar ruta'}</button>
            <button
              onClick={() => {
                setOrigin(null);
                setDestination(null);
                setSelectionStep('none');
                setTempSelection(null);
                setDisabledNames([]);
                setSelectedFeature(null);
                finalizeRoute();
              }}
              style={{
                padding: '0.5rem 1rem',
                fontSize: '1rem',
                backgroundColor: '#FF4136',
                color: 'white',
                border: 'none',
                borderRadius: '4px',
                cursor: 'pointer',
                fontWeight: 'bold'
              }}
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
          width: 'clamp(13rem, 17rem, 20rem)',
          backgroundColor: 'white',
          borderTopLeftRadius: '12px',
          borderTopRightRadius: '12px',
          boxShadow: '0 -2px 6px rgba(0,0,0,0.2)',
          transform: (routeSteps || selectedFeature)
            ? 'translateX(5%)'
            : 'translateX(-100%)',
          transition: 'transform 0.5s ease-in-out',
          zIndex: 1001,
          padding: '1rem',
          overflowY: 'auto',
        }}
      >
        {routeSteps ? (
          <>
            
            <div style={{
              marginBottom: '1rem',
              padding: '0.5rem',
              backgroundColor: '#f5f5f5',
              borderRadius: '6px',
              display: 'flex',
              justifyContent: 'space-between',
              alignItems: 'center',
            }}>
              <div style={{display:'flex', flexDirection:'column'}}>
                <div style={{padding:'auto', paddingBottom:'1em', display:'flex'}}>
                  <strong style={{ color: '#D59F0F'  }}>Distancia recorrida:</strong>
                  <span style={{ marginLeft: '0.2rem', color: '#002B7A', fontWeight:'500'}}>
                    {formatDistance(routeDistance)}
                  </span>
                </div>
                <div style={{display:'flex'}}>
                  <strong style={{ color: '#D59F0F' }}>Tiempo estimado:</strong>
                  <span style={{ marginLeft: '0.2rem', color: '#002B7A', fontWeight:'500' }}>
                    {formatDuration(routeDuration)}
                  </span>
                </div>
              </div>
              
            </div>
            

            <h3 style={{ margin: '0 0 1rem 0', fontSize: '1.25rem', fontWeight: 'bold', color: '#D59F0F' }}>
              Ruta óptima
            </h3>
            <ul style={{ listStyle: 'none', margin: 0, padding: 0 }}>
              {routeSteps.map((step, idx) => {
                const key           = step.estacion;
                const nombreLegible = estacionesNames[key] || key;
                const coords        = estacionesCoords[key];
                const isSelected    = idx === selectedStepIndex;
                return (
                  <li
                    key={key}
                    onClick={() => {
                      if (!coords) return;
                      setSelectedStepIndex(idx);
                      mapRef.current.flyTo({ center: coords, zoom: 16 });
                    }}
                    style={{
                      padding: '0.5rem 0',
                      borderBottom: '1px solid #ddd',
                      cursor: 'pointer',
                      backgroundColor: isSelected ? '#e0f7fa' : 'transparent',
                      fontWeight:     isSelected ? 'bold' : '500',
                      color: '#002B7A'
                    }}
                  >
                    {`${idx + 1}. ${nombreLegible}`}
                  </li>
                );
              })}
            </ul>
          </>
        ) : selectedFeature ? (
          <>
            <button
              onClick={() => { setSelectedFeature(null); setTempSelection(null); }}
              style={{
                position: 'absolute',
                top: 8,
                right: 12,
                background: 'transparent',
                border: 'none',
                fontSize: '2rem',
                cursor: 'pointer',
                color: 'black'
              }}
            >×</button>
            <h3 style={{
              margin: 0,
              fontSize: '1.25rem',
              fontWeight: 'bold',
              color: '#D59F0F',
              padding: '1em'
            }}>
              {selectedFeature.properties.name}
            </h3>
            
            {selectedFeature.properties.photo && (
              <img
                src={selectedFeature.properties.photo}
                alt={selectedFeature.properties.name}
                style={{
                  width: '100%',
                  height: '120px',
                  objectFit: 'cover',
                  borderRadius: '8px',
                  border:'2px solid #D59F0F',
                  zIndex:'10000',
                  cursor:'pointer'
                }}
                onClick={() => setIsImageOpen(true)}
              />
            )}

            
            <div style={{
              position: 'absolute',
              bottom: '1rem',
              left: '1rem',
              right: '1rem',
              display: 'flex',
              flexDirection: 'column',
              alignItems: 'center',
            }}>
              <span style={{ fontWeight: 'bold', marginBottom: '0.5rem', color: '#D59F0F' }}>
                Rutas de PumaBus:
              </span>
              <div style={{
                display: 'flex',
                flexWrap: 'wrap',
                gap: '0.5rem',
                justifyContent: 'center',
              }}>
                {Array.isArray(selectedFeature.properties.routes) && selectedFeature.properties.routes.length > 0 ? (
                  selectedFeature.properties.routes.map((r) => (
                    <span
                      key={r}
                      style={{
                        backgroundColor: getRouteColor(r),
                        color: 'white',
                        fontWeight: 'bold',
                        fontSize: '0.85rem',
                        width: '2.30em',
                        height: '2rem',
                        display: 'flex',
                        alignItems: 'center',
                        justifyContent: 'center',
                        borderRadius: '4px',
                        boxShadow: '0 1px 3px rgba(0,0,0,0.2)'
                      }}
                    >
                      {r}
                    </span>
                  ))
                ) : (
                  <span style={{ fontStyle: 'italic', color: '#7f8c8d' }}>
                    Sin rutas disponibles
                  </span>
                )}
              </div>
            </div>
            

          </>
        ) : null}
      </div>

      {isImageOpen && selectedFeature && (
        <div
          onClick={() => setIsImageOpen(false)}
          style={{
            position: 'fixed',
            top: 0,
            left: 0,
            width: '100vw',
            height: '100vh',
            backgroundColor: 'rgba(0, 0, 0, 0.8)',
            display: 'flex',
            justifyContent: 'center',
            alignItems: 'center',
            zIndex: 2000,
            cursor: 'zoom-out'
          }}
        >
          <img
            src={selectedFeature.properties.photo}
            alt={selectedFeature.properties.name}
            style={{
              maxWidth: '90vw',
              maxHeight: '90vh',
              objectFit: 'contain',
              borderRadius: '8px',
              boxShadow: '0 0 20px rgba(255,255,255,0.3)'
            }}
            onClick={e => e.stopPropagation()}
          />
        </div>
      )}
    </>
  );
}
