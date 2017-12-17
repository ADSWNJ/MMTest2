// ==============================================================
//
//	MMTest2 (Dialog Function Handlers)
//	===============================
//
//	Copyright (C) 2013	Andrew (ADSWNJ) Stokes
//                   All rights reserved
//
//	See MMTest2.cpp
//
// ==============================================================

#include "MMTest2_DialogFunc.hpp"
#include "MMTest2_Cores.hpp"
#include <EnjoLib/ModuleMessagingExt.hpp>

bool MMTest2_DialogFunc::clbkSIL(void *id, char *str, void *usrdata) {
	int parami; 

	if (strlen(str) == 0) return true;      // Empty string - assume canceled dialog
	if (sscanf_s(str,"%d",&parami) != 1) return true; // 0 or 2+ values found - ignore
  
	MMTest2_LCore* LC = (MMTest2_LCore*) usrdata;
	MMTest2_VCore* VC = LC->VC;

	VC->TestIntL = parami;
	VC->ModMsgPut("I",VC->TestIntL,VC->v);
	return true;
}

bool MMTest2_DialogFunc::clbkSDL(void *id, char *str, void *usrdata) {
	float paramf; 

	if (strlen(str) == 0) return true;      // Empty string - assume canceled dialog
	if (sscanf_s(str,"%f",&paramf) != 1) return true; // No double value found - ignore
  
	MMTest2_LCore* LC = (MMTest2_LCore*) usrdata;
	MMTest2_VCore* VC = LC->VC;

	VC->TestDblL = paramf;
	VC->ModMsgPut("D",VC->TestDblL,VC->v);
	return true;
}

bool MMTest2_DialogFunc::clbkSVL(void *id, char *str, void *usrdata) {
	float paramf1, paramf2, paramf3; 

	if (strlen(str) == 0) return true;      // Empty string - assume canceled dialog
	if (sscanf_s(str,"%f %f %f",&paramf1,&paramf2,&paramf3) != 3) return true; // No 3x doubles found - ignore
  
	MMTest2_LCore* LC = (MMTest2_LCore*) usrdata;
	MMTest2_VCore* VC = LC->VC;

	VC->TestVecL = _V(paramf1,paramf2,paramf3);
	VC->ModMsgPut("V",VC->TestVecL,VC->v);
	return true;
}
