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

#include "windows.h"
#include <list>
#include <string>

#include "orbitersdk.h"
#include <EnjoLib/ModuleMessagingExtBase.hpp>
#include <EnjoLib/ModuleMessagingExtPut.hpp>
#include "BaseSyncExports.hpp"

#include "MMTest2_Buttons.hpp"
#include "MFDPersist.hpp"
using namespace std;

#ifndef _MMTest2_CORE_CLASSES
#define _MMTest2_CORE_CLASSES

// Forward reference needed, as the cores all talk to each other. (This is also why the cores are kept together in this single hpp file)
class MMTest2_GCore;
class MMTest_Common {
public:

	std::string name;

};

#pragma pack(push)
#pragma pack(8)
struct ExportStruct : public EnjoLib::ModuleMessagingExtBase {
	ExportStruct():EnjoLib::ModuleMessagingExtBase(13, sizeof(ExportStruct)) {};	
	char safeName[32];
};
#pragma pack(pop)

//+++++
// Vessel Persistence core. One of these is instantiated per Vessel flown with RV Orientation up.
//+++++

class MMTest2_VCore : public EnjoLib::ModuleMessagingExtPut {
	public:
		// Core references ... instantiation, vessel reference and GC.
		MMTest2_VCore(VESSEL *vin, MMTest2_GCore* gcin);
		~MMTest2_VCore();
		MMTest2_GCore* GC;


		const char* ModuleMessagingGetModuleName() const { return "MMTest2"; }


		// Add Vessel data here
		VESSEL *v;

		struct INTERESTING_STRUCT {
			char name[32];
			int blah;
			double dd;
		} *s;

		const ExportStruct *imps;

		char TargetText[128];
		int TestIntL, TestIntR;
		double TestDblL, TestDblR;
		VECTOR3 TestVecL, TestVecR;
    char TestText[256];
		int goodVar[5];

		// Base Sync Exports
		const struct BaseSyncExportTgtStruct *BS_trgt;
		const struct BaseSyncExportModeStruct *BS_mode;
		const struct BaseSyncExportSolStruct *BS_sol;
		const struct BaseSyncExportDeorbitStruct *BS_deo;
		bool BaseSync_locked; 

	private:
};

//+++++
// Local Persistence core. One of these is instantiated per Vessel AND MFD panel location. Local defaults for that combination.
//+++++

class MMTest2_LCore {
	public:
		// Local references ... instantiation, references for vesseland mfd position, and links to the appropriate VC, MC and GC
		MMTest2_LCore(VESSEL *vin, UINT mfdin, MMTest2_GCore* gcin);
		VESSEL *v;
		UINT m;
		MMTest2_GCore* GC;
		MMTest2_VCore* VC;

		// Add local vessel+panel data here

		MMTest2_Buttons B;
		bool showMessage;
		bool okMessagePage;
		string Message;


};

//+++++
// Global Persistence core. One of these is instantiated for the whole orbiter session, on the first launch of this MFD type
//+++++

class MMTest2_GCore {
	public:
		// Global references ... instantiation and a link to the persistence library (running the linked lists)
		MMTest2_GCore();
		MFDPersist P;
    __declspec(dllexport) static bool GlobalCoreEntry();
};

#endif // _MMTest2_CORE_CLASSES