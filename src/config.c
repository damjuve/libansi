#include "libansi.h"
#include "__libansi__.h"

void libansi_set_matrix_buffer(bool matrix_buffer) {
        _libansi_.config.matrix_buff = matrix_buffer;
}

void libansi_set_auto_flush(bool auto_flush) {
        _libansi_.config.auto_flush = auto_flush;
}

void libansi_set_buff_len(size_t len) {
        if (len == 0)
                return ;
        _libansi_.config.buff_len = len;
}

void libansi_set_printf_len(size_t len) {
        if (len == 0)
                return ;
        _libansi_.config.printf_len = len;
}
