/**********************************************************************
*                    StringUtils implementación                       *
*               martes, 02 de febrero de 2021 a las 17:14             * 
*               by Jaime Andrés Feldman B.                            *
**********************************************************************/

#include "StringUtils.h"

using namespace std;

//Todo a mayusculas.
string StringUtils::to_upper(string data) {

    std::for_each(data.begin(), data.end(), [](char & c) {
        c = ::toupper(c);
    });
    return data;
}
// Todo a minusculas.
string StringUtils::to_lower(string data) {

    std::for_each(data.begin(), data.end(), [](char & c) {
        c = ::tolower(c);
    });
    return data;

}
// La Primera letra del string es mayuscula.
string StringUtils::capitalize(string data) {

    data[0] = toupper(data[0]);
    for (int i = 1; i < data.size(); i++) {
       data[i] = tolower(data[i]); 
    }
    return data;
}

// Devuelve True si el parametro string nunerico.
bool StringUtils::isNumber(string str) {

    if (str.empty()) return false;
    for (int i = 0; i < str.length(); i++) 
        if (isdigit(str[i]) == false) 
            return false;
        
    return true;
}

// Sobrecarga, detecta si es numero o caracter, argumento Char.
bool StringUtils::isNumber(char ch) {
    
    if (ch == '\0') return false;
        if (isdigit(ch))
            return true;
    
    return false;
}
// Diviendo un string en un vector de strings.
const vector<string> StringUtils::split(const string& stringValue, const char& chValue) {

    string buff {""};  
    vector<string> stringVector;
    for (auto ch : stringValue) {
       if (ch != chValue)
           buff += ch;
       else if (ch == chValue && buff != "") {
           stringVector.push_back(buff);
           buff = "";
       }
    }
    stringVector.push_back(buff);
    return stringVector;
}
