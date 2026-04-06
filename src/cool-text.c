/*
 * 2026 (c) Copyright - LibYGT Developers
 * Log system made in C
 * Licenced under the MIT license.
 * For details, look at the LICENSE file.
*/

/* Incuding the files */
#include <stdio.h> // Stdio
#include "styles.h" // The file that contains the styles.
#include "colors.h" // The file that contains the colors.
#include "libygt.h" // LibYGT main header file

/* Bold Text */
void ly_cool_text_bold(const char* message) {
    printf(LY_BOLD "%s" LY_RESET "\n", message);
}

/* Underline Text */
void ly_cool_text_underline(const char* message) {
    printf(LY_UNDERLINE "%s" LY_RESET "\n", message);
}

/* Bold + Underline */
void ly_cool_text_bold_underline(const char* message) {
    printf(LY_BOLD LY_UNDERLINE "%s" LY_RESET "\n", message);
}

/* Bold + Colored */
void ly_cool_text_bold_red(const char* message) {
    printf(LY_BOLD LY_RED "%s" LY_RESET "\n", message);
}

void ly_cool_text_bold_green(const char* message) {
    printf(LY_BOLD LY_GREEN "%s" LY_RESET "\n", message);
}

void ly_cool_text_bold_yellow(const char* message) {
    printf(LY_BOLD LY_YELLOW "%s" LY_RESET "\n", message);
}

/* Underline + Colored */
void ly_cool_text_underline_cyan(const char* message) {
    printf(LY_UNDERLINE LY_CYAN "%s" LY_RESET "\n", message);
}
