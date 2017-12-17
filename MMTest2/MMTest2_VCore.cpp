// ==============================================================
//
//	MMTest2 (Vessel Core Persistence)
//	==============================
//
//	Copyright (C) 2013	Andrew (ADSWNJ) Stokes
//                   All rights reserved
//
//	See MMTest2.cpp
//
// ==============================================================

#include "MMTest2_Cores.hpp"
#include "ParseFunctions.h"
#include "EnjoLib\ModuleMessagingExt.hpp"
#include <stdio.h>
#include <math.h>

MMTest2_VCore::MMTest2_VCore(VESSEL *vin, MMTest2_GCore* gcin) {
	GC = gcin;
	v = vin;

	TestIntL = 2;
	TestDblL = 2.222;
	TestVecL = _V(2.202, 2.202, 2.202);
	
	ModMsgPut("I",TestIntL,v);
	ModMsgPut("D",TestDblL,v);
	ModMsgPut("V",TestVecL,v);

	TestIntR = 0;
	TestDblR = 0;
	TestVecR = _V(0,0,0);

	goodVar[0] = 0;
	goodVar[1] = 0;
	goodVar[2] = 0;	
	goodVar[3] = 0;
  goodVar[4] = 0;

	BaseSync_locked = false;
	return;
};

MMTest2_VCore::~MMTest2_VCore() {
}
