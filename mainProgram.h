#include "structFilme.h"
#include "catalogo.h"

#include <string>
#include <vector>


#ifndef MAINPROGRAM_H
#define MAINSPROGRAM_H

Catalogo insereFilme(Catalogo &);

Catalogo insereVetorFilme(Catalogo &);

void buscaFilme(Catalogo &);

Catalogo removeFilme(Catalogo &);

Catalogo editaFilme(Catalogo &);

void imprimeFilme(Catalogo &);

void imprimeCatalogo(Catalogo &);

Filme instanciaFilme();

void buscaFilmeMaiorNota(Catalogo &);

Catalogo programInit(Catalogo &);

int programExit(Catalogo &);

#endif