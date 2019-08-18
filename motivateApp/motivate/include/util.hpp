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

class Record {
public:
    std::string name;
    std::string description;
    int num;  // number of tokens
    
    Record(std::string &name, std::string &description, int num);
};

#endif /* util_hpp */
