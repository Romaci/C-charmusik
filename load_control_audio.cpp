#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <thread> 
#include <chrono>

using namespace std;

int main (){

sf::SoundBuffer buffer;

if(!buffer.loadFromFile("dirty_house.wav"))
{
    cerr << "Loading error" << endl;
    return -1;
}


sf:: Sound sound (buffer);

cout << "Controls:\n";
cout << "  P - Play\n";
cout << "  S - Stop\n";
cout << "  F - Foward\n";
cout << "  Q - Quit\n";

char command;


while (true) {
        cout << "Enter command: ";
        cin >> command;
        command = tolower(command);  // Convert to lowercase to avoid case issues

        if (command == 'p') {
            sound.play();
            cout << "Playing..." << endl;
        } else if (command == 's') {
            sound.stop();
            cout << "Stopped." << endl;
        }else if(command == 'f'){

            string input;
            cout << "Enter sec: ";
            cin>> input;
            int sec = stoi(input);
            sound.setPlayingOffset(sf::seconds(sec));
            sound.play();
            cout << "Playing..." << endl;

        }else if (command == 'q') {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid command." << endl;
        }
    }

return 0;
}