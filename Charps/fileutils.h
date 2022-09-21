#pragma once
#include <string>

namespace Charps {
    /**
     * File utilitises.
     */
    struct FileUtils {
        /**
         * Reads the text from a file.
         * @param filePath the path of the file.
         */
        static std::string readFile(const char* filePath);
    };
}

