#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    void inicializarWidgets();
    //void tabla(QString nombre,QDate fecha,QString tipo, int prioridad);
    //void mostrarTabla();

private slots:
    void on_actionAgregar_triggered();
    void on_actionAcerca_de_triggered();

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
