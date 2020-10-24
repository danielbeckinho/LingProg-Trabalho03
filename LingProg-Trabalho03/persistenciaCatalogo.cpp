#include "catalogo.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

static const std::string fileName{"catalogo.txt"};

void outputCatalogoToFile(const Catalogo &catalogo) {
    std::ofstream out_file;
    out_file.open(fileName);

    out_file.write((char*)&catalogo,sizeof(catalogo));
    out_file.close();

}

Catalogo inputCatalogoFromFile(Catalogo &catalogo) {
    if (check_file(fileName)) {
        std::ifstream in_file;
        in_file.open(fileName);

        in_file.read((char*)&catalogo,sizeof(catalogo));
    }
    
    return catalogo;
}

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

