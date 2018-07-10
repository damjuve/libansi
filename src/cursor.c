#include <stdio.h>

#include "libansi.h"
#include "__libansi__.h"

void libansi_move_pos(unsigned int col, unsigned int line) {
        if (line == 0 || line > 99999 ||
            col == 0 || col > 99999)
                return ;
        char cmd[15];
        size_t len = snprintf(cmd, 14, __LIBANSI_ESC_MOVE_POS__, line, col);
        libansi_print_len(cmd, len);
}

void libansi_move_up(unsigned int move) {
        if (move == 0 || move > 99999)
                return ;
        char cmd[9];
        size_t len = snprintf(cmd, 8, __LIBANSI_ESC_MOVE_UP__, move);
        libansi_print_len(cmd, len);
}

void libansi_move_down(unsigned int move) {
        if (move == 0 || move > 99999)
                return ;
        char cmd[9];
        size_t len = snprintf(cmd, 8, __LIBANSI_ESC_MOVE_DOWN__, move);
        libansi_print_len(cmd, len);
}

void libansi_move_backward(unsigned int move) {
        if (move == 0 || move > 99999)
                return ;
        char cmd[9];
        size_t len = snprintf(cmd, 8, __LIBANSI_ESC_MOVE_BACKWARD__, move);
        libansi_print_len(cmd, len);
}

void libansi_move_forward(unsigned int move) {
        if (move == 0 || move > 99999)
                return ;
        char cmd[9];
        size_t len = snprintf(cmd, 8, __LIBANSI_ESC_MOVE_FORWARD__, move);
        libansi_print_len(cmd, len);
}

void libansi_move_start_of_line() {
        libansi_print_len(__LIBANSI_ESC_MOVE_START__, 1);
}
