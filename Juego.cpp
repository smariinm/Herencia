#include "Juego.h"
#include <iostream>

using namespace std;

Juego::Juego(const Personaje& heroe, Personaje enemigos[], const EnemigoFinal& jefeFinal)
    : heroe(heroe), jefeFinal(jefeFinal) {
    char tempNivel[FILAS][COLUMNAS] = {
        {' ', ' ', 'S', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'E'},
        {'E', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'E', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', 'E', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {'G', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            nivel[i][j] = tempNivel[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        this->enemigos[i] = enemigos[i];
    }
    posicionSalida[0] = 0;
    posicionSalida[1] = 2;
    posicionGuarida[0] = 9;
    posicionGuarida[1] = 0;
}

void Juego::moverHeroe(int x, int y) {
    int nuevaX = heroe.getPosicionX() + x;
    int nuevaY = heroe.getPosicionY() + y;

    if (nuevaX >= 0 && nuevaX < FILAS && nuevaY >= 0 && nuevaY < COLUMNAS) {
        heroe.setPosicion(nuevaX, nuevaY);
        char celda = nivel[nuevaX][nuevaY];

        if (celda == 'E') {
            for (int i = 0; i < 3; i++) {
                if (enemigos[i].getPosicionX() == nuevaX && enemigos[i].getPosicionY() == nuevaY) {
                    batalla(enemigos[i]);
                }
            }
        }
        else if (celda == 'G' || celda == 'S') {
            cout << "¡Has llegado al final! Enfrentas al jefe final." << endl;
            batallaFinal();
        }
    }
    else {
        cout << "Movimiento fuera de los límites del mapa." << endl;
    }
}

void Juego::batalla(Personaje& enemigo) {
    cout << "Batalla contra " << enemigo.getNombre() << "!" << endl;
    while (heroe.estaVivo() && enemigo.estaVivo()) {
        heroe.atacar(enemigo);
        if (enemigo.estaVivo()) {
            enemigo.atacar(heroe);
        }
    }
    if (heroe.estaVivo()) {
        cout << "Has derrotado a " << enemigo.getNombre() << "!" << endl;
    }
    else {
        cout << "Game Over. " << enemigo.getNombre() << " te ha derrotado." << endl;
        exit(0);
    }
}

void Juego::batallaFinal() {
    cout << "¡Batalla final contra " << jefeFinal.getNombre() << "!" << endl;
    while (heroe.estaVivo() && jefeFinal.estaVivo()) {
        heroe.atacar(jefeFinal);
        if (jefeFinal.estaVivo()) {
            jefeFinal.atacar(heroe);
        }
    }
    if (heroe.estaVivo()) {
        cout << "¡Has derrotado al jefe final! ¡Has ganado el juego!" << endl;
    }
    else {
        cout << "Game Over. " << jefeFinal.getNombre() << " te ha derrotado." << endl;
        exit(0);
    }
}

void Juego::mostrarNivel() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == heroe.getPosicionX() && j == heroe.getPosicionY()) {
                cout << 'H' << ' ';
            }
            else {
                cout << nivel[i][j] << ' ';
            }
        }
        cout << endl;
    }
}
