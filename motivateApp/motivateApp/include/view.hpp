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
#include <wx/wrapsizer.h>
#include <vector>
#include <map>
#include <string>
#include "util.hpp"

const int SMALL_SPACING = 5;
const int MEDIUM_SPACING = 15;
const int LARGE_SPACING = 30;
const std::string TOKEN_GAINED = "☆";
const std::string TOKEN_SPENT = "★";

// event ids
enum EVT_IDS {
    
};

class MyPane: public wxScrolledWindow {
public:
    MyPane(wxWindow *parent);
    int mNumUnusedTokens;  // len of mUnusedTokens
    
    void DrawRecordGained(std::string date, Record record);
    void DrawNumSpent(unsigned int num);
    
private:
    wxBoxSizer *mPaneSizer;
    wxStaticText *mNumUnusedTxt;
    std::map<std::string, wxWrapSizer *> mDateSizerMap;
    // gained and not yet spent
    std::vector<wxStaticText *> mUnusedTokens;
    
    void DrawDate(std::string date);
    void DrawTokensGained(wxSizer *sizer, int numTok);
    
    // controller
    void OnBtnAdd(wxCommandEvent &event);
    void OnBtnDetails(wxCommandEvent &event);
};

class AddRecordDialog: public wxDialog {
public:
    AddRecordDialog();
    
private:
    wxTextCtrl *mNameCtrl;
    wxRadioBox *mRbTokType;
    wxTextCtrl *mNumCtrl;
    
    // controller
    void OnNumCtrl(wxKeyEvent &event);
    void OnBtnOk(wxCommandEvent &event);
};

class MyView {
public:
    MyPane *mPane;
    
    MyView();
};

#endif /* view_hpp */
