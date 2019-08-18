//
//  model.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "model.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    wxFrame *frame = new wxFrame(NULL, wxID_OK, _T("motivate"));
    frame->Show(true);
    return true;
}
