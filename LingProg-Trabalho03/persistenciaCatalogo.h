#ifndef PERSISTENCIACATALOGO_H
#define PERSISTENCIACATALOGO_H

#include "catalogo.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void outputCatalogoToFile(const Catalogo &);

Catalogo inputCatalogoFromFile(Catalogo &);

bool check_file(const std::string &);

#endif