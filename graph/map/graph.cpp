#include <bits/stdc++.h>
#include "data.hpp"
using namespace std;

// pair<nodo destino, distancia en [metros]>
vector<vector<pair<int,int>>> adj(94);

void createGraph() {
    adj[ m["Base Metro Universidad"] ] = {{m["CENDI"], 551}, {m["Química Conjunto D y E"], 632}};
    adj[ m["CENDI"] ] = {{m["Psiquiatría y Salud Mental"], 621}};
    adj[ m["Psiquiatría y Salud Mental"] ] = {{m["Facultad de Química"], 360}, {m["Medicina"], 355}};
    adj[ m["Facultad de Química"] ] = {{m["ENALLT Edif. A y B"], 292}};
    adj[ m["ENALLT Edif. A y B"] ] = {{m["Facultad de Ingeniería"], 110}};
    adj[ m["Facultad de Ingeniería"] ] = {{m["Facultad de Arquitectura"], 252}};
    adj[ m["Facultad de Arquitectura"] ] = {{m["Rectoría"], 480}, {m["Estacionamiento 8"], 725}};
    adj[ m["Rectoría"] ] = {{m["Psicología"], 228}};
    adj[ m["Psicología"] ] = {{m["Facultad de Filosofía"], 146}};
    adj[ m["Facultad de Filosofía"] ] = {{m["Facultad de Derecho"], 318}};
    adj[ m["Facultad de Derecho"] ] = {{m["Facultad de Economía"], 194}, {m["Camino Verde"], 1680}};
    adj[ m["Facultad de Economía"] ] = {{m["Facultad de Odontología"], 250}};
    adj[ m["Facultad de Odontología"] ] = {{m["Facultad de Medicina"], 336}};
    adj[ m["Facultad de Medicina"] ] = {{m["Facultad de Veterinaria"], 880}, {m["Facultad de Química"], 368}, {m["Invernadero"], 467}};
    adj[ m["Facultad de Veterinaria"] ] = {{m["Instituto de Geofísica"], 307}};
    adj[ m["Instituto de Geofísica"] ] = {{m["Química Conjunto D y E"], 500}};
    adj[ m["Química Conjunto D y E"] ] = {{m["Base Metro Universidad"], 597}, {m["Facultad de Ciencias Alumnos"], 197}, {m["Tienda UNAM II"], 551}};
    
    adj[ m["Facultad de Ciencias Alumnos"] ] = {{m["Facultad de Ciencias Camino Verde"], 608}};
    adj[ m["Facultad de Ciencias Camino Verde"] ] = {{m["Facultad de Contaduría y Administración"], 401 }};
    adj[ m["Facultad de Contaduría y Administración"] ] = {{m["Escuela de Trabajo Social"], 211}};
    adj[ m["Escuela de Trabajo Social"] ] = {{m["Base Metrobús CU"], 141}};
    adj[ m["Base Metrobús CU"] ] = {{m["Metrobús CU"], 109}, {m["Estadio de Prácticas"], 316}};
    adj[ m["Metrobús CU"] ] = {{m["Educación a Distancia"], 178}};
    adj[ m["Educación a Distancia"] ] = {{m["DGTIC"], 234}};
    adj[ m["DGTIC"] ] = {{m["Facultad de Ciencias"], 634}, {m["Facultad de Ciencias Profesores"], 396}};
    adj[ m["Facultad de Ciencias"] ] = {{m["Base Metro Universidad"], 577}};
    
    adj[ m["Tienda UNAM II"] ] = {{m["Facultad de Ciencias Políticas"], 283}};
    adj[ m["Facultad de Ciencias Políticas"] ] = {{m["Investigaciones Jurídicas II"], 477}};
    adj[ m["Investigaciones Jurídicas II"] ] = {{m["Biblioteca Nacional II"], 877}, {m["Base Metrobús CU II"], 1400}};
    adj[ m["Biblioteca Nacional II"] ] = {{m["Zona Cultural"], 92}, {m["Unidad de Posgrado"], 1220}};
    adj[ m["Zona Cultural"] ] = {{m["Unidad de Posgrado"], 1130}};
    adj[ m["Unidad de Posgrado"] ] = {{m["Posgrado de Economía"], 316}, {m["Coordinación de Humanidades"], 1400}};
    adj[ m["Posgrado de Economía"] ] = {{m["DGIRE"], 111}};
    adj[ m["DGIRE"] ] = {{m["DGAPA"], 310}};
    adj[ m["DGAPA"] ] = {{m["Archivo General"], 222}};
    adj[ m["Archivo General"] ] = {{m["Avenida IMAN"], 210}};
    adj[ m["Avenida IMAN"] ] = {{m["Investigaciones Filosóficas"], 805}};
    adj[ m["Investigaciones Filosóficas"] ] = {{m["Investigaciones Filológicas"], 100}};
    adj[ m["Investigaciones Filológicas"] ] = {{m["Coordinación de Humanidades"], 46}};
    adj[ m["Coordinación de Humanidades"] ] = {{m["UNIVERSUM"], 349}, {m["Facultad de Ciencias Políticas"], 1470}};
    adj[ m["UNIVERSUM"] ] = {{m["Teatro y Danza"], 355}};
    adj[ m["Teatro y Danza"] ] = {{m["MUAC"], 373}};
    adj[ m["MUAC"] ] = {{m["Biblioteca Nacional"], 135}};
    adj[ m["Biblioteca Nacional"] ] = {{m["Espacio Escultórico"], 472}};
    adj[ m["Espacio Escultórico"] ] = {{m["Investigaciones Jurídicas"], 333}};
    adj[ m["Investigaciones Jurídicas"] ] = {{m["TV. UNAM"], 456}};
    adj[ m["TV. UNAM"] ] = {{m["CUEC"], 155}};
    adj[ m["CUEC"] ] = {{m["DGSA"], 169}};
    adj[ m["DGSA"] ] = {{m["Tienda UNAM"], 101}, {m["Tienda UNAM II"], 323}};
    adj[ m["Tienda UNAM"] ] = {{m["Base Metro Universidad"], 383}};
    
    adj[ m["Estadio de Prácticas"] ] = {{m["Campos de futbol I"], 732}, {m["MUCA"], 392}, {m["Facultad de Filosofía"], 1060}};
    adj[ m["Campos de futbol I"] ] = {{m["Jardín Botánico"], 670}, {m["Pumitas I"], 532}};
    adj[ m["Jardín Botánico"] ] = {{m["Campos de futbol II"], 238}};
    adj[ m["Campos de futbol II"] ] = {{m["Metrobús CU"], 652}, {m["Investigaciones Biomédicas"], 403}, {m["Base Metrobús CU"], 866}};
    
    adj[ m["Medicina"]  ] = {{m["Odontología"], 108}};
    adj[ m["Odontología"] ] = {{m["Economía"],  241}};
    adj[ m["Economía"] ] = {{m["Av. Universidad"], 314}};
    adj[ m["Av. Universidad"] ] = {{m["Derecho"], 324}};
    adj[ m["Derecho"] ] = {{m["Filosofía"], 265}};
    adj[ m["Filosofía"] ] = {{m["Facultad de Psicología"], 205}};
    adj[ m["Facultad de Psicología"] ] = {{m["Psicología"], 87}};
    
    adj[ m["Base Estadio Olímpico"] ] = {{m["Campos de futbol I"], 1400}, {m["Psicología"], 470}, {m["Centro Médico"], 1350}};
    adj[ m["Pumitas I"] ] = {{m["Pista de calentamiento I"], 197}};
    adj[ m["Pista de calentamiento I"] ] = {{m["Pista de calentamiento II"], 215}};
    adj[ m["Pista de calentamiento II"] ] = {{m["Pumitas II"], 210}};
    adj[ m["Pumitas II"] ] = {{m["Jardín Botánico"], 490}};
    adj[ m["Investigaciones Biomédicas"] ] = {{m["Base Metrobús CU II"], 240}, {m["Biblioteca Nacional II"], 1100}};
    adj[ m["Base Metrobús CU II"] ] = {{m["Metrobús CU"], 500}, {m["Campos de futbol I"], 650}, {m["Estadio de Prácticas"], 550}};
    adj[ m["Facultad de Ciencias Profesores"] ] = {{m["Investigación Científica"], 220}};
    adj[ m["Investigación Científica"] ] = {{m["Ciencias del Mar"], 280}};
    adj[ m["Ciencias del Mar"] ] = {{m["Invernadero"], 260}};
    adj[ m["Invernadero"] ] = {{m["Anexo de Ingeniería"], 250}};
    adj[ m["Anexo de Ingeniería"] ] = {{m["Camino Verde"], 180}};
    adj[ m["Camino Verde"] ] = {{m["Facultad de Contaduría y Administración"], 400}, {m["Biblioteca Nacional II"], 3100}};
    adj[ m["MUCA"] ] = {{m["Estacionamiento 8"], 500}, {m["Rectoría"], 290}};
    adj[ m["Estacionamiento 8"] ] = {{m["Estacionamiento 7"], 240}};
    adj[ m["Estacionamiento 7"] ] = {{m["Estacionamiento 6"], 240}, {m["Relaciones Laborales"], 1000}};
    adj[ m["Estacionamiento 6"] ] = {{m["Estacionamiento 4"], 140}};
    adj[ m["Estacionamiento 4"] ] = {{m["Estacionamiento 3"], 250}};
    adj[ m["Estacionamiento 3"] ] = {{m["Estacionamiento 2"], 280}};
    adj[ m["Estacionamiento 2"] ] = {{m["Base Estadio Olímpico"], 270}};
    
    adj[ m["Centro Médico"] ] = {{m["Alberca"], 160}};
    adj[ m["Alberca"] ] = {{m["Ingeniería"], 180}};
    adj[ m["Ingeniería"] ] = {{m["Frontones"], 170}};
    adj[ m["Frontones"] ] = {{m["IIMAS"], 240}};
    adj[ m["IIMAS"] ] = {{m["Invernadero"], 280}};
    
    adj[ m["Relaciones Laborales"] ] = {{m["Dirección General de Obras/Proveeduría"], 260}};
    adj[ m["Dirección General de Obras/Proveeduría"] ] = {{m["AAPAUNAM"], 270}};
    adj[ m["AAPAUNAM"] ] = {{m["Posgrado de Filosofía"], 250}, {m["Anexo de Filosofía"], 250}};
    adj[ m["Posgrado de Filosofía"] ] = {{m["Pista de calentamiento II"], 750}};
    adj[ m["Anexo de Filosofía"] ] = {{m["Estacionamiento 6"], 850}};
}