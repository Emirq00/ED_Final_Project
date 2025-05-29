#include <bits/stdc++.h>
#include "data.hpp"
using namespace std;

void createRoutes() {
    routes["base_metro_universidad"] = {1,2,3,4,5};
    routes["cendi"] = {1,5};
    routes["psiquiatria_y_salud_mental"] = {1,5};
    routes["facultad_de_quimica"]  = {1,7,12};
    routes["enallt_edif_a_y_b"]  = {1,7,12};
    routes["facultad_de_ingenieria"] = {1,7,12};
    routes["facultad_de_arquitectura"]  = {1,7,12};
    routes["rectoria"] = {1,9};
    routes["psicologia"] = {1,5,7,9,12};
    routes["facultad_de_filosofia"] = {1,5,7,9,12,13};
    routes["facultad_de_derecho"] = {1,5,7,9,12,13};
    routes["facultad_de_economia"]  = {1,5,7,9,12};
    routes["facultad_de_odontologia"] = {1,5,7,9,12};
    routes["facultad_de_medicina"] = {1,5,7,9,12};
    routes["facultad_de_veterinaria"] = {1,5};
    routes["instituto_de_geofisica"] = {1,5};
    routes["quimica_conjunto_d_y_e"] = {1,2,3,4,5};
    
    routes["facultad_de_ciencias_alumnos"] = {2,4};
    routes["facultad_de_ciencias_camino_verde"] = {2,4};
    routes["facultad_de_contaduria_y_administracion"] = {2,4,6,8,9};
    routes["escuela_de_trabajo_social"] = {2,4,6,8,9};
    routes["base_metrobus_cu"] = {2,6,8,9,11};
    routes["metrobus_cu"] = {2,4,6};
    routes["educacion_a_distancia"] = {2,4,6};
    routes["dgtic"] = {2,4,6};
    routes["facultad_de_ciencias"] = {2,4};
    
    routes["tienda_unam_ii"] = {3,10};
    routes["facultad_de_ciencias_politicas"] = {3,10,13};
    routes["investigaciones_juridicas_ii"] = {3,10,13};
    routes["biblioteca_nacional_ii"] = {3,10,13};
    routes["zona_cultural"] = {3,10};
    routes["unidad_de_posgrado"] = {3,10,13};
    routes["posgrado_de_economia"] = {3,10};
    routes["dgire"] = {3,10};
    routes["dgapa"] = {3,10};
    routes["archivo_general"] = {3,10};
    routes["avenida_iman"] = {3,10};
    routes["investigaciones_filosoficas"] = {3,10};
    routes["investigaciones_filologicas"] = {3,10};
    routes["coordinacion_de_humanidades"] = {3,10,13};
    routes["universum"] = {3,10};
    routes["teatro_y_danza"] = {3,10};
    routes["muac"] = {3,10};
    routes["biblioteca_nacional"] = {3,10};
    routes["espacio_escultorico"] = {3,10};
    routes["investigaciones_juridicas"] = {3,10};
    routes["tv_unam"] = {3,10};
    routes["cuec"] = {3,10};
    routes["dgsa"] = {3,10};
    routes["tienda_unam"] = {3};
    
    routes["estadio_de_practicas"] = {4,6,8,9,11,13};
    routes["campos_de_futbol_i"] = {4,6,10};
    routes["jardin_botanico"] = {4,6,10,11};
    routes["campos_de_futbol_ii"] = {4,6,10,11};
    
    routes["medicina"] = {5};
    routes["odontologia"] = {5};
    routes["economia"] = {5};
    routes["av_universidad"] = {5};
    routes["derecho"] = {5};
    routes["filosofia"] = {5};
    routes["facultad_de_psicologia"] = {5};
    
    routes["base_estadio_olimpico"] = {6,7,8,12};
    routes["pumitas_i"] = {6};
    routes["pista_de_calentamiento_i"] = {6};
    routes["pista_de_calentamiento_ii"] = {6,11};
    routes["pumitas_ii"] = {6,11};
    routes["investigaciones_biomedicas"] = {6,10};
    routes["base_metrobus_cu_ii"] = {6,10,13};
    routes["facultad_de_ciencias_profesores"] = {6};
    routes["investigacion_cientifica"] = {6};
    routes["ciencias_del_mar"] = {6};
    routes["invernadero"] = {6,8,9};
    routes["anexo_de_ingenieria"] = {6,8,9};
    routes["camino_verde"] = {6,8,9,13};
    routes["muca"] = {6,8,9,11};
    routes["estacionamiento_8"] = {6,7,8,11,12};
    routes["estacionamiento_7"] = {6,7,8,11,12};
    routes["estacionamiento_6"] = {6,7,8,12};
    routes["estacionamiento_4"] = {6,7,8,12};
    routes["estacionamiento_3"] = {6,7,8,12};
    routes["estacionamiento_2"] = {6,7,8,12};
    
    routes["centro_medico"] = {8};
    routes["alberca"] = {8};
    routes["ingenieria"] = {8};
    routes["frontones"] = {8};
    routes["iimas"] = {8};
    
    routes["relaciones_laborales"] = {11,12};
    routes["direccion_general_de_obras/proveeduria"] = {11,12};
    routes["aapaunam"] = {11,12};
    routes["posgrado_de_filosofia"] = {11};
    
    routes["anexo_de_filosofia"] = {12};
}