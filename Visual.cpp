// Don't take credits for this ;) Joplin / Manhhao are the first uploaders ;)

#include "Visuals.h"
#include "Interfaces.h"
#include "RenderManager.h"
#include "Autowall.h"
#include "Options.h"

#define M_PI 3.14159265358979323846
void CVisuals::Init() {}

void CVisuals::Move(CUserCmd *pCmd, bool &bSendPacket) {}

void CVisuals::Draw()
{
	IClientEntity* pLocal = hackManager.pLocal();


	DrawAutowallCrosshair();
	if (options.Rage.DrawCrosshair)
		DrawCrosshair();

	if (options.Rage.OtherRecoilCrosshair)
		DrawRecoilCrosshair();

	if (options.Rage.SpreadCrosshair)
		SpreadCrosshair();

	if (options.Rage.OtherNoScope && pLocal->IsScoped() && pLocal->IsAlive() && Interfaces::Engine->IsConnected() && Interfaces::Engine->IsInGame()) {
		RECT View = Render::GetViewport();
		int MidX = View.right / 2;
		int MidY = View.bottom / 2;
		Render::Line(MidX, MidY - 3000, MidX, MidY + 3000, Color(0, 0, 0, 255));
		Render::Line(MidX - 3000, MidY, MidX + 3000, MidY, Color(0, 0, 0, 255));
	}	
}

void CVisuals::DrawAutowallCrosshair()
{
	float damage = 0.f;
	if (CanWallbang(damage))
	{
		RECT View = Render::GetViewport();
		int MidX = View.right / 2;
		int MidY = View.bottom / 2;
		char buffer[64];
		sprintf_s(buffer, "Damage: %.1f", damage);
		Render::Text(MidX - 8, MidY - 8, Color(0, 255, 0, 255), Render::Fonts::ESP, buffer);
	}
	else
	{
		//	Draw->Rect(MidX - 2, MidY - 2, 5, 5, Color(255, 0, 0));
	}
}
void CVisuals::DrawCrosshair() { 
	RECT View = Render::GetViewport();
	int MidX = View.right / 2;
	int MidY = View.bottom / 2;
	Render::Line(MidX - 8, MidY - 8, MidX + 8, MidY + 8, Color(0, 0, 0, 200));
	Render::Line(MidX + 8, MidY - 8, MidX - 8, MidY + 8, Color(0, 0, 0, 200));
	Render::Line(MidX - 4, MidY - 4, MidX + 4, MidY + 4, Color(0, 255, 0, 255));
	Render::Line(MidX + 4, MidY - 4, MidX - 4, MidY + 4, Color(0, 255, 0, 255));
}

void CVisuals::DrawRecoilCrosshair() {

	if (Menu::Window.RageBotTab.AccuracyRecoil.GetState())
		return;

	IClientEntity *pLocal = hackManager.pLocal();

	Vector ViewAngles;
	Interfaces::Engine->GetViewAngles(ViewAngles);
	ViewAngles += pLocal->localPlayerExclusive()->GetAimPunchAngle() * 2.f;

	Vector fowardVec;
	AngleVectors(ViewAngles, &fowardVec);
	fowardVec *= 10000;

	Vector start = pLocal->GetOrigin() + pLocal->GetViewOffset();
	Vector end = start + fowardVec, endScreen;

	if (Render::WorldToScreen(end, endScreen) && pLocal->IsAlive())
	{
		Render::Line(endScreen.x - 4, endScreen.y - 4, endScreen.x + 4, endScreen.y + 4, Color(0, 255, 0, 255));
		Render::Line(endScreen.x + 4, endScreen.y - 4, endScreen.x - 4, endScreen.y + 4, Color(0, 255, 0, 255));
		Render::Line(endScreen.x - 2, endScreen.y - 2, endScreen.x + 2, endScreen.y + 2, Color(0, 0, 0, 200));
		Render::Line(endScreen.x + 2, endScreen.y - 2, endScreen.x - 2, endScreen.y + 2, Color(0, 0, 0, 200));
	}
}

void CVisuals::SpreadCrosshair() 
{
		IClientEntity *pLocal = hackManager.pLocal();
		CBaseCombatWeapon* pWeapon = (CBaseCombatWeapon*)Interfaces::EntList->GetClientEntityFromHandle(pLocal->GetActiveWeaponHandle());
		IClientEntity* WeaponEnt = Interfaces::EntList->GetClientEntityFromHandle(pLocal->GetActiveWeaponHandle());

		if (!hackManager.pLocal()->IsAlive())
			return;

		if (!GameUtils::IsBallisticWeapon(pWeapon))
			return;

		if (pWeapon == nullptr)
			return;

		int xs;
		int ys;
		Interfaces::Engine->GetScreenSize(xs, ys);
		xs /= 2; ys /= 2;


		float inaccuracy = pWeapon->GetInaccuracy() * 1000;
		if (inaccuracy <= 20)
			Render::DrawFilledCircle(Vector2D(xs, ys), Color(21, 21, 21, 125), inaccuracy, 60);
		else if (inaccuracy > 20 && inaccuracy <= 100)
			Render::DrawFilledCircle(Vector2D(xs, ys), Color(26, 24, 19, 125), inaccuracy, 60);
		else Render::DrawFilledCircle(Vector2D(xs, ys), Color(40, 10, 10, 125), inaccuracy, 60);


		if (pWeapon)
		{


			char buffer4[64];
			sprintf_s(buffer4, "Spread:  %.00f", inaccuracy);

			if (inaccuracy < 20)
				Render::Text(xs + inaccuracy + 4, ys, Color(5, 255, 80, 255), Render::Fonts::ESP, buffer4);
			else if (inaccuracy >= 20 && inaccuracy < 100)
				Render::Text(xs + inaccuracy + 4, ys, Color(255, 60, 20, 255), Render::Fonts::ESP, buffer4);
			else
				Render::Text(xs + inaccuracy + 4, ys, Color(255, 10, 170, 255), Render::Fonts::ESP, buffer4);
		}


		else
		{

			Render::Text(10, 70, Color(180, 20, 255, 255), Render::Fonts::ESP, "Spread: --");
		}

	}