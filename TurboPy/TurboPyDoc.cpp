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

// TurboPyDoc.cpp : implementation of the CTurboPyDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TurboPy.h"
#endif

#include "TurboPyDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTurboPyDoc

IMPLEMENT_DYNCREATE(CTurboPyDoc, CScintillaDoc)

BEGIN_MESSAGE_MAP(CTurboPyDoc, CScintillaDoc)
END_MESSAGE_MAP()

// CTurboPyDoc construction/destruction

CTurboPyDoc::CTurboPyDoc() noexcept
{
}

CTurboPyDoc::~CTurboPyDoc()
{
}

// CTurboPyDoc diagnostics

#ifdef _DEBUG
void CTurboPyDoc::AssertValid() const
{
	CScintillaDoc::AssertValid();
}

void CTurboPyDoc::Dump(CDumpContext& dc) const
{
	CScintillaDoc::Dump(dc);
}
#endif //_DEBUG

// CTurboPyDoc commands
