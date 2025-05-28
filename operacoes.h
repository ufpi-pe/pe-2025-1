#ifndef OPERACOES_H
#define OPERACOES_H

#include <math.h>

#define PI 3.14159265358979323846

// Funções trigonométricas
double seno(double x, int modo);
double cosseno(double x, int modo);
double tangente(double x, int modo);

// Funções exponenciais e logarítmicas
double exponencial(double x);
double logaritmo_natural(double x);
double logaritmo_base10(double x);

// Outras funções
double potencia(double base, double expoente);
void quadratica(double a, double b, double c, double *x1, double *x2);

#endif
