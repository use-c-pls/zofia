/* Author @daoluke */
#ifndef ZOFIA_CONSTANT_CPP__
#define ZOFIA_CONSTANT_CPP__

#include <string>
#include <map>
#include <vector>

namespace zofia {
    static std::string TITLE = "zofia";
    const std::string DEFAULT_CONFIG_PATH = "resources/configs/config.json";
    const std::string DEFAULT_FONT_PATH = "resources/fonts/Marker_Felt.ttf";

    static const int DEFAULT_GAME_WIDTH = 1920;
    static const int DEFAULT_GAME_HEIGHT = 1080;

    static std::map<std::string, std::string> DEFAULT_KEY_BINDING = {
            {"up",    "w"},
            {"down",  "s"},
            {"left",  "a"},
            {"right", "d"},
            {"fire",  "f"}
    };

    std::vector<int16_t> v(int16_t w, int16_t h, int16_t xOff, int16_t yOff) {
        std::vector<int16_t> res;
        res.push_back(w);
        res.push_back(h);
        res.push_back(xOff);
        res.push_back(yOff);
        return res;
    }

    static std::map<std::string, std::vector<int16_t>> DEFAULT_HIT_BOX = {
            {"space_ship_hit_box", v(50, 50, 0, 0)},
    };
}

#endif