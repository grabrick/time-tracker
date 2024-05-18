#ifndef TIMER_WINDOW_HPP
#define TIMER_WINDOW_HPP
#include <wx/wx.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

private:
    void OnStart(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnReset(wxCommandEvent& event);

    wxStaticText* m_timerDisplay;
    wxTimer* m_timer;
    int m_seconds;

wxDECLARE_EVENT_TABLE();

    void OnTimer(wxTimerEvent &event);
};

enum {
    ID_Timer = 1
};

#endif //TIMER_WINDOW_HPP
