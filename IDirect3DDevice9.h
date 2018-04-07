#pragma once
#include "SDK.h"
#include "Renderer.h"
#include "RenderManager.h"
#include <d3d9.h>
#include "dropboxes.h"
#include "Configs.hpp"
#include "options.h"
#include <unordered_map>
#define M_PI 3.14159265358979323846
uint8_t* m_present;
uint8_t* m_reset;
IDirect3DDevice9* d3d9_device;
typedef HRESULT(__stdcall *EndScene_t) (IDirect3DDevice9*);

typedef HRESULT(__stdcall *Reset_t) (IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);

EndScene_t	oEndScene = nullptr;
Reset_t		oReset = nullptr;

HRESULT __stdcall hkReset(IDirect3DDevice9* thisptr, D3DPRESENT_PARAMETERS* params) {


	if (!renderer->IsReady())
		return oReset(thisptr, params);


	ImGui_ImplDX9_InvalidateDeviceObjects();




	renderer->~Renderer();

	HRESULT result = oReset(thisptr, params);

	ImGui_ImplDX9_CreateDeviceObjects();

	renderer->Initialize(FindWindowA("Valve001", NULL), thisptr);
	Render::Initialise();

	return result;
}

void Light(ImGuiStyle* dst)
{
	ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();

	ImVec4* colors = style->Colors;



	colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);

	colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);

	//colors[ImGuiCol_TextHovered]          = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);

	//colors[ImGuiCol_TextActive]           = ImVec4(1.00f, 1.00f, 0.00f, 1.00f);

	colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);


	colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);

	colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);

	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

	colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);

	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);

	colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);

	colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);

	colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);

	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);

	colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);

	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);

	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);

	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);

	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);

	colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);

	colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);

	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.46f, 0.54f, 0.80f, 0.60f);

	colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);

	colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);

	colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);

	colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);

	colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);

	colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);



	colors[ImGuiCol_ResizeGrip] = ImVec4(0.80f, 0.80f, 0.80f, 0.56f);

	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);

	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);

	colors[ImGuiCol_CloseButton] = ImVec4(0.59f, 0.59f, 0.59f, 0.50f);

	colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);

	colors[ImGuiCol_CloseButtonActive] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);

	colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);

	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);

	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);

	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.45f, 0.00f, 1.00f);

	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);

	colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);


}

void Dark(ImGuiStyle* dst)
{
	ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();
	ImVec4* colors = style->Colors;
	colors[ImGuiCol_real_color] = ImVec4(255, 0, 0, 1.00f);
	colors[ImGuiCol_fake_color] = ImVec4(0, 0, 255, 1.00f);
	colors[ImGuiCol_lby_color] = ImVec4(0, 255, 0, 1.00f);
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
//	colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
//	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
//	colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	colors[ImGuiCol_CloseButton] = ImVec4(0.41f, 0.41f, 0.41f, 0.50f);
	colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
	colors[ImGuiCol_CloseButtonActive] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	//colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
//	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
}

void Theme_Init(IDirect3DDevice9* pDevice)
{
	ImGuiIO& io = ImGui::GetIO();
	io.DeltaTime = 1.f / 60.f;
	D3DDEVICE_CREATION_PARAMETERS d3dcp{ 0 };
	pDevice->GetCreationParameters(&d3dcp);

	auto& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowMinSize = ImVec2(32, 32);
	style.WindowRounding = 9.0f;
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.ChildWindowRounding = 0.0f;
	style.FramePadding = ImVec2(4, 3);
	style.FrameRounding = 2.3f;
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 3.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 0.0f;
	style.GrabMinSize = 5.0f;
	style.GrabRounding = 0.0f;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.DisplayWindowPadding = ImVec2(22, 22);
	style.DisplaySafeAreaPadding = ImVec2(4, 4);
	style.AntiAliasedLines = true;
	style.AntiAliasedShapes = true;
	style.CurveTessellationTol = 1.25f;

	Dark(NULL);
	//Light(NULL);
}



