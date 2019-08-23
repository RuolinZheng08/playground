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
