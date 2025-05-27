import React, { useEffect } from 'react'
import "./WelcomeModal.css"

const WelcomeModal =({onClose}) => {

    useEffect(() => {
        document.body.classList.add('modal-open');
        return () => document.body.classList.remove('modal-open');
    }, []);
    return(
        <div className='Container'>
            <h1 className='Modal-Title'>Bienvenido a PuMaps</h1>
            <button className='Modal-Button' onClick={onClose}>Entrar</button>
            
        </div>
    );
}

export default WelcomeModal;