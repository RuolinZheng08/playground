//
//  model.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "model.hpp"

MyModel::MyModel() {
    // FIXME
    time_t seconds = 1262304000;
    struct tm *tm = localtime(&seconds);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d", tm);
    std::string name = "LeetCode";
    std::string desc = "Q10";
    Record record = Record(name, desc, 2);
    for (int i = 0; i < 20; i++)
        recordMap[std::string(date)].push_back(record);
}
