//
//  util.hpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef util_hpp
#define util_hpp

#include <stdio.h>
#include <wx/wx.h>
#include <string>
#include <vector>
#include <map>

std::string timeToDate(time_t seconds);

class Record {
public:
    std::string mName;
    std::string mDesc;
    int mNumTok;  // number of tokens
    
    Record(std::string &name, std::string &description, int numTok): mName(name), mDesc(description), mNumTok(numTok) {}
};

class History: public Record {
public:
    time_t mTime;  // unix seconds
    
    History(std::string &name, std::string &description, int numTok, time_t seconds): Record(name, description, numTok), mTime(seconds) {}
};

#endif /* util_hpp */
