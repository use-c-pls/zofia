//
// Created by kienle on 12/02/2022.
//
#ifndef ZOFIA_CONFIG_CPP__
#define ZOFIA_CONFIG_CPP__

#include <iostream>
#include <fstream>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>

#include "Constant.cpp"

#define ZOFIA zofia::

namespace zofia {
    class Config {
        private:
          int m_width = 0;
          int m_height = 0;
          int m_volume = 0;
          std::string m_language = "en";
          std::string m_fontPath;

          std::map<std::string, std::string> m_keyBindings;

          void init(const std::string &configPath);
        public:
          explicit Config(const std::string &configPath) {
              this->init(configPath);
          };

          int getHeight();
          int getWidth();
          int getVolume();
          std::string getLanguage();
          std::string getFontPath();
          std::string getKeyBinding(const std::string &key);
    };
}

std::string readConfigAsString(const std::string &path);
Poco::JSON::Object::Ptr parse(const std::string &jsonStr);
Poco::JSON::Object::Ptr getFromJsonObject(Poco::JSON::Object::Ptr root, const std::string &key);
int get(const Poco::JSON::Object::Ptr &jsonObject, std::string key, int defaultValue);
std::string get(const Poco::JSON::Object::Ptr &jsonObject, std::string key, std::string defaultValue);

void zofia::Config::init(const std::string &configPath) {
    std::string jsonStr = readConfigAsString(configPath);
    Poco::JSON::Object::Ptr rootJson = parse(jsonStr);

    this->m_width = get(rootJson, "window_width", zofia::DEFAULT_GAME_WIDTH);
    this->m_height = get(rootJson, "window_height", zofia::DEFAULT_GAME_HEIGHT);
    this->m_language = get(rootJson, "language", "en");
    this->m_volume = get(rootJson, "volume", 1800);
    this->m_fontPath = get(rootJson, "font_path", zofia::DEFAULT_FONT_PATH);

    Poco::JSON::Object::Ptr keyBindingMap = getFromJsonObject(rootJson, "key_binding");
    std::string up = get(keyBindingMap, "up", zofia::DEFAULT_KEY_BINDING["up"]);
    std::string down = get(keyBindingMap, "down", zofia::DEFAULT_KEY_BINDING["down"]);
    std::string left = get(keyBindingMap, "left", zofia::DEFAULT_KEY_BINDING["left"]);
    std::string right = get(keyBindingMap, "right", zofia::DEFAULT_KEY_BINDING["right"]);
    std::string fire = get(keyBindingMap, "fire", zofia::DEFAULT_KEY_BINDING["fire"]);

    this->m_keyBindings.insert(std::pair<std::string, std::string>("up", up));
    this->m_keyBindings.insert(std::pair<std::string, std::string>("down", down));
    this->m_keyBindings.insert(std::pair<std::string, std::string>("left", left));
    this->m_keyBindings.insert(std::pair<std::string, std::string>("right", right));
    this->m_keyBindings.insert(std::pair<std::string, std::string>("fire", fire));
}

int ZOFIA Config::getHeight() {
    return this->m_height;
}

int ZOFIA Config::getWidth() {
    return this->m_width;
}

int ZOFIA Config::getVolume() {
    return this->m_volume;
}

std::string ZOFIA Config::getLanguage() {
    return this->m_language;
}

std::string ZOFIA Config::getKeyBinding(const std::string &key) {
    return this->m_keyBindings[key];
}
std::string zofia::Config::getFontPath() {
    return this->m_fontPath;
}
//----------------

std::string readConfigAsString(const std::string &path) {
    std::ifstream ifs(path, std::ifstream::binary);
    std::filebuf *fileBuf = ifs.rdbuf();

    std::size_t size = fileBuf->pubseekoff(0, ifs.end, std::ifstream::in);
    fileBuf->pubseekpos(0, std::ifstream::in);
    char *buffer = new char[size];
    fileBuf->sgetn(buffer, size);

    std::string str(buffer);

    ifs.close();
    delete[] buffer;

    return str;
}

Poco::JSON::Object::Ptr parse(const std::string &jsonStr) {
    Poco::JSON::Parser parser;

    Poco::Dynamic::Var jsonVar = parser.parse(jsonStr);

    return jsonVar.extract<Poco::JSON::Object::Ptr>();
}

Poco::JSON::Object::Ptr getFromJsonObject(Poco::JSON::Object::Ptr root, const std::string &key) {
    return root->getObject(key);
}

int get(const Poco::JSON::Object::Ptr &jsonObject, std::string key, int defaultValue) {
    if (jsonObject->has(key)) {
        return jsonObject->getValue<int>(key);
    }
    return defaultValue;
}

std::string get(const Poco::JSON::Object::Ptr &jsonObject, std::string key, std::string defaultValue) {
    if (jsonObject->has(key)) {
        return jsonObject->getValue<std::string>(key);
    }
    return defaultValue;
}

#endif