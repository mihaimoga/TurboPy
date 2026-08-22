# Agent Guidelines for TurboPy

This document provides essential context, architectural structure, build workflows, and coding conventions for AI coding agents and human developers working on the **TurboPy** repository.

---

## 1. Project Overview

**TurboPy** is a lightweight, fast, native Integrated Development Environment (IDE) for Python on Microsoft Windows, licensed under the **GNU General Public License v3.0 (GPLv3)**.

- **Primary Language:** C++ (compiled with `/std:c++latest` and `/std:clatest`)
- **Frameworks & Subsystems:** Win32 API, Microsoft Foundation Classes (MFC with Ribbon UI and Docking Panes), Standard Template Library (STL)
- **Key Editor & Lexing Engine:** Scintilla & Lexilla
- **Auto-Updater Engine:** `genUp4win`

---

## 2. Solution & Project Structure

The primary solution file is `TurboPy.slnx` (Visual Studio XML-based Solution format).

```
TurboPy/
├── TurboPy/                     # Main MFC GUI Application
│   ├── TurboPy.{h,cpp}          # CWinApp application class & entry point
│   ├── MainFrame.{h,cpp}        # CMDIFrameWndEx main frame & Ribbon UI
│   ├── ChildFrame.{h,cpp}       # CMDIChildWndEx MDI child window frame
│   ├── TurboPyDoc.{h,cpp}       # Document model (CDocument / CScintillaDoc)
│   ├── TurboPyView.{h,cpp}      # View model (CView / CScintillaView)
│   ├── ScintillaCtrl.{h,cpp}    # Scintilla MFC control wrapper (PJ Naughter)
│   ├── ScintillaDocView.{h,cpp} # Scintilla Doc/View integration
│   ├── HLinkCtrl.{h,cpp}        # Hyperlink control wrapper (PJ Naughter)
│   ├── VersionInfo.{h,cpp}      # Version resource helper (PJ Naughter)
│   ├── FileView.{h,cpp}         # Workspace / File Explorer dockable pane
│   ├── ClassView.{h,cpp}        # Python symbol / class tree dockable pane
│   ├── OutputWnd.{h,cpp}        # Output / console dockable pane
│   ├── PropertiesWnd.{h,cpp}    # Properties inspector dockable pane
│   ├── TurboPy.rc               # Resource script (menus, dialogs, icons)
│   └── res/                     # Bitmaps, icons, ribbon definition (.mfcribbon-ms)
├── scintilla/                   # Scintilla editor core library (Win32 control)
│   └── win32/Scintilla.vcxproj  # Scintilla vcxproj
├── lexilla/                     # Lexilla lexer modules (syntax highlighters)
│   └── src/Lexilla.vcxproj      # Lexilla vcxproj
├── genUp4win/                   # Generic Auto-updater library
│   └── genUp4win.vcxproj        # genUp4win vcxproj
├── Setup/                       # Deployment / installer project (.vdproj)
├── cpython/                     # Python runtime dependencies / headers
├── TurboPy.slnx                 # Main Visual Studio Solution
├── CONTRIBUTING.md              # Project contribution & style guidelines
├── README.md                    # User introduction & installation
└── LICENSE                      # GNU General Public License v3.0
```

---

## 3. Development Environment & Prerequisites

- **OS:** Windows 10 / Windows 11 (x64 / x86)
- **IDE:** Visual Studio 2022 (v17.x or later)
- **Workloads & Components:**
  - *Desktop development with C++*
  - *C++ MFC for latest v143/v145 build tools* (x86 & x64)
  - *C++ ATL for latest v143/v145 build tools* (x86 & x64)
  - *Windows 10/11 SDK* (10.0.x)
  - *C++ Clang Compiler for Windows* / *MSVC v145/v143 Toolset*

---

## 4. Build & Verification Workflows

