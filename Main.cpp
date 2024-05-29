#include <iostream>
#include "Personaje.h"
#include "Juego.h"

using namespace std;

int main() {
    Personaje heroe("Héroe", 100, 20, 0, 0);
    Personaje enemigos[3] = {
        Personaje("Enemigo1", 30, 10, 2, 4),
        Personaje("Enemigo2", 40, 15, 3, 0),
        Personaje("Enemigo3", 50, 20, 5, 3)
    };
    EnemigoFinal jefeFinal("Jefe Final", 200, 25, 9, 0);

    Juego juego(heroe, enemigos, jefeFinal);

    char accion;
    do {
        juego.mostrarNivel();
        cout << "Mover (w/a/s/d): ";
        cin >> accion;

        switch (accion) {
        case 'w':
            juego.moverHeroe(-1, 0);
            break;
        case 'a':
            juego.moverHeroe(0, -1);
            break;
        case 's':
            juego.moverHeroe(1, 0
            );
            break;
        case 'd':
            juego.moverHeroe(0, 1);
            break;
        default:
            cout << "Acción no válida." << endl;
        }
    } while (true);

    return 0;
}
