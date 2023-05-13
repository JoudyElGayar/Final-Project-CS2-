#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
#include "bruteForce.hpp"
#include "Document.hpp"
#include "PlagiarismDetector.hpp"
 // A prime number used for hashing

class bruteForce {
private:
    string database; // The paragraph database

public:
    bruteForce(const  string& db) {
        database = db;
    }

    int calculateHammingDistance(const  string& str1, const  string& str2) {
        int distance = 0;
        int length =  min(str1.length(), str2.length());

        for (int i = 0; i < length; i++) {
            if (str1[i] != str2[i])
                distance++;
        }

        distance +=  abs(int(str1.length() - str2.length()));

        return distance;
    }

    double checkPlagiarismPercentage(const  string& text) {
        int textLength = text.length();
        int databaseLength = database.length();

        int minLength =  min(textLength, databaseLength);

        int distance = calculateHammingDistance(text, database.substr(0, minLength));

        double plagiarismPercentage = (static_cast<double>(textLength - distance) / textLength) * 100;
        return plagiarismPercentage;
    }
};

class Document {
private:
     string filePath; // Path to the text file

public:
    Document(const  string& path) {
        filePath = path;
    }

     string readDocumentContents() {
         ifstream file(filePath);
         string contents;
         string line;

        if (file.is_open()) {
            while ( getline(file, line)) {
                contents += line + "\n";
            }
            file.close();
        }
        else {
             cout << "Unable to open file: " << filePath <<  endl;
        }

        return contents;
    }

    double checkPlagiarismPercentage(const  string& text) {
         string database = readDocumentContents();
        bruteForce bf(database);
        return bf.checkPlagiarismPercentage(text);
    }
};

int main() {
    
    Document database("/Users/khalednana/Desktop/ProjectDatabase/Database.txt");
    Document database2("/Users/khalednana/Desktop/ProjectDatabase/Database2.txt");
    Document database3("/Users/khalednana/Desktop/ProjectDatabase/Database3.txt");
    Document database4("/Users/khalednana/Desktop/ProjectDatabase/Database4.txt");
    
    Document input("/Users/khalednana/Desktop/ProjectDatabase/input.txt");
    
    PlagiarismDetector detector(database.readDocumentContents());
    cout<<"Plagiarism percentage (rabinKarp): "<<detector.findSimilarityPercentage(input.readDocumentContents())<<endl;
    int lcsLength =detector.calculateLCS(input.readDocumentContents());
    double lcsPercentage = (static_cast<double>(lcsLength) / input.readDocumentContents().length()) * 100;
    cout << "Similarity Percentage (LCS): " << lcsPercentage << "%" << endl;
    
    double plagiarismPercentage = database.checkPlagiarismPercentage(input.readDocumentContents());
     cout << "Plagiarism percentage (bruteForce) " << plagiarismPercentage << "%" <<  endl;
    
//    PlagiarismDetector detector2(database2.readDocumentContents());
//    cout<<"Plagiarism percentage (rabinKarp) 2 : "<<detector2.findSimilarityPercentage(input.readDocumentContents())<<endl;
//    int lcsLength2 =detector2.calculateLCS(input.readDocumentContents());
//    double lcsPercentage2 = (static_cast<double>(lcsLength2) / input.readDocumentContents().length()) * 100;
//    cout << "Similarity Percentage (LCS) 2: " << lcsPercentage2 << "%" << endl;
//
//     plagiarismPercentage = database2.checkPlagiarismPercentage(input.readDocumentContents());
//     cout << "Plagiarism percentage (bruteForce) 2 " << plagiarismPercentage << "%" <<  endl;


    return 0;
}
