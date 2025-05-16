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
}