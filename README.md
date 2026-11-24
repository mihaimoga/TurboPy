Download:
- [TurboPySetup.msi](https://www.moga.doctor/freeware/TurboPySetup.msi)
- [TurboPy.zip](https://www.moga.doctor/freeware/TurboPy.zip)

## Introduction

_TurboPy_ is a free (as in “free speech” and also as in “free beer”) **I**ntegrated **D**evelopment **E**nvironment for Python, built to simplify coding, testing, and managing Python projects in one place. Running in the Microsoft Windows environment, its use is governed by [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.html). _TurboPy_ is written in C++ and uses pure Win32 API and STL which ensures a higher execution speed and smaller program size. By optimizing as many routines as possible without losing user friendliness, _TurboPy_ is trying to reduce the world carbon dioxide emissions. When using less CPU power, the PC can throttle down and reduce power consumption, resulting in a greener environment. I hope you enjoy _TurboPy_ as much as I enjoy coding it!

## Getting started

### Install TurboPy using the installer

- Download the installer
- Run the executable binary and follow the installation flow

The installer will likely require Administrative privileges in order to install _TurboPy_ (and later, to update _TurboPy_ or install or update plugins, or anything else that requires writing to the installation directory). If you do not have Administrative privileges, you either need to tell the installer to use a location where you do have write permission (though that may still ask for Administrator privileges), or you may choose not use the installer and instead run a portable edition from a directory where you have write permission.

### Install TurboPy from zip

These instructions will allow you to run a portable or mini-portable (also called “minimalist”), without requiring administrative privileges.

- Create a new folder somewhere that you have write-permission
- Unzip the content into the new folder
- Run _TurboPy_ from the new folder

The portable zip edition of _TurboPy_ can be removed by deleting the directory they came in. If you manually set up file associations or context-menu entries in the OS, it is your responsibility to remove them yourself.

## Roadmap

This roadmap outlines where _TurboPy_ is heading. Today it is a fast, tabbed Python code editor with syntax highlighting, and the roadmap builds toward the IDE described in the introduction, where you code, run, debug, test and manage Python projects in one place. It brings together the next steps for the features that are already there, ideas for new ones, and the maintenance work that goes into every release. Items are grouped by horizon rather than by date, and their order may change as feedback arrives or as the libraries _TurboPy_ builds on evolve, so please treat it as a statement of intent, not a promise. For everything that has already shipped, see the [Release Notes](https://github.com/mihaimoga/TurboPy/releases).

_Last reviewed: November 2026 (version 0.02 in development)._

### Now (in progress and ongoing)

- **Version 0.02**: an _Open with TurboPy_ command in the Windows Explorer context menu of `.py` files, shown with the _TurboPy_ icon, and the latest version of PJ Naughter's `CScintillaCtrl` library.
- **Up-to-date components**: releases keep picking up the latest Scintilla and Lexilla (the editing component and its syntax highlighters), PJ Naughter's helper classes and genUp4win (the update library).
- **Stability, security and performance**: bug fixes, security updates and performance tuning continue alongside new features. Version 0.01 is a pre-release, so bug reports from a wide range of Windows setups are especially welcome.

### Next (planned, next in line)

- **Run a script**: a ribbon button and a keyboard shortcut to run the current Python file, plus a command to stop it. _TurboPy_ edits and saves Python files today, but it cannot run them yet.
- **Output pane**: show what a script prints, both standard output and errors, in a dockable pane, with tracebacks that can be clicked to jump to the line that failed.
- **Python interpreter selection**: choose which installed Python or virtual environment runs your scripts, and show the selected one in the status bar.
- **Python-friendly editing**: indent with four spaces as PEP 8 recommends (pressing Tab inserts a tab character today), indent automatically after a colon, show indentation guides, match braces, comment and uncomment the selected lines, and refresh the keyword list for current Python releases, including soft keywords such as `match`, `case` and `type`.
- **Status bar and Go To Line**: show the line and column of the caret, the encoding and the line endings in the status bar, which has no indicators today, and jump to a line by its number.
- **UTF-8 without BOM**: recognize UTF-8 files that have no byte order mark, which is the default for Python 3 source files. Today such files are read as single-byte text, so their non-ASCII characters are not displayed correctly.
- **Check for updates**: a _Check for Updates_ command that finds and installs new versions through genUp4win, which already ships with the installer but is not called by _TurboPy_ yet.

Running a script needs an interpreter to run it with and a pane to show its output, so the first three items are likely to be tackled together.

### Later (planned, larger efforts)

- **Workspace, File View and Find in Files**: open a folder as a project, browse its files in a dockable pane, and search for text across all of them; Find and Replace only works on the current file today.
- **Code folding and symbol outline**: collapse classes, functions and blocks, and browse the classes, functions and methods of the current file as a tree in a dockable Class View pane.
- **Debugger**: set breakpoints by clicking in the margin, step through the code and inspect variables. The editor already defines breakpoint and execution-pointer markers in its margin, but nothing uses them yet.
- **Code completion and call tips**: suggestions for keywords and for the names defined in your code as you type, and parameter hints for function calls.
- **Testing**: discover and run `unittest` and `pytest` tests, and review the results in a pane that jumps to the failures.
- **Packages and virtual environments**: create virtual environments, install packages with `pip`, and work with `requirements.txt` files without leaving _TurboPy_.
- **Options dialog**: one place to change what is fixed today, such as the font, the tab width, the indentation style and word wrap, which is always on.

### Under consideration (ideas, not yet committed)

- **Language Server Protocol support**: connect to a Python language server such as Pyright or python-lsp-server for smarter completion, go to definition, hover information and diagnostics.
- **Linting and formatting**: run a linter such as Ruff and a formatter such as Black from inside _TurboPy_, and show the problems in the editor.
- **Interactive console**: a Python console (REPL) in a dockable pane, to try out code without creating a file first.
- **Bundled Python runtime**: an optional Python distribution shipped with _TurboPy_, so that scripts can be run on a PC where Python is not installed.
- **Themes and dark mode**: selectable color schemes for the editor, including a dark one; the syntax colors are fixed today.
- **Localized user interface**: translated ribbon, commands and messages (the user interface is English only today).
- **Native ARM64 and high-DPI support**: a native ARM64 build for Windows on Arm devices (_TurboPy_ is currently built for x86 and x64) and Per-Monitor V2 DPI awareness for a sharper interface on high-DPI and mixed-DPI displays.
- **Automated builds**: a GitHub Actions workflow that builds the solution and checks every pull request, since there is no continuous integration yet.

### Help shape the roadmap

Want to see something sooner, or have an idea that is not listed here? [Open an issue](https://github.com/mihaimoga/TurboPy/issues) or start a conversation in [Discussions](https://github.com/mihaimoga/TurboPy/discussions). Contributions are welcome as well: any item above can be picked up through a pull request, as described in the next section. For enhancements, the issue must be approved by a project administrator (it will carry the `Accepted` label) before the pull request can be merged, so it is best to open the issue before you start coding.

## Create and Submit your Pull Request

As noted in the [Contributing Rules](https://github.com/mihaimoga/TurboPy/blob/main/CONTRIBUTING.md) for _TurboPy_, all Pull Requests need to be attached to a issue on GitHub. So the first step is to create an issue which requests that the functionality be improved (if it was already there) or added (if it was not yet there); in your issue, be sure to explain that you have the functionality definition ready, and will be submitting a Pull Request. The second step is to use the GitHub interface to create the Pull Request from your fork into the main repository. The final step is to wait for and respond to feedback from the developers as needed, until such time as your PR is accepted or rejected.

## Acknowledges

This open source project uses the following libraries:

- [The Python programming language](https://github.com/python/cpython)
- Stefan-Mihai MOGA's [genUp4win](https://github.com/mihaimoga/genUp4win)
- PJ Naughter's [CHLinkCtrl](https://www.naughter.com/hlinkctrl.html)
- [Lexilla, Scintilla, and SciTE](https://www.scintilla.org/)
- PJ Naughter's [CScintillaCtrl, CScintillaDoc, CScintillaView](https://www.naughter.com/scintilla.html)
- PJ Naughter's [CVersionInfo](https://www.naughter.com/versioninfo.html)
