/* Copyright (C) 2026 Stefan-Mihai MOGA
This file is part of TurboPy application developed by Stefan-Mihai MOGA.
TurboPy is an Integrated Development Environment for Python!

TurboPy is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Open
Source Initiative, either version 3 of the License, or any later version.

TurboPy is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
TurboPy. If not, see <http://www.opensource.org/licenses/gpl-3.0.html>*/

// TurboPy.h : main header file for the TurboPy application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTurboPyApp:
// See TurboPy.cpp for the implementation of this class
//

class CTurboPyApp : public CWinAppEx
{
public:
	CTurboPyApp() noexcept;

// Member variables
	Lexilla::CreateLexerFn m_pCreateLexer;

protected:
	HINSTANCE m_hScintilla;
	HINSTANCE m_hLexilla;

// Overrides
public:
	[[nodiscard]] CString GetModuleFileName(_Inout_opt_ DWORD* pdwLastError = nullptr);
	[[nodiscard]] HMODULE LoadLibraryFromApplicationDirectory(_In_z_ LPCTSTR lpFileName);
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTurboPyApp theApp;
