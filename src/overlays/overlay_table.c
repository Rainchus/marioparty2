#include "common.h"
#include "ld_addrs.h"

//doesn't match for some reason currently

// typedef struct OverlayTable {
//     u8* romStart;
//     u8* romEnd;
//     u8* vramStart;
//     u8* textVramStart;
//     u8* textVramEnd;
//     u8* dataVramStart;
//     u8* dataVramEnd;
//     u8* bssVramStart;
//     u8* bssVramEnd;
// } OverlayTable;

// u8 D_800C8870_C9470[] = {0, 0, 0, 0};

// OverlayTable overlay_table[] = {
// {Debug_ROM_START, Debug_ROM_END, Debug_VRAM, Debug_TEXT_START, Debug_TEXT_END, Debug_DATA_START, Debug_RODATA_END, Debug_bss_VRAM, Debug_bss_VRAM},
// {BowserSlots_ROM_START, BowserSlots_ROM_END, BowserSlots_VRAM, BowserSlots_TEXT_START, BowserSlots_TEXT_END, BowserSlots_DATA_START, BowserSlots_RODATA_END, BowserSlots_bss_VRAM, BowserSlots_bss_VRAM},
// {RollOutTheBarrels_ROM_START, RollOutTheBarrels_ROM_END, RollOutTheBarrels_VRAM, RollOutTheBarrels_TEXT_START, RollOutTheBarrels_TEXT_END, RollOutTheBarrels_DATA_START, RollOutTheBarrels_RODATA_END, RollOutTheBarrels_bss_VRAM, RollOutTheBarrels_bss_VRAM},
// {CoffinCongestion_ROM_START, CoffinCongestion_ROM_END, CoffinCongestion_VRAM, CoffinCongestion_TEXT_START, CoffinCongestion_TEXT_END, CoffinCongestion_DATA_START, CoffinCongestion_RODATA_END, CoffinCongestion_bss_VRAM, CoffinCongestion_bss_VRAM},
// {HammerSlammer_ROM_START, HammerSlammer_ROM_END, HammerSlammer_VRAM, HammerSlammer_TEXT_START, HammerSlammer_TEXT_END, HammerSlammer_DATA_START, HammerSlammer_RODATA_END, HammerSlammer_bss_VRAM, HammerSlammer_bss_VRAM},
// {GiveMeABrake_ROM_START, GiveMeABrake_ROM_END, GiveMeABrake_VRAM, GiveMeABrake_TEXT_START, GiveMeABrake_TEXT_END, GiveMeABrake_DATA_START, GiveMeABrake_RODATA_END, GiveMeABrake_bss_VRAM, GiveMeABrake_bss_VRAM},
// {MalletGoRound_ROM_START, MalletGoRound_ROM_END, MalletGoRound_VRAM, MalletGoRound_TEXT_START, MalletGoRound_TEXT_END, MalletGoRound_DATA_START, MalletGoRound_RODATA_END, MalletGoRound_bss_VRAM, MalletGoRound_bss_VRAM},
// {GrabBag_ROM_START, GrabBag_ROM_END, GrabBag_VRAM, GrabBag_TEXT_START, GrabBag_TEXT_END, GrabBag_DATA_START, GrabBag_RODATA_END, GrabBag_bss_VRAM, GrabBag_bss_VRAM},
// {LavaTileIsle_ROM_START, LavaTileIsle_ROM_END, LavaTileIsle_VRAM, LavaTileIsle_TEXT_START, LavaTileIsle_TEXT_END, LavaTileIsle_DATA_START, LavaTileIsle_RODATA_END, LavaTileIsle_bss_VRAM, LavaTileIsle_bss_VRAM},
// {BumperBalloonCars_ROM_START, BumperBalloonCars_ROM_END, BumperBalloonCars_VRAM, BumperBalloonCars_TEXT_START, BumperBalloonCars_TEXT_END, BumperBalloonCars_DATA_START, BumperBalloonCars_RODATA_END, BumperBalloonCars_bss_VRAM, BumperBalloonCars_bss_VRAM},
// {RakinEmIn_ROM_START, RakinEmIn_ROM_END, RakinEmIn_VRAM, RakinEmIn_TEXT_START, RakinEmIn_TEXT_END, RakinEmIn_DATA_START, RakinEmIn_RODATA_END, RakinEmIn_bss_VRAM, RakinEmIn_bss_VRAM},
// {DayAtTheRaces_ROM_START, DayAtTheRaces_ROM_END, DayAtTheRaces_VRAM, DayAtTheRaces_TEXT_START, DayAtTheRaces_TEXT_END, DayAtTheRaces_DATA_START, DayAtTheRaces_RODATA_END, DayAtTheRaces_bss_VRAM, DayAtTheRaces_bss_VRAM},
// {HotRopeJump_ROM_START, HotRopeJump_ROM_END, HotRopeJump_VRAM, HotRopeJump_TEXT_START, HotRopeJump_TEXT_END, HotRopeJump_DATA_START, HotRopeJump_RODATA_END, HotRopeJump_bss_VRAM, HotRopeJump_bss_VRAM},
// {HotBobOmb_ROM_START, HotBobOmb_ROM_END, HotBobOmb_VRAM, HotBobOmb_TEXT_START, HotBobOmb_TEXT_END, HotBobOmb_DATA_START, HotBobOmb_RODATA_END, HotBobOmb_bss_VRAM, HotBobOmb_bss_VRAM},
// {BowlOver_ROM_START, BowlOver_ROM_END, BowlOver_VRAM, BowlOver_TEXT_START, BowlOver_TEXT_END, BowlOver_DATA_START, BowlOver_RODATA_END, BowlOver_bss_VRAM, BowlOver_bss_VRAM},
// {RainbowRun_ROM_START, RainbowRun_ROM_END, RainbowRun_VRAM, RainbowRun_TEXT_START, RainbowRun_TEXT_END, RainbowRun_DATA_START, RainbowRun_RODATA_END, RainbowRun_bss_VRAM, RainbowRun_bss_VRAM},
// {CraneGame_ROM_START, CraneGame_ROM_END, CraneGame_VRAM, CraneGame_TEXT_START, CraneGame_TEXT_END, CraneGame_DATA_START, CraneGame_RODATA_END, CraneGame_bss_VRAM, CraneGame_bss_VRAM},
// {MoveToTheMusic_ROM_START, MoveToTheMusic_ROM_END, MoveToTheMusic_VRAM, MoveToTheMusic_TEXT_START, MoveToTheMusic_TEXT_END, MoveToTheMusic_DATA_START, MoveToTheMusic_RODATA_END, MoveToTheMusic_bss_VRAM, MoveToTheMusic_bss_VRAM},
// {BobOmbBarrage_ROM_START, BobOmbBarrage_ROM_END, BobOmbBarrage_VRAM, BobOmbBarrage_TEXT_START, BobOmbBarrage_TEXT_END, BobOmbBarrage_DATA_START, BobOmbBarrage_RODATA_END, BobOmbBarrage_bss_VRAM, BobOmbBarrage_bss_VRAM},
// {LookAway_ROM_START, LookAway_ROM_END, LookAway_VRAM, LookAway_TEXT_START, LookAway_TEXT_END, LookAway_DATA_START, LookAway_RODATA_END, LookAway_bss_VRAM, LookAway_bss_VRAM},
// {ShockDropOrRoll_ROM_START, ShockDropOrRoll_ROM_END, ShockDropOrRoll_VRAM, ShockDropOrRoll_TEXT_START, ShockDropOrRoll_TEXT_END, ShockDropOrRoll_DATA_START, ShockDropOrRoll_RODATA_END, ShockDropOrRoll_bss_VRAM, ShockDropOrRoll_bss_VRAM},
// {LightsOut_ROM_START, LightsOut_ROM_END, LightsOut_VRAM, LightsOut_TEXT_START, LightsOut_TEXT_END, LightsOut_DATA_START, LightsOut_RODATA_END, LightsOut_bss_VRAM, LightsOut_bss_VRAM},
// {FiletRelay_ROM_START, FiletRelay_ROM_END, FiletRelay_VRAM, FiletRelay_TEXT_START, FiletRelay_TEXT_END, FiletRelay_DATA_START, FiletRelay_RODATA_END, FiletRelay_bss_VRAM, FiletRelay_bss_VRAM},
// {Archerival_ROM_START, Archerival_ROM_END, Archerival_VRAM, Archerival_TEXT_START, Archerival_TEXT_END, Archerival_DATA_START, Archerival_RODATA_END, Archerival_bss_VRAM, Archerival_bss_VRAM},
// {ToadBandstand_ROM_START, ToadBandstand_ROM_END, ToadBandstand_VRAM, ToadBandstand_TEXT_START, ToadBandstand_TEXT_END, ToadBandstand_DATA_START, ToadBandstand_RODATA_END, ToadBandstand_bss_VRAM, ToadBandstand_bss_VRAM},
// {BobsledRun_ROM_START, BobsledRun_ROM_END, BobsledRun_VRAM, BobsledRun_TEXT_START, BobsledRun_TEXT_END, BobsledRun_DATA_START, BobsledRun_RODATA_END, BobsledRun_bss_VRAM, BobsledRun_bss_VRAM},
// {HandcarHavoc_ROM_START, HandcarHavoc_ROM_END, HandcarHavoc_VRAM, HandcarHavoc_TEXT_START, HandcarHavoc_TEXT_END, HandcarHavoc_DATA_START, HandcarHavoc_RODATA_END, HandcarHavoc_bss_VRAM, HandcarHavoc_bss_VRAM},
// {BallonBurst_ROM_START, BallonBurst_ROM_END, BallonBurst_VRAM, BallonBurst_TEXT_START, BallonBurst_TEXT_END, BallonBurst_DATA_START, BallonBurst_RODATA_END, BallonBurst_bss_VRAM, BallonBurst_bss_VRAM},
// {SkyPilots_ROM_START, SkyPilots_ROM_END, SkyPilots_VRAM, SkyPilots_TEXT_START, SkyPilots_TEXT_END, SkyPilots_DATA_START, SkyPilots_RODATA_END, SkyPilots_bss_VRAM, SkyPilots_bss_VRAM},
// {SpeedHockey_ROM_START, SpeedHockey_ROM_END, SpeedHockey_VRAM, SpeedHockey_TEXT_START, SpeedHockey_TEXT_END, SpeedHockey_DATA_START, SpeedHockey_RODATA_END, SpeedHockey_bss_VRAM, SpeedHockey_bss_VRAM},
// {CakeFactory_ROM_START, CakeFactory_ROM_END, CakeFactory_VRAM, CakeFactory_TEXT_START, CakeFactory_TEXT_END, CakeFactory_DATA_START, CakeFactory_RODATA_END, CakeFactory_bss_VRAM, CakeFactory_bss_VRAM},
// {DungeonDash_ROM_START, DungeonDash_ROM_END, DungeonDash_VRAM, DungeonDash_TEXT_START, DungeonDash_TEXT_END, DungeonDash_DATA_START, DungeonDash_RODATA_END, DungeonDash_bss_VRAM, DungeonDash_bss_VRAM},
// {MagnetCarta_ROM_START, MagnetCarta_ROM_END, MagnetCarta_VRAM, MagnetCarta_TEXT_START, MagnetCarta_TEXT_END, MagnetCarta_DATA_START, MagnetCarta_RODATA_END, MagnetCarta_bss_VRAM, MagnetCarta_bss_VRAM},
// {FaceLift_ROM_START, FaceLift_ROM_END, FaceLift_VRAM, FaceLift_TEXT_START, FaceLift_TEXT_END, FaceLift_DATA_START, FaceLift_RODATA_END, FaceLift_bss_VRAM, FaceLift_bss_VRAM},
// {ShellShocked_ROM_START, ShellShocked_ROM_END, ShellShocked_VRAM, ShellShocked_TEXT_START, ShellShocked_TEXT_END, ShellShocked_DATA_START, ShellShocked_RODATA_END, ShellShocked_bss_VRAM, ShellShocked_bss_VRAM},
// {CrazyCutters_ROM_START, CrazyCutters_ROM_END, CrazyCutters_VRAM, CrazyCutters_TEXT_START, CrazyCutters_TEXT_END, CrazyCutters_DATA_START, CrazyCutters_RODATA_END, CrazyCutters_bss_VRAM, CrazyCutters_bss_VRAM},
// {ToadInTheBox_ROM_START, ToadInTheBox_ROM_END, ToadInTheBox_VRAM, ToadInTheBox_TEXT_START, ToadInTheBox_TEXT_END, ToadInTheBox_DATA_START, ToadInTheBox_RODATA_END, ToadInTheBox_bss_VRAM, ToadInTheBox_bss_VRAM},
// {MechaMarathon_ROM_START, MechaMarathon_ROM_END, MechaMarathon_VRAM, MechaMarathon_TEXT_START, MechaMarathon_TEXT_END, MechaMarathon_DATA_START, MechaMarathon_RODATA_END, MechaMarathon_bss_VRAM, MechaMarathon_bss_VRAM},
// {RollCall_ROM_START, RollCall_ROM_END, RollCall_VRAM, RollCall_TEXT_START, RollCall_TEXT_END, RollCall_DATA_START, RollCall_RODATA_END, RollCall_bss_VRAM, RollCall_bss_VRAM},
// {AbandonShip_ROM_START, AbandonShip_ROM_END, AbandonShip_VRAM, AbandonShip_TEXT_START, AbandonShip_TEXT_END, AbandonShip_DATA_START, AbandonShip_RODATA_END, AbandonShip_bss_VRAM, AbandonShip_bss_VRAM},
// {PlatformPeril_ROM_START, PlatformPeril_ROM_END, PlatformPeril_VRAM, PlatformPeril_TEXT_START, PlatformPeril_TEXT_END, PlatformPeril_DATA_START, PlatformPeril_RODATA_END, PlatformPeril_bss_VRAM, PlatformPeril_bss_VRAM},
// {TotemPolePound_ROM_START, TotemPolePound_ROM_END, TotemPolePound_VRAM, TotemPolePound_TEXT_START, TotemPolePound_TEXT_END, TotemPolePound_DATA_START, TotemPolePound_RODATA_END, TotemPolePound_bss_VRAM, TotemPolePound_bss_VRAM},
// {BumperBalls_ROM_START, BumperBalls_ROM_END, BumperBalls_VRAM, BumperBalls_TEXT_START, BumperBalls_TEXT_END, BumperBalls_DATA_START, BumperBalls_RODATA_END, BumperBalls_bss_VRAM, BumperBalls_bss_VRAM},
// {BombsAway_ROM_START, BombsAway_ROM_END, BombsAway_VRAM, BombsAway_TEXT_START, BombsAway_TEXT_END, BombsAway_DATA_START, BombsAway_RODATA_END, BombsAway_bss_VRAM, BombsAway_bss_VRAM},
// {TipsyTourney_ROM_START, TipsyTourney_ROM_END, TipsyTourney_VRAM, TipsyTourney_TEXT_START, TipsyTourney_TEXT_END, TipsyTourney_DATA_START, TipsyTourney_RODATA_END, TipsyTourney_bss_VRAM, TipsyTourney_bss_VRAM},
// {HoneycombHavoc_ROM_START, HoneycombHavoc_ROM_END, HoneycombHavoc_VRAM, HoneycombHavoc_TEXT_START, HoneycombHavoc_TEXT_END, HoneycombHavoc_DATA_START, HoneycombHavoc_RODATA_END, HoneycombHavoc_bss_VRAM, HoneycombHavoc_bss_VRAM},
// {HexagonHeat_ROM_START, HexagonHeat_ROM_END, HexagonHeat_VRAM, HexagonHeat_TEXT_START, HexagonHeat_TEXT_END, HexagonHeat_DATA_START, HexagonHeat_RODATA_END, HexagonHeat_bss_VRAM, HexagonHeat_bss_VRAM},
// {SkateboardScamper_ROM_START, SkateboardScamper_ROM_END, SkateboardScamper_VRAM, SkateboardScamper_TEXT_START, SkateboardScamper_TEXT_END, SkateboardScamper_DATA_START, SkateboardScamper_RODATA_END, SkateboardScamper_bss_VRAM, SkateboardScamper_bss_VRAM},
// {SlotCarDerby_ROM_START, SlotCarDerby_ROM_END, SlotCarDerby_VRAM, SlotCarDerby_TEXT_START, SlotCarDerby_TEXT_END, SlotCarDerby_DATA_START, SlotCarDerby_RODATA_END, SlotCarDerby_bss_VRAM, SlotCarDerby_bss_VRAM},
// {ShyGuySays_ROM_START, ShyGuySays_ROM_END, ShyGuySays_VRAM, ShyGuySays_TEXT_START, ShyGuySays_TEXT_END, ShyGuySays_DATA_START, ShyGuySays_RODATA_END, ShyGuySays_bss_VRAM, ShyGuySays_bss_VRAM},
// {SneakNSnore_ROM_START, SneakNSnore_ROM_END, SneakNSnore_VRAM, SneakNSnore_TEXT_START, SneakNSnore_TEXT_END, SneakNSnore_DATA_START, SneakNSnore_RODATA_END, SneakNSnore_bss_VRAM, SneakNSnore_bss_VRAM},
// {DriversEd_ROM_START, DriversEd_ROM_END, DriversEd_VRAM, DriversEd_TEXT_START, DriversEd_TEXT_END, DriversEd_DATA_START, DriversEd_RODATA_END, DriversEd_bss_VRAM, DriversEd_bss_VRAM},
// {ChanceTime_ROM_START, ChanceTime_ROM_END, ChanceTime_VRAM, ChanceTime_TEXT_START, ChanceTime_TEXT_END, ChanceTime_DATA_START, ChanceTime_RODATA_END, ChanceTime_bss_VRAM, ChanceTime_bss_VRAM},
// {LooneyLumberjacks_ROM_START, LooneyLumberjacks_ROM_END, LooneyLumberjacks_VRAM, LooneyLumberjacks_TEXT_START, LooneyLumberjacks_TEXT_END, LooneyLumberjacks_DATA_START, LooneyLumberjacks_RODATA_END, LooneyLumberjacks_bss_VRAM, LooneyLumberjacks_bss_VRAM},
// {DizzyDancing_ROM_START, DizzyDancing_ROM_END, DizzyDancing_VRAM, DizzyDancing_TEXT_START, DizzyDancing_TEXT_END, DizzyDancing_DATA_START, DizzyDancing_RODATA_END, DizzyDancing_bss_VRAM, DizzyDancing_bss_VRAM},
// {TileDriver_ROM_START, TileDriver_ROM_END, TileDriver_VRAM, TileDriver_TEXT_START, TileDriver_TEXT_END, TileDriver_DATA_START, TileDriver_RODATA_END, TileDriver_bss_VRAM, TileDriver_bss_VRAM},
// {QuicksandCache_ROM_START, QuicksandCache_ROM_END, QuicksandCache_VRAM, QuicksandCache_TEXT_START, QuicksandCache_TEXT_END, QuicksandCache_DATA_START, QuicksandCache_RODATA_END, QuicksandCache_bss_VRAM, QuicksandCache_bss_VRAM},
// {BowsersBigBlast_ROM_START, BowsersBigBlast_ROM_END, BowsersBigBlast_VRAM, BowsersBigBlast_TEXT_START, BowsersBigBlast_TEXT_END, BowsersBigBlast_DATA_START, BowsersBigBlast_RODATA_END, BowsersBigBlast_bss_VRAM, BowsersBigBlast_bss_VRAM},
// {TorpedoTargets_ROM_START, TorpedoTargets_ROM_END, TorpedoTargets_VRAM, TorpedoTargets_TEXT_START, TorpedoTargets_TEXT_END, TorpedoTargets_DATA_START, TorpedoTargets_RODATA_END, TorpedoTargets_bss_VRAM, TorpedoTargets_bss_VRAM},
// {DestructionDuet_ROM_START, DestructionDuet_ROM_END, DestructionDuet_VRAM, DestructionDuet_TEXT_START, DestructionDuet_TEXT_END, DestructionDuet_DATA_START, DestructionDuet_RODATA_END, DestructionDuet_bss_VRAM, DestructionDuet_bss_VRAM},
// {DeepSeaSalvage_ROM_START, DeepSeaSalvage_ROM_END, DeepSeaSalvage_VRAM, DeepSeaSalvage_TEXT_START, DeepSeaSalvage_TEXT_END, DeepSeaSalvage_DATA_START, DeepSeaSalvage_RODATA_END, DeepSeaSalvage_bss_VRAM, DeepSeaSalvage_bss_VRAM},
// {name_3D_ROM_START, name_3D_ROM_END, name_3D_VRAM, name_3D_TEXT_START, name_3D_TEXT_END, name_3D_DATA_START, name_3D_RODATA_END, name_3D_bss_VRAM, name_3D_bss_VRAM},
// {name_3E_ROM_START, name_3E_ROM_END, name_3E_VRAM, name_3E_TEXT_START, name_3E_TEXT_END, name_3E_DATA_START, name_3E_RODATA_END, name_3E_bss_VRAM, name_3E_bss_VRAM},
// {DesertDuel_ROM_START, DesertDuel_ROM_END, DesertDuel_VRAM, DesertDuel_TEXT_START, DesertDuel_TEXT_END, DesertDuel_DATA_START, DesertDuel_RODATA_END, DesertDuel_bss_VRAM, DesertDuel_bss_VRAM},
// {Last5Turns_ROM_START, Last5Turns_ROM_END, Last5Turns_VRAM, Last5Turns_TEXT_START, Last5Turns_TEXT_END, Last5Turns_DATA_START, Last5Turns_RODATA_END, Last5Turns_bss_VRAM, Last5Turns_bss_VRAM},
// {name_41_ROM_START, name_41_ROM_END, name_41_VRAM, name_41_TEXT_START, name_41_TEXT_END, name_41_DATA_START, name_41_RODATA_END, name_41_bss_VRAM, name_41_bss_VRAM},
// {PirateDuel_ROM_START, PirateDuel_ROM_END, PirateDuel_VRAM, PirateDuel_TEXT_START, PirateDuel_TEXT_END, PirateDuel_DATA_START, PirateDuel_RODATA_END, PirateDuel_bss_VRAM, PirateDuel_bss_VRAM},
// {name_43_ROM_START, name_43_ROM_END, name_43_VRAM, name_43_TEXT_START, name_43_TEXT_END, name_43_DATA_START, name_43_RODATA_END, name_43_bss_VRAM, name_43_bss_VRAM},
// {name_44_ROM_START, name_44_ROM_END, name_44_VRAM, name_44_TEXT_START, name_44_TEXT_END, name_44_DATA_START, name_44_RODATA_END, name_44_bss_VRAM, name_44_bss_VRAM},
// {name_45_ROM_START, name_45_ROM_END, name_45_VRAM, name_45_TEXT_START, name_45_TEXT_END, name_45_DATA_START, name_45_RODATA_END, name_45_bss_VRAM, name_45_bss_VRAM},
// {name_46_ROM_START, name_46_ROM_END, name_46_VRAM, name_46_TEXT_START, name_46_TEXT_END, name_46_DATA_START, name_46_RODATA_END, name_46_bss_VRAM, name_46_bss_VRAM},
// {name_47_ROM_START, name_47_ROM_END, name_47_VRAM, name_47_TEXT_START, name_47_TEXT_END, name_47_DATA_START, name_47_RODATA_END, name_47_bss_VRAM, name_47_bss_VRAM},
// {name_48_ROM_START, name_48_ROM_END, name_48_VRAM, name_48_TEXT_START, name_48_TEXT_END, name_48_DATA_START, name_48_RODATA_END, name_48_bss_VRAM, name_48_bss_VRAM},
// {name_49_ROM_START, name_49_ROM_END, name_49_VRAM, name_49_TEXT_START, name_49_TEXT_END, name_49_DATA_START, name_49_RODATA_END, name_49_bss_VRAM, name_49_bss_VRAM},
// {name_4A_ROM_START, name_4A_ROM_END, name_4A_VRAM, name_4A_TEXT_START, name_4A_TEXT_END, name_4A_DATA_START, name_4A_RODATA_END, name_4A_bss_VRAM, name_4A_bss_VRAM},
// {name_4B_ROM_START, name_4B_ROM_END, name_4B_VRAM, name_4B_TEXT_START, name_4B_TEXT_END, name_4B_DATA_START, name_4B_RODATA_END, name_4B_bss_VRAM, name_4B_bss_VRAM},
// {name_4C_ROM_START, name_4C_ROM_END, name_4C_VRAM, name_4C_TEXT_START, name_4C_TEXT_END, name_4C_DATA_START, name_4C_RODATA_END, name_4C_bss_VRAM, name_4C_bss_VRAM},
// {RulesLand_ROM_START, RulesLand_ROM_END, RulesLand_VRAM, RulesLand_TEXT_START, RulesLand_TEXT_END, RulesLand_DATA_START, RulesLand_RODATA_END, RulesLand_bss_VRAM, RulesLand_bss_VRAM},
// {name_4E_ROM_START, name_4E_ROM_END, name_4E_VRAM, name_4E_TEXT_START, name_4E_TEXT_END, name_4E_DATA_START, name_4E_RODATA_END, name_4E_bss_VRAM, name_4E_bss_VRAM},
// {name_4F_ROM_START, name_4F_ROM_END, name_4F_VRAM, name_4F_TEXT_START, name_4F_TEXT_END, name_4F_DATA_START, name_4F_RODATA_END, name_4F_bss_VRAM, name_4F_bss_VRAM},
// {name_50_ROM_START, name_50_ROM_END, name_50_VRAM, name_50_TEXT_START, name_50_TEXT_END, name_50_DATA_START, name_50_RODATA_END, name_50_bss_VRAM, name_50_bss_VRAM},
// {name_51_ROM_START, name_51_ROM_END, name_51_VRAM, name_51_TEXT_START, name_51_TEXT_END, name_51_DATA_START, name_51_RODATA_END, name_51_bss_VRAM, name_51_bss_VRAM},
// {name_52_ROM_START, name_52_ROM_END, name_52_VRAM, name_52_TEXT_START, name_52_TEXT_END, name_52_DATA_START, name_52_RODATA_END, name_52_bss_VRAM, name_52_bss_VRAM},
// {name_53_ROM_START, name_53_ROM_END, name_53_VRAM, name_53_TEXT_START, name_53_TEXT_END, name_53_DATA_START, name_53_RODATA_END, name_53_bss_VRAM, name_53_bss_VRAM},
// {name_54_ROM_START, name_54_ROM_END, name_54_VRAM, name_54_TEXT_START, name_54_TEXT_END, name_54_DATA_START, name_54_RODATA_END, name_54_bss_VRAM, name_54_bss_VRAM},
// {name_55_ROM_START, name_55_ROM_END, name_55_VRAM, name_55_TEXT_START, name_55_TEXT_END, name_55_DATA_START, name_55_RODATA_END, name_55_bss_VRAM, name_55_bss_VRAM},
// {name_56_ROM_START, name_56_ROM_END, name_56_VRAM, name_56_TEXT_START, name_56_TEXT_END, name_56_DATA_START, name_56_RODATA_END, name_56_bss_VRAM, name_56_bss_VRAM},
// {name_57_ROM_START, name_57_ROM_END, name_57_VRAM, name_57_TEXT_START, name_57_TEXT_END, name_57_DATA_START, name_57_RODATA_END, name_57_bss_VRAM, name_57_bss_VRAM},
// {name_58_ROM_START, name_58_ROM_END, name_58_VRAM, name_58_TEXT_START, name_58_TEXT_END, name_58_DATA_START, name_58_RODATA_END, name_58_bss_VRAM, name_58_bss_VRAM},
// {name_59_ROM_START, name_59_ROM_END, name_59_VRAM, name_59_TEXT_START, name_59_TEXT_END, name_59_DATA_START, name_59_RODATA_END, name_59_bss_VRAM, name_59_bss_VRAM},
// {name_5A_ROM_START, name_5A_ROM_END, name_5A_VRAM, name_5A_TEXT_START, name_5A_TEXT_END, name_5A_DATA_START, name_5A_RODATA_END, name_5A_bss_VRAM, name_5A_bss_VRAM},
// {name_5B_ROM_START, name_5B_ROM_END, name_5B_VRAM, name_5B_TEXT_START, name_5B_TEXT_END, name_5B_DATA_START, name_5B_RODATA_END, name_5B_bss_VRAM, name_5B_bss_VRAM},
// {name_5C_ROM_START, name_5C_ROM_END, name_5C_VRAM, name_5C_TEXT_START, name_5C_TEXT_END, name_5C_DATA_START, name_5C_RODATA_END, name_5C_bss_VRAM, name_5C_bss_VRAM},
// {name_5D_ROM_START, name_5D_ROM_END, name_5D_VRAM, name_5D_TEXT_START, name_5D_TEXT_END, name_5D_DATA_START, name_5D_RODATA_END, name_5D_bss_VRAM, name_5D_bss_VRAM},
// {name_5E_ROM_START, name_5E_ROM_END, name_5E_VRAM, name_5E_TEXT_START, name_5E_TEXT_END, name_5E_DATA_START, name_5E_RODATA_END, name_5E_bss_VRAM, name_5E_bss_VRAM},
// {name_5F_ROM_START, name_5F_ROM_END, name_5F_VRAM, name_5F_TEXT_START, name_5F_TEXT_END, name_5F_DATA_START, name_5F_RODATA_END, name_5F_bss_VRAM, name_5F_bss_VRAM},
// {name_60_ROM_START, name_60_ROM_END, name_60_VRAM, name_60_TEXT_START, name_60_TEXT_END, name_60_DATA_START, name_60_RODATA_END, name_60_bss_VRAM, name_60_bss_VRAM},
// {name_61_ROM_START, name_61_ROM_END, name_61_VRAM, name_61_TEXT_START, name_61_TEXT_END, name_61_DATA_START, name_61_RODATA_END, name_61_bss_VRAM, name_61_bss_VRAM},
// {name_62_ROM_START, name_62_ROM_END, name_62_VRAM, name_62_TEXT_START, name_62_TEXT_END, name_62_DATA_START, name_62_RODATA_END, name_62_bss_VRAM, name_62_bss_VRAM},
// {name_63_ROM_START, name_63_ROM_END, name_63_VRAM, name_63_TEXT_START, name_63_TEXT_END, name_63_DATA_START, name_63_RODATA_END, name_63_bss_VRAM, name_63_bss_VRAM},
// {name_64_ROM_START, name_64_ROM_END, name_64_VRAM, name_64_TEXT_START, name_64_TEXT_END, name_64_DATA_START, name_64_RODATA_END, name_64_bss_VRAM, name_64_bss_VRAM},
// {name_65_ROM_START, name_65_ROM_END, name_65_VRAM, name_65_TEXT_START, name_65_TEXT_END, name_65_DATA_START, name_65_RODATA_END, name_65_bss_VRAM, name_65_bss_VRAM},
// {name_66_ROM_START, name_66_ROM_END, name_66_VRAM, name_66_TEXT_START, name_66_TEXT_END, name_66_DATA_START, name_66_RODATA_END, name_66_bss_VRAM, name_66_bss_VRAM},
// {name_67_ROM_START, name_67_ROM_END, name_67_VRAM, name_67_TEXT_START, name_67_TEXT_END, name_67_DATA_START, name_67_RODATA_END, name_67_bss_VRAM, name_67_bss_VRAM},
// {name_68_ROM_START, name_68_ROM_END, name_68_VRAM, name_68_TEXT_START, name_68_TEXT_END, name_68_DATA_START, name_68_RODATA_END, name_68_bss_VRAM, name_68_bss_VRAM},
// {name_69_ROM_START, name_69_ROM_END, name_69_VRAM, name_69_TEXT_START, name_69_TEXT_END, name_69_DATA_START, name_69_RODATA_END, name_69_bss_VRAM, name_69_bss_VRAM},
// {name_6A_ROM_START, name_6A_ROM_END, name_6A_VRAM, name_6A_TEXT_START, name_6A_TEXT_END, name_6A_DATA_START, name_6A_RODATA_END, name_6A_bss_VRAM, name_6A_bss_VRAM},
// {name_6B_ROM_START, name_6B_ROM_END, name_6B_VRAM, name_6B_TEXT_START, name_6B_TEXT_END, name_6B_DATA_START, name_6B_RODATA_END, name_6B_bss_VRAM, name_6B_bss_VRAM},
// {name_6C_ROM_START, name_6C_ROM_END, name_6C_VRAM, name_6C_TEXT_START, name_6C_TEXT_END, name_6C_DATA_START, name_6C_RODATA_END, name_6C_bss_VRAM, name_6C_bss_VRAM},
// {name_6D_ROM_START, name_6D_ROM_END, name_6D_VRAM, name_6D_TEXT_START, name_6D_TEXT_END, name_6D_DATA_START, name_6D_RODATA_END, name_6D_bss_VRAM, name_6D_bss_VRAM},
// {name_6E_ROM_START, name_6E_ROM_END, name_6E_VRAM, name_6E_TEXT_START, name_6E_TEXT_END, name_6E_DATA_START, name_6E_RODATA_END, name_6E_bss_VRAM, name_6E_bss_VRAM},
// {name_6F_ROM_START, name_6F_ROM_END, name_6F_VRAM, name_6F_TEXT_START, name_6F_TEXT_END, name_6F_DATA_START, name_6F_RODATA_END, name_6F_bss_VRAM, name_6F_bss_VRAM},
// {name_70_ROM_START, name_70_ROM_END, name_70_VRAM, name_70_TEXT_START, name_70_TEXT_END, name_70_DATA_START, name_70_RODATA_END, name_70_bss_VRAM, name_70_bss_VRAM},
// {name_71_ROM_START, name_71_ROM_END, name_71_VRAM, name_71_TEXT_START, name_71_TEXT_END, name_71_DATA_START, name_71_RODATA_END, name_71_bss_VRAM, name_71_bss_VRAM},
// {name_72_ROM_START, name_72_ROM_END, name_72_VRAM, name_72_TEXT_START, name_72_TEXT_END, name_72_DATA_START, name_72_RODATA_END, name_72_bss_VRAM, name_72_bss_VRAM},
// };

// f32 D_800C98C4_CA4C4 = 640.0f;

// f32 D_800C98C8_CA4C8[] = {
//     480.0f,
//     511.0f,
//     640.0f,
//     480.0f,
//     511.0f,
//     640.0f,
//     480.0f,
//     511.0f,
//     640.0f,
//     480.0f,
//     511.0f,
//     640.0f,
//     480.0f,
//     511.0f,
//     0.0f,
//     0.0f,
//     0.0f,
//     640.0f
// };