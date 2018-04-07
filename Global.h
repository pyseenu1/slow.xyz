#pragma once
#include "SDK.h"
#include "imgui/imgui.h"
#include "imgui/examples/directx9_example/imgui_impl_dx9.h"
#include "ImGui\imgui_internal.h"
namespace G // Global Stuff
{
	extern bool			Aimbotting;
	extern bool			InAntiAim;
	extern bool			Return;
	static Vector    	m_real_angle;
	static Vector		m_fake_angle;
	static float		m_lowerbodyyaw;
	extern HMODULE		Dll;
	extern HWND			Window;
	static bool			PressedKeys[256];
	extern bool			d3dinit;
	extern float		FOV;
	extern int			ChamMode;
	extern char			AnimatedClantag[16];
	extern bool			SendPacket;
	extern int			BestTarget;
	extern char			buf3[128];
	extern char			extra_flags;
}