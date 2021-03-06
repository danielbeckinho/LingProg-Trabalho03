#include "structFilme.h"
#include <vector>
#include <string>

#ifndef CATALOGO_H
#define CATALOGO_H

class Catalogo {
        friend std::ostream &operator<<(std::ostream &, const Catalogo &);
        friend std::ostream &operator<<(std::ostream &, const Filme &);

    public:
        //sobrecarregar op += pra Filme e vector de Filme
        Catalogo& operator += (Filme &);
        Catalogo& operator += (std::vector<Filme> &);

        //sobrecarregar op -=
        Catalogo& operator -= (const std::string &); // pode usar o metodo erase de vector

        //sobrecarregar op de busca c/ () - usar nome p/ buscar; retorna ponteiro pro filme ou NULL
        Filme* operator() (const std::string);

        //sobrecarregar op de editar dados filme c/ () - pode mudar prod ou nota, pra mudar nome tem que deletar e reinserir
        Catalogo& operator() (std::string, std::string, bool);
        Catalogo& operator() (std::string, double);
    
        Filme *filmeNotaMaisAlta(); 

        const int getNumMaxFilmes();

        const std::vector<Filme> getVectorCatalogo() const;
        const std::vector<Filme> getVectorCatalogo();
        
    private:
        static const int numMaxFilmes{3};
        std::vector<Filme> vectorCatalogo;
        Catalogo& inserirFilme (Filme &); //insere o filme ordenadamente no catalogo


};

#endif