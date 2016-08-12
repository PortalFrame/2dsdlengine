/*
 * Copyright (c) 2011-2016 minjie.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#include "Button.hpp"
#include "Texture.hpp"

cButton::cButton(int x, int y)
{
    m_x=x;
    m_y=y;
    m_width=160;
    m_height=30;

    m_tex=new cTexture();
    m_tex->LoadSprite("Images/btn.png",true,255,0,0);
}

cButton::~cButton()
{

}


bool cButton::IsClicked(int x, int y)
{
    if(x>=m_x&&x<=(m_x+m_width)
       &&y>=m_y&&y<=(m_y+m_height))
    {
        return true;
    }
    else
    {
        return false;
    }
}


/// virtual
void cButton::Draw()
{
    m_tex->Draw(m_x, m_y);
}

