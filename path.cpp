#include "path.h"
#include "ui_path.h"
#include "document.h"
#include "plagiarismdetector.h"
#include <QMessageBox>
Path::Path(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Path)
{
    ui->setupUi(this);
}

Path::~Path()
{
    delete ui;
}

void Path::on_pushButton_clicked()
{
    QString filepath=ui->lineEdit->text();
    QString input=ui->lineEdit_2->text();
    Document database(filepath);
    double plagiarism=database.checkPlagiarismPercentage(input);
    PlagiarismDetector detector(database.readDocumentContents());
    int lcsLength=detector.calculateLCS(input);
    double lcsPercentage=(static_cast<double>(lcsLength)/input.length())*100;
    QString lcs=QString::number(lcsPercentage);

    QString x=database.readDocumentContents();

    QString z="Brute Force: "+QString::number(plagiarism)+"%\nLCS: "+lcs+"%\n";
    QMessageBox::information(this,"similarity report",z);
}
/*Technology affects people all over the world. Advances in technology have made our countries safer and our lives easier, they have also negatively affected our lives. Technology have brought us online banking, smart cars, smart TVs, lightning fast computers, and the virtual reality. Also there include cyber warfare, hackers, identity theft, cyber stalking, and a host of other bad things.*/
/*What is technology? Technology is the application of scientific knowledge to the practical aims of human life or, as it is sometimes phrased*/
