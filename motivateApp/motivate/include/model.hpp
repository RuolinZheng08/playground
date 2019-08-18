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
#include "util.hpp"

class MyModel {
public:
    // maps date to recordList
    std::map<std::string, std::vector<Record>> recordMap;
    std::vector<Record> achievements;
    std::vector<Record> wishes;
    
    MyModel();
};

#endif /* model_h */
