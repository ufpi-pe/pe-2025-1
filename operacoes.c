#include "operacoes.h"

// Função auxiliar para conversão de graus para radianos
double para_radianos(double graus) {
    return graus * PI / 180.0;
}

// Trigonometria
double seno(double x, int modo) {
    if (modo == 2) { // modo graus
        x = para_radianos(x);
    }
    return sin(x);
}

double cosseno(double x, int modo) {
    if (modo == 2) { // modo graus
        x = para_radianos(x);
    }
    return cos(x);
}

double tangente(double x, int modo) {
    if (modo == 2) { // modo graus
        x = para_radianos(x);
    }
    return tan(x);
}

// Exponenciação e logaritmos
double exponencial(double x) {
    return exp(x);
}

double logaritmo_natural(double x) {
    return log(x);
}

double logaritmo_base10(double x) {
    return log10(x);
}

// Potenciação
double potencia(double base, double expoente) {
    return pow(base, expoente);
}

// Função quadrática
void quadratica(double a, double b, double c, double *x1, double *x2) {
    double delta = b*b - 4*a*c;
    *x1 = (-b + sqrt(delta)) / (2*a);
    *x2 = (-b - sqrt(delta)) / (2*a);
}
