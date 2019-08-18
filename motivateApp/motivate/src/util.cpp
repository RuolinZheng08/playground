//
//  util.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "util.hpp"

Record::Record(std::string &name, std::string &description, int num) {
    this->name = name;
    this->description = description;
    this->num = num;
}
