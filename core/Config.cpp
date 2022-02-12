//
// Created by kienle on 12/02/2022.
//
#include <iostream>
#include <fstream>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>

#define ZOFIA zofia::

namespace zofia {
    class Config {
        private:
            //default option
            std::string m_path;
            int m_width = 0;
            int m_height = 0;
            int m_volume = 0;
            std::string m_language = "en";
            //function
            std::string read_config(std::string path);

            //Key binding
            std::string m_keyUp = "w";
            std::string m_keyDown = "s";
            std::string m_keyLeft = "a";
            std::string m_keyRight = "d";
            std::string m_keyFire = "f";

        public:
            explicit Config() : m_path("resources/configs/config.json"){
                std::string jsonStr = read_config(m_path);
                Poco::JSON::Parser parser;

                Poco::Dynamic::Var jsonVar = parser.parse(jsonStr);

                Poco::JSON::Object::Ptr rootJson = jsonVar.extract<Poco::JSON::Object::Ptr>();

                this->m_width = rootJson->getValue<int>("window_width");
                this->m_height = rootJson->getValue<int>("window_height");
                this->m_language = rootJson->getValue<std::string>("language");
                this->m_volume = rootJson->getValue<int>("volume");

                //get key binding object from rootJson
                Poco::JSON::Object::Ptr keyBindingObj = rootJson->getObject("key_binding");

                this->m_keyUp = keyBindingObj->getValue<std::string>("up");
                this->m_keyDown = keyBindingObj->getValue<std::string>("down");
                this->m_keyLeft = keyBindingObj->getValue<std::string>("left");
                this->m_keyRight = keyBindingObj->getValue<std::string>("right");
                this->m_keyFire = keyBindingObj->getValue<std::string>("fire");


                if(this->m_width <= 0){
                    this->m_width = 1000;
                }

                if(this->m_height <= 0){
                    this->m_height = 1200;
                }

                if(this->m_language.empty()){
                    this->m_language = "en";
                }

                if(this->m_volume <= 0){
                    this->m_volume = 50;
                }

                if(this->m_keyUp.empty()){
                    this->m_keyUp = "w";
                }

                if(this->m_keyDown.empty()){
                    this->m_keyDown = "s";
                }

                if(this->m_keyRight.empty()){
                    this->m_keyRight = "d";
                }

                if(this->m_keyLeft.empty()){
                    this->m_keyLeft = "a";
                }

                if(this->m_keyFire.empty()){
                    this->m_keyFire = "f";
                }


            };

            virtual ~Config();

            int getHeight();
            int getWidth();
            int getVolume();
            std::string getLanguage();
            std::string getKeyUp();
            std::string getKeyDown();
            std::string getKeyLeft();
            std::string getKeyRight();
    };
}

std::string ZOFIA Config::read_config(std::string path) {
    std::ifstream ifs(path,std::ifstream::binary);

    std::filebuf* fileBuf = ifs.rdbuf();

    std::size_t size = fileBuf->pubseekoff(0,ifs.end,ifs.in);
    fileBuf->pubseekpos(0,ifs.in);

    char* buffer = new char[size];

    fileBuf->sgetn(buffer,size);

    ifs.close();

    std::string str (buffer);

    delete[] buffer;

    return str;
}

ZOFIA Config::~Config() {
    std::cout << "Cleaning up...";
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

std::string ZOFIA Config::getKeyUp() {
    return this->m_keyUp;
}

std::string ZOFIA Config::getKeyDown() {
    return this->m_keyDown;
}

std::string ZOFIA Config::getKeyLeft() {
    return this->m_keyLeft;
}

std::string ZOFIA Config::getKeyRight() {
    return this->m_keyRight;
}