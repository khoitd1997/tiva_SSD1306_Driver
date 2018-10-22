import numpy as np

bitmapData = [
         # space
 [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0021 (!), Width: 3 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x00,
    0x40,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0022 ("), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x60,
    0x60,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0023 (#), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x04,
    0x20,
    0x7e,
    0x28,
    0x28,
    0xfc,
    0x08,
    0x40,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0024 ($), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x40,
    0x60,
    0x30,
    0x08,
    0x08,
    0x78,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0025 (%), Width: 9 
, [
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x62, 0x00,
    0x14, 0x00,
    0x14, 0x00,
    0x1b, 0x00,
    0x6c, 0x00,
    0x14, 0x00,
    0x14, 0x00,
    0x23, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,

    ] #Unicode: U+0026 (&), Width: 8 
, [
    0x00,
    0x00,
    0x00,
    0x38,
    0x48,
    0x28,
    0x30,
    0x52,
    0x4e,
    0x46,
    0x7a,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0027 ('), Width: 2 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0028 ((), Width: 3 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x00,
    0x80,
    0x80,
    0x00,
    0x40,
    0x40,
    0x00,
    0x00,

    ] #Unicode: U+0029 ()), Width: 3 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x00,
    0x20,
    0x20,
    0x00,
    0x40,
    0x40,
    0x00,
    0x00,

    ] #Unicode: U+002a (*), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x30,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+002b (+), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+002c (,), Width: 3 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x80,
    0x00,

    ] #Unicode: U+002d (-), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x60,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+002e (.), Width: 3 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+002f (/), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x10,
    0x20,
    0x20,
    0x20,
    0x40,
    0x40,
    0x40,
    0x80,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0030 (0), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x30,
    0x48,
    0x48,
    0x00,
    0x00,
    0x48,
    0x48,
    0x30,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0031 (1), Width: 3 
, [
    0x00,
    0x00,
    0x00,
    0x60,
    0xa0,
    0x20,
    0x20,
    0x20,
    0x20,
    0x20,
    0x20,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0032 (2), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x70,
    0x08,
    0x08,
    0x08,
    0x10,
    0x20,
    0x40,
    0x78,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0033 (3), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x70,
    0x08,
    0x08,
    0x30,
    0x08,
    0x08,
    0x08,
    0x70,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0034 (4), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x18,
    0x18,
    0x28,
    0x48,
    0x08,
    0xfc,
    0x08,
    0x08,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0035 (5), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x78,
    0x40,
    0x40,
    0x70,
    0x08,
    0x08,
    0x08,
    0x70,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0036 (6), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x38,
    0x40,
    0x40,
    0x78,
    0x48,
    0x40,
    0x48,
    0x38,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0037 (7), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x78,
    0x08,
    0x08,
    0x10,
    0x10,
    0x00,
    0x20,
    0x20,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0038 (8), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x78,
    0x48,
    0x48,
    0x30,
    0x48,
    0x00,
    0x48,
    0x78,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0039 (9), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x30,
    0x48,
    0x08,
    0x48,
    0x78,
    0x08,
    0x08,
    0x70,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+003a (:), Width: 3 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+003b (;), Width: 3 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x80,
    0x00,

    ] #Unicode: U+003c (<), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x10,
    0x60,
    0x40,
    0x10,
    0x08,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+003d (=), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x00,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+003e (>), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x20,
    0x18,
    0x08,
    0x20,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+003f (?), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0x70,
    0x08,
    0x08,
    0x10,
    0x20,
    0x00,
    0x00,
    0x60,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0040 (@), Width: 10 
, [
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x1e, 0x00,
    0x20, 0x00,
    0x4e, 0x80,
    0x52, 0x00,
    0x12, 0x00,
    0x12, 0x80,
    0x4d, 0x00,
    0x40, 0x00,
    0x1e, 0x00,
    0x00, 0x00,
    0x00, 0x00,

    ] #Unicode: U+0041 (A), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x10,
    0x10,
    0x28,
    0x28,
    0x44,
    0x7c,
    0x44,
    0x82,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0042 (B), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0xf0,
    0x88,
    0x88,
    0xf0,
    0x88,
    0x88,
    0x88,
    0xf0,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0043 (C), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x1c,
    0x60,
    0x40,
    0x40,
    0x40,
    0x40,
    0x60,
    0x3c,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0044 (D), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0xf8,
    0x8c,
    0x84,
    0x84,
    0x84,
    0x84,
    0x8c,
    0xf0,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0045 (E), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0xf0,
    0x80,
    0x80,
    0xf0,
    0x80,
    0x80,
    0x80,
    0xf0,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0046 (F), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0xf8,
    0x80,
    0x80,
    0x80,
    0xf0,
    0x80,
    0x80,
    0x80,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0047 (G), Width: 8 
, [
    0x00,
    0x00,
    0x00,
    0x1e,
    0x60,
    0x40,
    0x40,
    0x46,
    0x42,
    0x62,
    0x3e,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0048 (H), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x84,
    0x84,
    0x84,
    0xfc,
    0x84,
    0x84,
    0x84,
    0x84,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0049 (I), Width: 1 
, [
    0x00,
    0x00,
    0x00,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+004a (J), Width: 2 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x80,
    0x00,

    ] #Unicode: U+004b (K), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x88,
    0x90,
    0xb0,
    0xe0,
    0xa0,
    0x90,
    0x88,
    0x84,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+004c (L), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0xf8,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+004d (M), Width: 8 
, [
    0x00,
    0x00,
    0x00,
    0xc3,
    0xc3,
    0x81,
    0xa5,
    0xa5,
    0x99,
    0x99,
    0x99,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+004e (N), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x84,
    0xc4,
    0xa4,
    0xa4,
    0x94,
    0x94,
    0x8c,
    0x84,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+004f (O), Width: 9 
, [
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x3e, 0x00,
    0x63, 0x00,
    0x41, 0x00,
    0x41, 0x00,
    0x41, 0x00,
    0x41, 0x00,
    0x63, 0x00,
    0x3e, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,

    ] #Unicode: U+0050 (P), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0xf0,
    0x88,
    0x88,
    0x88,
    0xf0,
    0x80,
    0x80,
    0x80,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0051 (Q), Width: 9 
, [
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x3e, 0x00,
    0x63, 0x00,
    0x41, 0x00,
    0x41, 0x00,
    0x41, 0x00,
    0x41, 0x00,
    0x63, 0x00,
    0x3c, 0x00,
    0x04, 0x00,
    0x02, 0x00,
    0x00, 0x00,

    ] #Unicode: U+0052 (R), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0xf0,
    0x88,
    0x88,
    0x88,
    0xf0,
    0x90,
    0x88,
    0x88,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0053 (S), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x38,
    0x40,
    0x40,
    0x60,
    0x18,
    0x08,
    0x08,
    0x78,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0054 (T), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0xfc,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0055 (U), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x84,
    0x84,
    0x84,
    0x84,
    0x84,
    0x84,
    0x84,
    0x78,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0056 (V), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x82,
    0x44,
    0x44,
    0x44,
    0x28,
    0x28,
    0x38,
    0x10,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0057 (W), Width: 10 
, [
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x8c, 0x40,
    0x0c, 0x00,
    0x4c, 0x80,
    0x50, 0x80,
    0x52, 0x80,
    0x12, 0x00,
    0x23, 0x00,
    0x21, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,

    ] #Unicode: U+0058 (X), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x48,
    0x30,
    0x30,
    0x30,
    0x00,
    0x48,
    0x84,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0059 (Y), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x84,
    0x48,
    0x48,
    0x30,
    0x30,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+005a (Z), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x78,
    0x08,
    0x10,
    0x10,
    0x20,
    0x20,
    0x40,
    0xf8,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+005b ([), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x70,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x70,
    0x00,

    ] #Unicode: U+005c (\), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x80,
    0x40,
    0x40,
    0x40,
    0x20,
    0x20,
    0x20,
    0x10,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+005d (]), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0xe0,
    0x20,
    0x20,
    0x20,
    0x20,
    0x20,
    0x20,
    0x20,
    0x20,
    0xe0,
    0x00,

    ] #Unicode: U+005e (^), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x20,
    0x30,
    0x40,
    0x48,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+005f (_), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xf8,
    0x00,

    ] #Unicode: U+0060 (`), Width: 2 
, [
    0x00,
    0x00,
    0x80,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0061 (a), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x08,
    0x78,
    0x48,
    0x48,
    0x78,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0062 (b), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x78,
    0x44,
    0x44,
    0x44,
    0x44,
    0x78,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0063 (c), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x30,
    0x40,
    0x40,
    0x40,
    0x40,
    0x30,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0064 (d), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x04,
    0x04,
    0x3c,
    0x44,
    0x44,
    0x44,
    0x44,
    0x3c,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0065 (e), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x38,
    0x48,
    0x78,
    0x40,
    0x40,
    0x38,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0066 (f), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0x30,
    0x40,
    0x60,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0067 (g), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x48,
    0x48,
    0x70,
    0x40,
    0x78,
    0x84,
    0x80,
    0x78,

    ] #Unicode: U+0068 (h), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x78,
    0x44,
    0x44,
    0x44,
    0x44,
    0x44,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0069 (i), Width: 2 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x00,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+006a (j), Width: 2 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x00,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x80,

    ] #Unicode: U+006b (k), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x48,
    0x50,
    0x60,
    0x50,
    0x48,
    0x48,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+006c (l), Width: 1 
, [
    0x00,
    0x00,
    0x00,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x80,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+006d (m), Width: 10 
, [
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x7b, 0x80,
    0x4c, 0x80,
    0x44, 0x80,
    0x40, 0x80,
    0x40, 0x80,
    0x40, 0x80,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,

    ] #Unicode: U+006e (n), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x44,
    0x44,
    0x44,
    0x44,
    0x44,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+006f (o), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x38,
    0x44,
    0x44,
    0x44,
    0x44,
    0x38,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0070 (p), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x78,
    0x44,
    0x44,
    0x44,
    0x44,
    0x78,
    0x40,
    0x40,
    0x40,

    ] #Unicode: U+0071 (q), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3c,
    0x44,
    0x44,
    0x44,
    0x44,
    0x3c,
    0x04,
    0x04,
    0x04,

    ] #Unicode: U+0072 (r), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x70,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0073 (s), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x70,
    0x00,
    0x60,
    0x10,
    0x00,
    0x70,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0074 (t), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x60,
    0x40,
    0x40,
    0x40,
    0x40,
    0x30,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0075 (u), Width: 7 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x44,
    0x44,
    0x44,
    0x44,
    0x44,
    0x3c,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0076 (v), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x84,
    0x48,
    0x48,
    0x48,
    0x30,
    0x30,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0077 (w), Width: 9 
