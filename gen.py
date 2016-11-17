"""Generate header and cpp files for wbmp files."""
import os

dest = open("source/bitmaps.cpp", "w+")
head = open("source/bitmaps.h", "w+")

dest.write("#include \"bitmaps.h\"\n\n")
head.write("#ifndef BITMAPS_H\n#define BITMAPS_H\n\n#include <stdint.h>\n\n")

for file in os.listdir("bitmaps"):
    if file != ".DS_Store":
        size = os.stat("bitmaps/" + file).st_size
        source = open("bitmaps/" + file, "r+b")
        head.write("extern const uint8_t " + file + "[" + str(size) + "];\n")
        dest.write("const uint8_t " + file + "[" + str(size) + "] = {\n   ")

        counter = 3
        for x in range(0,size):
            byte = ord(source.read(1))
            counter = counter + 1
            if counter == 8:
                dest.write("\n   ")
                counter = 0

            dest.write(" 0x" + format(byte, "02X"))

            if x != size - 1:
                dest.write(",")
        dest.write("\n};\n\n")


head.write("\n#endif")
