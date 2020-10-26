#include "catalogo.h"
#include "structFilme.h"
#include "persistenciaCatalogo.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

Filme instanciaFilme() {
    Filme filme;
    std::cin>>filme;
    return filme;
}

Catalogo programInit(Catalogo &catalogo) { 
    inputCatalogoFromFile(catalogo);
    return catalogo;
}

int programExit(Catalogo &catalogo) {
    outputCatalogoToFile(catalogo);
    return 0;
}

void insereFilme(Catalogo &catalogo) {
    Filme filme = instanciaFilme();
    catalogo+=filme;
}

void insereVetorFilme(Catalogo &catalogo) {
    std::vector<Filme> filmes;
    std::cout<< "Quantos filmes gostaria de inserir? ";
    int numFilmes;
    std::cin>> numFilmes;
    std::cout<< std::endl;

    for (int i{0}; i < numFilmes; i++) {
        filmes.push_back(instanciaFilme());
    }

    catalogo+=filmes;
}

void buscaFilme(Catalogo &catalogo) {
    std::string titulo;
    std::cout<< "Titulo para busca: ";
    std::getline (std::cin,titulo);
    std::cout<< std::endl;

    std::cout<< *catalogo(titulo);
}

void removeFilme(Catalogo &catalogo) {
    std::string titulo;
    std::cout<< "Titulo do filme para remocao: ";
    std::getline (std::cin,titulo);
    std::cout<< std::endl;

    catalogo-=titulo;
}

void editaFilme(Catalogo &catalogo) {
    std::cout<< "Titulo do filme a ser editado: ";
    std::string titulo;
    std::getline (std::cin,titulo);

    std::cout<< "Digite: \n1 - para editar titulo do filme \n2 - para editar o nome da produtora \n3 - para editar a nota do filme \n Opcao: ";
    int choice;
    std::cin>>choice;

    if (choice == 1) { 
        bool mudarTitulo = true;
        std::string novoNome;
        std::cout<< "Novo titulo: ";
        std::getline(std::cin, novoNome);
        std::cout<< std::endl;
        catalogo(titulo,novoNome,mudarTitulo);
    }

    else if (choice == 2) {
        bool mudarTitulo = false;
        std::string novoNome;
        std::cout<< "Nova produtora: ";
        std::getline(std::cin, novoNome);
        std::cout<< std::endl;
        catalogo(titulo,novoNome,mudarTitulo);
    }
    
    else if (choice == 3) { 
        std::cout<< "Nova nota: ";
        double nota;
        std::cin>>nota;
        std::cout<< std::endl;
        catalogo(titulo,nota);
    }

    else {
        std::cout<< "Opcao invalida. Tente novamente" << std::endl;
    }

}

void imprimeFilme(Catalogo &catalogo) {
    std::cout<< "Para imprimir, primeiro busqye pelo filme. \n";
    buscaFilme(catalogo);
}

void imprimeCatalogo(Catalogo &catalogo) {
    std::cout<< catalogo;
}

void buscaFilmeMaiorNota(Catalogo &catalogo) {
    std::cout<< catalogo.filmeNotaMaisAlta();
}



int main() {
    Catalogo catalogo;
    programInit(catalogo);

    int sel{11};
    while (sel != 0) {
        std::cout<< "\n \n \n \n \n \n \n \n \n" << std::endl;
        std::cout<< "   Favor selecionar uma opcao: " << std::endl;
        std::cout<< "1 - Inserir um filme no catalogo. " << "obs: capacidade maxima do catalogo e de "<< catalogo.getNumMaxFilmes() << "."<< std::endl;
        std::cout<< "2 - Inserir filmes no catalogo. " << "obs: capacidade maxima do catalogo e de "<< catalogo.getNumMaxFilmes() << "."<< std::endl;
        std::cout<< "3 - Buscar filme por titulo." << std::endl;
        std::cout<< "4 - Remover filme." << std::endl;
        std::cout<< "5 - Editar titulo, produtora ou nota de um dado filme." << std::endl;
        std::cout<< "6 - Imprime filme" << std::endl;
        std::cout<< "7 - Imprime catalogo completo." << std::endl;
        std::cout<< "8 - Exibe filme com maior nota no catalogo." << std::endl;
        std::cout<< "0 - Sair. \n" << std::endl;
        std::cout<< "Opcao: "; 
        std::cin>>sel;
        std::cout<<std::endl;

        if (sel == 1) {insereFilme(catalogo);}
        
        else if (sel == 2) {insereVetorFilme(catalogo);}

        else if (sel == 3) {buscaFilme(catalogo);}

        else if (sel == 4) {removeFilme(catalogo);}

        else if (sel == 5) {editaFilme(catalogo);} 

        else if (sel == 6) {imprimeFilme(catalogo);}

        else if (sel == 7) {imprimeCatalogo(catalogo);}

        else if (sel == 8) {buscaFilmeMaiorNota(catalogo);}

        else if (sel == 0) {break;} 

        else {std::cout<< "Opcao invalida. Tente novamente." << std::endl;} 
    } 

    programExit(catalogo);

}