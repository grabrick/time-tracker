#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include <wx/wx.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    void OnButtonClicked(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_BUTTON = 1,
    WIDTH = 650,
    HEGHT = 500,
};

#endif // MAINFRAME_HPP
