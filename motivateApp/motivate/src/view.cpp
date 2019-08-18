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
    SetSizerAndFit(paneSizer);
    FitInside();
    SetScrollRate(5, 5);
}

void MyScrolledPane::drawRecordList(std::vector<Record> recordList) {
    for (int i = 0; i < recordList.size(); i++) {
        wxButton* b = new wxButton(this, wxID_ANY, recordList[i].name);
        paneSizer->Add(b, 0, wxALL, 3);
    }
}

void MyScrolledPane::drawRecordMap(std::map<std::string, std::vector<Record>> recordMap) {
    std::map<std::string, std::vector<Record>>::iterator it;
    for (it = recordMap.begin(); it != recordMap.end(); it++) {
        std::string date = it->first;
        std::vector<Record> recordList = it->second;
        wxStaticText *text = new wxStaticText(this, wxID_ANY, wxString(date));
        paneSizer->Add(text, 0, wxALL, 3);
        drawRecordList(recordList);
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
    sizer->SetMinSize(350, 350);
    SetSizerAndFit(sizer);
}
