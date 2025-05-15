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
}