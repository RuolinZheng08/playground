//
//  util.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "util.hpp"

std::string timeToDate(time_t seconds) {
    struct tm *tm = localtime(&seconds);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d", tm);
    return std::string(date);
}

Record::Record(std::string &name, std::string &description, int numTok) {
    this->name = name;
    this->description = description;
    this->numTok = numTok;
}
