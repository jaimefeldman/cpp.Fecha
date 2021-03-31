/************************************************************************************************\

        NOMBRE: StringUtils.h

        AUTOR:  Jaime Andrés Feldman B., (jimix)

        FECHA:  lunes, 01 de febrero de 2021 a las 23:19 hrs.

        DESCRIPCIÓN:
              Utilidad para strings en C++
              - Devuelve strings modificados en: to_upper, to_lower, capitalize.
              - Verifica si es numerico un char char o string.
              - split divide una casena string en un vector de strings separados.

        LICENCIA:
           Copyright © 2021 Jaime Andrés Feldman B.
           
           Permission is hereby granted, free of charge, to any person obtaining
           a copy of this software and associated documentation files (the "Software"),
           to deal in the Software without restriction, including without limitation
           the rights to use, copy, modify, merge, publish, distribute, sublicense,
           and/or sell copies of the Software, and to permit persons to whom the
           Software is furnished to do so, subject to the following conditions:
           
           The above copyright notice and this permission notice shall be included
           in all copies or substantial portions of the Software.
           
           THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
           EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
           OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
           IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
           DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
           TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
           OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
            

\************************************************************************************************/

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringUtils
{
public:
    StringUtils() = default;
    string  to_upper(string);
    string  to_lower(string);
    string  capitalize(string);
    bool    isNumber(string); 
    bool    isNumber(char);
    const   vector<string> split(const string&, const char&);
};

