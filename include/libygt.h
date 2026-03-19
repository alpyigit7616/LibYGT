/*
 * 2026 (c) Copyright - LibYGT Developers
 * Log system made in C
 * Licenced under the MIT license.
 * For details, look at the LICENSE file.
*/

// Of course, the #... stuff
#ifndef LIBYGT_H
#define LIBYGT_H

// Here, all functions...

/*
 ******************************
 LOG FUNCTIONS
 ******************************
*/
void ly_log_message(const char* message); // Normal message
void ly_log_warn(const char* message); // Warning message
void ly_log_error(const char* message); // Error message

/*
 ******************************
 COOL TEXT FUNCTIONS
 ******************************
*/
void ly_cool_text_bold(const char* message); // Bold text
void ly_cool_text_underlined(const char* message); // Underlined text

/*
 ******************************
 MSGBOX FUNCTIONS
 ******************************
*/
void ly_msgbox_normal(const char *message); // Normal message
void ly_msgbox_warn(const char *message); // Warning message
void ly_msgbox_error(const char *message); // Error message

typedef enum {
    LY_INFO,
    LY_WARN,
    LY_ERROR
} ly_log_level;

#endif // End of the code
