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

// TurboPyView.cpp : implementation of the CTurboPyView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TurboPy.h"
#endif

#include "MainFrame.h"
#include "TurboPyDoc.h"
#include "TurboPyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Taken from "lib\keyword.py" in the Python distribution
constexpr const TCHAR* g_pyKeyWords = _T("False None True __peg_parser__ and as assert async await break class continue def del elif else except finally for from global if import in is lambda nonlocal not or pass raise return try while with yield");

// CTurboPyView

IMPLEMENT_DYNCREATE(CTurboPyView, CScintillaView)

BEGIN_MESSAGE_MAP(CTurboPyView, CScintillaView)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CTurboPyView construction/destruction

CTurboPyView::CTurboPyView() noexcept : m_pPythonLexer(nullptr)
{
	// TODO: add construction code here
}

CTurboPyView::~CTurboPyView()
{
}

// CTurboPyView message handlers

void CTurboPyView::SetAStyle(_In_ int style, _In_ COLORREF fore, _In_ COLORREF back, _In_ int size, _In_opt_z_ const char* face)
{
	auto& rCtrl{ GetCtrl() };

	rCtrl.StyleSetFore(style, fore);
	rCtrl.StyleSetBack(style, back);
	if (size >= 1)
		rCtrl.StyleSetSize(style, size);
	if (face != nullptr)
		rCtrl.StyleSetFont(style, face);
}

void CTurboPyView::OnInitialUpdate()
{
	// Let the base class do its thing
	__super::OnInitialUpdate();

	auto& rCtrl{ GetCtrl() };

	// Setup the Lexer
	rCtrl.SetILexer(m_pPythonLexer);
	rCtrl.SetKeyWords(0, g_pyKeyWords);
	SetAStyle(static_cast<int>(Scintilla::StylesCommon::Default), RGB(0, 0, 0), RGB(0xff, 0xff, 0xff), 10, "Consolas");
	rCtrl.StyleClearAll();
	SetAStyle(SCE_P_DEFAULT, RGB(0, 0, 0));
	SetAStyle(SCE_P_COMMENTLINE, RGB(0, 0x80, 0));
	SetAStyle(SCE_P_COMMENTBLOCK, RGB(0, 0x80, 0));
	SetAStyle(SCE_P_NUMBER, RGB(0, 0x80, 0x80));
	SetAStyle(SCE_P_WORD, RGB(0, 0, 0x80));
	rCtrl.StyleSetBold(SCE_P_WORD, 1);
	SetAStyle(SCE_P_WORD2, RGB(0, 0, 0x80));
	rCtrl.StyleSetBold(SCE_P_WORD2, 1);
	SetAStyle(SCE_P_STRING, RGB(0x80, 0, 0x80));
	SetAStyle(SCE_P_CHARACTER, RGB(0x80, 0, 0x80));
	SetAStyle(SCE_P_TRIPLE, RGB(0x80, 0, 0x80));
	SetAStyle(SCE_P_TRIPLEDOUBLE, RGB(0x80, 0, 0x80));
	SetAStyle(SCE_P_IDENTIFIER, RGB(0, 0, 0));
	SetAStyle(SCE_P_CLASSNAME, RGB(0, 0, 0));
	SetAStyle(SCE_P_DEFNAME, RGB(0, 0, 0));
	SetAStyle(SCE_P_OPERATOR, RGB(0x80, 0, 0));

	// Setup our markers
	rCtrl.SetMarginWidthN(1, 16);
	rCtrl.SetMarginTypeN(1, Scintilla::MarginType::Symbol);
	rCtrl.MarkerDefine(SC_PYTHON_MARK_ENABLED_BREAKPOINT, Scintilla::MarkerSymbol::Circle);
	rCtrl.MarkerSetFore(SC_PYTHON_MARK_ENABLED_BREAKPOINT, RGB(255, 0, 0));
	rCtrl.MarkerSetBack(SC_PYTHON_MARK_ENABLED_BREAKPOINT, RGB(255, 0, 0));
	rCtrl.MarkerDefine(SC_PYTHON_MARK_DISABLED_BREAKPOINT, Scintilla::MarkerSymbol::Circle);
	rCtrl.MarkerSetFore(SC_PYTHON_MARK_DISABLED_BREAKPOINT, RGB(255, 0, 0));
	rCtrl.MarkerDefine(SC_PYTHON_MARK_INSTRUCTION_POINTER, Scintilla::MarkerSymbol::ShortArrow);
	rCtrl.MarkerSetFore(SC_PYTHON_MARK_INSTRUCTION_POINTER, RGB(0, 0, 0));
	rCtrl.MarkerSetBack(SC_PYTHON_MARK_INSTRUCTION_POINTER, RGB(255, 255, 0));

	// Setup the notification for modified text
	rCtrl.SetModEventMask(Scintilla::ModificationFlags::InsertText | Scintilla::ModificationFlags::DeleteText);

	// Show line numbers
	rCtrl.SetMarginWidthN(0, 32);

	// Set word wrap
	rCtrl.SetWrapMode(Scintilla::Wrap::Word);
}

void CTurboPyView::OnModified(_Inout_ Scintilla::NotificationData* /*pSCNotification*/)
{
#pragma warning(suppress: 26429)
	CTurboPyDoc* pDoc{ GetDocument() };
	ASSERT(pDoc != nullptr);

	// TODO: pDoc->UpdateBreakpointsFromUI();
}

#pragma warning(suppress: 26434)
int CTurboPyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// Let the base class do its thing
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Create the Python Lexer
	m_pPythonLexer = theApp.m_pCreateLexer("python");
	if (m_pPythonLexer == nullptr)
		return -1;

	return 0;
}

// CTurboPyView diagnostics

#ifdef _DEBUG
void CTurboPyView::AssertValid() const
{
	CScintillaView::AssertValid();
}

void CTurboPyView::Dump(CDumpContext& dc) const
{
	CScintillaView::Dump(dc);
}

CTurboPyDoc* CTurboPyView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTurboPyDoc)));
	return (CTurboPyDoc*)m_pDocument;
}
#endif //_DEBUG
