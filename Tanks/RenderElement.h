#ifndef RENDERELEMENT_H
#define RENDERELEMENT_H
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"arus.h"
#include"DataBase.h"

class RenderElement
{
public:
	RenderElement(void);
	RenderElement(arus::Textures texture, sf::Vector2f pos);
	explicit RenderElement(arus::Textures texture);
	RenderElement(RenderElement& r);

	virtual ~RenderElement();

	//set
	void setTexture(arus::Textures t);
	void setTextureRect(sf::IntRect& rect);
	void setTextureAndRect(arus::Textures t, sf::IntRect& rect);
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);
	void setScale(float x, float y);
	void setScale(sf::Vector2f scale);
	void setRotation(float x);
	void setVisible(bool b);
	void setOrigin(float x, float y);
	void setOriginToCenter();

	//get
	sf::IntRect getTextureRect();
	arus::Textures getTextureID();
	sf::Sprite& getSprite();
	sf::Vector2f getPosition();
	sf::FloatRect getLocalBounds();
	sf::FloatRect getGlobalBounds();
	bool getVisible();

	//inne
	void move(float x, float y);
	void rotate(float x);
	void scale(float x, float y);

	void operator >> (sf::RenderWindow& window);

protected:
	bool isVisible;
	sf::Sprite mSprite;
	sf::Texture mTexture;
	arus::Textures mTexID;
};

#endif
