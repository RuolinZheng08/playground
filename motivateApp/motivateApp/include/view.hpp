//
//  view.hpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef view_hpp
#define view_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include "util.hpp"
#include "MyPane.hpp"
#include "AddRecordDialog.hpp"
#include "DateDetailDialog.hpp"

class MyView {
public:
    MyPane *mPane;
    
    MyView();
};

#endif /* view_hpp */
