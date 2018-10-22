#ifndef _OLED_FONT_H
#define _OLED_FONT_H

#include <stdint.h>

#define TOTAL_CHAR 95
#define CHAR_LIST_OFFSET 32

typedef struct {
  uint32_t glyphLen;
  const uint8_t *glyphBitmap;
} fontDescList;

extern const fontDescList descList[TOTAL_CHAR];

#endif