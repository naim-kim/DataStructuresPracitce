#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Playlist {
private:
    stack<string> playlist;

public:
    void AddSong(const string& song) {
        playlist.push(song);
        cout << "\"" << song << "\" successfully added to the playlist!" << endl;
    }

    void PlayCurrentSong() {
        if (!playlist.empty()) {
            cout << "Now playing: " << playlist.top() << endl;
            cout << " ~ playing ~" << endl;
            playlist.pop();
        } else {
            cout << "No more songs to play :(" << endl;
        }
    }

    void PrintPlaylist() const {
        if (!playlist.empty()) {
            cout << "[ Current Playlist: ]" << endl;
            stack<string> temp = playlist;
            while (!temp.empty()) {
                cout << temp.top() << endl;
                temp.pop();
            }
        } else {
            cout << "No more songs to play :(" << endl;
        }
    }
};


int main() {
    Playlist playlist;
    
    playlist.AddSong("Snooze - SZA");
    playlist.AddSong("Chi-Ka - Tabber");
    playlist.AddSong("Mala Fama - Danna Paola");

    cout << "--- Naim's Playlist ---\n" << endl;
    playlist.PrintPlaylist();

    cout << endl << "[ Playing songs from the playlist: ]" << endl;
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong(); //when empty

    return 0;
}
