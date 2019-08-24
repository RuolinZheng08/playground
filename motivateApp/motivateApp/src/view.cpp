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

AddRecordDialog::AddRecordDialog(): wxDialog(NULL, wxID_ANY, _T("Add New Record"), wxDefaultPosition, wxSize(400, 350)) {
    
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *contentSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *controlSizer = new wxBoxSizer(wxHORIZONTAL);
    
    wxStaticBox *contentBox = new wxStaticBox(this, wxID_ANY, _T("New record"), wxPoint(10, 10), wxSize(380, 250));
    
    // name text control
    wxStaticText *nameText = new wxStaticText(contentBox, wxID_ANY, _T("Name"));
    wxTextCtrl *nameCtrl = new wxTextCtrl(contentBox, TXT_CTRL_NAME, _T(""));
    
    wxBoxSizer *nameSizer = new wxBoxSizer(wxHORIZONTAL);
    nameSizer->Add(nameText, 0, wxALL, SMALL_SPACING);
    nameSizer->Add(nameCtrl, 0, wxALL, SMALL_SPACING);
    contentSizer->Add(nameSizer, 0);
    
    // radio buttons
    wxRadioButton *rb1 = new wxRadioButton(contentBox, RD_BTN_GAINED, _T("Gained"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
    wxRadioButton *rb2 = new wxRadioButton(contentBox, RD_BTN_GAINED, _T("Spent"), wxDefaultPosition, wxDefaultSize);
    wxBoxSizer *rbSizer = new wxBoxSizer(wxHORIZONTAL);
    rbSizer->Add(rb1, 0, wxALL, SMALL_SPACING);
    rbSizer->Add(rb2, 0, wxALL, SMALL_SPACING);
    contentSizer->Add(rbSizer, 0);
    
    // num tokens text control
    wxStaticText *numText = new wxStaticText(contentBox, wxID_ANY, _T("Number of tokens"));
    wxTextCtrl *numCtrl = new wxTextCtrl(contentBox, wxID_ANY, _T(""));
    wxBoxSizer *numSizer = new wxBoxSizer(wxHORIZONTAL);
    numSizer->Add(numText, 0, wxALL, SMALL_SPACING);
    numSizer->Add(numCtrl, 0, wxALL, SMALL_SPACING);
    contentSizer->Add(numSizer, 0);
    
    contentBox->SetSizer(contentSizer);
    
    // ok and cancel buttons
    wxButton *btnCancel = new wxButton(this, wxID_NO, _T("Cancel"));
    wxButton *btnOk = new wxButton(this, wxID_OK, _T("OK"));
    
    controlSizer->Add(btnCancel, 0);
    controlSizer->AddSpacer(20);
    controlSizer->Add(btnOk, 0);
    dialogSizer->Add(contentSizer, 1, wxALIGN_CENTER);
    dialogSizer->Add(controlSizer, 1, wxALIGN_CENTER);
    
    SetSizer(dialogSizer);
}

MyView::MyView() {
    mFrame = new MyFrame();
}
