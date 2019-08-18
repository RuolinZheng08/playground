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
#include <wx/wrapsizer.h>
#include <wx/notebook.h>
#include "util.hpp"

const int WINDOW_WIDTH = 350;
const int WINDOW_HEIGHT = 350;
const int HISTORY_BASIC_SPACING = 3;
const int HISTORY_DATE_SPACING = 20;
const std::string TOKEN = "☆";
const std::string TOKEN_USED = "★";

class MyScrolledPane: public wxScrolledWindow {
public:
    wxBoxSizer *paneSizer;
    
    MyScrolledPane(wxWindow *parent, wxWindowID id);
    // for history
    void drawRecordMap(std::map<std::string, std::vector<Record>> recordMap);
    // for achievements and wishes
    void drawRecordList(std::vector<Record> recordList);
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
