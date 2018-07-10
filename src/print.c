#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#include "libansi.h"
#include "__libansi__.h"

/* ************ Private static functions ************ */

static void __libansi_write__(char const *str, size_t len) {
        write(1, str, len);
}

static bool __libansi_alloc_buffer__(struct __libansi_buffer__ *buff) {
        buff->buff = realloc(buff->buff, sizeof(*buff->buff) * (buff->len + _libansi_.config.buff_len));
        if (buff->buff == NULL) {
                buff->idx = 0;
                buff->len = 0;
                return false;
        }
        buff->len += _libansi_.config.buff_len;
        return true;
}

static void __libansi_write_buffer__(char const *str, size_t len) {
        size_t i;
        struct __libansi_buffer__ *buff;

        if (_libansi_.dest_buffer != NULL)
                buff = _libansi_.dest_buffer;
        else
                buff = &_libansi_.print_buffer;

        for (i = 0; i < len; i++) {
                if (buff->idx == buff->len) {
                        if (!__libansi_alloc_buffer__(buff))
                                return ;
                }

                buff->buff[buff->idx] = str[i];
                buff->idx++;
        }
}

/* ************ Public print functions ************ */

void libansi_print_len(char const *str, size_t len) {
        if (_libansi_.config.auto_flush && _libansi_.dest_buffer == NULL)
                __libansi_write__(str, len);
        else
                __libansi_write_buffer__(str, len);
}

void libansi_print(char const *str) {
        libansi_print_len(str, strlen(str));
}

void libansi_print_char(char c) {
        libansi_print_len(&c, 1);
}

void libansi_printf(char const *format, ...) {
        va_list ap;
        char str[_libansi_.config.printf_len];

        va_start(ap, format);
        size_t len = vsnprintf(str, _libansi_.config.printf_len, format, ap);
        va_end(ap);
        libansi_print_len(str, len);
}

void libansi_flush() {
        if (_libansi_.print_buffer.idx == 0)
                return ;

        __libansi_write__(_libansi_.print_buffer.buff, _libansi_.print_buffer.idx);
        _libansi_.print_buffer.idx = 0;
        if (_libansi_.config.auto_free)
                libansi_free_buffer();
}

void libansi_print_2d_array(char const * const * array, size_t len_col, size_t len_line, char empty) {
        if (len_col == 0 || len_line == 0 || array == NULL)
                return ;
        size_t y, x;

        for (y = 0; y < len_line; y++) {
                if (empty < 0) {
                        libansi_print_len(array[y], len_col);
                }
                else {
                        for (x = 0; x < len_col; x++) {
                                if (array[y][x] != empty)
                                        libansi_print_char(array[y][x]);
                                else
                                        libansi_move_forward(1);
                        }
                }
                libansi_move_backward(len_col);
                libansi_move_down(1);
        }
}
