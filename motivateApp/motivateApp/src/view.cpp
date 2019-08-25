//
//  view.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "view.hpp"

MyView::MyView() {
    wxFrame *frame = new wxFrame(NULL, wxID_ANY, _T("motivate"));
    mPane = new MyPane(frame);
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(mPane, 1, wxEXPAND);
    frame->SetSizer(sizer);
    frame->Show();
}
