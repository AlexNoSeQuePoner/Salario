#include "acerca.h"
#include "ui_acerca.h"
#include <QtDebug>

Acerca::Acerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca)
{
    ui->setupUi(this);
    ui->outVersion->setText(tr("Versión: ") + version);
}

Acerca::~Acerca()
{
    delete ui;
}

void Acerca::on_pushButton_clicked()
{
    close();
}


