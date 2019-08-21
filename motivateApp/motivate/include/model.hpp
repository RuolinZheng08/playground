//
//  model.h
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef model_h
#define model_h

#include <string>
#include <vector>
#include <map>
#include <wx/wx.h>
#include <sqlite3.h>
#include "util.hpp"

const std::string dbFileName = "motivate.db";
const std::string historyTableGained = "historyTableGained";
const std::string historyTableSpent = "historyTableSpent";
const std::string recordTableGained = "recordTableGained";
const std::string recordTableSpent = "recordTableSpent";

class MyModel {
public:
    // maps date to recordList
    std::map<std::string, std::vector<Record>> recordMap;
    std::vector<Record> achievements;
    std::vector<Record> wishes;
    int numUsed;  // the number of used tokens
    
    MyModel();  // open and load from database
    ~MyModel();  // close database
    
private:
    void openDB();  // create tables if not exist
    void closeDB();
    void removeDB();
    
    void insertHistoryGained();
    void insertHistorySpent();
    void insertRecordGained();  // achievements
    void insertRecordSpent();  // wish list
};

#endif /* model_h */
