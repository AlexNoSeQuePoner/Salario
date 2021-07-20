#include "principal.h"

#include <QApplication>
#include <QLocale>
#include <QInputDialog>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Crear objeto de idiomas
    QTranslator traduccion;
    // Localizar el archivo que contiene el idioma, con el Qlocale obtiene el idioma del sistema
    traduccion.load(":/Idiomas/Salario_"+ QLocale::system().name() +".qm");
    //Establecer idioma
    a.installTranslator(&traduccion);
    Principal w;
    w.show();

    return a.exec();
}
