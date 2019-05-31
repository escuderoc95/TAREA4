#include "mainwindow.h"
#include "ui_mainwindow.h"


double NUM1;
bool NUM2=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->boton_0,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_1,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_2,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_3,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_4,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_5,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_6,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_7,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_8,SIGNAL(released()),this,SLOT(digito_oprimido()));
    connect(ui->boton_9,SIGNAL(released()),this,SLOT(digito_oprimido()));

    connect(ui->suma,SIGNAL(released()),this,SLOT(operaciones()));
    connect(ui->resta,SIGNAL(released()),this,SLOT(operaciones()));
    connect(ui->multiplicacion,SIGNAL(released()),this,SLOT(operaciones()));
    connect(ui->division,SIGNAL(released()),this,SLOT(operaciones()));

    ui->suma->setCheckable(true);
    ui->resta->setCheckable(true);
    ui->multiplicacion->setCheckable(true);
    ui->division->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digito_oprimido()
{
    QPushButton * button = (QPushButton*)sender();


    double labelNumber;
    QString newlabel;

    if ((ui->suma->isChecked() ||ui->resta->isChecked() || ui->multiplicacion->isChecked() ||
         ui->division->isChecked()) && (!NUM2))
    {
        labelNumber = button->text().toDouble();
        NUM2=true;
         newlabel = QString::number(labelNumber,'g',15);
         ui->lcd->QLCDNumber::mode();
    }
    else
    {
        if(ui->label->text().contains('.') && button->text()=="0")
        {
            newlabel=ui->label->text()+button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newlabel = QString::number(labelNumber,'g',15);
        }
    }
    ui->label->setText(newlabel);
    ui->lcd->display(newlabel);

}
void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text()+".");
    ui->lcd->display(".");
}

void MainWindow::on_pushButton_clear_released()
{
    ui->suma->setChecked(false);
    ui->resta->setChecked(false);
    ui->multiplicacion->setChecked(false);
    ui->division->setChecked(false);

    NUM2=false;

    ui->label->setText(("0"));
    ui->lcd->display(0);
}

void MainWindow::on_pushButton_equal_released()
{
    double labelNumber, secondNum;
    QString newlabel;

   // secondNum= ui->label->text().toDouble();
    secondNum=ui->lcd->value();

    if(ui->suma->isChecked())
    {
        labelNumber = NUM1+secondNum;
        newlabel=QString::number(labelNumber,'g',15);
       // ui->label->setText(newlabel);
        ui->lcd->display(newlabel);
        ui->suma->setChecked(false);
        QMessageBox msgBox;
         msgBox.setText("Operacion Realizada");
         msgBox.exec();
    }
    else if(ui->resta->isChecked())
    {
        labelNumber=NUM1-secondNum;
        newlabel=QString::number(labelNumber,'g',15);
       // ui->label->setText(newlabel);
        ui->lcd->display(newlabel);
        ui->resta->setChecked(false);
        QMessageBox msgBox;
         msgBox.setText("Operacion Realizada");
         msgBox.exec();
    }
    else if(ui->multiplicacion->isChecked())
    {
        labelNumber=NUM1*secondNum;
        newlabel=QString::number(labelNumber,'g',15);
      //  ui->label->setText(newlabel);
        ui->lcd->display(newlabel);
        ui->multiplicacion->setChecked(false);
        QMessageBox msgBox;
         msgBox.setText("Operacion Realizada");
         msgBox.exec();
    }
    else if(ui->division->isChecked())
    {
        labelNumber=NUM1/secondNum;
        newlabel=QString::number(labelNumber,'g',15);
       // ui->label->setText(newlabel);
        ui->lcd->display(newlabel);
        ui->division->setChecked(false);
        QMessageBox msgBox;
         msgBox.setText("Operacion Realizada");
         msgBox.exec();
    }

    NUM2=false;

}

void MainWindow::operaciones()
{
    QPushButton * button = (QPushButton*)sender();

    //NUM1=ui->label->text().toDouble();
    //NUM1=ui->lcd->checkOverflow(NUM1);
    NUM1=ui->lcd->value();

    button->setChecked(true);
}
