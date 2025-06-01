#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
#include "data.hpp"
using namespace std;

// pair<nodo destino, distancia en [metros]>

void createGraph() {
    adj[ m["base_metro_universidad"] ] = {{m["cendi"], 551}, {m["quimica_conjunto_d_y_e"], 632}};
    adj[ m["cendi"] ] = {{m["psiquiatria_y_salud_mental"], 621}};
    adj[ m["psiquiatria_y_salud_mental"] ] = {{m["facultad_de_quimica"], 360}, {m["medicina"], 355}};
    adj[ m["facultad_de_quimica"] ] = {{m["enallt_edif_a_y_b"], 292}};
    adj[ m["enallt_edif_a_y_b"] ] = {{m["facultad_de_ingenieria"], 110}};
    adj[ m["facultad_de_ingenieria"] ] = {{m["facultad_de_arquitectura"], 252}};
    adj[ m["facultad_de_arquitectura"] ] = {{m["rectoria"], 480}, {m["estacionamiento_8"], 725}};
    adj[ m["rectoria"] ] = {{m["psicologia"], 228}};
    adj[ m["psicologia"] ] = {{m["facultad_de_filosofia"], 146}};
    adj[ m["facultad_de_filosofia"] ] = {{m["facultad_de_derecho"], 318}};
    adj[ m["facultad_de_derecho"] ] = {{m["facultad_de_economia"], 194}, {m["camino_verde"], 1680}};
    adj[ m["facultad_de_economia"] ] = {{m["facultad_de_odontologia"], 250}};
    adj[ m["facultad_de_odontologia"] ] = {{m["facultad_de_medicina"], 336}};
    adj[ m["facultad_de_medicina"] ] = {{m["facultad_de_veterinaria"], 880}, {m["facultad_de_quimica"], 368}, {m["invernadero"], 467}};
    adj[ m["facultad_de_veterinaria"] ] = {{m["instituto_de_geofisica"], 307}};
    adj[ m["instituto_de_geofisica"] ] = {{m["quimica_conjunto_d_y_e"], 500}};
    adj[ m["quimica_conjunto_d_y_e"] ] = {{m["base_metro_universidad"], 597}, {m["facultad_de_ciencias_alumnos"], 197}, {m["tienda_unam_ii"], 551}};
    
    adj[ m["facultad_de_ciencias_alumnos"] ] = {{m["facultad_de_ciencias_camino_verde"], 608}};
    adj[ m["facultad_de_ciencias_camino_verde"] ] = {{m["facultad_de_contaduria_y_administracion"], 401 }};
    adj[ m["facultad_de_contaduria_y_administracion"] ] = {{m["escuela_de_trabajo_social"], 211}};
    adj[ m["escuela_de_trabajo_social"] ] = {{m["base_metrobus_cu"], 141}};
    adj[ m["base_metrobus_cu"] ] = {{m["metrobus_cu"], 109}, {m["estadio_de_practicas"], 316}};
    adj[ m["metrobus_cu"] ] = {{m["educacion_a_distancia"], 178}};
    adj[ m["educacion_a_distancia"] ] = {{m["dgtic"], 234}};
    adj[ m["dgtic"] ] = {{m["facultad_de_ciencias"], 634}, {m["facultad_de_ciencias_profesores"], 396}};
    adj[ m["facultad_de_ciencias"] ] = {{m["base_metro_universidad"], 577}};
    
    adj[ m["tienda_unam_ii"] ] = {{m["facultad_de_ciencias_politicas"], 283}};
    adj[ m["facultad_de_ciencias_politicas"] ] = {{m["investigaciones_juridicas_ii"], 477}};
    adj[ m["investigaciones_juridicas_ii"] ] = {{m["biblioteca_nacional_ii"], 877}, {m["base_metrobus_cu_ii"], 1400}};
    adj[ m["biblioteca_nacional_ii"] ] = {{m["zona_cultural"], 92}, {m["unidad_de_posgrado"], 1220}};
    adj[ m["zona_cultural"] ] = {{m["unidad_de_posgrado"], 1130}};
    adj[ m["unidad_de_posgrado"] ] = {{m["posgrado_de_economia"], 316}, {m["coordinacion_de_humanidades"], 1400}};
    adj[ m["posgrado_de_economia"] ] = {{m["dgire"], 111}};
    adj[ m["dgire"] ] = {{m["dgapa"], 310}};
    adj[ m["dgapa"] ] = {{m["archivo_general"], 222}};
    adj[ m["archivo_general"] ] = {{m["avenida_iman"], 210}};
    adj[ m["avenida_iman"] ] = {{m["investigaciones_filosoficas"], 805}};
    adj[ m["investigaciones_filosoficas"] ] = {{m["investigaciones_filologicas"], 100}};
    adj[ m["investigaciones_filologicas"] ] = {{m["coordinacion_de_humanidades"], 46}};
    adj[ m["coordinacion_de_humanidades"] ] = {{m["universum"], 349}, {m["facultad_de_ciencias_politicas"], 1470}};
    adj[ m["universum"] ] = {{m["teatro_y_danza"], 355}};
    adj[ m["teatro_y_danza"] ] = {{m["muac"], 373}};
    adj[ m["muac"] ] = {{m["biblioteca_nacional"], 135}};
    adj[ m["biblioteca_nacional"] ] = {{m["espacio_escultorico"], 472}};
    adj[ m["espacio_escultorico"] ] = {{m["investigaciones_juridicas"], 333}};
    adj[ m["investigaciones_juridicas"] ] = {{m["tv_unam"], 456}};
    adj[ m["tv_unam"] ] = {{m["cuec"], 155}};
    adj[ m["cuec"] ] = {{m["dgsa"], 169}};
    adj[ m["dgsa"] ] = {{m["tienda_unam"], 101}, {m["tienda_unam_ii"], 323}};
    adj[ m["tienda_unam"] ] = {{m["base_metro_universidad"], 383}};
    
    adj[ m["estadio_de_practicas"] ] = {{m["campos_de_futbol_i"], 732}, {m["muca"], 392}, {m["facultad_de_filosofia"], 1060}};
    adj[ m["campos_de_futbol_i"] ] = {{m["jardin_botanico"], 670}, {m["pumitas_i"], 532}};
    adj[ m["jardin_botanico"] ] = {{m["campos_de_futbol_ii"], 238}};
    adj[ m["campos_de_futbol_ii"] ] = {{m["metrobus_cu"], 652}, {m["investigaciones_biomedicas"], 403}, {m["base_metrobus_cu"], 866}};
    
    adj[ m["medicina"]  ] = {{m["odontologia"], 108}};
    adj[ m["odontologia"] ] = {{m["economia"],  241}};
    adj[ m["economia"] ] = {{m["av_universidad"], 314}};
    adj[ m["av_universidad"] ] = {{m["derecho"], 324}};
    adj[ m["derecho"] ] = {{m["filosofia"], 265}};
    adj[ m["filosofia"] ] = {{m["facultad_de_psicologia"], 205}};
    adj[ m["facultad_de_psicologia"] ] = {{m["psicologia"], 87}};
    
    adj[ m["base_estadio_olimpico"] ] = {{m["campos_de_futbol_i"], 1400}, {m["psicologia"], 470}, {m["centro_medico"], 1350}};
    adj[ m["pumitas_i"] ] = {{m["pista_de_calentamiento_i"], 197}};
    adj[ m["pista_de_calentamiento_i"] ] = {{m["pista_de_calentamiento_ii"], 215}};
    adj[ m["pista_de_calentamiento_ii"] ] = {{m["pumitas_ii"], 210}};
    adj[ m["pumitas_ii"] ] = {{m["jardin_botanico"], 490}};
    adj[ m["investigaciones_biomedicas"] ] = {{m["base_metrobus_cu_ii"], 240}, {m["biblioteca_nacional_ii"], 1100}};
    adj[ m["base_metrobus_cu_ii"] ] = {{m["metrobus_cu"], 500}, {m["campos_de_futbol_i"], 650}, {m["estadio_de_practicas"], 550}};
    adj[ m["facultad_de_ciencias_profesores"] ] = {{m["investigacion_cientifica"], 220}};
    adj[ m["investigacion_cientifica"] ] = {{m["ciencias_del_mar"], 280}};
    adj[ m["ciencias_del_mar"] ] = {{m["invernadero"], 260}};
    adj[ m["invernadero"] ] = {{m["anexo_de_ingenieria"], 250}};
    adj[ m["anexo_de_ingenieria"] ] = {{m["camino_verde"], 180}};
    adj[ m["camino_verde"] ] = {{m["facultad_de_contaduria_y_administracion"], 400}, {m["biblioteca_nacional_ii"], 3100}};
    adj[ m["muca"] ] = {{m["estacionamiento_8"], 500}, {m["rectoria"], 290}};
    adj[ m["estacionamiento_8"] ] = {{m["estacionamiento_7"], 240}};
    adj[ m["estacionamiento_7"] ] = {{m["estacionamiento_6"], 240}, {m["relaciones_laborales"], 1000}};
    adj[ m["estacionamiento_6"] ] = {{m["estacionamiento_4"], 140}};
    adj[ m["estacionamiento_4"] ] = {{m["estacionamiento_3"], 250}};
    adj[ m["estacionamiento_3"] ] = {{m["estacionamiento_2"], 280}};
    adj[ m["estacionamiento_2"] ] = {{m["base_estadio_olimpico"], 270}};
    
    adj[ m["centro_medico"] ] = {{m["alberca"], 160}};
    adj[ m["alberca"] ] = {{m["ingenieria"], 180}};
    adj[ m["ingenieria"] ] = {{m["frontones"], 170}};
    adj[ m["frontones"] ] = {{m["iimas"], 240}};
    adj[ m["iimas"] ] = {{m["invernadero"], 280}};
    
    adj[ m["relaciones_laborales"] ] = {{m["direccion_general_de_obras/proveeduria"], 260}};
    adj[ m["direccion_general_de_obras/proveeduria"] ] = {{m["aapaunam"], 270}};
    adj[ m["aapaunam"] ] = {{m["posgrado_de_filosofia"], 250}, {m["anexo_de_filosofia"], 250}};
    adj[ m["posgrado_de_filosofia"] ] = {{m["pista_de_calentamiento_ii"], 750}};
    adj[ m["anexo_de_filosofia"] ] = {{m["estacionamiento_6"], 850}};
}
