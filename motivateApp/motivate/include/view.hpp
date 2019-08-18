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
#include "util.hpp"

class MyScrolledPane: public wxScrolledWindow {
public:
    wxBoxSizer *paneSizer;
    
    MyScrolledPane(wxWindow *parent, wxWindowID id);
    void drawRecordList(std::vector<Record> recordList);
    void drawRecordMap(std::map<std::string, std::vector<Record>> recordMap);
};

class MyNotebookFrame: public wxFrame {
public:
    MyScrolledPane *historyTab;
    MyScrolledPane *achieveTab;
    MyScrolledPane *wishTab;
    
    MyNotebookFrame(const wxString &title);
};

class MyView {
public:
    MyNotebookFrame *frame;
    
    MyView();
};

#endif /* view_h */
