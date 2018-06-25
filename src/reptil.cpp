#include "../include/reptil.h"
#include <string>

bool Reptil::getVenenoso(){return m_venenoso;}
void Reptil::setVenenoso(bool venenoso){m_venenoso = venenoso;}
std::string Reptil::getTipo_veneno(){return m_tipo_veneno;}
void Reptil::setTipo_veneno(std::string tipo_veneno){m_tipo_veneno = tipo_veneno;}