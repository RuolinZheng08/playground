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

const int SMALL_SPACING = 5;
const int MEDIUM_SPACING = 10;
const int LARGE_SPACING = 15;
const std::string TOKEN_GAINED = "☆";
const std::string TOKEN_SPENT = "★";

// event ids
enum EVT_IDS {
    
};

class MyFrame: public wxFrame {
public:
    MyFrame();
    
private:
    wxBoxSizer *mSizer;
    wxBoxSizer *mRecordSizer;
    
    void OnBtnAdd(wxCommandEvent &event);  // controller
};

class AddRecordDialog: public wxDialog {
public:
    AddRecordDialog();
    
private:
    wxTextCtrl *nameCtrl;
    wxRadioBox *rbTokType;
    wxTextCtrl *numCtrl;
    
    // controller
    void OnNumCtrl(wxKeyEvent &event);
    void OnBtnOk(wxCommandEvent &event);
};

class MyView {
public:
    MyFrame *mFrame;
    
    MyView();
};

#endif /* view_hpp */
