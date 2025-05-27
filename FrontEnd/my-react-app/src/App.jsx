import { useState } from 'react'
import './App.css'
import 'mapbox-gl/dist/mapbox-gl.css';
import Map from './Map.jsx'
import WelcomeModal from './WelcomeModal.jsx';


function App() {
  const [showWelcome, setShowWelcome]=useState(true);
  const handleModalClose = () =>{
    setShowWelcome(false);
  }
  
  return (
    <>
      {/* <div id='map'></div> */}
     {showWelcome && <WelcomeModal onClose={handleModalClose}/>}
     <Map/>
    </>
  )
}

export default App;
