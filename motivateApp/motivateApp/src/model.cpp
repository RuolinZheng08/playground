//
//  model.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "model.hpp"

MyModel::MyModel() {
    std::ifstream in;
    in.open(PATH);
    if (!in) {
        // create file
        std::ofstream out;
        out.open(PATH);
        out.close();
    } else {
        // read into mRecordMap
        std::string str;
        const char *delim = ",";
        char *tok;
        while (std::getline(in, str)) {
            // parse time,name,numTok
            tok = strtok(const_cast<char*>(str.c_str()), delim);
            time_t seconds = atol(tok);
            tok = strtok(NULL, delim);
            std::string name = std::string(tok);
            tok = strtok(NULL, delim);
            int numTok = atoi(tok);
            
            // construct Record
            std::string time = timeToDate(seconds);
            Record record = Record(seconds, name, numTok);
            mRecordMap[time].push_back(record);
        }
        in.close();
    }
}

void MyModel::addRecord(std::string date, Record record) {
    std::ofstream out;
    out.open(PATH, std::ios_base::app);
    mRecordMap[date].push_back(record);
    out << record.mTime << "," << record.mName << "," << record.mNumTok << "\n";
    out.close();
}
