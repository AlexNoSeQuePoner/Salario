#include "principal.h"
#include "ui_principal.h"


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_action_Salir_triggered()
{
    close();
}

void Principal::on_cmdCalcular_clicked()
{
    this->calcular();
}

void Principal::on_action_Calcular_triggered()
{
    this->calcular();
}

void Principal::calcular()
{
    //OBTENER LOS DATOS
    QString nombre = ui->inNombre->text();
    if (nombre.isEmpty()){
        QMessageBox::warning(this, "Salarios", "No has proporcinado el nombre del obrero");
        return;
    }
    int horas = ui->inHoras->value();
    char jornada = '\0';

    if(ui->inMatutino->isChecked()){
        jornada = 'M';
    }else if(ui->inVespertino->isChecked()){
        jornada = 'V';
    }else if(ui->inNocturno->isChecked()){
        jornada = 'N';
    }

    CalcularSalario *objCalculo = new  CalcularSalario(nombre, horas, jornada);
    objCalculo->calcular();

    //mostrar resultados
    ui->outDatos->append(objCalculo->resultado());
    this->borrar();
}

void Principal::borrar()
{
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutino->setChecked(true);
    ui->inNombre->setFocus();
}

void Principal::on_action_Nuevo_triggered()
{
    ui->outDatos->clear();
}

void Principal::on_action_AcercaDe_triggered()
{
    Acerca *acercaDe = new Acerca(this);
    acercaDe->setVersion(VERSION);
    acercaDe->show();
}

void Principal::on_action_Guardar_triggered()
{
    //Crear un objeto QDir a partir del directorio del usuario
    QDir directorio = QDir::home();
    // agregar al path absoluto del objeto, un nombre por defecto
    QString pathArchivo = directorio.absolutePath() + "/Archivo Salario.txt";
    //Abrir un cuadro de dialogo para seleccionar el nombre y ubicacion del archivo
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar Archivo",
                                                    pathArchivo,
                                                    "Archivo de texto (*.txt)");
    // crear el archivo a partir del nombre crado por el cuadro de dialogo
    QFile f(fileName);
    // crear objeto QTextStream (permite escribir sobre el archivo)
    QTextStream out(&f);
    // Intentar abrir el archivo para escribir (si no existe) o agregar texto (si existe)
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append)){
        //Si no se puede abrir, sale una advertencia
        QMessageBox::warning(this, "Salarios", "No se puede abrir el archivo" + fileName);
        //Salir
        return;
    }
    out << ui->outDatos->toPlainText() << endl;
}

void Principal::on_actionA_brir_triggered()
{
    QDir directorio = QDir::home();
    // agregar al path absoluto del objeto, un nombre por defecto
    QString pathArchivo = directorio.absolutePath();
    //Abrir un cuadro de dialogo para seleccionar el nombre y ubicacion del archivo
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir Archivo",
                                                    pathArchivo,
                                                    "Archivo de texto (*.txt)");
    QFile f(fileName);
    QTextStream in(&f);

    if(!f.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this, "Salarios", "No se puede abrir el archivo");
        return;
    }
    while(!in.atEnd()){
    ui->outDatos->append(in.readLine());
    }
    f.close();
}
