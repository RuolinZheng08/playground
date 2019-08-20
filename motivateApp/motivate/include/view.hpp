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
const int SMALL_SPACING = 3;
const int MEDIUM_SPACING = 3;
const int RECORD_ROW_SPACING = 20;
const std::string TOKEN = "☆";
const std::string TOKEN_USED = "★";
const std::string ADD = "+";
const std::string REMOVE = "-";
const std::string INFO = "!";

const int HISTORY_ID_OFFSET = 1000;
const int ACHIEVE_ID_OFFSET = 2000;
const int WISHLIST_ID_OFFSET = 3000;

class HistoryPane: public wxScrolledWindow {
public:
    HistoryPane(wxWindow *parent, wxWindowID id);
    void drawRecordMap(std::map<std::string, std::vector<Record>> recordMap);
    // mark tokens from unusedTokenIdx to unusedTokenIdx + offset - 1 as used
    void colorRecordMap(int offset);
    
private:
    wxBoxSizer *paneSizer;
    std::vector<wxStaticText *> tokens;
    int unusedTokenIdx;  // idx of the next unused token
    
    void drawDateText(std::string date);
};

class RecordListPane: public wxScrolledWindow {
public:
    RecordListPane(wxWindow *parent, wxWindowID id);
    void drawRecordList(std::vector<Record> recordList);
    
private:
     wxBoxSizer *paneSizer;
    
    void drawRecord(Record record);
};

class MyNotebookFrame: public wxFrame {
public:
    HistoryPane *historyPane;
    RecordListPane *achievePane;
    RecordListPane *wishPane;
    
    MyNotebookFrame(const wxString &title);
};

class MyView {
public:
    MyNotebookFrame *frame;
    
    MyView();
};

#endif /* view_h */
