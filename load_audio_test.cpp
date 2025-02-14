#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <random>


using namespace std;

int main()
{
    /*
    //            ****Random****
    // Crear una semilla basada en el tiempo actual
   random_device rd;

    // Crear un generador de números aleatorios con la semilla
    mt19937 gen(rd());

    // Crear un distribuidor para generar números entre 1 y 100
    uniform_int_distribution<> dis(1, 100);
    //****************************************
    */

    // Crear la ventana usando Vector2u
    sf::RenderWindow window(sf::VideoMode({600, 600}), "Ventana SFML");
    // Crear un círculo de radio 50
    sf::CircleShape circle(50);  
    // Establecer el color de relleno a rojo
    circle.setFillColor(sf::Color::Red);  
    // Establecer la posición del círculo en el centro de la ventana
    circle.setPosition(sf::Vector2f(275.f, 275.f));   // Centro (600x600), con radio 50 -> (600-50)/2 = 275

    sf::Clock clock;
    // Cargar el sonido
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("bell-short.wav"))
    {
        cerr << "Error al cargar el archivo de sonido!" << endl;
        return -1;
    }

    // Crear el sonido directamente con el buffer
    sf::Sound sound(buffer);
    sound.play(); // Reproducir el sonido

    // Bucle principal de la ventana
    while (window.isOpen())
    {
        // Obtener eventos
        while (std::optional<sf::Event> event = window.pollEvent())
        {

            // Si se solicita cerrar la ventana
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Si el sonido terminó, cerrar la ventana
        if (sound.getStatus() == sf::Sound::Status::Stopped)
            window.close();

                // Cambiar el radio 
         circle.setRadius(dis(gen));
        // Limpiar y mostrar la ventana
        window.clear();
                // Dibujar el círculo rojo
        window.draw(circle);
        window.display();
    }

    return 0;
}
