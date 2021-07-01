#ifndef ACERCA_H
#define ACERCA_H

#include <QDialog>


namespace Ui {
class Acerca;
}

class Acerca : public QDialog
{
    Q_OBJECT

public:
    explicit Acerca(QWidget *parent = nullptr);
    ~Acerca();


    void setVersion(QString value);

private slots:
    void on_pushButton_clicked();
private:
    Ui::Acerca *ui;
    QString version = "1.0.0";
};

#endif // ACERCA_H
