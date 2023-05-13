#include "startingwindow.h"
#include "ui_startingwindow.h"
#include <QMessageBox>
#include "plagiarismdetector.h"
#include "document.h"
#include "bruteforce.h"
StartingWindow::StartingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartingWindow)
{
    ui->setupUi(this);
}

StartingWindow::~StartingWindow()
{
    delete ui;
}

void StartingWindow::on_pushButton_clicked()
{
    QString x;
    x=ui->lineEdit->text();
    Document database("/Users/khalednana/Desktop/ProjectDatabase/Database.txt");
    double bfpercentage=database.checkPlagiarismPercentage(x);
    QString z=QString::number(bfpercentage);

    PlagiarismDetector detector(database.readDocumentContents());
    int lcsLength=detector.calculateLCS(x);
    double lcsPercentage=(static_cast<double>(lcsLength)/x.length())*100;
    QString lcs=QString::number(lcsPercentage);

 //   PlagiarismDetector rkdetector(database.readDocumentContents());
   // double rkPercentage=rkdetector.findSimilarityPercentage(x);
    //QString rk=QString::number(rkPercentage);



//    QString finalOutput="Brute Force "+z+"%\n"+"Rabin Karp: "+rk+"%\n"+"LCS: "+lcs+"%\n"; "LCS: "+lcs+"%\n"+"Rabin Karp: "+rk+"%\n"
QString finalOutput="Brute Force "+z+"%\n"+"LCS: "+lcs+"%\n";
QMessageBox::information(this,tr("PG"),finalOutput);
}