void DrawSpectatingYou()
{
	auto& style = ImGui::GetStyle();
	style.Alpha = 0.9f;
	//ImGui::PushFont(Global::fDefault);
	ImGui::SetNextWindowSize(ImVec2(130, 150), ImGuiSetCond_FirstUseEver);
	if (ImGui::Begin("Spectating Me", NULL, ImGuiWindowFlags_NoCollapse))
	{
		IClientEntity *pLocal = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());
		// Loop through all active entitys
		for (int i = 0; i < Interfaces::EntList->GetHighestEntityIndex(); i++)
		{
			// Get the entity
			IClientEntity *pEntity = Interfaces::EntList->GetClientEntity(i);
			player_info_t pinfo;
			// The entity isn't some laggy peice of shit or something
			if (pEntity &&  pEntity != pLocal)
			{
				if (Interfaces::Engine->GetPlayerInfo(i, &pinfo) && !pEntity->IsAlive() && !pEntity->IsDormant())
				{
					HANDLE obs = pEntity->GetObserverTargetHandle();
					if (obs)
					{
						IClientEntity *pTarget = Interfaces::EntList->GetClientEntityFromHandle(obs);
						player_info_t pinfo2;
						if (pTarget)
						{
							if (Interfaces::Engine->GetPlayerInfo(pTarget->GetIndex(), &pinfo2))
							{
								if (pTarget->GetIndex() == pLocal->GetIndex())
									ImGui::Text("%s", pinfo.name);
							}
						}
					}
				}
			}
		}
	}
	ImGui::End();
}

player_info_t GetInfo1(int Index) {
	player_info_t Info;
	Interfaces::Engine->GetPlayerInfo(Index, &Info);
	return Info;
}
static auto degrees_to_radians(float deg) -> float { return deg * (M_PI / 180.f); }
auto get_rotated_position(Vector start, const float rotation, const float distance) -> Vector
{
	const auto rad = degrees_to_radians(rotation);
	start.x += cosf(rad) * distance;
	start.y += sinf(rad) * distance;

	return start;
};



void ArrowBS()
{
	IClientEntity *pLocal = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());
	if (pLocal->IsAlive()) {

	
	if (true) {

	
	auto client_viewangles = Vector();
	auto screen_width = 0, screen_height = 0;
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	//window->DrawList->AddTriangleFilled(a, b, c, col);
	Interfaces::Engine->GetViewAngles(client_viewangles);
	Interfaces::Engine->GetScreenSize(screen_width, screen_height);
	const auto screen_center = Vector2D(screen_width / 2.f, screen_height / 2.f);
	const auto real_rot = degrees_to_radians(client_viewangles.y - G::m_real_angle.y - 90);
	const auto fake_rot = degrees_to_radians(client_viewangles.y - G::m_fake_angle.y - 90);
	const auto lby_rot = degrees_to_radians(client_viewangles.y - G::m_lowerbodyyaw - 90);
	constexpr auto radius = 80.f;

	static const auto real_color = ImU32(ImGuiCol_real_color);
	static const auto fake_color = ImU32(ImGuiCol_fake_color);
	static const auto lby_color = ImU32(ImGuiCol_lby_color);
	auto draw_arrow = [&](float rot, ImU32 color) -> void
	{
		window->DrawList->AddTriangleFilled(
			ImVec2(screen_center.x + cosf(rot) * radius, screen_center.y + sinf(rot) * radius),
			ImVec2(screen_center.x + cosf(rot + degrees_to_radians(10)) * (radius - 25.f),
				screen_center.y + sinf(rot + degrees_to_radians(10)) * (radius - 25.f)),
			ImVec2(screen_center.x + cosf(rot - degrees_to_radians(10)) * (radius - 25.f),
				screen_center.y + sinf(rot - degrees_to_radians(10)) * (radius - 25.f)),
			color);
	};

	draw_arrow(real_rot, real_color);
	draw_arrow(fake_rot, fake_color);
	draw_arrow(lby_rot, lby_color);
	}
	}
	/*int w, h;
	Interfaces::Engine->GetScreenSize(w, h);
	h / 2;
	w / 2;
	bool leftColor = false;
	bool rightColor = false;

	if (!leftColor) {
	char buffer[64];
	sprintf_s(buffer, "<");
	Render::Text(w - 50, h, Color(250, 250, 250), Render::Fonts::ESP, buffer);
	}
	else {
	char buffer[64];
	sprintf_s(buffer, "<");
	Render::Text(w - 50, h, Color(0, 250, 0), Render::Fonts::ESP, buffer);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
	rightColor != rightColor;
	}
	if (!rightColor) {
	char buffer[64];
	sprintf_s(buffer, ">");
	Render::Text(w + 50, h, Color(250, 250, 250), Render::Fonts::ESP, buffer);
	}
	else {
	char buffer[64];
	sprintf_s(buffer, ">");
	Render::Text(w + 50, h, Color(0, 250, 0), Render::Fonts::ESP, buffer);
	}*/


}
//PlayerList_t PlayerList[65];
#define arrayss(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))
typedef HRESULT(_stdcall *Present_T)(void*, const RECT*, RECT*, HWND, RGNDATA*);
Present_T oPresent;

