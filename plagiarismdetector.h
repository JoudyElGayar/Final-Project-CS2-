#ifndef PLAGIARISMDETECTOR_H
#define PLAGIARISMDETECTOR_H


#include <QString>
#include <QVector>
#include <QtMath>

const int prime = 101;

class PlagiarismDetector {
public:
    PlagiarismDetector(const QString& pattern) : pattern_(pattern), patternLength_(pattern.length()) {}

    // Function to find the percentage of similarity between the text and the pattern
    double findSimilarityPercentage(const QString& text) {
        int textLength = text.length();
        int patternHash = calculateHash(pattern_, patternLength_);
        double similarityCount = 0;

        int textHash = calculateHash(text, patternLength_);
        for (int i = 0; i <= textLength - patternLength_; i++) {
            if (patternHash == textHash && checkStrings(text, i, pattern_)) {
                similarityCount += patternLength_;
            }
            if (i < textLength - patternLength_) {
                textHash = recalculateHash(textHash, text[i], text[i + patternLength_], patternLength_);
            }
        }

        double percentage = (similarityCount / textLength) * 100;
        return percentage;
    }

    // Function to calculate the length of the longest common subsequence between the text and the pattern
    int calculateLCS(const QString& text) {
        int textLength = text.length();

        QVector<QVector<int>> lcsMatrix(textLength + 1, QVector<int>(patternLength_ + 1));

        for (int i = 0; i <= textLength; ++i) {
            for (int j = 0; j <= patternLength_; ++j) {
                if (i == 0 || j == 0)
                    lcsMatrix[i][j] = 0;
                else if (text[i - 1] == pattern_[j - 1])
                    lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1;
                else
                    lcsMatrix[i][j] = qMax(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1]);
            }
        }

        return lcsMatrix[textLength][patternLength_];
    }

private:
    QString pattern_;
    int patternLength_;

    int calculateHash(const QString& str, int length) {
        int hash = 0;
        for (int i = 0; i < length; i++) {
            hash += str[i].unicode() * qPow(prime, length - i - 1);
        }
        return hash;
    }

    int recalculateHash(int oldHash, QChar oldChar, QChar newChar, int length) {
        int newHash = oldHash - oldChar.unicode() * qPow(prime, length - 1);
        newHash = newHash * prime + newChar.unicode();
        return newHash;
    }

    bool checkStrings(const QString& text, int start, const QString& pattern) {
        for (int i = 0; i < pattern.length(); i++) {
            if (text[start + i] != pattern[i])
                return false;
        }
        return true;
    }
};


#endif // PLAGIARISMDETECTOR_H
