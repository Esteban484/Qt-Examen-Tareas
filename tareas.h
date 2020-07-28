#ifndef TAREAS_H
#define TAREAS_H

#include <QDialog>

namespace Ui {
class Tareas;
}

class Tareas : public QDialog
{
    Q_OBJECT

public:
    explicit Tareas(QWidget *parent = nullptr);
    ~Tareas();
    QString nombre()const;
    QDate fecha()const;
    QString tipo()const;
    int prioridad() const;
    void validarDatos();

private slots:
    //void on_cmdAgregar_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Tareas *ui;


};

#endif // TAREAS_H
