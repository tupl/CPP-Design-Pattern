/**
 * Purpose of Adapter is to connect together object
 * with different interface. The object is already designed before.
 * As a result, we can create a wrapper around the object.
 */

class OldSong {
public:
    Song( ... )
    void playMySong() const;
};

class Song: {
public:
    Song();
    virtual void play() const = 0;
};

class WrapperOldSong: public Song, private OldSong {
public:
    WrapperOldSong(OldSong song): song(OldSong) {}
    void play() const {
        song.playMySong();
    }
};
