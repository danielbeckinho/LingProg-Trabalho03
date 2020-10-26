#include "catalogo.h"
#include "structFilme.h"

#include <string>
#include <algorithm>
#include <iostream>

// tenho que mudar essa pro busca sobrecarregada 
bool Catalogo::filmeNoCatalogo(const std::string &titulo) {
    for (auto filmeCat : vectorCatalogo) {
        if (filmeCat.titulo == titulo) {return false; }
    }
    return true;
}

Catalogo Catalogo::inserirFilme(Filme &filme) {
    if (vectorCatalogo.size() == 0) {vectorCatalogo.push_back(filme);}
    else { 
        for (int i{0}; i < vectorCatalogo.size(); i++) {
            if (filme < vectorCatalogo[i]) {
                auto it = vectorCatalogo.insert(vectorCatalogo.begin() + i, filme); 
                break;
            }
        }
    }

    return *this;
}

Catalogo Catalogo::operator+= (Filme &filme) {
    if (((*this)(filme.titulo) != NULL) && ((*this).vectorCatalogo.size() < Catalogo::numMaxFilmes)) {
        inserirFilme(filme); 
    }
    return *this;
}

Catalogo Catalogo::operator+= (std::vector<Filme> &vectorFilmes) {
    for (auto filme : vectorFilmes) {
        *this+= filme;
    }
    return *this;
}

Catalogo Catalogo::operator-= (const std::string &titulo) {
    if ((*this)(titulo) != NULL) {
        vectorCatalogo.erase(std::find(vectorCatalogo.begin(), vectorCatalogo.end(), *(*this)(titulo))); 
    }
    return *this;
}

Filme* Catalogo::operator() (const std::string titulo) {
    Filme* filmePtr = NULL;
    for (auto filme : vectorCatalogo) {
        if (filme.titulo == titulo) {filmePtr = &filme;}
    }
    return filmePtr;
}

Catalogo Catalogo::operator() (std::string titulo, std::string novoNome, bool mudarTitulo = false) {
    if (mudarTitulo == false) { (*this)(titulo)->produtora = novoNome; }

    else {
        std::string produtora = (*this)(titulo)->produtora; //salva dados nao mod
        double nota = (*this)(titulo)->nota;

        (*this)-= titulo; //remove filme antigo pra add novo com titulo alterado

        Filme f; //cria novo filme
        f.titulo = novoNome; f.produtora = produtora; f.nota = nota;
        (*this)+= f;
    }

    return *this;
}

Catalogo Catalogo::operator() (std::string titulo, double nota) {
    (*this)(titulo)->nota = nota;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Catalogo &catalogo) {
    std::cout<< "Exibindo todos os filmes do catalogo: " << std::endl;
    for (auto filme : catalogo.vectorCatalogo) {
        out<<filme;
    }
    return out;
}

Filme Catalogo::filmeNotaMaisAlta() {
    double notaMax = 0;
    Filme *filmeNotaMaxPtr = NULL; 

    for (auto filme : vectorCatalogo) {
        if (filme.nota > notaMax) {
            notaMax = filme.nota;
            filmeNotaMaxPtr = &filme;
        }
    }
    return *filmeNotaMaxPtr;
}

const int Catalogo::getNumMaxFilmes() {
    return numMaxFilmes;
}

