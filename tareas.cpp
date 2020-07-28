#include "tareas.h"
#include "ui_tareas.h"
#include "principal.h"

#include <QDate>
#include <QMessageBox>

Tareas::Tareas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tareas)
{
    ui->setupUi(this);
    ui->inAlta->setChecked(true);
}

QString Tareas::nombre() const
{
    return ui->inNombre->text();
}

QDate Tareas::fecha() const
{
    return ui->inFecha->date();
}

QString Tareas::tipo() const
{
    return ui->inTipo->text();
}

int Tareas::prioridad() const
{
    int prioridad=0;
    //Obtener Prioridad
    if(ui->inAlta->isChecked()){
        prioridad=1;
    }else if(ui->inMedia->isChecked()){
        prioridad=2;
    }else if(ui->inBaja->isChecked()){
        prioridad=3;
    }
    return prioridad;
}

void Tareas::validarDatos()
{
    QString nombre= ui->inNombre->text();
    QString tipo=ui->inTipo->text();

    if(nombre== ""){
        ui->inNombre->setStyleSheet("background-color: red");
    }else{
        ui->inNombre->setStyleSheet("background-color: green");
    }
    if(tipo==""){
        ui->inTipo->setStyleSheet("background-color: red");
    }else{
        ui->inTipo->setStyleSheet("background-color: green");
    }
}
Tareas::~Tareas()
{
    delete ui;
}


/*void Tareas::on_cmdAgregar_clicked()
{   
    QString nombre= ui->inNombre->text();
    QDate fecha= ui->inFecha->date();
    int prioridad=0;
    QString tipo=ui->inTipo->text();

    validarDatos();

    //Obtener Prioridad
    if(ui->inAlta->isChecked()){
        prioridad=1;
    }else if(ui->inMedia->isChecked()){
        prioridad=2;
    }else if(ui->inBaja->isChecked()){
        prioridad=3;
    }

    if(nombre==""||tipo==""){
        QMessageBox vacio;
        vacio.setText("No se han ingresado ciertos datos porfavor verifique");
        vacio.setIcon(QMessageBox::Warning);
        vacio.exec();
        return;
    }else{
        Principal *tabla= new Principal;
        tabla->tabla(nombre,fecha,tipo,prioridad);

        tabla->show();
    }






}*/

void Tareas::on_buttonBox_accepted()
{
    validarDatos();
    QString nombre= ui->inNombre->text();
    QString tipo= ui->inTipo->text();
    if(nombre==""||tipo==""){
        QMessageBox vacio;
        vacio.setText("No se han ingresado ciertos datos porfavor verifique");
        vacio.setIcon(QMessageBox::Warning);
        vacio.exec();
        return;
    }else{
        accept();
    }

}

void Tareas::on_buttonBox_rejected()
{
    reject();
}
