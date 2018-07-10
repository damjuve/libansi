#include <string.h>

#include "libansi.h"
#include "__libansi__.h"

void libansi_matrix_update_buffer(struct libansi_matrix *matrix) {
        if (matrix == NULL)
                return ;

        if (matrix->buff != NULL) {
                free(matrix->buff);
                matrix->buff = NULL;
                matrix->buff_len = 0;
        }

        struct __libansi_buffer__ buff;
        buff.buff = NULL;
        buff.len = 0;
        buff.idx = 0;
        _libansi_.config.dest_buff = &buff;

        size_t x;
        size_t y;
        size_t movef;
        size_t moved;
        enum libansi_color curr_f_color = LIBANSI_NB_COLORS;
        enum libansi_color curr_bg_color = LIBANSI_NB_COLORS;
        moved = 0;
        for (y = 0; y < matrix->len_line; y++) {
                movef = 0;
                for (x = 0; x < matrix->len_col; x++) {
                        if (matrix->matrix[y][x].value == LIBANSI_CHAR_EMPTY)
                                movef++;
                        else {
                                if (movef > 0) {
                                        libansi_move_forward(movef);
                                        movef = 0;
                                }
                                if (curr_f_color != matrix->matrix[y][x].font_color) {
                                        curr_f_color = matrix->matrix[y][x].font_color;
                                        libansi_set_color(curr_f_color);
                                }
                                if (curr_bg_color != matrix->matrix[y][x].background_color) {
                                        curr_bg_color = matrix->matrix[y][x].background_color;
                                        libansi_set_color(curr_bg_color);
                                }
                                libansi_print_char(matrix->matrix[y][x].value);
                        }
                }
                if (movef == matrix->len_col - 1)
                        moved++;
                else {
                        libansi_move_down(moved + 1);
                        moved = 0;
                        libansi_move_backward(matrix->len_col - movef);
                }
        }

        _libansi_.config.dest_buff = NULL;
        matrix->buff_len = buff.idx;
        matrix->buff = malloc(sizeof(*matrix->buff) * (matrix->buff_len + 1));
        memcpy(matrix->buff, buff.buff, matrix->buff_len);
        matrix->buff[matrix->buff_len] = '\0';
        free(buff.buff);
}

void libansi_print_matrix(struct libansi_matrix *matrix) {
        if (_libansi_.config.matrix_buff == false || matrix->buff == NULL) {
                libansi_matrix_update_buffer(matrix);
        }
        libansi_print_len(matrix->buff, matrix->buff_len);
}

struct libansi_matrix *libansi_create_matrix(size_t len_col, size_t len_line, char **values, char empty,
                                              enum libansi_color **font_colors, enum libansi_color **background_colors) {
        if (len_col == 0 || len_line == 0 || values == NULL || font_colors == NULL || background_colors == NULL)
                return NULL;

        struct libansi_matrix *container;
        container = malloc(sizeof(*container));
        if (container == NULL)
                return NULL;

        struct libansi_matrix_elem **matrix;
        matrix = malloc(sizeof(*matrix) * len_line);
        if (matrix == NULL)
                return NULL;

        size_t x;
        size_t y;
        for (y = 0; y < len_line; y++) {
                matrix[y] = malloc(sizeof(*matrix[y]) * len_col);
                if (matrix[y] == NULL)
                        return NULL;
                for (x = 0; x < len_col; x++) {
                        if (values[y][x] == empty) {
                                matrix[y][x].value = LIBANSI_CHAR_EMPTY;
                        }
                        else {
                                matrix[y][x].value = values[y][x];
                                matrix[y][x].font_color = font_colors[y][x];
                                matrix[y][x].background_color = background_colors[y][x];
                        }
                }
        }

        container->matrix = matrix;
        container->len_line = len_line;
        container->len_col = len_col;
        if (_libansi_.config.matrix_buff) {
                libansi_matrix_update_buffer(container);
        }
        else {
                container->buff = NULL;
                container->buff_len = 0;
        }
        return container;
}