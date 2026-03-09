/*
 * 2026 (c) Copyright - LibYGT Developers
 * Log system made in C
 * Licenced under the MIT license.
 * For details, look at the LICENSE file.
*/

/*
 ******************************** WARNING!!! ********************************
 * THIS PROJECT USES THE OPEN SOURCE GITHUB REPOSITORY NAMED "Tinyfiledialogs"
 * THANKS FOR MAKING THIS PROJECT OPEN-SOURCE, TINYFILEDIALOGS DEVELOPERS!
 * Tinyfiledialogs: https://github.com/native-toolkit/libtinyfiledialogs/tree/master
 * Details are in the docs/CREDITS.md file.
*/

// Including the files
#include "libygt.h"
#include "tinyfiledialogs.h" // including tinyfiledialogs

/***************** NORMAL MSGBOX *****************/
void ly_msgbox_normal(const char *message) {
   tinyfd_messageBox("INFO", message, "ok", "info", 1);
}

/***************** WARNING MSGBOX *****************/
void ly_msgbox_warn(const char *message) {
    tinyfd_messageBox("WARNING", message, "ok", "warning", 1);
}

/***************** ERROR MSGBOX *****************/
void ly_msgbox_error(const char *message) {
    tinyfd_messageBox("ERROR!", message, "ok", "error", 1);
}
