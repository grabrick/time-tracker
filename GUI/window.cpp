#include "window.hpp"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("Time Tracker");
    frame->Show(true);
    return true;
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MyFrame::OnStart)
EVT_BUTTON(wxID_ANY, MyFrame::OnStop)
EVT_BUTTON(wxID_ANY, MyFrame::OnReset)
EVT_TIMER(ID_Timer, MyFrame::OnTimer)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    m_timerDisplay = new wxStaticText(panel, wxID_ANY, "00:00:00");
    sizer->Add(m_timerDisplay, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);

    wxButton* startButton = new wxButton(panel, wxID_ANY, "Start");
    sizer->Add(startButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 5);

    wxButton* stopButton = new wxButton(panel, wxID_ANY, "Stop");
    sizer->Add(stopButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 5);

    wxButton* resetButton = new wxButton(panel, wxID_ANY, "Reset");
    sizer->Add(resetButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 5);

    panel->SetSizer(sizer);

    m_timer = new wxTimer(this, ID_Timer);
    m_seconds = 0;
}

void MyFrame::OnStart(wxCommandEvent& event) {
    if (!m_timer->IsRunning()) {
        m_timer->Start(1000); // 1 second interval
    }
}

void MyFrame::OnStop(wxCommandEvent& event) {
    if (m_timer->IsRunning()) {
        m_timer->Stop();
    }
}

void MyFrame::OnReset(wxCommandEvent& event) {
    m_timer->Stop();
    m_seconds = 0;
    m_timerDisplay->SetLabel("00:00:00");
}

void MyFrame::OnTimer(wxTimerEvent& event) {
    m_seconds++;
    int hours = m_seconds / 3600;
    int minutes = (m_seconds % 3600) / 60;
    int seconds = m_seconds % 60;

    wxString timeString = wxString::Format("%02d:%02d:%02d", hours, minutes, seconds);
    m_timerDisplay->SetLabel(timeString);
}
