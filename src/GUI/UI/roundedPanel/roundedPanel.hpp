#ifndef ROUNDED_PANEL_HPP
#define ROUNDED_PANEL_HPP

#include <wx/wx.h>
#include <wx/dcbuffer.h>

class RoundedPanel : public wxPanel {
public:
    RoundedPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, int radius);

    bool SetBackgroundColour(const wxColour& colour) wxOVERRIDE;
    bool SetForegroundColour(const wxColour& colour) wxOVERRIDE;
    void SetRadius(int radius);

    void SetText(const wxString& text);

private:
    int m_radius;
    wxColour m_bgColour;
    wxColour m_tColor;
    wxString m_text;

    void OnPaint(wxPaintEvent& event);

    wxDECLARE_EVENT_TABLE();
};


#endif // ROUNDED_PANEL_HPP
