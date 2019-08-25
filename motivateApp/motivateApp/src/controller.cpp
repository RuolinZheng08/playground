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
    std::map<int, std::string> btnIdMap = wxGetApp().mView->mPane->mBtnDetailsIdMap;
    int btnId = event.GetId();
    assert(btnIdMap.find(btnId) != btnIdMap.end());
    std::string date = btnIdMap[btnId];
    std::map<std::string, std::vector<Record>> recordMap = wxGetApp().mModel->mRecordMap;
    DateDetailDialog *dlg = new DateDetailDialog(date, recordMap[date]);
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
    mNumCtrl->Unbind(wxEVT_KEY_DOWN, &AddRecordDialog::OnNumCtrl, this);
    
    time_t timev;
    time(&timev);
    std::string date = timeToDate(timev);
    std::string name = mNameCtrl->GetValue().ToStdString();
    std::string numStr = mNumCtrl->GetValue().ToStdString();
    if (name == "" || numStr == "") {
        event.Skip();
        return;
    }
    
    int num = stoi(numStr);
    if (num > 1001 || num <= 0) {
        wxMessageDialog *dlg = new wxMessageDialog(NULL, _T("Please input a number between 1 and 1000"), _T("Invalid number of tokens"), wxOK | wxICON_ERROR);
        dlg->ShowModal();
        dlg->Destroy();
    }
    if (mRbTokType->GetSelection() == 1) {  // spent
        int diff = num - wxGetApp().mView->mPane->mNumUnusedTokens;
        if (diff > 0) {
            wxMessageDialog *dlg = new wxMessageDialog(NULL, wxString::Format(_T("You need to earn %d more tokens to spend on this activity."), diff), _T("Not enough tokens"), wxOK | wxICON_ERROR);
            dlg->ShowModal();
            dlg->Destroy();
            return;
        }
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
