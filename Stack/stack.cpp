#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime> // for srand

using namespace std;

class Playlist {
private:
    stack<string> playlist;
    vector<string> shuffledSongs;

public:
    void AddSong(const string& song) {
        playlist.push(song);
        cout << "\"" << song << "\" successfully added to the playlist!" << endl;
    }

    void ShufflePlaylist() {
        // Copy songs from playlist to a vector
        while (!playlist.empty()) {
            shuffledSongs.push_back(playlist.top());
            playlist.pop();
        }
        
        // Shuffle the songs using random_shuffle
        srand(time(0)); // Seed random number generator
        random_shuffle(shuffledSongs.begin(), shuffledSongs.end());

        // Push shuffled songs back to the playlist stack
        for (const string& song : shuffledSongs) {
            playlist.push(song);
        }

        cout << "Playlist shuffled successfully!" << endl;
    }

    void PlayCurrentSong() {
        if (!playlist.empty()) {
            cout << "Now playing: " << playlist.top() << endl;
            cout << "  >> playing" << endl;
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
    string songToAdd;
    char choice;

    do {
        cout << "Enter the name of the song to add to the playlist: ";
        getline(cin, songToAdd);
        playlist.AddSong(songToAdd);

        cout << "Do you want to add another song? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
    } while (choice == 'y' || choice == 'Y');

    cout << "--- Naim's Playlist ---\n" << endl;
    playlist.PrintPlaylist();

    cout << endl << "[ Shuffle Playlist: ]" << endl;
    playlist.ShufflePlaylist();
    playlist.PrintPlaylist();

    cout << endl << "[ Playing songs from the playlist: ]" << endl;
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong();
    playlist.PlayCurrentSong(); //when empty

    return 0;
}
