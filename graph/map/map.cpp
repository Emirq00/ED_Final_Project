#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> m;

int main() {
    // ruta 1
    m["Base Metro Universidad"] = 1;
    m["CENDI"] = 2;
    m["Psiquiatría y Salud Mental"] = 3;
    m["Facultad de Química"]  = 4;
    m["ENALLT Edif. A y B"]  = 5;
    m["Facultad de Ingeniería"] = 6;
    m["Facultad de Arquitectura"]  = 7;
    m["Rectoría"] = 8;
    m["Psicología"] = 9;
    m["Facultad de Filosofía"] = 10;
    m["Facultad de Derecho"] = 11;
    m["Facultad de Economía"]  = 12;
    m["Facultad de Odontología"] = 13;
    m["Facultad de Medicina"] = 14;
    m["Facultad de Veterinaria"]  =15;
    m["Instituto de Geofísica"] = 16;
    m["Química Conjunto D y E"] = 17;
    
    // ruta 2
    //* m["Base Metro Universidad"] = 1;
    //* m["Química Conjunto D y E"] = 17;
    m["Facultad de Ciencias Alumnos"] = 18;
    m["Facultad de Ciencias Camino Verde"] = 19;
    m["Facultad de Contaduría y Administración"] = 20;
    m["Escuela de Trabajo Social"] = 21;
    m["Base Metrobús CU"] = 22;
    m["Metrobús CU"] = 23;
    m["Educación a Distancia"] = 24;
    m["DGTC"] = 25;
    m["Facultad de Ciencias"] = 26;
    
    // ruta 3
    //* m["Base Metro Universidad"] = 1;
    //* m["Química Conjunto D y E"] = 17;
    m["Tienda UNAM 2"] = 27;
    m["Facultad de Ciencias Políticas"] = 28;
    m["Investigaciones Jurídicas 2"] = 29;
    m["Biblioteca Nacional 2"] = 30;
    m["Zona Cultural"] = 31;
    m["Unidad de Posgrado"] = 32;
    m["Posgrado de Economía"] = 33;
    m["DGIRE"] = 34;
    m["DGAPA"] = 35;
    m["Archivo General"] = 36;
    m["Avenida IMAN"] = 37;
    m["Investigaciones Filosóficas"] = 38;
    m["Investigaciones Filológicas"] = 39;
    m["Coordinación de Humanidades"] = 40;
    m["UNIVERSUM"] = 41;
    m["Teatro y Danza"] = 42;
    m["MUAC"] = 43;
    m["Biblioteca Nacional"] = 44;
    m["Espacio Escultórico"] = 45;
    m["Investigaciones Jurídicas"] = 46;
    m["TV. UNAM"] = 47;
    m["CUEC"] = 48;
    m["DGSA"] = 49;
    m["Tienda UNAM"] = 50;
    
    // ruta 4
    //* m["Base Metro Universidad"] = 1;
    //* m["Química Conjunto D y E"] = 17;
    //* m["Facultad de Ciencias Alumnos"] = 18;  
    //* m["Facultad de Ciencias Camino Verde"] = 19;  
    //* m["Facultad de Contaduría y Administración"] = 20;  
    //* m["Escuela de Trabajo Social"] = 21;  
    //* m["Base Metrobús CU"] = 22;
    m["Estadio de Prácticas"] = 51;
    m["Campos de futbol I"] = 52;
    m["Jardín Botánico"] = 53;
    m["Campos de futbol II"] = 54;
    //* m["Metrobús CU"] = 23; 
    //* m["Educación a Distancia"] = 24;  
    m["DGTIC"] = 55;
    //* m["Facultad de Ciencias"] = 26;
    
    // ruta 5
    //* m["Base Metro Universidad"] = 1; 
    //* m["CENDI"] = 2;
    //* m["Psiquiatría y Salud Mental"] = 3;
    m["Medicina"] = 56;
    m["Odontología"] = 57;
    m["Economía"] = 58;
    m["Av. Universidad"] = 59;
    m["Derecho"] = 60;
    m["Filosofía"] = 61;
    m["Facultad de Psicología"] = 62;
    //* m["Psicología"] = 9;
    //* m["Facultad de Filosofía"] = 10;
    //* m["Facultad de Derecho"] = 11;
    //* m["Facultad de Economía"]  = 12;
    //* m["Facultad de Odontología"] = 13;
    //* m["Facultad de Medicina"] = 14;
    //* m["Facultad de Veterinaria"]  =15;
    //* m["Instituto de Geofísica"] = 16;
    //* m["Química Conjunto D y E"] = 17;
    
    // ruta 6
    m["Base Estadio Olímpico"] = 63;
    //* m["Campos de futbol I"] = 52;
    m["Pumitas I"] = 64;
    m["Pista de calentamiento I"] = 65;
    m["Pista de calentamiento II"] = 66;
    m["Pumitas II"] = 67;
    //* ["Jardín Botánico"] = 53;
    //* ["Campos de futbol II"] = 54;
    m["Investigaciones Biomédicas"] = 68;
    m["Metrobús CU II"] = 69;
    //* m["Metrobús CU"] = 23;
    //* ["Educación a Distancia"] = 24;
    //* ["DGTC"] = 25;
    m["Facultad de Ciencias Profesores"] = 70;
    m["Investigación Científica"] = 71;
    m["Ciencias del Mar"] = 72;
    m["Invernadero"] = 73;
    m["Anexo de Ingeniería"] = 74;
    m["Camino Verde"] = 75;
    //* m["Facultad de Contaduría y Administración"] = 20;
    //* m["Escuela de Trabajo Social"] = 21;  
    //* m["Base Metrobús CU"] = 22;
    //* m["Estadio de Prácticas"] = 51;
    m["MUCA"] = 76;
    m["Estacionamiento 8"] = 77;
    m["Estacionamiento 7"] = 78;
    m["Estacionamiento 6"] = 79;
    m["Estacionamiento 5"] = 80;
    m["Estacionamiento 4"] = 81;
    m["Estacionamiento 3"] = 82;
    m["Estacionamiento 2"] = 83;
    
    // ruta 7
    //* m["Base Estadio Olímpico"] = 63;
    //* m["Psicología"] = 9;
    //* m["Facultad de Filosofía"] = 10;
    //* m["Facultad de Derecho"] = 11;
    //* m["Facultad de Economía"]  = 12;
    //* m["Facultad de Odontología"] = 13;
    //* m["Facultad de Medicina"] = 14; 
    //* m["Facultad de Química"]  = 4;
    //* m["ENALLT Edif. A y B"]  = 5;
    //* m["Facultad de Ingeniería"] = 6
    //* m["Facultad de Arquitectura"]  = 7
    //* m["Estacionamiento 8"] = 77;
    //* m["Estacionamiento 7"] = 78;
    //* m["Estacionamiento 6"] = 79;
    //* m["Estacionamiento 4"] = 80;
    //* m["Estacionamiento 3"] = 81;
    //* m["Estacionamiento 2"] = 82;
    
    // ruta 8;
    //* m["Base Estadio Olímpico"] = 63;  
    m["Centro Médico"] = 83;
    m["Alberca"] = 84;
    m["Ingeniería"] = 85;
    m["Frontones"] = 86;
    m["IIMAS"] = 87;
    //* m["Invernadero"] = 73;
    //* m["Anexo de Ingeniería"] = 74;
    //* m["Camino Verde"] = 75;
    //* m["Facultad de Contaduría y Administración"] = 20;
    //* m["Escuela de Trabajo Social"] = 21;  
    //* m["Base Metrobús CU"] = 22;
    //* m["Estadio de Prácticas"] = 51;
    //* m["MUCA"] = 76;
    //* m["Estacionamiento 8"] = 77;
    //* m["Estacionamiento 7"] = 78;
    //* m["Estacionamiento 6"] = 79;
    //* m["Estacionamiento 4"] = 80;
    //* m["Estacionamiento 3"] = 81;
    //* m["Estacionamiento 2"] = 82;
    
    // ruta 9
    //* m["Base Metrobús CU"] = 22;
    //* m["Estadio de Prácticas"] = 51;
    //* m["MUCA"] = 76;
    //* m["Rectoría"] = 8
    //* m["Psicología"] = 9
    //* m["Facultad de Filosofía"] = 10
    //* m["Facultad de Derecho"] = 11
    //* m["Facultad de Economía"]  = 12
    //* m["Facultad de Odontología"] = 13
    //* m["Facultad de Medicina"] = 14
    //* m["Invernadero"] = 73;
    //* m["Anexo de Ingeniería"] = 74;
    //* m["Camino Verde"] = 75;
    //* m["Facultad de Contaduría y Administración"] = 20;
    //* m["Escuela de Trabajo Social"] = 21;
    
    // ruta 10
    //* m["Base Metrobús CU II"] = 69;
    //* m["Campos de futbol I"] = 52;
    //* ["Jardín Botánico"] = 53;
    //* ["Campos de futbol II"] = 54;
    //* m["Investigaciones Biomédicas"] = 68;
    //* m["Biblioteca Nacional II"] = 30;
    //* m["Zona Cultural"] = 31;
    //* m["Unidad de Posgrado"] = 32;
    //* m["Posgrado de Economía"] = 33;
    //* m["DGIRE"] = 34;
    //* m["DGAPA"] = 35;
    //* m["Archivo General"] = 36;
    //* m["Avenida IMAN"] = 37;
    //* m["Investigaciones Filosóficas"] = 38;
    //* m["Investigaciones Filológicas"] = 39;
    //* m["Coordinación de Humanidades"] = 40;
    //* m["UNIVERSUM"] = 41;
    //* m["Teatro y Danza"] = 42;
    //* m["MUAC"] = 43;
    //* m["Biblioteca Nacional"] = 44;
    //* m["Espacio Escultórico"] = 45;
    //* m["Investigaciones Jurídicas"] = 46;
    //* m["TV. UNAM"] = 47;
    //* m["CUEC"] = 48;
    //* m["DGSA"] = 49;
    //* m["Tienda UNAM II"] = 27;
    //* m["Facultad de Ciencias Políticas"] = 28;
    //* m["Investigaciones Jurídicas II"] = 29;
    
    // ruta 11
    //* m["Base Metrobús CU"] = 22;
    //* m["Estadio de Prácticas"] = 51;
    //* m["MUCA"] = 76;
    //* m["Estacionamiento 8"] = 77;
    //* m["Estacionamiento 7"] = 78;
    m["Relaciones Laborales"] = 88;
    m["Dirección General de Obras/Proveeduría"] = 89;
    m["AAPAUNAM"] = 90;
    m["Posgrado de Filosofía"] = 91;
    //* m["Pista de calentamiento II"] = 66;
    //* m["Pumitas II"] = 67;
    //* m["Jardín Botánico"] = 53;
    //* m["Campos de futbol II"] = 54;
    
    // ruta 12
    //* m["Facultad de Filosofía"] = 10;
    //* m["Facultad de Derecho"] = 11; 
    //* m["Camino Verde"] = 75;
    //* m["Biblioteca Nacional II"] = 30;
    //* m["Unidad de Posgrado"] = 32;
    //* m["Coordinación de Humanidades"] = 40;
    //* m["Facultad de Ciencias Políticas"] = 28;
    //* m["Investigaciones Jurídicas II"] = 29;
    //* m["Base Metrobús CU II"] = 69;
    //* m["Estadio de Prácticas"] = 51;
}

