#include "structFilme.h"

#include <iostream>
#include <iomanip>

std::istream &operator>> (std::istream &in,  Filme &filme) { 
    std::cout << "Titulo do filme: "; 
    in >> filme.titulo; 
    std::cout << "Produtora do filme: "; 
    in >> filme.produtora;
    std::cout << "Nota do filme: ";
    in >> filme.nota;
    return in; 
} 

std::ostream &operator<< (std::ostream &out, const Filme &filme) { 
    out << "Titulo: " << filme.titulo << " |" << "Produtora: " << filme.produtora << " |" << "Nota: " << std::setprecision(1) << filme.nota << std::endl; 
    return out; 
} 

bool Filme::operator < (const Filme &filme2) { return ((*this).titulo < filme2.titulo); }

bool Filme::operator > (const Filme &filme2) { return ((*this).titulo > filme2.titulo); }

bool Filme::operator == (const Filme &filme2) { return ((*this).titulo == filme2.titulo); }

