/*
 Name: frame.cpp

 Purpose: declarations of the GUI classes and functions.

 Author: mamograg(Akram Ouizid)
 
 Created: 09/06/2022

*/


#include "frame.hpp"

//decalare the main panel
Panel::Panel(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name): wxPanel(parent)

{
 

 partitionsBox = new wxCheckListBox(this,wxID_ANY,wxPoint(5,5),wxSize(340,300));

 //add partitions' names to wxCheckListBox and give them IDs
 partitionsBox->Insert("vendor",0);
 partitionsBox->Insert("vbmeta",1);
 partitionsBox->Insert("system",2);
 partitionsBox->Insert("boot",3);
 partitionsBox->Insert("dtb",4);
 partitionsBox->Insert("dtbo",5);
 partitionsBox->Insert("recovery",6);
 partitionsBox->Insert("cache",7);
 partitionsBox->Insert("userdata",8);
 
 staticLine = new wxStaticLine(this,wxID_ANY,wxPoint(5,312),wxSize(340,3));
 
 //this button will run the backup function
 backupButton = new wxButton(this,backupButtonID,"backup",wxPoint(280,320),wxSize(70,40));
 
 //bind "panel::backup" function to "backupButton"
 backupButton->Bind(wxEVT_BUTTON,&Panel::backup,this);

}

frame::frame(const wxString & title) : wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(350,368))
{

 panelObject = new Panel(this);

}

void Panel::backup(wxCommandEvent & event)
{

 wxArrayInt chosenPartitionsIDs;
 
 //Get the checked partitions' IDs and add them to chosenPartitionsIDs array
 partitionsBox->GetCheckedItems(chosenPartitionsIDs);

 
 backupDialog = new wxDialog(this,wxID_ANY," ",wxDefaultPosition,wxSize(300,140));
 backupDialog->Show();

 dialogPanel = new wxPanel(backupDialog,wxID_ANY,wxDefaultPosition,wxSize(300,140));
 dialogPanel->Show();

 loggingTextCtrl = new wxTextCtrl(dialogPanel,wxID_ANY," ",wxPoint(1,1),wxSize(299,100),wxTE_MULTILINE);
 loggingTextCtrl->Show();
 loggingTextCtrl->SetEditable(false);

 for (int i = 0; i < chosenPartitionsIDs.GetCount(); i++)
 {

   int id = chosenPartitionsIDs[i];
   
   //get the current i partitions' name and store it in a string
   const wxString partitionName = partitionsBox->GetString(id);

   wxString text = "Backup of "+ partitionName + " partition in progress...";

   loggingTextCtrl->AppendText(text);

   //put he backup command in a wxString and run system function
   wxString fullCommand = "adb pull /dev/block/by-name/"+ partitionsBox->GetString(id) +" "+partitionsBox->GetString(id)+".img";
   system(fullCommand.c_str());

   text = loggingTextCtrl->GetLabel() + "\n" + "Backup up done." + "\n" + "--------------------------------------------------------------------------\n";
   loggingTextCtrl->AppendText(text);

 }
   
}
