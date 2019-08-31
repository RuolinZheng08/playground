//
//  DateDetailDialog.cpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/25.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#include "DateDetailDialog.hpp"

DateDetailDialog::DateDetailDialog(wxWindow *parent, std::string date, std::vector<Record> records): wxDialog(parent, wxID_ANY, date, wxPoint(800, 800), wxSize(400, 350)) {
    wxBoxSizer *dialogSizer = new wxBoxSizer(wxVERTICAL);
    dialogSizer->AddSpacer(MEDIUM_SPACING);  // top spacing
    for (int i = 0; i < records.size(); i++) {
        wxBoxSizer *recordSizer = new wxBoxSizer(wxHORIZONTAL);
        std::string tok = records[i].mNumTok > 0 ? TOKEN_GAINED : TOKEN_SPENT;
        recordSizer->Add(new wxStaticText(this, wxID_ANY, records[i].mName));
        recordSizer->AddSpacer(100);
        recordSizer->Add(new wxStaticText(this, wxID_ANY, wxString::Format(_T("%s %d"), tok, std::abs(records[i].mNumTok))));
        dialogSizer->Add(recordSizer, 0, wxLEFT, MEDIUM_SPACING);
        dialogSizer->AddSpacer(SMALL_SPACING);
    }
    SetSizer(dialogSizer);
}
