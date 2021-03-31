/**********************************************************************
*                Implemantación de la clase Fecha.                    *
*                by Jaime Andrés Feldman B.                           *
*                sábado, 27 de marzo de 2021 a las 23:59              *
**********************************************************************/

#include "Fecha.h"
#include <ctime>

/******************************
*  Constructor predeterinado  *
******************************/
Fecha::Fecha() {
    setCurrentDate(LOCAL);
}

/*************************************************************************
*  setCurrentDate(): establece las variables al dia y la hora acutales.  *
*************************************************************************/
void Fecha::setCurrentDate(timeZoneEnum zone) {
    
   time_t current_time  {time(0)};
   if (zone == LOCAL)
       this->time_struct_ptr = localtime(&current_time);  
   else if (zone == UTC)
       this->time_struct_ptr = gmtime(&current_time);  

   this->dia  = time_struct_ptr->tm_mday;
   this->mes  = time_struct_ptr->tm_mon;
   this->año  = time_struct_ptr->tm_year + 1900;
   this->hora = time_struct_ptr->tm_hour;
   this->min  = time_struct_ptr->tm_min;
   this->sec  = time_struct_ptr->tm_sec;

   this->numeroDiaSemana = time_struct_ptr->tm_wday;

   // se establece AMPM segun la hora.
   switch (this->hora) {
       case 12 ... 23:
           this->AMPMString = "pm";
           break;
       default:
           this->AMPMString = "am";
   }
}

/***********************************************************************
*                      Sobrecarga de operadores                        *
***********************************************************************/
ostream& operator<<(ostream& stream, Fecha& fecha) {
    stream << fecha.getDiaStringWZ() << "/"
           << fecha.getMesStringWZ() << "/"
           << fecha.getAñoString();
    return stream;
}

string Fecha::getDiaString() {
    return to_string(this->dia);
}

string Fecha::getMesString() {
    return to_string(this->mes + 1);
}

string Fecha::getAñoString() {
    return to_string(this->año);
}

string Fecha::getHoraString() {
    return to_string(this->hora);
}

string Fecha::getHoraStringWZ() {
    
    string horaWZ {"0"};
    if (this->hora == 0 || this->hora < 10) 
        horaWZ.append(getHoraString());
    else  
        horaWZ = getHoraString();

    return horaWZ;
}

string Fecha::getMinString() {
    return to_string(this->min);
}

string Fecha::getSecString() {
    return to_string(this->sec);
}

int Fecha::getDiaInt() {
    return this->dia;
}

int Fecha::getMesInt() {
    return this->mes;
}

int Fecha::getAñoInt() {
    return this->año;
}

int Fecha::getHoraInt() {
    return this->hora;
}

int Fecha::getMinInt() {
    return this->min;
}

int Fecha::getSecInt() {
    return this->sec;
}

/*************************************************************************
*  Devuelve el dia del mes con un zero delante si es de un solo digito.  *
*************************************************************************/
string Fecha::getDiaStringWZ() {
    
    string diaStringWZ {"0"}; 
    if (this->dia < 10) 
        return diaStringWZ.append(getDiaString());
    return getDiaString();
}

/*************************************************************************
*  Devuelve el mes del año con un zero delante si es de un solo digito.  *
*************************************************************************/
string Fecha::getMesStringWZ() {

    string mesStirngWZ {"0"};
    if (this->mes < 10) 
        return mesStirngWZ.append(getMesString());
    return getMesString();
}

/********************************************************************************
*  Devuelve los minutos de la hora con un zero delante si es de un solo digito. *
********************************************************************************/
string Fecha::getMinStringWZ() {
    
    string minStirngWZ {"0"};
    if (this->min < 10) 
        return minStirngWZ.append(getMinString());
    return getMinString();
}

/*********************************************************************************
*  Devuelve los segundos de la hora con un zero delante si es de un solo digito. *
*********************************************************************************/
string Fecha::getSecStringWZ() {

    string secStringWZ {"0"};
    if (this->sec < 10)
        return secStringWZ.append(getSecString());
    return getSecString();
}

