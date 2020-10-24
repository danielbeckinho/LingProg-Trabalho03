#ifndef MAINPROGRAM_H
#define MAINSPROGRAM_H

#include "structFilme.h"
#include "catalogo.h"

#include <string>
#include <vector>


void insereFilme(Catalogo &);

void insereVetorFilme(Catalogo &);

void buscaFilme(Catalogo &);

void removeFilme(Catalogo &);

void editaFilme(Catalogo &);

void imprimeFilme(Catalogo &);

void imprimeCatalogo(Catalogo &);

Filme instanciaFilme();

void buscaFilmeMaiorNota(Catalogo &);

Catalogo programInit(Catalogo &);

int programExit(Catalogo &);

#endif