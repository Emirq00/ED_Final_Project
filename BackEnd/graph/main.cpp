#include "httplib.h"
#include "json.hpp"
#include "data.hpp"   
#include <ctime>
using namespace std;
using json = nlohmann::json;

int main() {
    createMap();
    createGraph();
    createRoutes();
    
    httplib::Server svr;
    
    svr.Options("/ruta", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.status = 204;
    });
    
    svr.Post("/ruta", [](const httplib::Request& req, httplib::Response& res) {
        try {
            
            auto body = json::parse(req.body);
            string origen  = body["origen"];
            string destino = body["destino"];
            
            if (m.find(origen) == m.end() || m.find(destino) == m.end()) {
                res.status = 400;
                res.set_header("Access-Control-Allow-Origin", "*");
                res.set_content("Estación no válida", "text/plain");
                return;
            }
            int idx_origen  = m[origen];
            int idx_destino = m[destino];
            
            int N = static_cast<int>(adj.size());  
            vector<vector<int>> shortest_routes = dijkstra(N, idx_origen, adj);
            
            vector<int> ruta_ids = shortest_routes[idx_destino];
            
            cout << "[DEBUG]   IDs en ruta_ids:";
            for (int id : ruta_ids) cout << " " << id;
            cout << endl;
            
            json respuesta;
            json pasos = json::array();
            
            // Armar respuesta con nombres y rutas
            for (auto i : ruta_ids) {
                for (auto &j : m) {
                    if (j.second == i) {
                        json paso;
                        paso["estacion"] = j.first;
                        paso["rutas"]    = routes[j.first];
                        pasos.push_back(paso);
                        break;
                    }
                }
            }
            
            respuesta["ruta"]             = pasos;
            respuesta["distancia_metros"] = dist[idx_destino];
            
            srand(static_cast<unsigned>(time(nullptr)));
            float vprom = static_cast<float>(rand() % 6 + 5); 
            float distance_km = dist[idx_destino] / 1000.0f;
            float tiempo_min = (distance_km / vprom) * 60.0f;
            respuesta["tiempo_estimado_min"] = tiempo_min;
            
            // Agregar header CORS y responder JSON
            res.set_header("Access-Control-Allow-Origin", "*");
            res.set_content(respuesta.dump(), "application/json");
            cout << "[DEBUG]   Respuesta enviada al cliente\n";
        }
        catch (const std::exception &ex) {
            cout << "[ERROR] Excepción: " << ex.what() << endl;
            res.status = 500;
            res.set_header("Access-Control-Allow-Origin", "*");
            res.set_content("Error interno en el servidor", "text/plain");
        }
        catch (...) {
            cout << "[ERROR] Excepción desconocida en /ruta" << endl;
            res.status = 500;
            res.set_header("Access-Control-Allow-Origin", "*");
            res.set_content("Error interno en el servidor", "text/plain");
        }
    });
    
    cout << "Servidor corriendo en http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);
}
