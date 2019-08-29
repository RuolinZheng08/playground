//
//  model.hpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef model_hpp
#define model_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <fstream>
#include "util.hpp"

class MyModel {
public:
    std::map<std::string, std::vector<Record>> mRecordMap;
    
    MyModel();  // load from data.csv into mRecordMap if file exists
};

#endif /* model_hpp */
