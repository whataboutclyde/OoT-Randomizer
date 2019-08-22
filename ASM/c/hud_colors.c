#include <stdint.h>
#include "hud_colors.h"

extern colorRGB16_t CFG_HEART_COLOR;
extern colorRGB16_t CFG_A_BUTTON_COLOR;
extern colorRGB16_t CFG_B_BUTTON_COLOR;
extern colorRGB16_t CFG_C_BUTTON_COLOR;
extern colorRGB8_t CFG_START_BUTTON_COLOR;

colorRGB16_t defaultHeart   = { 0xFF, 0x46, 0x32 };
colorRGB16_t defaultDDHeart = { 0xC8, 0x00, 0x00 };

colorRGB16_t* beating_no_dd    = (colorRGB16_t*)0x801D8B92;
colorRGB16_2_t* normal_no_dd   = (colorRGB16_2_t*)0x801D8B9E;
colorRGB16_t* beating_dd       = (colorRGB16_t*)0x8011BD38;
colorRGB16_t* normal_dd        = (colorRGB16_t*)0x8011BD50;

colorRGB16_t* a_button        = (colorRGB16_t*)0x801C7950;
colorRGB16_t* b_button        = (colorRGB16_t*)0x801C767A;
colorRGB16_t* c_button        = (colorRGB16_t*)0x801C7672;

uint8_t* start_button_r          = (uint8_t*)0x80073F66;
uint8_t* start_button_g          = (uint8_t*)0x80073F67;
uint8_t* start_button_b          = (uint8_t*)0x80073F7A;
uint8_t* start_button_b_required = (uint8_t*)0x80073F78;

void update_hud_colors() {
  colorRGB16_t heartColor = CFG_HEART_COLOR;

  (*beating_no_dd)   = heartColor;

  (*normal_no_dd).r1 = heartColor.r;
  (*normal_no_dd).g1 = heartColor.g;
  (*normal_no_dd).b1 = heartColor.b;

  if (heartColor.r == defaultHeart.r &&
      heartColor.g == defaultHeart.g &&
      heartColor.b == defaultHeart.b) {
    heartColor = defaultDDHeart;
  }

  (*beating_dd) = heartColor;
  (*normal_dd)  = heartColor;

  (*a_button) = CFG_A_BUTTON_COLOR;
  (*b_button) = CFG_B_BUTTON_COLOR;
  (*c_button) = CFG_C_BUTTON_COLOR;

  (*start_button_r) = CFG_START_BUTTON_COLOR.r;
  (*start_button_g) = CFG_START_BUTTON_COLOR.g;
  (*start_button_b) = CFG_START_BUTTON_COLOR.b;
  if (CFG_START_BUTTON_COLOR.b != 0) {
    (*start_button_b_required) = 0x35;
  }
}
