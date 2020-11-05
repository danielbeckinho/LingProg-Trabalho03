#include "catalogo.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

static const std::string fileName{"catalogo.txt"};
static const std::string delimiter{"--"};

bool check_file(const std::string &fileName) {
    std::ifstream file(fileName);

    if (!file){
        return false;
    }

    if (file.peek() == EOF){
        return false;
    }

    return true;

}

void outputCatalogoToFile(const Catalogo &catalogo) {
    std::ofstream out_file;
    out_file.open(fileName);
    std::vector<Filme> vectorCat = catalogo.getVectorCatalogo();

    for (auto filme : vectorCat) {
        out_file << filme.titulo << "--"
                << filme.produtora << "--"
                << filme.nota << std::endl;
    }

    out_file.close();

}

Catalogo inputCatalogoFromFile(Catalogo &catalogo) {
    if (check_file(fileName)) {
        std::ifstream in_file;
        in_file.open(fileName);

        if (in_file.is_open()){
            std::string tituloIn;
            std::string produtoraIn;
            double notaIn; 

            std::string buffer;

            Filme filmeIn;

            while (std::getline(in_file, buffer)) {

                size_t pos{0};
                //std::cout<<buffer<<std::endl;

                pos = buffer.find(delimiter);
                tituloIn = buffer.substr(0,pos);
                buffer.erase(0, pos + delimiter.length());
                //std::cout<<tituloIn<<std::endl;

                pos = buffer.find(delimiter);
                produtoraIn = buffer.substr(0, pos);
                buffer.erase(0, pos + delimiter.length());
                //std::cout<<produtoraIn<<std::endl;

                notaIn = std::stod(buffer);
                //std::cout<<notaIn<<std::endl;

                filmeIn.titulo = tituloIn;
                filmeIn.produtora = produtoraIn;
                filmeIn.nota = notaIn;
                //std::cout<<filmeIn<<std::endl;

                catalogo+= filmeIn;

            }
        }
        in_file.close();
    }
    
    return catalogo;
}


