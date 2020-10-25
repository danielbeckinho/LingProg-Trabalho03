#include <string>

#ifndef STRUCTFILME_H
#define STRUCTFILME_H

struct Filme {

    friend class Catalogo;

    friend std::istream &operator>>(std::istream &, Filme &);
    friend std::ostream &operator<<(std::ostream &, const Filme &);

    bool operator < (const Filme &);
    bool operator > (const Filme &);
    bool operator == (const Filme &);
    
    std::string titulo;
    std::string produtora;
    double nota;

};

#endif