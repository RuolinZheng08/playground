//
//  controller.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "controller.hpp"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    // model
    mModel = new MyModel();
    
    // view
    mView = new MyView();
    mView->mFrame->Show(true);
    return true;
}

void MyFrame::OnBtnAdd(wxCommandEvent &event) {
    AddRecordDialog *dlg = new AddRecordDialog();
    dlg->ShowModal();
}

void AddRecordDialog::OnNumCtrl(wxKeyEvent &event) {
    if (wxIsdigit(event.GetKeyCode()) || wxIscntrl(event.GetKeyCode())) {
        event.Skip();
    } else {
        wxBell();
    }
}

void AddRecordDialog::OnBtnOk(wxCommandEvent &event) {
    time_t timev;
    time(&timev);
    std::string name = nameCtrl->GetValue().ToStdString();
    int num = stoi(numCtrl->GetValue().ToStdString());
    if (num > 1001 || num < 0) {
        wxMessageDialog *dlg = new wxMessageDialog(NULL,  _T("Please input a number between 0 and 1000"), _T("Invalid number of tokens"), wxOK | wxICON_ERROR);
        dlg->ShowModal();
    }
    
    if (rbTokType->GetSelection() == 1) {  // spent
        num = -num;
    }
    Record *record = new Record(timev, name, num);
    std::vector<Record *> records = wxGetApp().mModel->mRecordMap[timeToDate(timev)];
    records.push_back(record);
    
    // UI
    if (num < 0) {
        
    }
    
    Close();
}
