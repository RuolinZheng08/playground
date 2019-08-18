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

MyScrolledPane::MyScrolledPane(wxWindow *parent, wxWindowID id): wxScrolledWindow(parent, id) {
    paneSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(paneSizer);
    FitInside();
    SetScrollRate(5, 5);
}

void MyScrolledPane::drawRecordMap(std::map<std::string, std::vector<Record>> recordMap) {
    std::map<std::string, std::vector<Record>>::iterator it;
    for (it = recordMap.begin(); it != recordMap.end(); it++) {
        wxStaticText *date = new wxStaticText(this, wxID_ANY, wxString(it->first));
        paneSizer->Add(date, 0, wxTOP | wxBOTTOM, HISTORY_DATE_SPACING);
        
        // draw tokens
        wxWrapSizer *tokenSizer = new wxWrapSizer(wxHORIZONTAL);
        std::vector<Record> recordList = it->second;
        for (int i = 0; i < recordList.size(); i++) {
            wxStaticText *token = new wxStaticText(this, wxID_ANY, TOKEN);
            tokenSizer->Add(token, 0, wxRIGHT, HISTORY_BASIC_SPACING);
        }
        paneSizer->Add(tokenSizer);
    }
    paneSizer->Fit(this);
}

void MyScrolledPane::drawRecordList(std::vector<Record> recordList) {
    for (int i = 0; i < recordList.size(); i++) {
        Record record = recordList[i];
        wxStaticText *txt = new wxStaticText(this, wxID_ANY, wxString::Format(("%s %s %d"), record.name, record.description, record.num));
        paneSizer->Add(txt, 0, wxALL, HISTORY_BASIC_SPACING);
    }
}

MyNotebookFrame::MyNotebookFrame(const wxString &title): wxFrame(NULL, wxID_ANY, title) {
    wxNotebook *notebook = new wxNotebook(this, wxID_ANY);
    
    historyTab = new MyScrolledPane(notebook, wxID_ANY);
    notebook->AddPage(historyTab, _T("History"));
    achieveTab = new MyScrolledPane(notebook, wxID_ANY);
    notebook->AddPage(achieveTab, _T("Achievements"));
    wishTab = new MyScrolledPane(notebook, wxID_ANY);
    notebook->AddPage(wishTab, _T("Wish List"));
    
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(notebook, 1, wxEXPAND);
    sizer->SetMinSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    SetSizerAndFit(sizer);
}
