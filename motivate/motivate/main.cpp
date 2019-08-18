//
//  main.cpp
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/16.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "main.h"

class ScrolledWidgetsPane : public wxScrolledWindow
{
public:
    ScrolledWidgetsPane(wxWindow* parent, wxWindowID id) : wxScrolledWindow(parent, id)
    {
        // the sizer will take care of determining the needed scroll size
        // (if you don't use sizers you will need to manually set the viewport size)
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        
        // add a series of widgets
        for (int w=1; w<=120; w++)
        {
            wxButton* b = new wxButton(this, wxID_ANY, wxString::Format(wxT("Button %i"), w));
            sizer->Add(b, 0, wxALL, 3);
        }
        
        this->SetSizer(sizer);
        
        // this part makes the scrollbars show up
        this->FitInside(); // ask the sizer about the needed size
        this->SetScrollRate(5, 5);
    }
    
};

bool MyApp::OnInit() {
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Scrolling Widgets"), wxPoint(50,50), wxSize(650,650));
    
    ScrolledWidgetsPane* my_image = new ScrolledWidgetsPane(frame, wxID_ANY);
    sizer->Add(my_image, 1, wxEXPAND);
    frame->SetSizer(sizer);
    
    frame->Show();
    return true;
}

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)
