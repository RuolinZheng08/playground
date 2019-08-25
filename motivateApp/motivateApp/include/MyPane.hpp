//
//  MyPane.hpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/25.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef MyPane_hpp
#define MyPane_hpp

#include <stdio.h>
#include "util.hpp"

class MyPane: public wxScrolledWindow {
public:
    MyPane(wxWindow *parent);
    int mNumUnusedTokens;  // len of mUnusedTokens
    std::map<int, std::string> mBtnDetailsIdMap;  // button id to date
    
    void DrawRecordGained(std::string date, Record record);
    void DrawNumSpent(unsigned int num);
    
private:
    wxBoxSizer *mPaneSizer;
    wxStaticText *mNumUnusedTxt;
    std::map<std::string, wxWrapSizer *> mDateSizerMap;
    // gained and not yet spent
    std::vector<wxStaticText *> mUnusedTokens;
    int mOkayBtnId;
    
    void DrawDate(std::string date);
    void DrawTokensGained(wxSizer *sizer, int numTok);
    
    // controller
    void OnBtnAdd(wxCommandEvent &event);
    void OnBtnDetails(wxCommandEvent &event);
};

#endif /* MyPane_hpp */
