#include "mainframe.hpp"
#include "settings/settings.hpp"
#include "UI/roundedPanel/roundedPanel.hpp"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MainFrame *frame = new MainFrame("Time Tracker");
    frame->Show(true);
    return true;
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
//EVT_BUTTON(ID_BUTTON, MainFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
        : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEGHT), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    ApplyPanelSettings(panel);

    wxBoxSizer *sizer_vertical = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *sizer_horizontal = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *label = new wxStaticText(panel, wxID_ANY, "Time Tracker");
    ApplyLabelSettings(label);
    sizer_vertical->Add(label, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 20);

    wxBoxSizer *panelSizer = new wxBoxSizer(wxHORIZONTAL);

    RoundedPanel *roundedPanel1 = new RoundedPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(100, 100), 15);
    roundedPanel1->SetText("0");
    ApplyRoundedPanelSettings(roundedPanel1);
    panelSizer->Add(roundedPanel1, 0, wxALL, 5);

    RoundedPanel *roundedPanel2 = new RoundedPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(100, 100), 15);
    roundedPanel2->SetText("0");
    ApplyRoundedPanelSettings(roundedPanel2);
    panelSizer->Add(roundedPanel2, 0, wxALL, 5);

    RoundedPanel *roundedPanel3 = new RoundedPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(100, 100), 15);
    roundedPanel3->SetText("0");
    ApplyRoundedPanelSettings(roundedPanel3);
    panelSizer->Add(roundedPanel3, 0, wxALL, 5);

    sizer_vertical->Add(panelSizer, 0, wxALL | wxCENTER, 5);

//    wxButton *button = new wxButton(panel, ID_BUTTON, "Click Me", wxPoint(200, 50));
//    ApplyButtonSettings(button);

    panel->SetSizer(sizer_vertical);
}

//void MainFrame::OnButtonClicked(wxCommandEvent& event) {
//    wxMessageBox("Button clicked", "Info", wxOK | wxICON_INFORMATION);
//}
