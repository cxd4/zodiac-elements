mkdir -p obj

src="."
obj="$src/obj"

FLAGS_ANSI="\
    -S \
    -Os \
    -std=c89 \
    -ansi \
    -pedantic \
    -Wall"
FLAGS_x86="\
    -S \
    -Os \
    -masm=intel \
    -pedantic \
    -Wall"

C_FLAGS=$FLAGS_x86

echo Compiling sources...
cc -o $obj/elements.asm         $src/elements.c $C_FLAGS
cc -o $obj/geometry.asm         $src/geometry.c $C_FLAGS
cc -o $obj/input.asm            $src/input.c $C_FLAGS

echo Assembling compiled sources...
as -o $obj/elements.o           $obj/elements.asm
as -o $obj/geometry.o           $obj/geometry.asm
as -o $obj/input.o              $obj/input.asm

echo Linking assembled object files...
gcc -o $src/elements $obj/input.o $obj/geometry.o $obj/elements.o -lglut -lGL -lm -s
