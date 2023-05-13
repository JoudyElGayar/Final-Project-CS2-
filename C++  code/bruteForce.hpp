//
//  bruteForce.hpp
//  project 7
//
//  Created by Khaled  Nana  on 12/05/2023.
//

#ifndef bruteForce_hpp
#define bruteForce_hpp

#include "PlagiarismDetector.hpp"
#include "Document.hpp"
#include <iostream>
using namespace std;
#include <stdio.h>
//class bruteForce {
//private:
//    string database; // The paragraph database
//
//public:
//    bruteForce(const  string& db);
//
//    int calculateHammingDistance(const  string& str1, const  string& str2);
//
//    double checkPlagiarismPercentage(const  string& text);
//};

//class bruteForce {
//private:
//    string database; // The paragraph database
//
//public:
//    bruteForce(const  string& db) {
//        database = db;
//    }
//
//    int calculateHammingDistance(const  string& str1, const  string& str2) {
//        int distance = 0;
//        int length =  min(str1.length(), str2.length());
//
//        for (int i = 0; i < length; i++) {
//            if (str1[i] != str2[i])
//                distance++;
//        }
//
//        distance +=  abs(int(str1.length() - str2.length()));
//
//        return distance;
//    }
//
//    double checkPlagiarismPercentage(const  string& text) {
//        int textLength = text.length();
//        int databaseLength = database.length();
//
//        int minLength =  min(textLength, databaseLength);
//
//        int distance = calculateHammingDistance(text, database.substr(0, minLength));
//
//        double plagiarismPercentage = (static_cast<double>(textLength - distance) / textLength) * 100;
//        return plagiarismPercentage;
//    }
//};


#endif /* bruteForce_hpp */
