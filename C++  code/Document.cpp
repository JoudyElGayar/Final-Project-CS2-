//
//  Document.cpp
//  project 7
//
//  Created by Khaled  Nana  on 12/05/2023.
//

#include "Document.hpp"

//    Document::Document(const  string& path) {
//        filePath = path;
//    }
//
//     string Document::readDocumentContents() {
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
//    double Document::checkPlagiarismPercentage(const  string& text) {
//         string database = readDocumentContents();
//        PlagiarismDetector pE(database);
//        return pE.findSimilarityPercentage(text);
//    }




