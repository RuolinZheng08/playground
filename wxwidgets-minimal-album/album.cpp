#include "album.h"

// button id
static int id_offset = 100;

// helper functions
inline int mod(int a, int b) { return (a % b + b) % b; }

bool MyApp::OnInit() {
    wxInitAllImageHandlers();
    // load images
    wxImage img(_T("images/1.jpg"), wxBITMAP_TYPE_JPEG);
    wxBitmap bmp(img);
    this->images.push_back(bmp);

    AlbumFrame *album = new AlbumFrame();
    album->Show();
    return true;
}

// methods for AlbumFrame
AlbumFrame::AlbumFrame() : wxFrame(NULL, wxID_ANY, _T("Album")) {
    wxGridSizer *grid = new wxGridSizer(4, 5, 5);
    this->SetSizer(grid);

    vector<wxBitmap> images = wxGetApp().images;
    for (int i = 0; i < images.size(); i++) {
        wxBitmapButton *btn = new wxBitmapButton(this, id_offset + i, images[i]);
        btn->Bind(wxEVT_BUTTON, &AlbumFrame::OnImgBtn, this);
        grid->Add(btn, 0, wxALL | wxALIGN_CENTER);
        this->thumbnails[i] = btn;
    }
}

void AlbumFrame::OnImgBtn(wxCommandEvent &event) {
    int id = event.GetId();
    ImageFrame *image = new ImageFrame(id - id_offset);
    image->Show();
}

// methods for ImageFrame
ImageFrame::ImageFrame(int id) : wxFrame(NULL, wxID_ANY, wxString::Format(_T("Image %i"), id)) {
    this->currId = id;  // record the button id

    wxBoxSizer *navbar = new wxBoxSizer(wxHORIZONTAL);
    wxButton *prev = new wxButton(this, 97, _T("<"));
    wxButton *next = new wxButton(this, 98, _T(">"));

    prev->Bind(wxEVT_BUTTON, &ImageFrame::OnBtnPrev, this);
    next->Bind(wxEVT_BUTTON, &ImageFrame::OnBtnNext, this);

    navbar->Add(prev, 0, wxALL | wxEXPAND);
    navbar->Add(next, 0, wxALL | wxEXPAND);

    wxBoxSizer *content = new wxBoxSizer(wxVERTICAL);

    vector<wxBitmap> images = wxGetApp().images;
    wxStaticBitmap *sbmp = new wxStaticBitmap(this, wxID_OK, images[this->currId]);

    content->Add(navbar, 0, wxALL | wxEXPAND);
    content->Add(sbmp, 0, wxALL | wxEXPAND);
    this->SetSizer(content);
}

void ImageFrame::OnBtnPrev(wxCommandEvent &event) {
    int len = wxGetApp().images.size();
    ImageFrame *prev_img = new ImageFrame(mod(currId - 1, len));
    prev_img->Show();
    this->Close();
}

void ImageFrame::OnBtnNext(wxCommandEvent &event) {
    int len = wxGetApp().images.size();
    ImageFrame *next_img = new ImageFrame(mod(currId + 1, len));
    next_img->Show();
    this->Close();
}