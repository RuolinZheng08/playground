//
//  main.h
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/16.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef main_h
#define main_h

#include <iostream>
#include <vector>
#include <map>
#include <wx/wx.h>

class MyApp: public wxApp {
public:
    wxFrame *frame;
    bool OnInit();
};

#endif /* main_h */
