//
//  view.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "view.hpp"

MyFrame::MyFrame(): wxFrame(NULL, wxID_ANY, _T("motivate")) {
    mSizer = new wxBoxSizer(wxVERTICAL);
    wxButton *BtnAdd = new wxButton(this, BTN_ADD, _T("Add New"));
    mSizer->Add(BtnAdd, 0, wxALL, SMALL_SPACING);
    SetSizer(mSizer);
}

MyView::MyView() {
    mFrame = new MyFrame();
}
