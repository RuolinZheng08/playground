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

class ListItem {
public:
    std::string name;
    std::string description;
    int num;  // number of tokens
    
    ListItem(std::string name, std::string description, int num);
};

class MyModel {
public:
    // maps date to recordList
    std::map<std::string, std::vector<ListItem *>> recordMap;
    std::vector<ListItem *> achievements;
    std::vector<ListItem *> wishes;
    
    MyModel();
};

#endif /* model_h */
