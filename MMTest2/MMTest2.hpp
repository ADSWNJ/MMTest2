// ==============================================================
//
//	Bare Bones Auto Pilot (MMTest2)
//	============================
//
//	Copyright (C) 2014	Andrew (ADSWNJ) Stokes
//                   All rights reserved
//
//	See MMTest2.cpp
//
// ==============================================================


#ifndef __MMTest2_H
#define __MMTest2_H

#include "MMTest2_Cores.hpp"   

class MMTest2: public MFD2
{
public:
	MMTest2 (DWORD w, DWORD h, VESSEL *vessel, UINT mfd);
	~MMTest2 ();
	
  char *ButtonLabel (int bt);
	int ButtonMenu (const MFDBUTTONMENU **menu) const;
  bool ConsumeKeyBuffered (DWORD key);
  bool ConsumeButton (int bt, int event);
  
  bool Update (oapi::Sketchpad *skp);
  static int MsgProc (UINT msg, UINT mfd, WPARAM wparam, LPARAM lparam);

  // Button Press Handlers
  void Button_SIL();
  void Button_SDL();
  void Button_SVL();
  void Button_GIR();
  void Button_GDR();
  void Button_GVR();
  void Button_GSR();
  void Button_GBS();
  void Button_GCS();

  const char* GetModuleName() const;

  // Persistence functions
  void ReadStatus(FILEHANDLE scn);
  void WriteStatus(FILEHANDLE scn) const;

  // Unit conversions
  double id( double d ) const;
  double ed( double d ) const;

protected:
  MMTest2_GCore* GC;
  MMTest2_LCore* LC;
  MMTest2_VCore* VC;

  int Line( int row );
  int Col( int pos );
  int Col2( int pos );
  void ShowMessage(oapi::Sketchpad *skp);
  void DisplayEngUnit(char* buf, char* fmt, double val);

  oapi::Font *font;


};

#endif // !__MMTest2_H