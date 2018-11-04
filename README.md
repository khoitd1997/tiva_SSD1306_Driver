# tiva_SSD1306_Driver

Driver for the SSD1306 OLED controller for the TivaC.

## Features

- Flexible font types(any font that has ttf convertible by website listed in the Font instruction)
- Multiple simultaneuos fonts
- Variable image size
- Auxillary features like adjusting constrast, clear display, etc

## Docs

[Doxygen Docs for the Driver]()

## Directory Structure

- src/: the src directory containing the driver source files
    - oled_font.h: files containing font struct definition that all created bitmaps will follow
    - ssd1306_info.h: containing configs, register maps and information about the ssd1306
    - ssd1360_utils: header and source files for utilities functions used by the driver, mainly I2C functions for writing list/single item
    - ssd1306: the main driver containing function that user will directly uses
    - main.c: containing a small program serving as example or quick test of the display
- create_new_font.py: scripts used for automating creation of new c array struct for a font type, need the file path of the raw c font file as first argument and font name as second command line argument, output two files in src/oled_font_font_name.h and src/oled_font_font_name.c
- docs/: contain doxygen docs

## External Dependencies

This project is a ccs project, setting up ccs is outside the scope of this README so consult TI documentation for that

This driver uses the Tivaware support package from TI for the low level works so to run this you need to have this in the compile PATH

## Display Icon and Images

Icon and Images are recommended to have black background and be mainly black and white, icons like this have a better chance of working well:

![Black Background Icons](image/2018-11-03-19-18-36.png)

Credits: Icons made by Google from https://www.flaticon.com/ (a very good site to get black background icons)

Making the dimension symmetric like 16x16 gives good results, this driver does support drawing partial image but it's recommended to pre-crop before inserting the bit map into the firmware

### How to print picture on screen

Resize your picture if you need to, then go to this [site](http://javl.github.io/image2cpp/), depending on your picture, pick Horizontal or Vertical in the Output section(just do trial and error if you are not sure), copy the images in to a bitmap array and use it like this:

```c
// in your c file

static uint8_t testIcon[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; // arrays obtained from the site above

ssd1306PrintPic(testIcon, 0, 127, 0, 0); // print icons onscreen with given coordinate
```

## Using Custom Fonts

This driver comes with a python script called create_new_font.py that allows converting a c array bitmap to a struct that is used by the firmware

The python script will take a raw c bitmap file and converts to struct used by firmware, the struct you will be interested in will be in the form of font_name_set, where font_name is supplied as the second argument of the python script and is declared in src/oled_font_font_name.h

By default, the raw c font file has incosistent whitespace in them, the script will remove those whitespace as well as put the raw array into source files ready to be integrated into the firmware

This repo comes with an example font called source_pro.

Steps:

1. Get a ttf file from site like [this](https://fonts.google.com/)
2. Go [here](https://littlevgl.com/ttf-font-to-c-array) and convert the file to a c array file, set bpp to 1, other settings are up to you but monospace font tends to look better
3. With the downloaded c array file, launch the python script:

```python
python3 create_new_font.py /home/your_name/Downloads/source_code_pro_oled.c font_name # provide raw bit map fiile path and font name
```

4. The steps above will create two files, oled_font_font_name.h and oled_font_font_name.c, you need the struct named font_name_set(declared in oled_font_font_name.h) to use the write string function:

```c
// main.c

#include "oled_font_font_name.h"
ssd1306PrintString("ABCDE14321L", 0, 0, font_name_set);
```

## Credits And Reources

Huge thanks to [Adafruit SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306) for providing the detailed steps needed for initializing the ssd1306 as well as for the macro definitions

[Image to C Array Converter](http://javl.github.io/image2cpp/)

[Google Font](https://fonts.google.com/)

[TTF to C Array Converter](https://littlevgl.com/ttf-font-to-c-array)