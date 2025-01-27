#ifndef Textbox_hpp
#define Textbox_hpp

#include "../core.hpp"
#include "Button.hpp"

#define ESCAPE_KEY 27
#define ENTER_KEY 13
#define DELETE_KEY 8

// enum textbox {BTN_IDLE = 0, BTN_IDLE, BTN_ACTIVE};

class Textbox : public Button
{
private:
    unsigned int textboxState;
    unsigned int limit;
    unsigned int keyTime = 0.f;
    unsigned int keyTimeMax = 17.f;
    bool isSelected;
    char lastChar = ' ';
    bool isDefault = true;
    string dfltText;

    void inputLogic (char CharTyped);
    void deleteLastChar ();

public:
    Textbox () {}
    Textbox (sf::Vector2f position, sf::Vector2f dimensions,
            sf::Font* font, unsigned character_size, unsigned character_limit,
            sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
            sf::Color idle_color, sf::Color hover_color, sf::Color active_color, bool hasBorder, string dfltText);
    ~Textbox() {}

    // Modifiers
    void setLimit (unsigned character_limit);

    // Accessors
    std::string getInputText ();

    // Functions
    void neutralize ();
    void update (const sf::Vector2f &mousePos, sf::Event &event);
    void render (sf::RenderTarget& target);
};

#endif