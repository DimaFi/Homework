#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Sound {
public:
    int Height;
    int dlina;

    Sound(int height, int dlin) : Height(height), dlina(dlin) {}
};

class Melody {
private:
    list<Sound> sounds;

public:

    void addSound(const Sound& sound) {
        sounds.push_back(sound);
    }

    void newQueue(int n) {

        int count = 0;
        list<Sound> sounds2;
        auto it = sounds.begin();

        while (it != sounds.end() && count < sounds.size()) {
            if (it->Height >= n) {
                sounds2.push_back(*it);
                it = sounds.erase(it);
            }
            else {
                ++it;
            }
            ++count;
        }

        sounds.insert(sounds.end(), sounds2.begin(), sounds2.end());
    }

    void printMelody() {
        for (const Sound& sound : sounds) {
            cout << sound.Height << " " << sound.dlina  << endl;
        }
    }
};

int main() {

    Melody melody;

    melody.addSound(Sound(1, 3));
    melody.addSound(Sound(5, 2));
    melody.addSound(Sound(2, 4));
    melody.addSound(Sound(4, 1));
    melody.addSound(Sound(3, 5));

    cout << "Melody" << endl;
    melody.printMelody();

    int n = 4;
    melody.newQueue(n);

    cout << endl << "New melody" << endl;
    melody.printMelody();

}
