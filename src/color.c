#include <string.h>
#include <stdio.h>

#include "libansi.h"
#include "__libansi__.h"

static const struct __libansi_color__ _libansi_colors[LIBANSI_NB_COLORS] = {
        {LIBANSI_C_BLACK, "0;30"},
        {LIBANSI_C_BLUE, "0;34"},
        {LIBANSI_C_GREEN, "0;32"},
        {LIBANSI_C_CYAN, "0;36"},
        {LIBANSI_C_RED, "0;31"},
        {LIBANSI_C_PURPLE, "0;35"},
        {LIBANSI_C_BROWN, "0;33"},
        {LIBANSI_C_LGRAY, "0;37"},
        {LIBANSI_C_DGRAY, "1;30"},
        {LIBANSI_C_LBLUE, "1;34"},
        {LIBANSI_C_LGREEN, "1;32"},
        {LIBANSI_C_LCYAN, "1;36"},
        {LIBANSI_C_LRED, "1;31"},
        {LIBANSI_C_LPURPLE, "1;35"},
        {LIBANSI_C_YELLOW, "1;33"},
        {LIBANSI_C_WHITE, "1;37"},
        {LIBANSI_C_BG_BLACK, "0;40"},
        {LIBANSI_C_BG_BLUE, "0;44"},
        {LIBANSI_C_BG_GREEN, "0;42"},
        {LIBANSI_C_BG_CYAN, "0;46"},
        {LIBANSI_C_BG_RED, "0;41"},
        {LIBANSI_C_BG_PURPLE, "0;45"},
        {LIBANSI_C_BG_BROWN, "0;43"},
        {LIBANSI_C_BG_LGRAY, "0;47"},
        {LIBANSI_C_BG_DGRAY, "1;40"},
        {LIBANSI_C_BG_LBLUE, "1;44"},
        {LIBANSI_C_BG_LGREEN, "1;42"},
        {LIBANSI_C_BG_LCYAN, "1;46"},
        {LIBANSI_C_BG_LRED, "1;41"},
        {LIBANSI_C_BG_LPURPLE, "1;45"},
        {LIBANSI_C_BG_YELLOW, "1;43"},
        {LIBANSI_C_BG_WHITE, "1;47"},

};

void libansi_set_color(enum libansi_color col) {
        char cmd[8];

        size_t len = snprintf(cmd, 8, __LIBANSI_ESC_COLOR__, _libansi_colors[col].cmd);
        libansi_print_len(cmd, len);
}