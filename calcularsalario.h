#ifndef CALCULARSALARIO_H
#define CALCULARSALARIO_H

#include <QObject>

class CalcularSalario : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float salarioBruto READ salarioBruto)
    Q_PROPERTY(float descuento READ descuento)
    Q_PROPERTY(float salarioNeto READ salarioNeto)
private:
    //Constantes
    float const VALOR_HORA_MATUTINO = 5.15;
    float const VALOR_HORA_VESPERTINO = 8.50;
    float const VALOR_HORA_NOCTURNO = 12.65;
    float const PORCENTAJE_DESCUENTO = 0.095;
    // VARIABLE MIEMBRO
    int m_horas;//horas trabajadas
    QString m_nombre;//nombre del trabajador
    char m_jornada;//jornada en la que trabaja [M=matutina, V=Vespertina, N = Nocturna]

    float m_salarioBruto; //valor del salario sin descuento
    float m_descuento; //valor del descuento
    float m_salarioNeto; //valor del salario a recibir

    QString getJornada();

public:
    explicit CalcularSalario(QObject *parent = nullptr);
    CalcularSalario(QString nombre, int horas, char jornada);
    void calcular();
    QString resultado();

    float salarioBruto() const;
    float descuento() const;
    float salarioNeto() const;

signals:

};

#endif // CALCULARSALARIO_H
