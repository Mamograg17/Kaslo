/*
 Name: application.cpp

 Purpose: this file holdes the declation and the implementation of the 
          main application's class.

 Author: mamograg(Akram Ouizid)
 
 Created: 09/06/2022

*/
#include "application.hpp"
#include "frame.hpp"

IMPLEMENT_APP(application);

bool application::OnInit()
{
   frame * applicationFrame = new frame("KasloGUI");

   applicationFrame->Show();
   
   return true;
}
