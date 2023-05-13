//
//  Document.hpp
//  project 7
//
//  Created by Khaled  Nana  on 12/05/2023.
//

#ifndef Document_hpp
#define Document_hpp
#include "bruteForce.hpp"
#include "PlagiarismDetector.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include <stdio.h>
//class Document {
//private:
//     string filePath;
//
//public:
//    Document(const  string& path);
//
//    string readDocumentContents();
//    double checkPlagiarismPercentage(const  string& text);
//};

//class Document {
//private:
//     string filePath; // Path to the text file
//
//public:
//    Document(const  string& path) {
//        filePath = path;
//    }
//
//     string readDocumentContents() {
//         ifstream file(filePath);
//         string contents;
//         string line;
//
//        if (file.is_open()) {
//            while ( getline(file, line)) {
//                contents += line + "\n";
//            }
//            file.close();
//        }
//        else {
//             cout << "Unable to open file: " << filePath <<  endl;
//        }
//
//        return contents;
//    }
//
//    double checkPlagiarismPercentage(const  string& text) {
//         string database = readDocumentContents();
//        bruteForce bf(database);
//        return bf.checkPlagiarismPercentage(text);
//    }
//};


#endif /* Document_hpp */
