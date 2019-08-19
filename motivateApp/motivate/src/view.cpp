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
    paneSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(paneSizer);
    FitInside();
    SetScrollRate(5, 5);
}

void HistoryPane::drawDateText(std::string date) {
    wxStaticText *dateText = new wxStaticText(this, wxID_ANY, date);
    paneSizer->Add(dateText, 0, wxTOP | wxBOTTOM, HISTORY_DATE_SPACING);
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
            tokenSizer->Add(token, 0, wxRIGHT, HISTORY_BASIC_SPACING);
        }
        paneSizer->Add(tokenSizer);
    }
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
        wxStaticText *txt = new wxStaticText(this, wxID_ANY, wxString::Format(("%s %s %d"), record.name, record.description, record.num));
        paneSizer->Add(txt, 0, wxALL, HISTORY_BASIC_SPACING);
    }
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
