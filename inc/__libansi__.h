#ifndef ____LIBANSI____H_
#define ____LIBANSI____H_

/* *************** Includes *************** */
#include <stdlib.h>
#include "libansi.h"

/* *************** Defines *************** */
#define LIBANSI_DEFAULT_BUFF_LEN        (1024)
#define LIBANSI_DEFAULT_PRINTF_LEN      (1024)

#define __LIBANSI_ESC_MOVE_POS__        ("\033[%d;%dH")
#define __LIBANSI_ESC_MOVE_UP__         ("\033[%dA")
#define __LIBANSI_ESC_MOVE_DOWN__       ("\033[%dB")
#define __LIBANSI_ESC_MOVE_BACKWARD__   ("\033[%dD")
#define __LIBANSI_ESC_MOVE_FORWARD__    ("\033[%dC")
#define __LIBANSI_ESC_MOVE_START__      ("\r")
#define __LIBANSI_ESC_CLEAR_LINE__      ("\033[K")
#define __LIBANSI_ESC_CLEAR_SCREEN__    ("\033[2J")
#define __LIBANSI_ESC_COLOR__           ("\033[%sm")

/* *************** Structs *************** */
struct __libansi_buffer__ {
        char *buff;
        size_t len;
        size_t idx;
};

struct __libansi_config__ {
        bool auto_flush;
        bool auto_free;
        bool matrix_buff;
        size_t buff_len;
        size_t printf_len;
        struct __libansi_buffer__ *dest_buff;
};

struct __libansi__ {
        struct __libansi_config__ config;
        struct __libansi_buffer__ print_buffer;
        struct __libansi_buffer__ *dest_buffer;
};

struct __libansi_color__ {
        enum libansi_color idx;
        char const *cmd;
};

/* *************** Externs *************** */
extern struct __libansi__ _libansi_;
extern const struct __libansi_color__ _libansi_colors_[LIBANSI_NB_COLORS];

#endif
