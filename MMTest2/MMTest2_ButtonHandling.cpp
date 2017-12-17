// ==============================================================
//
//	MMTest2 (Button Handling Code)
//	============================
//
//	Copyright (C) 2013	Andrew (ADSWNJ) Stokes
//                   All rights reserved
//
//	See MMTest2.cpp
//
// ==============================================================

#include "MMTest2.hpp"
#include "MMTest2_DialogFunc.hpp"
#include <EnjoLib/ModuleMessagingExt.hpp>

// ==============================================================
// MFD button hooks to Button Page library
//
char* MMTest2::ButtonLabel (int bt)
{
	return LC->B.ButtonLabel(bt);
}

// Return button menus
int MMTest2::ButtonMenu (const MFDBUTTONMENU **menu) const
{
	return LC->B.ButtonMenu(menu);
}

// Return clicked button
bool MMTest2::ConsumeButton (int bt, int event) {
  return LC->B.ConsumeButton(this, bt, event);
}

// Return pressed keystroke
bool MMTest2::ConsumeKeyBuffered (DWORD key) {
  return LC->B.ConsumeKeyBuffered(this, key);
}



// ==============================================================
// MFD Button Handler Callbacks
//


// SIL = Set Integer Local
void MMTest2::Button_SIL() {
  sprintf_s(VC->TargetText,128,"%d",VC->TestIntL);
  oapiOpenInputBox( "Enter Test Int",MMTest2_DialogFunc::clbkSIL, VC->TargetText, 30, LC);
  return;
};

// SDL = Set Double Local
void MMTest2::Button_SDL() {
  sprintf_s(VC->TargetText,128,"%.3f",VC->TestDblL);
  oapiOpenInputBox( "Enter Test Dbl",MMTest2_DialogFunc::clbkSDL, VC->TargetText, 30, LC);
  return;
};

// SIL = Set Vector Local
void MMTest2::Button_SVL() {
	sprintf_s(VC->TargetText,128,"%.3f %.3f %.3f",VC->TestVecL.x,VC->TestVecL.y,VC->TestVecL.z);
	oapiOpenInputBox( "Enter Test Vec",MMTest2_DialogFunc::clbkSVL, VC->TargetText, 80, LC);
  return;
};


// GIR = Get Integer Remote
void MMTest2::Button_GIR() {
	int i;
	if (EnjoLib::ModuleMessagingExt().ModMsgGet("MMTest1","I", &i,VC->v)) {
		VC->TestIntR = i;
		VC->goodVar[0] = 1;
	} else {
		VC->TestIntR = 0;
		VC->goodVar[0] = -1;
	}
	return;
};

// GDR = Get Double Remote
void MMTest2::Button_GDR() {
	double d;
	if (EnjoLib::ModuleMessagingExt().ModMsgGet("MMTest1","D", &d, VC->v)) {
		VC->TestDblR = d;
		VC->goodVar[1] = 1;
	} else {
		VC->TestDblR = 0.0;
		VC->goodVar[1] = -1;
	}
	return;
};

// GVR = Get Vector Remote
void MMTest2::Button_GVR() {
	VECTOR3 vec;
	if (EnjoLib::ModuleMessagingExt().ModMsgGet("MMTest1","V", &vec, VC->v)) {
		VC->TestVecR = vec;
		VC->goodVar[2] = 1;
	} else {
		VC->TestVecR = _V(0.0,0.0,0.0);
		VC->goodVar[2] = -1;
	}
	return;
};

// GVR = Get Struct Remote
void MMTest2::Button_GSR() {

	if (EnjoLib::ModuleMessagingExt().ModMsgGetByRef("MMTest1","SafePtr_V1",13, &(VC->imps),VC->v)) {
		VC->goodVar[3] = 1;
	} else {
		VC->imps = nullptr;
		VC->goodVar[3] = -1;
	}

	return;
};


// GVR = Get Base Sync
void MMTest2::Button_GBS() {

	VC->BaseSync_locked = EnjoLib::ModuleMessagingExt().ModMsgGetByRef("BaseSyncMFD","BaseSyncTarget", 1, &(VC->BS_trgt),VC->v) &&
							EnjoLib::ModuleMessagingExt().ModMsgGetByRef("BaseSyncMFD","BaseSyncMode", 1, &(VC->BS_mode),VC->v) &&
							EnjoLib::ModuleMessagingExt().ModMsgGetByRef("BaseSyncMFD","BaseSyncSolution", 2, &(VC->BS_sol),VC->v) &&
							EnjoLib::ModuleMessagingExt().ModMsgGetByRef("BaseSyncMFD","BaseSyncDeorbitBurn", 2, &(VC->BS_deo),VC->v);
	return;
};

// GCS = Get Char * Remote
void MMTest2::Button_GCS() {

  if (EnjoLib::ModuleMessagingExt().ModMsgGet_Dyn("MMTest1", "STR", VC->TargetText, 128)) {
    VC->goodVar[4] = 1;
  } else {
    strcpy(VC->TargetText, "Failed!");
    VC->goodVar[4] = -1;
  }
  return;
};