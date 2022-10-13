#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class RenderUtils
{


	public:
		float sX,sY,eX,eY,getsX, getsY, geteX, geteY, cirlceRadius = 10;
	RectangleShape drawRect(float startX, float startY, float endX, float endY, float rotate,Color color)
	{
			RectangleShape block(Vector2f(0, 0));
			block.setRotation(rotate);
			block.setFillColor(color);
			block.setPosition(startX, startY);
			block.setSize(Vector2f(endX, endY));
			return block;
	}
	
	RectangleShape drawRoundedRect(float startX, float startY, float endX, float endY, float rotate, Color color)
	{

		getsX = startX;
		getsY = startY;
		geteX = endX + startX;
		geteY = endY + startY;

		RectangleShape block(Vector2f(0, 0));

		block.setOutlineThickness(2);
		block.setOutlineColor(Color(0,0,255));
		block.setRotation(rotate);
		block.setFillColor(color);
		block.setPosition(startX, startY);
		block.setSize(Vector2f(endX , endY));
		
		return block;
	}

	CircleShape drawCircle(float x, float y,float radius,Color color,Color outlineColor)
	{
		cirlceRadius = radius;
		CircleShape circle1;
		circle1.setRadius(radius);
		circle1.setPosition(x, y);
		circle1.setFillColor(color);
		circle1.setOutlineColor(outlineColor);
		circle1.setOutlineThickness(2);
		return circle1;


	}

	float getRad()
	{
		return cirlceRadius;
	}


};

