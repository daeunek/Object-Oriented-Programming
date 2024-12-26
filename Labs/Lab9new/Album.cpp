#include "Album.h"
#include <iostream>

using namespace std;

int Album::totalAlbums = 0;
int Album::totalRevenue = 0;

//constructor 
Album :: Album(const string &t,const string &a, double p, int copies) {
    title = t;
    artist = a;
    price = p;
    noOfCopies = copies;
    totalAlbums += noOfCopies;
}

void Album::purchase( int soldNum) {
    if (noOfCopies < soldNum) {
        cout << "Out of stock\n";
    }
    else{
        noOfCopies -= soldNum;
        totalRevenue += (soldNum * price);
        totalAlbums -= soldNum;
    }
}

int Album::getTotalAlbums() {
    return totalAlbums;
}

int Album::getTotalRevenue() {
    return totalRevenue;
}

string Album::getTitle() const{return title;}
string Album::getArtist() const{return artist;}
double Album::getPrice() const{return price;}
int Album::getCopies() const {return noOfCopies;}



