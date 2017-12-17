// ==============================================================
//
//	MMTest2 (MFD Button Management)
//	============================
//
//	Copyright (C) 2013	Andrew (ADSWNJ) Stokes
//                   All rights reserved
//
//	See MMTest2.cpp
//
// ==============================================================

#include "MFDButtonPage.hpp"
#include "MMTest2_Buttons.hpp"
#include "MMTest2.hpp"


MMTest2_Buttons::MMTest2_Buttons() 
{
    // The menu descriptions of all buttons
    static const MFDBUTTONMENU mnu0[] =
    {
      {"Set Int", 0, 'I'},
      {"Set Double", 0, 'D'},
      {"Set Vec", 0, 'V'},
      {"Get Int", 0, '1'},
      {"Get Double", 0, '2'},
      {"Get Vec", 0, '3'},
      {"Get Struc", 0, '4'},
      {"Get BaseSync", 0, '5'},
      {"Get Char*", 0, '6'}
    };

    RegisterPage(mnu0, sizeof(mnu0) / sizeof(MFDBUTTONMENU));

    RegisterFunction("SIL", OAPI_KEY_I, &MMTest2::Button_SIL);
    RegisterFunction("SDL", OAPI_KEY_D, &MMTest2::Button_SDL);
    RegisterFunction("SVL", OAPI_KEY_V, &MMTest2::Button_SVL);
    RegisterFunction("GIR", OAPI_KEY_1, &MMTest2::Button_GIR);
    RegisterFunction("GDR", OAPI_KEY_2, &MMTest2::Button_GDR);
    RegisterFunction("GVR", OAPI_KEY_3, &MMTest2::Button_GVR);
    RegisterFunction("GSR", OAPI_KEY_4, &MMTest2::Button_GSR);
    RegisterFunction("GBS", OAPI_KEY_5, &MMTest2::Button_GBS);
    RegisterFunction("GCS", OAPI_KEY_6, &MMTest2::Button_GCS);

    return;
}

bool MMTest2_Buttons::SearchForKeysInOtherPages() const
{
    return false;
}



