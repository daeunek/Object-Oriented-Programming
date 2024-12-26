#include<iostream>
#include<vector>
#include "Album.h"

using namespace std;

int main() {
    vector<Album> albums;
    albums.emplace_back("Abbey", "Riha", 19.99, 6);
    albums.emplace_back("Hk", "Blackpink", 29, 19);
    albums.emplace_back("Hotel California", "Eagles", 15.99, 4);
    albums.emplace_back("Back in Black", "AC/DC", 20.99, 2);
    albums.emplace_back("Rumours", "Fleetwood Mac", 16.99, 3);
    albums.emplace_back("Thriller", "Michael Jackson", 18.99, 5);
    albums.emplace_back("The Wall", "Pink Floyd", 22.99, 2);
    albums.emplace_back("Led Zeppelin IV", "Led Zeppelin", 17.99, 3);

    while (true) {
        cout << "Onlin Music Store Menu: \n";
        cout << "1. List all albums\n";
        cout << "2. Purchase an album\n";
        cout << "3. Display sales stastics\n";
        cout << "4. exit\n";
        int choice;
        cout << "Ente your choice(1-4): "; cin >> choice;

        switch(choice) {
            case 1:
                for (size_t i = 0; i < albums.size(); i++){
                    cout << i+1 << ". " << albums[i].getTitle() << " by " << albums[i].getArtist() << "- $"  << albums[i].getPrice() << " (" 
                        << albums[i].getCopies() << " copies available)\n";
                }
                break;

            case 2:
                int album_index; cout << "enter a album_indexber of album that you want to purchase: "; cin >> album_index;
                int num; cout << "enter num of albums that you want to purchase: "; cin >> num;
                if (album_index > 0 && album_index < albums.size() ) {
                    albums[album_index-1].purchase(num);
                    cout << "Successfully purchased " << albums[album_index-1].getTitle() << endl;

                }
                else{
                    cout << "Invalid album_index of album.\n";
                }
                break;

            case 3:
                cout << "Total Albums: " << Album::getTotalAlbums() << endl;
                cout << "Total sales: "  << Album::getTotalRevenue() << endl;
                break;              

            case 4:
                cout << "Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice\n";
                break;
        }
  
    }
    return 0;
}