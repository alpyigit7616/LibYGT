/*
 * 2026 (c) Copyright - LibYGT Developers
 * Log system made in C
 * Licenced under the MIT license.
 * For details, look at the LICENSE file.
*/

// INCLUDING THE HEADER FILE AND STDIO.H AND OTHERS
#include <stdio.h> // stdio.h
#include "libygt.h" // libygt.h
#include <time.h> // time.h for the time
#include "colors.h"

// NORMAL LOG MESSAGE
void ly_log_message(const char *message){
    time_t now = time(NULL); // Now thing
    char timestamp[20]; // timestamp thing

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now)); // strftime
    printf(LY_CYAN "[%s]" LY_RESET " " LY_GREEN "[INFO] " LY_RESET "%s\n", timestamp, message); // Finally, prints the message with printf from the stdio.h
}

// WARNING LOG MESSAGE
void ly_log_warn(const char *message){
    time_t now = time(NULL); // Now thing
    char timestamp[20]; // timestamp thing

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now)); // strftime
    printf(LY_CYAN "[%s]" LY_RESET " " LY_YELLOW"[WARNING] " LY_RESET "%s\n", timestamp, message); // Finally, prints the message with printf from the stdio.h
}

// ERROR LOG MESSAGE
void ly_log_error(const char *message){
    time_t now = time(NULL); // Now thing
    char timestamp[20]; // timestamp thing

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now)); // strftime
    printf(LY_CYAN "[%s]" LY_RESET " " LY_RED "[ERROR!] " LY_RESET "%s\n", timestamp, message); // Finally, prints the message with printf from the stdio.h
}
