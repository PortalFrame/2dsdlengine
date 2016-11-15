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


#ifndef _GAMESTATE_HPP_
    #define _GAMESTATE_HPP_

#include <vector>

class cUIObject;

class cGameState
{
    protected:
        std::vector<cUIObject *> m_DisplayList;

    public:
        virtual void OnEvent()=0;
        virtual void OnRender()=0;
        virtual void OnUpdate()=0;

    public:
         cGameState();
         virtual ~cGameState();
};

#endif
