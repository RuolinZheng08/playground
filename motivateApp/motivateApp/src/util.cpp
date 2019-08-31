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

std::string getCachePath() {
    char buffer[256];
    // FIXME?
    strcpy(buffer, getenv("HOME"));
    strcat(buffer, "motivateCache.csv");
//    strcpy(buffer, "motivateCache.csv");
    return std::string(buffer);
}
