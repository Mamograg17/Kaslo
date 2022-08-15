/*
 Name: frame.cpp

 Purpose: definations of the GUI classes and functions.

 Author: mamograg(Akram Ouizid)
 
 Created: 09/06/2022

*/

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/dialog.h>
#include <wx/checklst.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include <iostream>

class Panel : public wxPanel
{

 public:

 Panel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
 
 void backup(wxCommandEvent & event);

 wxCheckListBox * partitionsBox;
 wxStaticLine * staticLine;
 wxButton * backupButton;
 wxDialog * backupDialog;
 wxPanel * dialogPanel;
 wxTextCtrl* loggingTextCtrl;

 enum IDs
 {
  backupButtonID
 };

};

class frame : public wxFrame
{

  public:
  frame(const wxString & title);
  Panel * panelObject;

};

