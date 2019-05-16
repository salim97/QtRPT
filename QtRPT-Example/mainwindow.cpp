#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qtrpt.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int rows = ui->tableWidget->rowCount();

    QtRPT *report = new QtRPT(this) ;
//    report->loadReport("c:/Archive/GITHUB/SUDO-DEV/ProTeam_Stock/Templates/BonDeReception.xml");
    report->loadReport(":/Report Resource/Facture.xml");
    report->recordCount.append(rows);
    connect(report, &QtRPT::setValue, [&](int recNo,
            QString paramName, QVariant &paramValue, const int reportPage){
        if(paramName == "NAME") paramValue = "Bon De Réception" ;
        if(paramName == "COMP_TITLE") paramValue = "comp_title" ;
        if(paramName == "ADDRESS") paramValue = "address" ;
        if(paramName == "CAPITAL") paramValue = "capital_social" ;
        if(paramName == "NRC") paramValue = "n_rc" ;
        if(paramName == "NAI") paramValue = "n_ai" ;
        if(paramName == "NIF") paramValue = "n_if" ;
        if(paramName == "NIS") paramValue = "n_is" ;

        if (paramName == "PRIX_UNIT_H_T") {
            if (ui->tableWidget->item(recNo,0) == 0) return;
            paramValue = ui->tableWidget->item(recNo,0)->text();
        }
        if (paramName == "DESIGNATION") {
            if (ui->tableWidget->item(recNo,1) == 0) return;
            paramValue = ui->tableWidget->item(recNo,1)->text();
        }
        if (paramName == "QUANTITE") {
            if (ui->tableWidget->item(recNo,2) == 0) return;
            paramValue = ui->tableWidget->item(recNo,2)->text();
        }

    });
    report->printExec();

}
