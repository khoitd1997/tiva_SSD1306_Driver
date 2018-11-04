#include "oled_font_source_pro.h"
#include <stdint.h>

#define TOTAL_CHAR 95
#define CHAR_LIST_OFFSET 32

const fontDescList source_pro[TOTAL_CHAR] = {
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, //   
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){62, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // ! 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){30, 0, 6, 0, 30, 0, 6, 0}}, // " 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){80, 0, 240, 3, 84, 0, 80, 3, 92, 0, 16, 0}}, // # 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){128, 0, 28, 1, 36, 1, 36, 1, 196, 1, 128, 0}}, // $ 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){24, 0, 36, 1, 164, 0, 24, 0, 128, 1, 80, 2, 76, 2, 128, 1}}, // % 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){192, 1, 62, 2, 114, 2, 142, 3, 128, 1, 96, 2}}, // & 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){30, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // ' 
{.glyphLen = 6, .glyphBitmap=(uint8_t[]){248, 1, 6, 6, 1, 8}}, // ( 
{.glyphLen = 6, .glyphBitmap=(uint8_t[]){3, 12, 6, 6, 248, 1}}, // ) 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){160, 1, 96, 0, 224, 0, 32, 1}}, // * 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){32, 0, 32, 0, 248, 0, 32, 0, 32, 0, 32, 0}}, // + 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){0, 0, 0, 11, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // , 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){32, 0, 32, 0, 32, 0, 32, 0, 32, 0, 32, 0}}, // - 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // . 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){0, 8, 0, 6, 192, 1, 48, 0, 14, 0}}, // / 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){248, 0, 12, 3, 100, 2, 100, 2, 8, 1, 240, 0}}, // 0 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){0, 2, 4, 2, 12, 2, 252, 3, 0, 2, 0, 2}}, // 1 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){8, 2, 4, 3, 132, 2, 68, 2, 56, 2, 0, 2}}, // 2 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){8, 1, 4, 2, 36, 2, 36, 2, 92, 3, 128, 0}}, // 3 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){192, 0, 160, 0, 152, 0, 140, 0, 252, 3, 128, 0}}, // 4 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){48, 1, 44, 2, 36, 2, 36, 2, 100, 1, 192, 0}}, // 5 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){240, 0, 72, 1, 36, 2, 36, 2, 100, 3, 192, 1}}, // 6 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){4, 0, 4, 0, 132, 3, 100, 0, 28, 0, 4, 0}}, // 7 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){200, 1, 124, 2, 36, 2, 36, 2, 124, 3, 128, 1}}, // 8 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){56, 0, 68, 2, 68, 2, 68, 2, 168, 1, 240, 0}}, // 9 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){0, 0, 24, 3, 24, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // : 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){0, 0, 24, 11, 24, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // ; 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){112, 0, 80, 0, 136, 0, 136, 0}}, // < 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){80, 0, 80, 0, 80, 0, 80, 0, 80, 0, 80, 0}}, // = 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){136, 0, 136, 0, 80, 0, 32, 0}}, // > 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){2, 0, 66, 3, 50, 0, 28, 0}}, // ? 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){176, 3, 8, 4, 196, 9, 36, 9, 36, 9, 248, 1}}, // @ 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){128, 3, 120, 0, 70, 0, 78, 0, 112, 0, 128, 3}}, // A 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 34, 2, 34, 2, 34, 2, 62, 3, 200, 1}}, // B 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){248, 0, 4, 1, 2, 2, 2, 2, 2, 2, 4, 1}}, // C 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 2, 2, 2, 2, 2, 2, 4, 1, 248, 0}}, // D 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){254, 3, 34, 2, 34, 2, 34, 2, 2, 2}}, // E 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){254, 3, 34, 0, 34, 0, 34, 0, 2, 0}}, // F 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){248, 0, 4, 1, 2, 2, 34, 2, 34, 2, 224, 1}}, // G 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 32, 0, 32, 0, 32, 0, 32, 0, 254, 3}}, // H 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){2, 2, 2, 2, 254, 3, 2, 2, 2, 2, 2, 2}}, // I 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){0, 1, 2, 2, 2, 2, 2, 2, 254, 1}}, // J 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 96, 0, 48, 0, 120, 0, 196, 0, 2, 3}}, // K 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){254, 3, 0, 2, 0, 2, 0, 2, 0, 2}}, // L 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 12, 0, 192, 0, 96, 0, 14, 0, 254, 3}}, // M 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 12, 0, 48, 0, 192, 0, 0, 3, 254, 3}}, // N 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){252, 1, 6, 3, 2, 2, 2, 2, 4, 1, 248, 0}}, // O 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 34, 0, 34, 0, 34, 0, 50, 0, 28, 0}}, // P 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){252, 1, 6, 3, 2, 2, 2, 6, 4, 9, 248, 8}}, // Q 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 34, 0, 34, 0, 98, 0, 182, 1, 28, 2}}, // R 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){8, 1, 22, 2, 50, 2, 34, 2, 98, 3, 192, 1}}, // S 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){2, 0, 2, 0, 254, 3, 2, 0, 2, 0, 2, 0}}, // T 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 1, 0, 3, 0, 2, 0, 2, 0, 3, 254, 0}}, // U 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){14, 0, 112, 0, 0, 3, 128, 3, 120, 0, 6, 0}}, // V 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){14, 0, 240, 3, 0, 3, 112, 0, 96, 0, 0, 3, 252, 1, 2, 0}}, // W 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){2, 2, 140, 1, 112, 0, 112, 0, 140, 1, 2, 2}}, // X 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){6, 0, 24, 0, 224, 3, 96, 0, 28, 0, 6, 0}}, // Y 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){2, 3, 130, 2, 98, 2, 18, 2, 14, 2, 2, 2}}, // Z 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){254, 15, 2, 8, 2, 8, 2, 8}}, // [ 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){2, 0, 12, 0, 112, 0, 128, 1, 0, 14}}, // \ 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){2, 8, 2, 8, 2, 8, 254, 15, 0, 0, 0, 0, 0, 0, 0, 0}}, // ] 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){56, 0, 6, 0, 14, 0, 48, 0}}, // ^ 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8}}, // _ 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // ` 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){128, 1, 144, 2, 80, 2, 80, 2, 112, 1, 192, 3}}, // a 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 48, 1, 16, 2, 16, 2, 48, 3, 224, 1}}, // b 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){192, 1, 32, 1, 16, 2, 16, 2, 16, 2, 0, 1}}, // c 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){224, 1, 48, 2, 16, 2, 16, 2, 48, 3, 254, 3}}, // d 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){224, 1, 80, 3, 80, 2, 80, 2, 80, 2, 96, 0}}, // e 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){16, 0, 16, 0, 252, 3, 22, 0, 18, 0, 18, 0}}, // f 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){96, 13, 240, 18, 144, 18, 144, 18, 112, 18, 16, 14}}, // g 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 32, 0, 16, 0, 16, 0, 48, 0, 224, 3}}, // h 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){16, 0, 16, 0, 16, 0, 246, 3}}, // i 
{.glyphLen = 8, .glyphBitmap=(uint8_t[]){16, 16, 16, 16, 16, 16, 246, 15}}, // j 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){254, 3, 192, 0, 64, 0, 224, 0, 144, 1, 16, 2}}, // k 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){2, 0, 2, 0, 254, 1, 0, 3, 0, 2, 0, 2}}, // l 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){240, 3, 16, 0, 48, 0, 32, 0, 16, 0, 240, 3}}, // m 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){240, 3, 32, 0, 16, 0, 16, 0, 48, 0, 224, 3}}, // n 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){224, 1, 48, 3, 16, 2, 16, 2, 48, 3, 224, 1}}, // o 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){240, 31, 32, 3, 16, 2, 16, 2, 48, 3, 224, 1}}, // p 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){224, 1, 48, 2, 16, 2, 16, 2, 48, 3, 240, 31}}, // q 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){240, 3, 32, 0, 16, 0, 16, 0, 16, 0}}, // r 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){32, 1, 112, 2, 80, 2, 16, 2, 144, 2, 0, 1}}, // s 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){16, 0, 16, 0, 252, 3, 16, 2, 16, 2, 16, 2}}, // t 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){240, 1, 0, 2, 0, 2, 0, 2, 128, 1, 240, 3}}, // u 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){48, 0, 192, 0, 0, 3, 0, 3, 224, 0, 16, 0}}, // v 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){48, 0, 224, 3, 0, 3, 112, 0, 224, 0, 0, 3, 224, 1, 16, 0}}, // w 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){16, 2, 48, 1, 192, 0, 192, 0, 48, 3, 0, 2}}, // x 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){48, 16, 192, 16, 0, 15, 0, 3, 192, 0, 48, 0}}, // y 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){16, 2, 16, 3, 144, 2, 80, 2, 48, 2, 16, 2}}, // z 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){64, 0, 252, 7, 2, 8, 2, 8, 2, 8}}, // { 
{.glyphLen = 16, .glyphBitmap=(uint8_t[]){255, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // | 
{.glyphLen = 10, .glyphBitmap=(uint8_t[]){2, 8, 2, 8, 6, 12, 224, 0, 64, 0}}, // } 
{.glyphLen = 12, .glyphBitmap=(uint8_t[]){64, 0, 32, 0, 32, 0, 64, 0, 64, 0, 32, 0}}, // ~ 

};

const fontSetDesc source_pro_set = {
	.totalChar = TOTAL_CHAR,
	.charOffset = CHAR_LIST_OFFSET,
	.descList = source_pro, 
};
