#include <iostream>
#include <array>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    //Create Window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Sorting Algorithm", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;
    //Create Array
    std::array<int, 200> Bars;
    std::srand(time(0));
    for (int i = 0; i < Bars.size(); i++) {
        Bars[i] = i;
    }
    //Randomize Array
    int temp = 0;
    int randomIndex = 0;
    for (int i = 0; i < Bars.size(); i++) {
        randomIndex = rand() % 200;
        temp = Bars[i];
        Bars[i] = Bars[randomIndex];
        Bars[randomIndex] = temp;
    }
    //for (int i = 0; i < 200; i++) {
       // std::cout << Bars[i] << std::endl;
   // }
    //Creating Bars
    sf::RectangleShape Objects[200];
    for (int i = 0; i < 200; i++) {
        float j = 4 + 4 * i;
        Objects[i].setSize(sf::Vector2f(4, 4 + 4 * Bars[i]));
        Objects[i].setFillColor(sf::Color(100, 250, 50));
        Objects[i].rotate(180.f);
        Objects[i].setPosition(j, 800.f);
    }
    //Temporary Rectangle Shape Variable
    sf::RectangleShape Tempo;
    //Initialize clock
    sf::Clock clock;
    //Window mechanism
    int i = 1;
    int j = 0;
    while (window.isOpen())
    {
        //Evento poll command
        while (window.pollEvent(ev)) {
            switch (ev.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
        }
        //Update

        //Render
        window.clear(sf::Color::Black); //clear frame

        sf::Time elapsed1 = clock.getElapsedTime();


        //Draw

        if (Objects[i + j].getSize().y < Objects[i + j - 1].getSize().y && ((i + j - 1) > -1) && (i < 200)) {
            if (elapsed1.asSeconds() > .001) {
                Objects[i + j].move(-4.f, 0.f);
                Objects[i + j - 1].move(4.f, 0.f);
                Tempo = Objects[i + j];
                Objects[i + j] = Objects[i + j - 1];
                Objects[i + j - 1] = Tempo;
                Objects[i + j].setFillColor(sf::Color(100, 250, 50));
                Objects[i + j - 1].setFillColor(sf::Color(0, 47, 187));
                window.clear(sf::Color::Black);
                for (int i = 0; i < 200; i++) {
                    window.draw(Objects[i]);
                }
                j--;
                window.display();
                clock.restart();
            }
        }
        else {
            if (i == 200) {
                if (elapsed1.asSeconds() > 10) {
                    return 0;
                }
            }
            else {
                if ((i + j) > (-1))
                {

                    window.clear(sf::Color::Black);
                    Objects[i + j].setFillColor(sf::Color(100, 250, 50));
                    for (int i = 0; i < 200; i++) {
                        window.draw(Objects[i]);
                    }
                    window.display();
                    clock.restart();
                }
                i++;
                j = 0;
            }


        }



        //window is donde drawing


    }
    //end of the program
    return 0;

}