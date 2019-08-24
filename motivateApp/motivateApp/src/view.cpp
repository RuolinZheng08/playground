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
    wxButton *btnAdd = new wxButton(this, wxID_ANY, _T("Add New Record"));
    mSizer->Add(btnAdd, 0, wxALL, SMALL_SPACING);
    SetSizer(mSizer);
    
    btnAdd->Bind(wxEVT_BUTTON, &MyFrame::OnBtnAdd, this);
}

AddRecordDialog::AddRecordDialog(): wxDialog(NULL, wxID_ANY, _T("Add New Record"), wxDefaultPosition, wxSize(400, 350)) {
    
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *contentSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *controlSizer = new wxBoxSizer(wxHORIZONTAL);
    
    wxStaticBox *contentBox = new wxStaticBox(this, wxID_ANY, _T("New record"), wxPoint(10, 10), wxSize(380, 200));
    
    // name text control
    wxStaticText *nameText = new wxStaticText(contentBox, wxID_ANY, _T("Name"));
    nameCtrl = new wxTextCtrl(contentBox, wxID_ANY, _T(""));
    wxBoxSizer *nameSizer = new wxBoxSizer(wxHORIZONTAL);
    nameSizer->Add(nameText, 0, wxALL, SMALL_SPACING);
    nameSizer->Add(nameCtrl, 0, wxALL, SMALL_SPACING);
    contentSizer->Add(nameSizer, 0, wxTOP | wxBOTTOM, MEDIUM_SPACING);
    
    // radio buttons
    wxArrayString tokTypes;
    tokTypes.Add(_T("Gained"));
    tokTypes.Add(_T("Spent"));
    rbTokType = new wxRadioBox(contentBox, wxID_ANY, _T("Did you gain or spend tokens on this activity?"), wxDefaultPosition, wxDefaultSize, tokTypes, 2, wxRA_SPECIFY_COLS);
    contentSizer->Add(rbTokType, 0, wxTOP | wxBOTTOM, MEDIUM_SPACING);
    
    // num tokens text control
    wxStaticText *numText = new wxStaticText(contentBox, wxID_ANY, _T("Number of tokens"));
    numCtrl = new wxTextCtrl(contentBox, wxID_ANY, _T(""));
    wxBoxSizer *numSizer = new wxBoxSizer(wxHORIZONTAL);
    numSizer->Add(numText, 0, wxALL, SMALL_SPACING);
    numSizer->Add(numCtrl, 0, wxALL, SMALL_SPACING);
    contentSizer->Add(numSizer, 0, wxTOP | wxBOTTOM, MEDIUM_SPACING);
    
    contentBox->SetSizer(contentSizer);
    
    // ok and cancel buttons
    wxButton *btnCancel = new wxButton(this, wxID_CANCEL, _T("Cancel"));
    wxButton *btnOk = new wxButton(this, wxID_OK, _T("OK"));
    
    controlSizer->Add(btnCancel, 0);
    controlSizer->AddSpacer(30);
    controlSizer->Add(btnOk, 0);
    dialogSizer->Add(contentSizer, 1, wxALIGN_CENTER);
    dialogSizer->AddSpacer(100);
    dialogSizer->Add(controlSizer, 1, wxALIGN_CENTER);
    
    SetSizer(dialogSizer);
}

MyView::MyView() {
    mFrame = new MyFrame();
}
