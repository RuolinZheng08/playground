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
#include <wx/wx.h>
#include "util.hpp"

const int SMALL_SPACING = 3;
const std::string TOKEN = "☆";
const std::string TOKEN_USED = "★";
enum {
    BTN_ADD = wxID_HIGHEST + 1
};

class MyFrame: public wxFrame {
public:
    MyFrame();
    
private:
    wxBoxSizer *mSizer;
    wxBoxSizer *mRecordSizer;
};

class MyView {
public:
    MyFrame *mFrame;
    
    MyView();
};

#endif /* view_hpp */