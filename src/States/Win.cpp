/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Win
*/

#include "../../include/States/Win.hpp"

Win::Win(int nbPlayer, int nbIA, int skin1, int skin2, std::string nameWinner)
{
    _bgWin.LoadFile("../assets/pictures/bg_win.png");

    std::string tmp = nameWinner + " Win !";
    // char *tmp2 = tmp.c_str();
    // std::cout << tmp.c_str() << std::endl;
    _win = Raylib::Text(tmp.c_str());

    _back = Raylib::Text("Back to Menu");
    _again = Raylib::Text("Play Again");

    _nbPlayer = nbPlayer;
    _nbIA = nbIA;
    _skin1 = skin1;
    _skin2 = skin2;

    _winMusic.LoadMusic("../assets/music/win.mp3");
}

Win::~Win()
{
}

bool Win::CheckMouse(Vector2 mouse, Raylib::Rectangle rect, Raylib::Text text, int state)
{
    if (CheckCollisionPointRec(mouse, rect))
    {
        if (state == 1)
        {
            _rectBack = {};
            text.Draw(rect.x + _screenWidth / 30, rect.y + _screenHeight / 25, (_screenWidth / 20) - (_screenHeight / 23), BLACK);
        }
        if (state == 2)
        {
            text.Draw(rect.x + _screenWidth / 20, rect.y + _screenHeight / 25, (_screenWidth / 20) - (_screenHeight / 23), BLACK);
            _rectAgain = {};
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return true;
    }
    return false;
}

void Win::Draw()
{
    _bgWin.Draw(0, 0, RAYWHITE);
    _rectAgain.Draw(50, 50, BLACK);
    _rectBack.Draw(50, 50, BLACK);

    _winMusic.Play();
}

void Win::Update()
{
    _screenWidth = _tools.GetScreenWidth();
    _screenHeight = _tools.GetScreenHeight();
    _posMouse = GetMousePosition();

    _winMusic.Update();

    // DrawText(_win.c_str(), _screenWidth / 4.5, _screenHeight / 4.5, (_screenWidth / 10) - (_screenHeight / 18), BLACK);
    _win.Draw(_screenWidth / 4.5, _screenHeight / 4.5, (_screenWidth / 10) - (_screenHeight / 18), BLACK);
    //  _win.Draw(0, 0, 14, BLACK);

    _rectBack = {_screenWidth / static_cast<float>(6), _screenHeight / static_cast<float>(1.3), _screenWidth / static_cast<float>(4), _screenHeight / static_cast<float>(8)};
    _rectAgain = {_screenWidth / static_cast<float>(1.8), _screenHeight / static_cast<float>(1.3), _screenWidth / static_cast<float>(4), _screenHeight / static_cast<float>(8)};

    _back.Draw(_rectBack.x + _screenWidth / 30, _rectBack.y + _screenHeight / 25, (_screenWidth / 20) - (_screenHeight / 23), PINK);
    _again.Draw(_rectAgain.x + _screenWidth / 20, _rectAgain.y + _screenHeight / 25, (_screenWidth / 20) - (_screenHeight / 23), PINK);
}

void Win::Clear()
{
}

void Win::HandleInput()
{
    if (CheckMouse(_posMouse, _rectBack, _back, 1) == true)
        _context->TransitionTo(new Menu);
    if (CheckMouse(_posMouse, _rectAgain, _again, 2) == true)
        _context->TransitionTo(new Game(_nbPlayer, _nbIA, _skin1, _skin2));
}

void Win::Reset()
{
}