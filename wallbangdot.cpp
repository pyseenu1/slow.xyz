/*#pragma once
 #include "dothelper.h"
 #include "extrahelper.h"
Crosshair crosshair;


void Crosshair::wallbangdot() // this MIGHT be bad
{

if (Menu::Window.VisualsTab.bangdot.GetState());
{
auto plocal = hackManager.pLocal;

if (plocal && plocal->IsAlive())
{
float damage;

int midx, midy;
Interfaces::Engine->GetScreenSize(midx, midy);
midx /= 2; midy /= 2;

Render::otheroutlinerec(midx - 2, midy - 2, 5, 5, Color(27, 27, 27), trace_autowallable(damage) ? Color(130, 241, 13) : Color(255, 102, 102));
}
}

}
*/


/////////////////
/////////////////
//COMING LATER//
////////////////
////////////////