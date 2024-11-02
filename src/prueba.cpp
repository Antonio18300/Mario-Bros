//crecer canca
//cerar makefile para complilar prubas.cpp
//solo dejar canvas, quitar texto
//con las fucniones del canvas crear un dibujo

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int posicionX(int posicion, int velocidad, int tiempo){
    return posicion + (velocidad) * (tiempo);
}

int posicionY(int posicion, int velocidad, int tiempo){
    return 0.5 * (9.81) * (tiempo * tiempo);
}

int main(int argc, char const *argv[])
{
    std::string reset_position;

    int frame = 0;
    int vix = 1;
    int viy = 1;
    int posx = 10;//posiciones iniciales
    int posy = 10;

    while (true)
    {


        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        
        auto can = Canvas(300,100);

        int des_x = posx + vix * frame;

        can.DrawBlockLine(10, 70, 30, 70);
        can.DrawBlockLine(10, 70, 10, 50);
        can.DrawBlockLine(30, 70, 30, 50);
        can.DrawBlockLine(10, 50, 30, 50);
        can.DrawPointLine(10, 50, 20, 40);
        can.DrawPointLine(30, 50, 20, 40);
        can.DrawBlockLine(14, 70, 14, 60);
        can.DrawBlockLine(26, 70, 26, 60);
        can.DrawBlockLine(20, 70, 20, 65); 

        can.DrawBlockCircle(25 + des_x, 30, 5);
        can.DrawBlockCircle(85 + des_x, 30, 5);
        can.DrawBlockLine(15 + des_x, 20, 95 + des_x, 20);
        can.DrawBlockLine(15 + des_x, 22, 95 + des_x, 22);
        can.DrawBlockLine(35 + des_x, 10, 75 + des_x, 10);
        can.DrawPointLine(35 + des_x, 10, 35 + des_x, 20);
        can.DrawPointLine(75 + des_x, 10, 75 + des_x, 20);
        can.DrawBlockLine(40 + des_x, 14, 55 + des_x, 14);
        can.DrawBlockLine(60 + des_x, 14, 73 + des_x, 14);

        Element lienzo = bgcolor(Color::Red, canvas(&can));
        Render(pantalla, lienzo);

        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true); 

        this_thread::sleep_for(0.1s);
        frame++;
        if (des_x > 100) {
            frame = 0;
        }

    }

    return 0;
}