HRESULT _stdcall hkPresent(LPDIRECT3DDEVICE9 pDevice, RECT* pSourceRect, RECT* pDestRect, HWND hDestWindowOverride, RGNDATA* pDirtyRegion)
{
	if (!renderer->IsReady())
	{
		Theme_Init(pDevice);
		renderer->Initialize(FindWindowA("Valve001", NULL), pDevice);
	}
	
	static bool mouse_enabled = false;
	pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0xFFFFFFFF);
	bool is_renderer_active = renderer->IsActive();

	if (is_renderer_active) {
		if (mouse_enabled) {
			Interfaces::Engine->ClientCmd_Unrestricted("cl_mouseenable 0");
			mouse_enabled = false;
		}
	}
	else {
		if (!mouse_enabled) {
			Interfaces::Engine->ClientCmd_Unrestricted("cl_mouseenable 1");
			mouse_enabled = true;
		}
	}

	ImGui::GetIO().MouseDrawCursor = is_renderer_active;

	ImGui_ImplDX9_NewFrame();
//	ArrowBS();
	if (is_renderer_active)
	{
	//	ImGui::ShowTestWindow();
		auto& style = ImGui::GetStyle();
		style.Alpha = 1.0f;
		ImGui::SetNextWindowSize(ImVec2(960, 446), ImGuiSetCond_FirstUseEver);
		if (ImGui::Begin(("test"), NULL, ImVec2(960, 446), 1.0f, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse))
		{

			const char* tabs[] = {
				"Ragebot",
				"Visuals",
				"Misc"
			};

			for (int i = 0; i < arrayss(tabs); i++)
			{

				//ImGui::GetStyle().Colors[ImGuiCol_Button] = ImColor(54, 54, 54, 255);

				if (ImGui::Button(tabs[i], ImVec2(ImGui::GetWindowSize().x / arrayss(tabs) - 9, 0)))
					options.Menu.ActualTab = i;

				//ImGui::GetStyle().Colors[ImGuiCol_Button] = ImColor(54, 54, 54, 255);

				if (i < arrayss(tabs) - 1)
					ImGui::SameLine();
			}

			if (options.Menu.ActualTab == 0) {
				ImGui::Checkbox(("Active"), &options.Rage.MainSwitch);
				ImGui::NewLine();
				
				ImGui::Combo("Target Selection", &options.Rage.TargetSelection, TargetSelection, ARRAYSIZE(TargetSelection));
				ImGui::Combo("hitbones", &options.Rage.hitbones, hitbones_r, ARRAYSIZE(hitbones_r));
				ImGui::SliderFloat("##FoV", &options.Rage.AimbotFov, 0.f, 180.f, "Fov: %.f");
				ImGui::SliderFloat("##TargetPointscale", &options.Rage.TargetPointscale, 0.f, 1.f, "Target Pointscale: %.2f");
				ImGui::SliderFloat("##Hitchance", &options.Rage.Hitchance, 0.f, 100.f, "Hitchance: %.f");
				ImGui::SliderFloat("##MinimumDamage", &options.Rage.MinimumDamage, 1.f, 100.f, "Minimum Damage: %.f");
				ImGui::Checkbox(("Multipoint"), &options.Rage.TargetMultipoint);
				ImGui::Checkbox(("Auto Scope"), &options.Rage.AutoScope);
				ImGui::Checkbox(("Auto Pistol"), &options.Rage.AutoPistol);
				ImGui::Checkbox(("Auto Wall"), &options.Rage.AutoWall);
				ImGui::Checkbox(("Silent Aim"), &options.Rage.SilentAim);
				ImGui::Checkbox(("Resolver"), &options.Rage.AccuracyResolver);
				ImGui::Checkbox(("No Recoil"), &options.Rage.DoNoRecoil);
				ImGui::Checkbox(("Auto Fire"), &options.Rage.AutoFire);
			//	ImGui::Checkbox(("pSilent Aim"), &options.Rage.pSilentaim);
				ImGui::NewLine();
				ImGui::Checkbox(("Anti Aim"), &options.Rage.AntiAim);
				ImGui::Combo("pitch", &options.Rage.AntiAimPtich, Ptich, ARRAYSIZE(Ptich));
				ImGui::Combo("Yaw", &options.Rage.AntiAimYaw, Yaw, ARRAYSIZE(Yaw));
				ImGui::Checkbox(("Anti Aim Knife"), &options.Rage.AntiAimKnife);
				// Aim 
			}
			else if (options.Menu.ActualTab == 1) {
				ImGui::Checkbox(("Active"), &options.Rage.MainSwitchvh);
				ImGui::NewLine();
				ImGui::Checkbox(("Box"), &options.Rage.OptionsBox);
				ImGui::Checkbox(("Name"), &options.Rage.OptionsName);
				ImGui::Checkbox(("Health"), &options.Rage.OptionsHealth);
				ImGui::Checkbox(("Skeleton"), &options.Rage.OptionsSkeleton);
				ImGui::Checkbox(("Armor"), &options.Rage.DrawArmor);
				ImGui::Checkbox(("Drops"), &options.Rage.DrawDrop); // dosent work
				ImGui::Checkbox(("C4 ESP"), &options.Rage.FiltersC4); // dont know if it works
				ImGui::Checkbox(("Chicken ESP"), &options.Rage.FiltersChickens); // dont work
				ImGui::NewLine();
				ImGui::Text("Other");
				ImGui::Checkbox(("Spectators"), &options.Rage.SpecList);
				ImGui::Checkbox(("antiaim lines"), &options.Rage.DrawLinesAA);
				ImGui::Checkbox(("OtherNoScope"), &options.Rage.OtherNoScope);
			//	ImGui::Checkbox(("DrawCrosshair"), &options.Rage.DrawCrosshair);
			//	ImGui::Checkbox(("OtherRecoilCrosshair"), &options.Rage.OtherRecoilCrosshair);
				ImGui::Checkbox(("SpreadCrosshair"), &options.Rage.SpreadCrosshair);

			}
			else if (options.Menu.ActualTab == 2) {
				ImGui::Checkbox(("Active"), &options.Rage.MainSwitchmisc);
				ImGui::Checkbox(("bHop"), &options.Rage.bhop);
				ImGui::Checkbox(("Auto Strafe"), &options.Rage.AutoStrafe);
				ImGui::Checkbox(("OtherThirdperson"), &options.Rage.OtherThirdperson);
			//	ImGui::Checkbox(("Auto Strafe"), &options.Rage.AutoStrafe);
			}
		} ImGui::End();
		if (options.ESP.speclist)
			DrawSpectatingYou();
	}
	else {
	if (options.ESP.speclist)
			DrawSpectatingYou();
	}

	ImGui::Render();

	return oPresent(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}
