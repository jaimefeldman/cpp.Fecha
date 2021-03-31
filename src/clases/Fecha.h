/************************************************************************************************\
    string  getExtendedDateWT();

        NOMBRE: Fecha

        AUTOR:  Jaime Andrés Feldman B., (jimix)

        FECHA:  viernes, 26 de marzo de 2021 a las 09:44 hrs.

        DESCRIPCIÓN:
            Clase Fecha, crea instancias que reprensentan una fecha. 
            por defecto la fecha es la del dia actual. 
            Se puden crear instancias con fechas personalizadas.
            La clase defuelve la fecha en diferentes formatos.

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

#include <string>
#include <ostream>
#include <array>

#include "StringUtils.h"

using namespace std;


class Fecha {
private:
    int dia     {0};
    int mes     {0};
    int año     {0};
    int hora    {0};
    int min     {0};
    int sec     {0};
     
    string AMPMString      {""};
    int    AMPMHora        {0};
    int    numeroDiaSemana {0};

    // estructura para almacenar tiempo unix
    // usada para obtener el dia y la hora actual.
    struct tm *time_struct_ptr  {nullptr};

    const array<string, 7>   nombre_dias  = {"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado"};
    const array<string, 12>  nombre_meses = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    enum timeZoneEnum {LOCAL, UTC};
    
    timeZoneEnum timeZone = LOCAL;
    
    void setCurrentDate(timeZoneEnum);
     
public:
    Fecha();
    
    string getDiaString();
    string getMesString();
    string getAñoString();
    string getHoraString();
    string getMinString();
    string getSecString(); 

    string getDiaStringWZ();
    string getMesStringWZ();
    string getHoraStringWZ();
    string getMinStringWZ();
    string getSecStringWZ(); 
    
    int getDiaInt();
    int getMesInt();
    int getAñoInt();
    int getHoraInt();
    int getMinInt();
    int getSecInt(); 
   
    friend ostream& operator<<(ostream&, Fecha&);
    //virtual ~Fecha();
    
    string  getClockTimeWZ();
    string  getAMPMClockTime();
    string  getAMPMClockTimeShort();
    string  getWeekDayName();
    int     getWeekDayNumberInt();
    int     getAMPMHoraInt();
    int     getReverseDateInt();
    string  getReverseDateWDash();
    string  getReverseDateWDashWZ();
    string  getExtendedDate();
    string  getLongDate(); 
    string  getShortDate();
    string  getDayMonthShort();
    string  getDayMonthShortWYear();
    string  getDaySlashMonth(); 
    string  getMonthNameYear();
    string  getMonthName();
    string  getSlashDate();
    string  getSlashDateWZ();
    string  getSlashDateWShortYear();
    string  getSlashDayMonth();
    string  getDashDate();
    string  getDashDateWZ();
    string  getDashDateWShortYear();
    string  getDashReverseDateWZ();
    string  getPointDate();
    string  getPointDateWZ();
    string  getPointDateWShortYear();
    string  getCurrentAMPMString();
    string  getTimeStamp(); 
    string  getUTCClockTime();  
};

