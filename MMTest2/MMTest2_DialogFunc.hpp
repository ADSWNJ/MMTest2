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


#ifndef __MMTest2_DIALOGFunc
#define __MMTest2_DIALOGFunc

class MMTest2_DialogFunc
{
    public:
      static bool clbkSIL(void *id, char *str, void *usrdata);
      static bool clbkSDL(void *id, char *str, void *usrdata);
      static bool clbkSVL(void *id, char *str, void *usrdata);
    protected:
    private:

};

#endif // MMTest2_DIALOGTGT