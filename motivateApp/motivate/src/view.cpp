//
//  view.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "view.hpp"

MyView::MyView() {
    frame = new MyNotebookFrame(_T("motivate"));
}

HistoryPane::HistoryPane(wxWindow *parent, wxWindowID id): wxScrolledWindow(parent, id) {
    unusedTokenIdx = 0;
    paneSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(paneSizer);
    FitInside();
    SetScrollRate(5, 5);
}

void HistoryPane::drawDateText(std::string date) {
    wxGridSizer *dateSizer = new wxGridSizer(1, 3, MEDIUM_SPACING, MEDIUM_SPACING);
    wxStaticText *dateText = new wxStaticText(this, wxID_ANY, date);
    dateSizer->Add(dateText, 0, wxEXPAND);
    dateSizer->Add(new wxStaticText(this, wxID_ANY, "   "), 0, wxEXPAND);
    //int infoBtnId = wxID_HIGHEST + HISTORY_ID_OFFSET + ;
    wxButton *infoBtn = new wxButton(this, wxID_ANY, INFO);
    dateSizer->Add(infoBtn, 0, wxEXPAND);
    paneSizer->Add(dateSizer, 0, wxTOP | wxBOTTOM, RECORD_ROW_SPACING);
    
    //btn->Connect
}

void HistoryPane::drawRecordMap(std::map<std::string, std::vector<Record>> recordMap) {
    // draw all as unused tokens
    std::map<std::string, std::vector<Record>>::iterator it;
    for (it = recordMap.begin(); it != recordMap.end(); it++) {
        drawDateText(it->first);
        wxWrapSizer *tokenSizer = new wxWrapSizer(wxHORIZONTAL);
        std::vector<Record> recordList = it->second;
        for (int i = 0; i < recordList.size(); i++) {
            wxStaticText *token = new wxStaticText(this, wxID_ANY, TOKEN);
            tokenSizer->Add(token, 0, wxRIGHT, MEDIUM_SPACING);
            tokens.push_back(token);
        }
        paneSizer->Add(tokenSizer);
    }
}

void HistoryPane::colorRecordMap(int offset) {
    for (int i = unusedTokenIdx; i < unusedTokenIdx + offset; i++) {
        tokens[i]->SetLabel(TOKEN_USED);
    }
    unusedTokenIdx = unusedTokenIdx + offset;
}

RecordListPane::RecordListPane(wxWindow *parent, wxWindowID id): wxScrolledWindow(parent, id) {
    paneSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(paneSizer);
    FitInside();
    SetScrollRate(5, 5);
}

void RecordListPane::drawRecordList(std::vector<Record> recordList) {
    for (int i = 0; i < recordList.size(); i++) {
        Record record = recordList[i];
        drawRecord(record);
    }
}

void RecordListPane::drawRecord(Record record) {
    // UI: do work -- 3 ☆ + - !
    wxGridSizer *recordSizer = new wxFlexGridSizer(2, 3, SMALL_SPACING, MEDIUM_SPACING);
    wxStaticText *name = new wxStaticText(this, wxID_ANY, record.name);
    recordSizer->Add(name, 0, wxEXPAND);
    recordSizer->Add(new wxStaticText(this, wxID_ANY, "   "), 0, wxEXPAND);
    wxStaticText *tok = new wxStaticText(this, wxID_ANY, wxString::Format("%d %s", record.numTok, TOKEN));
    recordSizer->Add(tok, 0, wxEXPAND);
    wxButton *addBtn = new wxButton(this, wxID_ANY, ADD);
    recordSizer->Add(addBtn, 0, wxEXPAND);
    wxButton *rmvBtn = new wxButton(this, wxID_ANY, REMOVE);
    recordSizer->Add(rmvBtn, 0, wxEXPAND);
    wxButton *infoBtn = new wxButton(this, wxID_ANY, INFO);
    recordSizer->Add(infoBtn, 0, wxEXPAND);
    
    paneSizer->Add(recordSizer, 0, wxTOP | wxBOTTOM, RECORD_ROW_SPACING);
}

MyNotebookFrame::MyNotebookFrame(const wxString &title): wxFrame(NULL, wxID_ANY, title) {
    wxNotebook *notebook = new wxNotebook(this, wxID_ANY);
    
    historyPane = new HistoryPane(notebook, wxID_ANY);
    notebook->AddPage(historyPane, _T("History"));
    achievePane = new RecordListPane(notebook, wxID_ANY);
    notebook->AddPage(achievePane, _T("Achievements"));
    wishPane = new RecordListPane(notebook, wxID_ANY);
    notebook->AddPage(wishPane, _T("Wish List"));
    
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(notebook, 1, wxEXPAND);
    sizer->SetMinSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    SetSizerAndFit(sizer);
}
