#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>

using namespace std;

class Album {
private:
    string title, artist;
    double price; int noOfCopies;

    static int totalAlbums;
    static int totalRevenue;

public:
    Album(const string&,const string &, double, int);
    static int getTotalAlbums();
    static int getTotalRevenue();

    void purchase(int);
    
    string getTitle() const;
    string getArtist() const;
    double getPrice() const;
    int getCopies() const;
};

#endif