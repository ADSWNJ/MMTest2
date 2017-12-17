// ==============================================================
//
//	MMTest2 (MFD Update)
//	=================
//
//	Copyright (C) 2013	Andrew (ADSWNJ) Stokes
//                   All rights reserved
//
//	See MMTest2.cpp
//
// ==============================================================

#include "MMTest2.hpp"

bool MMTest2::Update (oapi::Sketchpad *skp)
{

  Title (skp, "MMTest2 w/MM Ext");
	// Draws the MFD title

  int l = 4;
  char buf[128];
  char buf2[128];

	skp->SetTextAlign (oapi::Sketchpad::LEFT, oapi::Sketchpad::BOTTOM);
	skp->SetTextColor (0x00FFFF);

  sprintf_s(buf,128,"Set Locally");
  skp->Text (Col(1), Line(l++), buf, strlen(buf));
	
	sprintf_s(buf,128,"I: %d",VC->TestIntL);
  skp->Text (Col(1), Line(l++), buf, strlen(buf));

  sprintf_s(buf,128,"D: %.3f",VC->TestDblL);
  skp->Text (Col(1), Line(l++), buf, strlen(buf));

  sprintf_s(buf,128,"V: %.3f %.3f %.3f",VC->TestVecL.x,VC->TestVecL.y,VC->TestVecL.z);
  skp->Text (Col(1), Line(l++), buf, strlen(buf));

	l++;
  sprintf_s(buf,128,"Get Remotely");
  skp->Text (Col(1), Line(l++), buf, strlen(buf));

	switch (VC->goodVar[0]) {
	case -1:
		sprintf_s(buf,128,"I: <fail>");
		break;
	case 0:
		sprintf_s(buf,128,"I: <unset>");
		break;
	case 1:
		sprintf_s(buf,128,"I: %d",VC->TestIntR);
		break;
	}
  skp->Text (Col(1), Line(l++), buf, strlen(buf));

	switch (VC->goodVar[1]) {
	case -1:
		sprintf_s(buf,128,"D: <fail>");
		break;
	case 0:
		sprintf_s(buf,128,"D: <unset>");
		break;
	case 1:
		sprintf_s(buf,128,"D: %.3f",VC->TestDblR);
		break;
	}
  skp->Text (Col(1), Line(l++), buf, strlen(buf));

	switch (VC->goodVar[2]) {
	case -1:
		sprintf_s(buf,128,"V: <fail>");
		break;
	case 0:
		sprintf_s(buf,128,"V: <unset>");
		break;
	case 1:
		sprintf_s(buf,128,"V: %.3f %.3f %.3f",VC->TestVecR.x,VC->TestVecR.y,VC->TestVecR.z);
		break;
	}
  skp->Text (Col(1), Line(l++), buf, strlen(buf));

	switch (VC->goodVar[3]) {
	case -1:
		sprintf_s(buf,128,"S: <fail>");
	  skp->Text (Col(1), Line(l++), buf, strlen(buf));
		break;
	case 0:
		sprintf_s(buf,128,"S: <unset>");
	  skp->Text (Col(1), Line(l++), buf, strlen(buf));
		break;
	case 1:
		sprintf_s(buf,128,"S: %s",VC->imps->safeName);
	  skp->Text (Col(1), Line(l++), buf, strlen(buf));
//		sprintf_s(buf,128,"S: %d",VC->s->blah);
//	  skp->Text (Col(1), Line(l++), buf, strlen(buf));
//		sprintf_s(buf,128,"S: %.9f",VC->s->dd);
//	  skp->Text (Col(1), Line(l++), buf, strlen(buf));
		break;
	}

  switch (VC->goodVar[4]) {
  case -1:
    sprintf_s(buf, 128, "T: <fail>");
    skp->Text(Col(1), Line(l++), buf, strlen(buf));
    break;
  case 0:
    sprintf_s(buf, 128, "T: <unset>");
    skp->Text(Col(1), Line(l++), buf, strlen(buf));
    break;
  case 1:
    sprintf_s(buf, 128, "T: %s", VC->TargetText);
    skp->Text(Col(1), Line(l++), buf, strlen(buf));
    break;
  }

	if (VC->BaseSync_locked) {
		l++;
		sprintf_s(buf,128,"BaseSyncMFD Status: Connected");
		skp->Text (Col(0), Line(l++), buf, strlen(buf));

		sprintf_s(buf,128,"Ref/Tgt: %s/%s",VC->BS_trgt->ref,VC->BS_trgt->name);
		skp->Text (Col(0), Line(l++), buf, strlen(buf));
		sprintf_s(buf,128,"Lat/Lon: %5.3f %5.3f",VC->BS_trgt->lat*DEG, VC->BS_trgt->lon*DEG);
		skp->Text (Col(0), Line(l++), buf, strlen(buf)); l++;

		if (VC->BS_mode->deo) {
			sprintf_s(buf,128,"Deorbit mode:");
			skp->Text (Col(0), Line(l++), buf, strlen(buf));
			if (VC->BS_deo->dataValid) {
				sprintf_s(buf,128,"Alignment: Retrograde");
				skp->Text (Col(0), Line(l++), buf, strlen(buf));

				DisplayEngUnit(buf2, "%3.3f%c", VC->BS_deo->tToBurn);
				sprintf_s(buf,128,"Burn Time: %ssec", buf2);
				skp->Text (Col(0), Line(l++), buf, strlen(buf));

				DisplayEngUnit(buf2, "%3.3f%c", VC->BS_deo->dV);
				sprintf_s(buf,128,"Delta V:   %sm/s", buf2);
				skp->Text (Col(0), Line(l++), buf, strlen(buf));

				DisplayEngUnit(buf2, "%3.3f%c", VC->BS_deo->tBurn);
				sprintf_s(buf,128,"Duration:   %ss", buf2);
				skp->Text (Col(0), Line(l++), buf, strlen(buf));
			} else {
				sprintf_s(buf,128,"No current solution");
				skp->Text (Col(0), Line(l++), buf, strlen(buf));
			}

		} else {
			sprintf_s(buf,128,"Base align mode:");
			skp->Text (Col(0), Line(l++), buf, strlen(buf));

			if (VC->BS_sol->dataValid) {
				if (VC->BS_sol->nmlBurn) {
					sprintf_s(buf,128,"Alignment: Normal");
				} else {
					sprintf_s(buf,128,"Alignment: Anti-Normal");
				}
				skp->Text (Col(0), Line(l++), buf, strlen(buf));

				DisplayEngUnit(buf2, "%3.3f%c", VC->BS_sol->tToBurn);
				sprintf_s(buf,128,"Burn Time: %ssec", buf2);
				skp->Text (Col(0), Line(l++), buf, strlen(buf));

				DisplayEngUnit(buf2, "%3.3f%c", VC->BS_sol->dV);
				sprintf_s(buf,128,"Delta V:   %sm/s", buf2);
				skp->Text (Col(0), Line(l++), buf, strlen(buf));

				DisplayEngUnit(buf2, "%3.3f%c", VC->BS_sol->tBurn);
				sprintf_s(buf,128,"Duration:   %ss", buf2);
				skp->Text (Col(0), Line(l++), buf, strlen(buf));
			} else {
				sprintf_s(buf,128,"No current solution");
				skp->Text (Col(0), Line(l++), buf, strlen(buf));
			}
		}
	}
	return true;
}