### Building from Visual Studio
1. Open `TurboPy.slnx` in Visual Studio.
2. Select target platform (`x64` recommended, or `Win32`) and configuration (`Debug` or `Release`).
3. Build the solution (`Ctrl+Shift+B` or *Build -> Build Solution*).

### Building via Command Line (MSBuild)
```powershell
# Build x64 Debug configuration
msbuild TurboPy.slnx /p:Configuration=Debug /p:Platform=x64

# Build x64 Release configuration
msbuild TurboPy.slnx /p:Configuration=Release /p:Platform=x64
```

### Static Analysis & Verification
- Code analysis (`RunCodeAnalysis=true`) is configured in the projects. Always ensure zero compiler errors and address static analysis warnings before submitting changes.

---

## 5. Coding Standards & Style Conventions

Adhere strictly to the project style rules defined in `CONTRIBUTING.md`:

### Formatting & Braces
- **Indentations:** Use tabs for indentation (tab stop set to 4 spaces equivalent).
- **Braces (Allman style):** Opening and closing braces must be on their own lines for classes, functions, and control blocks. Java-like braces (`{` on the same line) are prohibited, except for single-line trivial method definitions inside header (`.h`) files.
  ```cpp
  // Good
  void MyClass::method1()
  {
	  if (aCondition)
	  {
		  // Action
	  }
  }
  ```
- **Operator Spacing:** Place exactly one space before and after binary and ternary operators (`a == 10 && b == 42`).
- **Control Keywords:** Place one space between control keywords and parentheses (`if (condition)`, `for (int i = 0; i != 10; ++i)`).
- **Function Calls:** No space between function name and the argument list (`myFunction(arg1, arg2)`).

### Naming Conventions
- **Classes & Structs:** `PascalCase` (e.g., `CTurboPyView`, `CMainFrame`).
- **Methods & Functions:** `camelCase` for internal methods; standard MFC handler conventions (`OnCreate`, `OnDraw`, `OnUpdate...`) where integrating with MFC message maps.
- **Member Variables:** Preceded by an underscore `_` (e.g., `_myAttribute`, `_pEditView`) or standard MFC Hungarian notation where matching existing MFC patterns.
- **Descriptive Names:** Avoid single-letter or cryptic variable names (e.g., `hours`, `minutes`, `seconds` instead of `a`, `b`, `c`).

### C++ Best Practices & Idioms
- **Modern C++:** Use modern C++ standards (C++17/20/latest), RAII, and brace initialization (`MyClass instance{10.4};`).
- **Pointers & Memory:** Prefer references and smart pointers (`std::unique_ptr`). Avoid raw `new`/`delete` and avoid `std::shared_ptr` unless shared ownership is strictly required.
- **Casts:** Always use C++-style casts (`static_cast`, `reinterpret_cast`, `dynamic_cast`) instead of C-style casts (`(type)val`).
- **Strings:** Use `.empty()` to check for empty strings instead of `str == ""`.
- **Pre-increment:** Prefer pre-increment (`++i`) over post-increment (`i++`).
- **Header Directives:** Never put `using namespace` in header files.
- **Comments:** Prefer C++ single-line comments (`// ...`) over C-style multi-line comments (`/* ... */`).

---

## 6. Guidelines for AI Agents

When working on tasks in this repository:
1. **Targeted Changes:** Make compact, surgical edits. Do not perform mass reformatting, whitespace adjustments, or cosmetic refactorings unrelated to the requested task.
2. **Resource & UI Files:** Be cautious when editing MFC resource files (`Resource.h`, `TurboPy.rc`, `TurboPy.rc2`, `res/ribbon.mfcribbon-ms`). Maintain symbol ID integrity.
3. **Third-Party Libraries:** Respect third-party code boundaries in `scintilla/`, `lexilla/`, `genUp4win/`, and PJ Naughter helper classes (`HLinkCtrl`, `ScintillaCtrl`, `VersionInfo`).
4. **Validation:** Always verify changes by building the solution (`run_build` or `msbuild`) and checking for errors or warnings before declaring task completion.
