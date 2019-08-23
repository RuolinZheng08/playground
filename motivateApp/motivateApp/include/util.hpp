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
    time_t mTime;  // unix seconds
    int mNumTok;  // number of tokens
    
    Record(std::string name, time_t seconds, int numTok): mName(name), mTime(seconds), mNumTok(numTok) {}
};

#endif /* util_hpp */
