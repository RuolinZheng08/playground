#include <iostream>
#include <vector>
#include <wx/wx.h>

using namespace std;

class MyApp : public wxApp {
public:
    bool OnInit();
    // AlbumFrame uses wxBitmapButton and ImageFrame uses wxStaticBitmap
    vector<wxBitmap> images;
};

// a frame to display the grid view of images
class AlbumFrame : public wxFrame {
public:
    AlbumFrame();
    void OnImgBtn(wxCommandEvent &event);
private:
    // 4 rows and 5 columns
    wxButton *thumbnails[20];
};

// a frame to display individual images
class ImageFrame : public wxFrame {
public:
    ImageFrame(int id);
    // navigate back and forth
    void OnBtnPrev(wxCommandEvent &event);
    void OnBtnNext(wxCommandEvent &event);
private:
    int currId;
};

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)