#ifndef _OLED_FONT_H
#define _OLED_FONT_H

#include <stdint.h>

typedef struct {
  uint32_t glyphLen;
  const uint8_t *glyphBitmap;
} fontDescList;

typedef struct {
    const uint32_t totalChar;
    const uint32_t charOffset;
    const fontDescList *descList;
} fontSetDesc;

#endif