// MFD Line formatting helper
void MMTest2::ShowMessage(oapi::Sketchpad *skp) {

  char localMsg[750];
  strcpy_s(localMsg,750, LC->Message.c_str());
  char *bp = localMsg;
  char *bp2 = localMsg;
  char *bp3;
  char c1, c2;
  int i = 0;
  int j;
  int l = 4;
  bool eol = false;

  do {
    if ((*bp2 == '\n') || (*bp2 == '\0')) {     // Look for user newline or end of buffer
      eol = true;
      c1 = *bp2;
      *bp2 = '\0';
    } else {
      if (i==34) {                              // 34 chars no newline ... need to break the line
        eol=true;
        bp3 = bp2;
        for (j=34; j>20; j--) {                 // look for a space from 21 to 34
          if (*bp3==' ') break;
          bp3--;
        }
        if (j>20) {                             // space found
          bp2 = bp3;
          c1 = *bp2;
          *bp2 = '\0';
        } else {                                // no space ... insert hyphen
          bp3 = bp2 + 1;
          c1 = *bp2;
          c2 = *bp3;
          *bp2 = '-';
          *bp3 = '\0';
        }
      } else {                                  // Scan forward      
        i++;
        bp2++;
      }
    }

    if (eol) {                                  // EOL flag ... write out buffer from bp to bp2.
  	  skp->Text (Col(0), Line(l++), bp, strlen(bp));
      eol = false;
      if (c1 == '\0') {
        bp = bp2;     // End of buffer
      } else if ((c1 == '\n') || (c1 == ' ')) {
        bp = bp2+1;   // Reset for next line of the buffer
        bp2++;
        i=0;
      } else {
        bp = bp2;     // Put back the chars we stomped
        *bp2 = c1;
        *bp3 = c2;
        i=0;
      }
    }
  } while (*bp);

  return;
}


// MFD Positioning Helper Functions
int MMTest2::Line( int row ) {  // row is 0-24, for 24 rows. e.g. Line(12)
  int ret;
  ret = (int) ((H-(int)(ch/4)) * row / 25) + (int) (ch/4);
  return ret;
};

int MMTest2::Col( int pos ) {  // pos is 0-5, for 6 columns. Eg Col(3) for middle
  int ret = (int) ((W-(int)(cw/2)) * pos / 6) + int (cw/2);
  return ret;
};

int MMTest2::Col2( int pos ) {  // pos is 0-11, for 12 columns. Eg Col(6) for middle
  int ret = (int) ((W-(int)(cw/2)) * pos / 12) + int (cw/2);
  return ret;
};

// DisplayEngUnit ... Simple conversion of value into engineering format
void MMTest2::DisplayEngUnit(char* buf, char* fmt, double val) {
  char engUnit[12] = "pnum kMGTPE";
  double cnvVal = val;
  int i = 4;

  if (fabs(cnvVal) < 1) {
	  while ((fabs(cnvVal) < 1) && (i>0)) {
		  i--;
		  cnvVal *= 1000.0;
	  }
  } else if (fabs(cnvVal) >= 1000.0) {
    while ((fabs(cnvVal) >= 1000.0) && (i< 10.0)) {
		  i++;
		  cnvVal /= 1000.0;
	  }
  }
  sprintf_s(buf, 256, fmt, cnvVal, engUnit[i]);
}