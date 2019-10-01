add_library(ssd1306
            src/main.c
            src/oled_font_source_pro.c
            src/ssd1306.c
            src/ssd1306_utils.c)
target_include_directories(ssd1306 PUBLIC src/)
target_link_libraries(ssd1306 PRIVATE tiva_utils)
