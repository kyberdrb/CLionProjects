#pragma once

// global static function are hidden from the global scope of the linker; the linker sees this function only in this translation unit
static int foo() {
    return 2;
}

int useFooInFile2();
