#ifndef JUEGO_H
#define JUEGO_H

#include "Personaje.h"

const int FILAS = 10;
const int COLUMNAS = 5;

class Juego {
private:
    char nivel[FILAS][COLUMNAS];
    Personaje heroe;
    Personaje enemigos[3];
    EnemigoFinal jefeFinal;
    int posicionSalida[2];
    int posicionGuarida[2];

public:
    Juego(const Personaje& heroe, Personaje enemigos[], const EnemigoFinal& jefeFinal);

    void moverHeroe(int x, int y);
    void batalla(Personaje& enemigo);
    void batallaFinal();
    void mostrarNivel();
};

#endif // JUEGO_H
