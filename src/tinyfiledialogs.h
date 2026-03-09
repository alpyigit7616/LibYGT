/*
 * 2026 (c) Copyright - MyLib Developers
 * Log system made in C
 * POWERED BY TINYFILEDIALOGS
 * Licenced under the MIT license.
 * For details, look at the LICENSE file.
*/

#ifndef TINYFILEDIALOGS_H
#define TINYFILEDIALOGS_H

/* #define TINYFD_NOLIB */
/* On windows, define TINYFD_NOLIB here
if you don't want to include the code creating the graphic dialogs.
Then you won't need to link against Comdlg32.lib and Ole32.lib */

/* if tinydialogs.c is compiled with a C++ compiler rather than with a C compiler
(ie. you change the extension from .c to .cpp), you need to comment out:
extern "C" {
and the corresponding closing bracket near the end of this file:
}
*/
#ifdef	__cplusplus
extern "C" {
#endif

extern char tinyfd_version[8]; /* contains tinyfd current version number */

#ifdef _WIN32
/* for UTF-16 use the functions at the end of this files */
extern int tinyfd_winUtf8; /* 0 (default) or 1 */
/* on windows string char can be 0:MBSC or 1:UTF-8
unless your code is really prepared for UTF-8 on windows, leave this on MBSC.
Or you can use the UTF-16 (wchar) prototypes at the end of ths file.*/
#endif

extern int tinyfd_forceConsole ;  /* 0 (default) or 1 */
/* for unix & windows: 0 (graphic mode) or 1 (console mode).
0: try to use a graphic solution, if it fails then it uses console mode.
1: forces all dialogs into console mode even when an X server is present,
  if the package dialog (and a console is present) or dialog.exe is installed.
  on windows it only make sense for console applications */

extern char tinyfd_response[1024];
/* if you pass "tinyfd_query" as aTitle,
the functions will not display the dialogs
but will return 0 for console mode, 1 for graphic mode.
tinyfd_response is then filled with the retain solution.
possible values for tinyfd_response are (all lowercase)
for the graphic mode:
  windows applescript zenity zenity3 matedialog qarma kdialog
  xdialog tkinter gdialog gxmessage xmessage
for the console mode:
  dialog whiptail basicinput */

int tinyfd_messageBox (
	char const * const aTitle , /* "" */
	char const * const aMessage , /* "" may contain \n \t */
	char const * const aDialogType , /* "ok" "okcancel" "yesno" "yesnocancel" */
	char const * const aIconType , /* "info" "warning" "error" "question" */
	int const aDefaultButton ) ;
		/* 0 for cancel/no , 1 for ok/yes , 2 for no in yesnocancel */

char const * tinyfd_inputBox (
	char const * const aTitle , /* "" */
	char const * const aMessage , /* "" may NOT contain \n \t on windows */
	char const * const aDefaultInput ) ;  /* "" , if NULL it's a passwordBox */
		/* returns NULL on cancel */

char const * tinyfd_saveFileDialog (
	char const * const aTitle , /* "" */
	char const * const aDefaultPathAndFile , /* "" */
	int const aNumOfFilterPatterns , /* 0 */
	char const * const * const aFilterPatterns , /* NULL | {"*.jpg","*.png"} */
	char const * const aSingleFilterDescription ) ; /* NULL | "text files" */
		/* returns NULL on cancel */

char const * tinyfd_openFileDialog (
	char const * const aTitle , /* "" */
	char const * const aDefaultPathAndFile , /* "" */
	int const aNumOfFilterPatterns , /* 0 */
	char const * const * const aFilterPatterns , /* NULL {"*.jpg","*.png"} */
	char const * const aSingleFilterDescription , /* NULL | "image files" */
	int const aAllowMultipleSelects ) ; /* 0 or 1 */
		/* in case of multiple files, the separator is | */
		/* returns NULL on cancel */

char const * tinyfd_selectFolderDialog (
	char const * const aTitle , /* "" */
	char const * const aDefaultPath ) ; /* "" */
		/* returns NULL on cancel */

char const * tinyfd_colorChooser(
	char const * const aTitle , /* "" */
	char const * const aDefaultHexRGB , /* NULL or "#FF0000" */
	unsigned char const aDefaultRGB[3] , /* { 0 , 255 , 255 } */
	unsigned char aoResultRGB[3] ) ; /* { 0 , 0 , 0 } */
		/* returns the hexcolor as a string "#FF0000" */
		/* aoResultRGB also contains the result */
		/* aDefaultRGB is used only if aDefaultHexRGB is NULL */
		/* aDefaultRGB and aoResultRGB can be the same array */
		/* returns NULL on cancel */


/************ NOT CROSS PLATFORM SECTION STARTS HERE ************************/
#ifdef _WIN32
#ifndef TINYFD_NOLIB

/* windows only - utf-16 version */
int tinyfd_messageBoxW(
	wchar_t const * const aTitle ,
	wchar_t const * const aMessage, /* "" may contain \n \t */
	wchar_t const * const aDialogType, /* "ok" "okcancel" "yesno" */
	wchar_t const * const aIconType, /* "info" "warning" "error" "question" */
	int const aDefaultButton ); /* 0 for cancel/no , 1 for ok/yes */
		/* returns 0 for cancel/no , 1 for ok/yes */

/* windows only - utf-16 version */
wchar_t const * tinyfd_saveFileDialogW(
	wchar_t const * const aTitle, /* NULL or "" */
	wchar_t const * const aDefaultPathAndFile, /* NULL or "" */
	int const aNumOfFilterPatterns, /* 0 */
	wchar_t const * const * const aFilterPatterns, /* NULL or {"*.jpg","*.png"} */
	wchar_t const * const aSingleFilterDescription); /* NULL or "image files" */
		/* returns NULL on cancel */

/* windows only - utf-16 version */
wchar_t const * tinyfd_openFileDialogW(
	wchar_t const * const aTitle, /* "" */
	wchar_t const * const aDefaultPathAndFile, /* "" */
	int const aNumOfFilterPatterns , /* 0 */
	wchar_t const * const * const aFilterPatterns, /* NULL {"*.jpg","*.png"} */
	wchar_t const * const aSingleFilterDescription, /* NULL | "image files" */
	int const aAllowMultipleSelects ) ; /* 0 or 1 */
		/* in case of multiple files, the separator is | */
		/* returns NULL on cancel */

/* windows only - utf-16 version */
	wchar_t const * tinyfd_selectFolderDialogW(
	wchar_t const * const aTitle, /* "" */
	wchar_t const * const aDefaultPath); /* "" */
		/* returns NULL on cancel */

/* windows only - utf-16 version */
wchar_t const * tinyfd_colorChooserW(
	wchar_t const * const aTitle, /* "" */
	wchar_t const * const aDefaultHexRGB, /* NULL or "#FF0000" */
	unsigned char const aDefaultRGB[3] , /* { 0 , 255 , 255 } */
	unsigned char aoResultRGB[3] ) ; /* { 0 , 0 , 0 } */
		/* returns the hexcolor as a string "#FF0000" */
		/* aoResultRGB also contains the result */
		/* aDefaultRGB is used only if aDefaultHexRGB is NULL */
		/* aDefaultRGB and aoResultRGB can be the same array */
		/* returns NULL on cancel */


#endif /*TINYFD_NOLIB*/
#else /*_WIN32*/

/* unix zenity only */
char const * tinyfd_arrayDialog(
	char const * const aTitle , /* "" */
	int const aNumOfColumns , /* 2 */
	char const * const * const aColumns, /* {"Column 1","Column 2"} */
	int const aNumOfRows, /* 2*/
	char const * const * const aCells);
		/* {"Row1 Col1","Row1 Col2","Row2 Col1","Row2 Col2"} */

#endif /*_WIN32 */

#ifdef	__cplusplus
}
#endif