/**************************************************
*  Devuelve la hora en formato 24hrs. con zeros.  *
**************************************************/
string Fecha::getClockTimeWZ() {
    return getHoraStringWZ() + ":" + getMinStringWZ() + ":" + getSecStringWZ();
}

/***************************************************************
*  devuelve el simbolo PM o AM segun la hora que corresponda.  *
***************************************************************/
string Fecha::getCurrentAMPMString() {
    return this->AMPMString;
}

/*************************************************
*  devuelve como entero la hora en formato am pm  *
*************************************************/
int Fecha::getAMPMHoraInt() {
    switch (this->hora) {
        case 13:
           this->AMPMHora = 1;
            break;
        case 14:
           this->AMPMHora = 2;
            break;
        case 15:
           this->AMPMHora = 3;
            break;
        case 16:
           this->AMPMHora = 4;
            break;
        case 17:
           this->AMPMHora = 5;
            break;
        case 18:
           this->AMPMHora = 6;
            break;
        case 19:
           this->AMPMHora = 7;
            break;
        case 20:
           this->AMPMHora = 8;
            break;
        case 21:
           this->AMPMHora = 9;
            break;
        case 22:
           this->AMPMHora = 10;
            break;
        case 23:
           this->AMPMHora = 11;
           break;
        case 0:
           this->AMPMHora = 12;
           break;
        default:
           this->AMPMHora = this->hora;
    }
    return this->AMPMHora;
}    

/***************************************************
*  devuelve la hora en formato am pm con segundos.  *
***************************************************/
string  Fecha::getAMPMClockTime() {
    return to_string(getAMPMHoraInt()) + ":" + getMinStringWZ() + ":" + getSecStringWZ() + " " + getCurrentAMPMString();
}

/***************************************************
*  devuelve la hora en formato am pm hora minutos.  *
***************************************************/
string  Fecha::getAMPMClockTimeShort() {
    return to_string(getAMPMHoraInt()) + ":" + getMinStringWZ() + " " + getCurrentAMPMString();
}

/******************************************************
*  devuelve el nombre del dia de la semana: Viernes   *
******************************************************/
string Fecha::getWeekDayName() {
    return this->nombre_dias[this->numeroDiaSemana];
}

/**************************************
*  devuelve el nombre del mes: Enero  *
***************************************/
string Fecha::getMonthName() {
    return nombre_meses[this->mes];
}
/*********************************************
*  devuelve el nombre del dia de la semana   *
*********************************************/
int Fecha::getWeekDayNumberInt() {
    return this->numeroDiaSemana;
}

/*************************************************************
*  devuelve una fecha en formato martes, 5 de enero de 1995  *
*************************************************************/
string Fecha::getExtendedDate() {
    return getWeekDayName() + ", " + getLongDate();
}

string Fecha::getLongDate() { 
    return  getDiaString() + " de " + getMonthName() + " de " + getAñoString();
}

/****************************************************
*  devuelve una fecha en formato: mar, 5 ene. 2021  *
****************************************************/
string Fecha::getShortDate() {

    int largo {3};
    StringUtils strUtil;
    if (this->getWeekDayNumberInt() == 3 || this->getWeekDayNumberInt() == 6) largo = 4;
    
    string diaShort = nombre_dias[getWeekDayNumberInt()].substr(0,largo);
    string mesShort = nombre_meses[this->mes].substr(0,3);

    //return strUtil.to_lower(nombre_dias[this->dia]).substr(0,largo) + ". " + strUtil.to_lower(nombre_meses[this->mes]).substr(0,3) + ". " + getAñoString();                      
    return strUtil.to_lower(diaShort) + ", " + getDiaString() + " " + strUtil.to_lower(getMonthName()) + ". " + getAñoString();
}
/********************************************************************
*  devuelve el numero del dia y el nombre acortado del mes: 5 ene.  *
********************************************************************/
string Fecha::getDayMonthShort() {
    return getDiaString() + " " + nombre_meses[this->mes].substr(0,3) + ".";
}

