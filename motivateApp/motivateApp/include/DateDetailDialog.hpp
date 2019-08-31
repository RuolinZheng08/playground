//
//  DateDetailDialog.hpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/25.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef DateDetailDialog_hpp
#define DateDetailDialog_hpp

#include <stdio.h>
#include "util.hpp"

class DateDetailDialog: public wxDialog {
public:
    DateDetailDialog(wxWindow *parent, std::string date, std::vector<Record> records);
};

#endif /* DateDetailDialog_hpp */
