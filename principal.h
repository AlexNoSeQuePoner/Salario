#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "calcularsalario.h"
#include "acerca.h"

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>


QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_action_Salir_triggered();

    void on_cmdCalcular_clicked();

    void on_action_Calcular_triggered();

    void on_action_Nuevo_triggered();

    void on_action_AcercaDe_triggered();

    void on_action_Guardar_triggered();

    void on_actionA_brir_triggered();

private:
    Ui::Principal *ui;
    void calcular();
    void borrar();
};
#endif // PRINCIPAL_H
