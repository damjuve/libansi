#include "libansi.h"
#include "__libansi__.h"

void libansi_clear_end_of_line() {
        libansi_print_len(__LIBANSI_ESC_CLEAR_LINE__, 3);
}

void libansi_clear_screen() {
        libansi_print_len(__LIBANSI_ESC_CLEAR_SCREEN__, 3);
}

void libansi_free_buffer() {
        if (_libansi_.print_buffer.buff == NULL)
                return ;
        free(_libansi_.print_buffer.buff);
        _libansi_.print_buffer.buff = NULL;
        _libansi_.print_buffer.len = 0;
}
