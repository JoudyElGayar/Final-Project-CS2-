#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H


#include <QString>

class bruteForce {
private:
    QString database; // The paragraph database

public:
    bruteForce(const QString& db) {
        database = db;
    }

    int calculateHammingDistance(const QString& str1, const QString& str2) {
        int distance = 0;
        int length = qMin(str1.length(), str2.length());

        for (int i = 0; i < length; i++) {
            if (str1[i] != str2[i])
                distance++;
        }

        distance += qAbs(str1.length() - str2.length());

        return distance;
    }

    double checkPlagiarismPercentage(const QString& text) {
        int textLength = text.length();
        int databaseLength = database.length();

        int minLength = qMin(textLength, databaseLength);

        int distance = calculateHammingDistance(text, database.left(minLength));

        double plagiarismPercentage = (static_cast<double>(textLength - distance) / textLength) * 100;
        return plagiarismPercentage;
    }
};

#endif // BRUTEFORCE_H
