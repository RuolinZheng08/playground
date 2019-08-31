//
//  AddRecordDialog.hpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/25.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef AddRecordDialog_hpp
#define AddRecordDialog_hpp

#include <stdio.h>
#include "util.hpp"

class AddRecordDialog: public wxDialog {
public:
    AddRecordDialog(wxWindow *parent);
    
private:
    wxTextCtrl *mNameCtrl;
    wxRadioBox *mRbTokType;
    wxTextCtrl *mNumCtrl;
    
    void OnClose(wxCloseEvent &event);
    // controller
    void OnNumCtrl(wxKeyEvent &event);
    void OnBtnOk(wxCommandEvent &event);
};

#endif /* AddRecordDialog_hpp */
