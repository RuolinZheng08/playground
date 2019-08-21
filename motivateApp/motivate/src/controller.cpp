//
//  controller.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "controller.hpp"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    // model
    model = new MyModel();
    
    // view
    view = new MyView();
    
    view->frame->historyPane->drawRecordMap(model->recordMap);
    view->frame->historyPane->colorRecordMap(model->numUsed);
    view->frame->achievePane->drawRecordList(model->achievements);
    view->frame->wishPane->drawRecordList(model->wishes);
    view->frame->Show(true);
    return true;
}

void HistoryPane::OnInfoBtn(wxCommandEvent &event) {
    wxDialog *dlg = new wxDialog(this, wxID_ANY, _T("afaf"));
    if (dlg->ShowModal() == wxID_OK) {
        Close();
    }
}

void RecordListPane::OnInfoBtn(wxCommandEvent &event) {
    
}

void RecordListPane::OnAddBtn(wxCommandEvent &event) {
    
}

void RecordListPane::OnRmvBtn(wxCommandEvent &event) {
    
}
