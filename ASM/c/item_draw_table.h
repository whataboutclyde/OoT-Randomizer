#ifndef ITEM_DRAW_TABLE_H
#define ITEM_DRAW_TABLE_H

#include "z64.h"

typedef struct {
    void        (*draw_func)(z64_game_t *game, uint32_t draw_id);
    uint32_t    dlists[8];
} item_draw_table_entry_t;

extern item_draw_table_entry_t item_draw_table[];

void base_draw_gi_model(z64_game_t *game, uint32_t draw_id);

#endif
