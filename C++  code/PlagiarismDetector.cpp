//
//  PlagiarismDetector.cpp
//  project 7
//
//  Created by Khaled  Nana  on 12/05/2023.
//

#include "PlagiarismDetector.hpp"
   

    // Function to find the percentage of similarity between the text and the pattern
//    double PlagiarismDetector::findSimilarityPercentage(const std::string& text) {
//    int textLength = text.length();
//    int patternHash = calculateHash(pattern_, patternLength_);
//    double similarityCount = 0;
//
//    int textHash = calculateHash(text, patternLength_);
//    for (int i = 0; i <= textLength - patternLength_; i++) {
//        if (patternHash == textHash && checkStrings(text, i, pattern_)) {
//            similarityCount += patternLength_;
//        }
//        if (i < textLength - patternLength_) {
//            textHash = recalculateHash(textHash, text[i], text[i + patternLength_], patternLength_);
//        }
//    }
//
//    double percentage = (similarityCount / textLength) * 100;
//    return percentage;
//}


    // Function to calculate the length of the longest common subsequence between the text and the pattern
//int PlagiarismDetector::calculateLCS(const string& text) {
//    int textLength = text.length();
//
//    vector<vector<int> > lcsMatrix(textLength + 1, vector<int>(patternLength_ + 1));
//
//    for (int i = 0; i <= textLength; ++i) {
//        for (int j = 0; j <= patternLength_; ++j) {
//            if (i == 0 || j == 0)
//                lcsMatrix[i][j] = 0;
//            else if (text[i - 1] == pattern_[j - 1])
//                lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1;
//            else
//                lcsMatrix[i][j] = max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1]);
//        }
//    }
//
//    return lcsMatrix[textLength][patternLength_];
//}




    int PlagiarismDetector::calculateHash(const string& str, int length) {
        int hash = 0;
        for (int i = 0; i < length; i++) {
            hash += str[i] * pow(prime, i);
        }
        return hash;
    }

    int PlagiarismDetector::recalculateHash(int oldHash, char oldChar, char newChar, int length) {
        int newHash = oldHash - oldChar;
        newHash /= prime;
        newHash += newChar * pow(prime, length - 1);
        return newHash;
    }

    bool PlagiarismDetector::checkStrings(const string& text, int start, const string& pattern) {
        for (int i = 0; i < patternLength_; i++) {
            if (text[start + i] != pattern[i]) {
                return false;
            }
        }
        return true;
    }

