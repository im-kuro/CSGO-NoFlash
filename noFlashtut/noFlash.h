#include "memory.h"

#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
// initialize memory class
const auto memory = Memory{ "csgo.exe" };

// module addresses
const auto client = memory.GetModuleAddress("client.dll");

// offsets
constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDEA964;
constexpr ::std::ptrdiff_t m_flFlashMaxAlpha = 0x1046C;

// run the actual no flash cheat
int runNoFlash() {
	// read our local player using the client module and localPlayer offset
	const auto ourPlayer = memory.Read<std::uintptr_t>(client + dwLocalPlayer);
	// write to the local player (you) that the flash level is set to 0.f (float) 
	memory.Write<float>(ourPlayer + m_flFlashMaxAlpha, 0.f);

	return 0;
}










