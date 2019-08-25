//
//  view.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "view.hpp"

MyPane::MyPane(wxWindow *parent): wxScrolledWindow(parent, wxID_ANY) {
    mPaneSizer = new wxBoxSizer(wxVERTICAL);
    wxButton *btnAdd = new wxButton(this, wxID_ANY, _T("Add New Record"));
    mPaneSizer->Add(btnAdd, 0, wxALL, MEDIUM_SPACING);
    SetSizer(mPaneSizer);
    FitInside();
    SetScrollRate(5, 5);
    
    btnAdd->Bind(wxEVT_BUTTON, &MyPane::OnBtnAdd, this);
}

void MyPane::DrawRecordGained(std::string date, Record record) {
    wxWrapSizer *tokenSizer;
    if (mDateSizerMap.find(date) == mDateSizerMap.end()) {
        // draw date label and tokens
        DrawDate(date);
        tokenSizer = new wxWrapSizer(wxHORIZONTAL);
        DrawTokensGained(tokenSizer, record.mNumTok);
        mPaneSizer->Add(tokenSizer, 0, wxLEFT | wxRIGHT, MEDIUM_SPACING);
        mDateSizerMap[date] = tokenSizer;
    } else {
        // draw tokens only
        tokenSizer = mDateSizerMap[date];
        DrawTokensGained(tokenSizer, record.mNumTok);
    }
    FitInside();
    mPaneSizer->Layout();
}

void MyPane::DrawNumSpent(unsigned int num) {
    
}

void MyPane::DrawDate(std::string date) {
    wxBoxSizer *dateSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *dateText = new wxStaticText(this, wxID_ANY, date);
    wxButton *btnDetails = new wxButton(this, wxID_ANY, _T("Details"));
    
    dateSizer->Add(dateText, 0);
    dateSizer->AddSpacer(200);
    dateSizer->Add(btnDetails, 0);
    mPaneSizer->Add(dateSizer, 0, wxALL, MEDIUM_SPACING);
    
    btnDetails->Bind(wxEVT_BUTTON, &MyPane::OnBtnDetails, this);
}

void MyPane::DrawTokensGained(wxSizer *sizer, int numTok) {
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
    wxFrame *frame = new wxFrame(NULL, wxID_ANY, _T("motivate"));
    mPane = new MyPane(frame);
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(mPane, 1, wxEXPAND);
    frame->SetSizer(sizer);
    frame->Show();
}
