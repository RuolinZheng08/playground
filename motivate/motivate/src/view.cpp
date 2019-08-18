//
//  view.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "view.h"

MyView::MyView() {
    frame = new NotebookFrame(_T("motivate"));
}

NotebookFrame::NotebookFrame(const wxString &title): wxFrame(NULL, wxID_ANY, title) {
    wxNotebook *notebook = new wxNotebook(this, wxID_ANY);
    
    wxScrolledWindow *recordTab = new wxScrolledWindow(notebook, wxID_ANY);
    notebook->AddPage(recordTab, _T("Record"));
    
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(notebook, 1, wxEXPAND);
    SetSizerAndFit(sizer);
}
