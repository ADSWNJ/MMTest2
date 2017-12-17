// ==========================================================================
//
//	MMTest2 (Local (Vessel+MFD Panel) Core Persistence)
//	================================================
//
//	Copyright (C) 2013	Andrew (ADSWNJ) Stokes
//                   All rights reserved
//
//	See MMTest2.cpp
//
// ==========================================================================

#include "MMTest2_Cores.hpp"

MMTest2_LCore::MMTest2_LCore(VESSEL *vin, UINT mfdin, MMTest2_GCore* gcin) {
  GC = gcin;
  v = vin;
  m = mfdin;

  VC = (MMTest2_VCore*) GC->P.FindVC(v);

  showMessage = false;
  okMessagePage = true;
  return;
}
