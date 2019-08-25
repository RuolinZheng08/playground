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
    return true;
}

void MyPane::OnBtnAdd(wxCommandEvent &event) {
    AddRecordDialog *dlg = new AddRecordDialog();
    dlg->ShowModal();
}

void MyPane::OnBtnDetails(wxCommandEvent &event) {
    
}

void AddRecordDialog::OnNumCtrl(wxKeyEvent &event) {
    if (wxIsdigit(event.GetKeyCode()) || wxIscntrl(event.GetKeyCode())) {
        event.Skip();
    } else {
        wxBell();
    }
}

void AddRecordDialog::OnBtnOk(wxCommandEvent &event) {
    mNumCtrl->Unbind(wxEVT_KEY_DOWN, &AddRecordDialog::OnNumCtrl, this);
    
    time_t timev;
    time(&timev);
    std::string date = timeToDate(timev);
    std::string name = mNameCtrl->GetValue().ToStdString();
    int num = stoi(mNumCtrl->GetValue().ToStdString());
    if (num > 1001 || num <= 0) {
        wxMessageDialog *dlg = new wxMessageDialog(NULL,  _T("Please input a number between 1 and 1000"), _T("Invalid number of tokens"), wxOK | wxICON_ERROR);
        dlg->ShowModal();
        dlg->Destroy();
    }
    if (mRbTokType->GetSelection() == 1) {  // spent
        num = -num;
    }
    
    // logic
    Record record = Record(timev, name, num);
    wxGetApp().mModel->mRecordMap[date].push_back(record);
    
    // UI
    if (num > 0) {
        wxGetApp().mView->mPane->DrawRecordGained(date, record);
    } else {
        wxGetApp().mView->mPane->DrawNumSpent(-num);
    }
    
    Close();
}
