# used for preparing fonts
# input is the file path to the .c file received from https://littlevgl.com/ttf-font-to-c-array

import fileinput
import sys
import re
import os

fontSourceFileName = "font_source.py"
destFolder = "src"
destFileName = "oled_font.c"


def createSourceFontFile():
        foundOpen = False
        foundFirstChar = False
        try:
                processedFontFile = open(fontSourceFileName, 'w')

        except:
            print("Can't create new files")
            sys.exit(0)  # quit Python
        for line in fileinput.input():
                if(foundOpen):
                        searchResult = re.search("\s*};\s*", line)
                        if(searchResult != None):
                                processedFontFile.write("]]")
                                processedFontFile.close()
                                break

                        tempLine = line
                        tempLine = re.sub("{", "", tempLine)
                        tempLine = re.sub("\w*//.*", "", tempLine)  # delete all c comments

                        # change c array to sub list
                        if(foundFirstChar):
                                tempLine = re.sub("/\*", "]#", tempLine)
                                tempLine = re.sub("\*/", "\n,[", tempLine)
                        else:
                                searchResult = re.search("/\*", line)
                                if(searchResult != None):
                                        tempLine = re.sub("/\*", "#", tempLine)
                                        tempLine = re.sub("\*/", "\n[", tempLine)
                                        foundFirstChar = True

                        processedFontFile.write(tempLine)

                if(False == foundOpen):
                        searchResult = re.search("\s*static const uint8_t source_code_pro_oled_glyph_bitmap\[\] =\s*", line)
                        if(searchResult != None):
                                foundOpen = True
                                processedFontFile.write("bitmapData = [")


def makeCHeaderFile():
        import numpy as np
        import font_source as ft

        BITS_PER_COLUMN = 8
        TOTAL_PAGE = 4

        tempMatrix = []
        finalList = []
        for currChar, bitHex in enumerate(ft.bitmapData):

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
                                finalList[currChar].append(tempSum & 0xff)
                                tempSum >>= BITS_PER_COLUMN
                                appendCounter += 1

                        # pad unoccupied page
                        for k in range(0, TOTAL_PAGE - appendCounter):
                                finalList[currChar].append(0)

                tempMatrix = []

        try:
                currDir = os.path.dirname(os.path.abspath(__file__))
                print(currDir)
                relDir = destFolder + "/" + destFileName
                finalPath = os.path.join(currDir, relDir)
                print(finalPath)
                cHeaderFile = open(finalPath, 'w')

        except:
                print("Can't create new files\n")
                sys.exit(0)

        cHeaderFile.write("#include \"oled_font.h\"\n")
        cHeaderFile.write("#include <stdint.h>\n")
        cHeaderFile.write("\n")
        cHeaderFile.write("const fontDescList descList[TOTAL_CHAR] = {\n")
        structMember = ""
        for charMoved in finalList:
                structMember = structMember.join(["{.glyphLen = ", str(len(charMoved)), ", .glyphBitmap=(uint8_t[]){", ', '.join(map(str, charMoved)), "}}, \n"])
                cHeaderFile.write(structMember)
                structMember = ""

        cHeaderFile.write("\n};")
        try:
                cHeaderFile.close()
        except:
                print("Can't close c header file")
                sys.exit(0)


def main():
        createSourceFontFile()
        makeCHeaderFile()
        os.remove(fontSourceFileName)


if __name__ == '__main__':
	main()
