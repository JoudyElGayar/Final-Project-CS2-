#ifndef DOCUMENT_H
#define DOCUMENT_H


//
//  Document.hpp
//  project 7
//
//  Created by Khaled  Nana  on 12/05/2023.
//

#include "bruteforce.h"

//#include "PlagiarismDetector.h"
//#include <vector>
//#include <fstream>
using namespace std;
#include <stdio.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class Document {
private:
    QString filePath; // Path to the text file

public:
    Document(const QString& path) {
        filePath = path;
    }

    QString readDocumentContents() {
        QString contents;
        QString line;

        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            while (!stream.atEnd()) {
                line = stream.readLine();
                contents += line + "\n";
            }
            file.close();
        } else {
            qDebug() << "Unable to open file:" << filePath;
        }

        return contents;
    }

    double checkPlagiarismPercentage(const QString& text) {
        QString database = readDocumentContents();
        bruteForce bf(database);
        return bf.checkPlagiarismPercentage(text);
    }
};
#endif // DOCUMENT_H
