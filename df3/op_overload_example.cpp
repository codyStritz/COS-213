#include <iostream> 
#include <iomanip> 
#include <string>
using namespace std;


class Movie {
  private:
    double rating_;
    string title_;
    // genre,
    // year,
    // etc.
  public:
    Movie(string title, double rating)      // Constructor
      : title_(title), rating_(rating) {}  
    
    bool operator > (Movie &other) {      // > operator override
      return rating_ > other.rating_;
    }

    bool operator < (Movie &other) {      // < operator override
      return rating_ < other.rating_;
    }

    string GetTitle()  {
      return title_;
    }
    
};



int main()
{
  Movie the_dark_knight = Movie("The Dark Knight", 9.0);
  Movie jurassic_park = Movie("Jurassic Park", 8.1);
  if (the_dark_knight > jurassic_park) {
    cout << the_dark_knight.GetTitle() << " has better ratings." << endl;
  } else {
    cout << jurassic_park.GetTitle() << " has better ratings." << endl;
  }
  system("pause");
  return 0;
}
