#pragma once
#include <Windows.h>

LRESULT WINAPI HookedCode(int, WPARAM, LPARAM);

int wWinMain(HINSTANCE, HINSTANCE, PWSTR, int);
