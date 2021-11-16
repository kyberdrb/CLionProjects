#pragma once

class Forward;

class Master : Forward {};  // Use forward declared class as a base class.
                            // In this situation we need to include the header with the class, instead of forward declaring the class.
                            // Compilation fails even when the 'Forward.h' is not present in the build.