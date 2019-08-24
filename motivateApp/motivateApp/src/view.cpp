//
//  view.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "view.hpp"

MyFrame::MyFrame(): wxFrame(NULL, wxID_ANY, _T("motivate")) {
    mSizer = new wxBoxSizer(wxVERTICAL);
    wxButton *btnAdd = new wxButton(this, BTN_ADD, _T("Add New Record"));
    mSizer->Add(btnAdd, 0, wxALL, SMALL_SPACING);
    SetSizer(mSizer);
    
    btnAdd->Bind(wxEVT_BUTTON, &MyFrame::OnBtnAdd, this);
}

AddRecordDialog::AddRecordDialog(): wxDialog(NULL, wxID_ANY, _T("Add New Record")) {
    
    wxBoxSizer *contentSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *controlSizer = new wxBoxSizer(wxHORIZONTAL);
    
    // name text control
    wxStaticText *nameText = new wxStaticText(this, wxID_ANY, _T("Name"));
    wxTextCtrl *nameCtrl = new wxTextCtrl(this, TXT_CTRL_NAME, _T(""));
    
    wxBoxSizer *nameSizer = new wxBoxSizer(wxHORIZONTAL);
    nameSizer->Add(nameText, 0, wxALL, SMALL_SPACING);
    nameSizer->Add(nameCtrl, 0);
    contentSizer->Add(nameSizer, 0);
    
    // radio buttons
    wxRadioButton *rb1 = new wxRadioButton(this, RD_BTN_GAINED, _T("Gained"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
    wxRadioButton *rb2 = new wxRadioButton(this, RD_BTN_GAINED, _T("Spent"), wxDefaultPosition, wxDefaultSize);
    wxBoxSizer *rbSizer = new wxBoxSizer(wxHORIZONTAL);
    rbSizer->Add(rb1, 0, wxALL, SMALL_SPACING);
    rbSizer->Add(rb2, 0, wxALL, SMALL_SPACING);
    contentSizer->Add(rbSizer, 0);
    
    // num tokens text control
    wxStaticText *numText = new wxStaticText(this, wxID_ANY, _T("Number of tokens"));
    wxTextCtrl *numCtrl = new wxTextCtrl(this, wxID_ANY, _T(""));
    wxBoxSizer *numSizer = new wxBoxSizer(wxHORIZONTAL);
    numSizer->Add(numText, 0, wxALL, SMALL_SPACING);
    numSizer->Add(numCtrl, 0);
    contentSizer->Add(numSizer, 0);
    
    // ok and cancel buttons
    wxButton *btnCancel = new wxButton(this, wxID_NO, _T("Cancel"));
    wxButton *btnOk = new wxButton(this, wxID_OK, _T("OK"));
    
    controlSizer->Add(btnOk, 0, wxALIGN_RIGHT);
    controlSizer->Add(btnCancel, 0, wxALIGN_RIGHT);
    contentSizer->Add(controlSizer, 0);
    
    SetSizer(contentSizer);
}

MyView::MyView() {
    mFrame = new MyFrame();
}
