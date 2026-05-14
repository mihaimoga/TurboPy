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

// TurboPyView.h : interface of the CTurboPyView class
//

#pragma once

#include "ScintillaDocView.h"

class CTurboPyView : public Scintilla::CScintillaView
{
protected: // create from serialization only
	CTurboPyView() noexcept;
	DECLARE_DYNCREATE(CTurboPyView)

// Attributes
public:
	CTurboPyDoc* GetDocument() const;

// Operations
public:

protected:
// Member variables
	Scintilla::ILexer5* m_pPythonLexer;

// Methods
	void SetAStyle(_In_ int style, _In_ COLORREF fore, _In_ COLORREF back = RGB(0xFF, 0xFF, 0xFF), _In_ int size = -1, _In_opt_z_ const char* face = nullptr);
	void OnInitialUpdate() override;
	void OnModified(_Inout_ Scintilla::NotificationData* pSCNotification) override;

// Implementation
public:
	virtual ~CTurboPyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// Message handlers
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

// Generated message map functions
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TurboPyView.cpp
inline CTurboPyDoc* CTurboPyView::GetDocument() const
   { return reinterpret_cast<CTurboPyDoc*>(m_pDocument); }
#endif