#endif /* TINYFILEDIALOGS_H */

/*
- This is not for android nor ios.
- The code is pure C, perfectly compatible with C++.
- the windows only wchar_t (utf-16) prototypes are in the header file
- windows is fully supported from XP to 10 (maybe even older versions)
- C# & LUA via dll, see example files
- OSX supported from 10.4 to 10.11 (maybe even older versions)
- Avoid using " and ' in titles and messages.
- There's one file filter only, it may contain several patterns.
- If no filter description is provided,
  the list of patterns will become the description.
- char const * filterPatterns[3] = { "*.obj" , "*.stl" , "*.dxf" } ;
- On windows link against Comdlg32.lib and Ole32.lib
  This linking is not compulsary for console mode (see above).
- On unix: it tries command line calls, so no such need.
- On unix you need applescript, zenity, matedialog, qarma, kdialog, Xdialog,
  python2/tkinter or dialog (will open a terminal if running without console).
- One of those is already included on most (if not all) desktops.
- In the absence of those it will use gdialog, gxmessage or whiptail
  with a textinputbox.
- If nothing is found, it switches to basic console input,
  it opens a console if needed (requires xterm + bash).
- Use windows separators on windows and unix separators on unix.
- String memory is preallocated statically for all the returned values.
- File and path names are tested before return, they are valid.
- If you pass only a path instead of path + filename,
  make sure it ends with a separator.
- tinyfd_forceConsole=1; at run time, forces dialogs into console mode.
- On windows, console mode only make sense for console applications.
- Mutiple selects are not allowed in console mode.
- The package dialog must be installed to run in enhanced console mode.
  It is already installed on most unix systems.
- On osx, the package dialog can be installed via http://macports.org
- On windows, for enhanced console mode,
  dialog.exe should be copied somewhere on your executable path.
  It can be found at the bottom of the following page:
  http://andrear.altervista.org/home/cdialog.php
- If dialog is missing, it will switch to basic console input.
- You can query the type of dialog that will be use.
- MinGW needs gcc >= v4.9 otherwise some headers are incomplete.
- The Hello World (and a bit more) is on the sourceforge site:
*/