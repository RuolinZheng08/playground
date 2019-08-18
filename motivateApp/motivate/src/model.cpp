//
//  model.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "model.hpp"

ListItem::ListItem(std::string name, std::string description, int num) {
    name = name;
    description = description;
    num = num;
}

MyModel::MyModel() {
    // FIXME
    time_t seconds = 1262304000;
    struct tm *tm = localtime(&seconds);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d", tm);
    ListItem *record = new ListItem("LeetCode", "Q10", 2);
    recordMap[std::string(date)].push_back(record);
}
