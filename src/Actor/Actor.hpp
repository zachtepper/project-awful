#ifndef Actor_hpp
#define Actor_hpp

#include "../core.hpp"

class Actor
{
private:
    // Variables
    bool attacking;
        
    // Initializer Functions
    void initVariables();

protected:
    sf::Sprite sprite;
        
public:
    Actor(float x, float y, sf::Texture& texture_sheet);
    virtual ~Actor();

    void setTexture(sf::Texture& texture);

    // Functions
    virtual void setPosition(const float x, const float y);
        
    // Functions
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);
};

#endif /* Actor_hpp */
