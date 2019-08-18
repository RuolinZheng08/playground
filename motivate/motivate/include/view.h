//
//  view.h
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef view_h
#define view_h

#include <wx/wx.h>
#include <wx/notebook.h>

class NotebookFrame: public wxFrame {
public:
    NotebookFrame(const wxString &title);
};

class MyView {
public:
    NotebookFrame *frame;
    
    MyView();
};

#endif /* view_h */