/******************************************************
*  devuelve del nombre del mes y el año.: enero 2021  *
******************************************************/
string Fecha::getMonthNameYear() {
    return getMonthName() + " " + getAñoString(); 
}
/**********************************************************************
*  devuelve el dia el nombre del corto del mes y el año: 5 ene. 2021  *
**********************************************************************/
string Fecha::getDayMonthShortWYear() {
    return getDayMonthShort() + " " + getAñoString();
} 

/****************************************
*  devuelve la fecha con / : 20/3/2021  *
****************************************/
string Fecha::getSlashDate() {
    return getDiaString() + "/" + getMesString() + "/" + getAñoString();
}

/************************************************
*  devuelve la fecha con / y zeros: 20/03/2021  *
************************************************/
string Fecha::getSlashDateWZ() {
    return getDiaStringWZ() + "/" + getMesStringWZ() + "/" + getAñoString();
}

/*************************************************
*  devuelve al fecha en formato dia / mes: 4/11  *
*************************************************/
string Fecha::getDaySlashMonth() {
    return getDiaString() + "/" + getMesString();
}

/*****************************************************
*  devuelve la fecha en invertida con - : 2021-3-10  *
*****************************************************/
string Fecha::getReverseDateWDash() {
    return getAñoString() + "-" + getMesString() + "-" + getDiaString();
}

/*****************************************************************
*  devuelve la fecha invertida con - pero con zeros: 2021-03-10  *
*****************************************************************/
string Fecha::getReverseDateWDashWZ() {
    return getAñoString() + "-" + getMesStringWZ() + "-" + getDiaStringWZ();
}

/*******************************************************************
*  devuelve la fecha invertida toda junta como un entero: 2021310  *
*******************************************************************/
int Fecha::getReverseDateInt() {
    string reverseDateString = getAñoString() + getMesString() + getDiaString();
    return stoi(reverseDateString); 
}

/***************************************************************
*  devuelve la fecha con slashes / con el año corto: 23/04/21  *
***************************************************************/
string Fecha::getSlashDateWShortYear() {
    return getDiaStringWZ() + "/" + getMesStringWZ() + "/" + getAñoString().substr(0,2);
}

/***********************************************
*  devuelve la fecha con dashes - : 23/3/2021  *
***********************************************/
string Fecha::getDashDate() {
    return getDiaString() + "-" + getMesString() + "-" + getAñoString();
}

/******************************************************
*  devuelve la fecha con dashes y zeros : 23/03/2021  *
******************************************************/
string Fecha::getDashDateWZ() {
    return getDiaStringWZ() + "-" + getMesStringWZ() + "-" + getAñoString();
}

/*****************************************************************
*  devuelve la fecha con dashes y zeros y el año corto 23-03-21  *
*****************************************************************/
string Fecha::getDashDateWShortYear() {
    return getDiaStringWZ() + "-" + getMesStringWZ() + "-" + getAñoString().substr(0,2);
}

/****************************************************************
*  devuelve la hora con formato timestamp: 2021-03-10 22:04:33  *
****************************************************************/
string Fecha::getTimeStamp() {
    return getReverseDateWDashWZ() + " " + getClockTimeWZ();
}

/******************************************************
*  devuelve la fecha en formato con punto: 23.5.2021  *
******************************************************/
string Fecha::getPointDate() {
    return getDiaString() + "." + getMesString() + "." + getAñoString();
}

/******************************************************************
*  devuelve la fecha en formato con puntos con zeros: 23.05.2021  *
******************************************************************/
string Fecha::getPointDateWZ() {
    return getDiaStringWZ() + "." + getMesStringWZ() + "." + getAñoString();
}

/******************************************************************
*  devuelve la fecha en formato con punto y año corto: 23.5.2021  *
******************************************************************/
string Fecha::getPointDateWShortYear() {
    return getDiaString() + "." + getMesString() + "." + getAñoString().substr(0,2);
}

/*j*********************************
*  devuelve la hora UTC  22:10:45  *
***********************************/
string Fecha::getUTCClockTime() {
    setCurrentDate(UTC);
    return getHoraStringWZ() + ":" + getMinStringWZ() + ":" + getSecStringWZ();
}

