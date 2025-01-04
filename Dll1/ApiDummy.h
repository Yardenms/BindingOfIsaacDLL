#pragma once
#pragma comment(lib, "detours.lib")

#define API __declspec(dllimport)

class API APIDummy {
public:
	APIDummy(void);
};

extern "C" __declspec(dllexport) __declspec() int SteamInternal_ContextInit() {
	MessageBox(0, L"here1", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_GetHSteamPipe() {
	MessageBox(0, L"here2", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_GetHSteamUser() {
	MessageBox(0, L"here3", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamInternal_CreateInterface() {
	MessageBox(0, L"here4", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_RegisterCallback() {
	MessageBox(0, L"here5", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_RegisterCallResult() {
	MessageBox(0, L"here6", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_UnregisterCallResult() {
	MessageBox(0, L"here7", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_RunCallbacks() {
	MessageBox(0, L"here8", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_Shutdown() {
	MessageBox(0, L"here9", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_Init() {
	MessageBox(0, L"here10", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 0;
}

extern "C" __declspec(dllexport) __declspec() int SteamAPI_UnregisterCallback() {
	MessageBox(0, L"here11", L"Msg title", MB_OK | MB_ICONQUESTION);
	return 1;
}

