#include <iostream>
#include <fstream>

#include "Matica.h"

using std::cout;
using std::endl;

int main() {
  std::ifstream inputMatrixFile;
  inputMatrixFile.open("matrix.txt");

  uint32_t pocetRiadkov{};
  uint32_t pocetStlpcov{};

  // nacitanie matice zo subotu - deserializacia
  inputMatrixFile >> pocetRiadkov;
  inputMatrixFile >> std::ws;
  inputMatrixFile >> pocetStlpcov;
  inputMatrixFile >> std::ws;

  Matica nacitanaMatica(pocetRiadkov, pocetStlpcov);
  inputMatrixFile >> nacitanaMatica;

  //Matica maticaVynasobenaSkalarom = nacitanaMatica;
  Matica maticaVynasobenaSkalarom;
  maticaVynasobenaSkalarom = nacitanaMatica;
  maticaVynasobenaSkalarom *= 3;

  // ulozit maticu do suboru - serializacia
  std::ofstream matrixMultipliedByScalarOutputFile;
  matrixMultipliedByScalarOutputFile.open("matrix_multiplied_with_scalar.txt");
  matrixMultipliedByScalarOutputFile << maticaVynasobenaSkalarom;

  Matica& rozdielovaMatica = maticaVynasobenaSkalarom - nacitanaMatica;

  std::ofstream subtractedMatrixOutputFile;
  subtractedMatrixOutputFile.open("subtracted_matrix.txt");
  subtractedMatrixOutputFile << rozdielovaMatica;

  cout << "maticaVynasobenaSkalarom\n" << maticaVynasobenaSkalarom << endl;
  cout << "nacitanaMatica\n" << nacitanaMatica << endl;
  cout << "rozdielovaMatica\n" << rozdielovaMatica << endl;

  delete &rozdielovaMatica;

  cout << "--------------------------" << endl << endl;

  // Test 2
  // Copy Initialization
  Matica maticaPodelenaSkalarom = nacitanaMatica;
  maticaPodelenaSkalarom /= 2;

  std::ofstream dividedMatrixOutputFile;
  dividedMatrixOutputFile.open("matrix_divided_by_scalar.txt");
  dividedMatrixOutputFile << maticaPodelenaSkalarom;

  Matica& scitanaMatica = nacitanaMatica + maticaPodelenaSkalarom;
  cout << "nacitanaMatica\n" << nacitanaMatica << endl;
  cout << "maticaPodelenaSkalarom\n" << maticaPodelenaSkalarom << endl;
  cout << "scitanaMatica\n" << scitanaMatica << endl;

  std::ofstream addedMatrixOutputFile;
  addedMatrixOutputFile.open("added_matrix.txt");
  addedMatrixOutputFile << scitanaMatica;

  delete &scitanaMatica;

  /*
  Matica matica2(2, 2);
  matica2[0][0] = 2;                          //pretazeny operator[]
  matica2[0][1] = 4;
  matica2[1][0] = 4;
  matica2[1][1] = 2;
  cout << "matica2\n" << matica2 << endl;

  Matica matica3(3, 3);
  cin >> matica3;                             //pretazeny operator>>
  cout << "\nmatica3\n" << matica3 << endl;

  Matica matica4 = matica3;                   //pretazeny kopirovaci konstruktor
  cout << "matica4\n" << matica4 << endl;

  Matica matica5;
  matica5 = matica4;                          //pretazeny operator=
  cout << "matica5\n" << matica5 << endl;



  Matica* matica7 = matica6 * matica5;        //pretazeny operator*(const Matica &, const Matica &)
  cout << "matica7\n" << *matica7 << endl;
  delete matica7;

  cout << "matica6 == matica5 ... " << ((matica5 == matica6) ? "ano" : "nie") << endl;    //pretazeny operator==
  cout << "matica1 > matica3 ... " << ((matica1 > matica3) ? "ano" : "nie") << endl;      //pretazeny operator>
  */


  return 0;
}
