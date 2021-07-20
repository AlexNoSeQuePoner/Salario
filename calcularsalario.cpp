#include "calcularsalario.h"

float CalcularSalario::salarioBruto() const
{
    return m_salarioBruto;
}

float CalcularSalario::descuento() const
{
    return m_descuento;
}

float CalcularSalario::salarioNeto() const
{
    return m_salarioNeto;
}

QString CalcularSalario::getJornada()
{
    switch (m_jornada) {
    case 'V':
        return tr("Vespertina");
        break;
    case 'M':
        return tr("Matutina");
        break;
    case 'N':
        return tr("Nocturna");
        break;
    }
    return "N/D";
}

CalcularSalario::CalcularSalario(QObject *parent) : QObject(parent)
{

}

CalcularSalario::CalcularSalario(QString nombre, int horas, char jornada)
{
    m_nombre = nombre;
    m_horas = horas;
    m_jornada = jornada;
}

void CalcularSalario::calcular()
{
    float valorHora = 0;
    switch (m_jornada) {
    case 'V':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'M':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'N':
        valorHora = VALOR_HORA_NOCTURNO;
        break;
    }
    m_salarioBruto = m_horas * valorHora;
    m_descuento = m_salarioBruto * PORCENTAJE_DESCUENTO;
    m_salarioNeto = m_salarioBruto - m_descuento;
}

QString CalcularSalario::resultado()
{
    QString str;
    str = tr("Obrero: ") + m_nombre + "\n";
    str += tr("Horas: ") + QString::number(m_horas) + "\n";
    str += tr("Jornada: ") + getJornada() + "\n";
    str += tr("Salario Bruto: $") +QString::number(m_salarioBruto) + "\n";
    str += tr("Descuento: $") +QString::number(m_descuento) + "\n";
    str += tr("Salario Bruto: $") +QString::number(m_salarioNeto) + "\n\n";
    return str;
}
