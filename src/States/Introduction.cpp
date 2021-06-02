/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Introduction
*/

#include "../../include/States/Introduction.hpp"

Introduction::Introduction()
{
    _width = 10000;
    _height = 10000 / 2.9;

    _bouboule = LoadImage("./assets/img/Bouboule.png");

    music = LoadMusicStream("./assets/music/poutine.mp3");
    PlayMusicStream(music);
}

Introduction::~Introduction()
{
}

void Introduction::Draw()
{
    Texture2D texture = LoadTextureFromImage(_bouboule);
    Vector2 pos = {(GetScreenWidth()/2 - texture.width/2 * scale), (GetScreenHeight()/2 - texture.height/2 * scale)};
    DrawTextureEx(texture, pos, 0, scale, WHITE);

    UpdateScale(texture);
}

void Introduction::Update()
{
    UpdateMusicStream(music);
}

void Introduction::Clear()
{
    ClearBackground(RAYWHITE);
}

void Introduction::HandleInput()
{}

void Introduction::Reset()
{}

void Introduction::UpdateScale(Texture2D texture)
{
    if ((texture.width/2 * scale) < GetScreenWidth() + 20)
        scale = scale - 0.0001;
    else
        scale = scale - 0.014;

    if ((texture.width/2 * scale) < GetScreenWidth())
        _context->TransitionTo(new Menu);
}