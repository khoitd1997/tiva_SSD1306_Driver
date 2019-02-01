/**
 * @file oled_font.h
 * @author Khoi Trinh
 * @brief Header file for skeleton of oled bit maps
 * @version 0.1
 * @date 2018-11-03
 *
 *
 */

#ifndef _OLED_FONT_H
#define _OLED_FONT_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Struct containing the description of a character
 *
 */
typedef struct {
  uint32_t       glyphLen;     //!< Length of the bitmap describing the character
  const uint8_t *glyphBitmap;  //!< The array containing bitmap of the char
} fontDescList;

/**
 * @brief Struct describing an entire set of fonts
 *
 */
typedef struct {
  const uint32_t totalChar;   //!< Total characters in the fonts
  const uint32_t charOffset;  //!< Offset of character index in descriptor list from its ascii value
  const fontDescList *descList;  //!< Descriptor list containing bitmaps of the characters
} fontSetDesc;

#ifdef __cplusplus
}
#endif
#endif
