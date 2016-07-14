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


#include "global.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"
#include "../Util/image_func.hpp"
#include "../Util/FPSCounter.hpp"

#include "../Objects/Wall.hpp"
#include "../Objects/Creature.hpp"

#include "../Objects/Object.hpp"


int cPlayState::OnInit()
{
m_tex_bg=NULL;
//m_tex_bg=ImageFunc::LoadSprites("Images/play.png");

//init other members
m_wall=new cWall;
m_player=new cCreature;

    m_fps=new cFPSCounter(60);
    m_fps->StartCount();
return 0;
}


int cPlayState::OnCleanUp()
{
    delete m_wall;
    delete m_player;

    delete m_fps;
    SDL_DestroyTexture(m_tex_bg);

    return 0;
}


void cPlayState::OnEvent()
{
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                // FIX: mem leak
                Global::state.clear();
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_ESCAPE)
                {
                    cMenuState *p_menu=new cMenuState;
                    p_menu->OnInit();
                    Global::state.push_back(p_menu);
                }

                else if(event.key.keysym.sym==SDLK_q)
                {
                    Global::state.back()->OnCleanUp();
                    delete Global::state.back();
                    Global::state.pop_back();
                }
                 
                // movement
                else if (event.key.keysym.sym==SDLK_LEFT) {
                    m_player->Move(Move_LEFT);
                }
                else if(event.key.keysym.sym==SDLK_RIGHT){
                    m_player->Move(Move_RIGHT);
                }
                    
                // jump
                else if(event.key.keysym.sym==SDLK_SPACE){
                    m_player->Jump();
                }
                    
                break;
                    
            case SDL_KEYUP:
                // movement
                if (event.key.keysym.sym==SDLK_LEFT) {
                    m_player->Move(Move_NONE);
                }
                else if(event.key.keysym.sym==SDLK_RIGHT){
                    m_player->Move(Move_NONE);
                }
                    break;
            }

        }
}


void cPlayState::OnRender()
{
    SDL_RenderClear(Global::renderer);
    
    ImageFunc::DrawTexture(0, 0, m_tex_bg);
    
    m_player->Draw();
    m_wall->Draw();
    
    SDL_RenderPresent(Global::renderer);
}


void cPlayState::OnUpdate()
{
    m_fps->CheckFPS();
    
    m_player->Update(m_fps->m_deltaTime);
    
    m_fps->GetNewTick();
}

