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



#ifndef _MMTest2_BUTTON_CLASS
#define _MMTest2_BUTTON_CLASS
#include "MFDButtonPage.hpp"

class MMTest2;

class MMTest2_Buttons : public MFDButtonPage<MMTest2>
{
  public:
    MMTest2_Buttons();
  protected:
    bool SearchForKeysInOtherPages() const;
  private:
};
#endif // _MMTest2_BUTTON_CLASS

