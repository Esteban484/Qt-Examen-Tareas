#include "principal.h"
#include "ui_principal.h"
#include "tareas.h"
#include "acerca_de.h"

#include <QTableWidget>
#include <QTranslator>
#include <QDate>
#include <QColor>


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    inicializarWidgets();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::inicializarWidgets()
{
    // Colocar cabecera de la tabla
    QStringList cabecera = {" Nombre ", " Tipo "," Fecha "};
    ui->outTareas->setColumnCount(3);
    ui->outTareas->setHorizontalHeaderLabels(cabecera);

}

/*void Principal::tabla(QString nombre, QDate fecha, QString tipo, int prioridad)
{
    int posicion=ui->outTareas->rowCount();
    ui->outTareas->insertRow(posicion);
    //ui->outTareas->setItem(posicion,0,new QTableWidgetItem(numero));
    ui->outTareas->setItem(posicion,0,new QTableWidgetItem(nombre));
    ui->outTareas->setItem(posicion,2,new QTableWidgetItem(fecha.toString()));
    ui->outTareas->setItem(posicion,1,new QTableWidgetItem(tipo));

    //Establecer color de prioridad
    if(prioridad==1){
        for(int i=0;i<3;i++){
            ui->outTareas->item(posicion,i)->setBackgroundColor(Qt::red);
        }
    }else if (prioridad==2) {
        for(int i=0;i<3;i++){
            ui->outTareas->item(posicion,i)->setBackgroundColor(Qt::yellow);
        }
    }else if(prioridad==3){
        for(int i=0;i<3;i++){
            ui->outTareas->item(posicion,i)->setBackgroundColor(Qt::gray);
        }
    }
}*/



void Principal::on_actionAgregar_triggered()
{
    int res;
    Tareas tarea(this);
    tarea.setModal(true);
    res=tarea.exec();
    if(res== QDialog::Rejected){
        return;
    }
    QString nombre=tarea.nombre();
    QDate fecha= tarea.fecha();
    QString tipo= tarea.tipo();

    int posicion=ui->outTareas->rowCount();
    ui->outTareas->insertRow(posicion);
    //ui->outTareas->setItem(posicion,0,new QTableWidgetItem(numero));
    ui->outTareas->setItem(posicion,0,new QTableWidgetItem(nombre));
    ui->outTareas->setItem(posicion,2,new QTableWidgetItem(fecha.toString()));
    ui->outTareas->setItem(posicion,1,new QTableWidgetItem(tipo));

    //Establecer color de prioridad

    if(tarea.prioridad()==1){
        for(int i=0;i<3;i++){
            QColor color(224, 46, 32);
            ui->outTareas->item(posicion,i)->setBackgroundColor(color);
        }
    }else if (tarea.prioridad()==2) {
        for(int i=0;i<3;i++){
            QColor color(224,119,32);
            ui->outTareas->item(posicion,i)->setBackgroundColor(color);
        }
    }else if(tarea.prioridad()==3){
        for(int i=0;i<3;i++){
            QColor color(255, 202, 0);
            ui->outTareas->item(posicion,i)->setBackgroundColor(color);
        }
    }
}





void Principal::on_actionAcerca_de_triggered()
{
    Acerca_de ayuda;
    ayuda.setModal(true);
    ayuda.exec();
}
