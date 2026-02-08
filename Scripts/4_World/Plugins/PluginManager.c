modded class PluginManager {
	override void Init() {
		super.Init();

		RegisterPlugin("InventoryManagerRPCManager", false, true);
	}
}