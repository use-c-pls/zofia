/* Author @daoluke */
#ifndef ZOFIA_CONSTANT_CPP__
#define ZOFIA_CONSTANT_CPP__

#include <string>
#include <map>

namespace zofia {
    static std::string TITLE = "zofia";
    const std::string DEFAULT_CONFIG_PATH = "resources/configs/config.json";
    const std::string DEFAULT_FONT_PATH = "resources/fonts/arial.ttf";

    static int DEFAULT_GAME_WIDTH = 1920;
    static int DEFAULT_GAME_HEIGHT = 1080;

    static std::map<std::string, std::string> DEFAULT_KEY_BINDING = {
            {"up",    "w"},
            {"down",  "s"},
            {"left",  "a"},
            {"right", "d"},
            {"fire",  "f"}
    };
}

#endif