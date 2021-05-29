#ifndef Gui_hpp
#define Gui_hpp

#include "../core.hpp"

enum button { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button 
{
private:
    short unsigned buttonState;
    
    // shape will be the actual construct that makes up the button
    sf::RectangleShape shape;
    
    // used for putting text on the button
    sf::Font* font;
    sf::Text text;
    
    // fun colors for animation
    sf::Color textIdleColor;
    sf::Color textHoverColor;
    sf::Color textActiveColor;
    
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    
public:
    Button( float x, float y, float width, float height,
            sf::Font* font, std::string text, unsigned character_size,
            sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
            sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
    ~Button();
    
    // Accessors
    const bool isPressed() const;
    const std::string getText() const;
    
    // Modifiers
    void setText(const std::string text);
    
    // Functions
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);
};