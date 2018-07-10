#include "libansi.h"
#include "__libansi__.h"

struct __libansi__ _libansi_ = {
        .config = {
                .auto_flush = true,
                .auto_free = true,
                .matrix_buff = false,
                .buff_len = LIBANSI_DEFAULT_BUFF_LEN,
                .printf_len = LIBANSI_DEFAULT_PRINTF_LEN,
        },
        .print_buffer = {
                .buff = NULL,
                .len = 0,
                .idx = 0
        },
        .dest_buffer = NULL
};