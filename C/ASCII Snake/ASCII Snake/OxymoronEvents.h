#pragma once

#include <processthreadsapi.h>
#include <conio.h>

char eventChar = ' ';

DWORD WINAPI getChar(void* data) {
	while (true) {
		eventChar = _getch();
	}
}

void initializeEventSystem() {
	CreateThread(NULL, 0, getChar, NULL, 0, NULL);
}