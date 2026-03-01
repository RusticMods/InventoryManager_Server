# InventoryManager_Server

InventoryManager_Server is the **server-side authority half** of the Rustic inventory administration mod for DayZ. It handles configuration, RPC endpoints, inventory manipulation, notifications, and logging for the InventoryManager system.

This project is now open source under **GPLv3**.

## What it does

This is the backend side of InventoryManager. It receives requests from the client UI and executes the actual admin actions on the server.

The server component currently handles:

- Creating/loading `InventoryManager.json`
- Registering InventoryManager RPC handlers
- Syncing the online player list to admins
- Looking up target players by player ID
- Clearing a player's inventory
- Repairing all items in a player's inventory
- Deleting a selected item
- Taking an item from one player and moving it to another
- Raising/lowering item health state
- Setting quantity on stackable items
- Spawning items in inventory or at world position
- Optional spawning of compatible attachments
- Teleporting the requesting admin to a selected player
- Sending notifications back to the admin client
- Writing action logs through RusticModsCore

## Required companion mods

This server package is not intended to be used alone. It is the companion to:

- `InventoryManager`
- `RusticModsCore`

## Installation

Install `InventoryManager_Server` on the **server**.

For full functionality, also install:

- `RusticModsCore` on server and clients
- `InventoryManager` on server and clients
- `CF`

## Configuration

On first start, the mod creates:

```text
profiles/RusticMods/InventoryManager.json
```

Current config fields from the source:

- `EnableDebugMode`
- `WebhookLogs`

### Default generated values

```json
{
  "EnableDebugMode": "false",
  "WebhookLogs": "url (EVERYTHING AFTER https://discord.com/api/webhooks/ (Ex: https://discord.com/api/webhooks/12312541 would be 12312541))"
}
```

Note: WebhookLogs was a pre-RusticModsCore implementation. It was reserved for possible future use, however, RusticModsCore is further developed in this sense. Either use RusticModsCore's implementation, or create something from this config entry.

## Permissions

InventoryManager relies on the admin flag supplied by **RusticModsCore**.

Add authorized admin IDs to:

```text
profiles/RusticMods/Permissions/users.json
```

Example:

```json
{
  "SuperAdmins": [
    "YourPlainIdHere"
  ]
}
```

## Server-side actions

### Player sync and lookup

The server can:

- build a list of online players
- send it to the requesting admin
- resolve a selected player by `playerId`
- return inventory contents and position data back to the client UI

### Inventory operations

The server implements logic for:

- `ClearInventoryRPC`
- `RepairAllRPC`
- `DeleteItemRPC`
- `TakeItemRPC`
- `LowerHealthRPC`
- `RaiseHealthRPC`
- `SetItemRPC`
- `SpawnItemRPC`
- `TeleportPlayerRPC`

### Spawn behavior

The item spawn flow supports:

- validation of classname, quantity, health state, and destination
- spawning directly into a player's inventory
- spawning in the world at a position
- optional attachment spawning for compatible items
- exclusion handling for restricted/unfinished classes in the attachment logic

## Logging

Inventory actions are logged through `GetRusticModsCoreLogger()`.

Examples of logged actions include:

- clearing inventory
- repairing inventory
- deleting items
- moving/taking items
- changing health state
- spawning items
- teleporting

Check the RusticMods log folder under:

```text
profiles/RusticMods/Logs/
```

## License

This project is licensed under the **GNU General Public License v3.0**. See `LICENSE-GPL-3.0.txt` for the full license text.
