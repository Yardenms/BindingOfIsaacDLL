// dllmain.cpp : Defines the entry point for the DLL application.
#pragma comment(lib, "detours.lib")
#include "pch.h"
#include <Windows.h>
#include <string>
#include "detours.h"


VOID WINAPI showConsole()
{
    AllocConsole();
    AttachConsole(GetCurrentProcessId());

    freopen("CON", "w", stdout);

    char cc[128];
    sprintf_s(cc, "Client: %i", GetCurrentProcessId());
    SetConsoleTitleA(cc);
}

int get_base_addr() 
{
    DWORD base_address = (DWORD)GetModuleHandle(NULL);
    return base_address;
}

BOOL SetHook(BOOL bInstall, PVOID* ppvTarget, PVOID pvDetour)
{
    if (DetourTransactionBegin() != NO_ERROR)
    {
        return FALSE;
    }

    auto tid = GetCurrentThread();

    if (DetourUpdateThread(tid) == NO_ERROR)
    {
        auto func = bInstall ? DetourAttach : DetourDetach;

        if (func(ppvTarget, pvDetour) == NO_ERROR)
        {
            if (DetourTransactionCommit() == NO_ERROR)
            {
                return TRUE;
            }
        }
    }

    DetourTransactionAbort();
    return FALSE;
}

BOOL create_hooks()
{
    typedef int(__cdecl* startf)(int a1, int a2);
    static auto startf_instance = (startf)(get_base_addr() + 0x85F390);
    //static auto startf_1 = (startf)(0x88BC50);
    typedef int(__cdecl* startf1)();
    static auto startf_1 = (startf1)(get_base_addr() + 0x5EB6BC);

    startf toHook = [](int a1, int a2) -> int {
        //printf("%d", get_base_addr());
        //return startf_instance(a1, a2);
        return startf_1();
    };

    return SetHook(TRUE, reinterpret_cast<void**>(&startf_instance), toHook);
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    BOOL result;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        showConsole();

        result = SetEnvironmentVariableA("SteamAppId", "250900");
        printf("%d", result);

        printf("%d", get_base_addr());        
        create_hooks();
        //Sleep(100000);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

