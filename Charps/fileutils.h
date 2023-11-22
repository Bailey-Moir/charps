#pragma once
#include <string>

using namespace std;

namespace Charps {
    /**
     * File utilitises.
     */
    struct FileUtils {
        /**
         * Reads the text from a file.
         * @param filePath the path of the file.
         */
        static string readFile(const char* filePath);
    };
}

