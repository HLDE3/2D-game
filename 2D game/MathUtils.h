#pragma once
#include "PlayerSettings.h"
#include "RenderUtils.h"
#include <windows.h>

class MathUtils
{
    RenderUtils obj;
    bool tr = false;
    public:
	//hit box logic 
    bool UpCkeckBox(BallSettings unStaticObject, RenderUtils staticObject, float mod)
    {
        if (unStaticObject.x < staticObject.getsX - obj.getRad() * 2 
            || unStaticObject.x > staticObject.geteX
            || unStaticObject.y > staticObject.geteY + mod
            || unStaticObject.y < staticObject.getsY - obj.getRad() * 2 + 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool DownCkeckBox(BallSettings unStaticObject, RenderUtils staticObject)
    {
        if (unStaticObject.x < staticObject.getsX - obj.getRad() * 2
            || unStaticObject.x > staticObject.geteX
            || unStaticObject.y > staticObject.geteY
            || unStaticObject.y < staticObject.getsY - obj.getRad() * 2 - 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool LeftCkeckBox(BallSettings unStaticObject, RenderUtils staticObject)
    {
        if (unStaticObject.x < staticObject.getsX
            || unStaticObject.x > staticObject.geteX + 4
            || unStaticObject.y > staticObject.geteY
            || unStaticObject.y < staticObject.getsY - obj.getRad() * 2 + 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool RightCkeckBox(BallSettings unStaticObject, RenderUtils staticObject)
    {
        if (unStaticObject.x < staticObject.getsX - obj.getRad() * 2 - 2
            || unStaticObject.x > staticObject.geteX
            || unStaticObject.y > staticObject.geteY
            || unStaticObject.y < staticObject.getsY - obj.getRad() * 2 + 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    bool FallCkeckBox(BallSettings unStaticObject, RenderUtils staticObject)
    {
        if (unStaticObject.x < staticObject.getsX - obj.getRad() * 2
            || unStaticObject.x > staticObject.geteX
            || unStaticObject.y > staticObject.geteY
            || unStaticObject.y < staticObject.getsY - obj.getRad() * 2 - 4 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool FallBlockCkeckBox(RenderUtils unStaticObject, RenderUtils staticObject)
    {
        if (unStaticObject.geteX < staticObject.getsX
            || unStaticObject.getsX > staticObject.geteX
            || unStaticObject.getsY > staticObject.geteY
            || unStaticObject.geteY < staticObject.getsY)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool AllCkeckBox(BallSettings unStaticObject, RenderUtils staticObject)
    {
        if (unStaticObject.x < staticObject.getsX - obj.getRad() * 2 - 2
            || unStaticObject.x > staticObject.geteX + 2
            || unStaticObject.y > staticObject.geteY
            || unStaticObject.y < staticObject.getsY - obj.getRad() * 2 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //mausemausemausemausemausemausemausemausemausemausemausemause

    bool CkeckHover(Vector2i unStaticObject, RenderUtils staticObject)
    {
        if (unStaticObject.x > staticObject.sX - 50
            && unStaticObject.x < staticObject.eX
            && unStaticObject.y < staticObject.eY
            && unStaticObject.y > staticObject.sY - 50)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool MouseClickedLeft(Event ev)
    {
        if (ev.type == Event::MouseButtonPressed) {
            if (ev.key.code == Mouse::Left)
                tr = true;
        }

        if (ev.type == Event::MouseButtonReleased)
            if (ev.key.code == Mouse::Left)
                tr = false;

        return tr;
    }

    

    //math

        int lerp(float start, float end, float t) {
            float x = start * (1 - t) + end * t;
            return x;
    }

};

