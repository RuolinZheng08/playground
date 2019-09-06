//
//  MyPane.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/25.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "MyPane.hpp"

MyPane::MyPane(wxWindow *parent): wxScrolledWindow(parent, wxID_ANY) {
    mNumUnusedTokens = 0;
    mOkayBtnId = wxID_HIGHEST;
    
    mPaneSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton *btnAdd = new wxButton(this, wxID_ANY, _T("Add New Record"));
    mNumUnusedTxt = new wxStaticText(this, wxID_ANY, wxString::Format(_T("Number of unused tokens: %d"), mNumUnusedTokens));
    
    topSizer->Add(btnAdd, 0);
    topSizer->AddSpacer(60);
    topSizer->Add(mNumUnusedTxt, 0);
    mPaneSizer->Add(topSizer, 0, wxALL, MEDIUM_SPACING);
    
    SetSizer(mPaneSizer);
    FitInside();
    SetScrollRate(5, 5);
    
    btnAdd->Bind(wxEVT_BUTTON, &MyPane::OnBtnAdd, this);
}

void MyPane::DrawRecordMap(std::map<std::string, std::vector<Record>> recordMap) {
    int numUsed = 0;
    std::map<std::string, std::vector<Record>>::iterator it;
    for (it =recordMap.begin(); it != recordMap.end(); it++) {
        std::string date = it->first;
        DrawDate(date);
        wxWrapSizer *tokenSizer = new wxWrapSizer(wxHORIZONTAL);
        mPaneSizer->Add(tokenSizer, 0, wxLEFT | wxRIGHT, MEDIUM_SPACING);
        mDateSizerMap[date] = tokenSizer;
        
        std::vector<Record> records = it->second;
        for (int i = 0; i != records.size(); i++) {
            if (records[i].mNumTok < 0) {
                numUsed += -records[i].mNumTok;
            } else {
                // draw tokens
                DrawTokensGained(mDateSizerMap[date], records[i].mNumTok);
            }
        }
    }
    DrawNumSpent(numUsed);
    FitInside();
    mPaneSizer->Layout();
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
    for (int i = 0; i < num; i++) {
        mUnusedTokens.front()->SetLabel(TOKEN_SPENT);
        mUnusedTokens.pop_front();
        mNumUnusedTokens--;
    }
    mNumUnusedTxt->SetLabel(wxString::Format(_T("Number of unused tokens: %d"), mNumUnusedTokens));
}

void MyPane::DrawDate(std::string date) {
    wxBoxSizer *dateSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *dateText = new wxStaticText(this, wxID_ANY, date);
    
    wxButton *btnDetails = new wxButton(this, mOkayBtnId, _T("Details"));
    
    dateSizer->Add(dateText, 0);
    dateSizer->AddSpacer(200);
    dateSizer->Add(btnDetails, 0);
    mPaneSizer->Add(dateSizer, 0, wxALL, MEDIUM_SPACING);
    
    btnDetails->Bind(wxEVT_BUTTON, &MyPane::OnBtnDetails, this);
    assert(mBtnDetailsIdMap.find(mOkayBtnId) == mBtnDetailsIdMap.end());
    mBtnDetailsIdMap[mOkayBtnId] = date;
    mOkayBtnId++;
}

void MyPane::DrawTokensGained(wxSizer *sizer, int numTok) {
    for (int i = 0; i < numTok; i++) {
        wxStaticText *tok = new wxStaticText(this, wxID_ANY, TOKEN_GAINED);
        sizer->Add(tok, 0, wxRIGHT, SMALL_SPACING);
        mUnusedTokens.push_back(tok);
        mNumUnusedTokens++;
    }
    mNumUnusedTxt->SetLabel(wxString::Format(_T("Number of unused tokens: %d"), mNumUnusedTokens));
}
