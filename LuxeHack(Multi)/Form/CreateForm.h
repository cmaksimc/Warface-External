#pragma once
#include "../Define/Stdafx.h"
#include "Tools.h"

void MakeWindows()
{
	int X = 20, W = 250;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	Esp_Table1 = CreateWindow(XorString("button"), XorString("Show enemy silhouettes"), StyleCheckBox, X, POS(1), W, 25, hwndMain, (HMENU)1, hinst, NULL);
	Esp_Table2 = CreateWindow(XorString("button"), XorString("Show mines"), StyleCheckBox, X, POS(2), W, 25, hwndMain, (HMENU)2, hinst, NULL);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	Aim_Table1 = CreateWindow(XorString("button"), XorString("Enable Silent-Aim"), StyleCheckBox, X, POS(1), W, 25, hwndMain, (HMENU)3, hinst, NULL);
	Aim_Table2 = CreateWindow(XorString("button"), XorString("Body [Head]"), StyleButton, X, POS(2), W, 25, hwndMain, (HMENU)4, hinst, NULL);
	Aim_Table3 = CreateWindow(XorString("button"), XorString("Aim bosses"), StyleCheckBox, X, POS(3), W, 25, hwndMain, (HMENU)5, hinst, NULL);
	Aim_Table4 = CreateWindow(XorString("button"), XorString("Disable aim [ Capslock ]"), StyleCheckBox, X, POS(4), W, 25, hwndMain, (HMENU)6, hinst, NULL);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	Weapon_Table1 = CreateWindow(XorString("button"), XorString("No Recoil"), StyleCheckBox, X, POS(1), W, 25, hwndMain, (HMENU)7, hinst, NULL);
	Weapon_Table2 = CreateWindow(XorString("button"), XorString("No Spread"), StyleCheckBox, X, POS(2), W, 25, hwndMain, (HMENU)8, hinst, NULL);
	Weapon_Table3 = CreateWindow(XorString("button"), XorString("No Shutter"), StyleCheckBox, X, POS(3), W, 25, hwndMain, (HMENU)9, hinst, NULL);
	Weapon_Table4 = CreateWindow(XorString("button"), XorString("No Sway"), StyleCheckBox, X, POS(4), W, 25, hwndMain, (HMENU)10, hinst, NULL);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	Player_Table1 = CreateWindow(XorString("button"), XorString("Long Slide"), StyleCheckBox, X, POS(1), W, 25, hwndMain, (HMENU)12, hinst, NULL);
	Player_Table2 = CreateWindow(XorString("button"), XorString("Rate bosses"), StyleCheckBox, X, POS(2), W, 25, hwndMain, (HMENU)14, hinst, NULL);
	Player_Table3 = CreateWindow(XorString("button"), XorString("Anti-AFK"), StyleCheckBox, X, POS(3), W, 25, hwndMain, (HMENU)16, hinst, NULL);
	Player_Table4 = CreateWindow(XorString("button"), XorString("AutoShot"), StyleCheckBox, X, POS(4), W, 25, hwndMain, (HMENU)17, hinst, NULL);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		Driver().Unload();
		Driver().DeleteDriver();
		TerminateProcess(GetCurrentProcess(), EXIT_SUCCESS);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_NOTIFY:
		switch (((LPNMHDR)lParam)->code)
		{
		case TCN_SELCHANGE:
		{
			int iPage = TabCtrl_GetCurSel(hwndTab);
			CloseWindows();
			SHWindow(iPage);
			break;
		}
		}
		break;
	case WM_COMMAND:
	{
		switch (wParam)
		{
		case 1:
			set_bool(Settings::ESP::EspSilhouettes, Esp_Table1);
			break;
		case 2:
			set_bool(Settings::ESP::EspMines, Esp_Table2);
			break;
		case 3:
			set_bool(Settings::Aimbot::enabled, Aim_Table1);
			break;
		case 4:
			set_int_text(Settings::Aimbot::bones, Aim_Table2, XorStringW(L"Body [Head]"), XorStringW(L"Body [Spine]"));
			break;
		case 5:
			set_bool(Settings::Aimbot::turets, Aim_Table3);
			break;
		case 6:
			set_bool(Settings::Aimbot::capslock, Aim_Table4);
			break;
		case 7:
			set_bool(Settings::Weapone::norecoil, Weapon_Table1);
			break;
		case 8:
			set_bool(Settings::Weapone::nospread, Weapon_Table2);
			break;
		case 9:
			set_bool(Settings::Weapone::noshoters, Weapon_Table3);
			break;
		case 10:
			set_bool(Settings::Weapone::nosway, Weapon_Table4);
			break;
		case 12:
			set_bool(Settings::Player::longslide, Player_Table1);
			break;
		case 14:
			set_bool(Settings::Player::rotateshl, Player_Table2);
			break;
		case 16:
			set_bool(Settings::Player::afk, Player_Table3);
			break;
		case 17:
			set_bool(Settings::Player::autoshoot, Player_Table4);
			break;
		}
	}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

