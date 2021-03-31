#include "clases/AnsiColors.h"
#include "clases/Fecha.h"

#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //Fecha fecha;
    cout << "[" << yellow << " Probando la clase fecha en c++ " << default_color << "]" << endl; 
    Fecha fecha;    
    cout << "fecha instance: "          << fecha << endl;
    cout << "[" << cyan << " Formatos de salida disponibles "   << default_color << "]" << endl;
    cout << right << setw(15) << "[" << blue << " Unidades Basicas "   << default_color << "]" << endl;
    cout << right << setw(29) << "getDiaInt(): "            << left << setw(25) << fecha.getDiaInt()        << endl;
    cout << right << setw(29) << "getDiaString(): "         << left << setw(25) << fecha.getDiaString()     << endl;
    cout << right << setw(29) << "getDiaStringWZ(): "       << left << setw(25) << fecha.getDiaStringWZ()   << endl;
    cout << right << setw(29) << "getMesInt(): "            << left << setw(25) << fecha.getMesInt()        << endl;
    cout << right << setw(29) << "getMesStirng(): "         << left << setw(25) << fecha.getMesString()     << endl;
    cout << right << setw(29) << "getMesStringWZ(): "       << left << setw(25) << fecha.getMesStringWZ()   << endl;
    cout << right << setw(29) << "getAnoInt(): "            << left << setw(25) << fecha.getAñoInt()        << endl;
    cout << right << setw(29) << "getAnoString(): "         << left << setw(25) << fecha.getAñoString()     << endl;
    cout << right << setw(29) << "getHoraInt(): "           << left << setw(25) << fecha.getHoraInt()       << endl;
    cout << right << setw(29) << "getHoraString(): "        << left << setw(25) << fecha.getHoraString()    << endl;
    cout << right << setw(29) << "getHoraStringWZ(): "      << left << setw(25) << fecha.getHoraStringWZ()  << endl;
    cout << right << setw(29) << "getAMPMHoraInt(): "       << left << setw(25) << fecha.getAMPMHoraInt()   << endl;
    cout << right << setw(29) << "getMinInt(): "            << left << setw(25) << fecha.getMinInt()        << endl;
    cout << right << setw(29) << "getMinString(): "         << left << setw(25) << fecha.getMinString()     << endl;
    cout << right << setw(29) << "getMinStringWZ(): "       << left << setw(25) << fecha.getMinStringWZ()   << endl;
    cout << right << setw(29) << "getSecInt(): "            << left << setw(25) << fecha.getSecInt()        << endl;
    cout << right << setw(29) << "getSecString(): "         << left << setw(25) << fecha.getSecString()     << endl;
    cout << right << setw(29) << "getSecStringWZ(): "       << left << setw(25) << fecha.getSecStringWZ()   << endl;
    cout << right << setw(29) << "getWeekDayNumberInt(): "  << left << setw(25) << fecha.getWeekDayNumberInt() << endl;
    cout << right << setw(29) << "getWeekDayName(): "       << left << setw(25) << fecha.getWeekDayName()   << endl;
    cout << right << setw(29) << "getMonthName(): "         << left << setw(25) << fecha.getMonthName()     << endl;
    
    cout << right << setw(15) << "[" << blue << " La hora "   << default_color << "]" << endl;
    cout << right << setw(29) << "getClockTimeWZ(): "       << left << setw(25) << fecha.getClockTimeWZ()        << endl;
    cout << right << setw(29) << "getAMPMClockTime(): "     << left << setw(25) << fecha.getAMPMClockTime()      << endl;
    cout << right << setw(29) << "getAMPMClockTimeShort(): "<< left << setw(25) << fecha.getAMPMClockTimeShort() << endl;
    cout << right << setw(29) << "getAMPMHoraInt(): "       << left << setw(25) << fecha.getAMPMHoraInt()        << endl;
    cout << right << setw(29) << "getCurrentAMPMString(): " << left << setw(25) << fecha.getCurrentAMPMString()  << endl;
    cout << right << setw(29) << "getUTCClockTime(): "      << left << setw(25) << fecha.getUTCClockTime()       << endl;

    cout << right << setw(15) << "[" << blue << " Fechas corrientes "   << default_color << "]" << endl;
    cout << right << setw(29) << "getSlashDate(): "             << left << setw(25) << fecha.getSlashDate()           << endl;
    cout << right << setw(29) << "getSlashDateWZ(): "           << left << setw(25) << fecha.getSlashDateWZ()         << endl;
    cout << right << setw(29) << "getSlashDateWShortYear(): "   << left << setw(25) << fecha.getSlashDateWShortYear() << endl;
    cout << right << setw(29) << "getDashDate(): "              << left << setw(25) << fecha.getDashDate()            << endl;
    cout << right << setw(29) << "getDashDateWZ(): "            << left << setw(25) << fecha.getDashDateWZ()          << endl;
    cout << right << setw(29) << "getDashDateWShortYear(): "    << left << setw(25) << fecha.getSlashDateWShortYear()      << endl;
    cout << right << setw(29) << "getReverseDateInt(): "        << left << setw(25) << fecha.getReverseDateInt()   << endl;
    cout << right << setw(29) << "getReverseDateWDash(): "      << left << setw(25) << fecha.getReverseDateWDash()    << endl;
    cout << right << setw(29) << "getReverseDateWDashWZ(): "    << left << setw(25) << fecha.getReverseDateWDashWZ()  << endl;
   // cout << right << setw(29) << "getDashReverseDateWZ(): "     << left << setw(25) << fecha.getDashReverseDateWZ()   << endl;
    cout << right << setw(29) << "getPointDate(): "             << left << setw(25) << fecha.getPointDate()           << endl;
    cout << right << setw(29) << "getPointDateWZ(): "           << left << setw(25) << fecha.getPointDateWZ()         << endl;
    cout << right << setw(29) << "getPointDateWShortDate(): "   << left << setw(25) << fecha.getPointDateWShortYear() << endl;

    cout << right << setw(15) << "[" << blue << " Fechas compuestas "   << default_color << "]" << endl;
    cout << right << setw(29) << "getExtendedDate(): "          << left << setw(25) << fecha.getExtendedDate() << endl;
    cout << right << setw(29) << "getLongDate(): "              << left << setw(25) << fecha.getLongDate() << endl;
    cout << right << setw(29) << "getShortDate(): "             << left << setw(25) << fecha.getShortDate() << endl;
    cout << right << setw(29) << "getDayMonthShort(): "         << left << setw(25) << fecha.getDayMonthShort() << endl;
    cout << right << setw(29) << "getDayMonthShortWYear(): "    << left << setw(25) << fecha.getDayMonthShortWYear() << endl;
    cout << right << setw(29) << "getDaySlashMonth(): "         << left << setw(25) << fecha.getDaySlashMonth() << endl;
    cout << right << setw(29) << "getMonthNameYear(): "         << left << setw(25) << fecha.getMonthNameYear() << endl;
    cout << right << setw(29) << "getTimeStamp(): "             << left << setw(25) << fecha.getTimeStamp() << endl;
    
    return 0;
}



