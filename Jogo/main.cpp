#include "stdafx/stdafx.hpp"
#include "../Jogo/include/Jogo.hpp"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    Jogo jogo;

    jogo.executar();

    return 0;
}