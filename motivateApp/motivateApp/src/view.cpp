//
//  view.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "view.hpp"

MyFrame::MyFrame(): wxFrame(NULL, wxID_ANY, _T("motivate")) {
    mFrameSizer = new wxBoxSizer(wxVERTICAL);
    wxButton *btnAdd = new wxButton(this, wxID_ANY, _T("Add New Record"));
    mFrameSizer->Add(btnAdd, 0, wxALL, SMALL_SPACING);
    SetSizer(mFrameSizer);
    
    btnAdd->Bind(wxEVT_BUTTON, &MyFrame::OnBtnAdd, this);
}

void MyFrame::DrawRecordGained(std::string date, Record record) {
    wxWrapSizer *tokenSizer;
    if (mDateSizerMap.find(date) == mDateSizerMap.end()) {
        // draw date label and tokens
        DrawDate(date);
        tokenSizer = new wxWrapSizer(wxHORIZONTAL);
        DrawTokensGained(tokenSizer, record.mNumTok);
        mFrameSizer->Add(tokenSizer, 1, wxALIGN_CENTER_HORIZONTAL);
        mDateSizerMap[date] = tokenSizer;
    } else {
        // draw tokens only
        tokenSizer = mDateSizerMap[date];
        DrawTokensGained(tokenSizer, record.mNumTok);
    }
    mFrameSizer->Layout();
}

void MyFrame::DrawNumSpent(unsigned int num) {
    
}

void MyFrame::DrawDate(std::string date) {
    wxBoxSizer *dateSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *dateText = new wxStaticText(this, wxID_ANY, date);
    wxButton *btnDetails = new wxButton(this, wxID_ANY, _T("Details"));
    
    dateSizer->Add(dateText, 0);
    dateSizer->AddSpacer(30);
    dateSizer->Add(btnDetails, 0, wxALIGN_RIGHT);
    mFrameSizer->Add(dateSizer, 1);
    
    btnDetails->Bind(wxEVT_BUTTON, &MyFrame::OnBtnDetails, this);
}

void MyFrame::DrawTokensGained(wxSizer *sizer, int numTok) {
    for (int i = 0; i < numTok; i++) {
        wxStaticText *tok = new wxStaticText(this, wxID_ANY, TOKEN_GAINED);
        sizer->Add(tok, 0, wxRIGHT, SMALL_SPACING);
        mUnusedTokens.push_back(tok);
    }
}

AddRecordDialog::AddRecordDialog(): wxDialog(NULL, wxID_ANY, _T("Add New Record"), wxDefaultPosition, wxSize(400, 350)) {
    
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

MyView::MyView() {
    mFrame = new MyFrame();
}
