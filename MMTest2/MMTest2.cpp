// ================================================================================================
//
//	MM Test 2
//	==========
//
//	Copyright (C) 2014	Andrew (ADSWNJ) Stokes
//                   All rights reserved
//
//	Description:
//
//	Just a little MFD to play with Enjo's Module Messaging utils
//
//	Copyright Notice:
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	For full licencing terms, pleaserefer to the GNU General Public License
//	(gpl-3_0.txt) distributed with this release, or see
//	http://www.gnu.org/licenses/.
//
//
//	Credits:
//
//	Orbiter Simulator	(c) 2003-2013 Martin (Martins) Schweiger
// 	MFDButtonPage		(c) 2012-2013 Szymon (Enjo) Ender
//	
//
//	Release History:
//
//	V1.00	Initial Release
// ================================================================================================

#define STRICT
#define ORBITER_MODULE

#include "windows.h"
#include "orbitersdk.h"
#include "MMTest2.hpp"
#include "MMTest2_Cores.hpp"
#include "MMTest2_DialogFunc.hpp"
#include "MFDPersist.hpp"


// =======================================================================
// Global variables

MMTest2_GCore *g_SC;      // points to the static core, root of all persistence
int g_MFDmode;      // holds the mode identifier for our MFD


// =======================================================================
// API interface

DLLCLBK void InitModule (HINSTANCE hDLL)
{
	static char *name = "MMTest2";
	MFDMODESPECEX spec;
	spec.name = name;
	spec.key = OAPI_KEY_T;
	spec.context = NULL;
	spec.msgproc = MMTest2::MsgProc;
	g_MFDmode = oapiRegisterMFDMode (spec);
}

DLLCLBK void ExitModule (HINSTANCE hDLL)
{
	oapiUnregisterMFDMode (g_MFDmode);
}



// Constructor
MMTest2::MMTest2 (DWORD w, DWORD h, VESSEL *vessel, UINT mfd)
: MFD2 (w, h, vessel)
{
  if (!g_SC) {										// Find the static global core 
    g_SC = new MMTest2_GCore;						//  ... if missing, then init the static core (only done once for this addon per run of Orbiter)
  }
  GC = g_SC;

  VC = (MMTest2_VCore*) GC->P.FindVC(vessel);		// Find the vessel core for our vessel
  if (!VC) {
    VC = new MMTest2_VCore(vessel,GC);				// ... if missing, then init the vessel core for our vessel (once for this vessel)
    GC->P.AddVC(vessel, VC);
  }

  LC = (MMTest2_LCore*) GC->P.FindLC(vessel, mfd);	// Find the local core doe this vessel + mfd combination
  if (!LC) {
    LC = new MMTest2_LCore(vessel,mfd,GC);			// ... if missing, init the local core once per vessel + mfd position
    GC->P.AddLC(vessel, mfd, LC);
  }

  //
  // Set up core components for this MFD instance
  //

  font = oapiCreateFont (h/25, true, "Fixed", FONT_NORMAL, 0);

}

// ===========================================================================
// Destructor (called any time our MFD goes out of scope ... e.g. on F8 press)
MMTest2::~MMTest2 ()
{
  return;
}


// ==============================================================
// MFD message parser
int MMTest2::MsgProc (UINT msg, UINT mfd, WPARAM wparam, LPARAM lparam)
{
	switch (msg) {
	case OAPI_MSG_MFD_OPENED:
		return (int)(new MMTest2 (LOWORD(wparam), HIWORD(wparam), (VESSEL*)lparam, mfd));
	}
	return 0;
}



// ==============================================================
// Persistence functions
void MMTest2::ReadStatus(FILEHANDLE scn) {
  return;
}

void MMTest2::WriteStatus(FILEHANDLE scn) const {
  return;
}



