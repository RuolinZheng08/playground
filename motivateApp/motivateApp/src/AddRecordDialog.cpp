//
//  AddRecordDialog.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/25.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "AddRecordDialog.hpp"

AddRecordDialog::AddRecordDialog(wxWindow *parent): wxDialog(parent, wxID_ANY, _T("Add New Record"), wxDefaultPosition, wxSize(400, 350)) {
    
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *contentSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *controlSizer = new wxBoxSizer(wxHORIZONTAL);
    
    wxStaticBox *contentBox = new wxStaticBox(this, wxID_ANY, _T("New record"), wxPoint(10, 10), wxSize(380, 200));
    
    // name text control
    wxStaticText *nameText = new wxStaticText(contentBox, wxID_ANY, _T("Name"));
    mNameCtrl = new wxTextCtrl(contentBox, wxID_ANY, _T(""), wxDefaultPosition, wxSize(250, -1));
    wxBoxSizer *nameSizer = new wxBoxSizer(wxHORIZONTAL);
    nameSizer->Add(nameText, 0, wxALL, SMALL_SPACING);
    nameSizer->Add(mNameCtrl, 0, wxALL, SMALL_SPACING);
    contentSizer->Add(nameSizer, 0, wxTOP | wxBOTTOM, MEDIUM_SPACING);
    
    // radio buttons
    wxArrayString tokTypes;
    tokTypes.Add(_T("Gained"));
    tokTypes.Add(_T("Spent"));
    mRbTokType = new wxRadioBox(contentBox, wxID_ANY, _T("Did you gain or spend tokens on this activity?"), wxDefaultPosition, wxDefaultSize, tokTypes, 2, wxRA_SPECIFY_COLS);
    contentSizer->Add(mRbTokType, 0, wxTOP | wxBOTTOM, MEDIUM_SPACING);
    
    // num tokens text control
    wxStaticText *numText = new wxStaticText(contentBox, wxID_ANY, _T("Number of tokens"));
    mNumCtrl = new wxTextCtrl(contentBox, wxID_ANY, _T(""));
    wxBoxSizer *numSizer = new wxBoxSizer(wxHORIZONTAL);
    numSizer->Add(numText, 0, wxALL, SMALL_SPACING);
    numSizer->Add(mNumCtrl, 0, wxALL, SMALL_SPACING);
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
    
    // bind to event handlers
    mNumCtrl->Bind(wxEVT_KEY_DOWN, &AddRecordDialog::OnNumCtrl, this);
    btnOk->Bind(wxEVT_BUTTON, &AddRecordDialog::OnBtnOk, this);
}

void AddRecordDialog::OnClose(wxCloseEvent &event) {
    mNameCtrl->Enable(false);
    mNumCtrl->Enable(false);
    Close();
}
