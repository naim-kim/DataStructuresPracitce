#include <iostream>
#include <stack>
#include <string>
using namespace std;

class MusicPlaylist {
private:
    stack<string> playlist;

public:
    void AddSong(const string& song) {
        playlist.push(song);
    }

    void PlayCurrentSong() {
        if (!playlist.empty()) {
            cout << "Now playing: " << playlist.top() << endl;
            playlist.pop();
        } else {
            cout << "Playlist is empty" << endl;
        }
    }

    // Print current playlist
    void PrintPlaylist() const {
        if (!playlist.empty()) {
            cout << "Current Playlist:" << endl;
            stack<string> temp = playlist;
            while (!temp.empty()) {
                cout << temp.top() << endl;
                temp.pop();
            }
        } else {
            cout << "Playlist is empty" << endl;
        }
    }
};

int main() {
    MusicPlaylist playlist;
    
    // Add songs to the playlist
    playlist.AddSong("Snooze - SZA");
    playlist.AddSong("Chi-Ka - Tabber");
    playlist.AddSong("Mala Fama - Danna Paola");

    // Play the songs
    cout << "--- Playing Playlist ---" << endl;
    playlist.PrintPlaylist();
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong(); // Try to play when playlist is empty

    return 0;
}
