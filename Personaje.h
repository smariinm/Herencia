#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

using namespace std;

class Personaje {
protected:
    int vida;
    int ataque;
    string nombre;
    int posicionX;
    int posicionY;

public:
    Personaje();
    Personaje(string nombre, int vida, int ataque, int x, int y);

    int getVida() const;
    int getAtaque() const;
    string getNombre() const;
    int getPosicionX() const;
    int getPosicionY() const;

    void setPosicion(int x, int y);
    void atacar(Personaje& enemigo);
    void recibirDano(int dano);
    bool estaVivo() const;
};

class EnemigoFinal : public Personaje {
public:
    EnemigoFinal();
    EnemigoFinal(string nombre, int vida, int ataque, int x, int y);
    void atacar(Personaje& enemigo);
};

#endif // PERSONAJE_H
