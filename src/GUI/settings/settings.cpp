#include "settings.hpp"

void ApplyPanelSettings(wxPanel* panel) {
    wxColour panelBgColor(19, 22, 25); // Темно синий
//    wxColour panelBgColor(255, 255, 255);
    panel->SetBackgroundColour(panelBgColor);
}

void ApplyRoundedPanelSettings(wxPanel* panel) {
    wxColour panelBgColor(29, 34, 39);
    wxColour textColor(255, 255, 255);
    panel->SetBackgroundColour(panelBgColor);
    panel->SetForegroundColour(textColor);

    wxFont textFont(40, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    panel->SetFont(textFont);
}

void ApplyButtonSettings(wxButton* button) {
    wxColour buttonBgColor(0, 120, 215); // Синий цвет фона
    wxColour buttonFgColor(255, 255, 255); // Белый цвет текста
    button->SetBackgroundColour(buttonBgColor);
    button->SetForegroundColour(buttonFgColor);

    wxFont buttonFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    button->SetFont(buttonFont);
}

void ApplyLabelSettings(wxStaticText* label) {
    wxColour labelFgColor(255, 255, 255); // Черный цвет текста
    label->SetForegroundColour(labelFgColor);

    wxFont labelFont(24, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    label->SetFont(labelFont);
}
