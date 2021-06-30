#include "DropDown.hpp"

DropDown::DropDown(sf::Vector2f position, sf::Vector2f size, sf::Font& font, std::string list[], unsigned numElements, const unsigned default_index)
    : font(font), showList(false), keytimeMax(1.f), keytime(0.f)
{
    this->activeElement = new Button(
                    sf::Vector2f( position.x, position.y ), 
                    sf::Vector2f( size.x, size.y ),
                    &this->font, list[default_index], 24,
                    sf::Color(245, 245, 245, 200), sf::Color(255, 255, 255, 250), sf::Color(240, 240, 240, 100),
                    sf::Color(0x56A5ECcc), sf::Color(0x56A5ECbf), sf::Color(0x56A5ECb3));

    for (size_t i = 0; i < numElements; i++)
    {
        this->list.push_back( 
            new Button
            (
                sf::Vector2f( position.x, position.y + ( ( i + 1 ) * size.y ) ), 
                sf::Vector2f( size.x, size.y ),
                &this->font, list[i], 24,
                sf::Color(245, 245, 245, 200), sf::Color(255, 255, 255, 250), sf::Color(240, 240, 240, 100),
                sf::Color(0x56A5ECcc), sf::Color(0x56A5ECbf), sf::Color(0x56A5ECb3)
            )
         );
    }
    
}


DropDown::~DropDown()
{
    delete this->activeElement;
    for(size_t i = 0; i < this->list.size(); i++)
    {
        delete this->list[i];
    }
}

const bool DropDown::getKeytime()
{
    if (this->keytime >= this->keytimeMax)
    {
        this->keytime = 0.f;
        return true;
    }
    return false;
}

void DropDown::updateKeytime(const float& dt)
{
    if ( this->keytime < this->keytimeMax )
    {
        this->keytime += 10.f * dt;
    }
}

void DropDown::update(const sf::Vector2f &mousePos, const float& dt)
{
    this->updateKeytime(dt);
    this->activeElement->update(mousePos);
    
    // Show and hide list
    if (this->activeElement->isPressed() && this->getKeytime())
    {
        if (this->showList)
            this->showList = false;
        else
            this->showList = true;
    }
    
    if (this->showList)
    {
        for (auto &i : this->list)
        {
            i->update(mousePos);
            
            // close the list and replace the active element with the selected
            if (i->isPressed() && this->getKeytime())
            {
                this->showList = false;
                this->activeElement->setText(i->getText());
            }
        }
    }
}

void DropDown::render(sf::RenderTarget &target)
{
    this->activeElement->render(target);
    
    if ( this->showList ) 
    {
        for ( auto &i : this->list )
        {
            i->render(target);
        }
    }
}