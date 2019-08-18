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
    
    view->frame->historyTab->drawRecordMap(model->recordMap);
    view->frame->achieveTab->drawRecordList(model->achievements);
    view->frame->wishTab->drawRecordList(model->wishes);
    view->frame->Show(true);
    return true;
}
