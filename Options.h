#pragma once


struct Variables
{

	struct RAGE_TT
	{
		bool MainSwitch;
		int TargetSelection;

		int hitbones;

		bool DoNoRecoil;

		bool Enabled;

		bool DrawArmor;

		bool DrawDrop;

		bool FiltersC4;

		bool FiltersChickens;

		bool SpecList;

		bool DrawLinesAA;

		bool OtherThirdperson;

		bool BulletTracers; //yeet

		bool SpreadCrosshair;

		bool DrawCrosshair;

		bool OtherRecoilCrosshair;

		bool OtherNoScope;

		float AimFOV;

		float AimbotFov;

		bool AutoFire;

		bool OptionsBox;

		bool OptionsName;

		bool OptionsHealth;

		bool OptionsSkeleton;

		bool MainSwitchmisc;

		bool MainSwitchvh;

		bool bhop;

		bool AutoStrafe;

		bool AutoWall;

		float MinimumDamage;

		bool SilentAim;

		bool AccuracyResolver;

		bool AntiAim;

		int AntiAimYaw;

		int AntiAimPtich;

		bool AntiAimKnife;

		bool pSilentaim;

		bool AutoScope;

		float Hitchance;

		bool AutoPistol;

		bool TargetMultipoint;

		float TargetPointscale;

		int Hitbone1;

		bool SilentTYPE;

		bool AutoFiring;

		int AcurracyControl;

		bool PosAdjustment;

		bool bcktrck;

		bool lagfix;

		bool MultiPoint_mb;

		float Pointscale;

		int BaimIFUnderXHP;

		int BaimAfterXShots;

		int selectiontrgt;

		bool autowall;
		
		float autowalldmg;

		float hitchanceval;

		int resolver;

		int flipangle;

		int bruteafter;

		int preferbaim;

		bool enableaa;

		int pitchaa;

		int realyaa;

		int fakeyyaa;

		int moveyaa;

		int leftkey;

		int rightkey;
	} Rage;

	struct LEGIT_TT
	{
		bool enabled;
		bool backtrack;
		int backtrackticks;
	} Legit;

	struct PLAYERLIST_TT
	{
		int selectedplayer;
		bool isfriend;
	} PlayerlistOpt;

	struct ESP_TT
	{
		bool Active;
		bool FilterPlayers;
		bool FilterEnemy;
		bool FilterC4;
		bool FilterExplosives;
		bool FilterWeapons;
		int BoxEsp;
		float fovchanger;
		bool HPBar;
		int fakeanglechams;
		bool removesmoke;
		bool removeflash;
		bool removevisualrecoil;
		bool removescopeborder;
		bool name;
		bool weapon;
		bool armor;
		bool spreadcrs;
		int ghostchams;
		bool speclist;
		bool logs;
		bool createtracer;
	} ESP;

	struct MISC_TT
	{
		bool SafeMode;
		int modetp;
		bool thirdperson;
		int tpkey1;
		int actualstrafer;
		bool autojumping;
		bool enableknife;
		int skinknife;
		bool clantag;
		bool animated_clantag;
	} Misc;

	struct HVH_TT
	{
		bool FakelagEnable;
		int FakeLagMode;
		float DeltaStand;
		float DeltaMove;
	} HvH;

	struct GLOBAL_TT
	{
		int ActualTab;
		struct CONFIGS_TT
		{
			char ConfigFile;
		} Configs;
	} Menu;
};


extern Variables options;