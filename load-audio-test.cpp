#include <SFML/Audio.hpp>
#include <iostream>
#include <SFML/Window.hpp>
int main()
{
    // Intentar cargar el archivo de sonido
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("bell-short.wav"))
    {
        std::cerr << "Error al cargar el archivo de sonido!" << std::endl;
        return -1;
    }

    // Crear el sonido y asignarle el buffer
    sf::Sound sound(buffer);

    // Reproducir el sonido
    sound.play();
    sf::Window window(sf::VideoMode({600, 600}), "My window");


    // Mantener el programa en ejecución mientras el sonido se reproduce
    while (sound.getStatus() == sf::Sound::Status::Playing)
    {
             // Esperar un poco para evitar consumir demasiada CPU
  //      sf::sleep(sf::milliseconds(100));  
            // run the program as long as the window is open
    while (window.isOpen() || sound.getStatus() == sf::Sound::Status::Stopped)
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>() || sound.getStatus() == sf::Sound::Status::Stopped)
                window.close();
        }
    }         

    

    }



    return 0;
}
