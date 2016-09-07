/*
Functionalities
- User
- Song & getSong
- PlayList

Pattern Usage:
- Singleton
*/

//=========== First Design ===========

class Song {
private:
    int id;
    string _name;
    shared_ptr<char>
    static map<int, Song> songs;
public:
    static Song getSong(int o_id) {
        auto it = songs.find(o_id);
        return it != songs.end() ? & sit->second : nullptr;
    }
    static void addSong(int o_id, Song o_song);
    string getName() const;
    void jump(int posi);
};

class PlayList {
private:
    vector<int> song_ids;
public:
    PlayList();
};

class Player {
private:
    Song currentSong;
public:
    Player();
    void setSong()
};

class User {
private:
    int age;
    string first, last;
    vector<PlayList>
public:
    User()
};
