#ifndef         __LIBANSI_H_
#define         __LIBANSI_H_

/* *************** Includes *************** */
#include <stdlib.h>
#include <stdbool.h>

/* *************** Defines *************** */
#define LIBANSI_CHAR_EMPTY      (-1)

/* *************** Enums *************** */
enum libansi_color {
        LIBANSI_C_BLACK = 0,
        LIBANSI_C_BLUE,
        LIBANSI_C_GREEN,
        LIBANSI_C_CYAN,
        LIBANSI_C_RED,
        LIBANSI_C_PURPLE,
        LIBANSI_C_BROWN,
        LIBANSI_C_LGRAY,
        LIBANSI_C_DGRAY,
        LIBANSI_C_LBLUE,
        LIBANSI_C_LGREEN,
        LIBANSI_C_LCYAN,
        LIBANSI_C_LRED,
        LIBANSI_C_LPURPLE,
        LIBANSI_C_YELLOW,
        LIBANSI_C_WHITE,
        LIBANSI_C_BG_BLACK,
        LIBANSI_C_BG_BLUE,
        LIBANSI_C_BG_GREEN,
        LIBANSI_C_BG_CYAN,
        LIBANSI_C_BG_RED,
        LIBANSI_C_BG_PURPLE,
        LIBANSI_C_BG_BROWN,
        LIBANSI_C_BG_LGRAY,
        LIBANSI_C_BG_DGRAY,
        LIBANSI_C_BG_LBLUE,
        LIBANSI_C_BG_LGREEN,
        LIBANSI_C_BG_LCYAN,
        LIBANSI_C_BG_LRED,
        LIBANSI_C_BG_LPURPLE,
        LIBANSI_C_BG_YELLOW,
        LIBANSI_C_BG_WHITE,
        LIBANSI_NB_COLORS
};

/* *************** Structs *************** */
struct libansi_matrix_elem {
        char value;
        enum libansi_color font_color;
        enum libansi_color background_color;
};

struct libansi_matrix {
        struct libansi_matrix_elem **matrix;
        size_t len_col;
        size_t len_line;
        char *buff;
        size_t buff_len;
};

/* *************** Prototypes *************** */

/* config.c */
void libansi_set_matrix_buffer(bool matrix_buffer);
void libansi_set_auto_flush(bool auto_flush);
void libansi_set_buff_len(size_t len);
void libansi_set_printf_len(size_t len);

/* print.c */
void libansi_print_len(char const *str, size_t len);
void libansi_print(char const *str);
void libansi_print_char(char c);
void libansi_printf(char const *format, ...);
void libansi_print_2d_array(char const* const* array, size_t len_col, size_t len_line, char empty);
void libansi_flush();

/* cursor.c */
void libansi_move_pos(unsigned int col, unsigned int line);
void libansi_move_up(unsigned int move);
void libansi_move_down(unsigned int move);
void libansi_move_backward(unsigned int move);
void libansi_move_forward(unsigned int move);
void libansi_move_start_of_line();

/* clear.c */
void libansi_free_buffer();
void libansi_clear_end_of_line();
void libansi_clear_screen();

/* matrix.c */
void libansi_matrix_update_buffer(struct libansi_matrix *matrix);
void libansi_print_matrix(struct libansi_matrix *matrix);
struct libansi_matrix *libansi_create_matrix(size_t len_col, size_t len_line, char **values, char empty,
                                             enum libansi_color **font_colors, enum libansi_color **background_colors);

/* color.c */
void libansi_set_color(enum libansi_color col);

#endif
