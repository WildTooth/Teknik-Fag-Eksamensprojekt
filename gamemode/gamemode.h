#ifndef GAMEMODE_H
#define GAMEMODE_H

class Gamemode {
public:
    virtual void init() {
      // Standard initialiserings logik kan implementeres her
    }

    virtual void run() {
      // Standard run logik, det som skal loopes ;)
      // Gid det var Java det her, Runnable.run() ville gå ret hårdt lige nu 8-( - Kh. Jonathan "Johnny" "John" Holck
    }
};

#endif