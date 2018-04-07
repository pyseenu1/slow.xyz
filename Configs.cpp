#include "Configs.hpp"
#include "options.h"
#include <winerror.h>
#pragma warning( disable : 4091)
#include <ShlObj.h>
#include <string>
#include <sstream>

void CConfig::Setup()
{
	/* RAGE */
	SetupValue(options.Rage.MainSwitch, false, ("Ragebot"), ("MainSwitchRage"));
	SetupValue(options.Rage.Enabled, false, ("Ragebot"), ("EnabledRage"));
	SetupValue(options.Rage.AimFOV, 90.f, ("Ragebot"), ("AimbotFovRAGE"));
	SetupValue(options.Rage.AutoFiring, false, ("Ragebot"), ("autofirerage"));
	SetupValue(options.Rage.SilentTYPE, false, ("Ragebot"), ("AimbotSilentType"));
	SetupValue(options.Rage.Hitbone1, 0, ("Ragebot"), ("HitboxRage"));
	SetupValue(options.Rage.selectiontrgt, 0, ("Ragebot"), ("SelectionRage"));
	SetupValue(options.Rage.MultiPoint_mb, false, ("Ragebot"), ("multipointingrage"));
	SetupValue(options.Rage.Pointscale, 0.66f, ("Ragebot"), ("pointscale_rage"));
	SetupValue(options.Rage.AcurracyControl, 0, ("Ragebot"), ("AccuracyControlingRecoil"));
	SetupValue(options.Rage.autowall, false, ("Ragebot"), ("autowallenabled"));
	SetupValue(options.Rage.autowalldmg, 15.f, ("Ragebot"), ("autowallmindamage"));
	SetupValue(options.Rage.hitchanceval, 50.f, ("Ragebot"), ("hitchancevaluerage"));
	SetupValue(options.Rage.resolver, 0, ("Ragebot"), ("ResolverRage"));
	SetupValue(options.Rage.flipangle, 0, ("Ragebot"), ("ResolverRage_bruteKey"));
	SetupValue(options.Rage.bruteafter, 5, ("Ragebot"), ("ResolverRage_bruteAfter"));
	SetupValue(options.Rage.PosAdjustment, false, ("Ragebot"), ("positionadjustment"));
	SetupValue(options.Rage.lagfix, false, ("Ragebot"), ("lagfixinterpfix"));
	SetupValue(options.Rage.bcktrck, false, ("Ragebot"), ("backtrackinglog"));
	SetupValue(options.Rage.preferbaim, 0, ("Ragebot"), ("preferbodyfilter"));
	SetupValue(options.Rage.BaimAfterXShots, 6, ("Ragebot"), ("baimafterxshots"));
	SetupValue(options.Rage.BaimIFUnderXHP, 20, ("Ragebot"), ("baimifunderxhealth"));
	SetupValue(options.Rage.enableaa, false, ("Ragebot"), ("aa_enable"));
	SetupValue(options.Rage.pitchaa, 0, ("Ragebot"), ("aa_pitch"));
	SetupValue(options.Rage.realyaa, 0, ("Ragebot"), ("aa_realyaw"));
	SetupValue(options.Rage.fakeyyaa, 0, ("Ragebot"), ("aa_fakeyaw"));
	SetupValue(options.Rage.moveyaa, 0, ("Ragebot"), ("aa_moveyaw"));
	SetupValue(options.Rage.leftkey, 0, ("Ragebot"), ("aa_switchleft"));
	SetupValue(options.Rage.rightkey, 0, ("Ragebot"), ("aa_switchright"));
	/* RAGE */

	/* LEGIT */
	SetupValue(options.Legit.enabled, false, ("Legitbot"), ("legit_toggle"));
	SetupValue(options.Legit.backtrack, false, ("Legitbot"), ("backtrack_toggle"));
	SetupValue(options.Legit.backtrackticks, false, ("Legitbot"), ("backtrack_ticks"));
	/* LEGIT */

	/* VISUALS */
	SetupValue(options.ESP.Active, true, ("Visuals"), ("MainSwitchVisuals"));
	SetupValue(options.ESP.BoxEsp, 0, ("Visuals"), ("BoxESPCOnclusion"));
	SetupValue(options.ESP.HPBar, false, ("Visuals"), ("HealthBar"));
	SetupValue(options.ESP.name, false, ("Visuals"), ("NameESP"));
	SetupValue(options.ESP.armor, false, ("Visuals"), ("ArmorESP"));
	SetupValue(options.ESP.weapon, false, ("Visuals"), ("WeaponESP"));
	SetupValue(options.ESP.FilterPlayers, false, ("Visuals"), ("FilterPlayers"));
	SetupValue(options.ESP.FilterEnemy, false, ("Visuals"), ("FilterEnemyOnly"));
	SetupValue(options.ESP.FilterExplosives, false, ("Visuals"), ("FilterNades"));
	SetupValue(options.ESP.FilterC4, false, ("Visuals"), ("FilterBomb"));
	SetupValue(options.ESP.FilterWeapons, false, ("Visuals"), ("FilterWeapons"));
	SetupValue(options.ESP.removeflash, false, ("Visuals"), ("NoFlash"));
	SetupValue(options.ESP.removesmoke, false, ("Visuals"), ("NoSmoke"));
	SetupValue(options.ESP.removescopeborder, false, ("Visuals"), ("NoScope"));
	SetupValue(options.ESP.removevisualrecoil, false, ("Visuals"), ("novisualrecoil"));
	SetupValue(options.ESP.fovchanger, 0.f, ("Visuals"), ("FovChangerSlider"));
	SetupValue(options.ESP.spreadcrs, false, ("Visuals"), ("spreadindicator"));
	SetupValue(options.ESP.fakeanglechams, 0, ("Visuals"), ("GhostAngleChams"));
	SetupValue(options.ESP.speclist, false, ("Visuals"), ("SpecListImGui"));
	SetupValue(options.ESP.logs, false, ("Visuals"), ("EventLogs"));
	SetupValue(options.ESP.createtracer, false, ("Visuals"), ("BulletTracers"));
	/* VISUALS */

	/* MISC */
	SetupValue(options.Misc.SafeMode, true, ("Misc"), ("ClampAnglesSafeMode"));
	SetupValue(options.Misc.autojumping, false, ("Misc"), ("BunnyhopFunc"));
	SetupValue(options.Misc.actualstrafer, 0, ("Misc"), ("AutoStrafershit"));
	SetupValue(options.Misc.thirdperson, false, ("Misc"), ("ThirdpersonToggle"));
	SetupValue(options.Misc.tpkey1, 0, ("Misc"), ("thirdpersonkey"));
	SetupValue(options.Misc.modetp, 0, ("Misc"), ("thirdpersonmode"));
	SetupValue(options.Misc.enableknife, false, ("Misc"), ("knifechanger_toggler"));
	SetupValue(options.Misc.skinknife, 0, ("Misc"), ("knifechanger_skin"));
	SetupValue(options.Misc.clantag, false, ("Misc"), ("clantag_toggle"));
	SetupValue(options.Misc.animated_clantag, false, ("Misc"), ("clantag_animate"));
	/* MISC */

	/* HVH */
	SetupValue(options.HvH.FakeLagMode, 0, ("HvH"), ("fakelag_mode"));
	SetupValue(options.HvH.DeltaStand, 0.f, ("HvH"), ("breaker_stand"));
	SetupValue(options.HvH.DeltaMove, 0.f, ("HvH"), ("breaker_move"));
	/* HVH */
}

void CConfig::SetupValue(int &value, int def, std::string category, std::string name)
{
	value = def;
	ints.push_back(new ConfigValue<int>(category, name, &value));
}

void CConfig::SetupValue(float &value, float def, std::string category, std::string name)
{
	value = def;
	floats.push_back(new ConfigValue<float>(category, name, &value));
}

void CConfig::SetupValue(bool &value, bool def, std::string category, std::string name)
{
	value = def;
	bools.push_back(new ConfigValue<bool>(category, name, &value));
}

void CConfig::Save()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{


		folder = std::string(path) + ("\\cringetk\\");
		file = std::string(path) + ("\\cringetk\\", &options.Menu.Configs.ConfigFile);

	}

	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}

void CConfig::Load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("\\cringetk\\");
		file = std::string(path) + ("\\cringetk\\", &options.Menu.Configs.ConfigFile);
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = (float)atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}

CConfig* Config = new CConfig();
