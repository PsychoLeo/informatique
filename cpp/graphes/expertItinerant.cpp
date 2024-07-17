#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class rue {
public:
  int rue_depart;
  int rue_arrivee;
  int rue_temps;
};

class requete {
public:
  int requete_depart;
  int requete_arrivee;
};

void expert_itinerant0(int n, int m, int r, vector<rue *> * rues, vector<requete *> * requetes){
  /* Inserez votre code ici */
}


int main(){
  int r, m, n;
  std::cin >> n >> std::skipws >> m >> r;
  std::vector<rue * > *rues = new std::vector<rue *>( m );
  for (int i = 0 ; i < m; i++)
  {
    rue * ru = new rue();
    ru->rue_depart=0;
    ru->rue_arrivee=0;
    ru->rue_temps=0;
    std::cin >> ru->rue_depart >> std::skipws >> ru->rue_arrivee >> ru->rue_temps;
    rues->at(i) = ru;
  }
  std::vector<requete * > *requetes = new std::vector<requete *>( r );
  for (int j = 0 ; j < r; j++)
  {
    requete * req = new requete();
    req->requete_depart=0;
    req->requete_arrivee=0;
    std::cin >> req->requete_depart >> std::skipws >> req->requete_arrivee;
    requetes->at(j) = req;
  }
  expert_itinerant0(n, m, r, rues, requetes);
  return 0;
}

