#include "roundedPanel.hpp"
#include <wx/wx.h>

wxBEGIN_EVENT_TABLE(RoundedPanel, wxPanel)
EVT_PAINT(RoundedPanel::OnPaint)
wxEND_EVENT_TABLE()

RoundedPanel::RoundedPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, int radius)
        : wxPanel(parent, id, pos, size, wxBORDER_NONE), m_radius(radius), m_bgColour(*wxRED), m_tColor(*wxRED) {
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

bool RoundedPanel::SetBackgroundColour(const wxColour& colour) {
    m_bgColour = colour;
    Refresh();
    return wxPanel::SetBackgroundColour(colour);
}

bool RoundedPanel::SetForegroundColour(const wxColour& colour) {
    m_tColor = colour;
    Refresh();
    return wxPanel::SetForegroundColour(colour);
}

void RoundedPanel::SetText(const wxString& text) {
    m_text = text;
    Refresh();
}

void RoundedPanel::OnPaint(wxPaintEvent& event) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxSize size = GetSize();
    int width = size.GetWidth();
    int height = size.GetHeight();
    int shadowOffset = 5;

    // Смещение тени
    int offsetX = 0;
    int offsetY = 2;

    // Полная очистка фона
    dc.SetBrush(wxBrush(GetParent()->GetBackgroundColour(), wxBRUSHSTYLE_SOLID));
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRectangle(0, 0, width, height);

    // Рисуем тень с эффектом размытия
    for (int i = 1; i <= 20; ++i) {
        int alpha = 64 / i;
        int blurRadius = m_radius + i;
        dc.SetBrush(wxBrush(wxColour(29, 34, 39, alpha)));
        dc.SetPen(*wxTRANSPARENT_PEN);
        dc.DrawRoundedRectangle(offsetX + i, offsetY + i, width - offsetX - 2 * i, height - offsetY - 2 * i, blurRadius);
    }

    // Рисуем основной закругленный квадрат
    dc.SetBrush(wxBrush(m_bgColour));
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRoundedRectangle(0, 0, width - shadowOffset, height - shadowOffset, m_radius);


    if (!m_text.IsEmpty()) {
        dc.SetTextForeground(m_tColor);
        wxSize textSize = dc.GetTextExtent(m_text);

        // Вычисление координат для центрирования текста
        int x = (width - textSize.GetWidth() - shadowOffset) / 2;
        int y = (height - textSize.GetHeight() - shadowOffset) / 2;

        dc.DrawText(m_text, wxPoint(x, y));
    }
}