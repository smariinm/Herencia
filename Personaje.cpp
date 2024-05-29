#include "Personaje.h"
#include <iostream>

using namespace std;

Personaje::Personaje() : nombre(""), vida(0), ataque(0), posicionX(0), posicionY(0) {}

Personaje::Personaje(string nombre, int vida, int ataque, int x, int y)
    : nombre(nombre), vida(vida), ataque(ataque), posicionX(x), posicionY(y) {}

int Personaje::getVida() const { return vida; }
int Personaje::getAtaque() const { return ataque; }
string Personaje::getNombre() const { return nombre; }
int Personaje::getPosicionX() const { return posicionX; }
int Personaje::getPosicionY() const { return posicionY; }

void Personaje::setPosicion(int x, int y) {
    posicionX = x;
    posicionY = y;
}

void Personaje::atacar(Personaje& enemigo) {
    cout << nombre << " ataca a " << enemigo.getNombre() << " con " << ataque << " de daño." << endl;
    enemigo.recibirDano(ataque);
}

void Personaje::recibirDano(int dano) {
    vida -= dano;
    if (vida < 0) vida = 0;
}

bool Personaje::estaVivo() const {
    return vida > 0;
}

EnemigoFinal::EnemigoFinal() : Personaje() {}

EnemigoFinal::EnemigoFinal(string nombre, int vida, int ataque, int x, int y)
    : Personaje(nombre, vida, ataque, x, y) {}

void EnemigoFinal::atacar(Personaje& enemigo) {
    cout << nombre << " usa un super ataque contra " << enemigo.getNombre() << " con " << ataque * 2 << " de daño." << endl;
    enemigo.recibirDano(ataque * 2);
}
