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

MyNotebookFrame::MyNotebookFrame(const wxString &title): wxFrame(NULL, wxID_ANY, title) {
    wxNotebook *notebook = new wxNotebook(this, wxID_ANY);
    
    wxScrolledWindow *recordTab = new wxScrolledWindow(notebook, wxID_ANY);
    notebook->AddPage(recordTab, _T("Record"));
    wxScrolledWindow *achieveTab = new wxScrolledWindow(notebook, wxID_ANY);
    notebook->AddPage(achieveTab, _T("Achievements"));
    wxScrolledWindow *wishTab = new wxScrolledWindow(notebook, wxID_ANY);
    notebook->AddPage(wishTab, _T("Wish List"));
    
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(notebook, 1, wxEXPAND);
    SetSizerAndFit(sizer);
}
