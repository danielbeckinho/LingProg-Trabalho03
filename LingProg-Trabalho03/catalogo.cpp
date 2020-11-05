#include "catalogo.h"
#include "structFilme.h"

#include <string>
#include <algorithm>
#include <iostream>

Catalogo& Catalogo::inserirFilme(Filme &filme) {
    if (vectorCatalogo.size() == 0) {vectorCatalogo.push_back(filme);}
    else { 
        for (size_t i{0}; i < vectorCatalogo.size(); i++) {
            if (filme < vectorCatalogo[i]) {
                vectorCatalogo.insert(vectorCatalogo.begin() + i, 1, filme); 
                break;
            }
        }
        //se n tiver elemento menos que o filme ele eh o maior entao push_back
        vectorCatalogo.push_back(filme);
    }
    return *this;
}

Catalogo& Catalogo::operator+= (Filme &filme) {
    if (((*this)(filme.titulo) == NULL) && (this->vectorCatalogo.size() < numMaxFilmes)) {
        (*this).inserirFilme(filme); 
    }
    return *this;
}

Catalogo& Catalogo::operator+= (std::vector<Filme> &vectorFilmes) {
    for (unsigned i{0}; i < vectorFilmes.size(); i++) {
        *this+= vectorFilmes[i];
    }
    
    /*for (auto filme : vectorFilmes) {
        *this+= filme;
    }*/
    return *this;
}

Catalogo& Catalogo::operator-= (const std::string &titulo) {
    if ((*this)(titulo) != NULL) {
        vectorCatalogo.erase(std::find(vectorCatalogo.begin(), vectorCatalogo.end(), *(*this)(titulo))); 
    }
    return *this;
}

Filme* Catalogo::operator() (const std::string titulo) {
    for (unsigned i = 0; i < (this->vectorCatalogo).size(); i++) {
    	if ((this->vectorCatalogo[i]).titulo == titulo) {
            return &(this->vectorCatalogo[i]);
        }
	}
	//se nao encontrar retorna NULL
	return NULL;
}

Catalogo& Catalogo::operator() (std::string titulo, std::string novoNome, bool mudarTitulo = false) {
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

Catalogo& Catalogo::operator() (std::string titulo, double nota) {
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

Filme *Catalogo::filmeNotaMaisAlta() {
    double notaMax = 0;
    unsigned indiceNotaMax{0};

    for (unsigned i{0}; i < vectorCatalogo.size(); i++) {
        if (vectorCatalogo[i].nota > notaMax) {
            notaMax = vectorCatalogo[i].nota;
            indiceNotaMax = i;
        }
    }

    return &vectorCatalogo[indiceNotaMax];

    /* Filme *filmeNotaMax = NULL; 

    for (auto filme : vectorCatalogo) {
        if (filme.nota > notaMax) {
            notaMax = filme.nota;
            filmeNotaMaxPtr = &filme;
        }
    }
    return *filmeNotaMaxPtr;
    */
}

const int Catalogo::getNumMaxFilmes() {
    return numMaxFilmes;
}

const std::vector<Filme> Catalogo::getVectorCatalogo() {
    return vectorCatalogo;
}

const std::vector<Filme> Catalogo::getVectorCatalogo() const {
    return vectorCatalogo;
}

