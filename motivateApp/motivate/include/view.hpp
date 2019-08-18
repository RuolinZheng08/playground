//
//  view.h
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef view_h
#define view_h

#include <vector>
#include <wx/wx.h>
#include <wx/notebook.h>

class MyScrolledPane: public wxScrolledWindow {
public:
    MyScrolledPane(wxWindow *parent, wxWindowID id);
};

class MyNotebookFrame: public wxFrame {
public:
    MyNotebookFrame(const wxString &title);
};

class MyView {
public:
    MyNotebookFrame *frame;
    
    MyView();
};

#endif /* view_h */
