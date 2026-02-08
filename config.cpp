class CfgMods
{
	class InventoryManager_Server
	{
		dir = "InventoryManager_Server";
		hideName = 1;
		hidePicture = 1;
		name = "InventoryManager_Server";
		credits = "Rustic";
		author = "Rustic";
		authorID = "69";
		version = "Version 1.0";
		type = "mod";
		dependencies[] = {"Game","Mission","World"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"InventoryManager_Server/Scripts/3_Game"};
			};

			class worldScriptModule
			{
				value = "";
				files[] = {"InventoryManager_Server/Scripts/4_World"};
			};

			class missionScriptModule
			{
				value = "";
				files[] = {"InventoryManager_Server/Scripts/5_Mission"};
			};
		};
	};
};
class CfgPatches
{
	class InventoryManager_Server
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","JM_CF_Scripts","InventoryManager","RusticModsCore"};
	};
};