, [
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x88, 0x80,
    0x08, 0x00,
    0x55, 0x00,
    0x55, 0x00,
    0x63, 0x00,
    0x22, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,

    ] #Unicode: U+0078 (x), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x48,
    0x48,
    0x30,
    0x30,
    0x48,
    0x48,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+0079 (y), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x84,
    0x48,
    0x48,
    0x48,
    0x30,
    0x30,
    0x20,
    0x20,
    0xc0,

    ] #Unicode: U+007a (z), Width: 5 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x70,
    0x10,
    0x20,
    0x20,
    0x40,
    0xf0,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+007b ({), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x30,
    0x20,
    0x00,
    0x00,
    0x40,
    0x40,
    0x00,
    0x00,
    0x20,
    0x30,
    0x00,

    ] #Unicode: U+007c (|), Width: 2 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

    ] #Unicode: U+007d (}), Width: 4 
, [
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x00,
    0x00,
    0x20,
    0x20,
    0x00,
    0x00,
    0x40,
    0x40,
    0x00,

    ] #Unicode: U+007e (~), Width: 6 
, [
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x60,
    0x18,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
]
]


OLED_TOTAL_COLUMN = 128
BITS_PER_COLUMN = 8


def main():
        tempMatrix = []
        finalList = []
        for currChar, bitHex in enumerate(bitmapData):

                # for i in range(0, len(bitHex)):
                #     for j in range(0, 7):
                #         tempMatrix.append([])

                # build a matrix representation of the character
                for index in range(0, len(bitHex)):
                        tempMatrix.append([])
                        print(hex(bitHex[index]))
                        for bitOrder in range(7, -1, -1):
                                # print(1 << bitOrder)
                                if (bitHex[index] & (1 << bitOrder)) > 0:
                                        tempMatrix[index].append(1)
                                else:
                                        tempMatrix[index].append(0)
                # print(tempMatrix)
                m = np.array(tempMatrix)
                m = np.transpose(m)
                print(np.array(tempMatrix))
                print("")
                print(m)
                m = m.tolist()

                finalList.append([])

                # prelocate position for first run
                for i in m:
                        finalList[currChar].append(0)

                for currPosition, i in enumerate(m):
                        tempSum = 0
                        tempCounter = 0
                        # package the number
                        for j in i:
                                tempSum = tempSum + (j << tempCounter)
                                tempCounter += 1
                        appendCounter = 0
                        # spread the number into 8 bit packs
                        while(tempSum > 0):
                                finalList[currChar][currPosition + (appendCounter * OLED_TOTAL_COLUMN)] = tempSum & 0xff
                                # print("Inserting ", tempSum & 0xff, "at ", currPosition + (appendCounter * OLED_TOTAL_COLUMN))
                                tempSum >>= BITS_PER_COLUMN
                                # print(tempSum)
                                # pad the list if there is another one
                                if(tempSum > 0):
                                        # print(len(finalList[bitChar]))
                                        appendCounter += 1
                                        while(len(finalList[currChar]) < OLED_TOTAL_COLUMN * appendCounter + currPosition + 1):
                                                # print("appending")
                                                finalList[currChar].append(0)

                tempMatrix = []

        print("")
        print("const fontDescList descList[TOTAL_CHAR] = {")
        for charIndex, charMoved in enumerate(finalList):
                print("{.glyphLen = ", len(charMoved), ", .glyphDataIndex =", charIndex, ", .glypBitmap=", charMoved, "}, ")
                # print(charMoved)
        print("};")
        # for bitChar, bitHex in finalList.items():
        #         print(bitChar, ": ", bitHex)
        #         print("")


if __name__ == '__main__':
	main()