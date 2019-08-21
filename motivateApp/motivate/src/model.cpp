//
//  model.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "model.hpp"

MyModel::MyModel() {
    openDB();
//    numUsed = 103;
//
//    // map
//    time_t seconds = 1262304000;
//    std::string name = "LeetCode";
//    std::string desc = "Q10";
//    Record record = Record(name, desc, 2);
//    for (int i = 0; i < 100; i++)
//        recordMap[timeToDate(seconds)].push_back(record);
//
//    time_t seconds2 = 1272339000;
//    std::string name2 = "LeetCode";
//    std::string desc2 = "Q110";
//    Record record2 = Record(name2, desc2, 4);
//    for (int i = 0; i < 10; i++)
//        recordMap[timeToDate(seconds2)].push_back(record2);
//
//    // list
//    std::string name3 = "draw";
//    std::string desc3 = "anime";
//    Record record3 = Record(name3, desc3, 3);
//    for (int i = 0; i < 15; i++)
//        achievements.push_back(record3);
}

void MyModel::openDB() {
    sqlite3 *db;
    int rc;
    rc = sqlite3_open(dbFileName.c_str(), &db);
    if (rc) {
        sqlite3_close(db);
        return;
    }
    
    std::string cmdCreate = "CREATE TABLE IF NOT EXISTS ";
    std::string cmdHistory = "(time INT, name STRING, desc STRING, numTok INT);";
    
//    wxMessageOutputDebug().Printf(err);
//
//    std::string cmd = "CREATE "
//
//    rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
//    29    if( rc!=SQLITE_OK ){
//        30      fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        31      sqlite3_free(zErrMsg);
//        32    }
//    33    sqlite3_close(db);
}
